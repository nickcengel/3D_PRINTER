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
 *    which data fields will be used to update the machine's state.
 *  - The blockNumber and layerNumber variables are used during generation and playback to
 *    keep track of the place of the block inside the parts different layers.
 *  - lg_string contains the generated command string destined for the laser-galvo controller
 *  - md_string contains a list of command strings for the various material-delivery controllers.
 *      index0 = build plate, index1 = hopper, index2 = spreader
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


    // setBlockTask sets the bit of block's task variable corresponding to the input argument task
    void setBlockTask(uint16_t task);
    uint16_t blockTask() const;


    bool laser_enabled() const; //  The on/off state of the laser
    void setLaser_enabled(bool laser_enabled);

    // The laser must be armed to be enabled. otherwise enable
    // commands will be ignored.
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

Q_DECLARE_METATYPE(PowderBlock);

#endif // POWDER_BLOCK
