//#ifndef SERIALTRANSPORT_H
//#define SERIALTRANSPORT_H

//#include <QObject>
//#include <QState>
//#include <QStateMachine>
//#include <QThread>
//#include <QApplication>
//#include <QDebug>
//#include <QTimer>
//#include <QtSerialPort>
//#include <QSharedPointer>
//#include "powder_objects/partobject.h"

//class PortDaemon : public QStateMachine
//{
//    Q_OBJECT
//public:
//    PortDaemon() : time(new QTimer(this)),
//        port(new QSerialPort(this))
//    {

//        QState *portDaemonState_init = new QState();
//        this->addState(portDaemonState_init);
//        this->setInitialState(portDaemonState_init);

//        QState *portDaemonState_idle = new QState();

//        QState *portDaemonState_timeout = new QState();

//        QState *portDaemonState_error = new QState();

//        QState *portDaemonState_Tx = new QState();

//        QState *portDaemonState_Rx = new QState();

//        QState *portDaemonState_disconnected = new QState();

//        portDaemonState_init->addTransition(this, SIGNAL(portDaemonSig_port_isConnected()), portDaemonState_idle);

//        portDaemonState_init->addTransition(this, SIGNAL(portDaemonSig_error(const QString&)), portDaemonState_error);
//        portDaemonState_init->addTransition(this, SIGNAL(portDaemonSig_disconnected()), portDaemonState_disconnected);

//        portDaemonState_idle->addTransition(this, SIGNAL(portDaemonSig_commandPending()), portDaemonState_Tx);
//        portDaemonState_idle->addTransition(this, SIGNAL(portDaemonSig_disconnected()), portDaemonState_disconnected);

//        portDaemonState_Tx->addTransition(time, &QTimer::timeout, portDaemonState_timeout);
//        portDaemonState_Tx->addTransition(this, &PortDaemon::portDaemonSig_error, portDaemonState_error);
//        portDaemonState_Tx->addTransition(this, SIGNAL(portDaemonSig_commandSent()), portDaemonState_Rx);


//        portDaemonState_Rx->addTransition(time, &QTimer::timeout, portDaemonState_timeout);
//        portDaemonState_Rx->addTransition(this, SIGNAL(portDaemonSig_error(const QString&)), portDaemonState_error);
//        portDaemonState_Rx->addTransition(this, SIGNAL(portDaemonSig_deviceReply(const QString&)), portDaemonState_error);
//        portDaemonState_Rx->addTransition(this, SIGNAL(portDaemonSig_commandConfirmed()), portDaemonState_idle);


//        portDaemonState_error->addTransition(this, SIGNAL(portDaemonSig_reconnect()), portDaemonState_init);



//        this->addState(portDaemonState_idle);

//        this->addState(portDaemonState_error);

//        this->addState(portDaemonState_timeout);

//        this->addState(portDaemonState_Tx);

//        this->addState(portDaemonState_Rx);

//        time->setInterval(2000);

//        connect(portDaemonState_Tx, SIGNAL(entered()), time, SLOT(start()));
//        connect(time, &QTimer::timeout, this, &PortDaemon::portDaemonSlot_commandTimedOut);

//        connect(portDaemonState_Rx, SIGNAL(entered()), time, SLOT(start()));

//        connect(time, &QTimer::timeout, this, &PortDaemon::portDaemonSlot_replyTimedOut);

//        connect(port, SIGNAL(bytesWritten(qint64)),
//                this, SLOT(portDaemonSlot_checkBytesWritten(qint64)));

//        connect(port, SIGNAL(readyRead()),
//                this, SLOT(portDaemonSlot_checkBytesRead()));


//        port->setBaudRate(115200);

//    }
//    ~PortDaemon() = default;

//public slots:

//    void portDaemonSlot_setPortName(const QString &name){
//        port->setPortName(name);
//    }

//    void portDaemonSlot_openPort(){
//        if(!portName.isEmpty()){
//            if(!port->isOpen())
//                port->open(QIODevice::ReadWrite);
//            if(port->isOpen()){
//                port->clear();
//                qDebug()<<"port is open in thread";
//                emit portDaemonSig_port_isConnected();
//            }
//            else
//                emit portDaemonSig_error("Could Not Open Port");
//        }
//        else
//            emit portDaemonSig_error("Invalid Port Name");
//    }

//    void portDaemonSlot_closePort(){
//        if(port->isOpen())
//            port->close();
//        emit portDaemonSig_disconnected();
//    }

//    void portDaemonSlot_writeToPort(const QString &command){
//        emit portDaemonSig_commandPending();
//        port->clear();
//        const QByteArray txBytes = command.toUtf8();
//        bytesRemaining = command.length();
//        port->write(txBytes);
//    }

//    void portDaemonSlot_checkBytesWritten(qint64 bytes){
//        bytesRemaining -= bytes;

//        if(bytesRemaining <= 0){
//            time->stop();
//            emit portDaemonSig_commandSent();
//        }
//    }

//    void portDaemonSlot_checkBytesRead(){
//        const QByteArray reply = port->readAll();
//        const QString replyStr = QString::fromUtf8(reply);

//        if(replyStr.contains("ok",Qt::CaseInsensitive)){
//            time->stop();

//            emit portDaemonSig_commandConfirmed();
//        }
//        else
//            emit portDaemonSig_deviceReply(replyStr);
//    }

//    void portDaemonSlot_commandTimedOut(){
//        port->clear();
//        port->close();
//        emit portDaemonSig_error("Port Timed Out While Writing Command");
//    }

//    void portDaemonSlot_replyTimedOut(){
//        port->clear();
//        port->close();

//        emit portDaemonSig_error("Port Timed Out While Waiting For a Reply");
//    }

//    void portDaemonSlot_clearErrors(){
//        if(port->isOpen())
//            port->close();

//        port->clear();
//        port->clearError();
//        emit portDaemonSig_reconnect();
//    }

//signals:
//    void portDaemonSig_port_isConnected();
//    void portDaemonSig_commandPending();
//    void portDaemonSig_error(const QString &error);
//    void portDaemonSig_deviceReply(const QString &error);
//    void portDaemonSig_commandSent();
//    void portDaemonSig_commandConfirmed();
//    void portDaemonSig_disconnected();
//    void portDaemonSig_reconnect();
//private:
//    QTimer *time;
//    QSerialPort *port;
//    QString portName;
//    qint64 bytesRemaining;
//};



//class PortController : public QStateMachine
//{
//    Q_OBJECT
//public:
//    PortController(QObject *parent = nullptr) : portDaemon(new PortDaemon()) {
//        this->setParent(parent);
//        portDaemon->moveToThread(&daemonThread);
//        connect(portDaemon, &QStateMachine::started, this, &PortController::portControllerSlot_onDaemonStart);
//        portDaemon->start();

//        QState *portControllerState_disabled = new QState();
//        QState *portControllerState_enabled = new QState();
//        QState *portControllerState_error = new QState();

//        connect(this, SIGNAL(portControllerSig_newPortName(const QString&)), portDaemon, SLOT(portDaemonSlot_setPortName(const QString &)));

//        portControllerState_disabled->addTransition(this, SIGNAL(portControllerSig_controllerEnable()), portControllerState_enabled);
//        connect(&daemonThread, SIGNAL(started()), this, SLOT(portControllerSlot_onDaemonStart()));
//        connect(portControllerState_enabled, &QState::entered, portDaemon, &PortDaemon::start);

//        portControllerState_enabled->addTransition(this, SIGNAL(portControllerSig_controllerDisable()), portControllerState_disabled);
//        connect(&daemonThread, SIGNAL(finished()), this, SLOT(portControllerSlot_onDaemonStop()));
//        connect(portControllerState_disabled, &QState::entered, portDaemon, &PortDaemon::stop);

//        connect(this, SIGNAL(portControllerSig_controllerDisable()), portDaemon, SLOT(portDaemonSlot_closePort()));

//        connect(this, SIGNAL(portControllerSig_openPort()), portDaemon, SLOT(portDaemonSlot_openPort()));
//        connect(this, SIGNAL(portControllerSig_closePort()), portDaemon, SLOT(portDaemonSlot_closePort()));

//        connect(portDaemon, SIGNAL(portDaemonSig_port_isConnected()),
//                this, SLOT(portControllerSlot_onPortOpened()));

//        connect(this, SIGNAL(portControllerSig_command_isPending(const QString&)),
//                portDaemon, SLOT(portDaemonSlot_writeToPort(const QString&)));

//        connect(portDaemon, SIGNAL(portDaemonSig_commandConfirmed()),
//                this, SLOT(portControllerSlot_onTransactionComplete()));


//        portControllerState_enabled->addTransition(portDaemon, SIGNAL(portDaemonSig_error(const QString&)), portControllerState_error);

//        connect(portDaemon, SIGNAL(portDaemonSig_error(const QString&)),
//                this, SLOT(portControllerSlot_onPortError(const QString&)));

//        connect(portDaemon, SIGNAL(portDaemonSig_deviceReply(const QString&)),
//                this, SLOT(portControllerSlot_onReply(const QString&)));


//        portControllerState_error->addTransition(this, SIGNAL(portControllerSig_clearErrors()), portControllerState_disabled);
//        connect(this, SIGNAL(portControllerSig_clearErrors()),
//                portDaemon, SLOT(portDaemonSlot_clearErrors()));

//        connect(&daemonThread, &QThread::finished,
//                portDaemon, &QObject::deleteLater);


//        this->addState(portControllerState_disabled);
//        this->setInitialState(portControllerState_disabled);

//        this->addState(portControllerState_enabled);
//        this->addState(portControllerState_error);
//    }

//    ~PortController() {
//        daemonThread.quit();
//        daemonThread.wait();
//    }
//public slots:


//    void portControllerSlot_setPortName(const QString &name){
//        emit portControllerSig_newPortName(name);
//    }

//    void portControllerSlot_enableController(){
//        emit portControllerSig_controllerEnable();
//    }

//    void portControllerSlot_disableController(){
//        emit portControllerSig_controllerDisable();
//    }

//    void portControllerSlot_openPort(){
//        emit portControllerSig_openPort();
//    }

//    void portControllerSlot_closePort(){
//        emit portControllerSig_closePort();
//    }


//    void portControllerSlot_commandInput(const QString &command){
//        emit portControllerSig_command_isPending(command);
//    }

//    void portControllerSlot_clearErrors(){
//        emit portControllerSig_clearErrors();
//    }


//    // local slots
//    void portControllerSlot_onDaemonStart(){
//        qDebug()<<"deamonStarted";
//        emit controller_isEnabled();
//    }
//    void portControllerSlot_onDaemonStop(){
//        emit controller_isDisabled();
//    }

//    void portControllerSlot_onPortOpened(){
//        emit portControllerSig_port_isOpen(); // output
//    }

//    void portControllerSlot_onPortError(const QString &error){
//        emit portControllerSig_portError(error); // output
//    }

//    void portControllerSlot_onReply(const QString &reply){
//        emit portControllerSig_deviceReply(reply); // output
//    }

//    void portControllerSlot_onTransactionComplete(){
//        emit portControllerSig_transactionSuccessful(); // output
//    }


//public:
//    QThread daemonThread;
//    PortDaemon *portDaemon;
//    QString portName;

//signals:
//    void controller_isEnabled();
//    void controller_isDisabled();
//    void portControllerSig_port_isOpen(); // output
//    void portControllerSig_port_isClosed(); // output

//    void portControllerSig_portError(const QString &error); // output
//    void portControllerSig_deviceReply(const QString &reply); // output
//    void portControllerSig_transactionSuccessful(); // output

//    // local signals
//    void portControllerSig_newPortName(const QString &name);
//    void portControllerSig_command_isPending(const QString &command);
//    void portControllerSig_controllerEnable();
//    void portControllerSig_controllerDisable();
//    void portControllerSig_clearErrors();
//    void portControllerSig_openPort();
//    void portControllerSig_closePort();



//};



//class SerialTransport : public QObject{
//    Q_OBJECT
//public:
//    SerialTransport(QObject *parent = nullptr) : laserGalvoPort(new PortController(this)), materialDeliveryPort(new PortController(this))
//    {
//        this->setParent(parent);
//        laserGalvoController_isEnabled = false;
//        laserGalvoPort_isOpen = false;
//        laserGalvoPort_isAvailable = false;

//        materialDeliveryController_isEnabled = false;
//        materialDeliveryPort_isOpen = false;
//        materialDeliveryPort_isAvailable = false;

//        connect(this, SIGNAL(serialTransportSignal_enableLaserGalvoController()), laserGalvoPort, SLOT(portControllerSlot_enableController()));
//        connect(this, SIGNAL(serialTransportSignal_disableLaserGalvoController()), laserGalvoPort, SLOT(portControllerSlot_disableController()));

//        connect(this, SIGNAL(serialTransportSignal_setLgPortName(const QString&)), laserGalvoPort, SLOT(portControllerSlot_setPortName(const QString&)));
//        connect(this, SIGNAL(serialTransportSignal_openLaserGalvoPort()), laserGalvoPort, SLOT(portControllerSlot_openPort()));
//        connect(this, SIGNAL(serialTransportSignal_closeLaserGalvoPort()), laserGalvoPort, SLOT(portControllerSlot_closePort()));
//        connect(this, SIGNAL(serialTransportSignal_clearLaserGalvoPortErrors()), laserGalvoPort, SLOT(portControllerSlot_clearErrors()));
//        connect(this, SIGNAL(serialTransportSignal_laserGalvoCommand(const QString&)), laserGalvoPort, SLOT(portControllerSlot_commandInput(const QString&)));

//        connect(laserGalvoPort,SIGNAL(controller_isEnabled()), this, SLOT(serialTransportSlot_on_laserGalvoController_enabled()));
//        connect(laserGalvoPort,SIGNAL(controller_isDisabled()), this, SLOT(serialTransportSlot_on_laserGalvoController_disabled()));

//        connect(laserGalvoPort,SIGNAL(portControllerSig_port_isOpen()), this, SLOT(serialTransportSlot_on_laserGalvoPort_opened()));
//        connect(laserGalvoPort,SIGNAL(portControllerSig_port_isClosed()), this, SLOT(serialTransportSlot_on_laserGalvoPort_closed()));

//        connect(laserGalvoPort,SIGNAL(portControllerSig_deviceReply(const QString&)), this, SLOT(serialTransportSlot_on_laserGalvo_DeviceReply(const QString&)));
//        connect(laserGalvoPort,SIGNAL(portControllerSig_portError(const QString&)), this, SLOT(serialTransportSlot_on_laserGalvo_error(const QString&)));
//        connect(laserGalvoPort,SIGNAL(portControllerSig_transactionSuccessful()), this, SLOT(serialTransportSlot_on_laserGalvo_transactionCompleted()));

//        connect(this, SIGNAL(serialTransportSignal_enableMaterialDeliveryController()), materialDeliveryPort, SLOT(portControllerSlot_enableController()));
//        connect(this, SIGNAL(serialTransportSignal_disableMaterialDeliveryController()), materialDeliveryPort, SLOT(portControllerSlot_disableController()));

//        connect(this, SIGNAL(serialTransportSignal_setMdPortName(const QString&)), materialDeliveryPort, SLOT(portControllerSlot_setPortName(const QString&)));
//        connect(this, SIGNAL(serialTransportSignal_openMaterialDeliveryPort()), materialDeliveryPort, SLOT(portControllerSlot_openPort()));
//        connect(this, SIGNAL(serialTransportSignal_closeMaterialDeliveryPort()), materialDeliveryPort, SLOT(portControllerSlot_closePort()));
//        connect(this, SIGNAL(serialTransportSignal_clearMaterialDeliveryPortErrors()), materialDeliveryPort, SLOT(portControllerSlot_clearErrors()));
//        connect(this, SIGNAL(serialTransportSignal_materialDeliveryCommand(const QString&)), materialDeliveryPort, SLOT(portControllerSlot_commandInput(const QString&)));

//        connect(materialDeliveryPort,SIGNAL(controller_isEnabled()), this, SLOT(serialTransportSlot_on_materialDeliveryController_enabled()));
//        connect(materialDeliveryPort,SIGNAL(controller_isDisabled()), this, SLOT(serialTransportSlot_on_materialDeliveryController_disabled()));

//        connect(materialDeliveryPort,SIGNAL(portControllerSig_port_isOpen()), this, SLOT(serialTransportSlot_on_materialDeliveryPort_opened()));
//        connect(materialDeliveryPort,SIGNAL(portControllerSig_port_isClosed()), this, SLOT(serialTransportSlot_on_materialDeliveryPort_closed()));

//        connect(materialDeliveryPort,SIGNAL(portControllerSig_deviceReply(const QString&)), this, SLOT(serialTransportSlot_on_materialDelivery_DeviceReply(const QString&)));
//        connect(materialDeliveryPort,SIGNAL(portControllerSig_portError(const QString&)), this, SLOT(serialTransportSlot_on_materialDelivery_error(const QString&)));
//        connect(materialDeliveryPort,SIGNAL(portControllerSig_transactionSuccessful()), this, SLOT(serialTransportSlot_on_materialDelivery_transactionCompleted()));

//    }
//    ~SerialTransport()
//    {
//        laserGalvoPort->deleteLater();
//        materialDeliveryPort->deleteLater();
//    }

//    void set_LaserGalvo_portName(const QString &name){
//        emit serialTransportSignal_setLgPortName(name);
//    }

//    void set_MaterialDelivery_portName(const QString &name){
//        emit serialTransportSignal_setMdPortName(name);
//    }


//    bool isLaserGalvoControllerEnabled() const {
//        return laserGalvoController_isEnabled;
//    }

//    bool isLaserGalvoPortOpen() const {
//        return laserGalvoPort_isOpen;
//    }

//    bool isLaserGalvoPortAvailable() const {
//        return laserGalvoPort_isAvailable;
//    }

//    bool isMaterialDeliveryControllerEnabled() const {
//        return materialDeliveryController_isEnabled;
//    }

//    bool isMaterialDeliveryPortOpen() const {
//        return materialDeliveryPort_isOpen;
//    }

//    bool isMaterialDeliveryPortAvailable() const {
//        return materialDeliveryPort_isAvailable;
//    }

//public slots:
//    void serialTransportSlot_setLG_portName(const QString &name){
//        emit serialTransportSignal_setLgPortName(name);
//    }

//    void serialTransportSlot_openLaserGalvoPort(){
//        emit serialTransportSignal_openLaserGalvoPort();
//    }

//    void serialTransportSlot_closeLaserGalvoPort(){
//        emit serialTransportSignal_closeLaserGalvoPort();
//    }

//    void serialTransportSlot_clearLgPortErrors(){
//        emit serialTransportSignal_clearLaserGalvoPortErrors();
//    }

//    void serialTransportSlot_laserGalvoPort_CommandInput(const QString &command){
//        laserGalvoPort_isAvailable = false;
//        emit serialTransportSignal_laserGalvoCommand(command);
//    }

//    void serialTransportSlot_on_laserGalvoController_enabled(){
//        laserGalvoController_isEnabled = true;
//        emit serialTransportSignal_laserGalvoController_statusChanged(true);
//    }

//    void serialTransportSlot_on_laserGalvoController_disabled(){
//        laserGalvoController_isEnabled = false;
//        laserGalvoPort_isAvailable = false;
//        emit serialTransportSignal_laserGalvoController_statusChanged(false);
//    }

//    void serialTransportSlot_on_laserGalvoPort_opened(){
//        laserGalvoPort_isOpen = true;
//        emit serialTransportSignal_laserGalvoPort_isOpen();
//    }

//    void serialTransportSlot_on_laserGalvoPort_closed(){
//        laserGalvoPort_isOpen = false;
//        laserGalvoPort_isAvailable = false;
//        void serialTransportSignal_laserGalvoPort_isClosed();
//    }

//    void serialTransportSlot_on_laserGalvo_DeviceReply(const QString &reply){
//        laserGalvoPort_isAvailable = true;
//        emit serialTransportSignal_laserGalvo_replyOutput(reply);
//    }

//    void serialTransportSlot_on_laserGalvo_error(const QString &error){
//        laserGalvoPort_isAvailable = false;
//        emit serialTransportSignal_laserGalvo_errorOutput(error);
//    }

//    void serialTransportSlot_on_laserGalvo_transactionCompleted(){
//        laserGalvoPort_isAvailable = true;
//        emit serialTransportSignal_laserGalvo_transactionComplete();
//    }

//    void serialTransportSlot_setMD_portName(const QString &name){
//        emit serialTransportSignal_setMdPortName(name);
//    }

//    void serialTransportSlot_openMaterialDeliveryPort(){

//        emit serialTransportSignal_openMaterialDeliveryPort();
//    }


//    void serialTransportSlot_closeLMaterialDeliveryPort(){

//        emit serialTransportSignal_closeMaterialDeliveryPort();
//    }


//    void serialTransportSlot_clearMdPortErrors(){
//        emit serialTransportSignal_clearMaterialDeliveryPortErrors();
//    }

//    void serialTransportSlot_materialDelivery_CommandInput(const QString &command){
//        materialDeliveryPort_isAvailable = false;
//        emit serialTransportSignal_materialDeliveryCommand(command);
//    }

//    void serialTransportSlot_on_materialDeliveryController_enabled(){
//        materialDeliveryController_isEnabled = true;
//        emit serialTransportSignal_materialDeliveryController_statusChanged(true);
//    }

//    void serialTransportSlot_on_materialDeliveryController_disabled(){
//        materialDeliveryController_isEnabled = false;
//        materialDeliveryPort_isAvailable = false;
//        emit serialTransportSignal_materialDeliveryController_statusChanged(false);
//    }

//    void serialTransportSlot_on_materialDeliveryPort_opened(){
//        materialDeliveryPort_isOpen = true;
//        materialDeliveryPort_isAvailable = true;
//        emit serialTransportSignal_materialDeliveryPort_isOpen();
//    }

//    void serialTransportSlot_on_materialDeliveryPort_closed(){
//        materialDeliveryPort_isOpen = false;
//        materialDeliveryPort_isAvailable = false;
//        void serialTransportSignal_materialDeliveryPort_isClosed();
//    }

//    void  serialTransportSlot_on_materialDelivery_DeviceReply(const QString &reply){
//        materialDeliveryPort_isAvailable = true;
//        emit serialTransportSignal_materialDelivery_replyOutput(reply);
//    }

//    void  serialTransportSlot_on_materialDelivery_error(const QString &error){
//        materialDeliveryPort_isAvailable = false;
//        emit serialTransportSignal_materialDelivery_errorOutput(error);
//    }

//    void  serialTransportSlot_on_materialDelivery_transactionCompleted(){
//        materialDeliveryPort_isAvailable = true;
//        emit serialTransportSignal_materialDelivery_transactionComplete();
//    }

//signals:
//    // output
//    void serialTransportSignal_laserGalvoController_statusChanged(bool enabled);

//    void serialTransportSignal_laserGalvoPort_isOpen();
//    void serialTransportSignal_laserGalvoPort_isClosed();

//    void serialTransportSignal_laserGalvo_replyOutput(const QString &reply);
//    void serialTransportSignal_laserGalvo_errorOutput(const QString &error);
//    void serialTransportSignal_laserGalvo_transactionComplete();

//    void serialTransportSignal_materialDeliveryController_statusChanged(bool enabled);

//    void serialTransportSignal_materialDeliveryPort_isOpen();
//    void serialTransportSignal_materialDeliveryPort_isClosed();

//    void serialTransportSignal_materialDelivery_replyOutput(const QString &reply);
//    void serialTransportSignal_materialDelivery_errorOutput(const QString &error);
//    void serialTransportSignal_materialDelivery_transactionComplete();


//    // local
//    void serialTransportSignal_enableLaserGalvoController();
//    void serialTransportSignal_disableLaserGalvoController();

//    void serialTransportSignal_openLaserGalvoPort();
//    void serialTransportSignal_closeLaserGalvoPort();
//    void serialTransportSignal_clearLaserGalvoPortErrors();
//    void serialTransportSignal_laserGalvoCommand(const QString &command);

//    void serialTransportSignal_setLgPortName(const QString &name);

//    void serialTransportSignal_enableMaterialDeliveryController();
//    void serialTransportSignal_disableMaterialDeliveryController();

//    void serialTransportSignal_openMaterialDeliveryPort();
//    void serialTransportSignal_closeMaterialDeliveryPort();
//    void serialTransportSignal_clearMaterialDeliveryPortErrors();
//    void serialTransportSignal_materialDeliveryCommand(const QString &command);

//    void serialTransportSignal_setMdPortName(const QString &name);

//    void serialTransportSignal_newPartAvailable();

//private:
//    PortController *laserGalvoPort;
//    bool laserGalvoController_isEnabled;
//    bool laserGalvoPort_isOpen;
//    bool laserGalvoPort_isAvailable;

//    PortController *materialDeliveryPort;
//    bool materialDeliveryController_isEnabled;
//    bool materialDeliveryPort_isOpen;
//    bool materialDeliveryPort_isAvailable;
//};


//#endif // SERIALTRANSPORT_H
