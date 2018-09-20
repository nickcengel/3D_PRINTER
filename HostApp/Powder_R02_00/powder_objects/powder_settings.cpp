#include "powder_settings.h"

PowderSettings::PowderSettings()
{
    qRegisterMetaType<PowderSettings>("PowderSettings");

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

PowderSettings::PowderSettings(const PowderSettings &otherSettings)
{
     m_settingsFilePath = otherSettings.settingsFilePath();

     m_status = otherSettings.status();

     m_laser_galvo_portNumber = otherSettings.laserGalvo_portNumber();
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

PowderSettings::~PowderSettings()
{

}

int PowderSettings::laserGalvo_portNumber() const
{
    return m_laser_galvo_portNumber;
}

void PowderSettings::setLaser_galvo_portNumber(const int &laser_galvo_portNumber)
{
    m_laser_galvo_portNumber = laser_galvo_portNumber;
}

int PowderSettings::materialDelivery_portNumber() const
{
    return m_materialDelivery_portNumber;
}

void PowderSettings::setMaterialDelivery_portNumber(const int &materialDelivery_portNumber)
{
    m_materialDelivery_portNumber = materialDelivery_portNumber;
}

int PowderSettings::laser_deviceNumber() const
{
    return m_laser_deviceNumber;
}

void PowderSettings::setLaser_deviceNumber(const int &laser_deviceNumber)
{
    m_laser_deviceNumber = laser_deviceNumber;
}

int PowderSettings::galvo_deviceNumber() const
{
    return m_galvo_deviceNumber;
}

void PowderSettings::setGalvo_deviceNumber(const int &galvo_deviceNumber)
{
    m_galvo_deviceNumber = galvo_deviceNumber;
}

int PowderSettings::z_deviceNumber() const
{
    return m_z_deviceNumber;
}

void PowderSettings::setZ_deviceNumber(const int &z_deviceNumber)
{
    m_z_deviceNumber = z_deviceNumber;
}

int PowderSettings::hopper_deviceNumber() const
{
    return m_hopper_deviceNumber;
}

void PowderSettings::setHopper_deviceNumber(const int &hopper_deviceNumber)
{
    m_hopper_deviceNumber = hopper_deviceNumber;
}

int PowderSettings::spreader_deviceNumber() const
{
    return m_spreader_deviceNumber;
}

void PowderSettings::setSpreader_deviceNumber(const int &spreader_deviceNumber)
{
    m_spreader_deviceNumber = spreader_deviceNumber;
}

int PowderSettings::laser_axisNumber() const
{
    return m_laser_axisNumber;
}

void PowderSettings::setLaser_axisNumber(const int &laser_axisNumber)
{
    m_laser_axisNumber = laser_axisNumber;
}

int PowderSettings::x_axisNumber() const
{
    return m_x_axisNumber;
}

void PowderSettings::setX_axisNumber(const int &x_axisNumber)
{
    m_x_axisNumber = x_axisNumber;
}

int PowderSettings::y_axisNumber() const
{
    return m_y_axisNumber;
}

void PowderSettings::setY_axisNumber(const int &y_axisNumber)
{
    m_y_axisNumber = y_axisNumber;
}

int PowderSettings::z_axisNumber() const
{
    return m_z_axisNumber;
}

void PowderSettings::setZ_axisNumber(const int &z_axisNumber)
{
    m_z_axisNumber = z_axisNumber;
}

int PowderSettings::hopper_axisNumber() const
{
    return m_hopper_axisNumber;
}

void PowderSettings::setHopper_axisNumber(const int &hopper_axisNumber)
{
    m_hopper_axisNumber = hopper_axisNumber;
}

int PowderSettings::spreader_axisNumber() const
{
    return m_spreader_axisNumber;
}

void PowderSettings::setSpreader_axisNumber(const int &spreader_axisNumber)
{
    m_spreader_axisNumber = spreader_axisNumber;
}

float PowderSettings::laser_power_resolution() const
{
    return m_laser_power_resolution;
}

void PowderSettings::setLaser_power_resolution(float laser_power_resolution)
{
    m_laser_power_resolution = laser_power_resolution;
}

float PowderSettings::x_position_resolution() const
{
    return m_x_position_resolution;
}

void PowderSettings::setX_position_resolution(float x_position_resolution)
{
    m_x_position_resolution = x_position_resolution;
}

float PowderSettings::y_position_resolution() const
{
    return m_y_position_resolution;
}

void PowderSettings::setY_position_resolution(float y_position_resolution)
{
    m_y_position_resolution = y_position_resolution;
}

float PowderSettings::z_position_resolution() const
{
    return m_z_position_resolution;
}

void PowderSettings::setZ_position_resolution(float z_position_resolution)
{
    m_z_position_resolution = z_position_resolution;
}

float PowderSettings::hopper_position_resolution() const
{
    return m_hopper_position_resolution;
}

void PowderSettings::setHopper_position_resolution(float hopper_position_resolution)
{
    m_hopper_position_resolution = hopper_position_resolution;
}

float PowderSettings::spreader_position_resolution() const
{
    return m_spreader_position_resolution;
}

void PowderSettings::setSpreader_position_resolution(float spreader_position_resolution)
{
    m_spreader_position_resolution = spreader_position_resolution;
}

int PowderSettings::laser_power_default() const
{
    return m_laser_power_default;
}

void PowderSettings::setLaser_power_default(const int &laser_power_default)
{
    m_laser_power_default = laser_power_default;
}

int PowderSettings::laser_power_max() const
{
    return m_laser_power_max;
}

void PowderSettings::setLaser_power_max(const int &laser_power_max)
{
    m_laser_power_max = laser_power_max;
}

int PowderSettings::laser_power_min() const
{
    return m_laser_power_min;
}

void PowderSettings::setLaser_power_min(const int &laser_power_min)
{
    m_laser_power_min = laser_power_min;
}

float PowderSettings::x_position_max() const
{
    return m_x_position_max;
}

float PowderSettings::x_position_min() const
{
    return m_x_position_min;
}

void PowderSettings::setX_position_max(float x_position_max)
{
    m_x_position_max = x_position_max;
}

void PowderSettings::setX_position_min(float x_position_min)
{
    m_x_position_min = x_position_min;
}

float PowderSettings::y_position_max() const
{
    return m_y_position_max;
}

void PowderSettings::setY_position_max(float y_position_max)
{
    m_y_position_max = y_position_max;
}

float PowderSettings::y_position_min() const
{
    return m_y_position_min;
}

void PowderSettings::setY_position_min(float y_position_min)
{
    m_y_position_min = y_position_min;
}

float PowderSettings::xy_speed_default() const
{
    return m_xy_speed_default;
}

void PowderSettings::setXY_speed_default(float xy_speed_default)
{
    m_xy_speed_default = xy_speed_default;
}

float PowderSettings::xy_speed_max() const
{
    return m_xy_speed_max;
}

void PowderSettings::setXY_speed_max(float xy_speed_max)
{
    m_xy_speed_max = xy_speed_max;
}

float PowderSettings::xy_speed_min() const
{
    return m_xy_speed_min;
}

void PowderSettings::setXY_speed_min(float xy_speed_min)
{
    m_xy_speed_min = xy_speed_min;
}

float PowderSettings::z_position_max() const
{
    return m_z_position_max;
}

void PowderSettings::setZ_position_max(float z_position_max)
{
    m_z_position_max = z_position_max;
}

float PowderSettings::z_position_min() const
{
    return m_z_position_min;
}

void PowderSettings::setZ_position_min(float z_position_min)
{
    m_z_position_min = z_position_min;
}

float PowderSettings::z_speed_default() const
{
    return m_z_speed_default;
}

void PowderSettings::setZ_speed_default(float z_speed_default)
{
    m_z_speed_default = z_speed_default;
}

float PowderSettings::z_speed_max() const
{
    return m_z_speed_max;
}

void PowderSettings::setZ_speed_max(float z_speed_max)
{
    m_z_speed_max = z_speed_max;
}

float PowderSettings::z_speed_min() const
{
    return m_z_speed_min;
}

void PowderSettings::setZ_speed_min(float z_speed_min)
{
    m_z_speed_min = z_speed_min;
}

float PowderSettings::hopper_position_max() const
{
    return m_hopper_position_max;
}

void PowderSettings::setHopper_position_max(float hopper_position_max)
{
    m_hopper_position_max = hopper_position_max;
}

float PowderSettings::hopper_position_min() const
{
    return m_hopper_position_min;
}

void PowderSettings::setHopper_position_min(float hopper_position_min)
{
    m_hopper_position_min = hopper_position_min;
}

float PowderSettings::hopper_speed_default() const
{
    return m_hopper_speed_default;
}

void PowderSettings::setHopper_speed_default(float hopper_speed_default)
{
    m_hopper_speed_default = hopper_speed_default;
}

float PowderSettings::hopper_speed_max() const
{
    return m_hopper_speed_max;
}

void PowderSettings::setHopper_speed_max(float hopper_speed_max)
{
    m_hopper_speed_max = hopper_speed_max;
}

float PowderSettings::hopper_speed_min() const
{
    return m_hopper_speed_min;
}

void PowderSettings::setHopper_speed_min(float hopper_speed_min)
{
    m_hopper_speed_min = hopper_speed_min;
}

float PowderSettings::spreader_position_max() const
{
    return m_spreader_position_max;
}

void PowderSettings::setSpreader_position_max(float spreader_position_max)
{
    m_spreader_position_max = spreader_position_max;
}

float PowderSettings::spreader_position_min() const
{
    return m_spreader_position_min;
}

void PowderSettings::setSpreader_position_min(float spreader_position_min)
{
    m_spreader_position_min = spreader_position_min;
}

float PowderSettings::spreader_speed_default() const
{
    return m_spreader_speed_default;
}

void PowderSettings::setSpreader_speed_default(float spreader_speed_default)
{
    m_spreader_speed_default = spreader_speed_default;
}

float PowderSettings::spreader_speed_max() const
{
    return m_spreader_speed_max;
}

void PowderSettings::setSpreader_speed_max(float spreader_speed_max)
{
    m_spreader_speed_max = spreader_speed_max;
}

float PowderSettings::spreader_speed_min() const
{
    return m_spreader_speed_min;
}

void PowderSettings::setSpreader_speed_min(float spreader_speed_min)
{
    m_spreader_speed_min = spreader_speed_min;
}

void PowderSettings::setSettingsFilePath(const QString &settingsFilePath)
{
    m_settingsFilePath = settingsFilePath;
}

PowderSettings::SettingsStatus PowderSettings::status() const
{
    return m_status;
}

void PowderSettings::setStatus(const SettingsStatus &status)
{
    m_status = status;
}

QString PowderSettings::settingsFilePath() const
{
    return m_settingsFilePath;
}

