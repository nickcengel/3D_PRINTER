#include "powderdaemon.h"

PowderDaemon::PowderDaemon(QObject *parent) : QObject(parent)
{

    m_lg_port = new QSerialPort(this);
    m_md_port = new QSerialPort(this);

    m_lg_port->setBaudRate(115200);
    m_md_port->setBaudRate(115200);

    m_manualModeEnabled = false;
    m_printModeEnabled = false;

    m_xPosition = 0;
    m_yPosition = 0;
    m_zPosition = 0;
    m_sPosition = 0;
    m_hPosition = 0;
    m_xySpeed = 0;
    m_laserPower = 0;
    m_laserEnableState = false;
    m_laserArmState = false;

    m_jogIncrement = 1.0;
    m_jogSign = 1.0;
    m_homeOption = 1;

    m_xHomed = false;
    m_yHomed = false;
    m_zHomed = false;
    m_hHomed = false;
    m_sHomed = false;

    m_currentBlockNumber = 0;
    m_currentLayerNumber = 0;

    m_pendingTasks = 0;
    m_activeTask = 0;

    lg_port_TxBytesRemaining = 0;
    md_port_TxBytesRemaining = 0;

    connect(m_lg_port, SIGNAL(bytesWritten(qint64)),
            this, SLOT(on_lg_port_bytesWritten(qint64)));

    connect(m_lg_port, SIGNAL(readyRead()),
            this, SLOT(on_lg_port_bytesRead()));

    connect(m_lg_port, SIGNAL(errorOccurred(QSerialPort::SerialPortError)),
            this, SLOT(on_lg_port_error(QSerialPort::SerialPortError)));

    connect(m_md_port, SIGNAL(bytesWritten(qint64)),
            this, SLOT(on_md_port_bytesWritten(qint64)));

    connect(m_md_port, SIGNAL(readyRead()),
            this, SLOT(on_md_port_bytesRead()));

    connect(m_md_port, SIGNAL(errorOccurred(QSerialPort::SerialPortError)),
            this, SLOT(on_md_port_error(QSerialPort::SerialPortError)));

    lg_port_timer = new QTimer(this);
    lg_port_timer->setSingleShot(true);
    md_port_timer = new QTimer(this);
    md_port_timer->setSingleShot(true);

    QObject::connect(lg_port_timer, SIGNAL(timeout()), this, SLOT(on_lg_portTimeout()));
    QObject::connect(md_port_timer, SIGNAL(timeout()), this, SLOT(on_md_portTimeout()));




    printRoutine = new QStateMachine(this);

    QState *printRoutine_init_state = new QState(printRoutine);

    QState *generateProcessQueueFromBlock_state = new QState(printRoutine);
    QState *selectNextProcessFromQueue_state = new QState(printRoutine);
    QState *send_lgCommand_state = new QState(printRoutine);
    QState *receive_lgReply_state = new QState(printRoutine);
    QState *lg_transactionFinished_state = new QState(printRoutine);
    QState *send_mdCommand_state = new QState(printRoutine);
    QState *receive_mdReply_state = new QState(printRoutine);
    QState *md_transactionFinished_state = new QState(printRoutine);
    QState *selectNextBlockToProcess_state = new QState(printRoutine);
    QState *printRoutine_finished_state = new QState(printRoutine);
    QState *printRoutine_error_state = new QState(printRoutine);

    printRoutine->setInitialState(printRoutine_init_state);

    connect(printRoutine_init_state, SIGNAL(entered()), SLOT(on_printRoutine_init()));
    connect(generateProcessQueueFromBlock_state, SIGNAL(entered()), SLOT(on_generateProcessQueueFromBlock()));
    connect(selectNextProcessFromQueue_state, SIGNAL(entered()), SLOT(on_selectProcessFromQueue()));
    connect(send_lgCommand_state, SIGNAL(entered()), SLOT(on_send_lgCommand()));
    connect(receive_lgReply_state, SIGNAL(entered()), SLOT(on_receive_lgReply()));
    connect(lg_transactionFinished_state, SIGNAL(entered()), SLOT(on_lg_transactionFinished()));
    connect(send_mdCommand_state, SIGNAL(entered()), SLOT(on_send_mdCommand()));
    connect(receive_mdReply_state, SIGNAL(entered()), SLOT(on_receive_mdReply()));
    connect(md_transactionFinished_state, SIGNAL(entered()), SLOT(on_md_transactionFinished()));
    connect(selectNextBlockToProcess_state, SIGNAL(entered()), SLOT(on_selectNextBlockToProcess()));
    connect(printRoutine_finished_state, SIGNAL(entered()), SLOT(on_printRoutine_finished()));
    connect(printRoutine_error_state, SIGNAL(entered()), SLOT(on_printRoutine_error()));

    printRoutine_init_state->addTransition(this, SIGNAL(startPrint()), generateProcessQueueFromBlock_state);
    generateProcessQueueFromBlock_state->addTransition(this, SIGNAL(tasksRemaining()), selectNextProcessFromQueue_state);
    generateProcessQueueFromBlock_state->addTransition(this, SIGNAL(blockComplete()), selectNextBlockToProcess_state);

    selectNextProcessFromQueue_state->addTransition(this, SIGNAL(lg_commandPending()), send_lgCommand_state);
    send_lgCommand_state->addTransition(this, SIGNAL(lg_port_txFinished()), receive_lgReply_state);
    receive_lgReply_state->addTransition(this, SIGNAL(lg_port_rxFinished()), lg_transactionFinished_state);
    lg_transactionFinished_state->addTransition(this, SIGNAL(tasksRemaining()), selectNextProcessFromQueue_state);
    lg_transactionFinished_state->addTransition(this, SIGNAL(blockComplete()), selectNextBlockToProcess_state);

    selectNextProcessFromQueue_state->addTransition(this, SIGNAL(md_commandPending()), send_mdCommand_state);
    send_mdCommand_state->addTransition(this, SIGNAL(md_port_txFinished()), receive_mdReply_state);
    receive_mdReply_state->addTransition(this, SIGNAL(md_port_rxFinished()), md_transactionFinished_state);
    md_transactionFinished_state->addTransition(this, SIGNAL(tasksRemaining()), selectNextProcessFromQueue_state);
    md_transactionFinished_state->addTransition(this, SIGNAL(blockComplete()), selectNextBlockToProcess_state);

    selectNextProcessFromQueue_state->addTransition(this, SIGNAL(blockComplete()), selectNextBlockToProcess_state);

    selectNextBlockToProcess_state->addTransition(this, SIGNAL(blocksRemaining()), generateProcessQueueFromBlock_state);
    selectNextBlockToProcess_state->addTransition(this, SIGNAL(printFinished()), printRoutine_finished_state);

    printRoutine_init_state->addTransition(this, SIGNAL(stopPrint()), printRoutine_finished_state);
    generateProcessQueueFromBlock_state->addTransition(this, SIGNAL(stopPrint()), printRoutine_finished_state);
    selectNextProcessFromQueue_state->addTransition(this, SIGNAL(stopPrint()), printRoutine_finished_state);
    send_lgCommand_state->addTransition(this, SIGNAL(stopPrint()), printRoutine_finished_state);
    receive_lgReply_state->addTransition(this, SIGNAL(stopPrint()), printRoutine_finished_state);
    send_mdCommand_state->addTransition(this, SIGNAL(stopPrint()), printRoutine_finished_state);
    receive_mdReply_state->addTransition(this, SIGNAL(stopPrint()), printRoutine_finished_state);
    selectNextBlockToProcess_state->addTransition(this, SIGNAL(stopPrint()), printRoutine_finished_state);
    printRoutine_error_state->addTransition(this, SIGNAL(stopPrint()), printRoutine_finished_state);

    printRoutine_init_state->addTransition(this, SIGNAL(lg_port_error(const QString&)), printRoutine_error_state);
    printRoutine_init_state->addTransition(this, SIGNAL(md_port_error(const QString&)), printRoutine_error_state);
    printRoutine_init_state->addTransition(this, SIGNAL(printRoutine_error(const QString&)), printRoutine_error_state);

    selectNextProcessFromQueue_state->addTransition(this, SIGNAL(lg_port_error(const QString&)), printRoutine_error_state);
    selectNextProcessFromQueue_state->addTransition(this, SIGNAL(md_port_error(const QString&)), printRoutine_error_state);
    selectNextProcessFromQueue_state->addTransition(this, SIGNAL(printRoutine_error(const QString&)), printRoutine_error_state);

    send_lgCommand_state->addTransition(this, SIGNAL(lg_port_error(const QString&)), printRoutine_error_state);
    send_lgCommand_state->addTransition(this, SIGNAL(printRoutine_error(const QString&)), printRoutine_error_state);

    receive_lgReply_state->addTransition(this, SIGNAL(lg_port_error(const QString&)), printRoutine_error_state);
    receive_lgReply_state->addTransition(this, SIGNAL(printRoutine_error(const QString&)), printRoutine_error_state);

    send_mdCommand_state->addTransition(this, SIGNAL(md_port_error(const QString&)), printRoutine_error_state);
    send_mdCommand_state->addTransition(this, SIGNAL(printRoutine_error(const QString&)), printRoutine_error_state);

    receive_mdReply_state->addTransition(this, SIGNAL(md_port_error(const QString&)), printRoutine_error_state);
    receive_mdReply_state->addTransition(this, SIGNAL(printRoutine_error(const QString&)), printRoutine_error_state);

    selectNextBlockToProcess_state->addTransition(this, SIGNAL(md_port_error(const QString&)), printRoutine_error_state);
    selectNextBlockToProcess_state->addTransition(this, SIGNAL(printRoutine_error(const QString&)), printRoutine_error_state);

    lg_transactionFinished_state->addTransition(this, SIGNAL(printRoutine_error(const QString&)), printRoutine_error_state);
    md_transactionFinished_state->addTransition(this, SIGNAL(printRoutine_error(const QString&)), printRoutine_error_state);

    printRoutine_init_state->addTransition(this, SIGNAL(lg_commandPending()), send_lgCommand_state);
    lg_transactionFinished_state->addTransition(this, SIGNAL(jogComplete()), printRoutine_init_state);

    printRoutine_init_state->addTransition(this, SIGNAL(md_commandPending()), send_mdCommand_state);
    md_transactionFinished_state->addTransition(this, SIGNAL(jogComplete()), printRoutine_init_state);


    printRoutine_error_state->addTransition(this, SIGNAL(resetDaemon()), printRoutine_init_state);

    printRoutine->start();
}


PowderDaemon::~PowderDaemon(){
    if(m_lg_port->isOpen()){
        m_lg_port->clear();
        m_lg_port->close();
    }
    if(m_md_port->isOpen()){
        m_md_port->clear();
        m_md_port->close();
    }

}

float PowderDaemon::xPosition() const
{
    return m_xPosition;
}

void PowderDaemon::setXPosition(float xPosition)
{
    m_xPosition = xPosition;
    emit xPosition_changed(static_cast<double>(m_xPosition));

}

float PowderDaemon::yPosition() const
{
    return m_yPosition;
}

void PowderDaemon::setYPosition(float yPosition)
{
    m_yPosition = yPosition;
    emit yPosition_changed(static_cast<double>(m_yPosition));

}

float PowderDaemon::zPosition() const
{
    return m_zPosition;
}

void PowderDaemon::setZPosition(float zPosition)
{
    m_zPosition = zPosition;
    emit zPosition_changed(static_cast<double>(m_zPosition));

}

float PowderDaemon::sPosition() const
{
    return m_sPosition;
}

void PowderDaemon::setSPosition(float sPosition)
{
    m_sPosition = sPosition;
    emit sPosition_changed(static_cast<double>(m_sPosition));

}

float PowderDaemon::hPosition() const
{
    return m_hPosition;
}

void PowderDaemon::setHPosition(float hPosition)
{
    m_hPosition = hPosition;
    emit hPosition_changed(static_cast<double>(m_hPosition));

}
int PowderDaemon::laserPower() const
{
    return m_laserPower;
}

void PowderDaemon::setLaserPower(int laserPower)
{
    m_laserPower = laserPower;
    emit laserPower_changed(m_laserPower);

}

bool PowderDaemon::laserEnableState() const
{
    return m_laserEnableState;
}

void PowderDaemon::setLaserEnableState(bool laserEnableState)
{
    if(laserEnableState != m_laserEnableState){
        m_laserEnableState = laserEnableState;
        if(m_laserEnableState)
            emit laserEnableState_changed("Laser\nOn");
        else
            emit laserEnableState_changed("Laser\nOff");
    }
}

bool PowderDaemon::laserArmState() const
{
    return m_laserArmState;
}

void PowderDaemon::setLaserArmState(bool laserArmState)
{
    m_laserArmState = laserArmState;
    emit laserArmState_changed(m_laserArmState);

}

float PowderDaemon::jogIncrement() const
{
    return m_jogIncrement;
}

void PowderDaemon::setJogIncrement(float jogIncrement)
{
    m_jogIncrement = jogIncrement;
}

bool PowderDaemon::xHomed() const
{
    return m_xHomed;
}

void PowderDaemon::setXHomed(bool xHomed)
{
    m_xHomed = xHomed;
}

bool PowderDaemon::yHomed() const
{
    return m_yHomed;
}

void PowderDaemon::setYHomed(bool yHomed)
{
    m_yHomed = yHomed;
}

bool PowderDaemon::zHomed() const
{
    return m_zHomed;
}

void PowderDaemon::setZHomed(bool zHomed)
{
    m_zHomed = zHomed;
}

bool PowderDaemon::hHomed() const
{
    return m_hHomed;
}

void PowderDaemon::setHHomed(bool hHomed)
{
    m_hHomed = hHomed;
}

bool PowderDaemon::sHomed() const
{
    return m_sHomed;
}

void PowderDaemon::setSHomed(bool sHomed)
{
    m_sHomed = sHomed;
}

void PowderDaemon::write_to_lg_port(const QString &txString)
{
    if(m_lg_port->isOpen()){
        lg_port_rxBytes.clear();
        const QByteArray txBytes = txString.toUtf8();
        lg_port_TxBytesRemaining = txBytes.length();
        lg_port_timer->start(1000);
        m_lg_port->write(txBytes);
    }
    else
        emit lg_port_error("Cannot write to closed port");
}

void PowderDaemon::write_to_md_port(const QString &txString)
{
    if(m_md_port->isOpen()){
        qDebug()<<"port is open?";
        md_port_rxBytes.clear();
        const QByteArray txBytes = txString.toUtf8();
        md_port_TxBytesRemaining = txBytes.length();
        md_port_timer->start(1000);
        m_md_port->write(txBytes);
    }
    else
        emit md_port_error("Cannot write to closed port");
}

void PowderDaemon::on_printManager_enabled(bool enabled)
{
    m_printModeEnabled = enabled;
    if(enabled)
        m_manualModeEnabled = false;
}

void PowderDaemon::on_config_available(QSharedPointer<SettingsObject> config)
{
    m_config = config;
}

void PowderDaemon::on_partFile_available(QSharedPointer<PartObject> part)
{
    m_part = part;
}

void PowderDaemon::on_startPrint_request()
{
    emit startPrint();
}

void PowderDaemon::on_stopPrint_request()
{
    emit stopPrint();
}




void PowderDaemon::on_lg_port_bytesWritten(qint64 bytes)
{
    lg_port_TxBytesRemaining -= bytes;
    if(lg_port_TxBytesRemaining <= 0)
        emit lg_port_txFinished();
}

void PowderDaemon::on_lg_port_bytesRead()
{

    lg_port_rxBytes +=  m_lg_port->readAll();

    if(lg_port_rxBytes.length() > 2){
        lg_port_timer->stop();
        QString reply = QString::fromUtf8(lg_port_rxBytes);
        if(reply.contains("ok", Qt::CaseInsensitive)){
            emit lg_port_deviceReply(reply);
            emit lg_port_rxFinished();
        }
        else{
            emit lg_port_error(reply);
        }
        lg_port_rxBytes.clear();
    }
}


void PowderDaemon::on_md_port_bytesWritten(qint64 bytes)
{
    md_port_TxBytesRemaining -= bytes;
    if(md_port_TxBytesRemaining <= 0)
        emit md_port_txFinished();
}

void PowderDaemon::on_md_port_bytesRead()
{
    md_port_rxBytes +=  m_md_port->readAll();

    if(md_port_rxBytes.length() > 2){
        md_port_timer->stop();
        QString reply = QString::fromUtf8(md_port_rxBytes);
        if(reply.contains("ok", Qt::CaseInsensitive)){
            emit md_port_deviceReply(reply);
            emit md_port_rxFinished();
        }
        else{
            emit md_port_error(reply);
        }
        md_port_rxBytes.clear();
    }
}






void PowderDaemon::on_lg_portTimeout()
{
    emit lg_port_error("Error: Time out");
}

void PowderDaemon::on_md_portTimeout()
{
    emit md_port_error("Error: Time out");
}

void PowderDaemon::on_lg_port_error(QSerialPort::SerialPortError portError)
{
    if(portError != QSerialPort::SerialPortError::NoError){
        QMetaEnum metaEnum = QMetaEnum::fromType<QSerialPort::SerialPortError>();
        emit lg_port_error(metaEnum.valueToKey(portError));
    }
}

void PowderDaemon::on_md_port_error(QSerialPort::SerialPortError portError)
{
    if(portError != QSerialPort::SerialPortError::NoError){
        QMetaEnum metaEnum = QMetaEnum::fromType<QSerialPort::SerialPortError>();
        emit md_port_error(metaEnum.valueToKey(portError));
    }
}





void PowderDaemon::on_printRoutine_init()
{
    qDebug()<<"entered printRoutine_init_state";
}

void PowderDaemon::on_generateProcessQueueFromBlock()
{
    qDebug()<<"entered generateProcessQueueFromBlock_state";
    bool empty = true;
    m_lg_commandStr.clear();
    m_md_commandStr.clear();
    m_pendingTasks = m_part.get()->getBlock(m_currentBlockNumber).blockTask();

    if(m_pendingTasks != 0){
        if(!m_lg_commandStr.isEmpty()){
            m_lg_commandStr = m_part.get()->getBlock(m_currentBlockNumber).lg_string();
            empty &= m_lg_commandStr.contains("EMPTY");
        }

        if(!m_md_commandStr.isEmpty()){
            m_md_commandStr =  m_part.get()->getBlock(m_currentBlockNumber).md_string();
            empty &= m_md_commandStr.at(0).contains("EMPTY");
            empty &= m_md_commandStr.at(1).contains("EMPTY");
            empty &= m_md_commandStr.at(2).contains("EMPTY");
        }

        if(!empty){
            emit tasksRemaining();
        }
        else{
            m_pendingTasks = 0;
            emit blockComplete();
        }
    }
    else{
        emit blockComplete();
    }
}

void PowderDaemon::on_selectProcessFromQueue()
{
    qDebug()<<"entered selectProcessFromQueue_state";

    m_activeTask = 0;

    if(m_pendingTasks & BlockObject::BlockTask::SET_HOME_AXIS)
        m_activeTask |= BlockObject::BlockTask::SET_HOME_AXIS;

    if(m_pendingTasks & (BlockObject::BlockTask::SET_X_POSITION|BlockObject::BlockTask::SET_Y_POSITION)){
        if(m_pendingTasks & BlockObject::BlockTask::SET_X_POSITION)
            m_activeTask |= BlockObject::BlockTask::SET_X_POSITION;
        if(m_pendingTasks & BlockObject::BlockTask::SET_Y_POSITION)
            m_activeTask |= BlockObject::BlockTask::SET_Y_POSITION;
        if(m_pendingTasks & BlockObject::BlockTask::SET_LASER_ENABLE_STATE)
            m_activeTask |= BlockObject::BlockTask::SET_LASER_ENABLE_STATE;
        if(m_pendingTasks & BlockObject::BlockTask::SET_LASER_ARM_STATE)
            m_activeTask |= BlockObject::BlockTask::SET_LASER_ARM_STATE;
        if(m_pendingTasks & BlockObject::BlockTask::SET_XY_SPEED)
            m_activeTask |= BlockObject::BlockTask::SET_XY_SPEED;
        if(m_pendingTasks & BlockObject::BlockTask::SET_LASER_POWER)
            m_activeTask |= BlockObject::BlockTask::SET_LASER_POWER;
        emit lg_commandPending();
    }
    else if(m_pendingTasks & BlockObject::BlockTask::SET_Z_POSITION){
        m_activeTask |= BlockObject::BlockTask::SET_Z_POSITION;
        emit md_commandPending();
    }
    else if(m_pendingTasks & BlockObject::BlockTask::SET_HOPPER_POSITION){
        m_activeTask |= BlockObject::BlockTask::SET_HOPPER_POSITION;
        emit md_commandPending();
    }
    else if(m_pendingTasks & BlockObject::BlockTask::SET_SPREADER_POSITION){
        m_activeTask |= BlockObject::BlockTask::SET_SPREADER_POSITION;
        emit md_commandPending();
    }
    else
        emit blockComplete();
}

void PowderDaemon::on_send_lgCommand()
{
    qDebug()<<"entered send_lgCommand_state";
    write_to_lg_port(m_lg_commandStr);
}

void PowderDaemon::on_receive_lgReply()
{
    qDebug()<<"entered receive_lgReply_state";
    lg_port_timer->start(1000);
}


void PowderDaemon::on_lg_transactionFinished()
{
    qDebug()<<"entered lg_transactionFinished_state";

    if(m_printModeEnabled){
        if(m_activeTask & BlockObject::BlockTask::SET_X_POSITION){
            setXPosition(m_part.get()->getBlock(m_currentBlockNumber).x_position());
            if(m_activeTask & BlockObject::BlockTask::SET_HOME_AXIS)
                setXHomed(true);
        }
        if(m_activeTask & BlockObject::BlockTask::SET_Y_POSITION){
            setYPosition(m_part.get()->getBlock(m_currentBlockNumber).y_position());
            if(m_activeTask & BlockObject::BlockTask::SET_HOME_AXIS)
                setYHomed(true);
        }
        if(m_activeTask & BlockObject::BlockTask::SET_XY_SPEED)
            setXYSpeed(m_part.get()->getBlock(m_currentBlockNumber).xy_speed());

        if(m_activeTask & BlockObject::BlockTask::SET_LASER_ENABLE_STATE)
            setLaserEnableState(m_part.get()->getBlock(m_currentBlockNumber).laser_enabled());
        if(m_activeTask & BlockObject::BlockTask::SET_LASER_ARM_STATE)
            setLaserArmState(m_part.get()->getBlock(m_currentBlockNumber).laser_armed());
        if(m_activeTask & BlockObject::BlockTask::SET_LASER_POWER)
            setLaserPower(m_part.get()->getBlock(m_currentBlockNumber).laser_power());

        m_pendingTasks &= (m_activeTask^0xFFFF);

        if(m_pendingTasks != 0){
            if(m_activeTask & BlockObject::BlockTask::SET_HOME_AXIS)
                m_pendingTasks |= BlockObject::BlockTask::SET_HOME_AXIS;
            emit tasksRemaining();
        }
        else
            emit blockComplete();
    }
    else if(m_manualModeEnabled){
        if(m_activeTask & BlockObject::BlockTask::SET_X_POSITION){
            if(m_activeTask & BlockObject::BlockTask::SET_HOME_AXIS){
                setXHomed(true);
                setXPosition(0);
            }
            else
                setXPosition(xPosition() + m_jogSign*m_jogIncrement);
            m_activeTask = 0;
            emit jogComplete();
        }

        if(m_activeTask & BlockObject::BlockTask::SET_Y_POSITION){
            if(m_activeTask & BlockObject::BlockTask::SET_HOME_AXIS){
                setYHomed(true);
                setYPosition(0);
            }
            else
                setYPosition(yPosition() + m_jogSign*m_jogIncrement);
            m_activeTask = 0;
            emit jogComplete();
        }
    }
    else
        emit printRoutine_error("No Mode Selected");
}

void PowderDaemon::on_send_mdCommand()
{
    qDebug()<<"entered send_mdCommand_state";
    qDebug()<<m_md_commandStr.at(0);

    if(m_activeTask & BlockObject::BlockTask::SET_Z_POSITION)
        write_to_md_port(m_md_commandStr.at(0));
    else if(m_pendingTasks & BlockObject::BlockTask::SET_HOPPER_POSITION)
        write_to_md_port(m_md_commandStr.at(1));
    else if(m_pendingTasks & BlockObject::BlockTask::SET_SPREADER_POSITION)
        write_to_md_port(m_md_commandStr.at(2));
}

void PowderDaemon::on_receive_mdReply()
{
    qDebug()<<"entered receive_mdReply_state";

}

void PowderDaemon::on_md_transactionFinished()
{
    qDebug()<<"entered transactionFinished_state";

    if(m_printModeEnabled){
        if(m_activeTask & BlockObject::BlockTask::SET_Z_POSITION){
            setZPosition(m_part.get()->getBlock(m_currentBlockNumber).z_position());
            if(m_activeTask & BlockObject::BlockTask::SET_HOME_AXIS)
                setZHomed(true);
        }
        else if(m_activeTask & BlockObject::BlockTask::SET_HOPPER_POSITION){
            setHPosition(m_part.get()->getBlock(m_currentBlockNumber).hopper_position());
            if(m_activeTask & BlockObject::BlockTask::SET_HOME_AXIS)
                setHHomed(true);
        }
        else if(m_activeTask & BlockObject::BlockTask::SET_SPREADER_POSITION){
            setSPosition(m_part.get()->getBlock(m_currentBlockNumber).spreader_position());
            if(m_activeTask & BlockObject::BlockTask::SET_HOME_AXIS)
                setSHomed(true);
        }
        m_pendingTasks &= (m_activeTask^0xFFFF);
        if(m_pendingTasks != 0){
            if(m_activeTask & BlockObject::BlockTask::SET_HOME_AXIS)
                m_pendingTasks |= BlockObject::BlockTask::SET_HOME_AXIS;
            emit tasksRemaining();
        }
        else
            emit blockComplete();
    }
    else if(m_manualModeEnabled){
        if(m_activeTask & BlockObject::BlockTask::SET_Z_POSITION){
            if(m_activeTask & BlockObject::BlockTask::SET_HOME_AXIS){
                setZHomed(true);
                setZPosition(0);
            }
            else
                setZPosition(zPosition() + m_jogSign*m_jogIncrement);
            m_activeTask = 0;
            emit jogComplete();
        }
        else if(m_activeTask & BlockObject::BlockTask::SET_HOPPER_POSITION){
            if(m_activeTask & BlockObject::BlockTask::SET_HOME_AXIS){
                setHHomed(true);
                setHPosition(0);
            }
            else
                setHPosition(hPosition() + m_jogSign*m_jogIncrement);
            m_activeTask = 0;
            emit jogComplete();
        }
        else if(m_activeTask & BlockObject::BlockTask::SET_SPREADER_POSITION){
            if(m_activeTask & BlockObject::BlockTask::SET_HOME_AXIS){
                setSHomed(true);
                setSPosition(0);
            }
            else
                setSPosition(sPosition() + m_jogSign*m_jogIncrement);
            m_activeTask = 0;
            emit jogComplete();
        }
    }
    else
        emit printRoutine_error("No Mode Selected");
}

void PowderDaemon::on_selectNextBlockToProcess()
{
    qDebug()<<"entered selectNextBlockToProcess_state";

    m_currentBlockNumber += 1;
    emit currentBlockNumber_changed(m_currentBlockNumber);
    if(m_currentLayerNumber != m_part.get()->getBlock(m_currentBlockNumber).layerNumber()){
        m_currentLayerNumber = m_part.get()->getBlock(m_currentBlockNumber).layerNumber();
        emit currentLayerNumber_changed(m_currentLayerNumber);
    }
    if(m_currentBlockNumber < m_part.get()->blockCount()){
        emit blocksRemaining();
    }
    else
        emit printFinished();

}

void PowderDaemon::on_printRoutine_finished()
{
    qDebug()<<"entered printRoutine_finished_state";

}

void PowderDaemon::on_printRoutine_error()
{
    qDebug()<<"entered printRoutine_error_state";
    if(m_lg_port->error() != QSerialPort::SerialPortError::NoError)
        m_lg_port->clearError();
    if(m_md_port->error() != QSerialPort::SerialPortError::NoError)
        m_md_port->clearError();
    m_activeTask = 0;
    m_pendingTasks = 0;
    emit resetDaemon();
}

float PowderDaemon::xySpeed() const
{
    return m_xySpeed;
}

void PowderDaemon::setXYSpeed(float xySpeed)
{
    m_xySpeed = xySpeed;
    emit  xySpeed_changed(m_xySpeed);
}

void PowderDaemon::on_manualControl_enabled(bool enabled)
{
    m_manualModeEnabled = enabled;
    if(enabled)
        m_printModeEnabled = false;
}

void PowderDaemon::on_lgPortName_changed(const QString &name)
{
    if(m_lg_port->isOpen())
        m_lg_port->close();
    m_lg_port->setPortName(name);
}

void PowderDaemon::on_mdPortName_changed(const QString &name)
{
    if(m_md_port->isOpen())
        m_md_port->close();
    m_md_port->setPortName(name);
}

void PowderDaemon::on_lg_port_connectionRequested(bool open)
{
    if(open && !m_lg_port->isOpen()){
        m_lg_port->open(QIODevice::ReadWrite);
        if(m_lg_port->isOpen())
            emit lg_port_connectionChanged(true);
        else
            emit lg_port_error("Could not open LG port");
    }
    else if(!open && m_lg_port->isOpen()){
        m_lg_port->close();
        emit lg_port_connectionChanged(false);
    }
}

void PowderDaemon::on_md_port_connectionRequested(bool open)
{
    if(open && !m_md_port->isOpen()){
        m_md_port->open(QIODevice::ReadWrite);
        if(m_md_port->isOpen())
            emit md_port_connectionChanged(true);
        else
            emit lg_port_error("Could not open MD port");
    }
    else if(!open && m_md_port->isOpen()){
        m_md_port->close();
        emit md_port_connectionChanged(false);
    }
}



void PowderDaemon::on_jogIncrement_changed(double jogIncrement)
{
    m_jogIncrement = jogIncrement;
}

void PowderDaemon::on_homeOption_change(int homeOption)
{
    m_homeOption = homeOption;
}

void PowderDaemon::on_home_request()
{
    switch (m_homeOption) {
    case 0:
    {
        m_activeTask = (BlockObject::BlockTask::SET_HOME_AXIS|BlockObject::BlockTask::SET_X_POSITION);
        if(m_lg_port->isOpen())
            emit lg_commandPending();
        break;
    }
    case 1:
    {
        m_activeTask = (BlockObject::BlockTask::SET_HOME_AXIS|BlockObject::BlockTask::SET_Y_POSITION);
        if(m_lg_port->isOpen())
            emit lg_commandPending();
        break;
    }
    case 2:
    {
        m_activeTask = (BlockObject::BlockTask::SET_HOME_AXIS|BlockObject::BlockTask::SET_Z_POSITION);
        if(m_md_port->isOpen())
            emit md_commandPending();
        break;
    }
    case 3:
    {
        m_activeTask = (BlockObject::BlockTask::SET_HOME_AXIS|BlockObject::BlockTask::SET_HOPPER_POSITION);
        if(m_md_port->isOpen())
            emit md_commandPending();
        break;
    }
    case 4:
    {
        m_activeTask = (BlockObject::BlockTask::SET_HOME_AXIS|BlockObject::BlockTask::SET_SPREADER_POSITION);
        if(m_md_port->isOpen())
            emit md_commandPending();
        break;
    }
    default:
        m_activeTask = 0;
        emit printRoutine_error("No Axis to Home");
        break;
    }
}

void PowderDaemon::on_increment_xPosition_request()
{
    if(((m_xPosition + jogIncrement())) < m_config.get()->x_position_max()){
        m_jogSign = 1.0;
        const int32_t steps = static_cast<int32_t>(jogIncrement()*m_config.get()->x_position_resolution());
        m_lg_commandStr = LaserGalvo_Utility::composeJogCommandString(BlockObject::BlockTask::SET_X_POSITION, steps);
        m_activeTask = BlockObject::BlockTask::SET_X_POSITION;
        emit lg_commandPending();
    }
}

void PowderDaemon::on_decrement_xPosition_request()
{
    if(((m_xPosition - jogIncrement())) > m_config.get()->x_position_min()){
        m_jogSign = -1.0;
        const int32_t steps = static_cast<int32_t>(-1*jogIncrement()*m_config.get()->x_position_resolution());
        m_lg_commandStr = LaserGalvo_Utility::composeJogCommandString(BlockObject::BlockTask::SET_X_POSITION, steps);
        m_activeTask = BlockObject::BlockTask::SET_X_POSITION;
        emit lg_commandPending();
    }
}

void PowderDaemon::on_increment_yPosition_request()
{
    if(((m_yPosition + jogIncrement())) < m_config.get()->y_position_max()){
        m_jogSign = 1.0;
        const int32_t steps = static_cast<int32_t>(jogIncrement()*m_config.get()->y_position_resolution());
        m_lg_commandStr = LaserGalvo_Utility::composeJogCommandString(BlockObject::BlockTask::SET_Y_POSITION, steps);
        m_activeTask = BlockObject::BlockTask::SET_Y_POSITION;
        emit lg_commandPending();
    }
}

void PowderDaemon::on_decrement_yPosition_request()
{
    if(((m_yPosition - jogIncrement())) > m_config.get()->y_position_min()){
        m_jogSign = -1.0;
        const int32_t steps = static_cast<int32_t>(-1*jogIncrement()*m_config.get()->y_position_resolution());
        m_lg_commandStr = LaserGalvo_Utility::composeJogCommandString(BlockObject::BlockTask::SET_Y_POSITION, steps);
        m_activeTask = BlockObject::BlockTask::SET_Y_POSITION;
        emit lg_commandPending();
    }
}

void PowderDaemon::on_increment_zPosition_request()
{
    m_md_commandStr.clear();
    if(((m_zPosition + jogIncrement())) < m_config.get()->z_position_max()){
        m_jogSign = 1.0;
        const int32_t steps = static_cast<int32_t>(jogIncrement()*m_config.get()->z_position_resolution());
        QString z ="/" + QString::number(m_config.get()->z_deviceNumber()) + " " + QString::number(m_config.get()->z_axisNumber());
        z += " move rel " + QString::number(steps) + "\r";
        m_md_commandStr.append(z);
        m_md_commandStr.append("EMPTY");
        m_md_commandStr.append("EMPTY");
        m_activeTask = BlockObject::BlockTask::SET_Z_POSITION;
        emit md_commandPending();
    }
}

void PowderDaemon::on_decrement_zPosition_request()
{
    m_md_commandStr.clear();
    if(((m_zPosition - jogIncrement())) > m_config.get()->z_position_min()){
        m_jogSign = -1.0;
        const int32_t steps = static_cast<int32_t>(-1*jogIncrement()*m_config.get()->z_position_resolution());
        QString z ="/" + QString::number(m_config.get()->z_deviceNumber()) + " " + QString::number(m_config.get()->z_axisNumber());
        z += " move rel " + QString::number(steps) + "\r";
        m_md_commandStr.append(z);
        m_md_commandStr.append("EMPTY");
        m_md_commandStr.append("EMPTY");
        m_activeTask = BlockObject::BlockTask::SET_Z_POSITION;
        emit md_commandPending();
    }
}

void PowderDaemon::on_increment_hPosition_request()
{
    m_md_commandStr.clear();
    if(((m_hPosition + jogIncrement())) < m_config.get()->hopper_position_max()){
        m_jogSign = 1.0;
        const int32_t steps = static_cast<int32_t>(jogIncrement()*m_config.get()->hopper_position_resolution());
        QString h ="/" + QString::number(m_config.get()->hopper_deviceNumber()) + " " + QString::number(m_config.get()->hopper_axisNumber());
        h += " move rel " + QString::number(steps) + "\r";
        m_md_commandStr.append("EMPTY");
        m_md_commandStr.append(h);
        m_md_commandStr.append("EMPTY");
        m_activeTask = BlockObject::BlockTask::SET_HOPPER_POSITION;
        emit md_commandPending();
    }
}

void PowderDaemon::on_decrement_hPosition_request()
{
    m_md_commandStr.clear();
    if(((m_hPosition - jogIncrement())) > m_config.get()->hopper_position_min()){
        m_jogSign = -1.0;
        const int32_t steps = static_cast<int32_t>(-1*jogIncrement()*m_config.get()->hopper_position_resolution());
        QString h ="/" + QString::number(m_config.get()->hopper_deviceNumber()) + " " + QString::number(m_config.get()->hopper_axisNumber());
        h += " move rel " + QString::number(steps) + "\r";
        m_md_commandStr.append("EMPTY");
        m_md_commandStr.append(h);
        m_md_commandStr.append("EMPTY");
        m_activeTask = BlockObject::BlockTask::SET_HOPPER_POSITION;
        emit md_commandPending();
    }
}

void PowderDaemon::on_increment_sPosition_request()
{
    m_md_commandStr.clear();
    if(((m_sPosition + jogIncrement())) < m_config.get()->spreader_position_max()){
        m_jogSign = 1.0;
        const int32_t steps = static_cast<int32_t>(jogIncrement()*m_config.get()->spreader_position_resolution());
        QString s ="/" + QString::number(m_config.get()->spreader_deviceNumber()) + " " + QString::number(m_config.get()->spreader_axisNumber());
        s += " move rel " + QString::number(steps) + "\r";
        m_md_commandStr.append("EMPTY");
        m_md_commandStr.append("EMPTY");
        m_md_commandStr.append(s);
        m_activeTask = BlockObject::BlockTask::SET_SPREADER_POSITION;
        emit md_commandPending();
    }
}

void PowderDaemon::on_decrement_sPosition_request()
{
    m_md_commandStr.clear();
    if(((m_sPosition - jogIncrement())) > m_config.get()->spreader_position_min()){
        m_jogSign = -1.0;
        const int32_t steps = static_cast<int32_t>(-1*jogIncrement()*m_config.get()->spreader_position_resolution());
        QString s ="/" + QString::number(m_config.get()->spreader_deviceNumber()) + " " + QString::number(m_config.get()->spreader_axisNumber());
        s += " move rel " + QString::number(steps) + "\r";
        m_md_commandStr.append("EMPTY");
        m_md_commandStr.append("EMPTY");
        m_md_commandStr.append(s);
        m_activeTask = BlockObject::BlockTask::SET_SPREADER_POSITION;
        emit md_commandPending();
    }
}
