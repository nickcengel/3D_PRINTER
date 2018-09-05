#ifndef SETTINGSOBJECT_H
#define SETTINGSOBJECT_H
#include <QMetaType>
#include <QString>

class SettingsObject
{


public:
    SettingsObject();
    SettingsObject(const SettingsObject &otherSettings);
    ~SettingsObject();

    enum SettingsStatus : uint8_t
    {
        NO_SETTINGS,
        SETTINGS_INVALID,
        SETTINGS_FILE_INVALID,
        SETTINGS_VALID
    };

    uint8_t laser_galvo_portNumber() const;
    void setLaser_galvo_portNumber(const uint8_t &laser_galvo_portNumber);

    uint8_t materialDelivery_portNumber() const;
    void setMaterialDelivery_portNumber(const uint8_t &materialDelivery_portNumber);

    uint8_t laser_deviceNumber() const;
    void setLaser_deviceNumber(const uint8_t &laser_deviceNumber);


    uint8_t galvo_deviceNumber() const;
    void setGalvo_deviceNumber(const uint8_t &galvo_deviceNumber);


    uint8_t z_deviceNumber() const;
    void setZ_deviceNumber(const uint8_t &z_deviceNumber);


    uint8_t hopper_deviceNumber() const;
    void setHopper_deviceNumber(const uint8_t &hopper_deviceNumber);


    uint8_t spreader_deviceNumber() const;
    void setSpreader_deviceNumber(const uint8_t &spreader_deviceNumber);


    uint8_t laser_axisNumber() const;
    void setLaser_axisNumber(const uint8_t &laser_axisNumber);

    uint8_t x_axisNumber() const;
    void setX_axisNumber(const uint8_t &x_axisNumber);

    uint8_t y_axisNumber() const;
    void setY_axisNumber(const uint8_t &y_axisNumber);

    uint8_t z_axisNumber() const;
    void setZ_axisNumber(const uint8_t &z_axisNumber);

    uint8_t hopper_axisNumber() const;
    void setHopper_axisNumber(const uint8_t &hopper_axisNumber);

    uint8_t spreader_axisNumber() const;
    void setSpreader_axisNumber(const uint8_t &spreader_axisNumber);

    float laser_power_resolution() const;
    void setLaser_power_resolution(float laser_power_resolution);

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

    uint8_t laser_power_default() const;
    void setLaser_power_default(const uint8_t &laser_power_default);

    uint8_t laser_power_max() const;
    void setLaser_power_max(const uint8_t &laser_power_max);

    uint8_t laser_power_min() const;
    void setLaser_power_min(const uint8_t &laser_power_min);

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


signals:

public slots:

private:
    QString m_settingsFilePath;

    SettingsStatus m_status;

    uint8_t m_laser_galvo_portNumber;
    uint8_t m_materialDelivery_portNumber;

    uint8_t m_laser_deviceNumber;
    uint8_t m_galvo_deviceNumber;
    uint8_t m_z_deviceNumber;
    uint8_t m_hopper_deviceNumber;
    uint8_t m_spreader_deviceNumber;

    uint8_t m_laser_axisNumber;
    uint8_t m_x_axisNumber;
    uint8_t m_y_axisNumber;
    uint8_t m_z_axisNumber;
    uint8_t m_hopper_axisNumber;
    uint8_t m_spreader_axisNumber;

    float m_laser_power_resolution;
    float m_x_position_resolution;
    float m_y_position_resolution;
    float m_z_position_resolution;
    float m_hopper_position_resolution;
    float m_spreader_position_resolution;

    uint8_t m_laser_power_default;
    uint8_t m_laser_power_max;
    uint8_t m_laser_power_min;

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
Q_DECLARE_METATYPE(SettingsObject)
#endif // SETTINGSOBJECT_H
