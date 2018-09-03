#ifndef SETTINGSOBJECT_H
#define SETTINGSOBJECT_H

#include <QObject>

class SettingsObject : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString settingsFilePath READ settingsFilePath WRITE setSettingsFilePath)
    Q_PROPERTY(SettingsStatus status READ status WRITE setStatus)
    Q_PROPERTY(uint8_t laser_galvo_portNumber READ laser_galvo_portNumber WRITE setLaser_galvo_portNumber)
    Q_PROPERTY(uint8_t materialDelivery_portNumber READ materialDelivery_portNumber WRITE setMaterialDelivery_portNumber)
    Q_PROPERTY(uint8_t laser_deviceNumber READ laser_deviceNumber WRITE setLaser_deviceNumber)
    Q_PROPERTY(uint8_t galvo_deviceNumber READ galvo_deviceNumber WRITE setGalvo_deviceNumber)
    Q_PROPERTY(uint8_t z_deviceNumber READ z_deviceNumber WRITE setZ_deviceNumber)
    Q_PROPERTY(uint8_t hopper_deviceNumber READ hopper_deviceNumber WRITE setHopper_deviceNumber)
    Q_PROPERTY(uint8_t spreader_deviceNumber READ spreader_deviceNumber WRITE setSpreader_deviceNumber)
    Q_PROPERTY(uint8_t laser_axisNumber READ laser_axisNumber WRITE setLaser_axisNumber)
    Q_PROPERTY(uint8_t x_axisNumber READ x_axisNumber WRITE setX_axisNumber)
    Q_PROPERTY(uint8_t y_axisNumber READ y_axisNumber WRITE setY_axisNumber)
    Q_PROPERTY(uint8_t z_axisNumber READ z_axisNumber WRITE setZ_axisNumber)
    Q_PROPERTY(uint8_t hopper_axisNumber READ hopper_axisNumber WRITE setHopper_axisNumber)
    Q_PROPERTY(uint8_t spreader_axisNumber READ spreader_axisNumber WRITE setSpreader_axisNumber)
    Q_PROPERTY(float laser_power_resolution READ laser_power_resolution WRITE setLaser_power_resolution)
    Q_PROPERTY(float x_position_resolution READ x_position_resolution WRITE setX_position_resolution)
    Q_PROPERTY(float y_position_resolution READ y_position_resolution WRITE setY_position_resolution)
    Q_PROPERTY(float z_position_resolution READ z_position_resolution WRITE setZ_position_resolution)
    Q_PROPERTY(float hopper_position_resolution READ hopper_position_resolution WRITE setHopper_position_resolution)
    Q_PROPERTY(float spreader_position_resolution READ spreader_position_resolution WRITE setSpreader_position_resolution)
    Q_PROPERTY(float laser_power_default READ laser_power_default WRITE setLaser_power_default)
    Q_PROPERTY(float laser_power_max READ laser_power_max WRITE setLaser_power_max)
    Q_PROPERTY(float laser_power_min READ laser_power_min WRITE setLaser_power_min)
    Q_PROPERTY(float x_position_max READ x_position_max WRITE setX_position_max)
    Q_PROPERTY(float x_position_min READ x_position_min WRITE setX_position_min)
    Q_PROPERTY(float y_position_max READ y_position_max WRITE setY_position_max)
    Q_PROPERTY(float y_position_min READ y_position_min WRITE setY_position_min)
    Q_PROPERTY(float xy_speed_default READ xy_speed_default WRITE setXY_speed_default)
    Q_PROPERTY(float xy_speed_max READ xy_speed_max WRITE setXY_speed_max)
    Q_PROPERTY(float xy_speed_min READ xy_speed_min WRITE setXY_speed_min)
    Q_PROPERTY(float z_position_max READ z_position_max WRITE setZ_position_max)
    Q_PROPERTY(float z_position_min READ z_position_min WRITE setZ_position_min)
    Q_PROPERTY(float z_speed_default READ z_speed_default WRITE setZ_speed_default)
    Q_PROPERTY(float z_speed_max READ z_speed_max WRITE setZ_speed_max)
    Q_PROPERTY(float z_speed_min READ z_speed_min WRITE setZ_speed_min)
    Q_PROPERTY(float hopper_position_max READ hopper_position_max WRITE setHopper_position_max)
    Q_PROPERTY(float hopper_position_min READ hopper_position_min WRITE setHopper_position_min)
    Q_PROPERTY(float hopper_speed_default READ hopper_speed_default WRITE setHopper_speed_default)
    Q_PROPERTY(float hopper_speed_max READ hopper_speed_max WRITE setHopper_speed_max)
    Q_PROPERTY(float hopper_speed_min READ hopper_speed_min WRITE setHopper_speed_min)
    Q_PROPERTY(float spreader_position_max READ spreader_position_max WRITE setSpreader_position_max)
    Q_PROPERTY(float spreader_position_min READ spreader_position_min WRITE setSpreader_position_min)
    Q_PROPERTY(float spreader_speed_default READ spreader_speed_default WRITE setSpreader_speed_default)
    Q_PROPERTY(uint8_t spreader_speed_max READ spreader_speed_max WRITE setSpreader_speed_max)
    Q_PROPERTY(uint8_t spreader_speed_min READ spreader_speed_min WRITE setSpreader_speed_min)

public:
    explicit SettingsObject(QObject *parent = nullptr);
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
