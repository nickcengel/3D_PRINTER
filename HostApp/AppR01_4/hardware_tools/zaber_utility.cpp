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
        modeString = " abs ";
    }
    else if(block->positionMode() == BlockObject::PositionMode::Position_Relative){
        modeString = " rel ";
    }

    if(task & (BlockObject::BlockTask::SET_Z_POSITION)){
        uint8_t devNum = config->z_deviceNumber();
        uint8_t axisNum = config->z_axisNumber();
        float res = config->z_position_resolution();
        QString Zoutput = "/" + QString::number(devNum) + " " + QString::number(axisNum);
        if(modeString != " home\r"){
            float pos = res * (block->z_position());
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
        uint8_t devNum = config->hopper_deviceNumber();
        uint8_t axisNum = config->hopper_axisNumber();
        float res = config->hopper_position_resolution();
        QString Houtput = "/" + QString::number(devNum) + " " + QString::number(axisNum);
        if(modeString != " home\r"){
            float pos = res * (block->hopper_position());
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
        uint8_t devNum = config->spreader_deviceNumber();
        uint8_t axisNum = config->spreader_axisNumber();
        float res = config->spreader_position_resolution();
        QString Soutput = "/" + QString::number(devNum) + " " + QString::number(axisNum);
        if(modeString != " home\r"){
            float pos = res * (block->spreader_position());
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

QString ZaberUtility::composeJogCommandString(BlockObject::BlockTask axisTask, int32_t distance)
{
    QString output = "/";
    //    if(axisTask & BlockObject::BlockTask::SET_Z_POSITION){
    //        output += QString::number(config->z_deviceNumber());
    //        output += " " + QString::number(config->z_axisNumber());
    //        float pos = config->z_position_resolution() * distance;
    //        output += " " + QString::number(pos) + "\r";
    //    }
    //    else if (axisTask & BlockObject::BlockTask::SET_HOPPER_POSITION){
    //        output += QString::number(config->hopper_deviceNumber());
    //        output += " " + QString::number(config->hopper_axisNumber());
    //        float pos = config->hopper_position_resolution() * distance;
    //        output += " " + QString::number(pos) + "\r";
    //    }
    //    else if (axisTask & BlockObject::BlockTask::SET_SPREADER_POSITION){
    //        output += QString::number(config->spreader_deviceNumber());
    //        output += " " + QString::number(config->spreader_axisNumber());
    //        float pos = config->spreader_position_resolution() * distance;
    //        output += " " + QString::number(pos) + "\r";
    //    }
    return output;
}
