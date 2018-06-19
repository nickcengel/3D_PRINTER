#include "devicemodels.h"
#include "blockio.h"
#include <QObject>
using BlockIO::AxisTitle;
using BlockIO::Tasks;
using BlockIO::Message;

////////////////////////////////////////// BEGIN Axis CLASS //////////////////////////////////////////
Axis::Axis()
{
    m_portNumber = -1;
    m_deviceNumber = -1;
    m_homePending = false;
    m_homed = false;
    m_positionPending = false;
    m_speedPending = false;
}

Axis::Axis(int portNumber, int deviceNumber, BlockIO::AxisTitle axisTitle)
{
    m_portNumber = portNumber;
    m_deviceNumber = deviceNumber;
    m_axisTitle = axisTitle;
    m_homePending = false;
    m_homed = false;
    m_positionPending = false;
    m_speedPending = false;
}

int Axis::portNumber() const
{
    return m_portNumber;
}

void Axis::setPortNumber(int portNumber)
{
    m_portNumber = portNumber;
}

int Axis::deviceNumber() const
{
    return m_deviceNumber;
}

void Axis::setDeviceNumber(int deviceNumber)
{
    m_deviceNumber = deviceNumber;
}

void Axis::requestHome()
{
    m_homePending = true;
}

bool Axis::isHomePending() const
{
    return m_homePending;
}

void Axis::setHomed(bool isHomed)
{
    m_homed = isHomed;
    m_homePending = false;
}

bool Axis::isHomed() const
{
   return m_homed;
}

void Axis::setDesiredPosition(float desiredPosition)
{
    m_desiredPosition = desiredPosition;
    m_positionPending = true;
}

float Axis::desiredPosition() const
{
    return m_desiredPosition;
}

bool Axis::isPositionPending() const
{
    return m_positionPending;
}

void Axis::setCurrentPosition(float currentPosition)
{
        m_currentPosition = currentPosition;
        m_positionPending = false;
}

float Axis::currentPosition() const
{
    return m_currentPosition;
}

void Axis::setDesiredSpeed(float desiredSpeed)
{
    m_desiredSpeed = desiredSpeed;
    m_speedPending = true;
}

float Axis::desiredSpeed() const
{
    return m_desiredSpeed;
}

bool Axis::isSpeedPending() const
{
    return m_speedPending;
}

void Axis::setCurrentSpeed(float currentSpeed)
{
        m_currentSpeed = currentSpeed;
        m_speedPending = false;
}

float Axis::currentSpeed() const
{
    return m_currentSpeed;
}

void Axis::addMessage(BlockIO::Message aMessage)
{
    m_axisTask = aMessage.task();
    switch (m_axisTask) {
    case Tasks::NONE:
        break;
    case Tasks::POSITION:
        setDesiredPosition(aMessage.D0());
        break;
    case Tasks::POSITION_SPEED:
        setDesiredPosition(aMessage.D0());
        setDesiredSpeed(aMessage.D1());
        break;
    case Tasks::HOME:
        requestHome();
        break;
    case Tasks::ABSOLUTE:
        setDesiredMode(Tasks::ABSOLUTE);
        break;
    case Tasks::RELATIVE:
        setDesiredMode(Tasks::RELATIVE);
        break;
    case Tasks::ENABLE:
        setDesiredMode(Tasks::ENABLE);
        break;
    case Tasks::DISABLE:
        setDesiredMode(Tasks::DISABLE);
        break;
    default:
        break;
    }
}

BlockIO::Tasks Axis::desiredMode() const
{
    return m_desiredMode;
}

void Axis::clearPending()
{
    if(isModePending())
        setCurrentMode(desiredMode());
     if(isPositionPending())
         setCurrentPosition(desiredPosition());
     if(isSpeedPending())
         setCurrentSpeed(desiredSpeed());
     setAxisTask(Tasks::NONE);
}

Tasks Axis::axisTask() const
{
    return m_axisTask;
}

void Axis::setAxisTask(const BlockIO::Tasks axisTask)
{
    m_axisTask = axisTask;
}

void Axis::setDesiredMode(Tasks m)
{
    m_desiredMode = m;
    m_modePending = true;
}

bool Axis::isModePending() const
{
    return m_modePending;
}

void Axis::setCurrentMode(Tasks m)
{
    m_modePending = false;
    m_currentMode = m;
}

AxisTitle Axis::axisTitle() const
{
    return m_axisTitle;
}

void Axis::setAxisTitle(const AxisTitle &axisTitle)
{
    m_axisTitle = axisTitle;
}
////////////////////////////////////////// END Axis CLASS //////////////////////////////////////////



////////////////////////////////////////// BEGIN Laser CLASS //////////////////////////////////////////

Laser::Laser()
{
    m_modePending = false;
    m_currentMode = Tasks::DISABLE;
    m_currentPower = 0;
    m_powerPending = false;
}

void Laser::setDesiredPower(const float power)
{
    m_powerPending = true;
    m_desiredPower = power;
}

float Laser::desiredPower() const
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

float Laser::currentPower() const
{
    return m_currentPower;
}

int Laser::getPortNumber() const
{
    return portNumber;
}

void Laser::setPortNumber(int value)
{
    portNumber = value;
}

int Laser::getDeviceNumber() const
{
    return deviceNumber;
}

void Laser::setDeviceNumber(int value)
{
    deviceNumber = value;
}

void Laser::addMessage(BlockIO::Message aMessage)
{
    setLaserTask(aMessage.task());
    switch (m_laserTask) {
    case Tasks::NONE:
        break;
    case Tasks::ENABLE:
            setDesiredMode(Tasks::ENABLE);
        break;
    case Tasks::DISABLE:
            setDesiredMode(Tasks::DISABLE);
        break;
    case Tasks::ENABLE_POWER:
            setDesiredMode(Tasks::ENABLE_POWER);
            setDesiredPower(aMessage.D1());
        break;
    case Tasks::POWER:
        setDesiredPower(aMessage.D1());
        break;
    default:
        break;
    }
}

void Laser::clearPending()
{
   if(isModePending())
       setCurrentMode(desiredMode());
    if(isPowerPending())
        setCurrentPower(desiredPower());
    setLaserTask(Tasks::NONE);
}

Tasks Laser::laserTask() const
{
    return m_laserTask;
}

void Laser::setLaserTask(const Tasks laserTask)
{
    m_laserTask = laserTask;
}

void Laser::setDesiredMode(Tasks m)
{
    m_desiredMode = m;
    m_modePending = true;
}

BlockIO::Tasks Laser::desiredMode() const
{
    return m_desiredMode;
}

bool Laser::isModePending() const
{
    return m_modePending;
}

void Laser::setCurrentMode(Tasks m)
{
    m_modePending = false;
    m_currentMode = m;
}

////////////////////////////////////////// END Laser CLASS //////////////////////////////////////////


//////////////////////////////////// BEGIN SystemController CLASS ////////////////////////////////////


SystemController::SystemController(QObject *parent) : QObject(parent)
{
    laserGalvoMap = LG_Map::LG_NONE;
    materialDeliveryMap = MD_Map::MD_NONE;
}

void SystemController::updateLaserGalvo_model(BlockIO::LG_Package laserGalvoMessage)
{
    laserGalvoMap = laserGalvoMessage.getMap();
    switch (laserGalvoMap) {
    case LG_Map::LG_NONE:
        break;
    case LG_Map::X_ONLY:
        x_axis_model.addMessage(*laserGalvoMessage.x_message());
        break;
    case LG_Map::Y_ONLY:
        y_axis_model.addMessage(*laserGalvoMessage.y_message());
        break;
    case LG_Map::X_Y:
        x_axis_model.addMessage(*laserGalvoMessage.x_message());
        y_axis_model.addMessage(*laserGalvoMessage.y_message());
        break;
    case LG_Map::LG_ALL:
        x_axis_model.addMessage(*laserGalvoMessage.x_message());
        y_axis_model.addMessage(*laserGalvoMessage.y_message());
        laser_model.addMessage(*laserGalvoMessage.laser_message());
        break;
    case LG_Map::X_LASER:
        x_axis_model.addMessage(*laserGalvoMessage.x_message());
        laser_model.addMessage(*laserGalvoMessage.laser_message());
        break;
    case LG_Map::Y_LASER:
        y_axis_model.addMessage(*laserGalvoMessage.y_message());
        laser_model.addMessage(*laserGalvoMessage.laser_message());
        break;
    default:
        break;
    }
}

void SystemController::updateMaterialDelivery_model(BlockIO::MD_Package MaterialDeliveryMessage)
{
    switch (MaterialDeliveryMessage.getMap())
    {
    case MD_Map::MD_NONE:
        break;
    case MD_Map::BUILD_PLATE:
        buildPlate_model.addMessage(*MaterialDeliveryMessage.buildPlate_message());
        break;
    case MD_Map::HOPPPER_PLATE:
        hopperPlate_model.addMessage(*MaterialDeliveryMessage.hopperPlate_message());
        break;
    case MD_Map::SPREAD_BLADE:
        spreadBlade_model.addMessage(*MaterialDeliveryMessage.spreadBlade_message());
        break;
    case MD_Map::BUILD_HOPPER:
        buildPlate_model.addMessage(*MaterialDeliveryMessage.buildPlate_message());
        hopperPlate_model.addMessage(*MaterialDeliveryMessage.hopperPlate_message());
        break;
    case MD_Map::BUILD_SPREAD:
        buildPlate_model.addMessage(*MaterialDeliveryMessage.buildPlate_message());
        spreadBlade_model.addMessage(*MaterialDeliveryMessage.spreadBlade_message());
        break;
    case MD_Map::HOPPER_SPREAD:
        hopperPlate_model.addMessage(*MaterialDeliveryMessage.hopperPlate_message());
        spreadBlade_model.addMessage(*MaterialDeliveryMessage.spreadBlade_message());
        break;
    case MD_Map::MD_ALL:
        buildPlate_model.addMessage(*MaterialDeliveryMessage.buildPlate_message());
        hopperPlate_model.addMessage(*MaterialDeliveryMessage.hopperPlate_message());
        spreadBlade_model.addMessage(*MaterialDeliveryMessage.spreadBlade_message());
        break;
    default:
        break;
    }
}

void SystemController::sendBlock(BlockIO::Block block)
{
    if((laserGalvoMap == LG_Map::LG_NONE) && (block.laserGalvo()->getMap() != LG_Map::LG_NONE))
    {
        updateLaserGalvo_model(*block.laserGalvo());
        emit laserGalvoSignal(*block.laserGalvo());
    }
    if((materialDeliveryMap == MD_Map::MD_NONE) && (block.materialDelivery()->getMap() != MD_Map::MD_NONE))
    {
        updateMaterialDelivery_model(*block.materialDelivery());
        emit MaterialDeliverySignal(*block.materialDelivery());
    }
}

void SystemController::laserGalvoReply(BlockIO::LG_Map reply)
{
    switch (reply) {
    case LG_Map::X_ONLY:
        x_axis_model.clearPending();
        laserGalvoMap = LG_Map::LG_NONE;
        break;
    case LG_Map::Y_ONLY:
        y_axis_model.clearPending();
        laserGalvoMap = LG_Map::LG_NONE;
        break;
    case LG_Map::X_Y:
        x_axis_model.clearPending();
        y_axis_model.clearPending();
        laserGalvoMap = LG_Map::LG_NONE;
        break;
    case LG_Map::LASER_ONLY:
        laser_model.clearPending();
        laserGalvoMap = LG_Map::LG_NONE;
        break;
    case LG_Map::X_LASER:
        x_axis_model.clearPending();
        laser_model.clearPending();
        laserGalvoMap = LG_Map::LG_NONE;
        break;
    case LG_Map::Y_LASER:
        y_axis_model.clearPending();
        laser_model.clearPending();
        laserGalvoMap = LG_Map::LG_NONE;
        break;
    case LG_Map::LG_ALL:
        x_axis_model.clearPending();
        y_axis_model.clearPending();
        laser_model.clearPending();
        laserGalvoMap = LG_Map::LG_NONE;
        break;
    case LG_Map::LG_FAILED:
        laserGalvoMap = LG_Map::LG_FAILED;
        //handle error
        break;
    default:
        break;
    }
}

void SystemController::MaterialDeliveryReply(BlockIO::MD_Map reply)
{
    switch (reply) {
    case MD_Map::BUILD_PLATE:
        buildPlate_model.clearPending();
        materialDeliveryMap = MD_Map::MD_NONE;
        break;
    case MD_Map::HOPPPER_PLATE:
        hopperPlate_model.clearPending();
        materialDeliveryMap = MD_Map::MD_NONE;
        break;
    case MD_Map::SPREAD_BLADE:
        spreadBlade_model.clearPending();
        materialDeliveryMap = MD_Map::MD_NONE;
        break;
    case MD_Map::BUILD_HOPPER:
        buildPlate_model.clearPending();
        hopperPlate_model.clearPending();
        materialDeliveryMap = MD_Map::MD_NONE;
        break;
    case MD_Map::BUILD_SPREAD:
        buildPlate_model.clearPending();
        spreadBlade_model.clearPending();
        materialDeliveryMap = MD_Map::MD_NONE;
        break;
    case MD_Map::HOPPER_SPREAD:
        hopperPlate_model.clearPending();
        spreadBlade_model.clearPending();
        materialDeliveryMap = MD_Map::MD_NONE;
        break;
    case MD_Map::MD_ALL:
        buildPlate_model.clearPending();
        hopperPlate_model.clearPending();
        spreadBlade_model.clearPending();
        materialDeliveryMap = MD_Map::MD_NONE;
        break;
    case MD_Map::MD_FAILED:
        materialDeliveryMap = MD_Map::MD_FAILED;
        //handle errors
        break;
    default:
        break;
    }
}

//////////////////////////////////// END SystemController CLASS ////////////////////////////////////



