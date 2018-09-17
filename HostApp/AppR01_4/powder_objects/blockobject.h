#ifndef BLOCKOBJECT_H
#define BLOCKOBJECT_H
#include <QString>

#include <QMetaType>
#include <QStringList>

class BlockObject
{

public:
    BlockObject();
    BlockObject(const int block_number, const int layer_Number); // constructor
    BlockObject(const BlockObject &otherBlock); // copy constructor
    ~BlockObject(); // destructor

    int blockNumber() const;
    void setBlockNumber(const int &blockNumber);
    int layerNumber() const;
    void setLayerNumber(const int &layerNumber);

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
    void setBlockTask(uint16_t blockTask);
    uint16_t blockTask() const;

    bool laser_enabled() const;
    void setLaser_enabled(bool laser_enabled);

    bool laser_armed() const;
    void setLaser_armed(bool laser_armed);

    int laser_power() const;
    void setLaser_power(const int &laser_power);

    enum PositionMode {
        Position_Absolute,
        Position_Relative,
    };
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

    void clearTask();


    QString lg_string() const;
    void setLg_string(const QString &lg_string);

    QStringList md_string() const;
    void setMd_string(const QStringList &md_string);

private:
    int m_blockNumber;
    int m_layerNumber;

    uint16_t m_blockTask;

    bool m_laser_enabled;
    bool m_laser_armed;
    int m_laser_power;

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

    QString m_lg_string;
    QStringList m_md_string;

};

Q_DECLARE_METATYPE(BlockObject);

#endif // BLOCKOBJECT_H
