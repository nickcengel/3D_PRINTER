#include "galvo_utility.h"

GalvoUtility::GalvoUtility()
{

}

QString GalvoUtility::composeCommandString(PowderBlock *block, PowderSettings *config)
{
    uint32_t task = block->blockTask();

    bool delim = false;
    QString output = "$(";

    if(task & PowderBlock::BlockTask::SET_POSITION_MODE){
        delim = true;
        if(block->positionMode() == PowderBlock::PositionMode::Position_Absolute){
            output += "g=4";
        }
        else if(block->positionMode() == PowderBlock::PositionMode::Position_Relative){
            output += "g=3";
        }
    }

    if(task & PowderBlock::BlockTask::SET_XY_SPEED){
        if(delim)
            output += ",";
        else
            delim = true;

        float avg_res_steps_mm = (config->x_position_resolution() + config->y_position_resolution())/2.0f;
        const int speed = static_cast<int>(block->xy_speed()*avg_res_steps_mm*0.001024f); // units: (steps/usecond)*1024

        output += ("s=" + QString::number(speed));
    }

    if(task & PowderBlock::BlockTask::SET_X_POSITION){
        if(delim)
            output += ",";
        else
            delim = true;
        float res = config->x_position_resolution();
        int pos = static_cast<int>(res * (block->x_position()));
        output += ("X=" + QString::number(pos));
    }

    if(task & PowderBlock::BlockTask::SET_Y_POSITION){
        if(delim)
            output += ",";
        else
            delim = true;
        float res = config->y_position_resolution();
        int pos = static_cast<int>(res * (block->y_position()));
        output += ("Y=" + QString::number(pos));
    }

    if(task & PowderBlock::BlockTask::SET_LASER_ENABLE_STATE){
        if(delim)
            output += ",";
        else
            delim = true;
        if(block->laser_enabled()){
            output += "l=1";
        }
        else
        {
            output += "l=0";
        }
    }

    output += ")";
    if(output == "$()"){
        output = "EMPTY";
    }

    return output;
}

QString GalvoUtility::composeJogCommandString(PowderBlock::BlockTask axisTask, int32_t steps)
{
    QString output = "$(g=3,";
    if(axisTask & PowderBlock::BlockTask::SET_X_POSITION){
        output += ("X=" + QString::number(steps));
    }

    else if(axisTask & PowderBlock::BlockTask::SET_Y_POSITION){
        output += ("Y=" + QString::number(steps));
    }
    output += ")";
    if(output == "$(g=3,"){
        output = "";
    }
    return output;
}
