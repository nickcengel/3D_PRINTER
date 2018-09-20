#include "hardware_drivers.h"

namespace HARDWARE_NS{
HARDWARE_NS::AXIS_NUMBER Axis::get_axisNumber(){
    return axisNumber;
}

void Axis::set_axisNumber(AXIS_NUMBER n){
    axisNumber = n;
}

float Axis::get_position(){

    return position;
}

bool Axis::is_homed(){
    return homed;
}

void Axis::set_homed(bool h){
    homed = h;
}


void Axis::clear_go_home(){
    go_home = false;
}

float Axis::get_uStepPerMM(){
    return  uStepPerMM;
}

void Axis::set_uStepPerMM(float k){
    uStepPerMM = k;
}

bool Laser::is_armed(){
    return armed;
}


bool Laser::is_enabled(){
    return enabled;
}

int Laser::get_power(){
    return power;
}

AXIS_NUMBER Laser::get_axisNumber(){
    return axisNumber;
}

void Laser::set_axisNumber(AXIS_NUMBER n){
    axisNumber = n;
}

DEVICE_NUMBER Device::get_deviceNumber(){
    return  deviceNumber;
}
void Device::set_deviceNumber(DEVICE_NUMBER n){
    deviceNumber = n;
}

bool Device::is_deviceActive(){

    return deviceActive;
}
void Device::activate_device(){
    deviceActive = true;
}
void Device::deactivate_device(){
    deviceActive = false;
}

POSITION_MODE Device::get_positionMode(){
    return positionMode;
}

QString Device::get_deviceString(){
    return deviceString;
}

void Device::set_deviceString(QString s){
    deviceString = s;
}


Material_Delivery_Device::Material_Delivery_Device(){

    positionMode = ABSOLUTE;
}


int Material_Delivery_Device::get_speed(){
    return speed;
}


bool Material_Delivery_Device::is_enabled(){
    return enabled;
}

void Material_Delivery_Device::set_enable_disable(bool e){
    enabled = e;
    task = (task)|(MD_TASKS::CHANGE_MD_ENABLED);
}

void Material_Delivery_Device::set_positionMode(POSITION_MODE m){
    if(positionMode != m){
        positionMode = m;
        task = (task)|(MD_TASKS::CHANGE_MD_POSITION_MODE);
    }
}

void Material_Delivery_Device::set_speed(int v){
    speed = v;
    task = (task)|(MD_TASKS::CHANGE_MD_SPEED);
    activate_device();
}

void Material_Delivery_Device::set_position(float p){
    position = p;
    task = (task)|(MD_TASKS::CHANGE_MD_POSITION);
    activate_device();
}

void Material_Delivery_Device::go_home(){
    task = (task)|(MD_TASKS::DO_MD_GO_HOME);
    activate_device();
}

void Material_Delivery_Device::set_clear_stop(bool s){
    stopped = s;
}

bool Material_Delivery_Device::is_stopped(){
    return stopped;
}

void Material_Delivery_Device::make_commandString(){

    if(is_deviceActive() && (task != 0x0)){
        QString myString = ("/" + QString::number(get_deviceNumber())
                            + " " + QString::number(get_axisNumber()));

        if(task & (MD_TASKS::CHANGE_MD_POSITION)){
            if(get_positionMode() == POSITION_MODE::ABSOLUTE){
                myString += " move abs ";
            }
            else if (get_positionMode() == POSITION_MODE::RELATIVE){
                myString += " move rel ";
            }
            int32_t p = static_cast<int32_t>(get_uStepPerMM()*get_position());
            myString += (QString::number(p) + "\r");
        }

        else if(task & (MD_TASKS::DO_MD_GO_HOME)){
            myString += " home\r";
        }

        else if(task == MD_TASKS::CHANGE_MD_ENABLED){
            if(is_enabled())
                myString += " on\r";
            else
                myString += " off\r";
        }

        else if (task & (MD_TASKS::CHANGE_MD_STOPPED)) {
            myString += " stop\r";
        }
        set_deviceString(myString);
    }
}

Laser_Galvo_Device::Laser_Galvo_Device(){
    positionMode = ABSOLUTE;
}

int Laser_Galvo_Device::get_speed(){
    return speed;
}

void Laser_Galvo_Device::set_positionMode(POSITION_MODE m){
    if(m != positionMode){
        positionMode = m;
        task = (task)|(CHANGE_LG_POSITION_MODE);
    }
}

void Laser_Galvo_Device::set_speed(int v){
    speed = v;
    task = (task)|(CHANGE_LG_SPEED);
    activate_device();
}

void Laser_Galvo_Device::set_x_position(float x){
    x_axis.position = x;
    task = (task)|(CHANGE_LG_X_POSITION);
    activate_device();
}

void Laser_Galvo_Device::set_y_position(float y){
    y_axis.position = y;
    task = (task)|(CHANGE_LG_Y_POSITION);
    activate_device();
}

void Laser_Galvo_Device::x_go_home(){
    task = (task)|(DO_LG_X_GO_HOME);
    activate_device();
}

void Laser_Galvo_Device::y_go_home(){
    task = (task)|(DO_LG_Y_GO_HOME);
    activate_device();
}

void Laser_Galvo_Device::set_arm_disarm(bool a){
    laser.armed = a;
    task = (task)|(CHANGE_LASER_ARMED);
    activate_device();
}

void Laser_Galvo_Device::set_enable_disable(bool e){
    laser.enabled = e;
    task = (task)|(CHANGE_LASER_ENABLED);
    activate_device();
}

void Laser_Galvo_Device::set_power(int p){
    laser.power = p;
    task = (task)|(CHANGE_LASER_POWER);
    activate_device();
}

void Laser_Galvo_Device::make_commandString(){
    bool delim = false;
    if(is_deviceActive() && (task != 0x0)){
        QString myString = "$(";

        if(task & (CHANGE_LG_POSITION_MODE)){
            myString += "g=";
            if(get_positionMode() == POSITION_MODE::ABSOLUTE)
                myString += "4";
            else if(get_positionMode() == POSITION_MODE::RELATIVE)
                myString += "3";
            delim = true;
        }

        if(task & (CHANGE_LG_SPEED)){
            if(delim)
                myString += ",";
            else
                delim = true;
            myString += ("s=" + QString::number(get_speed()));
        }

        if(task & (CHANGE_LG_X_POSITION)){
            if(delim)
                myString += ",";
            else
                delim = true;
            int32_t x =  static_cast<int32_t>(x_axis.get_uStepPerMM()*x_axis.get_position());
            myString += ("X=" + QString::number(x));
        }
        else if(task & (DO_LG_X_GO_HOME)){
            if(delim)
                myString += ",";
            else
                delim = true;
            myString += "X=0 ";
        }

        if(task & (CHANGE_LG_Y_POSITION)){
            if(delim)
                myString += ",";
            else
                delim = true;
            int32_t y =  static_cast<int32_t>(y_axis.get_uStepPerMM()*y_axis.get_position());
            myString += ("Y=" + QString::number(y));
        }
        else if(task & (DO_LG_Y_GO_HOME)){
            if(delim)
                myString += ",";
            else
                delim = true;
            myString += "Y=0";

        }

        if(task & (CHANGE_LASER_ARMED)){
            if(delim)
                myString += ",";
            else
                delim = true;
            if(laser.is_armed())
                myString += "L=1";
            else
                myString += "L=0";
        }

        if(task & (CHANGE_LASER_ENABLED)){
            if(delim)
                myString += ",";
            else
                delim = true;
            if(laser.is_enabled())
                myString += "l=1";
            else
                myString += "l=0";
        }

        if(task & (CHANGE_LASER_POWER)){
            if(delim)
                myString += ",";
            else
                delim = true;
            myString += ("p=" + QString::number(laser.get_power()));
        }
        myString += ")";

        set_deviceString(myString);
    }
}
}
