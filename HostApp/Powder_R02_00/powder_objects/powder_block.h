#ifndef POWDER_BLOCK_H
#define POWDER_BLOCK_H

#include <QString>

#include <QMetaType>
#include <QStringList>

/*
 * The PowderBlock class is used to create a representation of a single line of G-Code.
 *
 * PowderBlocks are created and stored in a PowderPart. This class is not intended to be
 * instantiated outside of the PowderPart class.
 *
 * In addition to holding the data from a line of G-Code, PowderBlock also contains
 * additional information that is useful for "playing back" the blocks during a print.
 *  - This includes the "blockTask" variable, in which setting a or clearing a bit controls
 *    which data fields will be used to update the machine's state parameters.
 *  - The blockNumber and layerNumber variables are used during generation and playback to
 *    keep track of the place of the block inside a part's different layers.
 *  - galvo_string contains the generated command string destined for the galvo controller
 *  - materialDelivery_string contains a list of command strings for the various material-delivery devices.
 *      index0 = build plate, index1 = hopper, index2 = spreader, index3 = md speed
 */
class PowderBlock
{
public:
    PowderBlock();
    PowderBlock(const int block_number, const int layer_Number);
    PowderBlock(const PowderBlock &otherBlock);
    ~PowderBlock();

    int blockNumber() const; //Corresponds to the line number of the G-Code
    void setBlockNumber(const int &blockNumber);

    //If the parser finds a new_layer flag, it will group blocks into layers.
    int layerNumber() const;
    void setLayerNumber(const int &layerNumber);


    // BlockTask enumerates the possible actions that a block may contain.
    // Each task is cannonical, so multiple tasks can be OR'd together.
    enum BlockTask : uint32_t {
        BLOCK_EMPTY = 0x0,
        SET_LASER_ARM_STATE = (1<<1),
        SET_LASER_ENABLE_STATE = (1<<2),
        SET_LASER_INTENSITY = (1<<3),
        SET_LASER_MODE = (1<<4),
        SET_LASER_PULSE_FREQ = (1<<5),
        SET_POSITION_MODE = (1<<6),
        SET_X_POSITION = (1<<7),
        SET_Y_POSITION = (1<<8),
        SET_XY_SPEED = (1<<9),
        SET_Z_POSITION = (1<<10),
        SET_Z_SPEED = (1<<11),
        SET_HOPPER_POSITION = (1<<12),
        SET_HOPPER_SPEED = (1<<13),
        SET_SPREADER_POSITION = (1<<14),
        SET_SPREADER_SPEED = (1<<15),
        SET_HOME_AXIS = (1<<16),
        SET_DWELL_TIME  = (1<<17),
        BLOCK_ERROR  = (1<<18)
    };


    // setBlockTask sets the bit of block's task variable corresponding to the input argument task
    void setBlockTask(uint32_t task);
    uint32_t blockTask() const;


    bool laser_enabled() const; //  The on/off state of the laser
    void setLaser_enabled(bool laser_enabled);

    // The laser must be armed to be enabled. otherwise enable
    // commands will be ignored.
    bool laser_armed() const;
    void setLaser_armed(bool laser_armed);

    float laser_intensity() const;
    void setLaser_intensity(const float &laser_intensity);

    enum PositionMode {
        Position_Absolute,
        Position_Relative,
    };

    enum CommandType {
        NO_COMMAND_TYPE,
        G0_RAPID_MOVE,
        G1_LINEAR_MOVE,
        G4_DWELL,
        M649_MODIFY_LASER
    };

    enum LaserMode {
        LASER_PULSED = 0,
        LASER_CONTINUOUS = 1,
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

    QString galvo_string() const;
    void setGalvo_string(const QString &galvo_string);

    QStringList materialDeliveryPosition_string() const;
    void setmaterialDeliveryPosition_string(const QStringList &materialDeliveryPosition_string);

    CommandType commandType() const;
    void setCommandType(const CommandType &commandType);


    int laser_pulseFreq() const;
    void setLaser_pulseFreq(int laser_pulseFreq);

    LaserMode laserMode() const;
    void setLaserMode(const LaserMode &laserMode);

    QStringList laser_string() const;
    void setLaser_string(const QStringList &laser_string);

    QStringList materialDeliverySpeed_string() const;
    void setMaterialDeliverySpeed_string(const QStringList &materialDeliverySpeed_string);

private:
    int m_blockNumber;
    int m_layerNumber;

    uint32_t m_blockTask;

    LaserMode m_laserMode;
    bool m_laser_enabled;
    bool m_laser_armed;
    float m_laser_intensity;
    int m_laser_pulseFreq;


    PositionMode m_positionMode;

    CommandType m_commandType;

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

    QStringList m_laser_string;
    QString m_galvo_string;
    QStringList m_materialDeliverySpeed_string;
    QStringList m_materialDeliveryPosition_string;

};

Q_DECLARE_METATYPE(PowderBlock);

#endif // POWDER_BLOCK
