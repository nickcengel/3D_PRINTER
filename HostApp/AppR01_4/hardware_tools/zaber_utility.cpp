#include "zaber_utility.h"
ZaberUtility::ZaberUtility()
{

}

QString ZaberUtility::composeCommandString(BlockObject *block, SettingsObject *config)
{
    uint16_t task = block->blockTask();

    QString modeString;
    QString Zoutput;
    QString Houtput;
    QString Soutput;
    QString cat_output;

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
        Zoutput = "/" + QString::number(devNum) + " " + QString::number(axisNum);
        if(modeString != " home\r"){
            float pos = res * (block->z_position());
            Zoutput += (modeString + QString::number(pos) + "\r");
        }
        else
        {
            Zoutput += modeString;
        }
    }

    if(task & (BlockObject::BlockTask::SET_HOPPER_POSITION)){
        uint8_t devNum = config->hopper_deviceNumber();
        uint8_t axisNum = config->hopper_axisNumber();
        float res = config->hopper_position_resolution();
        Houtput = "/" + QString::number(devNum) + " " + QString::number(axisNum);
        if(modeString != " home\r"){
            float pos = res * (block->hopper_position());
            Houtput += (modeString + QString::number(pos) + "\r");
        }
        else
        {
            Houtput += modeString;
        }
    }

    if(task & (BlockObject::BlockTask::SET_SPREADER_POSITION)){
        uint8_t devNum = config->spreader_deviceNumber();
        uint8_t axisNum = config->spreader_axisNumber();
        float res = config->spreader_position_resolution();
        Soutput = "/" + QString::number(devNum) + " " + QString::number(axisNum);
        if(modeString != " home\r"){
            float pos = res * (block->spreader_position());
            Soutput += (modeString + QString::number(pos) + "\r");
        }
        else
        {
            Soutput += modeString;
        }
    }

    if(!Zoutput.isEmpty())
        cat_output = Zoutput;
    if(!Houtput.isEmpty())
        cat_output += Houtput;
    if(!Soutput.isEmpty())
        cat_output += Soutput;
    if(cat_output.isEmpty())
        cat_output = "EMPTY";
    return cat_output;
}
