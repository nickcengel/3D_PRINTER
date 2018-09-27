#include "zaber_utility.h"
#include "QtDebug"
ZaberUtility::ZaberUtility()
{

}

QStringList ZaberUtility::composeCommandString(PowderBlock *block, PowderSettings *config)
{
    uint32_t task = block->blockTask();

    QStringList outputList;

    QString modeString;



    if(task & PowderBlock::BlockTask::SET_HOME_AXIS){
        modeString = " home\r";
    }
    else if(block->positionMode() == PowderBlock::PositionMode::Position_Absolute){
        modeString = " move abs ";
    }
    else if(block->positionMode() == PowderBlock::PositionMode::Position_Relative){
        modeString = " move rel ";
    }

    if(task & (PowderBlock::BlockTask::SET_Z_POSITION)){
        int devNum = config->z_deviceNumber();
        int axisNum = config->z_axisNumber();
        float res = config->z_position_resolution();
        QString Zoutput = "/" + QString::number(devNum) + " " + QString::number(axisNum);
        if(modeString != " home\r"){
            int pos = static_cast<int>(res * (block->z_position()));
            Zoutput += (modeString + QString::number(pos) + "\r");
        }
        else
        {
            Zoutput += modeString;
        }
        outputList.append(Zoutput);
    }
    else
        outputList.append("EMPTY");


    if(task & (PowderBlock::BlockTask::SET_HOPPER_POSITION)){
        int devNum = config->hopper_deviceNumber();
        int axisNum = config->hopper_axisNumber();
        float res = config->hopper_position_resolution();
        QString Houtput = "/" + QString::number(devNum) + " " + QString::number(axisNum);
        if(modeString != " home\r"){
            int pos = static_cast<int>(res * (block->hopper_position()));
            Houtput += (modeString + QString::number(pos) + "\r");
        }
        else
        {
            Houtput += modeString;
        }
        outputList.append(Houtput);
    }
    else
        outputList.append("EMPTY");

    if(task & (PowderBlock::BlockTask::SET_SPREADER_POSITION)){
        int devNum = config->spreader_deviceNumber();
        int axisNum = config->spreader_axisNumber();
        float res = config->spreader_position_resolution();
        QString Soutput = "/" + QString::number(devNum) + " " + QString::number(axisNum);
        if(modeString != " home\r"){
            int pos = static_cast<int>(res * (block->spreader_position()));
            Soutput += (modeString + QString::number(pos) + "\r");
        }
        else
        {
            Soutput += modeString;
        }
        outputList.append(Soutput);
    }
    else
        outputList.append("EMPTY");

    if(task == (PowderBlock::BlockTask::SET_Z_SPEED)){
        int devNum = config->z_deviceNumber();
        int axisNum = config->z_axisNumber();
        QString speedString = "/" + QString::number(devNum) + " " + QString::number(axisNum);
        speedString += " set maxspeed ";
        double res = 1.6384*static_cast<double>(config->z_position_resolution()*block->z_speed());
        speedString += (QString::number(res) + "\r");
        outputList.append(speedString);
    }
    else if(task == (PowderBlock::BlockTask::SET_HOPPER_SPEED)){
        int devNum = config->hopper_deviceNumber();
        int axisNum = config->hopper_axisNumber();
        QString speedString = "/" + QString::number(devNum) + " " + QString::number(axisNum);
        speedString += " set maxspeed ";
        double res = 1.6384*static_cast<double>(config->hopper_position_resolution()*block->hopper_speed());
        speedString += (QString::number(res) + "\r");
        outputList.append(speedString);
    }
//    else if(task == (PowderBlock::BlockTask::SET_SPREADER_SPEED)){
//        int devNum = config->spreader_deviceNumber();
//        int axisNum = config->spreader_axisNumber();
//        QString speedString = "/" + QString::number(devNum) + " " + QString::number(axisNum);
//        speedString += " set maxspeed ";
//        double res = 1.6384*static_cast<double>(config->spreader_position_resolution()*block->spreader_speed());
//        speedString += (QString::number(res) + "\r");
//        outputList.append(speedString);
//    }
//    else
//        outputList.append("EMPTY");

    return outputList;
}
