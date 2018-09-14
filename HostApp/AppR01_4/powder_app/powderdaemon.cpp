#include "powderdaemon.h"

PowderDaemon::PowderDaemon(QObject *parent) : QObject(parent)
{

    lg_port_timer = new QTimer(this);
    lg_port_timer->setSingleShot(true);
    lg_port_timer->setInterval(1000);
    md_port_timer = new QTimer(this);
    md_port_timer->setSingleShot(true);
    md_port_timer->setInterval(1000);

    QObject::connect(lg_port_timer, SIGNAL(timeout()), this, SLOT(on_lg_portTimeout()));
    QObject::connect(md_port_timer, SIGNAL(timeout()), this, SLOT(on_md_portTimeout()));


    //    QState *machineInit_state = new QState(stateMachine);
    //    QStateMachine *machineJogControl_mode = new QStateMachine(stateMachine);
    //    QState *machineError_state = new QState(stateMachine);

    //    stateMachine->setInitialState(machineInit_state);
    //    machineInit_state->addTransition(this, SIGNAL(enter_manualControl_mode()), machineJogControl_mode);
    //    machineJogControl_mode->addTransition(this, SIGNAL(enter_printManager_mode()), machinePrintFile_mode);
    //    machineJogControl_mode->addTransition(lg_port_timer, SIGNAL(timeout()), machineError_state);
    //    machineJogControl_mode->addTransition(md_port_timer, SIGNAL(timeout()), machineError_state);
    //    machineJogControl_mode->addTransition(this, SIGNAL(md_port_deviceError(const QString&)), machineError_state);
    //    machineJogControl_mode->addTransition(this, SIGNAL(lg_port_deviceError(const QString&)), machineError_state);


    //    machineInit_state->addTransition(this, SIGNAL(enter_printManager_mode()), machinePrintFile_mode);
    //    machinePrintFile_mode->addTransition(this, SIGNAL(enter_manualControl_mode()), machineJogControl_mode);
    //    machinePrintFile_mode->addTransition(lg_port_timer, SIGNAL(timeout()), machineError_state);
    //    machinePrintFile_mode->addTransition(md_port_timer, SIGNAL(timeout()), machineError_state);
    //    machinePrintFile_mode->addTransition(this, SIGNAL(md_port_deviceError(const QString&)), machineError_state);
    //    machinePrintFile_mode->addTransition(this, SIGNAL(lg_port_deviceError(const QString&)), machineError_state);

    //    QState *jogControlInit_state = new QState(machineJogControl_mode);
    //    QState *jogControl_send_lgCommand_state = new QState(machineJogControl_mode);
    //    QState *jogControl_send_mdCommand_state = new QState(machineJogControl_mode);
    //    QState *jogControl_receive_lgReply_state = new QState(machineJogControl_mode);
    //    QState *jogControl_receive_mdReply_state = new QState(machineJogControl_mode);

    //    jogControlInit_state->addTransition(this, SIGNAL(lg_commandPending()), jogControl_send_lgCommand_state);
    //    jogControl_send_lgCommand_state->addTransition(this, SIGNAL(lg_port_txFinished()), jogControl_receive_lgReply_state);
    //    jogControl_receive_lgReply_state->addTransition(this, SIGNAL(lg_port_rxFinished()), jogControlInit_state);

    //    jogControlInit_state->addTransition(this, SIGNAL(md_commandPending()), jogControl_send_mdCommand_state);
    //    jogControl_send_mdCommand_state->addTransition(this, SIGNAL(md_port_txFinished()), jogControl_receive_mdReply_state);
    //    jogControl_receive_mdReply_state->addTransition(this, SIGNAL(md_port_rxFinished()), jogControlInit_state);
    //    machineJogControl_mode->setInitialState(jogControlInit_state);
    //    connect(this, SIGNAL(enter_manualControl_mode()), machineJogControl_mode, SLOT(start()));
    //    connect(this, SIGNAL(enter_manualControl_mode()), machinePrintFile_mode, SLOT(stop()));
    //    connect(this, SIGNAL(enter_printManager_mode()), machinePrintFile_mode, SLOT(start()));
    //    connect(this, SIGNAL(enter_printManager_mode()), machineJogControl_mode, SLOT(stop()));

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
    send_lgCommand_state->addTransition(this, SIGNAL(md_port_error(const QString&)), printRoutine_error_state);
    send_lgCommand_state->addTransition(this, SIGNAL(printRoutine_error(const QString&)), printRoutine_error_state);

    receive_lgReply_state->addTransition(this, SIGNAL(lg_port_error(const QString&)), printRoutine_error_state);
    receive_lgReply_state->addTransition(this, SIGNAL(md_port_error(const QString&)), printRoutine_error_state);
    receive_lgReply_state->addTransition(this, SIGNAL(printRoutine_error(const QString&)), printRoutine_error_state);

    send_mdCommand_state->addTransition(this, SIGNAL(lg_port_error(const QString&)), printRoutine_error_state);
    send_mdCommand_state->addTransition(this, SIGNAL(md_port_error(const QString&)), printRoutine_error_state);
    send_mdCommand_state->addTransition(this, SIGNAL(printRoutine_error(const QString&)), printRoutine_error_state);

    receive_mdReply_state->addTransition(this, SIGNAL(lg_port_error(const QString&)), printRoutine_error_state);
    receive_mdReply_state->addTransition(this, SIGNAL(md_port_error(const QString&)), printRoutine_error_state);
    receive_mdReply_state->addTransition(this, SIGNAL(printRoutine_error(const QString&)), printRoutine_error_state);

    selectNextBlockToProcess_state->addTransition(this, SIGNAL(lg_port_error(const QString&)), printRoutine_error_state);
    selectNextBlockToProcess_state->addTransition(this, SIGNAL(md_port_error(const QString&)), printRoutine_error_state);
    selectNextBlockToProcess_state->addTransition(this, SIGNAL(printRoutine_error(const QString&)), printRoutine_error_state);

    printRoutine->start();
}





PowderDaemon::~PowderDaemon(){


}

float PowderDaemon::xPosition() const
{
    return m_xPosition;
}

void PowderDaemon::setXPosition(float xPosition)
{
    if(xPosition > m_xPosition || xPosition < m_xPosition){
        m_xPosition = xPosition;
        emit xPosition_changed(m_xPosition);
    }
}

float PowderDaemon::yPosition() const
{
    return m_yPosition;
}

void PowderDaemon::setYPosition(float yPosition)
{
    if(yPosition > m_yPosition || yPosition < m_yPosition){
        m_yPosition = yPosition;
        emit yPosition_changed(m_yPosition);
    }
}

float PowderDaemon::zPosition() const
{
    return m_zPosition;
}

void PowderDaemon::setZPosition(float zPosition)
{
    if(zPosition > m_zPosition || zPosition < m_zPosition){
        m_zPosition = zPosition;
        emit zPosition_changed(m_zPosition);
    }
}

float PowderDaemon::sPosition() const
{
    return m_sPosition;
}

void PowderDaemon::setSPosition(float sPosition)
{
    if(sPosition > m_sPosition || sPosition < m_sPosition){
        m_sPosition = sPosition;
        emit sPosition_changed(m_sPosition);
    }
}

float PowderDaemon::hPosition() const
{
    return m_hPosition;
}

void PowderDaemon::setHPosition(float hPosition)
{
    if(hPosition > m_hPosition || hPosition < m_hPosition){
        m_hPosition = hPosition;
        emit hPosition_changed(m_hPosition);
    }
}
int PowderDaemon::laserPower() const
{
    return m_laserPower;
}

void PowderDaemon::setLaserPower(int laserPower)
{
    if(laserPower != m_laserPower){
        m_laserPower = laserPower;
        emit laserPower_changed(m_laserPower);
    }
}

bool PowderDaemon::laserEnableState() const
{
    return m_laserEnableState;
}

void PowderDaemon::setLaserEnableState(bool laserEnableState)
{
    if(laserEnableState != m_laserEnableState){
        m_laserEnableState = laserEnableState;
        emit laserEnableState_changed(m_laserEnableState);
    }
}

bool PowderDaemon::laserArmState() const
{
    return m_laserArmState;
}

void PowderDaemon::setLaserArmState(bool laserArmState)
{
    if(m_laserArmState != laserArmState){
        m_laserArmState = laserArmState;
        emit laserArmState_changed(m_laserArmState);
    }
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
    lg_port_rxBytes.clear();
    const QByteArray txBytes = txString.toUtf8();
    lg_port_TxBytesRemaining = txBytes.length();
    lg_port_timer->start(1000);
    m_lg_port->write(txBytes);
}

void PowderDaemon::write_to_md_port(const QString &txString)
{
    md_port_rxBytes.clear();
    const QByteArray txBytes = txString.toUtf8();
    md_port_TxBytesRemaining = txBytes.length();
    md_port_timer->start(1000);
    m_md_port->write(txBytes);
}

//void PowderDaemon::on_printManager_enabled(const bool enabled)
//{
//    if(enabled){
//        disconnect(this, SIGNAL(lg_port_rxFinished()), this, SLOT(on_lg_jogTransactionComplete()));
//        disconnect(this, SIGNAL(md_port_rxFinished()), this, SLOT(on_md_jogTransactionComplete()));
//        connect(this, SIGNAL(lg_port_rxFinished()), this, SLOT(on_lg_transactionComplete()));
//        connect(this, SIGNAL(md_port_rxFinished()), this, SLOT(on_md_transactionComplete()));
//        emit enter_printManager_mode();
//    }
//}

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

void PowderDaemon::on_lg_port_opened(QSerialPort * const port)
{
    m_lg_port = port;

}

void PowderDaemon::on_md_port_opened(QSerialPort * const port)
{
    m_md_port = port;

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
    QMetaEnum metaEnum = QMetaEnum::fromType<QSerialPort::SerialPortError>();
    emit lg_port_error(metaEnum.valueToKey(portError));
}

void PowderDaemon::on_md_port_error(QSerialPort::SerialPortError portError)
{
    QMetaEnum metaEnum = QMetaEnum::fromType<QSerialPort::SerialPortError>();
    emit md_port_error(metaEnum.valueToKey(portError));
}





void PowderDaemon::on_printRoutine_init()
{
    qDebug()<<"entered printRoutine_init_state";
}

void PowderDaemon::on_generateProcessQueueFromBlock()
{
    bool empty = true;
    m_lg_commandStr.clear();
    m_md_commandStr.clear();
    m_pendingTasks = m_part.get()->getBlock(static_cast<int>(m_currentBlockNumber)).blockTask();

    if(m_pendingTasks != 0){
        if(!m_lg_commandStr.isEmpty()){
            m_lg_commandStr = m_part.get()->getBlock(static_cast<int>(m_currentBlockNumber)).lg_string();
            empty &= m_lg_commandStr.contains("EMPTY");
        }

        if(!m_md_commandStr.isEmpty()){
            m_md_commandStr =  m_part.get()->getBlock(static_cast<int>(m_currentBlockNumber)).md_string();
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
    write_to_lg_port(m_lg_commandStr);
}

void PowderDaemon::on_receive_lgReply()
{

}


void PowderDaemon::on_lg_transactionFinished()
{
    if(m_activeTask & BlockObject::BlockTask::SET_X_POSITION){
        setXPosition(m_part.get()->getBlock(static_cast<int>(m_currentBlockNumber)).x_position());
        if(m_activeTask & BlockObject::BlockTask::SET_HOME_AXIS)
            setXHomed(true);
    }
    if(m_activeTask & BlockObject::BlockTask::SET_Y_POSITION){
        setYPosition(m_part.get()->getBlock(static_cast<int>(m_currentBlockNumber)).y_position());
        if(m_activeTask & BlockObject::BlockTask::SET_HOME_AXIS)
            setYHomed(true);
    }
    //    if(m_activeTask & BlockObject::BlockTask::SET_XY_SPEED)
    //        set(m_part.get()->getBlock(static_cast<int>(m_currentBlockNumber)).xy_speed());

    if(m_activeTask & BlockObject::BlockTask::SET_LASER_ENABLE_STATE)
        setLaserEnableState(m_part.get()->getBlock(static_cast<int>(m_currentBlockNumber)).laser_enabled());
    if(m_activeTask & BlockObject::BlockTask::SET_LASER_ARM_STATE)
        setLaserArmState(m_part.get()->getBlock(static_cast<int>(m_currentBlockNumber)).laser_armed());
    if(m_activeTask & BlockObject::BlockTask::SET_LASER_POWER)
        setLaserPower(m_part.get()->getBlock(static_cast<int>(m_currentBlockNumber)).laser_power());

    m_pendingTasks &= (m_activeTask^0xFFFF);
    if(m_pendingTasks != 0){
        if(m_activeTask & BlockObject::BlockTask::SET_HOME_AXIS)
            m_pendingTasks |= BlockObject::BlockTask::SET_HOME_AXIS;
        emit tasksRemaining();
    }
    else
        emit blockComplete();
}

void PowderDaemon::on_send_mdCommand()
{
    if(m_activeTask & BlockObject::BlockTask::SET_Z_POSITION)
        write_to_md_port(m_md_commandStr.at(0));
    else if(m_pendingTasks & BlockObject::BlockTask::SET_HOPPER_POSITION)
        write_to_md_port(m_md_commandStr.at(1));
    else if(m_pendingTasks & BlockObject::BlockTask::SET_SPREADER_POSITION)
        write_to_md_port(m_md_commandStr.at(2));
}

void PowderDaemon::on_receive_mdReply()
{

}

void PowderDaemon::on_md_transactionFinished()
{
    if(m_activeTask & BlockObject::BlockTask::SET_Z_POSITION){
        setZPosition(m_part.get()->getBlock(static_cast<int>(m_currentBlockNumber)).z_position());
        if(m_activeTask & BlockObject::BlockTask::SET_HOME_AXIS)
            setZHomed(true);
    }
    else if(m_activeTask & BlockObject::BlockTask::SET_HOPPER_POSITION){
        setHPosition(m_part.get()->getBlock(static_cast<int>(m_currentBlockNumber)).hopper_position());
        if(m_activeTask & BlockObject::BlockTask::SET_HOME_AXIS)
            setHHomed(true);
    }
    else if(m_activeTask & BlockObject::BlockTask::SET_SPREADER_POSITION){
        setSPosition(m_part.get()->getBlock(static_cast<int>(m_currentBlockNumber)).spreader_position());
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

void PowderDaemon::on_selectNextBlockToProcess()
{
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

}

void PowderDaemon::on_printRoutine_error()
{

}
//void PowderDaemon::on_manualControl_enabled(const bool enabled)
//{
//    if(enabled){
//        disconnect(this, SIGNAL(lg_port_rxFinished()), this, SLOT(on_lg_transactionComplete()));
//        disconnect(this, SIGNAL(md_port_rxFinished()), this, SLOT(on_md_transactionComplete()));
//        connect(this, SIGNAL(lg_port_rxFinished()), this, SLOT(on_lg_jogTransactionComplete()));
//        connect(this, SIGNAL(md_port_rxFinished()), this, SLOT(on_md_jogTransactionComplete()));
//        emit enter_manualControl_mode();
//    }
//}
//void PowderDaemon::on_lg_jogTransactionComplete()
//{
//    if(pendingTasks & BlockObject::BlockTask::SET_X_POSITION){
//        if(m_lg_commandStr.contains("-")){
//            setXPosition(xPosition()-jogIncrement());
//        }
//        else
//            setXPosition(xPosition()+jogIncrement());
//    }
//    else if(pendingTasks & BlockObject::BlockTask::SET_Y_POSITION){
//        if(m_lg_commandStr.contains("-")){
//            setYPosition(yPosition()-jogIncrement());
//        }
//        else
//            setYPosition(yPosition()+jogIncrement());
//    }
//    m_lg_commandStr.clear();
//    pendingTasks = 0;
//}

//void PowderDaemon::on_md_jogTransactionComplete()
//{
//    if(pendingTasks & BlockObject::BlockTask::SET_Z_POSITION){
//        if(m_md_commandStr.contains("-")){
//            setZPosition(zPosition()-jogIncrement());
//        }
//        else
//            setZPosition(zPosition()+jogIncrement());
//    }
//    else if(pendingTasks & BlockObject::BlockTask::SET_HOPPER_POSITION){
//        if(m_md_commandStr.contains("-")){
//            setHPosition(hPosition()-jogIncrement());
//        }
//        else
//            setHPosition(hPosition()+jogIncrement());
//    }
//    else if(pendingTasks & BlockObject::BlockTask::SET_SPREADER_POSITION){
//        if(m_md_commandStr.contains("-")){
//            setSPosition(sPosition()-jogIncrement());
//        }
//        else
//            setSPosition(sPosition()+jogIncrement());
//    }
//    m_md_commandStr.clear();
//    pendingTasks = 0;
//}
//void PowderDaemon::on_jogIncrement_change(const float jogIncrement)
//{
//    m_jogIncrement = jogIncrement;
//}

//void PowderDaemon::on_homeOption_change(const int homeOption)
//{

//}

//void PowderDaemon::on_home_request()
//{

//}

//void PowderDaemon::on_increment_xPosition_request()
//{

//    if(((m_xPosition + jogIncrement())) < m_config.get()->x_position_max()){
//        const int32_t steps = static_cast<int32_t>(jogIncrement()*m_config.get()->x_position_resolution());
//        m_lg_commandStr = LaserGalvo_Utility::composeJogCommandString(BlockObject::BlockTask::SET_X_POSITION, steps);
//        pendingTasks = BlockObject::BlockTask::SET_X_POSITION;
//        emit lg_commandPending();
//    }

//}

//void PowderDaemon::on_decrement_xPosition_request()
//{

//    if(((m_xPosition - jogIncrement())) > m_config.get()->x_position_min()){
//        const int32_t steps = static_cast<int32_t>(-1*jogIncrement()*m_config.get()->x_position_resolution());
//        m_lg_commandStr = LaserGalvo_Utility::composeJogCommandString(BlockObject::BlockTask::SET_X_POSITION, steps);
//        pendingTasks = BlockObject::BlockTask::SET_X_POSITION;
//        emit lg_commandPending();
//    }
//}

//void PowderDaemon::on_increment_yPosition_request()
//{
//    if(((m_yPosition + jogIncrement())) < m_config.get()->y_position_max()){
//        const int32_t steps = static_cast<int32_t>(jogIncrement()*m_config.get()->y_position_resolution());
//        m_lg_commandStr = LaserGalvo_Utility::composeJogCommandString(BlockObject::BlockTask::SET_Y_POSITION, steps);
//        pendingTasks = BlockObject::BlockTask::SET_Y_POSITION;
//        emit lg_commandPending();
//    }
//}

//void PowderDaemon::on_decrement_yPosition_request()
//{
//    if(((m_yPosition - jogIncrement())) > m_config.get()->y_position_min()){
//        const int32_t steps = static_cast<int32_t>(-1*jogIncrement()*m_config.get()->y_position_resolution());
//        m_lg_commandStr = LaserGalvo_Utility::composeJogCommandString(BlockObject::BlockTask::SET_Y_POSITION, steps);
//        emit lg_commandPending();
//        pendingTasks = BlockObject::BlockTask::SET_Y_POSITION;
//    }
//}

//void PowderDaemon::on_increment_zPosition_request()
//{
//    if(((m_zPosition + jogIncrement())) < m_config.get()->z_position_max()){
//        const int32_t steps = static_cast<int32_t>(jogIncrement()*m_config.get()->z_position_resolution());
//        m_md_commandStr = "/" + QString::number(m_config.get()->z_deviceNumber()) + " " + QString::number(m_config.get()->z_axisNumber());
//        m_md_commandStr += " rel " + QString::number(steps) + "\r";
//        pendingTasks = BlockObject::BlockTask::SET_Z_POSITION;
//        emit md_commandPending();
//    }
//}

//void PowderDaemon::on_decrement_zPosition_request()
//{
//    if(((m_zPosition - jogIncrement())) > m_config.get()->z_position_min()){
//        const int32_t steps = static_cast<int32_t>(-1*jogIncrement()*m_config.get()->z_position_resolution());
//        m_md_commandStr = "/" + QString::number(m_config.get()->z_deviceNumber()) + " " + QString::number(m_config.get()->z_axisNumber());
//        m_md_commandStr += " rel " + QString::number(steps) + "\r";
//        pendingTasks = BlockObject::BlockTask::SET_Z_POSITION;
//        emit md_commandPending();
//    }
//}

//void PowderDaemon::on_increment_hPosition_request()
//{
//    if(((m_hPosition + jogIncrement())) < m_config.get()->hopper_position_max()){
//        const int32_t steps = static_cast<int32_t>(jogIncrement()*m_config.get()->hopper_position_resolution());
//        m_md_commandStr = "/" + QString::number(m_config.get()->hopper_deviceNumber()) + " " + QString::number(m_config.get()->hopper_axisNumber());
//        m_md_commandStr += " rel " + QString::number(steps) + "\r";
//        pendingTasks = BlockObject::BlockTask::SET_HOPPER_POSITION;
//        emit md_commandPending();
//    }
//}

//void PowderDaemon::on_decrement_hPosition_request()
//{
//    if(((m_hPosition - jogIncrement())) > m_config.get()->hopper_position_min()){
//        const int32_t steps = static_cast<int32_t>(-1*jogIncrement()*m_config.get()->hopper_position_resolution());
//        m_md_commandStr = "/" + QString::number(m_config.get()->hopper_deviceNumber()) + " " + QString::number(m_config.get()->hopper_axisNumber());
//        m_md_commandStr += " rel " + QString::number(steps) + "\r";
//        pendingTasks = BlockObject::BlockTask::SET_HOPPER_POSITION;
//        emit md_commandPending();
//    }
//}

//void PowderDaemon::on_increment_sPosition_request()
//{
//    if(((m_sPosition + jogIncrement())) < m_config.get()->spreader_position_max()){
//        const int32_t steps = static_cast<int32_t>(jogIncrement()*m_config.get()->spreader_position_resolution());
//        m_md_commandStr = "/" + QString::number(m_config.get()->spreader_deviceNumber()) + " " + QString::number(m_config.get()->spreader_axisNumber());
//        m_md_commandStr += " rel " + QString::number(steps) + "\r";
//        pendingTasks = BlockObject::BlockTask::SET_SPREADER_POSITION;
//        emit md_commandPending();
//    }
//}

//void PowderDaemon::on_decrement_sPosition_request()
//{
//    if(((m_sPosition - jogIncrement())) > m_config.get()->spreader_position_min()){
//        const int32_t steps = static_cast<int32_t>(-1*jogIncrement()*m_config.get()->spreader_position_resolution());
//        m_md_commandStr = "/" + QString::number(m_config.get()->spreader_deviceNumber()) + " " + QString::number(m_config.get()->spreader_axisNumber());
//        m_md_commandStr += " rel " + QString::number(steps) + "\r";
//        pendingTasks = BlockObject::BlockTask::SET_SPREADER_POSITION;
//        emit md_commandPending();
//    }
//}
