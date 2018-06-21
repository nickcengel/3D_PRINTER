#ifndef BLOCKIO_H
#define BLOCKIO_H

#include <QObject>
#include <QTextStream>
#include <QDebug>
#include <qfiledialog.h>
#include <QString>
#include <QStringList>

//////////////////////////////////// BLOCKIO (a brief explanation) //////////////////////////////////
///
/// BLOCKIO is a namespace containing object and methods that transform a G code file into a "Part".
///
///     We'll use it to build a lightweight and flexible representation of a G code file
///     using the following hierarchy.
///
///     (BLOCKIO::) Part::Layer::Block::Package::Message
///
///        Where: a Part is a collection of Layers,
///               a Layer is a collection Blocks,
///               a Block contains Packages and meta information
///               a Package contains messages for a group of devices
///               a Message contains instructions and data for a device
///
/////////////////////////////////////////////////////////////////////////////////////////////////////

namespace BlockIO {

/////////////////////////////////// BLOCKIO BASE TYPES AND ENUMERATIONS /////////////////////////////

/// Codes : lists the accepted commands:
///// M0 - PROGRAM PAUSE
///// M2 - END PROGRAM
///// M3 - TURN LASER ON
///// M5 - TURN LASER OFF
///// G0 - RAPID MOVE
///// G1 - LINEAR MOVE
///// G4 - DWELL
///// G28 - HOME AXIS
///// G90 - ABSOLUTE POSITIONING
///// G91 - RELATIVE POSITIONING
enum Code {NO_CODE, M0, M2, M3, M5, G0, G1, G4, G28, G90, G91};

/// AxisTitle : Lists the accepted axis
///// X - x axis of the galvonometer
///// Y - y axis of the galvonometer
///// Z - z axis of the build plate
///// A - z' axis of the material hopper
///// B - x' axis of the material wiper
enum Axis_Number {ALL_AXIS, X, Y, Z, A, B, L, NO_AXIS};

/// An Axis' physical and electrical constraints
struct axis_settings_t
{
    int portNumber;
    int deviceNumber;
    Axis_Number axisNumber;
    float positionMin;
    float positionMax;
    float speedMin;
    float speedMax;
    float homeOffset;
    float uStepPerMM;
    axis_settings_t() {}
    axis_settings_t(int aPortNumber, int aDeviceNumber, Axis_Number anAxisNumber,
                    float aPositionMin, float aPositionMax, float aSpeedMin,
                    float aSpeedMax, float aHomeOffset, float microStepsPerMM){
        portNumber = aPortNumber;
        deviceNumber = aDeviceNumber;
        axisNumber = anAxisNumber;
        positionMin = aPositionMin;
        positionMax = aPositionMax;
        speedMin = aSpeedMin;
        speedMax = aSpeedMax;
        homeOffset = aHomeOffset;
        uStepPerMM = microStepsPerMM;
    }
};

/// A group of axis settings with other machine parameters
struct machine_settings_t
{
    axis_settings_t l_settings;
    axis_settings_t x_settings;
    axis_settings_t y_settings;
    axis_settings_t z_settings;
    axis_settings_t a_settings;
    axis_settings_t b_settings;

    machine_settings_t() {}
    machine_settings_t(axis_settings_t L_settings, axis_settings_t X_settings, axis_settings_t Y_settings,
                       axis_settings_t Z_settings, axis_settings_t A_settings,
                       axis_settings_t B_settings){
        l_settings = L_settings;
        x_settings = X_settings;
        y_settings = Y_settings;
        z_settings = Z_settings;
        a_settings = A_settings;
        b_settings = B_settings;
    }
};

/// message_t : A task grouped with one or more data values
///// a sender of a message will set the task value in order to encode the type of task along with an optional value.
///// a receiever of a message will read the task value in order to interpret the data value.
/// TaskMap - Lists the recognized tasks
///   [0] NONE : default value
///
///   [1] DISABLE: disable device
///
///   [2] POSITION : data[0] -> change in position
///
///   [3] POSITION_SPEED : data[0] -> change in position, data[1] -> change in speed
///
///   [4] HOME : if(data[0] != 0) -> go Home
///
///   [5] RELATIVE : switch to relative mode
///
///   [6] ABSOLUTE : switch to absolute mode
///
///   [7] ENABLE : enable device
///
///   [8] ENABLE_POWER : data[0] -> enable/disable *Laser*, data[1] -> laser power
///
///   [9] POWER : data[0] -> laser power
///
///   [10] DWELL : data[0] -> delay time
///

enum Device_Number {ALL_DEVICES,
                    LASER_GALVO,
                    BUILD_PLATE,
                    HOP_SPRD,
                    NO_DEVICE};

enum Message_Mode {MODE_ERROR,
                   ABSOLUTE_MODE,
                   ENABLED_MODE,
                   DISABLED_MODE,
                   RELATIVE_MODE,
                   NO_MODE};

enum Message_Task {TASK_ERROR,
                   DISABLE,
                   ENABLE,
                   ENABLE_AT_POWER,
                   SET_POWER,
                   MOVE_ABS,
                   MOVE_REL,
                   MOVE_ABS_AT_SPEED,
                   MOVE_REL_AT_SPEED,
                   STOP,
                   GO_HOME,
                   GET_STATUS,
                   TASK_COMPLETE,
                   NO_TASK};

enum Message_Status{STATUS_ERROR,
                    REPLY_FAILED,
                    REPLY_OK,
                    REPLY_PENDING,
                    ENABLED,
                    DISABLED,
                    IDLE,
                    BUSY,
                    NO_STATUS};

enum Message_Type{TYPE_ERROR,
                  M_INFO,       //  #
                  M_ALERT,      //  !
                  M_COMMAND,    //  /
                  M_REPLY,      //  @
                  NO_TYPE};

enum Message_Reply_Flag{FLAG_ERROR,
                        OK,
                        REJECTED,
                        DID_NOT_FIND_END,
                        NO_FLAG};

enum Message_Reply_Flag_Data{FLAG_DATA_ERROR,
                             AGAIN,
                             BAD_AXIS,
                             BAD_COMMAND,
                             BAD_DATA,
                             BAD_MESSAGE_ID,
                             DEVICE_ONLY,
                             NO_ACCESS,
                             PARKED,
                             STATUS_BUSY,
                             NO_FLAG_DATA};

enum Message_Reply_Warning_Flag{WARNING_FLAG_ERROR,
                                DRIVER_DISABLED,
                                ENCODER_ERROR,
                                STALLED,
                                LIMIT_ERROR,
                                NOT_HOMED,
                                UNEXPECTED_LIMIT_TRIG,
                                INVALID_CALIBRATION,
                                VOLTAGE_ERROR,
                                TEMPERATURE_ERROR,
                                UNEXPECTED_DISPLACEMENT,
                                NO_REFERENCE_POSITION,
                                BUSY_WITH_MANUAL_CONTRL,
                                COMMAND_INTERRUPTED,
                                UPDATE_OR_RESET_PENDING,
                                NO_WARNING_FLAG};


class Message
{
public:

    Message();
    Message(const QString &replyMessage);
    Message(const Message_Type type);
    Message(const Message_Type type, const Device_Number dn, const Axis_Number an);

    Message(const Device_Number dn, const Axis_Number an);

    Device_Number getDeviceNumber() const;
    void setDeviceNumber(const Device_Number deviceNumber);

    Axis_Number getAxisNumber() const;
    void setAxisNumber(const Axis_Number number);

    Message_Mode getMode() const;
    void setMode(const Message_Mode mode);

    Message_Task getTask() const;
    void setTask(const Message_Task task);

    Message_Status getStatus() const;
    void setStatus(const Message_Status status);

    float getPosition_mm() const;
    void setPosition_mm(const float position_mm);

    int getPosition_ms() const;
    void setPosition_ms(const float mm);

    int getSpeed() const;
    void setSpeed(const int speed);

    int getPower() const;
    void setPower(const int power);

    QString getCommandStr() const;
    void composeCommandStr();

    float getUStepPerMM() const;
    void setUStepPerMM(const float uStepPerMM);

    Message_Type getMessageType() const;
    void setMessageType(const Message_Type type);

    Message_Reply_Flag getReplyFlag() const;
    void setReplyFlag(const Message_Reply_Flag replyFlag);

    Message_Reply_Flag_Data getRepyFlagData() const;
    void setRepyFlagData(const Message_Reply_Flag_Data repyFlagData);


    Message_Reply_Warning_Flag getReplyWarningFlag() const;
    void setReplyWarningFlag(const Message_Reply_Warning_Flag replyWarningFlag);

    QString getReplyStr() const;
    Message_Reply_Flag decomposeReplyStr(const QString &rplystr);

private:
    Message_Type m_messageType;
    Device_Number m_deviceNumber;
    Axis_Number m_axisNumber;

    Message_Reply_Flag m_replyFlag;
    Message_Reply_Flag_Data m_repyFlagData;
    Message_Reply_Warning_Flag m_replyWarningFlag;

    Message_Mode m_mode;
    Message_Task m_task;
    Message_Status m_status;

    QString m_commandString;
    QString m_replyString;

    float m_uStepPerMM;
    float m_position_mm;
    int m_position_ms;
    int m_speed;
    int m_power;
};


/////////////////////////////////// END BLOCKIO BASE TYPES AND ENUMERATIONS ///////////////////////////


////////////////////////////////////////// BEGIN BLOCK CLASS //////////////////////////////////////////
/// The Block class:
/// A Block represents a single line of G code.
/// General usage:
///     To make a block, use its constructor:
///
///         Block(const QString toParse, machine_settings_t *settings)
///
///     Blocks are usually made from a file and assembled into Layers and then a Part using the methods of
///     the Part class     
///
///   Inputs:
///    From constructor:
///     QString toParse - a line of Gcode
///     machine_settings_t *settings - a pointer to the machine settings
///
///   Outputs:
///     Qstring m_com_err - any comments present in the G code or errors generated when making the bloc
///     Code code() - a G code
///     bool newLayerFlag() - set high when the parser finds a "(NEW_LAYER)" comment
///     bool isBlockValid() - set high if no errors encountered
///     MD_Package *materialDelivery() - a pointer to the package of messages for the material delivery system
///     LG_Package *laserGalvo() - a pointer to the package of messages for the laser-galvo system
///
///
class Block
{
public:
    Block();
    Block(const QString &toParse, const Message_Mode previousMode, machine_settings_t *settings);

    Message *L_Axis();
    Message *X_Axis();
    Message *Y_Axis();
    Message *Z_Axis();
    Message *A_Axis();
    Message *B_Axis();

    float getDwell() const;
    void setDwell(const float dwell);

    Code getCode() const;
    void setCode(const Code code);

    QString getComments() const;
    void setComments(const QString &comments);

    QString getErrors() const;
    void setErrors(const QString &errors);

    bool isNewLayer() const;
    void setNewLayer(const bool newLayer);

    bool isBlockValid() const;
    void setBlockValid(const bool blockValid);

    Message_Mode getPreviousMode() const;
    void setPreviousMode(const Message_Mode previousMode);

private:
    Message m_L_Axis;
    Message m_X_Axis;
    Message m_Y_Axis;
    Message m_Z_Axis;
    Message m_A_Axis;
    Message m_B_Axis;

    float m_dwell;

    Code m_code;

    Message_Mode m_previousMode;

    QString m_comments;
    QString m_errors;

    bool m_newLayer;

    bool m_blockValid;

    void makeBlock(const QString &toParse, const Message_Mode previousMode, machine_settings_t *settings);
};
////////////////////////////////////////// END BLOCK CLASS //////////////////////////////////////////

////////////////////////////////////////// BEGIN LAYER CLASS //////////////////////////////////////////
////// The Layer class:
/// A Layer is a collection of blocks used by the Part class to represent the G code file.
/// General usage:
///     To make a Layer, use its constructor:
///
///         Layer(QVector <Block> someBlocks)
///
///   Inputs:
///     void addBlock(Block aBlock) - add a block to the layer
///     void clearLayer() - remove the blocks in the layer
///
///   Outputs:
///     bool validateLayer() - true if all blocks are valid
///     QVector<Block> get() const - returns the full layer
///     Block getBlock(int blockNumber) const - returns a block at the index blockNumber
///
class Layer
{
public:
    Layer();
    Layer(const QVector<Block> &someBlocks);

    QVector<Block> get() const;
    Block getBlock(const int blockNumber) const;

    void addBlock(const Block &aBlock);
    bool isLayerValid() const;
    void setLayerValid(const bool layerValid);
    bool validateLayer();
    void clearLayer();

private:
    bool m_layerValid;
    QVector <Block> m_layer;

};
////////////////////////////////////////// END LAYER CLASS //////////////////////////////////////////

////////////////////////////////////////// BEGIN PART CLASS //////////////////////////////////////////
////// The Part class:
/// A Part is the top level object of our G code representation.
/// A part is a vector of Layers.
/// A Layer is a vector of Blocks.
///
/// General usage:
///     To make a Part, use its constructor:
///
///             Part(QString fileName, machine_settings_t *settings);
///
///   Inputs:
///    From constructor:
///         QString fileName - name/directory of the file to open and parse
///         machine_settings_t *settings - a pointer to the machine settings
///
///     void addLayer(Layer aLayer) - add a Layer to the Part
///
///   Outputs:
///     QVector<Layer> get() const - returns the full part
///     Layer getLayer(int layerNumber) const - returns a layer
///     Block getBlock(int LayerNumber, int blockNumber) - returns a block
///     bool isPartValid() const - true if no errors were found
///     QStringList debugPart(bool errorOnly) - generates a formatted output
///                        for each Layer/Block/message_t that contains data
///
class Part
{
public:
    Part(QString &fileName, machine_settings_t *settings);

    void addLayer(const Layer &aLayer);
    QVector<Layer> get() const;
    Layer getLayer(const int layerNumber) const;
    Block getBlock(const int LayerNumber, const int blockNumber);
    bool isPartValid() const;
    void validatePart();
    QString displayAxis(const QChar axisTitle, const Message axis);
    QString displayBlock( Block &aBlock, const bool errorOnly);
    QStringList debugPart(const bool errorOnly);

private:
    bool m_partValid;
    QString m_fileName;
    machine_settings_t *m_settings;
    QVector <Layer> m_part;
    void makePart();    /// used by constructor

};
////////////////////////////////////////// END PART CLASS //////////////////////////////////////////

}

#endif
