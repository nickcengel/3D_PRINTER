#include "settingsobject.h"

SettingsObject::SettingsObject(QObject *parent) : QObject(parent)
{
    qRegisterMetaType<SettingsObject>("SettingsObject");
    this->setParent(parent);


    m_status = NO_SETTINGS;

     m_laser_galvo_portNumber = 0;
     m_materialDelivery_portNumber = 0;

     m_laser_deviceNumber = 0;
     m_galvo_deviceNumber = 0;
     m_z_deviceNumber = 0;
     m_hopper_deviceNumber = 0;
     m_spreader_deviceNumber = 0;

     m_laser_axisNumber = 0;
     m_x_axisNumber = 0;
     m_y_axisNumber = 0;
     m_z_axisNumber = 0;
     m_hopper_axisNumber = 0;
     m_spreader_axisNumber = 0;

     m_laser_power_resolution = 0;
     m_x_position_resolution = 0;
     m_y_position_resolution = 0;
     m_z_position_resolution = 0;
     m_hopper_position_resolution = 0;
     m_spreader_position_resolution = 0;

     m_laser_power_default = 0;
     m_laser_power_max = 0;
     m_laser_power_min = 0;

     m_x_position_max = 0;
     m_x_position_min = 0;
     m_y_position_max = 0;
     m_y_position_min = 0;
     m_xy_speed_default = 0;
     m_xy_speed_max = 0;
     m_xy_speed_min = 0;

     m_z_position_max = 0;
     m_z_position_min = 0;
     m_z_speed_default = 0;
     m_z_speed_max = 0;
     m_z_speed_min = 0;

     m_hopper_position_max = 0;
     m_hopper_position_min = 0;
     m_hopper_speed_default = 0;
     m_hopper_speed_max = 0;
     m_hopper_speed_min = 0;

     m_spreader_position_max = 0;
     m_spreader_position_min = 0;
     m_spreader_speed_default = 0;
     m_spreader_speed_max = 0;
     m_spreader_speed_min = 0;
}

SettingsObject::SettingsObject(const SettingsObject &otherSettings)
{
    this->setParent(otherSettings.parent());

     m_settingsFilePath = otherSettings.settingsFilePath();

     m_status = otherSettings.status();

     m_laser_galvo_portNumber = otherSettings.laser_galvo_portNumber();
     m_materialDelivery_portNumber = otherSettings.materialDelivery_portNumber();

     m_laser_deviceNumber = otherSettings.laser_deviceNumber();
     m_galvo_deviceNumber = otherSettings.galvo_deviceNumber();
     m_z_deviceNumber = otherSettings.z_deviceNumber();
     m_hopper_deviceNumber = otherSettings.hopper_deviceNumber();
     m_spreader_deviceNumber = otherSettings.spreader_deviceNumber();

     m_laser_axisNumber = otherSettings.laser_axisNumber();
     m_x_axisNumber = otherSettings.x_axisNumber();
     m_y_axisNumber = otherSettings.y_axisNumber();
     m_z_axisNumber = otherSettings.z_axisNumber();
     m_hopper_axisNumber = otherSettings.hopper_axisNumber();
     m_spreader_axisNumber = otherSettings.spreader_axisNumber();

     m_laser_power_resolution = otherSettings.laser_power_resolution();
     m_x_position_resolution = otherSettings.x_position_resolution();
     m_y_position_resolution = otherSettings.y_position_resolution();
     m_z_position_resolution = otherSettings.z_position_resolution();
     m_hopper_position_resolution = otherSettings.hopper_position_resolution();
     m_spreader_position_resolution = otherSettings.spreader_position_resolution();

     m_laser_power_default = otherSettings.laser_power_default();
     m_laser_power_max = otherSettings.laser_power_max();
     m_laser_power_min = otherSettings.laser_power_min();

     m_x_position_max = otherSettings.x_position_max();
     m_x_position_min = otherSettings.x_position_min();
     m_y_position_max = otherSettings.y_position_max();
     m_y_position_min = otherSettings.y_position_min();
     m_xy_speed_default = otherSettings.xy_speed_default();
     m_xy_speed_max = otherSettings.xy_speed_max();
     m_xy_speed_min = otherSettings.xy_speed_min();

     m_z_position_max = otherSettings.z_position_max();
     m_z_position_min = otherSettings.z_position_min();
     m_z_speed_default = otherSettings.z_speed_default();
     m_z_speed_max = otherSettings.z_speed_max();
     m_z_speed_min = otherSettings.z_speed_min();

     m_hopper_position_max = otherSettings.hopper_position_max();
     m_hopper_position_min = otherSettings.hopper_position_min();
     m_hopper_speed_default = otherSettings.hopper_speed_default();
     m_hopper_speed_max = otherSettings.hopper_speed_max();
     m_hopper_speed_min = otherSettings.hopper_speed_min();

     m_spreader_position_max = otherSettings.spreader_position_max();
     m_spreader_position_min = otherSettings.spreader_position_min();
     m_spreader_speed_default = otherSettings.spreader_speed_default();
     m_spreader_speed_max = otherSettings.spreader_speed_max();
     m_spreader_speed_min = otherSettings.spreader_speed_min();
}

SettingsObject::~SettingsObject()
{

}

uint8_t SettingsObject::laser_galvo_portNumber() const
{
    return m_laser_galvo_portNumber;
}

void SettingsObject::setLaser_galvo_portNumber(const uint8_t &laser_galvo_portNumber)
{
    m_laser_galvo_portNumber = laser_galvo_portNumber;
}

uint8_t SettingsObject::materialDelivery_portNumber() const
{
    return m_materialDelivery_portNumber;
}

void SettingsObject::setMaterialDelivery_portNumber(const uint8_t &materialDelivery_portNumber)
{
    m_materialDelivery_portNumber = materialDelivery_portNumber;
}

uint8_t SettingsObject::laser_deviceNumber() const
{
    return m_laser_deviceNumber;
}

void SettingsObject::setLaser_deviceNumber(const uint8_t &laser_deviceNumber)
{
    m_laser_deviceNumber = laser_deviceNumber;
}

uint8_t SettingsObject::galvo_deviceNumber() const
{
    return m_galvo_deviceNumber;
}

void SettingsObject::setGalvo_deviceNumber(const uint8_t &galvo_deviceNumber)
{
    m_galvo_deviceNumber = galvo_deviceNumber;
}

uint8_t SettingsObject::z_deviceNumber() const
{
    return m_z_deviceNumber;
}

void SettingsObject::setZ_deviceNumber(const uint8_t &z_deviceNumber)
{
    m_z_deviceNumber = z_deviceNumber;
}

uint8_t SettingsObject::hopper_deviceNumber() const
{
    return m_hopper_deviceNumber;
}

void SettingsObject::setHopper_deviceNumber(const uint8_t &hopper_deviceNumber)
{
    m_hopper_deviceNumber = hopper_deviceNumber;
}

uint8_t SettingsObject::spreader_deviceNumber() const
{
    return m_spreader_deviceNumber;
}

void SettingsObject::setSpreader_deviceNumber(const uint8_t &spreader_deviceNumber)
{
    m_spreader_deviceNumber = spreader_deviceNumber;
}

uint8_t SettingsObject::laser_axisNumber() const
{
    return m_laser_axisNumber;
}

void SettingsObject::setLaser_axisNumber(const uint8_t &laser_axisNumber)
{
    m_laser_axisNumber = laser_axisNumber;
}

uint8_t SettingsObject::x_axisNumber() const
{
    return m_x_axisNumber;
}

void SettingsObject::setX_axisNumber(const uint8_t &x_axisNumber)
{
    m_x_axisNumber = x_axisNumber;
}

uint8_t SettingsObject::y_axisNumber() const
{
    return m_y_axisNumber;
}

void SettingsObject::setY_axisNumber(const uint8_t &y_axisNumber)
{
    m_y_axisNumber = y_axisNumber;
}

uint8_t SettingsObject::z_axisNumber() const
{
    return m_z_axisNumber;
}

void SettingsObject::setZ_axisNumber(const uint8_t &z_axisNumber)
{
    m_z_axisNumber = z_axisNumber;
}

uint8_t SettingsObject::hopper_axisNumber() const
{
    return m_hopper_axisNumber;
}

void SettingsObject::setHopper_axisNumber(const uint8_t &hopper_axisNumber)
{
    m_hopper_axisNumber = hopper_axisNumber;
}

uint8_t SettingsObject::spreader_axisNumber() const
{
    return m_spreader_axisNumber;
}

void SettingsObject::setSpreader_axisNumber(const uint8_t &spreader_axisNumber)
{
    m_spreader_axisNumber = spreader_axisNumber;
}

float SettingsObject::laser_power_resolution() const
{
    return m_laser_power_resolution;
}

void SettingsObject::setLaser_power_resolution(float laser_power_resolution)
{
    m_laser_power_resolution = laser_power_resolution;
}

float SettingsObject::x_position_resolution() const
{
    return m_x_position_resolution;
}

void SettingsObject::setX_position_resolution(float x_position_resolution)
{
    m_x_position_resolution = x_position_resolution;
}

float SettingsObject::y_position_resolution() const
{
    return m_y_position_resolution;
}

void SettingsObject::setY_position_resolution(float y_position_resolution)
{
    m_y_position_resolution = y_position_resolution;
}

float SettingsObject::z_position_resolution() const
{
    return m_z_position_resolution;
}

void SettingsObject::setZ_position_resolution(float z_position_resolution)
{
    m_z_position_resolution = z_position_resolution;
}

float SettingsObject::hopper_position_resolution() const
{
    return m_hopper_position_resolution;
}

void SettingsObject::setHopper_position_resolution(float hopper_position_resolution)
{
    m_hopper_position_resolution = hopper_position_resolution;
}

float SettingsObject::spreader_position_resolution() const
{
    return m_spreader_position_resolution;
}

void SettingsObject::setSpreader_position_resolution(float spreader_position_resolution)
{
    m_spreader_position_resolution = spreader_position_resolution;
}

uint8_t SettingsObject::laser_power_default() const
{
    return m_laser_power_default;
}

void SettingsObject::setLaser_power_default(const uint8_t &laser_power_default)
{
    m_laser_power_default = laser_power_default;
}

uint8_t SettingsObject::laser_power_max() const
{
    return m_laser_power_max;
}

void SettingsObject::setLaser_power_max(const uint8_t &laser_power_max)
{
    m_laser_power_max = laser_power_max;
}

uint8_t SettingsObject::laser_power_min() const
{
    return m_laser_power_min;
}

void SettingsObject::setLaser_power_min(const uint8_t &laser_power_min)
{
    m_laser_power_min = laser_power_min;
}

float SettingsObject::x_position_max() const
{
    return m_x_position_max;
}

float SettingsObject::x_position_min() const
{
    return m_x_position_min;
}

void SettingsObject::setX_position_max(float x_position_max)
{
    m_x_position_max = x_position_max;
}

void SettingsObject::setX_position_min(float x_position_min)
{
    m_x_position_min = x_position_min;
}

float SettingsObject::y_position_max() const
{
    return m_y_position_max;
}

void SettingsObject::setY_position_max(float y_position_max)
{
    m_y_position_max = y_position_max;
}

float SettingsObject::y_position_min() const
{
    return m_y_position_min;
}

void SettingsObject::setY_position_min(float y_position_min)
{
    m_y_position_min = y_position_min;
}

float SettingsObject::xy_speed_default() const
{
    return m_xy_speed_default;
}

void SettingsObject::setXY_speed_default(float xy_speed_default)
{
    m_xy_speed_default = xy_speed_default;
}

float SettingsObject::xy_speed_max() const
{
    return m_xy_speed_max;
}

void SettingsObject::setXY_speed_max(float xy_speed_max)
{
    m_xy_speed_max = xy_speed_max;
}

float SettingsObject::xy_speed_min() const
{
    return m_xy_speed_min;
}

void SettingsObject::setXY_speed_min(float xy_speed_min)
{
    m_xy_speed_min = xy_speed_min;
}

float SettingsObject::z_position_max() const
{
    return m_z_position_max;
}

void SettingsObject::setZ_position_max(float z_position_max)
{
    m_z_position_max = z_position_max;
}

float SettingsObject::z_position_min() const
{
    return m_z_position_min;
}

void SettingsObject::setZ_position_min(float z_position_min)
{
    m_z_position_min = z_position_min;
}

float SettingsObject::z_speed_default() const
{
    return m_z_speed_default;
}

void SettingsObject::setZ_speed_default(float z_speed_default)
{
    m_z_speed_default = z_speed_default;
}

float SettingsObject::z_speed_max() const
{
    return m_z_speed_max;
}

void SettingsObject::setZ_speed_max(float z_speed_max)
{
    m_z_speed_max = z_speed_max;
}

float SettingsObject::z_speed_min() const
{
    return m_z_speed_min;
}

void SettingsObject::setZ_speed_min(float z_speed_min)
{
    m_z_speed_min = z_speed_min;
}

float SettingsObject::hopper_position_max() const
{
    return m_hopper_position_max;
}

void SettingsObject::setHopper_position_max(float hopper_position_max)
{
    m_hopper_position_max = hopper_position_max;
}

float SettingsObject::hopper_position_min() const
{
    return m_hopper_position_min;
}

void SettingsObject::setHopper_position_min(float hopper_position_min)
{
    m_hopper_position_min = hopper_position_min;
}

float SettingsObject::hopper_speed_default() const
{
    return m_hopper_speed_default;
}

void SettingsObject::setHopper_speed_default(float hopper_speed_default)
{
    m_hopper_speed_default = hopper_speed_default;
}

float SettingsObject::hopper_speed_max() const
{
    return m_hopper_speed_max;
}

void SettingsObject::setHopper_speed_max(float hopper_speed_max)
{
    m_hopper_speed_max = hopper_speed_max;
}

float SettingsObject::hopper_speed_min() const
{
    return m_hopper_speed_min;
}

void SettingsObject::setHopper_speed_min(float hopper_speed_min)
{
    m_hopper_speed_min = hopper_speed_min;
}

float SettingsObject::spreader_position_max() const
{
    return m_spreader_position_max;
}

void SettingsObject::setSpreader_position_max(float spreader_position_max)
{
    m_spreader_position_max = spreader_position_max;
}

float SettingsObject::spreader_position_min() const
{
    return m_spreader_position_min;
}

void SettingsObject::setSpreader_position_min(float spreader_position_min)
{
    m_spreader_position_min = spreader_position_min;
}

float SettingsObject::spreader_speed_default() const
{
    return m_spreader_speed_default;
}

void SettingsObject::setSpreader_speed_default(float spreader_speed_default)
{
    m_spreader_speed_default = spreader_speed_default;
}

float SettingsObject::spreader_speed_max() const
{
    return m_spreader_speed_max;
}

void SettingsObject::setSpreader_speed_max(float spreader_speed_max)
{
    m_spreader_speed_max = spreader_speed_max;
}

float SettingsObject::spreader_speed_min() const
{
    return m_spreader_speed_min;
}

void SettingsObject::setSpreader_speed_min(float spreader_speed_min)
{
    m_spreader_speed_min = spreader_speed_min;
}

void SettingsObject::setSettingsFilePath(const QString &settingsFilePath)
{
    m_settingsFilePath = settingsFilePath;
}

SettingsObject::SettingsStatus SettingsObject::status() const
{
    return m_status;
}

void SettingsObject::setStatus(const SettingsStatus &status)
{
    m_status = status;
}

QString SettingsObject::settingsFilePath() const
{
    return m_settingsFilePath;
}

