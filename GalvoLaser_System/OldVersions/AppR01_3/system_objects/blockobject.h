#ifndef BLOCKOBJECT_H
#define BLOCKOBJECT_H

#include <QObject>
#include <QMetaType>

class BlockObject : public QObject
{
    Q_OBJECT
    Q_PROPERTY(uint32_t blockNumber READ blockNumber WRITE setBlockNumber)
    Q_PROPERTY(uint32_t layerNumber READ layerNumber WRITE setLayerNumber)

    Q_PROPERTY(uint16_t blockTask READ blockTask WRITE setBlockTask)

    Q_PROPERTY(bool laser_enabled READ laser_enabled WRITE setLaser_enabled)
    Q_PROPERTY(bool laser_armed READ laser_armed WRITE setLaser_armed)
    Q_PROPERTY(uint8_t laser_power READ laser_power WRITE setLaser_power)

    Q_PROPERTY(PositionMode positionMode READ positionMode WRITE setPositionMode)

    Q_PROPERTY(float x_position READ x_position WRITE setX_position)
    Q_PROPERTY(float y_position READ y_position WRITE setY_position)
    Q_PROPERTY(float xy_speed READ xy_speed WRITE setXY_speed)

    Q_PROPERTY(float z_position READ z_position WRITE setZ_position)
    Q_PROPERTY(float z_speed READ z_speed WRITE setZ_speed)

    Q_PROPERTY(float hopper_position READ hopper_position WRITE setHopper_position)
    Q_PROPERTY(float hopper_speed READ hopper_speed WRITE setHopper_speed)

    Q_PROPERTY(float spreader_position READ spreader_position WRITE setSpreader_position)
    Q_PROPERTY(float spreader_speed READ spreader_speed WRITE setSpreader_speed)

    Q_PROPERTY(float dwellTime READ dwellTime WRITE setDwellTime)

    Q_PROPERTY(QString g_code_line READ g_code_line WRITE setG_code_line)

    Q_PROPERTY(QString laser_galvo_command READ laser_galvo_command WRITE setLaser_galvo_command)
    Q_PROPERTY(QString z_command READ z_command WRITE setZ_command)
    Q_PROPERTY(QString hopper_command READ hopper_command WRITE setHopper_command)
    Q_PROPERTY(QString spreader_command READ spreader_command WRITE setSpreader_command)

public:
    explicit BlockObject(QObject *parent = nullptr); // constructor
    BlockObject(const BlockObject &otherBlock); // copy constructor
    ~BlockObject(); // destructor

    uint32_t blockNumber() const;
    void setBlockNumber(const uint32_t &blockNumber);
    uint32_t layerNumber() const;
    void setLayerNumber(const uint32_t &layerNumber);

    enum BlockTask : uint16_t {
        BLOCK_EMPTY = 0x0,
        SET_LASER_ARM_STATE = 0x1,
        SET_LASER_ENABLE_STATE = 0x2,
        SET_LASER_POWER = 0x4,
        SET_POSITION_MODE = 0x8,
        SET_X_POSITION = 0x10,
        SET_Y_POSITION = 0x20,
        SET_XY_SPEED = 0x40,
        SET_Z_POSITION = 0x80,
        SET_Z_SPEED = 0x100,
        SET_HOPPER_POSITION = 0x200,
        SET_HOPPER_SPEED = 0x400,
        SET_SPREADER_POSITION = 0x800,
        SET_SPREADER_SPEED = 0x1000,
        SET_HOME_AXIS = 0x2000,
        SET_DWELL_TIME  = 0x4000,
        BLOCK_ERROR  = 0x8000
    };
    Q_ENUM(BlockTask)
    void setBlockTask(uint16_t blockTask);
    uint16_t blockTask() const;

    bool laser_enabled() const;
    void setLaser_enabled(bool laser_enabled);

    bool laser_armed() const;
    void setLaser_armed(bool laser_armed);

    uint8_t laser_power() const;
    void setLaser_power(const uint8_t &laser_power);

    enum PositionMode {
        Position_Absolute,
        Position_Relative,
    };
    Q_ENUM(PositionMode)
    PositionMode positionMode() const;
    void setPositionMode(const PositionMode &positionMode);


    float x_position() const;
    void setX_position(float x_position);
    float y_position() const;
    void setY_position(float y_position);
    float xy_speed() const;
    void setXY_speed(float xy_speed);

    float z_position() const;
    void setZ_position(float z_position);
    float z_speed() const;
    void setZ_speed(float z_speed);

    float hopper_position() const;
    void setHopper_position(float hopper_position);
    float hopper_speed() const;
    void setHopper_speed(float hopper_speed);

    float spreader_position() const;
    void setSpreader_position(float spreader_position);
    float spreader_speed() const;
    void setSpreader_speed(float spreader_speed);

    float dwellTime() const;
    void setDwellTime(float dwellTime);

    QString g_code_line() const;
    void setG_code_line(const QString &g_code_line);

    QString laser_galvo_command() const;
    void setLaser_galvo_command(const QString &laser_galvo_command);

    QString z_command() const;
    void setZ_command(const QString &z_command);

    QString hopper_command() const;
    void setHopper_command(const QString &hopper_command);

    QString spreader_command() const;
    void setSpreader_command(const QString &spreader_command);

signals:

public slots:


private:
    uint32_t m_blockNumber;
    uint32_t m_layerNumber;

    uint16_t m_blockTask;

    bool m_laser_enabled;
    bool m_laser_armed;
    uint8_t m_laser_power;

    PositionMode m_positionMode;

    float m_x_position;
    float m_y_position;
    float m_xy_speed;

    float m_z_position;
    float m_z_speed;

    float m_hopper_position;
    float m_hopper_speed;

    float m_spreader_position;
    float m_spreader_speed;

    float m_dwellTime;

    QString m_g_code_line;

    QString m_laser_galvo_command;
    QString m_z_command;
    QString m_hopper_command;
    QString m_spreader_command;

};

Q_DECLARE_METATYPE(BlockObject);

#endif // BLOCKOBJECT_H
