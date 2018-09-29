#include "zaber_utility.h"
#include "QtDebug"
ZaberUtility::ZaberUtility()
{

}

QStringList ZaberUtility::composePositionCommand_String(PowderBlock *block, PowderSettings *config)
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

    return outputList;
}

QStringList ZaberUtility::composeSpeedCommand_String(PowderBlock *block, PowderSettings *config)
{
    uint32_t task = block->blockTask();

    QStringList outputList;

    QString modeString = " set maxspeed ";

    if(task & (PowderBlock::BlockTask::SET_Z_SPEED)){
        int devNum = config->z_deviceNumber();
        int axisNum = config->z_axisNumber();
        float res = config->z_position_resolution();
        QString Zoutput = "/" + QString::number(devNum) + " " + QString::number(axisNum);

        int speed = static_cast<int>(1.6384f*(block->z_speed()/res));
        Zoutput += (modeString + QString::number(speed) + "\r");

        outputList.append(Zoutput);
    }
    else
        outputList.append("EMPTY");


    if(task & (PowderBlock::BlockTask::SET_HOPPER_SPEED)){
        int devNum = config->hopper_deviceNumber();
        int axisNum = config->hopper_axisNumber();
        float res = config->hopper_position_resolution();
        QString Houtput = "/" + QString::number(devNum) + " " + QString::number(axisNum);

        int speed = static_cast<int>(1.6384f*(block->hopper_speed()/res));
        Houtput += (modeString + QString::number(speed) + "\r");

        outputList.append(Houtput);
    }
    else
        outputList.append("EMPTY");

    if(task & (PowderBlock::BlockTask::SET_SPREADER_SPEED)){
        int devNum = config->spreader_deviceNumber();
        int axisNum = config->spreader_axisNumber();
        float res = config->spreader_position_resolution();
        QString Soutput = "/" + QString::number(devNum) + " " + QString::number(axisNum);

        int speed = static_cast<int>(1.6384f*(block->spreader_speed()/res));
        Soutput += (modeString + QString::number(speed) + "\r");

        outputList.append(Soutput);
    }
    else
        outputList.append("EMPTY");

    return outputList;
}
