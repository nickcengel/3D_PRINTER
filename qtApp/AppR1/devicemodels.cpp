#include "devicemodels.h"
#include "blockio.h"
#include <QObject>
using BlockIO::AxisNumber;
using BlockIO::Message_Task;
using BlockIO::Message_Mode;
using BlockIO::Message;
using BlockIO::Block;


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
}

Axis::Axis(int portNumber, BlockIO::DeviceNumber deviceNumber, BlockIO::AxisNumber axisNumber)
{
    m_portNumber = portNumber;
    m_deviceNumber = deviceNumber;
    m_axisNumber = axisNumber;
    m_modePending = false;
    m_taskPending = false;
    m_homed = false;
    m_positionPending = false;
    m_speedPending = false;
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

void Axis::setDeviceNumber(const BlockIO::DeviceNumber deviceNumber)
{
    m_deviceNumber = deviceNumber;
}

BlockIO::AxisNumber Axis::getAxisNumber() const
{
    return m_axisNumber;
}

void Axis::setAxisNumber(const BlockIO::AxisNumber axisNumber)
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



BlockIO::Message_Mode Axis::getDesiredMode() const
{
    return m_desiredMode;
}

void Axis::setDesiredMode(const BlockIO::Message_Mode m)
{
    m_desiredMode = m;
    m_modePending = true;
}

bool Axis::isModePending() const
{
    return m_modePending;
}

void Axis::setCurrentMode(const BlockIO::Message_Mode m)
{
    m_modePending = false;
    m_currentMode = m;
}

BlockIO::Message_Mode Axis::getCurrentMode() const
{
    return m_currentMode;
}

Message_Task Axis::getCurrentTask() const
{
    return m_currentTask;
}

void Axis::setCurrentTask(const BlockIO::Message_Task task)
{
    m_taskPending = false;
    m_currentTask = task;
}

Message_Task Axis::getDesiredTask() const
{
    return m_desiredTask;
}

void Axis::setDesiredTask(const BlockIO::Message_Task task)
{
    m_taskPending = true;
    m_desiredTask = task;
}

bool Axis::isTaskPending() const
{
    return m_taskPending;
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
}

Laser::Laser(int portNumber, BlockIO::DeviceNumber deviceNumber, BlockIO::AxisNumber axisNumber)
{
    m_portNumber = portNumber;
    m_deviceNumber = deviceNumber;
    m_axisNumber = axisNumber;
    m_modePending = false;
    m_taskPending = false;
    m_powerPending = false;
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

void Laser::setDeviceNumber(const BlockIO::DeviceNumber deviceNumber)
{
    m_deviceNumber = deviceNumber;
}

BlockIO::AxisNumber Laser::getAxisNumber() const
{
    return m_axisNumber;
}

void Laser::setAxisNumber(const BlockIO::AxisNumber axisNumber)
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

BlockIO::Message_Mode Laser::getDesiredMode() const
{
    return m_desiredMode;
}

void Laser::setDesiredMode(const BlockIO::Message_Mode m)
{
    m_desiredMode = m;
    m_modePending = true;
}

bool Laser::isModePending() const
{
    return m_modePending;
}

void Laser::setCurrentMode(const BlockIO::Message_Mode m)
{
    m_modePending = false;
    m_currentMode = m;
}

BlockIO::Message_Mode Laser::getCurrentMode() const
{
    return m_currentMode;
}

Message_Task Laser::getCurrentTask() const
{
    return m_currentTask;
}

void Laser::setCurrentTask(const BlockIO::Message_Task task)
{
    m_taskPending = false;
    m_currentTask = task;
}

Message_Task Laser::getDesiredTask() const
{
    return m_desiredTask;
}

void Laser::setDesiredTask(const BlockIO::Message_Task task)
{
    m_taskPending = true;
    m_desiredTask = task;
}

bool Laser::isTaskPending() const
{
    return m_taskPending;
}






////////////////////////////////////////// END Laser CLASS //////////////////////////////////////////


//////////////////////////////////// BEGIN SystemController CLASS ////////////////////////////////////


//SystemController::SystemController(QObject *parent) : QObject(parent)
//{
//    laserGalvoMap = LG_Map::LG_NONE;
//    materialDeliveryMap = MD_Map::MD_NONE;
//}

//void SystemController::updateLaserGalvo_model(BlockIO::LG_Package laserGalvoMessage)
//{
//    laserGalvoMap = laserGalvoMessage.getMap();
//    switch (laserGalvoMap) {
//    case LG_Map::LG_NONE:
//        break;
//    case LG_Map::X_ONLY:
//        x_axis_model.addMessage(*laserGalvoMessage.x_message());
//        break;
//    case LG_Map::Y_ONLY:
//        y_axis_model.addMessage(*laserGalvoMessage.y_message());
//        break;
//    case LG_Map::X_Y:
//        x_axis_model.addMessage(*laserGalvoMessage.x_message());
//        y_axis_model.addMessage(*laserGalvoMessage.y_message());
//        break;
//    case LG_Map::LG_ALL:
//        x_axis_model.addMessage(*laserGalvoMessage.x_message());
//        y_axis_model.addMessage(*laserGalvoMessage.y_message());
//        laser_model.addMessage(*laserGalvoMessage.laser_message());
//        break;
//    case LG_Map::X_LASER:
//        x_axis_model.addMessage(*laserGalvoMessage.x_message());
//        laser_model.addMessage(*laserGalvoMessage.laser_message());
//        break;
//    case LG_Map::Y_LASER:
//        y_axis_model.addMessage(*laserGalvoMessage.y_message());
//        laser_model.addMessage(*laserGalvoMessage.laser_message());
//        break;
//    default:
//        break;
//    }
//}

//void SystemController::updateMaterialDelivery_model(BlockIO::MD_Package MaterialDeliveryMessage)
//{
//    switch (MaterialDeliveryMessage.getMap())
//    {
//    case MD_Map::MD_NONE:
//        break;
//    case MD_Map::BUILD_PLATE:
//        buildPlate_model.addMessage(*MaterialDeliveryMessage.buildPlate_message());
//        break;
//    case MD_Map::HOPPPER_PLATE:
//        hopperPlate_model.addMessage(*MaterialDeliveryMessage.hopperPlate_message());
//        break;
//    case MD_Map::SPREAD_BLADE:
//        spreadBlade_model.addMessage(*MaterialDeliveryMessage.spreadBlade_message());
//        break;
//    case MD_Map::BUILD_HOPPER:
//        buildPlate_model.addMessage(*MaterialDeliveryMessage.buildPlate_message());
//        hopperPlate_model.addMessage(*MaterialDeliveryMessage.hopperPlate_message());
//        break;
//    case MD_Map::BUILD_SPREAD:
//        buildPlate_model.addMessage(*MaterialDeliveryMessage.buildPlate_message());
//        spreadBlade_model.addMessage(*MaterialDeliveryMessage.spreadBlade_message());
//        break;
//    case MD_Map::HOPPER_SPREAD:
//        hopperPlate_model.addMessage(*MaterialDeliveryMessage.hopperPlate_message());
//        spreadBlade_model.addMessage(*MaterialDeliveryMessage.spreadBlade_message());
//        break;
//    case MD_Map::MD_ALL:
//        buildPlate_model.addMessage(*MaterialDeliveryMessage.buildPlate_message());
//        hopperPlate_model.addMessage(*MaterialDeliveryMessage.hopperPlate_message());
//        spreadBlade_model.addMessage(*MaterialDeliveryMessage.spreadBlade_message());
//        break;
//    default:
//        break;
//    }
//}

//void SystemController::sendBlock(BlockIO::Block block)
//{
//    if((laserGalvoMap == LG_Map::LG_NONE) && (block.laserGalvo()->getMap() != LG_Map::LG_NONE))
//    {
//        updateLaserGalvo_model(*block.laserGalvo());
//        emit laserGalvoSignal(*block.laserGalvo());
//    }
//    if((materialDeliveryMap == MD_Map::MD_NONE) && (block.materialDelivery()->getMap() != MD_Map::MD_NONE))
//    {
//        updateMaterialDelivery_model(*block.materialDelivery());
//        emit MaterialDeliverySignal(*block.materialDelivery());
//    }
//}

//void SystemController::laserGalvoReply(BlockIO::LG_Map reply)
//{
//    switch (reply) {
//    case LG_Map::X_ONLY:
//        x_axis_model.clearPending();
//        laserGalvoMap = LG_Map::LG_NONE;
//        break;
//    case LG_Map::Y_ONLY:
//        y_axis_model.clearPending();
//        laserGalvoMap = LG_Map::LG_NONE;
//        break;
//    case LG_Map::X_Y:
//        x_axis_model.clearPending();
//        y_axis_model.clearPending();
//        laserGalvoMap = LG_Map::LG_NONE;
//        break;
//    case LG_Map::LASER_ONLY:
//        laser_model.clearPending();
//        laserGalvoMap = LG_Map::LG_NONE;
//        break;
//    case LG_Map::X_LASER:
//        x_axis_model.clearPending();
//        laser_model.clearPending();
//        laserGalvoMap = LG_Map::LG_NONE;
//        break;
//    case LG_Map::Y_LASER:
//        y_axis_model.clearPending();
//        laser_model.clearPending();
//        laserGalvoMap = LG_Map::LG_NONE;
//        break;
//    case LG_Map::LG_ALL:
//        x_axis_model.clearPending();
//        y_axis_model.clearPending();
//        laser_model.clearPending();
//        laserGalvoMap = LG_Map::LG_NONE;
//        break;
//    case LG_Map::LG_FAILED:
//        laserGalvoMap = LG_Map::LG_FAILED;
//        //handle error
//        break;
//    default:
//        break;
//    }
//}

//void SystemController::MaterialDeliveryReply(BlockIO::MD_Map reply)
//{
//    switch (reply) {
//    case MD_Map::BUILD_PLATE:
//        buildPlate_model.clearPending();
//        materialDeliveryMap = MD_Map::MD_NONE;
//        break;
//    case MD_Map::HOPPPER_PLATE:
//        hopperPlate_model.clearPending();
//        materialDeliveryMap = MD_Map::MD_NONE;
//        break;
//    case MD_Map::SPREAD_BLADE:
//        spreadBlade_model.clearPending();
//        materialDeliveryMap = MD_Map::MD_NONE;
//        break;
//    case MD_Map::BUILD_HOPPER:
//        buildPlate_model.clearPending();
//        hopperPlate_model.clearPending();
//        materialDeliveryMap = MD_Map::MD_NONE;
//        break;
//    case MD_Map::BUILD_SPREAD:
//        buildPlate_model.clearPending();
//        spreadBlade_model.clearPending();
//        materialDeliveryMap = MD_Map::MD_NONE;
//        break;
//    case MD_Map::HOPPER_SPREAD:
//        hopperPlate_model.clearPending();
//        spreadBlade_model.clearPending();
//        materialDeliveryMap = MD_Map::MD_NONE;
//        break;
//    case MD_Map::MD_ALL:
//        buildPlate_model.clearPending();
//        hopperPlate_model.clearPending();
//        spreadBlade_model.clearPending();
//        materialDeliveryMap = MD_Map::MD_NONE;
//        break;
//    case MD_Map::MD_FAILED:
//        materialDeliveryMap = MD_Map::MD_FAILED;
//        //handle errors
//        break;
//    default:
//        break;
//    }
//}

//////////////////////////////////// END SystemController CLASS ////////////////////////////////////





