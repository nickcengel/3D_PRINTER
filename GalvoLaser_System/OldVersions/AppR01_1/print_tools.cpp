#include "print_tools.h"

namespace PRINT_CONTROL_NS {




Printer_State::Printer_State(){

}


Laser_Galvo_Device *Printer_State::laser_galvo(){
    return &m_laser_galvo;
}

Material_Delivery_Device *Printer_State::plate(){
    return &m_plate;
}

Material_Delivery_Device *Printer_State::hopper(){
    return &m_hopper;
}

Material_Delivery_Device *Printer_State::spreader(){
    return &m_spreader;
}





Print_System_Controller::Print_System_Controller(QObject *parent) : QObject(parent)
{
    controllerState = NO_PART;
}


void Print_System_Controller::Run_Print_Routine(){

        switch(controllerState)
        {

        case PRINT_INITIALIZE:
        {
            current_layerNumber = 0;
            L_blockNumber = 0;
            L_blockMax = 0;
            controllerState = PRINT_READY;
            break;
        }

        case PRINT_READY:
        {
            if(!paused){
                controllerState = PRINT_GET_NEXT_LAYER;
            }
            else
            {
                previous_controllerState = PRINT_READY;
                controllerState = PRINT_PAUSED;
            }
            break;
        }

        case PRINT_GET_NEXT_LAYER:
        {
            if(current_layerNumber < total_layers){
                L_blockNumber = 0;
                L_blockMax = currentPart->getLayer(current_layerNumber).get().size();
                controllerState = PRINT_GET_NEXT_BLOCK;
            }
            else
                controllerState = PRINT_DEINITIALIZE;
            break;
        }

        case PRINT_GET_NEXT_BLOCK:
        {
            if(L_blockNumber < L_blockMax){
                *pendingBlock = currentPart->getBlock(current_layerNumber, L_blockNumber);
                controllerState = PRINT_SEND_BLOCK;
            }
            else
                controllerState = PRINT_LAYER_COMPLETE;
            break;
        }

        case PRINT_SEND_BLOCK:
        {
            send_block();
            controllerState = PRINT_WAIT_FOR_REPLY;
            break;
        }

        case PRINT_WAIT_FOR_REPLY:
        {
            if(!lg_pending && !md_pending)
                controllerState = PRINT_BLOCK_COMPLETE;
            break;
        }

        case PRINT_BLOCK_COMPLETE:
        {
            if(!paused){
                L_blockNumber++;
                current_blockNumber++;
                controllerState = PRINT_GET_NEXT_BLOCK;
            }
            else
            {
                previous_controllerState = PRINT_BLOCK_COMPLETE;
                controllerState = PRINT_PAUSED;
            }
            break;
        }


        case PRINT_LAYER_COMPLETE:
        {
            if(!paused){
                current_layerNumber++;
                controllerState = PRINT_GET_NEXT_LAYER;
            }
            else
            {
                previous_controllerState = PRINT_LAYER_COMPLETE;
                controllerState = PRINT_PAUSED;
            }
            break;
        }

        case PRINT_COMPLETE:
        {

            break;
        }

        case PRINT_PAUSED:
        {
            if(resume)
                controllerState = PRINT_RESUME;
            break;
        }

        case PRINT_RESUME:
        {
            controllerState = previous_controllerState;
            break;
        }

        case PRINT_DEINITIALIZE:
        {
            controllerState = PRINT_COMPLETE;
            break;
        }

        default:
            break;
        }
}


void Print_System_Controller::Controller_Load_Part_Slot(Part &p){
    currentPart = &p;
    current_layerNumber = 0;
    current_blockNumber = 0;
    total_blocks = currentPart->get_BlockCount();
    total_layers = currentPart->get_LayerCount();
    controllerState = PART_LOADED;
}


void Print_System_Controller::Controller_Start_Slot(){
    if(currentPart != nullptr)
        controllerState = PRINT_INITIALIZE;
}

void Print_System_Controller::send_block(){
    if(pendingBlock->Laser_Galvo()->is_deviceActive()){
        lg_pending = true;
        QString s1 = pendingBlock->Laser_Galvo()->get_deviceString();
        emit Laser_Galvo_Command(s1);
    }
    if(pendingBlock->Plate()->is_deviceActive()){
        md_pending = true;
        QString s2 = pendingBlock->Plate()->get_deviceString();
        emit Material_Delivery_Command(s2);
    }
    if(pendingBlock->Hopper()->is_deviceActive()){
        md_pending = true;
        QString s3 = pendingBlock->Hopper()->get_deviceString();
        emit Material_Delivery_Command(s3);
    }
    if(pendingBlock->Spreader()->is_deviceActive()){
        md_pending = true;
        QString s4 = pendingBlock->Spreader()->get_deviceString();
        emit Material_Delivery_Command(s4);
    }
}




void Print_System_Controller::Laser_Galvo_Socket(QString rs){

    if(rs.contains("@ok")){
        lg_pending = false;
        if(pendingBlock->Laser_Galvo()->task & (CHANGE_LG_POSITION_MODE)){
            printerState.laser_galvo()->set_positionMode(pendingBlock->Laser_Galvo()->get_positionMode());
        }
        if(pendingBlock->Laser_Galvo()->task & (CHANGE_LG_SPEED)){
            printerState.laser_galvo()->set_speed(pendingBlock->Laser_Galvo()->get_speed());
        }

        if(pendingBlock->Laser_Galvo()->task & (CHANGE_LG_X_POSITION)){
            printerState.laser_galvo()->set_x_position(pendingBlock->Laser_Galvo()->x_axis.get_position());
        }

        if(pendingBlock->Laser_Galvo()->task & (CHANGE_LG_X_POSITION)){
            printerState.laser_galvo()->set_x_position(pendingBlock->Laser_Galvo()->x_axis.get_position());
        }
        else if(pendingBlock->Laser_Galvo()->task & (DO_LG_X_GO_HOME)){
            printerState.laser_galvo()->x_axis.set_homed(true);
            printerState.laser_galvo()->x_axis.clear_go_home();
        }

        if(pendingBlock->Laser_Galvo()->task & (CHANGE_LG_X_POSITION)){
            printerState.laser_galvo()->set_x_position(pendingBlock->Laser_Galvo()->x_axis.get_position());
        }
        else if(pendingBlock->Laser_Galvo()->task & (DO_LG_Y_GO_HOME)){
            printerState.laser_galvo()->y_axis.set_homed(true);
            printerState.laser_galvo()->y_axis.clear_go_home();
        }

        if(pendingBlock->Laser_Galvo()->task & (CHANGE_LASER_ARMED)){
            printerState.laser_galvo()->set_arm_disarm(pendingBlock->Laser_Galvo()->laser.is_armed());
        }

        if(pendingBlock->Laser_Galvo()->task & (CHANGE_LASER_ENABLED)){
            printerState.laser_galvo()->set_enable_disable(pendingBlock->Laser_Galvo()->laser.is_enabled());
        }

        if(pendingBlock->Laser_Galvo()->task & (CHANGE_LASER_ENABLED)){
            printerState.laser_galvo()->set_enable_disable(pendingBlock->Laser_Galvo()->laser.is_enabled());
        }

        if(pendingBlock->Laser_Galvo()->task & (CHANGE_LASER_POWER)){
            printerState.laser_galvo()->set_power(pendingBlock->Laser_Galvo()->laser.get_power());
        }
    }
}


void Print_System_Controller::Material_Delivery_Socket(QString rs){

    if(rs.contains("@ok")){
        md_pending = false;

        if(pendingBlock->Plate()->is_deviceActive() && (pendingBlock->Plate()->task != 0x0)){
            if(pendingBlock->Plate()->task & CHANGE_MD_POSITION_MODE){
                printerState.plate()->set_positionMode(pendingBlock->Plate()->get_positionMode());
            }

            if(pendingBlock->Plate()->task & CHANGE_MD_POSITION){
                printerState.plate()->set_position(pendingBlock->Plate()->get_position());
            }
            else if(pendingBlock->Plate()->task & DO_MD_GO_HOME){
                printerState.plate()->set_homed(true);
                printerState.plate()->clear_go_home();
            }

            if(pendingBlock->Plate()->task & CHANGE_MD_ENABLED){
                printerState.plate()->set_enable_disable(pendingBlock->Plate()->is_enabled());
            }

            if(pendingBlock->Plate()->task & (CHANGE_MD_STOPPED)){
                printerState.plate()->set_clear_stop(true);
            }
        }

        if(pendingBlock->Hopper()->is_deviceActive() && (pendingBlock->Hopper()->task != 0x0)){
            if(pendingBlock->Hopper()->task & CHANGE_MD_POSITION_MODE){
                printerState.hopper()->set_positionMode(pendingBlock->Hopper()->get_positionMode());
            }

            if(pendingBlock->Hopper()->task & CHANGE_MD_POSITION){
                printerState.hopper()->set_position(pendingBlock->Hopper()->get_position());
            }
            else if(pendingBlock->Hopper()->task & DO_MD_GO_HOME){
                printerState.hopper()->set_homed(true);
                printerState.hopper()->clear_go_home();
            }

            if(pendingBlock->Hopper()->task & CHANGE_MD_ENABLED){
                printerState.hopper()->set_enable_disable(pendingBlock->Hopper()->is_enabled());
            }

            if(pendingBlock->Hopper()->task & (CHANGE_MD_STOPPED)){
                printerState.hopper()->set_clear_stop(true);
            }
        }

        if(pendingBlock->Spreader()->is_deviceActive() && (pendingBlock->Spreader()->task != 0x0)){
            if(pendingBlock->Spreader()->task & CHANGE_MD_POSITION_MODE){
                printerState.spreader()->set_positionMode(pendingBlock->Spreader()->get_positionMode());
            }

            if(pendingBlock->Spreader()->task & CHANGE_MD_POSITION){
                printerState.spreader()->set_position(pendingBlock->Spreader()->get_position());
            }
            else if(pendingBlock->Spreader()->task & DO_MD_GO_HOME){
                printerState.spreader()->set_homed(true);
                printerState.spreader()->clear_go_home();
            }

            if(pendingBlock->Spreader()->task & CHANGE_MD_ENABLED){
                printerState.spreader()->set_enable_disable(pendingBlock->Spreader()->is_enabled());
            }

            if(pendingBlock->Spreader()->task & (CHANGE_MD_STOPPED)){
                printerState.spreader()->set_clear_stop(true);
            }
        }
    }
}








}



