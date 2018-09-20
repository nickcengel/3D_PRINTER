#include "powder_transport.h"

Q_LOGGING_CATEGORY(powder_transport_log, "powder.transport")
Q_LOGGING_CATEGORY(laser_galvo_port_log, "powder.transport.laser_and_galvo.port")
Q_LOGGING_CATEGORY(material_delivery_port_log, "powder.transport.material_delivery.port")
Q_LOGGING_CATEGORY(environment_port_log, "powder.transport.environment.port")

Q_LOGGING_CATEGORY(laser_device_log, "powder.transport.laser")
Q_LOGGING_CATEGORY(galvanometer_device_log, "powder.transport.galvanometer")
Q_LOGGING_CATEGORY(buildPlate_device_log, "powder.transport.build_plate")
Q_LOGGING_CATEGORY(hopperPlate_device_log, "powder.transport.hopper_plate")
Q_LOGGING_CATEGORY(spreaderBlade_device_log, "powder.transport.spreader_blade")
Q_LOGGING_CATEGORY(environment_device_log, "powder.transport.environment")


/*
 * The PowderTransport default constructor instantiates the serial port objects,
 * initializes its local variables, and instantiates the powderDaemon statemachine.
 */

PowderTransport::PowderTransport(QObject *parent) : QObject(parent)
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

    // handle TX bytes
    connect(m_lg_port, SIGNAL(bytesWritten(qint64)),
            this, SLOT(on_lg_port_bytesWritten(qint64)));

    connect(m_md_port, SIGNAL(bytesWritten(qint64)),
            this, SLOT(on_md_port_bytesWritten(qint64)));

    // handle RX bytes
    connect(m_lg_port, SIGNAL(readyRead()),
            this, SLOT(on_lg_port_bytesRead()));

    connect(m_md_port, SIGNAL(readyRead()),
            this, SLOT(on_md_port_bytesRead()));

    // handle port errors
    connect(m_lg_port, SIGNAL(errorOccurred(QSerialPort::SerialPortError)),
            this, SLOT(on_lg_port_error(QSerialPort::SerialPortError)));

    connect(m_md_port, SIGNAL(errorOccurred(QSerialPort::SerialPortError)),
            this, SLOT(on_md_port_error(QSerialPort::SerialPortError)));

    lg_port_timer = new QTimer(this); // used for port timeouts
    lg_port_timer->setSingleShot(true);
    md_port_timer = new QTimer(this); // used for port timeouts
    md_port_timer->setSingleShot(true);
    md_transaction_timer = new QTimer(this); // used to poll device until Idle
    md_transaction_timer->setSingleShot(true);

    QObject::connect(lg_port_timer, SIGNAL(timeout()), this, SLOT(on_lg_portTimeout()));
    QObject::connect(md_port_timer, SIGNAL(timeout()), this, SLOT(on_md_portTimeout()));
    QObject::connect(md_transaction_timer, SIGNAL(timeout()), this, SLOT(poll_mdPort()));

    powderDaemon = new QStateMachine(this);

    // powderDaemon begins in and resets to printRoutine_init_state,
    // where it waits for user input.
    QState *daemonInit_state = new QState(powderDaemon);

    // Durring execution of a print the statemachine first reads a block
    // and sets the pending tasks and desired final values.
    QState *generateProcessQueueFromBlock_state = new QState(powderDaemon);

    // A single task is selected from the pending tasks and designated as the active_task
    QState *selectNextProcessFromQueue_state = new QState(powderDaemon);

    // send_lgCommand_state writes the command string to the lg_port buffer.
    QState *send_lgCommand_state = new QState(powderDaemon);

    // receive_lgReply_state is entered when the transmit buffer has finished being written to the device.
    QState *receive_lgReply_state = new QState(powderDaemon);

    // If the a valid reply is received the statemachine proceeds to the lg_transactionFinished_state
    QState *lg_transactionFinished_state = new QState(powderDaemon);

    // send_mdCommand_state writes the command string to the md_port buffer.
    QState *send_mdCommand_state = new QState(powderDaemon);

    // receive_mdReply_state is entered when the transmit buffer has finished being written to the device.
    QState *receive_mdReply_state = new QState(powderDaemon);

    // If the a valid reply is received the statemachine proceeds to the md_transactionFinished_state
    QState *md_transactionFinished_state = new QState(powderDaemon);

    // If no pending tasks remain, the next block is selected for execution
    QState *selectNextBlockToProcess_state = new QState(powderDaemon);

    // When the final block is written the statemachine enters printFinished_state
    QState *printFinished_state = new QState(powderDaemon);

    // All errors transition the statemachine to daemonError_state
    QState *daemonError_state = new QState(powderDaemon);

    powderDaemon->setInitialState(daemonInit_state);



    // Link daemon states with functions to be evaluated on entering
    connect(daemonInit_state, SIGNAL(entered()), SLOT(on_printRoutine_init()));
    connect(generateProcessQueueFromBlock_state, SIGNAL(entered()), SLOT(on_generateProcessQueueFromBlock()));
    connect(selectNextProcessFromQueue_state, SIGNAL(entered()), SLOT(on_selectProcessFromQueue()));
    connect(send_lgCommand_state, SIGNAL(entered()), SLOT(on_send_lgCommand()));
    connect(receive_lgReply_state, SIGNAL(entered()), SLOT(on_receive_lgReply()));
    connect(lg_transactionFinished_state, SIGNAL(entered()), SLOT(on_lg_transactionFinished()));
    connect(send_mdCommand_state, SIGNAL(entered()), SLOT(on_send_mdCommand()));
    connect(receive_mdReply_state, SIGNAL(entered()), SLOT(on_receive_mdReply()));
    connect(md_transactionFinished_state, SIGNAL(entered()), SLOT(on_md_transactionFinished()));
    connect(selectNextBlockToProcess_state, SIGNAL(entered()), SLOT(on_selectNextBlockToProcess()));
    connect(printFinished_state, SIGNAL(entered()), SLOT(on_printRoutine_finished()));
    connect(daemonError_state, SIGNAL(entered()), SLOT(on_printRoutine_error()));

    // powderDaemon transitions between states in response to signals:

    daemonInit_state->addTransition(this, SIGNAL(startPrint()), generateProcessQueueFromBlock_state);
    daemonInit_state->addTransition(this, SIGNAL(stopPrint()), printFinished_state);
    daemonInit_state->addTransition(this, SIGNAL(lg_port_error(const QString&)), daemonError_state);
    daemonInit_state->addTransition(this, SIGNAL(md_port_error(const QString&)), daemonError_state);
    daemonInit_state->addTransition(this, SIGNAL(printRoutine_error(const QString&)), daemonError_state);
    daemonInit_state->addTransition(this, SIGNAL(lg_commandPending()), send_lgCommand_state);
    daemonInit_state->addTransition(this, SIGNAL(md_commandPending()), send_mdCommand_state);

    generateProcessQueueFromBlock_state->addTransition(this, SIGNAL(blockComplete()), selectNextBlockToProcess_state);
    generateProcessQueueFromBlock_state->addTransition(this, SIGNAL(tasksRemaining()), selectNextProcessFromQueue_state);
    generateProcessQueueFromBlock_state->addTransition(this, SIGNAL(stopPrint()), printFinished_state);

    selectNextProcessFromQueue_state->addTransition(this, SIGNAL(lg_commandPending()), send_lgCommand_state);
    selectNextProcessFromQueue_state->addTransition(this, SIGNAL(md_commandPending()), send_mdCommand_state);
    selectNextProcessFromQueue_state->addTransition(this, SIGNAL(blockComplete()), selectNextBlockToProcess_state);
    selectNextProcessFromQueue_state->addTransition(this, SIGNAL(stopPrint()), printFinished_state);
    selectNextProcessFromQueue_state->addTransition(this, SIGNAL(lg_port_error(const QString&)), daemonError_state);
    selectNextProcessFromQueue_state->addTransition(this, SIGNAL(md_port_error(const QString&)), daemonError_state);
    selectNextProcessFromQueue_state->addTransition(this, SIGNAL(printRoutine_error(const QString&)), daemonError_state);

    selectNextBlockToProcess_state->addTransition(this, SIGNAL(blocksRemaining()), generateProcessQueueFromBlock_state);
    selectNextBlockToProcess_state->addTransition(this, SIGNAL(printFinished()), printFinished_state);
    selectNextBlockToProcess_state->addTransition(this, SIGNAL(stopPrint()), printFinished_state);
    selectNextBlockToProcess_state->addTransition(this, SIGNAL(md_port_error(const QString&)), daemonError_state);
    selectNextBlockToProcess_state->addTransition(this, SIGNAL(printRoutine_error(const QString&)), daemonError_state);

    daemonError_state->addTransition(this, SIGNAL(stopPrint()), printFinished_state);
    daemonError_state->addTransition(this, SIGNAL(resetDaemon()), daemonInit_state);

    printFinished_state->addTransition(this, SIGNAL(startPrint()), daemonInit_state);
    printFinished_state->addTransition(this, SIGNAL(resetDaemon()), daemonInit_state);

    send_lgCommand_state->addTransition(this, SIGNAL(lg_port_txFinished()), receive_lgReply_state);
    send_lgCommand_state->addTransition(this, SIGNAL(stopPrint()), printFinished_state);
    send_lgCommand_state->addTransition(this, SIGNAL(lg_port_error(const QString&)), daemonError_state);
    send_lgCommand_state->addTransition(this, SIGNAL(printRoutine_error(const QString&)), daemonError_state);

    receive_lgReply_state->addTransition(this, SIGNAL(lg_port_rxFinished()), lg_transactionFinished_state);
    receive_lgReply_state->addTransition(this, SIGNAL(stopPrint()), printFinished_state);
    receive_lgReply_state->addTransition(this, SIGNAL(lg_port_error(const QString&)), daemonError_state);
    receive_lgReply_state->addTransition(this, SIGNAL(printRoutine_error(const QString&)), daemonError_state);

    lg_transactionFinished_state->addTransition(this, SIGNAL(tasksRemaining()), selectNextProcessFromQueue_state);
    lg_transactionFinished_state->addTransition(this, SIGNAL(blockComplete()), selectNextBlockToProcess_state);
    lg_transactionFinished_state->addTransition(this, SIGNAL(printRoutine_error(const QString&)), daemonError_state);
    lg_transactionFinished_state->addTransition(this, SIGNAL(jogComplete()), daemonInit_state);

    send_mdCommand_state->addTransition(this, SIGNAL(md_port_txFinished()), receive_mdReply_state);
    send_mdCommand_state->addTransition(this, SIGNAL(md_port_error(const QString&)), daemonError_state);
    send_mdCommand_state->addTransition(this, SIGNAL(printRoutine_error(const QString&)), daemonError_state);
    send_mdCommand_state->addTransition(this, SIGNAL(stopPrint()), printFinished_state);

    receive_mdReply_state->addTransition(this, SIGNAL(md_port_rxFinished()), md_transactionFinished_state);
    receive_mdReply_state->addTransition(this, SIGNAL(stopPrint()), printFinished_state);
    receive_mdReply_state->addTransition(this, SIGNAL(md_port_error(const QString&)), daemonError_state);
    receive_mdReply_state->addTransition(this, SIGNAL(printRoutine_error(const QString&)), daemonError_state);

    md_transactionFinished_state->addTransition(this, SIGNAL(tasksRemaining()), selectNextProcessFromQueue_state);
    md_transactionFinished_state->addTransition(this, SIGNAL(blockComplete()), selectNextBlockToProcess_state);
    md_transactionFinished_state->addTransition(this, SIGNAL(printRoutine_error(const QString&)), daemonError_state);
    md_transactionFinished_state->addTransition(this, SIGNAL(jogComplete()), daemonInit_state);

    powderDaemon->start();
    qWarning(powder_transport_log, "daemon started");
}


PowderTransport::~PowderTransport(){
    if(m_lg_port->isOpen()){
        m_lg_port->clear();
        m_lg_port->close();
    }
    if(m_md_port->isOpen()){
        m_md_port->clear();
        m_md_port->close();
    }
}


float PowderTransport::xPosition() const
{
    return m_xPosition;
}

void PowderTransport::setXPosition(float xPosition)
{
    m_xPosition = xPosition;
    emit xPosition_changed(static_cast<double>(m_xPosition));
}

float PowderTransport::yPosition() const
{
    return m_yPosition;
}

void PowderTransport::setYPosition(float yPosition)
{
    m_yPosition = yPosition;
    emit yPosition_changed(static_cast<double>(m_yPosition));

}

float PowderTransport::xySpeed() const
{
    return m_xySpeed;
}

void PowderTransport::setXYSpeed(float xySpeed)
{
    m_xySpeed = xySpeed;
    emit xySpeed_changed(static_cast<double>(m_xySpeed));
}

float PowderTransport::zPosition() const
{
    return m_zPosition;
}

void PowderTransport::setZPosition(float zPosition)
{
    m_zPosition = zPosition;
    emit zPosition_changed(static_cast<double>(m_zPosition));
}

float PowderTransport::sPosition() const
{
    return m_sPosition;
}

void PowderTransport::setSPosition(float sPosition)
{
    m_sPosition = sPosition;
    emit sPosition_changed(static_cast<double>(m_sPosition));
}

float PowderTransport::hPosition() const
{
    return m_hPosition;
}

void PowderTransport::setHPosition(float hPosition)
{
    m_hPosition = hPosition;
    emit hPosition_changed(static_cast<double>(m_hPosition));
}

int PowderTransport::laserPower() const
{
    return m_laserPower;
}

void PowderTransport::setLaserPower(int laserPower)
{
    m_laserPower = laserPower;
    emit laserPower_changed(m_laserPower);
}

bool PowderTransport::laserEnableState() const
{
    return m_laserEnableState;
}

void PowderTransport::setLaserEnableState(bool laserEnableState)
{
    if(laserEnableState != m_laserEnableState){
        m_laserEnableState = laserEnableState;
        if(m_laserEnableState)
            emit laserEnableState_changed("Laser\nOn");
        else
            emit laserEnableState_changed("Laser\nOff");
    }
}

bool PowderTransport::laserArmState() const
{
    return m_laserArmState;
}

void PowderTransport::setLaserArmState(bool laserArmState)
{
    m_laserArmState = laserArmState;
    emit laserArmState_changed(m_laserArmState);

}

float PowderTransport::jogIncrement() const
{
    return m_jogIncrement;
}

void PowderTransport::setJogIncrement(float jogIncrement)
{
    m_jogIncrement = jogIncrement;
}

bool PowderTransport::xHomed() const
{
    return m_xHomed;
}

void PowderTransport::setXHomed(bool xHomed)
{
    m_xHomed = xHomed;
}

bool PowderTransport::yHomed() const
{
    return m_yHomed;
}

void PowderTransport::setYHomed(bool yHomed)
{
    m_yHomed = yHomed;
}

bool PowderTransport::zHomed() const
{
    return m_zHomed;
}

void PowderTransport::setZHomed(bool zHomed)
{
    m_zHomed = zHomed;
}

bool PowderTransport::hHomed() const
{
    return m_hHomed;
}

void PowderTransport::setHHomed(bool hHomed)
{
    m_hHomed = hHomed;
}

bool PowderTransport::sHomed() const
{
    return m_sHomed;
}

void PowderTransport::setSHomed(bool sHomed)
{
    m_sHomed = sHomed;
}


void PowderTransport::write_to_lg_port(const QString &txString)
{
    if(m_lg_port->isOpen()){
        lg_port_rxBytes.clear();
        const QByteArray txBytes = txString.toUtf8();
        lg_port_TxBytesRemaining = txBytes.length();
        lg_port_timer->start(1000); // timeout in 1000ms
        m_lg_port->write(txBytes);
    }
    else
        emit lg_port_error("Cannot write to closed port");
}

void PowderTransport::write_to_md_port(const QString &txString)
{
    if(m_md_port->isOpen()){
        md_port_rxBytes.clear();
        const QByteArray txBytes = txString.toUtf8();
        md_port_TxBytesRemaining = txBytes.length();
        md_port_timer->start(1000); // timeout in 1000ms
        m_md_port->write(txBytes);
    }
    else
        emit md_port_error("Cannot write to closed port");
}


void PowderTransport::on_lg_port_bytesWritten(qint64 bytes)
{
    lg_port_TxBytesRemaining -= bytes;
    if(lg_port_TxBytesRemaining <= 0)
        emit lg_port_txFinished();
}

void PowderTransport::on_lg_port_bytesRead()
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

void PowderTransport::on_md_port_bytesWritten(qint64 bytes)
{
    md_port_TxBytesRemaining -= bytes;
    if(md_port_TxBytesRemaining <= 0)
        emit md_port_txFinished();
}

void PowderTransport::on_md_port_bytesRead()
{
    // add new bytes.
    md_port_rxBytes +=  m_md_port->readAll();

    if(md_port_rxBytes.length() > 2){ // message contains data
        md_port_timer->stop();
        QString reply = QString::fromUtf8(md_port_rxBytes);

        if(reply.contains("OK", Qt::CaseInsensitive)){ // OK indicates no errors
            float distanceCounts = 0; // holds value of the received distance

            // find the distance data in the reply
            int posIndex = reply.lastIndexOf(" ");
            if(posIndex != -1){
                posIndex += 1;
                distanceCounts = reply.mid(posIndex, reply.indexOf("\r") - posIndex).toFloat();
            }

            // regexs used to determine active device.
            const QString Z_id = "0"+QString::number(m_config.get()->z_deviceNumber())
                    +" " + QString::number(m_config.get()->z_axisNumber());
            const QString H_id = "0"+QString::number(m_config.get()->hopper_deviceNumber())
                    +" " + QString::number(m_config.get()->hopper_axisNumber());
            const QString S_id = "0"+QString::number(m_config.get()->hopper_deviceNumber())
                    +" " + QString::number(m_config.get()->hopper_axisNumber());

            if(reply.contains("IDLE")){ // Idle indicates task was completed
                // update the axis that was modified.
                if(reply.contains(Z_id)){
                    setZPosition(distanceCounts/m_config.get()->z_position_resolution());
                }
                else if(reply.contains(H_id)){
                    setHPosition(distanceCounts/m_config.get()->hopper_position_resolution());
                }
                else if(reply.contains(S_id)){
                    setSPosition(distanceCounts/m_config.get()->spreader_position_resolution());
                }

                emit md_port_deviceReply(reply);
                emit md_port_rxFinished();  // alerts statemachine to continue to next state.
            }
            else if(reply.contains("BUSY")){ // Device is currently executing task
                if(static_cast<int>(distanceCounts)){
                    // update positions if available.
                    if(reply.contains(Z_id)){
                        setZPosition(distanceCounts/m_config.get()->z_position_resolution());
                    }
                    else if(reply.contains(H_id)){
                        setHPosition(distanceCounts/m_config.get()->hopper_position_resolution());
                    }
                    else if(reply.contains(S_id)){
                        setSPosition(distanceCounts/m_config.get()->spreader_position_resolution());
                    }
                }
                // enable polling timer to send a status check in 500ms
                md_transaction_timer->start(500);
            }
        }

        else{ // Did not receive OK
            emit md_port_error(reply); // post error
        }
        md_port_rxBytes.clear();    // clear junk bytes
    }
}


void PowderTransport::on_config_available(QSharedPointer<PowderSettings> config)
{
    m_config = config;
}

void PowderTransport::on_partFile_available(QSharedPointer<PowderPart> part)
{
    m_part = part;
}

void PowderTransport::on_startPrint_request()
{
    emit startPrint();
}

void PowderTransport::on_stopPrint_request()
{
    emit stopPrint();
}

void PowderTransport::on_reset_request()
{
    m_currentBlockNumber = 0;
    m_currentLayerNumber = 0;
    m_pendingTasks = 0;
    m_activeTask = 0;
    m_lg_commandStr.clear();
    m_md_commandStr.clear();
    currentBlockNumber_changed(0);
    currentLayerNumber_changed(0);
    emit resetDaemon();
}


void PowderTransport::on_lg_portTimeout()
{
    emit lg_port_error("Error: Time out");
}

void PowderTransport::on_md_portTimeout()
{
    emit md_port_error("Error: Time out");
}

void PowderTransport::on_lg_port_error(QSerialPort::SerialPortError portError)
{
    if(portError != QSerialPort::SerialPortError::NoError){
        // decode error type
        QMetaEnum metaEnum = QMetaEnum::fromType<QSerialPort::SerialPortError>();
        emit lg_port_error(metaEnum.valueToKey(portError));
    }
}

void PowderTransport::on_md_port_error(QSerialPort::SerialPortError portError)
{
    if(portError != QSerialPort::SerialPortError::NoError){
        // decode error type
        QMetaEnum metaEnum = QMetaEnum::fromType<QSerialPort::SerialPortError>();
        emit md_port_error(metaEnum.valueToKey(portError));
    }
}


void PowderTransport::on_printRoutine_init()
{
    qDebug()<<"entered printRoutine_init_state";
}

void PowderTransport::on_generateProcessQueueFromBlock()
{
    qDebug()<<"entered generateProcessQueueFromBlock_state";

    bool empty = true;
    m_lg_commandStr.clear();
    m_md_commandStr.clear();

    m_pendingTasks = m_part.get()->getBlock(m_currentBlockNumber).blockTask();

    // Find tasks
    if(m_pendingTasks != 0){
        m_lg_commandStr = m_part.get()->getBlock(m_currentBlockNumber).lg_string();
        m_md_commandStr =  m_part.get()->getBlock(m_currentBlockNumber).md_string();
        if(!m_lg_commandStr.contains("EMPTY"))
            empty = false;
        if(!m_md_commandStr.at(0).contains("EMPTY"))
            empty = false;
        if(!m_md_commandStr.at(1).contains("EMPTY"))
            empty = false;
        if(!m_md_commandStr.at(2).contains("EMPTY"))
            empty = false;
    }

    if(!empty){
        emit tasksRemaining();
    }
    else{
        emit blockComplete();
    }
}

void PowderTransport::on_selectProcessFromQueue()
{
    qDebug()<<"entered selectProcessFromQueue_state";

    m_activeTask = 0;

    // set activeTask to a remaining pending task

    if(m_pendingTasks & PowderBlock::BlockTask::SET_HOME_AXIS)
        m_activeTask |= PowderBlock::BlockTask::SET_HOME_AXIS;

    if(m_pendingTasks & (PowderBlock::BlockTask::SET_X_POSITION|PowderBlock::BlockTask::SET_Y_POSITION)){
        if(m_pendingTasks & PowderBlock::BlockTask::SET_X_POSITION)
            m_activeTask |= PowderBlock::BlockTask::SET_X_POSITION;
        if(m_pendingTasks & PowderBlock::BlockTask::SET_Y_POSITION)
            m_activeTask |= PowderBlock::BlockTask::SET_Y_POSITION;
        if(m_pendingTasks & PowderBlock::BlockTask::SET_LASER_ENABLE_STATE)
            m_activeTask |= PowderBlock::BlockTask::SET_LASER_ENABLE_STATE;
        if(m_pendingTasks & PowderBlock::BlockTask::SET_LASER_ARM_STATE)
            m_activeTask |= PowderBlock::BlockTask::SET_LASER_ARM_STATE;
        if(m_pendingTasks & PowderBlock::BlockTask::SET_XY_SPEED)
            m_activeTask |= PowderBlock::BlockTask::SET_XY_SPEED;
        if(m_pendingTasks & PowderBlock::BlockTask::SET_LASER_POWER)
            m_activeTask |= PowderBlock::BlockTask::SET_LASER_POWER;
        emit lg_commandPending();   // found lg command
    }
    else if(m_pendingTasks & PowderBlock::BlockTask::SET_Z_POSITION){
        m_activeTask |= PowderBlock::BlockTask::SET_Z_POSITION;
        emit md_commandPending(); // found md command
    }
    else if(m_pendingTasks & PowderBlock::BlockTask::SET_HOPPER_POSITION){
        m_activeTask |= PowderBlock::BlockTask::SET_HOPPER_POSITION;
        emit md_commandPending(); // found md command
    }
    else if(m_pendingTasks & PowderBlock::BlockTask::SET_SPREADER_POSITION){
        m_activeTask |= PowderBlock::BlockTask::SET_SPREADER_POSITION;
        emit md_commandPending(); // found md command
    }
    else
        emit blockComplete(); // block contains no tasks
}

void PowderTransport::on_send_lgCommand()
{
    qDebug()<<"entered send_lgCommand_state";

    if(m_activeTask & (PowderBlock::BlockTask::SET_X_POSITION|PowderBlock::BlockTask::SET_Y_POSITION)){
        emit galvoBusy();   // tells UI galvo is executing a task
        write_to_lg_port(m_lg_commandStr);
    }
}

void PowderTransport::on_receive_lgReply()
{
    qDebug()<<"entered receive_lgReply_state";
    lg_port_timer->start(1000); // timeout in 1000ms if no reply
}

void PowderTransport::on_lg_transactionFinished()
{
    qDebug()<<"entered lg_transactionFinished_state";

   // if a print is underway update state with block data
    if(m_printModeEnabled){
        if(m_activeTask & PowderBlock::BlockTask::SET_X_POSITION){
            setXPosition(m_part.get()->getBlock(m_currentBlockNumber).x_position());
            if(m_activeTask & PowderBlock::BlockTask::SET_HOME_AXIS)
                setXHomed(true);
        }
        if(m_activeTask & PowderBlock::BlockTask::SET_Y_POSITION){
            setYPosition(m_part.get()->getBlock(m_currentBlockNumber).y_position());
            if(m_activeTask & PowderBlock::BlockTask::SET_HOME_AXIS)
                setYHomed(true);
        }
        if(m_activeTask & PowderBlock::BlockTask::SET_XY_SPEED)
            setXYSpeed(m_part.get()->getBlock(m_currentBlockNumber).xy_speed());

        if(m_activeTask & PowderBlock::BlockTask::SET_LASER_ENABLE_STATE)
            setLaserEnableState(m_part.get()->getBlock(m_currentBlockNumber).laser_enabled());
        if(m_activeTask & PowderBlock::BlockTask::SET_LASER_ARM_STATE)
            setLaserArmState(m_part.get()->getBlock(m_currentBlockNumber).laser_armed());
        if(m_activeTask & PowderBlock::BlockTask::SET_LASER_POWER)
            setLaserPower(m_part.get()->getBlock(m_currentBlockNumber).laser_power());

        m_pendingTasks &= (m_activeTask^0xFFFF);

        if(m_pendingTasks != 0){
            if(m_activeTask & PowderBlock::BlockTask::SET_HOME_AXIS)
                m_pendingTasks |= PowderBlock::BlockTask::SET_HOME_AXIS;
            emit tasksRemaining();
        }
        else
            emit blockComplete();
    }
    // if a manaul move was executed update state with new position
    else if(m_manualModeEnabled){
        if(m_activeTask & PowderBlock::BlockTask::SET_X_POSITION){
            if(m_activeTask & PowderBlock::BlockTask::SET_HOME_AXIS){
                setXHomed(true);
                setXPosition(0);
            }
            else
                setXPosition(xPosition() + m_jogSign*m_jogIncrement);
            m_activeTask = 0;
            emit jogComplete();
        }

        if(m_activeTask & PowderBlock::BlockTask::SET_Y_POSITION){
            if(m_activeTask & PowderBlock::BlockTask::SET_HOME_AXIS){
                setYHomed(true);
                setYPosition(0);
            }
            else
                setYPosition(yPosition() + m_jogSign*m_jogIncrement);
            m_activeTask = 0;
            emit jogComplete();
        }
    }
    else    // neither mode selected.
        emit jogComplete(); // leave current state
}

void PowderTransport::on_send_mdCommand()
{
    qDebug()<<"entered send_mdCommand_state";

    // select and send relevant command string
    if(m_activeTask & PowderBlock::BlockTask::SET_Z_POSITION){
        emit buildPlateBusy();
        write_to_md_port(m_md_commandStr.at(0));
    }
    else if(m_activeTask & PowderBlock::BlockTask::SET_HOPPER_POSITION){
        emit hopperBusy();
        write_to_md_port(m_md_commandStr.at(1));
    }
    else if(m_activeTask & PowderBlock::BlockTask::SET_SPREADER_POSITION){
        emit spreaderBusy();
        write_to_md_port(m_md_commandStr.at(2));
    }
}

void PowderTransport::on_receive_mdReply()
{
    qDebug()<<"entered receive_mdReply_state";
    md_port_timer->start(1000); // timeout in 1000ms if no reply
}

void PowderTransport::on_md_transactionFinished()
{
    qDebug()<<"entered transactionFinished_state";

    // if a print is underway. positions are updated in bytesRead function
    if(m_printModeEnabled){
        if(m_activeTask & PowderBlock::BlockTask::SET_Z_POSITION){
            //            setZPosition(m_part.get()->getBlock(m_currentBlockNumber).z_position());
            if(m_activeTask & PowderBlock::BlockTask::SET_HOME_AXIS)
                setZHomed(true);
        }
        else if(m_activeTask & PowderBlock::BlockTask::SET_HOPPER_POSITION){
            //            setHPosition(m_part.get()->getBlock(m_currentBlockNumber).hopper_position());
            if(m_activeTask & PowderBlock::BlockTask::SET_HOME_AXIS)
                setHHomed(true);
        }
        else if(m_activeTask & PowderBlock::BlockTask::SET_SPREADER_POSITION){
            //            setSPosition(m_part.get()->getBlock(m_currentBlockNumber).spreader_position());
            if(m_activeTask & PowderBlock::BlockTask::SET_HOME_AXIS)
                setSHomed(true);
        }
        m_pendingTasks &= (m_activeTask^0xFFFF);
        if(m_pendingTasks != 0){
            if(m_activeTask & PowderBlock::BlockTask::SET_HOME_AXIS)
                m_pendingTasks |= PowderBlock::BlockTask::SET_HOME_AXIS;
            emit tasksRemaining();
        }
        else
            emit blockComplete();
    }
    // A manual command was executed. positions are updated in bytesRead function
    else if(m_manualModeEnabled){
        if(m_activeTask & PowderBlock::BlockTask::SET_Z_POSITION){
            if(m_activeTask & PowderBlock::BlockTask::SET_HOME_AXIS){
                setZHomed(true);
                //                setZPosition(0);
            }
            //            else
            //                setZPosition(zPosition() + m_jogSign*m_jogIncrement);
            m_activeTask = 0;
            emit jogComplete();
        }
        else if(m_activeTask & PowderBlock::BlockTask::SET_HOPPER_POSITION){
            if(m_activeTask & PowderBlock::BlockTask::SET_HOME_AXIS){
                setHHomed(true);
                //                setHPosition(0);
            }
            //            else
            //                setHPosition(hPosition() + m_jogSign*m_jogIncrement);
            m_activeTask = 0;
            emit jogComplete();
        }
        else if(m_activeTask & PowderBlock::BlockTask::SET_SPREADER_POSITION){
            if(m_activeTask & PowderBlock::BlockTask::SET_HOME_AXIS){
                setSHomed(true);
                //                setSPosition(0);
            }
            //            else
            //                setSPosition(sPosition() + m_jogSign*m_jogIncrement);
            m_activeTask = 0;
            emit jogComplete();
        }
    }
    else // neither mode selected
        emit jogComplete(); // got to next state
}

void PowderTransport::on_selectNextBlockToProcess()
{
    qDebug()<<"entered selectNextBlockToProcess_state";

    if(m_currentBlockNumber < (m_part.get()->blockCount()-1)){
        m_currentBlockNumber += 1;
        emit currentBlockNumber_changed(m_currentBlockNumber);
        if(m_currentLayerNumber != m_part.get()->getBlock(m_currentBlockNumber).layerNumber()){
            m_currentLayerNumber = m_part.get()->getBlock(m_currentBlockNumber).layerNumber();
            emit currentLayerNumber_changed(m_currentLayerNumber);
        }
        emit blocksRemaining();
    }
    else
        emit printFinished();
}

void PowderTransport::on_printRoutine_finished()
{
    qDebug()<<"entered printRoutine_finished_state";

}

void PowderTransport::on_printRoutine_error()
{
    qDebug()<<"entered printRoutine_error_state";
    if(m_lg_port->error() != QSerialPort::SerialPortError::NoError)
        m_lg_port->clearError();    // clear port errors
    if(m_md_port->error() != QSerialPort::SerialPortError::NoError)
        m_md_port->clearError();  // clear port errors
    m_activeTask = 0;
    m_pendingTasks = 0;
}



void PowderTransport::on_printManager_enabled(bool enabled)
{
    m_printModeEnabled = enabled;
    if(enabled)
        m_manualModeEnabled = false;
}

void PowderTransport::on_manualControl_enabled(bool enabled)
{
    m_manualModeEnabled = enabled;
    if(enabled)
        m_printModeEnabled = false;
}

void PowderTransport::on_lgPortName_changed(const QString &name)
{
    if(m_lg_port->isOpen())
        m_lg_port->close();
    m_lg_port->setPortName(name);
}

void PowderTransport::on_mdPortName_changed(const QString &name)
{
    if(m_md_port->isOpen())
        m_md_port->close();
    m_md_port->setPortName(name);
}

void PowderTransport::on_lg_port_connectionRequested(bool open)
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

void PowderTransport::on_md_port_connectionRequested(bool open)
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

void PowderTransport::on_jogIncrement_changed(double jogIncrement)
{
    // update jogincrement with value from ui
    m_jogIncrement = static_cast<float>(jogIncrement);
}

void PowderTransport::on_homeOption_change(int homeOption)
{
    m_homeOption = homeOption;  // sets axis to home
}


void PowderTransport::on_home_request()
{
    switch (m_homeOption) { // select axis to home
    case 0:
    {
        m_activeTask = (PowderBlock::BlockTask::SET_HOME_AXIS|PowderBlock::BlockTask::SET_X_POSITION);
        if(m_lg_port->isOpen())
            emit lg_commandPending();
        break;
    }
    case 1:
    {
        m_activeTask = (PowderBlock::BlockTask::SET_HOME_AXIS|PowderBlock::BlockTask::SET_Y_POSITION);

        if(m_lg_port->isOpen())
            emit lg_commandPending();
        break;
    }
    case 2:
    {
        m_activeTask = (PowderBlock::BlockTask::SET_HOME_AXIS|PowderBlock::BlockTask::SET_Z_POSITION);
        if(m_md_port->isOpen()){
            QString homeStr ="/" + QString::number(m_config.get()->z_deviceNumber()) + " " + QString::number(m_config.get()->z_axisNumber()) + " home\r";
            m_md_commandStr.insert(0,homeStr);
            emit md_commandPending();
        }
        break;
    }
    case 3:
    {
        m_activeTask = (PowderBlock::BlockTask::SET_HOME_AXIS|PowderBlock::BlockTask::SET_HOPPER_POSITION);
        if(m_md_port->isOpen()){
            QString homeStr ="/" + QString::number(m_config.get()->hopper_deviceNumber()) + " " + QString::number(m_config.get()->hopper_axisNumber()) + " home\r";
            m_md_commandStr.insert(1,homeStr);
            emit md_commandPending();
        }
        break;
    }
    case 4:
    {
        m_activeTask = (PowderBlock::BlockTask::SET_HOME_AXIS|PowderBlock::BlockTask::SET_SPREADER_POSITION);
        if(m_md_port->isOpen()){
            QString homeStr ="/" + QString::number(m_config.get()->spreader_deviceNumber()) + " " + QString::number(m_config.get()->spreader_axisNumber()) + " home\r";
            m_md_commandStr.insert(2,homeStr);
            emit md_commandPending();
        }
        break;
    }
    default:
        m_activeTask = 0;
        emit printRoutine_error("No Axis to Home");
        break;
    }
}

void PowderTransport::on_increment_xPosition_request()
{
    if(((m_xPosition + jogIncrement())) < m_config.get()->x_position_max()){
        m_jogSign = 1.0;
        const int32_t steps = static_cast<int32_t>(jogIncrement()*m_config.get()->x_position_resolution());
        m_lg_commandStr = LaserGalvo_Utility::composeJogCommandString(PowderBlock::BlockTask::SET_X_POSITION, steps);
        m_activeTask = PowderBlock::BlockTask::SET_X_POSITION;
        emit lg_commandPending();
    }
}

void PowderTransport::on_decrement_xPosition_request()
{
    if(((m_xPosition - jogIncrement())) > m_config.get()->x_position_min()){
        m_jogSign = -1.0;
        const int32_t steps = static_cast<int32_t>(-1*jogIncrement()*m_config.get()->x_position_resolution());
        m_lg_commandStr = LaserGalvo_Utility::composeJogCommandString(PowderBlock::BlockTask::SET_X_POSITION, steps);
        m_activeTask = PowderBlock::BlockTask::SET_X_POSITION;
        emit lg_commandPending();
    }
}

void PowderTransport::on_increment_yPosition_request()
{
    if(((m_yPosition + jogIncrement())) < m_config.get()->y_position_max()){
        m_jogSign = 1.0;
        const int32_t steps = static_cast<int32_t>(jogIncrement()*m_config.get()->y_position_resolution());
        m_lg_commandStr = LaserGalvo_Utility::composeJogCommandString(PowderBlock::BlockTask::SET_Y_POSITION, steps);
        m_activeTask = PowderBlock::BlockTask::SET_Y_POSITION;
        emit lg_commandPending();
    }
}

void PowderTransport::on_decrement_yPosition_request()
{
    if(((m_yPosition - jogIncrement())) > m_config.get()->y_position_min()){
        m_jogSign = -1.0;
        const int32_t steps = static_cast<int32_t>(-1*jogIncrement()*m_config.get()->y_position_resolution());
        m_lg_commandStr = LaserGalvo_Utility::composeJogCommandString(PowderBlock::BlockTask::SET_Y_POSITION, steps);
        m_activeTask = PowderBlock::BlockTask::SET_Y_POSITION;
        emit lg_commandPending();
    }
}

void PowderTransport::on_increment_zPosition_request()
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
        m_activeTask = PowderBlock::BlockTask::SET_Z_POSITION;
        emit md_commandPending();
    }
}

void PowderTransport::on_decrement_zPosition_request()
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
        m_activeTask = PowderBlock::BlockTask::SET_Z_POSITION;
        emit md_commandPending();
    }
}

void PowderTransport::on_increment_hPosition_request()
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
        m_activeTask = PowderBlock::BlockTask::SET_HOPPER_POSITION;
        emit md_commandPending();
    }
}

void PowderTransport::on_decrement_hPosition_request()
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
        m_activeTask = PowderBlock::BlockTask::SET_HOPPER_POSITION;
        emit md_commandPending();
    }
}

void PowderTransport::on_increment_sPosition_request()
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
        m_activeTask = PowderBlock::BlockTask::SET_SPREADER_POSITION;
        emit md_commandPending();
    }
}

void PowderTransport::on_decrement_sPosition_request()
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
        m_activeTask = PowderBlock::BlockTask::SET_SPREADER_POSITION;
        emit md_commandPending();
    }
}

void PowderTransport::on_clearError_request()
{
    emit resetDaemon();
}


void PowderTransport::ping_laserGalvo()
{
    // write an empty command
    m_lg_commandStr = "$()";
    m_activeTask = PowderBlock::BlockTask::SET_X_POSITION|PowderBlock::BlockTask::SET_Y_POSITION;
    emit lg_commandPending();
}

void PowderTransport::ping_materialDelivery(int devNum, int axisNum)
{
    // write an empty command
    if(devNum == m_config.get()->z_deviceNumber()){
        const QString pingStr ="/" + QString::number(devNum) + " " + QString::number(axisNum) + "\r";
        m_md_commandStr.insert(0, pingStr);
        m_activeTask = PowderBlock::BlockTask::SET_Z_POSITION;
        emit md_commandPending();
    }
    else if((devNum == m_config.get()->hopper_deviceNumber())&&(axisNum == m_config.get()->hopper_axisNumber())){
        const QString pingStr ="/" + QString::number(devNum) + " " + QString::number(axisNum) + "\r";
        m_md_commandStr.insert(1, pingStr);
        m_activeTask = PowderBlock::BlockTask::SET_HOPPER_POSITION;
        emit md_commandPending();
    }
    else if((devNum == m_config.get()->spreader_deviceNumber())&&(axisNum == m_config.get()->spreader_axisNumber())){
        const QString pingStr ="/" + QString::number(devNum) + " " + QString::number(axisNum) + "\r";
        m_md_commandStr.insert(2, pingStr);
        m_activeTask = PowderBlock::BlockTask::SET_SPREADER_POSITION;
        emit md_commandPending();
    }
    else if((devNum == m_config.get()->hopper_deviceNumber())||(devNum == m_config.get()->spreader_deviceNumber())){
        const QString pingStr ="/" + QString::number(devNum) +"\r";
        m_md_commandStr.insert(1, pingStr);
        m_activeTask = PowderBlock::BlockTask::SET_HOPPER_POSITION;
        emit md_commandPending();
    }
}

void PowderTransport::poll_mdPort()
{
    // poll md device for current position while return status is BUSY
    QString requestStr;
    if(m_activeTask & PowderBlock::BlockTask::SET_Z_POSITION){
        requestStr ="/" + QString::number(m_config.get()->z_deviceNumber()) + " " + QString::number(m_config.get()->z_axisNumber())
                + " get pos" + "\r";
    }
    else if(m_activeTask & PowderBlock::BlockTask::SET_HOPPER_POSITION){
        requestStr ="/" + QString::number(m_config.get()->hopper_deviceNumber()) + " " + QString::number(m_config.get()->hopper_axisNumber())
                + " get pos" + "\r";
    }
    else if(m_activeTask & PowderBlock::BlockTask::SET_SPREADER_POSITION){
        requestStr ="/" + QString::number(m_config.get()->spreader_deviceNumber()) + " " + QString::number(m_config.get()->spreader_axisNumber())
                + " get pos" + "\r";
    }

    if(!requestStr.isEmpty()){
        write_to_md_port(requestStr);
    }
    else    // did not formulate a position request
        emit md_port_error("Could Not Confirm Command");
}
