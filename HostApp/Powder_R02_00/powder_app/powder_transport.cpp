#include "powder_transport.h"

Q_LOGGING_CATEGORY(powder_transport_log, "powder.transport")
Q_LOGGING_CATEGORY(laser_port_log, "powder.transport.laser.port")
Q_LOGGING_CATEGORY(galvo_port_log, "powder.transport.galvo.port")
Q_LOGGING_CATEGORY(material_delivery_port_log, "powder.transport.material_delivery.port")

Q_LOGGING_CATEGORY(laser_device_log, "powder.transport.laser")
Q_LOGGING_CATEGORY(galvanometer_device_log, "powder.transport.galvanometer")
Q_LOGGING_CATEGORY(buildPlate_device_log, "powder.transport.build_plate")
Q_LOGGING_CATEGORY(hopperPlate_device_log, "powder.transport.hopper_plate")
Q_LOGGING_CATEGORY(spreaderBlade_device_log, "powder.transport.spreader_blade")


/*
 * The PowderTransport default constructor instantiates the serial port objects,
 * initializes its local variables, and instantiates the powderDaemon statemachine.
 */

PowderTransport::PowderTransport(QObject *parent) : QObject(parent)
{
    m_laser_port = new QSerialPort(this);
    m_galvo_port = new QSerialPort(this);
    m_md_port = new QSerialPort(this);

    m_galvo_port->setBaudRate(115200);
    m_md_port->setBaudRate(115200);
    m_laser_port->setBaudRate(9600);

    m_manualModeEnabled = false;
    m_printModeEnabled = false;

    m_xPosition = 0;
    m_yPosition = 0;
    m_zPosition = 0;
    m_sPosition = 0;
    m_hPosition = 0;
    m_xySpeed = 0;
    m_zSpeed = 0;
    m_sSpeed = 0;
    m_hSpeed = 0;

    m_laserIntensity = 0;
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

    laser_port_TxBytesRemaining = 0;
    galvo_port_TxBytesRemaining = 0;
    md_port_TxBytesRemaining = 0;

    m_laser_commandStr.append({"EMPTY","EMPTY","EMPTY","EMPTY"});
    m_galvo_commandStr = "EMPTY";
    m_md_SpeedCommandStr.append({"EMPTY","EMPTY","EMPTY"});
    m_md_PositionCommandStr.append({"EMPTY","EMPTY","EMPTY"});

    // handle TX bytes
    connect(m_laser_port, SIGNAL(bytesWritten(qint64)),
            this, SLOT(on_laser_port_bytesWritten(qint64)));

    connect(m_galvo_port, SIGNAL(bytesWritten(qint64)),
            this, SLOT(on_galvo_port_bytesWritten(qint64)));

    connect(m_md_port, SIGNAL(bytesWritten(qint64)),
            this, SLOT(on_md_port_bytesWritten(qint64)));

    // handle RX bytes
    connect(m_laser_port, SIGNAL(readyRead()),
            this, SLOT(on_laser_port_bytesRead()));

    connect(m_galvo_port, SIGNAL(readyRead()),
            this, SLOT(on_galvo_port_bytesRead()));

    connect(m_md_port, SIGNAL(readyRead()),
            this, SLOT(on_md_port_bytesRead()));

    // handle port errors
    connect(m_laser_port, SIGNAL(errorOccurred(QSerialPort::SerialPortError)),
            this, SLOT(on_laser_port_error(QSerialPort::SerialPortError)));

    connect(m_galvo_port, SIGNAL(errorOccurred(QSerialPort::SerialPortError)),
            this, SLOT(on_galvo_port_error(QSerialPort::SerialPortError)));

    connect(m_md_port, SIGNAL(errorOccurred(QSerialPort::SerialPortError)),
            this, SLOT(on_md_port_error(QSerialPort::SerialPortError)));


    laserPort_timer = new QTimer(this); // used for port timeouts
    laserPort_timer->setSingleShot(true);
    QObject::connect(laserPort_timer, SIGNAL(timeout()), this, SLOT(on_laser_portTimeout()));

    galvoPort_timer = new QTimer(this); // used for port timeouts
    galvoPort_timer->setSingleShot(true);
    QObject::connect(galvoPort_timer, SIGNAL(timeout()), this, SLOT(on_galvo_portTimeout()));

    materialDeliveryPort_timer = new QTimer(this); // used for port timeouts
    materialDeliveryPort_timer->setSingleShot(true);
    QObject::connect(materialDeliveryPort_timer, SIGNAL(timeout()), this, SLOT(on_md_portTimeout()));

    materialDeliveryPoll_timer = new QTimer(this); // used to poll device until Idle
    materialDeliveryPoll_timer->setSingleShot(true);
    QObject::connect(materialDeliveryPoll_timer, SIGNAL(timeout()), this, SLOT(poll_mdPort()));


    powderDaemon = new QStateMachine(this);

    // powderDaemon begins in and resets to printRoutine_init_state,
    // where it waits for user input.
    QState *daemonInit_state = new QState(powderDaemon);

    // Durring execution of a print the statemachine first reads a block
    // and sets the pending tasks and desired final values.
    QState *generateProcessQueueFromBlock_state = new QState(powderDaemon);

    // A single task is selected from the pending tasks and designated as the active_task
    QState *selectNextProcessFromQueue_state = new QState(powderDaemon);

    // send_galvoCommand_state writes the command string to the galvo_port buffer.
    QState *send_laserCommand_state = new QState(powderDaemon);

    // receive_galvoReply_state is entered when the transmit buffer has finished being written to the device.
    QState *receive_laserReply_state = new QState(powderDaemon);

    // If the a valid reply is received the statemachine proceeds to the galvo_transactionFinished_state
    QState *laser_transactionFinished_state = new QState(powderDaemon);


    // send_galvoCommand_state writes the command string to the galvo_port buffer.
    QState *send_galvoCommand_state = new QState(powderDaemon);

    // receive_galvoReply_state is entered when the transmit buffer has finished being written to the device.
    QState *receive_galvoReply_state = new QState(powderDaemon);

    // If the a valid reply is received the statemachine proceeds to the galvo_transactionFinished_state
    QState *galvo_transactionFinished_state = new QState(powderDaemon);

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

    connect(send_laserCommand_state, SIGNAL(entered()), SLOT(on_send_laserCommand()));
    connect(receive_laserReply_state, SIGNAL(entered()), SLOT(on_receive_laserReply()));
    connect(laser_transactionFinished_state, SIGNAL(entered()), SLOT(on_laser_transactionFinished()));

    connect(send_galvoCommand_state, SIGNAL(entered()), SLOT(on_send_galvoCommand()));
    connect(receive_galvoReply_state, SIGNAL(entered()), SLOT(on_receive_galvoReply()));
    connect(galvo_transactionFinished_state, SIGNAL(entered()), SLOT(on_galvo_transactionFinished()));

    connect(send_mdCommand_state, SIGNAL(entered()), SLOT(on_send_mdCommand()));
    connect(receive_mdReply_state, SIGNAL(entered()), SLOT(on_receive_mdReply()));
    connect(md_transactionFinished_state, SIGNAL(entered()), SLOT(on_md_transactionFinished()));

    connect(selectNextBlockToProcess_state, SIGNAL(entered()), SLOT(on_selectNextBlockToProcess()));
    connect(printFinished_state, SIGNAL(entered()), SLOT(on_printRoutine_finished()));
    connect(daemonError_state, SIGNAL(entered()), SLOT(on_printRoutine_error()));

    // powderDaemon transitions between states in response to signals:

    daemonInit_state->addTransition(this, SIGNAL(startPrint()), generateProcessQueueFromBlock_state);
    daemonInit_state->addTransition(this, SIGNAL(stopPrint()), printFinished_state);

    daemonInit_state->addTransition(this, SIGNAL(laser_error(const QString&)), daemonError_state);
    daemonInit_state->addTransition(this, SIGNAL(laser_commandPending()), send_laserCommand_state);
    daemonInit_state->addTransition(this, SIGNAL(galvo_error(const QString&)), daemonError_state);
    daemonInit_state->addTransition(this, SIGNAL(galvo_commandPending()), send_galvoCommand_state);
    daemonInit_state->addTransition(this, SIGNAL(md_port_error(const QString&)), daemonError_state);
    daemonInit_state->addTransition(this, SIGNAL(md_commandPending()), send_mdCommand_state);
    daemonInit_state->addTransition(this, SIGNAL(transport_error(const QString&)), daemonError_state);

    generateProcessQueueFromBlock_state->addTransition(this, SIGNAL(blockComplete()), selectNextBlockToProcess_state);
    generateProcessQueueFromBlock_state->addTransition(this, SIGNAL(tasksRemaining()), selectNextProcessFromQueue_state);
    generateProcessQueueFromBlock_state->addTransition(this, SIGNAL(stopPrint()), printFinished_state);

    selectNextProcessFromQueue_state->addTransition(this, SIGNAL(laser_commandPending()), send_laserCommand_state);
    selectNextProcessFromQueue_state->addTransition(this, SIGNAL(laser_error(const QString&)), daemonError_state);

    selectNextProcessFromQueue_state->addTransition(this, SIGNAL(galvo_commandPending()), send_galvoCommand_state);
    selectNextProcessFromQueue_state->addTransition(this, SIGNAL(galvo_error(const QString&)), daemonError_state);

    selectNextProcessFromQueue_state->addTransition(this, SIGNAL(md_commandPending()), send_mdCommand_state);
    selectNextProcessFromQueue_state->addTransition(this, SIGNAL(md_port_error(const QString&)), daemonError_state);

    selectNextProcessFromQueue_state->addTransition(this, SIGNAL(blockComplete()), selectNextBlockToProcess_state);
    selectNextProcessFromQueue_state->addTransition(this, SIGNAL(stopPrint()), printFinished_state);
    selectNextProcessFromQueue_state->addTransition(this, SIGNAL(transport_error(const QString&)), daemonError_state);

    selectNextBlockToProcess_state->addTransition(this, SIGNAL(blocksRemaining()), generateProcessQueueFromBlock_state);
    selectNextBlockToProcess_state->addTransition(this, SIGNAL(printFinished()), printFinished_state);
    selectNextBlockToProcess_state->addTransition(this, SIGNAL(stopPrint()), printFinished_state);

    selectNextBlockToProcess_state->addTransition(this, SIGNAL(laser_error(const QString&)), daemonError_state);
    selectNextBlockToProcess_state->addTransition(this, SIGNAL(galvo_error(const QString&)), daemonError_state);
    selectNextBlockToProcess_state->addTransition(this, SIGNAL(md_port_error(const QString&)), daemonError_state);
    selectNextBlockToProcess_state->addTransition(this, SIGNAL(transport_error(const QString&)), daemonError_state);

    daemonError_state->addTransition(this, SIGNAL(stopPrint()), printFinished_state);
    daemonError_state->addTransition(this, SIGNAL(resetDaemon()), daemonInit_state);

    printFinished_state->addTransition(this, SIGNAL(startPrint()), daemonInit_state);
    printFinished_state->addTransition(this, SIGNAL(resetDaemon()), daemonInit_state);


    send_laserCommand_state->addTransition(this, SIGNAL(laser_port_txFinished()), receive_laserReply_state);
    send_laserCommand_state->addTransition(this, SIGNAL(stopPrint()), printFinished_state);
    send_laserCommand_state->addTransition(this, SIGNAL(laser_error(const QString&)), daemonError_state);
    send_laserCommand_state->addTransition(this, SIGNAL(transport_error(const QString&)), daemonError_state);

    receive_laserReply_state->addTransition(this, SIGNAL(laser_port_rxFinished()), laser_transactionFinished_state);
    receive_laserReply_state->addTransition(this, SIGNAL(stopPrint()), printFinished_state);
    receive_laserReply_state->addTransition(this, SIGNAL(laser_error(const QString&)), daemonError_state);
    receive_laserReply_state->addTransition(this, SIGNAL(transport_error(const QString&)), daemonError_state);

    laser_transactionFinished_state->addTransition(this, SIGNAL(tasksRemaining()), selectNextProcessFromQueue_state);
    laser_transactionFinished_state->addTransition(this, SIGNAL(blockComplete()), selectNextBlockToProcess_state);
    laser_transactionFinished_state->addTransition(this, SIGNAL(transport_error(const QString&)), daemonError_state);

    send_galvoCommand_state->addTransition(this, SIGNAL(galvo_port_txFinished()), receive_galvoReply_state);
    send_galvoCommand_state->addTransition(this, SIGNAL(stopPrint()), printFinished_state);
    send_galvoCommand_state->addTransition(this, SIGNAL(galvo_error(const QString&)), daemonError_state);
    send_galvoCommand_state->addTransition(this, SIGNAL(transport_error(const QString&)), daemonError_state);

    receive_galvoReply_state->addTransition(this, SIGNAL(galvo_port_rxFinished()), galvo_transactionFinished_state);
    receive_galvoReply_state->addTransition(this, SIGNAL(stopPrint()), printFinished_state);
    receive_galvoReply_state->addTransition(this, SIGNAL(galvo_error(const QString&)), daemonError_state);
    receive_galvoReply_state->addTransition(this, SIGNAL(transport_error(const QString&)), daemonError_state);

    galvo_transactionFinished_state->addTransition(this, SIGNAL(tasksRemaining()), selectNextProcessFromQueue_state);
    galvo_transactionFinished_state->addTransition(this, SIGNAL(blockComplete()), selectNextBlockToProcess_state);
    galvo_transactionFinished_state->addTransition(this, SIGNAL(transport_error(const QString&)), daemonError_state);
    galvo_transactionFinished_state->addTransition(this, SIGNAL(jogComplete()), daemonInit_state);

    send_mdCommand_state->addTransition(this, SIGNAL(md_port_txFinished()), receive_mdReply_state);
    send_mdCommand_state->addTransition(this, SIGNAL(md_port_error(const QString&)), daemonError_state);
    send_mdCommand_state->addTransition(this, SIGNAL(transport_error(const QString&)), daemonError_state);
    send_mdCommand_state->addTransition(this, SIGNAL(stopPrint()), printFinished_state);

    receive_mdReply_state->addTransition(this, SIGNAL(md_port_rxFinished()), md_transactionFinished_state);
    receive_mdReply_state->addTransition(this, SIGNAL(stopPrint()), printFinished_state);
    receive_mdReply_state->addTransition(this, SIGNAL(md_port_error(const QString&)), daemonError_state);
    receive_mdReply_state->addTransition(this, SIGNAL(transport_error(const QString&)), daemonError_state);

    md_transactionFinished_state->addTransition(this, SIGNAL(tasksRemaining()), selectNextProcessFromQueue_state);
    md_transactionFinished_state->addTransition(this, SIGNAL(blockComplete()), selectNextBlockToProcess_state);
    md_transactionFinished_state->addTransition(this, SIGNAL(transport_error(const QString&)), daemonError_state);
    md_transactionFinished_state->addTransition(this, SIGNAL(jogComplete()), daemonInit_state);

    powderDaemon->start();
    qWarning(powder_transport_log, "daemon started");
    m_md_PositionCommandStr.append("EMPTY");
    m_md_PositionCommandStr.append("EMPTY");
    m_md_PositionCommandStr.append("EMPTY");
}


PowderTransport::~PowderTransport(){
    if(m_galvo_port->isOpen()){
        m_galvo_port->clear();
        m_galvo_port->close();
    }
    if(m_md_port->isOpen()){
        m_md_port->clear();
        m_md_port->close();
    }

    if(m_laser_port->isOpen()){
        m_laser_port->clear();
        m_laser_port->close();
    }
}


float PowderTransport::xPosition() const
{
    return m_xPosition;
}

void PowderTransport::setXPosition(float xPosition)
{
    m_xPosition = xPosition;
    const QString pos = QString::number(static_cast<double>(m_xPosition), 'f', 3);
    emit xPosition_changed(pos);
}

float PowderTransport::yPosition() const
{
    return m_yPosition;
}

void PowderTransport::setYPosition(float yPosition)
{
    m_yPosition = yPosition;
    const QString pos = QString::number(static_cast<double>(m_yPosition), 'f', 3);
    emit yPosition_changed(pos);
}

float PowderTransport::xySpeed() const
{
    return m_xySpeed;
}

void PowderTransport::setXYSpeed(float xySpeed)
{
    m_xySpeed = xySpeed;
    const QString spd = QString::number(static_cast<double>(m_xySpeed), 'f', 3);
    emit xySpeed_changed(spd);
}

float PowderTransport::zPosition() const
{
    return m_zPosition;
}

void PowderTransport::setZPosition(float zPosition)
{
    m_zPosition = zPosition;
    const QString pos = QString::number(static_cast<double>(m_zPosition), 'f', 3);
    emit zPosition_changed(pos);
}

float PowderTransport::sPosition() const
{
    return m_sPosition;
}

void PowderTransport::setSPosition(float sPosition)
{
    m_sPosition = sPosition;
    const QString pos = QString::number(static_cast<double>(m_sPosition), 'f', 3);
    emit sPosition_changed(pos);
}

float PowderTransport::hPosition() const
{
    return m_hPosition;
}

void PowderTransport::setHPosition(float hPosition)
{
    m_hPosition = hPosition;
    const QString pos = QString::number(static_cast<double>(m_hPosition), 'f', 3);
    emit hPosition_changed(pos);
}

float PowderTransport::laserIntensity() const
{
    return m_laserIntensity;
}

void PowderTransport::setLaserIntensity(float laserIntensity)
{
    m_laserIntensity = laserIntensity;
    emit laserIntensity_changed(static_cast<double>(m_laserIntensity));
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

void PowderTransport::write_to_laser_port(const QString &txString)
{
    if(m_laser_port->isOpen()){
        laser_port_rxBytes.clear();
        const QByteArray txBytes = txString.toUtf8();
        laser_port_TxBytesRemaining = txBytes.length();
        laserPort_timer->start(1000); // timeout in 1000ms
        m_laser_port->write(txBytes);
    }
    else
        emit laser_error("Cannot write to closed port");}


void PowderTransport::write_to_galvo_port(const QString &txString)
{
    if(m_galvo_port->isOpen()){
//        m_galvo_port->clear();
        const QByteArray txBytes = txString.toUtf8();
        galvo_port_TxBytesRemaining = txBytes.length();
        galvoPort_timer->start(1000); // timeout in 1000ms
        m_galvo_port->write(txBytes);
    }
    else
        emit galvo_error("Cannot write to closed port");
}

void PowderTransport::write_to_md_port(const QString &txString)
{
    if(m_md_port->isOpen()){
        md_port_rxBytes.clear();
        const QByteArray txBytes = txString.toUtf8();
        md_port_TxBytesRemaining = txBytes.length();
        materialDeliveryPort_timer->start(1000); // timeout in 1000ms
        m_md_port->write(txBytes);
    }
    else
        emit md_port_error("Cannot write to closed port");
}


void PowderTransport::on_galvo_port_bytesWritten(qint64 bytes)
{
    galvo_port_TxBytesRemaining -= bytes;
    if(galvo_port_TxBytesRemaining <= 0){
        galvoPort_timer->stop();
        emit galvo_port_txFinished();
    }
}

void PowderTransport::on_galvo_port_bytesRead()
{

    if(m_galvo_port->canReadLine()){
        galvoPort_timer->stop();
        galvo_port_rxBytes =  m_galvo_port->readLine();
        QString reply = QString::fromUtf8(galvo_port_rxBytes);

        bool numValid = true;
        if(reply.contains("ok", Qt::CaseInsensitive)){
            int xDataIndex = reply.indexOf("X") + 1;
            if(xDataIndex > 0){
                int xDataLen = reply.indexOf(" ", xDataIndex) - xDataIndex;
                int xData = reply.mid(xDataIndex, xDataLen).toInt(&numValid,10);
                if(numValid){
                    setXPosition(xData/m_config.get()->x_position_resolution());
                }
            }
            int yDataIndex = reply.indexOf("Y") + 1;
            if(yDataIndex > 0){
                int yDataLen = reply.indexOf(" ", yDataIndex) - yDataIndex;
                int yData = reply.mid(yDataIndex, yDataLen).toInt(&numValid,10);
                if(numValid){
                    setYPosition(yData/m_config.get()->y_position_resolution());
                }
            }
            int sDataIndex = reply.indexOf("S") + 1;
            if(sDataIndex > 0){
                int sDataLen = reply.indexOf(" ", sDataIndex) - sDataIndex;
                int sData = reply.mid(sDataIndex, sDataLen).toInt(&numValid,10);
                if(numValid){
                    setXYSpeed(sData);
                }
            }
            int lDataIndex = reply.indexOf("L") + 1;
            if(lDataIndex > 0){
                bool lData = (reply.at(lDataIndex) == '1');
                if(lData){
                    setLaserEnableState(true);
                }
                else
                    setLaserEnableState(false);
            }
            emit galvo_deviceReply(reply);
            emit galvo_port_rxFinished();
        }
        else{
            emit galvo_error(reply);
        }
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
        materialDeliveryPort_timer->stop();
        QString reply = QString::fromUtf8(md_port_rxBytes);

        // OK indicates no errors - Accept the reply and process it
        if(reply.contains("OK", Qt::CaseInsensitive)){
            float replyData = 0; // holds value of the received data

            // find the data in the reply
            int posIndex = reply.lastIndexOf(" ");
            if(posIndex != -1){
                posIndex += 1;
                replyData = reply.mid(posIndex, reply.indexOf("\r") - posIndex).toFloat();
            }
            // regexs used to determine active device.
            const QString Z_id = "0"+QString::number(m_config.get()->z_deviceNumber())
                    +" " + QString::number(m_config.get()->z_axisNumber());
            const QString H_id = "0"+QString::number(m_config.get()->hopper_deviceNumber())
                    +" " + QString::number(m_config.get()->hopper_axisNumber());
            const QString S_id = "0"+QString::number(m_config.get()->hopper_deviceNumber())
                    +" " + QString::number(m_config.get()->hopper_axisNumber());

            if(reply.contains("IDLE")){ // Idle indicates task was completed
                // update the axis that was modified during a position change

                if(reply.contains(Z_id)){
                    if(m_activeTask & (PowderBlock::BlockTask::SET_Z_POSITION))
                    {
                        setZPosition(replyData/m_config.get()->z_position_resolution());
                    }
                    else if(m_activeTask & (PowderBlock::BlockTask::SET_Z_SPEED))
                    {
                        setZSpeed(replyData/(1.6384f*m_config.get()->z_position_resolution()));
                    }
                    emit buildPlate_deviceReply(reply);
                }
                else if(reply.contains(H_id)){
                    if(m_activeTask & (PowderBlock::BlockTask::SET_HOPPER_POSITION))
                    {
                        setHPosition(replyData/m_config.get()->hopper_position_resolution());
                    }
                    else if(m_activeTask & (PowderBlock::BlockTask::SET_HOPPER_SPEED))
                    {
                        setHSpeed(replyData/(1.6384f*m_config.get()->hopper_position_resolution()));
                    }
                    emit hopper_deviceReply(reply);
                }
                else if(reply.contains(S_id)){
                    if(m_activeTask & (PowderBlock::BlockTask::SET_SPREADER_POSITION))
                    {
                        setSPosition(replyData/m_config.get()->spreader_position_resolution());
                    }
                    else if(m_activeTask & (PowderBlock::BlockTask::SET_SPREADER_SPEED))
                    {
                        setSSpeed(replyData/(1.6384f*m_config.get()->spreader_position_resolution()));
                    }
                    emit spreader_deviceReply(reply);
                }
                emit md_port_rxFinished();  // alerts statemachine to continue to next state.
            }
            else if(reply.contains("BUSY")){ // Device is currently executing task
                if(static_cast<int>(replyData)){
                    // update positions if available.
                    if(reply.contains(Z_id)){
                        setZPosition(replyData/m_config.get()->z_position_resolution());
                    }
                    else if(reply.contains(H_id)){
                        setHPosition(replyData/m_config.get()->hopper_position_resolution());
                    }
                    else if(reply.contains(S_id)){
                        setSPosition(replyData/m_config.get()->spreader_position_resolution());
                    }
                }
                // enable polling timer to send a status check in 500ms
                materialDeliveryPoll_timer->start(500);
            }
        }

        else{ // Did not receive OK
            emit md_port_error(reply); // post error
        }
        md_port_rxBytes.clear();    // clear junk bytes in local buffer
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
    if(m_laser_port->isOpen()){
        m_laser_port->flush();
        m_laser_port->clear();
    }
    if(m_galvo_port->isOpen()){
        m_galvo_port->flush();
        m_galvo_port->clear();
    }
    if(m_md_port->isOpen()){
        m_md_port->flush();
        m_md_port->clear();
    }
    emit startPrint();
}

void PowderTransport::on_stopPrint_request()
{
    if(m_laser_port->isOpen()){
        m_laser_port->flush();
        m_laser_port->clear();
    }
    if(m_galvo_port->isOpen()){
        m_galvo_port->flush();
        m_galvo_port->clear();
    }
    if(m_md_port->isOpen()){
        m_md_port->flush();
        m_md_port->clear();
    }
    emit stopPrint();
}

void PowderTransport::on_reset_request()
{
    if(m_laser_port->isOpen()){
        m_laser_port->flush();
        m_laser_port->clear();
    }
    if(m_galvo_port->isOpen()){
        m_galvo_port->flush();
        m_galvo_port->clear();
    }
    if(m_md_port->isOpen()){
        m_md_port->flush();
        m_md_port->clear();
    }
    m_currentBlockNumber = 0;
    m_currentLayerNumber = 0;
    m_pendingTasks = 0;
    m_activeTask = 0;
    m_galvo_commandStr.clear();
    m_md_PositionCommandStr.clear();
    m_md_SpeedCommandStr.clear();

    currentBlockNumber_changed(0);
    currentLayerNumber_changed(0);
    emit resetDaemon();
}

void PowderTransport::on_emergency_stop_request()
{
    write_to_md_port("/0 stop\r");
}


void PowderTransport::on_galvo_portTimeout()
{
//    qDebug()<<m_galvo_commandStr;
    m_galvo_port->flush();
    m_galvo_port->clear();
    write_to_galvo_port("$(X:,Y:)");
//    emit(galvo_commandPending());
//    emit galvo_error("Error: Time out");
}

void PowderTransport::on_md_portTimeout()
{
    emit md_port_error("Error: Time out");
}

void PowderTransport::on_galvo_port_error(QSerialPort::SerialPortError portError)
{
    if(portError != QSerialPort::SerialPortError::NoError){
        // decode error type
        QMetaEnum metaEnum = QMetaEnum::fromType<QSerialPort::SerialPortError>();
        emit galvo_error(metaEnum.valueToKey(portError));
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

    m_galvo_commandStr.clear();
    m_md_PositionCommandStr.clear();

    m_pendingTasks = m_part.get()->getBlock(m_currentBlockNumber).blockTask();

    // Find tasks
    if(m_pendingTasks != 0){
        m_laser_commandStr = m_part.get()->getBlock(m_currentBlockNumber).laser_string();
        m_galvo_commandStr = m_part.get()->getBlock(m_currentBlockNumber).galvo_string();
        m_md_PositionCommandStr =  m_part.get()->getBlock(m_currentBlockNumber).materialDeliveryPosition_string();
        m_md_PositionCommandStr =  m_part.get()->getBlock(m_currentBlockNumber).materialDeliveryPosition_string();
        emit tasksRemaining();
    }
    else{
        emit blockComplete();
    }
}


// Block tasks are evaluated in the order given
// by the series of if statements.
// after the active task has been evaluated, it is cleared
// from the pending tasks.
void PowderTransport::on_selectProcessFromQueue()
{
    qDebug()<<"entered selectProcessFromQueue_state";

    m_activeTask = 0;

    // set activeTask to a remaining pending task

    if(m_pendingTasks & PowderBlock::BlockTask::SET_LASER_ARM_STATE){
        m_activeTask = PowderBlock::BlockTask::SET_LASER_ARM_STATE;
        emit laser_commandPending();
    }
    else if(m_pendingTasks & PowderBlock::BlockTask::SET_LASER_INTENSITY){
        m_activeTask = PowderBlock::BlockTask::SET_LASER_INTENSITY;
        emit laser_commandPending();
    }
    else if(m_pendingTasks & PowderBlock::BlockTask::SET_LASER_MODE){
        m_activeTask = PowderBlock::BlockTask::SET_LASER_MODE;
        emit laser_commandPending();
    }
    else if(m_pendingTasks & PowderBlock::BlockTask::SET_LASER_PULSE_FREQ){
        m_activeTask = PowderBlock::BlockTask::SET_LASER_PULSE_FREQ;
        emit laser_commandPending();
    }
    else if(m_pendingTasks & (PowderBlock::BlockTask::SET_X_POSITION|PowderBlock::BlockTask::SET_Y_POSITION)){
        if(m_pendingTasks & PowderBlock::BlockTask::SET_HOME_AXIS)
            m_activeTask |= PowderBlock::BlockTask::SET_HOME_AXIS;
        if(m_pendingTasks & PowderBlock::BlockTask::SET_X_POSITION)
            m_activeTask |= PowderBlock::BlockTask::SET_X_POSITION;
        if(m_pendingTasks & PowderBlock::BlockTask::SET_Y_POSITION)
            m_activeTask |= PowderBlock::BlockTask::SET_Y_POSITION;
        if(m_pendingTasks & PowderBlock::BlockTask::SET_LASER_ENABLE_STATE)
            m_activeTask |= PowderBlock::BlockTask::SET_LASER_ENABLE_STATE;
        if(m_pendingTasks & PowderBlock::BlockTask::SET_XY_SPEED)
            m_activeTask |= PowderBlock::BlockTask::SET_XY_SPEED;

        emit galvo_commandPending();   // found galvo command
    }
    else if(m_pendingTasks & (PowderBlock::BlockTask::SET_Z_SPEED)){
        m_activeTask = PowderBlock::BlockTask::SET_Z_SPEED;
        emit md_commandPending();
    }
    else if(m_activeTask & (PowderBlock::BlockTask::SET_HOPPER_SPEED)){
        m_activeTask = PowderBlock::BlockTask::SET_HOPPER_SPEED;
        emit md_commandPending();
    }
    else if(m_activeTask & (PowderBlock::BlockTask::SET_SPREADER_SPEED)){
        m_activeTask = PowderBlock::BlockTask::SET_SPREADER_SPEED;
        emit md_commandPending();
    }
    else if(m_pendingTasks & PowderBlock::BlockTask::SET_Z_POSITION){
        if(m_pendingTasks & PowderBlock::BlockTask::SET_HOME_AXIS)
            m_activeTask = PowderBlock::BlockTask::SET_HOME_AXIS;
        m_activeTask |= PowderBlock::BlockTask::SET_Z_POSITION;
        emit md_commandPending(); // found md command
    }
    else if(m_pendingTasks & PowderBlock::BlockTask::SET_HOPPER_POSITION){
        if(m_pendingTasks & PowderBlock::BlockTask::SET_HOME_AXIS)
            m_activeTask = PowderBlock::BlockTask::SET_HOME_AXIS;
        m_activeTask |= PowderBlock::BlockTask::SET_HOPPER_POSITION;
        emit md_commandPending(); // found md command
    }
    else if(m_pendingTasks & PowderBlock::BlockTask::SET_SPREADER_POSITION){
        if(m_pendingTasks & PowderBlock::BlockTask::SET_HOME_AXIS)
            m_activeTask = PowderBlock::BlockTask::SET_HOME_AXIS;
        m_activeTask |= PowderBlock::BlockTask::SET_SPREADER_POSITION;
        emit md_commandPending(); // found md command
    }
    else
        emit blockComplete(); // block contains no tasks
}

void PowderTransport::on_send_laserCommand()
{
    qDebug()<<"entered on_send_laserCommand_state";

    // select and send relevant command string from list
    if(m_pendingTasks & PowderBlock::BlockTask::SET_LASER_ARM_STATE){
        emit laserBusy();
        write_to_laser_port(m_laser_commandStr.at(0));
    }
    else if(m_activeTask & PowderBlock::BlockTask::SET_LASER_INTENSITY){
        emit laserBusy();
        write_to_laser_port(m_laser_commandStr.at(1));
    }
    else if(m_activeTask & PowderBlock::BlockTask::SET_LASER_MODE){
        emit laserBusy();
        write_to_laser_port(m_laser_commandStr.at(2));
    }
    else if(m_activeTask & PowderBlock::BlockTask::SET_LASER_PULSE_FREQ){
        emit laserBusy();
        write_to_laser_port(m_laser_commandStr.at(3));
    }
}

void PowderTransport::on_receive_laserReply()
{
    qDebug()<<"receive_laserReply_state";
    laserPort_timer->start(1000); // timeout in 1000ms if no reply
}

void PowderTransport::on_laser_transactionFinished()
{
    m_pendingTasks &= (m_activeTask^0xFFFF); // remove active task from pending tasks
    if(m_pendingTasks != 0){
        emit tasksRemaining();
    }
    else
        emit blockComplete();
}

void PowderTransport::on_laser_port_bytesRead()
{
    laser_port_rxBytes +=  m_laser_port->readAll();

    if(laser_port_rxBytes.length() > 2){
        laserPort_timer->stop();
        QString reply = QString::fromUtf8(laser_port_rxBytes);

        if(reply.contains("err", Qt::CaseInsensitive)){
            emit laser_error(reply);
        }
        else if(reply.contains("EGM")){
            setLaserMode(PowderBlock::LaserMode::LASER_PULSED);
            emit laser_deviceReply("Pulsed Mode");
            emit laser_port_rxFinished();
        }
        else if(reply.contains("DGM")){
            setLaserMode(PowderBlock::LaserMode::LASER_CONTINUOUS);
            emit laser_deviceReply("Continuous Mode");
            emit laser_port_rxFinished();
        }
        else if(reply.contains("EMOD")){
            setLaserArmState(true);
            emit laser_deviceReply("Armed");
            emit laser_port_rxFinished();
        }
        else if(reply.contains("DMOD")){
            setLaserArmState(false);
            emit laser_deviceReply("Disarmed");
            emit laser_port_rxFinished();
        }
        else if(reply.contains("SDC")){
            float replyData = 0; // holds value of the received data

            // find the data in the reply
            int posIndex = reply.lastIndexOf(": ");
            if(posIndex != -1){
                posIndex += 2;
                replyData = reply.mid(posIndex, reply.length() - posIndex).toFloat();
                setLaserIntensity(replyData);
                reply = reply.replace("SDC","Intensity");
                emit laser_deviceReply(reply);
                emit laser_port_rxFinished();
            }
            else
            { // received unknown message
                emit laser_error(reply);
            }
        }
        else if(reply.contains("SPRR")){
            int replyData = 0; // holds value of the received data

            // find the data in the reply
            int posIndex = reply.lastIndexOf(": ");
            if(posIndex != -1){
                posIndex += 2;
                replyData = reply.mid(posIndex, reply.length() - posIndex).toInt();
                setLaserPulseFreq(replyData);
                reply = reply.replace("SPRR","Frequency");
                emit laser_deviceReply(reply);
                emit laser_port_rxFinished();
            }
            else
            { // received unknown message
                emit laser_error(reply);
            }
        }
        else    // received unknown message
        {
            emit laser_error(reply);
        }
    }
}

void PowderTransport::on_send_galvoCommand()
{
    qDebug()<<"entered send_galvoCommand_state";

    if(m_activeTask & (PowderBlock::BlockTask::SET_X_POSITION|PowderBlock::BlockTask::SET_Y_POSITION
                       |PowderBlock::BlockTask::SET_XY_SPEED|PowderBlock::BlockTask::SET_LASER_ENABLE_STATE)){
        emit galvoBusy();   // tells UI galvo is executing a task
        write_to_galvo_port(m_galvo_commandStr);
    }
}

void PowderTransport::on_receive_galvoReply()
{
    qDebug()<<"entered receive_galvoReply_state";
    galvoPort_timer->start(1000); // timeout in 1000ms if no reply
}

void PowderTransport::on_galvo_transactionFinished()
{
    qDebug()<<"entered galvo_transactionFinished_state";

    // if a print is underway update state with block data
    if(m_printModeEnabled){

        m_pendingTasks &= (m_activeTask^0xFFFF); // remove active task from pending tasks

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
            m_activeTask = 0;
            emit jogComplete();
        }

        if(m_activeTask & PowderBlock::BlockTask::SET_Y_POSITION){
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

    if(m_activeTask & PowderBlock::BlockTask::SET_Z_SPEED){
        emit buildPlateBusy();
        write_to_md_port(m_md_SpeedCommandStr.at(0));
    }
    else if(m_activeTask & PowderBlock::BlockTask::SET_HOPPER_SPEED){
        emit hopperBusy();
        write_to_md_port(m_md_SpeedCommandStr.at(1));
    }
    else if(m_activeTask & PowderBlock::BlockTask::SET_SPREADER_SPEED){
        emit spreaderBusy();
        write_to_md_port(m_md_SpeedCommandStr.at(2));
    }

    else if(m_activeTask & PowderBlock::BlockTask::SET_Z_POSITION){
        emit buildPlateBusy();
        write_to_md_port(m_md_PositionCommandStr.at(0));
    }
    else if(m_activeTask & PowderBlock::BlockTask::SET_HOPPER_POSITION){
        emit hopperBusy();
        write_to_md_port(m_md_PositionCommandStr.at(1));
    }
    else if(m_activeTask & PowderBlock::BlockTask::SET_SPREADER_POSITION){
        emit spreaderBusy();
        write_to_md_port(m_md_PositionCommandStr.at(2));
    }
}

void PowderTransport::on_receive_mdReply()
{
    qDebug()<<"entered receive_mdReply_state";
    materialDeliveryPort_timer->start(1000); // timeout in 1000ms if no reply
}

void PowderTransport::on_md_transactionFinished()
{
    qDebug()<<"entered md_transactionFinished_state";

    // if a print is underway. positions are updated in bytesRead function
    if(m_printModeEnabled){

        // remove active task from pending tasks
        m_pendingTasks &= (m_activeTask^0xFFFF);
        if(m_pendingTasks != 0){
            // if tasks remain, and we were previously executing a homing command,
            // clear the active task, but reinstate the home request.
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
            m_activeTask = 0;
            emit jogComplete();
        }
        else if(m_activeTask & PowderBlock::BlockTask::SET_HOPPER_POSITION){
            m_activeTask = 0;
            emit jogComplete();
        }
        else if(m_activeTask & PowderBlock::BlockTask::SET_SPREADER_POSITION){
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
    if(m_galvo_port->error() != QSerialPort::SerialPortError::NoError)
        m_galvo_port->clearError();    // clear port errors
    if(m_md_port->error() != QSerialPort::SerialPortError::NoError)
        m_md_port->clearError();  // clear port errors
    m_activeTask = 0;
    m_pendingTasks = 0;
}

PowderBlock::LaserMode PowderTransport::laserMode() const
{
    return m_laserMode;
}

void PowderTransport::setLaserMode(const PowderBlock::LaserMode &laserMode)
{
    m_laserMode = laserMode;
}

int PowderTransport::laserPulseFreq() const
{
    return m_laserPulseFreq;
}

void PowderTransport::setLaserPulseFreq(int laserPulseFreq)
{
    m_laserPulseFreq = laserPulseFreq;
}

float PowderTransport::sSpeed() const
{
    return m_sSpeed;
}

void PowderTransport::setSSpeed(float sSpeed)
{
    m_sSpeed = sSpeed;
}

float PowderTransport::hSpeed() const
{
    return m_hSpeed;
}

void PowderTransport::setHSpeed(float hSpeed)
{
    m_hSpeed = hSpeed;
}

float PowderTransport::zSpeed() const
{
    return m_zSpeed;
}

void PowderTransport::setZSpeed(float zSpeed)
{
    m_zSpeed = zSpeed;
}



void PowderTransport::on_printManager_enabled(bool enabled)
{
    m_galvo_port->clear();
    galvo_port_rxBytes.clear();

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

void PowderTransport::on_laserPortName_changed(const QString &name)
{
    if(m_laser_port->isOpen())
        m_laser_port->close();
    m_laser_port->setPortName(name);
}

void PowderTransport::on_galvoPortName_changed(const QString &name)
{
    if(m_galvo_port->isOpen())
        m_galvo_port->close();
    m_galvo_port->setPortName(name);
}

void PowderTransport::on_mdPortName_changed(const QString &name)
{
    if(m_md_port->isOpen())
        m_md_port->close();
    m_md_port->setPortName(name);
}

void PowderTransport::on_laser_port_connectionRequested(bool open)
{
    if(open && !m_laser_port->isOpen()){
        m_laser_port->open(QIODevice::ReadWrite);
        if(m_laser_port->isOpen()){
            m_laser_port->flush();
            m_laser_port->clear();
            emit laser_port_connectionChanged(true);
        }
        else
            emit laser_error("Could not open laser port");
    }
    else if(!open && m_laser_port->isOpen()){
        m_laser_port->flush();
        m_laser_port->clear();
        m_laser_port->close();
        emit laser_port_connectionChanged(false);
    }
}

void PowderTransport::on_galvo_port_connectionRequested(bool open)
{
    if(open && !m_galvo_port->isOpen()){
        m_galvo_port->open(QIODevice::ReadWrite);
        if(m_galvo_port->isOpen()){
            m_galvo_port->flush();
            m_galvo_port->clear();
            emit galvo_port_connectionChanged(true);
        }
        else
            emit galvo_error("Could not open galvo port");
    }
    else if(!open && m_galvo_port->isOpen()){
        m_galvo_port->flush();
        m_galvo_port->clear();
        m_galvo_port->close();
        emit galvo_port_connectionChanged(false);
    }
}

void PowderTransport::on_md_port_connectionRequested(bool open)
{
    if(open && !m_md_port->isOpen()){
        m_md_port->open(QIODevice::ReadWrite);
        if(m_md_port->isOpen()){
            m_md_port->flush();
            m_md_port->clear();
            emit md_port_connectionChanged(true);
        }
        else
            emit galvo_error("Could not open MD port");
    }
    else if(!open && m_md_port->isOpen()){
        m_md_port->flush();
        m_md_port->clear();
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
        m_galvo_commandStr = "$(g=4,X=0)";
        if(m_galvo_port->isOpen())
            emit galvo_commandPending();
        break;
    }
    case 1:
    {
        m_activeTask = (PowderBlock::BlockTask::SET_HOME_AXIS|PowderBlock::BlockTask::SET_Y_POSITION);
        m_galvo_commandStr = "$(g=4,Y=0)";
        if(m_galvo_port->isOpen())
            emit galvo_commandPending();
        break;
    }
    case 2:
    {
        m_activeTask = (PowderBlock::BlockTask::SET_HOME_AXIS|PowderBlock::BlockTask::SET_Z_POSITION);
        if(m_md_port->isOpen()){
            QString homeStr ="/" + QString::number(m_config.get()->z_deviceNumber()) + " " + QString::number(m_config.get()->z_axisNumber()) + " home\r";
            m_md_PositionCommandStr.replace(0,homeStr);
            emit md_commandPending();
        }
        break;
    }
    case 3:
    {
        m_activeTask = (PowderBlock::BlockTask::SET_HOME_AXIS|PowderBlock::BlockTask::SET_HOPPER_POSITION);
        if(m_md_port->isOpen()){
            QString homeStr ="/" + QString::number(m_config.get()->hopper_deviceNumber()) + " " + QString::number(m_config.get()->hopper_axisNumber()) + " home\r";
            m_md_PositionCommandStr.replace(1,homeStr);
            emit md_commandPending();
        }
        break;
    }
    case 4:
    {
        m_activeTask = (PowderBlock::BlockTask::SET_HOME_AXIS|PowderBlock::BlockTask::SET_SPREADER_POSITION);
        if(m_md_port->isOpen()){
            QString homeStr ="/" + QString::number(m_config.get()->spreader_deviceNumber()) + " " + QString::number(m_config.get()->spreader_axisNumber()) + " home\r";
            m_md_PositionCommandStr.replace(2,homeStr);
            emit md_commandPending();
        }
        break;
    }
    default:
        m_activeTask = 0;
        emit transport_error("No Axis to Home");
        break;
    }
}

void PowderTransport::on_increment_xPosition_request()
{
    if(((m_xPosition + jogIncrement())) < m_config.get()->x_position_max()){
        m_jogSign = 1.0;
        const int32_t steps = static_cast<int32_t>(jogIncrement()*m_config.get()->x_position_resolution());
        m_galvo_commandStr = GalvoUtility::composeJogCommandString(PowderBlock::BlockTask::SET_X_POSITION, steps);
        m_activeTask = PowderBlock::BlockTask::SET_X_POSITION;
        emit galvo_commandPending();
    }
}

void PowderTransport::on_decrement_xPosition_request()
{
    if(((m_xPosition - jogIncrement())) > m_config.get()->x_position_min()){
        m_jogSign = -1.0;
        const int32_t steps = static_cast<int32_t>(-1*jogIncrement()*m_config.get()->x_position_resolution());
        m_galvo_commandStr = GalvoUtility::composeJogCommandString(PowderBlock::BlockTask::SET_X_POSITION, steps);
        m_activeTask = PowderBlock::BlockTask::SET_X_POSITION;
        emit galvo_commandPending();
    }
}

void PowderTransport::on_increment_yPosition_request()
{
    if(((m_yPosition + jogIncrement())) < m_config.get()->y_position_max()){
        m_jogSign = 1.0;
        const int32_t steps = static_cast<int32_t>(jogIncrement()*m_config.get()->y_position_resolution());
        m_galvo_commandStr = GalvoUtility::composeJogCommandString(PowderBlock::BlockTask::SET_Y_POSITION, steps);
        m_activeTask = PowderBlock::BlockTask::SET_Y_POSITION;
        emit galvo_commandPending();
    }
}

void PowderTransport::on_decrement_yPosition_request()
{
    if(((m_yPosition - jogIncrement())) > m_config.get()->y_position_min()){
        m_jogSign = -1.0;
        const int32_t steps = static_cast<int32_t>(-1*jogIncrement()*m_config.get()->y_position_resolution());
        m_galvo_commandStr = GalvoUtility::composeJogCommandString(PowderBlock::BlockTask::SET_Y_POSITION, steps);
        m_activeTask = PowderBlock::BlockTask::SET_Y_POSITION;
        emit galvo_commandPending();
    }
}

void PowderTransport::on_increment_zPosition_request()
{
    m_md_PositionCommandStr.clear();
    if(((m_zPosition + jogIncrement())) < m_config.get()->z_position_max()){
        m_jogSign = 1.0;
        const int32_t steps = static_cast<int32_t>(jogIncrement()*m_config.get()->z_position_resolution());
        QString z ="/" + QString::number(m_config.get()->z_deviceNumber()) + " " + QString::number(m_config.get()->z_axisNumber());
        z += " move rel " + QString::number(steps) + "\r";
        m_md_PositionCommandStr.append(z);
        m_md_PositionCommandStr.append("EMPTY");
        m_md_PositionCommandStr.append("EMPTY");
        m_activeTask = PowderBlock::BlockTask::SET_Z_POSITION;
        emit md_commandPending();
    }
}

void PowderTransport::on_decrement_zPosition_request()
{
    m_md_PositionCommandStr.clear();
    if(((m_zPosition - jogIncrement())) > m_config.get()->z_position_min()){
        m_jogSign = -1.0;
        const int32_t steps = static_cast<int32_t>(-1*jogIncrement()*m_config.get()->z_position_resolution());
        QString z ="/" + QString::number(m_config.get()->z_deviceNumber()) + " " + QString::number(m_config.get()->z_axisNumber());
        z += " move rel " + QString::number(steps) + "\r";
        m_md_PositionCommandStr.append(z);
        m_md_PositionCommandStr.append("EMPTY");
        m_md_PositionCommandStr.append("EMPTY");
        m_activeTask = PowderBlock::BlockTask::SET_Z_POSITION;
        emit md_commandPending();
    }
}

void PowderTransport::on_increment_hPosition_request()
{
    m_md_PositionCommandStr.clear();
    if(((m_hPosition + jogIncrement())) < m_config.get()->hopper_position_max()){
        m_jogSign = 1.0;
        const int32_t steps = static_cast<int32_t>(jogIncrement()*m_config.get()->hopper_position_resolution());
        QString h ="/" + QString::number(m_config.get()->hopper_deviceNumber()) + " " + QString::number(m_config.get()->hopper_axisNumber());
        h += " move rel " + QString::number(steps) + "\r";
        m_md_PositionCommandStr.append("EMPTY");
        m_md_PositionCommandStr.append(h);
        m_md_PositionCommandStr.append("EMPTY");
        m_activeTask = PowderBlock::BlockTask::SET_HOPPER_POSITION;
        emit md_commandPending();
    }
}

void PowderTransport::on_decrement_hPosition_request()
{
    m_md_PositionCommandStr.clear();
    if(((m_hPosition - jogIncrement())) > m_config.get()->hopper_position_min()){
        m_jogSign = -1.0;
        const int32_t steps = static_cast<int32_t>(-1*jogIncrement()*m_config.get()->hopper_position_resolution());
        QString h ="/" + QString::number(m_config.get()->hopper_deviceNumber()) + " " + QString::number(m_config.get()->hopper_axisNumber());
        h += " move rel " + QString::number(steps) + "\r";
        m_md_PositionCommandStr.append("EMPTY");
        m_md_PositionCommandStr.append(h);
        m_md_PositionCommandStr.append("EMPTY");
        m_activeTask = PowderBlock::BlockTask::SET_HOPPER_POSITION;
        emit md_commandPending();
    }
}

void PowderTransport::on_increment_sPosition_request()
{
    m_md_PositionCommandStr.clear();
    if(((m_sPosition + jogIncrement())) < m_config.get()->spreader_position_max()){
        m_jogSign = 1.0;
        const int32_t steps = static_cast<int32_t>(jogIncrement()*m_config.get()->spreader_position_resolution());
        QString s ="/" + QString::number(m_config.get()->spreader_deviceNumber()) + " " + QString::number(m_config.get()->spreader_axisNumber());
        s += " move rel " + QString::number(steps) + "\r";
        m_md_PositionCommandStr.append("EMPTY");
        m_md_PositionCommandStr.append("EMPTY");
        m_md_PositionCommandStr.append(s);
        m_activeTask = PowderBlock::BlockTask::SET_SPREADER_POSITION;
        emit md_commandPending();
    }
}

void PowderTransport::on_decrement_sPosition_request()
{
    m_md_PositionCommandStr.clear();
    if(((m_sPosition - jogIncrement())) > m_config.get()->spreader_position_min()){
        m_jogSign = -1.0;
        const int32_t steps = static_cast<int32_t>(-1*jogIncrement()*m_config.get()->spreader_position_resolution());
        QString s ="/" + QString::number(m_config.get()->spreader_deviceNumber()) + " " + QString::number(m_config.get()->spreader_axisNumber());
        s += " move rel " + QString::number(steps) + "\r";
        m_md_PositionCommandStr.append("EMPTY");
        m_md_PositionCommandStr.append("EMPTY");
        m_md_PositionCommandStr.append(s);
        m_activeTask = PowderBlock::BlockTask::SET_SPREADER_POSITION;
        emit md_commandPending();
    }
}

void PowderTransport::on_clearError_request()
{
    if(m_laser_port->isOpen()){
        m_laser_port->flush();
        m_laser_port->clear();
    }
    if(m_galvo_port->isOpen()){
        m_galvo_port->flush();
        m_galvo_port->clear();
    }
    if(m_md_port->isOpen()){
        m_md_port->flush();
        m_md_port->clear();
    }
    emit resetDaemon();
}

void PowderTransport::on_reset_galvo_request()
{
    m_galvo_port->flush();
    m_galvo_port->clear();
    // write an empty command
    m_galvo_commandStr = "$R";
    m_activeTask = PowderBlock::BlockTask::SET_X_POSITION|PowderBlock::BlockTask::SET_Y_POSITION;
    m_xPosition = 0;
    m_yPosition = 0;
    m_xySpeed = m_config.get()->xy_speed_default();
    emit galvo_commandPending();
}


void PowderTransport::ping_galvo()
{
    m_galvo_port->flush();
    m_galvo_port->clear();
    // write an empty command
    m_galvo_commandStr = "$(X:,Y:)";
    m_activeTask = PowderBlock::BlockTask::SET_X_POSITION|PowderBlock::BlockTask::SET_Y_POSITION;
    emit galvo_commandPending();
}

void PowderTransport::ping_materialDelivery(int devNum, int axisNum)
{
    // write an empty command
    if(devNum == m_config.get()->z_deviceNumber()){
        const QString pingStr ="/" + QString::number(devNum) + " " + QString::number(axisNum) + "\r";
        m_md_PositionCommandStr.replace(0, pingStr);
        m_activeTask = PowderBlock::BlockTask::SET_Z_POSITION;
        emit md_commandPending();
    }
    else if((devNum == m_config.get()->hopper_deviceNumber())&&(axisNum == m_config.get()->hopper_axisNumber())){
        const QString pingStr ="/" + QString::number(devNum) + " " + QString::number(axisNum) + "\r";
        m_md_PositionCommandStr.replace(1, pingStr);
        m_activeTask = PowderBlock::BlockTask::SET_HOPPER_POSITION;
        emit md_commandPending();
    }
    else if((devNum == m_config.get()->spreader_deviceNumber())&&(axisNum == m_config.get()->spreader_axisNumber())){
        const QString pingStr ="/" + QString::number(devNum) + " " + QString::number(axisNum) + "\r";
        m_md_PositionCommandStr.replace(2, pingStr);
        m_activeTask = PowderBlock::BlockTask::SET_SPREADER_POSITION;
        emit md_commandPending();
    }
    else if((devNum == m_config.get()->hopper_deviceNumber())||(devNum == m_config.get()->spreader_deviceNumber())){
        const QString pingStr ="/" + QString::number(devNum) +"\r";
        m_md_PositionCommandStr.replace(1, pingStr);
        m_activeTask = PowderBlock::BlockTask::SET_HOPPER_POSITION;
        emit md_commandPending();
    }
}

void PowderTransport::on_laser_port_bytesWritten(qint64 bytes)
{
    laser_port_TxBytesRemaining -= bytes;
    if(laser_port_TxBytesRemaining <= 0)
        emit laser_port_txFinished();
}



void PowderTransport::on_laser_portTimeout()
{
    emit laser_error("Error: Time out");
}

void PowderTransport::on_laser_port_error(QSerialPort::SerialPortError portError)
{
    if(portError != QSerialPort::SerialPortError::NoError){
        // decode error type
        QMetaEnum metaEnum = QMetaEnum::fromType<QSerialPort::SerialPortError>();
        emit laser_error(metaEnum.valueToKey(portError));
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
