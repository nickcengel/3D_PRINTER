//#include "printmanager.h"

//PrintManager::PrintManager(QObject *parent) : QObject(parent)
//{




//}

//void PrintManager::setupPrintManager()
//{

//    QStateMachine *printerStateMachine = new QStateMachine(this);
//    QState *printerInitState = new QState(printerStateMachine);
//    QState *printerReadyState = new QState(printerStateMachine);
//    QState *printerRunningState = new QState(printerStateMachine);
//    QState *printerPausedState = new QState(printerStateMachine);
//    QState *printerStoppedState = new QState(printerStateMachine);

//    QState *generateProcessQueueFromBlock = new QState(printerRunningState);
//    QState *selectProcessFromQueue = new QState(printerRunningState);
//    QState *runLaserGalvoProcess = new QState(printerRunningState);
//    QState *runMaterialDeliveryProcess = new QState(printerRunningState);
//    QState *updateUiWithBlockData = new QState(printerRunningState);
//    QState *selectNextBlockToProcess = new QState(printerRunningState);




//}
