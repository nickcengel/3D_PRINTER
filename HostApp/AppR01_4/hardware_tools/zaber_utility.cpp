#include "zaber_utility.h"
#include "QtDebug"
ZaberUtility::ZaberUtility()
{

}

QStringList ZaberUtility::composeCommandString(BlockObject *block, SettingsObject *config)
{
    uint16_t task = block->blockTask();
    QStringList outputList;

    QString modeString;

    if(task & BlockObject::BlockTask::SET_HOME_AXIS){
        modeString = " home\r";
    }
    else if(block->positionMode() == BlockObject::PositionMode::Position_Absolute){
        modeString = " move abs ";
    }
    else if(block->positionMode() == BlockObject::PositionMode::Position_Relative){
        modeString = " move rel ";
    }

    if(task & (BlockObject::BlockTask::SET_Z_POSITION)){
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


    if(task & (BlockObject::BlockTask::SET_HOPPER_POSITION)){
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

    if(task & (BlockObject::BlockTask::SET_SPREADER_POSITION)){
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
    return outputList;
}
