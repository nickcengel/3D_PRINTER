#include "devicemodels.h"
#include "blockio.h"
#include <QObject>
using BlockIO::Axis_Number;
using BlockIO::Message_Task;
using BlockIO::Message_Mode;
using BlockIO::Message;
using BlockIO::Block;
using BlockIO::Message_Status;
using BlockIO::machine_settings_t;
using BlockIO::axis_settings_t;
using BlockIO::Message_Reply_Flag;
using BlockIO::Message_Status;




////////////////////////////////////////// BEGIN Axis CLASS //////////////////////////////////////////
Axis::Axis()
{
    m_portNumber = -1;
    m_deviceNumber = -1;
    m_modePending = false;
    m_taskPending = false;
    m_homed = false;
    m_positionPending = false;
    m_speedPending = false;
    setCurrentMode(Message_Mode::NO_MODE);
    setCurrentTask(Message_Task::NO_TASK);
    setCurrentStatus(Message_Status::NO_STATUS);
}

Axis::Axis(const int portNumber, const Device_Number deviceNumber, const Axis_Number axisNumber)
{
    m_portNumber = portNumber;
    m_deviceNumber = deviceNumber;
    m_axisNumber = axisNumber;
    m_modePending = false;
    m_taskPending = false;
    m_homed = false;
    m_positionPending = false;
    m_speedPending = false;
    setCurrentMode(Message_Mode::NO_MODE);
    setCurrentTask(Message_Task::NO_TASK);
    setCurrentStatus(Message_Status::NO_STATUS);
}


int Axis::getPortNumber() const
{
    return m_portNumber;
}

void Axis::setPortNumber(const int portNumber)
{
    m_portNumber = portNumber;
}

int Axis::getDeviceNumber() const
{
    return m_deviceNumber;
}

void Axis::setDeviceNumber(const Device_Number deviceNumber)
{
    m_deviceNumber = deviceNumber;
}

Axis_Number Axis::getAxisNumber() const
{
    return m_axisNumber;
}

void Axis::setAxisNumber(const Axis_Number axisNumber)
{
    m_axisNumber = axisNumber;
}

void Axis::setHomed(const bool isHomed)
{
    m_homed = isHomed;
}

bool Axis::isHomed() const
{
    return m_homed;
}

void Axis::setDesiredPosition(const float position)
{
    m_desiredPosition = position;
    m_positionPending = true;
}

float Axis::getDesiredPosition() const
{
    return m_desiredPosition;
}

bool Axis::isPositionPending() const
{
    return m_positionPending;
}

void Axis::setCurrentPosition(const float position)
{
    m_currentPosition = position;
    m_positionPending = false;
}

float Axis::getCurrentPosition() const
{
    return m_currentPosition;
}

void Axis::setDesiredSpeed(const float speed)
{
    m_desiredSpeed = speed;
    m_speedPending = true;
}

float Axis::getDesiredSpeed() const
{
    return m_desiredSpeed;
}

bool Axis::isSpeedPending() const
{
    return m_speedPending;
}

void Axis::setCurrentSpeed(const float speed)
{
    m_currentSpeed = speed;
    m_speedPending = false;
}


float Axis::getCurrentSpeed() const
{
    return m_currentSpeed;
}



Message_Mode Axis::getDesiredMode() const
{
    return m_desiredMode;
}

void Axis::setDesiredMode(const Message_Mode m)
{
    m_desiredMode = m;
    m_modePending = true;
}

bool Axis::isModePending() const
{
    return m_modePending;
}

void Axis::setCurrentMode(const Message_Mode m)
{
    m_modePending = false;
    m_currentMode = m;
}

Message_Mode Axis::getCurrentMode() const
{
    return m_currentMode;
}

Message_Task Axis::getCurrentTask() const
{
    return m_currentTask;
}

void Axis::setCurrentTask(const Message_Task task)
{
    m_taskPending = false;
    m_currentTask = task;
}

Message_Task Axis::getDesiredTask() const
{
    return m_desiredTask;
}

void Axis::setDesiredTask(const Message_Task task)
{
    m_taskPending = true;
    m_desiredTask = task;
}

bool Axis::isTaskPending() const
{
    return m_taskPending;
}

Message_Status Axis::getCurrentStatus() const
{
    return m_currentStatus;
}

void Axis::setCurrentStatus(const Message_Status currentStatus)
{
    m_currentStatus = currentStatus;
}










////////////////////////////////////////// END Axis CLASS //////////////////////////////////////////



////////////////////////////////////////// BEGIN Laser CLASS //////////////////////////////////////////

Laser::Laser()
{
    m_portNumber = -1;
    m_deviceNumber = -1;
    m_modePending = false;
    m_taskPending = false;
    m_powerPending = false;
    setCurrentMode(Message_Mode::NO_MODE);
    setCurrentTask(Message_Task::NO_TASK);
    setCurrentStatus(Message_Status::NO_STATUS);
}

Laser::Laser(const int portNumber, const Device_Number deviceNumber, const Axis_Number axisNumber)
{
    m_portNumber = portNumber;
    m_deviceNumber = deviceNumber;
    m_axisNumber = axisNumber;
    m_modePending = false;
    m_taskPending = false;
    m_powerPending = false;
    setCurrentMode(Message_Mode::NO_MODE);
    setCurrentTask(Message_Task::NO_TASK);
    setCurrentStatus(Message_Status::NO_STATUS);
}


int Laser::getPortNumber() const
{
    return m_portNumber;
}

void Laser::setPortNumber(const int portNumber)
{
    m_portNumber = portNumber;
}

int Laser::getDeviceNumber() const
{
    return m_deviceNumber;
}

void Laser::setDeviceNumber(const Device_Number deviceNumber)
{
    m_deviceNumber = deviceNumber;
}

Axis_Number Laser::getAxisNumber() const
{
    return m_axisNumber;
}

void Laser::setAxisNumber(const Axis_Number axisNumber)
{
    m_axisNumber = axisNumber;
}


void Laser::setDesiredPower(const float power)
{
    m_desiredPower = power;
    m_powerPending = true;
}

float Laser::getDesiredPower() const
{
    return m_desiredPower;
}

bool Laser::isPowerPending() const
{
    return m_powerPending;
}

void Laser::setCurrentPower(const float power)
{
    m_currentPower = power;
    m_powerPending = false;
}

float Laser::getCurrentPower() const
{
    return m_currentPower;
}

Message_Mode Laser::getDesiredMode() const
{
    return m_desiredMode;
}

void Laser::setDesiredMode(const Message_Mode m)
{
    m_desiredMode = m;
    m_modePending = true;
}

bool Laser::isModePending() const
{
    return m_modePending;
}

void Laser::setCurrentMode(const Message_Mode m)
{
    m_modePending = false;
    m_currentMode = m;
}

Message_Mode Laser::getCurrentMode() const
{
    return m_currentMode;
}

Message_Task Laser::getCurrentTask() const
{
    return m_currentTask;
}

void Laser::setCurrentTask(const Message_Task task)
{
    m_taskPending = false;
    m_currentTask = task;
}

Message_Task Laser::getDesiredTask() const
{
    return m_desiredTask;
}

void Laser::setDesiredTask(const Message_Task task)
{
    m_taskPending = true;
    m_desiredTask = task;
}

bool Laser::isTaskPending() const
{
    return m_taskPending;
}

Message_Status Laser::getCurrentStatus() const
{
    return m_currentStatus;
}

void Laser::setCurrentStatus(const Message_Status currentStatus)
{
    m_currentStatus = currentStatus;
}






////////////////////////////////////////// END Laser CLASS //////////////////////////////////////////


//////////////////////////////////// BEGIN SystemController CLASS ////////////////////////////////////

SystemController::SystemController(QObject *parent) : QObject(parent)
{

}
//SystemController::SystemController(machine_settings_t *settings, QObject *parent)
//    : QObject(parent)
//{
//    laser_model.setPortNumber(settings->l_settings.portNumber);
//    laser_model.setDeviceNumber((Device_Number)settings->l_settings.deviceNumber);
//    laser_model.setAxisNumber((Axis_Number)settings->l_settings.deviceNumber);

//    x_axis_model.setPortNumber(settings->x_settings.portNumber);
//    x_axis_model.setDeviceNumber((Device_Number)settings->x_settings.deviceNumber);
//    x_axis_model.setAxisNumber((Axis_Number)settings->x_settings.deviceNumber);

//    y_axis_model.setPortNumber(settings->y_settings.portNumber);
//    y_axis_model.setDeviceNumber((Device_Number)settings->y_settings.deviceNumber);
//    y_axis_model.setAxisNumber((Axis_Number)settings->y_settings.deviceNumber);

//    buildPlate_model.setPortNumber(settings->z_settings.portNumber);
//    buildPlate_model.setDeviceNumber((Device_Number)settings->z_settings.deviceNumber);
//    buildPlate_model.setAxisNumber((Axis_Number)settings->z_settings.deviceNumber);

//    hopperPlate_model.setPortNumber(settings->a_settings.portNumber);
//    hopperPlate_model.setDeviceNumber((Device_Number)settings->a_settings.deviceNumber);
//    hopperPlate_model.setAxisNumber((Axis_Number)settings->a_settings.deviceNumber);

//    spreadBlade_model.setPortNumber(settings->b_settings.portNumber);
//    spreadBlade_model.setDeviceNumber((Device_Number)settings->b_settings.deviceNumber);
//    spreadBlade_model.setAxisNumber((Axis_Number)settings->b_settings.deviceNumber);

//}



void SystemController::sendMessage(Message aMessage)
{
    if((aMessage.getTask() != Message_Task::NO_TASK)
            && (aMessage.getDeviceNumber() == Device_Number::LASER_GALVO))
    {
        const Message_Status currentTraffic = setModelToDesired(aMessage);
        if(currentTraffic != Message_Status::BUSY)
        {
            m_current_lg_command_str = aMessage.getCommandStr();
            emit LaserGalvoCommand_sig(m_current_lg_command_str);
        }
    }
    else if((aMessage.getTask() != Message_Task::NO_TASK)
            && ((aMessage.getDeviceNumber() == Device_Number::BUILD_PLATE)
                || (aMessage.getDeviceNumber() == Device_Number::HOP_SPRD)))
    {
        const Message_Status currentTraffic = setModelToDesired(aMessage);
        if(currentTraffic != Message_Status::BUSY)
        {
            m_current_md_command_str = aMessage.getCommandStr();
            emit MaterialDeliveryCommand_sig(m_current_md_command_str);
        }
    }
}


void SystemController::LaserGalvoReply_slot(Message lg_reply)
{
    m_current_lg_reply = lg_reply;
    const Message_Status replyStatus = updateModelWithReply(m_current_lg_reply);
//    if(replyStatus == Message_Status::REPLY_OK)
//        do something, tell somebody
//    else
//        int g = -3;// handle the error;
}

void SystemController::MaterialDeliveryReply_slot(Message md_reply)
{
    m_current_md_reply = md_reply;
    updateModelWithReply(m_current_md_reply);
}


Message_Status SystemController::setModelToDesired(Message aMessage)
{
    Message_Status myStatus = Message_Status::BUSY;
    if((aMessage.getAxisNumber() == Axis_Number::L)
            && laser_model.getCurrentStatus() == Message_Status::IDLE)
    {
        myStatus = Message_Status::REPLY_PENDING;
        laser_model.setDesiredMode(aMessage.getMode());
        laser_model.setDesiredTask(aMessage.getTask());
        if(aMessage.getTask() == Message_Task::ENABLE_AT_POWER)
            laser_model.setDesiredPower(aMessage.getPower());
        laser_model.setCurrentStatus(Message_Status::REPLY_PENDING);
    }
    else if((aMessage.getAxisNumber() == Axis_Number::X)
            && x_axis_model.getCurrentStatus() == Message_Status::IDLE)
    {
        myStatus = Message_Status::REPLY_PENDING;
        x_axis_model.setDesiredMode(aMessage.getMode());
        x_axis_model.setDesiredTask(aMessage.getTask());
        if(aMessage.getTask() == Message_Task::MOVE_ABS)
            x_axis_model.setDesiredPosition(aMessage.getPosition_mm());
        else if(aMessage.getTask() == Message_Task::MOVE_ABS_AT_SPEED)
        {
            x_axis_model.setDesiredPosition(aMessage.getPosition_mm());
            x_axis_model.setDesiredSpeed(aMessage.getSpeed());
        }
        else if(aMessage.getTask() == Message_Task::MOVE_REL_AT_SPEED)
        {
            x_axis_model.setDesiredPosition(x_axis_model.getCurrentPosition() + aMessage.getPosition_mm());
            x_axis_model.setDesiredSpeed(aMessage.getSpeed());
        }
        else if(aMessage.getTask() == Message_Task::MOVE_REL)
        {
            x_axis_model.setDesiredPosition(x_axis_model.getCurrentPosition() + aMessage.getPosition_mm());
        }

        x_axis_model.setCurrentStatus(Message_Status::REPLY_PENDING);

    }
    else if((aMessage.getAxisNumber() == Axis_Number::Y)
            && (y_axis_model.getCurrentStatus() == Message_Status::IDLE))
    {
        myStatus = Message_Status::REPLY_PENDING;
        y_axis_model.setDesiredMode(aMessage.getMode());
        y_axis_model.setDesiredTask(aMessage.getTask());
        if(aMessage.getTask() == Message_Task::MOVE_ABS)
            y_axis_model.setDesiredPosition(aMessage.getPosition_mm());
        else if(aMessage.getTask() == Message_Task::MOVE_ABS_AT_SPEED)
        {
            y_axis_model.setDesiredPosition(aMessage.getPosition_mm());
            y_axis_model.setDesiredSpeed(aMessage.getSpeed());
        }
        else if(aMessage.getTask() == Message_Task::MOVE_REL_AT_SPEED)
        {
            y_axis_model.setDesiredPosition(y_axis_model.getCurrentPosition() + aMessage.getPosition_mm());
            y_axis_model.setDesiredSpeed(aMessage.getSpeed());
        }
        else if(aMessage.getTask() == Message_Task::MOVE_REL)
        {
            y_axis_model.setDesiredPosition(y_axis_model.getCurrentPosition() + aMessage.getPosition_mm());
        }

        y_axis_model.setCurrentStatus(Message_Status::REPLY_PENDING);

    }
    else if((aMessage.getAxisNumber() == Axis_Number::Z)
            && (buildPlate_model.getCurrentStatus() == Message_Status::IDLE))
    {
        myStatus = Message_Status::REPLY_PENDING;
        buildPlate_model.setDesiredMode(aMessage.getMode());
        buildPlate_model.setDesiredTask(aMessage.getTask());
        if(aMessage.getTask() == Message_Task::MOVE_ABS)
            buildPlate_model.setDesiredPosition(aMessage.getPosition_mm());
        else if(aMessage.getTask() == Message_Task::MOVE_ABS_AT_SPEED)
        {
            buildPlate_model.setDesiredPosition(aMessage.getPosition_mm());
            buildPlate_model.setDesiredSpeed(aMessage.getSpeed());
        }
        else if(aMessage.getTask() == Message_Task::MOVE_REL_AT_SPEED)
        {
            buildPlate_model.setDesiredPosition(buildPlate_model.getCurrentPosition() + aMessage.getPosition_mm());
            buildPlate_model.setDesiredSpeed(aMessage.getSpeed());
        }
        else if(aMessage.getTask() == Message_Task::MOVE_REL)
        {
            buildPlate_model.setDesiredPosition(buildPlate_model.getCurrentPosition() + aMessage.getPosition_mm());
        }

        buildPlate_model.setCurrentStatus(Message_Status::REPLY_PENDING);

    }
    else if((aMessage.getAxisNumber() == Axis_Number::A)
            && (hopperPlate_model.getCurrentStatus() == Message_Status::IDLE))
    {
        myStatus = Message_Status::REPLY_PENDING;
        hopperPlate_model.setDesiredMode(aMessage.getMode());
        hopperPlate_model.setDesiredTask(aMessage.getTask());
        if(aMessage.getTask() == Message_Task::MOVE_ABS)
            hopperPlate_model.setDesiredPosition(aMessage.getPosition_mm());
        else if(aMessage.getTask() == Message_Task::MOVE_ABS_AT_SPEED)
        {
            hopperPlate_model.setDesiredPosition(aMessage.getPosition_mm());
            hopperPlate_model.setDesiredSpeed(aMessage.getSpeed());
        }
        else if(aMessage.getTask() == Message_Task::MOVE_REL_AT_SPEED)
        {
            hopperPlate_model.setDesiredPosition(hopperPlate_model.getCurrentPosition() + aMessage.getPosition_mm());
            hopperPlate_model.setDesiredSpeed(aMessage.getSpeed());
        }
        else if(aMessage.getTask() == Message_Task::MOVE_REL)
        {
            hopperPlate_model.setDesiredPosition(hopperPlate_model.getCurrentPosition() + aMessage.getPosition_mm());
        }

        hopperPlate_model.setCurrentStatus(Message_Status::REPLY_PENDING);

    }
    else if((aMessage.getAxisNumber() == Axis_Number::B)
            && (spreadBlade_model.getCurrentStatus() == Message_Status::IDLE))
    {
        myStatus = Message_Status::REPLY_PENDING;
        spreadBlade_model.setDesiredMode(aMessage.getMode());
        spreadBlade_model.setDesiredTask(aMessage.getTask());
        if(aMessage.getTask() == Message_Task::MOVE_ABS)
            spreadBlade_model.setDesiredPosition(aMessage.getPosition_mm());
        else if(aMessage.getTask() == Message_Task::MOVE_ABS_AT_SPEED)
        {
            spreadBlade_model.setDesiredPosition(aMessage.getPosition_mm());
            spreadBlade_model.setDesiredSpeed(aMessage.getSpeed());
        }
        else if(aMessage.getTask() == Message_Task::MOVE_REL_AT_SPEED)
        {
            spreadBlade_model.setDesiredPosition(spreadBlade_model.getCurrentPosition() + aMessage.getPosition_mm());
            spreadBlade_model.setDesiredSpeed(aMessage.getSpeed());
        }
        else if(aMessage.getTask() == Message_Task::MOVE_REL)
        {
            spreadBlade_model.setDesiredPosition(spreadBlade_model.getCurrentPosition() + aMessage.getPosition_mm());
        }

        spreadBlade_model.setCurrentStatus(Message_Status::REPLY_PENDING);
    }
    return myStatus;
}


Message_Status SystemController::updateModelWithReply(Message aMessage)
{
    Message_Status myStatus = Message_Status::REPLY_FAILED;
    if((aMessage.getReplyFlag() == Message_Reply_Flag::OK))
    {
        if((aMessage.getAxisNumber() == Axis_Number::L)
                &&(laser_model.getCurrentStatus() == Message_Status::REPLY_PENDING))
        {
            myStatus = Message_Status::REPLY_OK;

            laser_model.setCurrentStatus(aMessage.getStatus());
            if(aMessage.getStatus() == Message_Status::IDLE)
            {
                if(laser_model.isModePending())
                    laser_model.setCurrentMode(laser_model.getDesiredMode());

                if(laser_model.isTaskPending())
                    laser_model.setCurrentTask(Message_Task::TASK_COMPLETE);

                if(laser_model.isModePending())
                    laser_model.setCurrentPower(laser_model.getDesiredPower());
            }
        }

        else if(aMessage.getAxisNumber() == Axis_Number::X)
        {

            x_axis_model.setCurrentStatus(aMessage.getStatus());

            if((aMessage.getStatus() == Message_Status::IDLE)
                    &&(x_axis_model.getCurrentStatus() == Message_Status::REPLY_PENDING))
            {
                myStatus = Message_Status::REPLY_OK;

                if(x_axis_model.isModePending())
                    x_axis_model.setCurrentMode(x_axis_model.getDesiredMode());

                if(x_axis_model.isPositionPending())
                    x_axis_model.setCurrentPosition(x_axis_model.getDesiredPosition());

                if(x_axis_model.isSpeedPending())
                    x_axis_model.setCurrentSpeed(x_axis_model.getDesiredSpeed());

                if(x_axis_model.isTaskPending())
                {
                    if(x_axis_model.getDesiredTask() == Message_Task::GO_HOME)
                        x_axis_model.setHomed(true);

                    x_axis_model.setCurrentTask(Message_Task::TASK_COMPLETE);
                }
            }
        }

        else if(aMessage.getAxisNumber() == Axis_Number::Y)
        {
            y_axis_model.setCurrentStatus(aMessage.getStatus());

            if((aMessage.getStatus() == Message_Status::IDLE)
                    &&(y_axis_model.getCurrentStatus() == Message_Status::REPLY_PENDING))
            {

                myStatus = Message_Status::REPLY_OK;

                if(y_axis_model.isModePending())
                    y_axis_model.setCurrentMode(y_axis_model.getDesiredMode());

                if(y_axis_model.isPositionPending())
                    y_axis_model.setCurrentPosition(y_axis_model.getDesiredPosition());

                if(y_axis_model.isSpeedPending())
                    y_axis_model.setCurrentSpeed(y_axis_model.getDesiredSpeed());

                if(y_axis_model.isTaskPending())
                {
                    if(y_axis_model.getDesiredTask() == Message_Task::GO_HOME)
                        y_axis_model.setHomed(true);

                    y_axis_model.setCurrentTask(Message_Task::TASK_COMPLETE);
                }
            }
        }

        else if(aMessage.getAxisNumber() == Axis_Number::Z)
        {
            buildPlate_model.setCurrentStatus(aMessage.getStatus());

            if((aMessage.getStatus() == Message_Status::IDLE)
                    &&(buildPlate_model.getCurrentStatus() == Message_Status::REPLY_PENDING))
            {
                myStatus = Message_Status::REPLY_OK;

                if(buildPlate_model.isModePending())
                    buildPlate_model.setCurrentMode(buildPlate_model.getDesiredMode());

                if(buildPlate_model.isPositionPending())
                    buildPlate_model.setCurrentPosition(buildPlate_model.getDesiredPosition());

                if(buildPlate_model.isSpeedPending())
                    buildPlate_model.setCurrentSpeed(buildPlate_model.getDesiredSpeed());

                if(buildPlate_model.isTaskPending())
                {
                    if(buildPlate_model.getDesiredTask() == Message_Task::GO_HOME)
                        buildPlate_model.setHomed(true);

                    buildPlate_model.setCurrentTask(Message_Task::TASK_COMPLETE);
                }
            }

        }

        else if(aMessage.getAxisNumber() == Axis_Number::A)
        {
            hopperPlate_model.setCurrentStatus(aMessage.getStatus());

            if((aMessage.getStatus() == Message_Status::IDLE)
                    &&(hopperPlate_model.getCurrentStatus() == Message_Status::REPLY_PENDING))

            {
                myStatus = Message_Status::REPLY_OK;

                if(hopperPlate_model.isModePending())
                    hopperPlate_model.setCurrentMode(hopperPlate_model.getDesiredMode());

                if(hopperPlate_model.isPositionPending())
                    hopperPlate_model.setCurrentPosition(hopperPlate_model.getDesiredPosition());

                if(hopperPlate_model.isSpeedPending())
                    hopperPlate_model.setCurrentSpeed(hopperPlate_model.getDesiredSpeed());

                if(hopperPlate_model.isTaskPending())
                {
                    if(hopperPlate_model.getDesiredTask() == Message_Task::GO_HOME)
                        hopperPlate_model.setHomed(true);

                    hopperPlate_model.setCurrentTask(Message_Task::TASK_COMPLETE);
                }
            }
        }
        else if(aMessage.getAxisNumber() == Axis_Number::B)
        {
            spreadBlade_model.setCurrentStatus(aMessage.getStatus());

            if((aMessage.getStatus() == Message_Status::IDLE)
                    &&(spreadBlade_model.getCurrentStatus() == Message_Status::REPLY_PENDING))
            {
                myStatus = Message_Status::REPLY_OK;

                if(spreadBlade_model.isModePending())
                    spreadBlade_model.setCurrentMode(spreadBlade_model.getDesiredMode());

                if(spreadBlade_model.isPositionPending())
                    spreadBlade_model.setCurrentPosition(spreadBlade_model.getDesiredPosition());

                if(spreadBlade_model.isSpeedPending())
                    spreadBlade_model.setCurrentSpeed(spreadBlade_model.getDesiredSpeed());

                if(spreadBlade_model.isTaskPending())
                {
                    if(spreadBlade_model.getDesiredTask() == Message_Task::GO_HOME)
                        spreadBlade_model.setHomed(true);

                    spreadBlade_model.setCurrentTask(Message_Task::TASK_COMPLETE);
                }
            }
        }
    }
    return myStatus;
}




void SystemController::simpleReceive(QString s)
{
    m_myString = s;
}

void SystemController::sendString(const QString &aString)
{
    emit simpleSend(aString);
}

QString SystemController::getMyString() const
{
    return m_myString;
}



//////////////////////////////////// END SystemController CLASS ////////////////////////////////////
































