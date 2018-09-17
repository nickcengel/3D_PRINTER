#include "lasergalvo_utility.h"

LaserGalvo_Utility::LaserGalvo_Utility()
{

}

QString LaserGalvo_Utility::composeCommandString(BlockObject *block, SettingsObject *config)
{
    uint16_t task = block->blockTask();

    bool delim = false;
    QString output = "$(";

    if(task & BlockObject::BlockTask::SET_POSITION_MODE){
        delim = true;
        if(block->positionMode() == BlockObject::PositionMode::Position_Absolute){
            output += "g=4";
        }
        else if(block->positionMode() == BlockObject::PositionMode::Position_Relative){
            output += "g=3";
        }
    }

    if(task & BlockObject::BlockTask::SET_XY_SPEED){
        if(delim)
            output += ",";
        else
            delim = true;
        output += ("s=" + QString::number(static_cast<double>(block->xy_speed())));
    }

    if(task & BlockObject::BlockTask::SET_X_POSITION){
        if(delim)
            output += ",";
        else
            delim = true;
        float res = config->x_position_resolution();
        int pos = static_cast<int>(res * (block->x_position()));
        output += ("X=" + QString::number(pos));
    }

    if(task & BlockObject::BlockTask::SET_Y_POSITION){
        if(delim)
            output += ",";
        else
            delim = true;
        float res = config->y_position_resolution();
        int pos = static_cast<int>(res * (block->y_position()));
        output += ("Y=" + QString::number(pos));
    }

    if(task & BlockObject::BlockTask::SET_LASER_ENABLE_STATE){
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

    if(task & BlockObject::BlockTask::SET_LASER_POWER){
        if(delim)
            output += ",";
        else
            delim = true;
        output += ("p=" + QString::number(block->laser_power()));
    }

    output += ")";
    if(output == "$()"){
        output = "EMPTY";
    }

    return output;
}

QString LaserGalvo_Utility::composeJogCommandString(BlockObject::BlockTask axisTask, int32_t steps)
{
    QString output = "$(g=3,";
    if(axisTask & BlockObject::BlockTask::SET_X_POSITION){
        output += ("X=" + QString::number(steps));
    }

    else if(axisTask & BlockObject::BlockTask::SET_Y_POSITION){
        output += ("Y=" + QString::number(steps));
    }
    output += ")";
    if(output == "$(g=3,"){
        output = "";
    }
    return output;
}
