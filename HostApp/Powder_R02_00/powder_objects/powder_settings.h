#ifndef POWDER_SETTINGS_H
#define POWDER_SETTINGS_H

#include <QMetaType>
#include <QString>

/*
 * PowderSettings holds the configuration parameters for printer.
 * PowderSettings is set by the UI from a ini file or user input.
 */

class PowderSettings
{
public:
    PowderSettings();
    PowderSettings(const PowderSettings &otherSettings);
    ~PowderSettings();

    enum SettingsStatus :  int
    {
        NO_SETTINGS,
        SETTINGS_INVALID,
        SETTINGS_FILE_INVALID,
        SETTINGS_VALID
    };

    int galvo_portNumber() const;
    void setGalvo_portNumber(const  int &galvo_portNumber);

    int materialDelivery_portNumber() const;
    void setMaterialDelivery_portNumber(const  int &materialDelivery_portNumber);

    int laser_deviceNumber() const;
    void setLaser_deviceNumber(const  int &laser_deviceNumber);


    int galvo_deviceNumber() const;
    void setGalvo_deviceNumber(const  int &galvo_deviceNumber);


    int z_deviceNumber() const;
    void setZ_deviceNumber(const  int &z_deviceNumber);


    int hopper_deviceNumber() const;
    void setHopper_deviceNumber(const  int &hopper_deviceNumber);

    int spreader_deviceNumber() const;
    void setSpreader_deviceNumber(const  int &spreader_deviceNumber);

    int laser_axisNumber() const;
    void setLaser_axisNumber(const  int &laser_axisNumber);

    int x_axisNumber() const;
    void setX_axisNumber(const  int &x_axisNumber);

    int y_axisNumber() const;
    void setY_axisNumber(const  int &y_axisNumber);

    int z_axisNumber() const;
    void setZ_axisNumber(const  int &z_axisNumber);

    int hopper_axisNumber() const;
    void setHopper_axisNumber(const  int &hopper_axisNumber);

    int spreader_axisNumber() const;
    void setSpreader_axisNumber(const  int &spreader_axisNumber);

    float laserPower_max() const;
    void setLaserPower_max(float laserPower_max);

    float x_position_resolution() const;
    void setX_position_resolution(float x_position_resolution);

    float y_position_resolution() const;
    void setY_position_resolution(float y_position_resolution);

    float z_position_resolution() const;
    void setZ_position_resolution(float z_position_resolution);

    float hopper_position_resolution() const;
    void setHopper_position_resolution(float hopper_position_resolution);

    float spreader_position_resolution() const;
    void setSpreader_position_resolution(float spreader_position_resolution);

    float laser_intensity_default() const;
    void setLaser_intensity_default(const  float &laser_intensity_default);

    float laser_intensity_max() const;
    void setLaser_intensity_max(const  float &laser_intensity_max);

    float laser_intensity_min() const;
    void setLaser_intensity_min(const  float &laser_intensity_min);

    float x_position_max() const;
    void setX_position_max(float x_position_max);

    float x_position_min() const;
    void setX_position_min(float x_position_min);

    float y_position_max() const;
    void setY_position_max(float y_position_max);

    float y_position_min() const;
    void setY_position_min(float y_position_min);

    float xy_speed_default() const;
    void setXY_speed_default(float xy_speed_default);

    float xy_speed_max() const;
    void setXY_speed_max(float xy_speed_max);

    float xy_speed_min() const;
    void setXY_speed_min(float xy_speed_min);

    float z_position_max() const;
    void setZ_position_max(float z_position_max);

    float z_position_min() const;
    void setZ_position_min(float z_position_min);

    float z_speed_default() const;
    void setZ_speed_default(float z_speed_default);

    float z_speed_max() const;
    void setZ_speed_max(float z_speed_max);

    float z_speed_min() const;
    void setZ_speed_min(float z_speed_min);

    float hopper_position_max() const;
    void setHopper_position_max(float hopper_position_max);

    float hopper_position_min() const;
    void setHopper_position_min(float hopper_position_min);

    float hopper_speed_default() const;
    void setHopper_speed_default(float hopper_speed_default);

    float hopper_speed_max() const;
    void setHopper_speed_max(float hopper_speed_max);

    float hopper_speed_min() const;
    void setHopper_speed_min(float hopper_speed_min);

    float spreader_position_max() const;
    void setSpreader_position_max(float spreader_position_max);

    float spreader_position_min() const;
    void setSpreader_position_min(float spreader_position_min);

    float spreader_speed_default() const;
    void setSpreader_speed_default(float spreader_speed_default);

    float spreader_speed_max() const;
    void setSpreader_speed_max(float spreader_speed_max);

    float spreader_speed_min() const;
    void setSpreader_speed_min(float spreader_speed_min);

    QString settingsFilePath() const;
    void setSettingsFilePath(const QString &settingsFilePath);

    SettingsStatus status() const;
    void setStatus(const SettingsStatus &status);


    int laser_pulseFreq_default() const;
    void setLaser_pulseFreq_default(int laser_pulseFreq_default);

    int laser_pulseFreq_max() const;
    void setLaser_pulseFreq_max(int laser_pulseFreq_max);

    int laser_pulseFreq_min() const;
    void setLaser_pulseFreq_min(int laser_pulseFreq_min);

    int laser_portNumber() const;
    void setLaser_portNumber(int laser_portNumber);

private:
    QString m_settingsFilePath;

    SettingsStatus m_status;

    int m_laser_portNumber;
    int m_galvo_portNumber;
    int m_materialDelivery_portNumber;

    int m_laser_deviceNumber;
    int m_galvo_deviceNumber;
    int m_z_deviceNumber;
    int m_hopper_deviceNumber;
    int m_spreader_deviceNumber;

    int m_laser_axisNumber;
    int m_x_axisNumber;
    int m_y_axisNumber;
    int m_z_axisNumber;
    int m_hopper_axisNumber;
    int m_spreader_axisNumber;

    float m_laserPower_max;
    float m_x_position_resolution;
    float m_y_position_resolution;
    float m_z_position_resolution;
    float m_hopper_position_resolution;
    float m_spreader_position_resolution;

    float m_laser_intensity_default;
    float m_laser_intensity_max;
    float m_laser_intensity_min;

    int m_laser_pulseFreq_default;
    int m_laser_pulseFreq_max;
    int m_laser_pulseFreq_min;

    float m_x_position_max;
    float m_x_position_min;
    float m_y_position_max;
    float m_y_position_min;
    float m_xy_speed_default;
    float m_xy_speed_max;
    float m_xy_speed_min;

    float m_z_position_max;
    float m_z_position_min;
    float m_z_speed_default;
    float m_z_speed_max;
    float m_z_speed_min;

    float m_hopper_position_max;
    float m_hopper_position_min;
    float m_hopper_speed_default;
    float m_hopper_speed_max;
    float m_hopper_speed_min;

    float m_spreader_position_max;
    float m_spreader_position_min;
    float m_spreader_speed_default;
    float m_spreader_speed_max;
    float m_spreader_speed_min;

};
Q_DECLARE_METATYPE(PowderSettings)
#endif // POWDER_SETTINGS_H
