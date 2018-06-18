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
///     (BLOCKIO::) Part::Layer::Block::message
///
///        Where: a Part is a collection of Layers,
///               a Layer is a collection Blocks,
///               a Block contains messages and meta information, and
///               a message represents the possible tasks a G code line can request of our system
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
enum AxisTitle{X,Y,Z,A,B};

/// An Axis' physical and electrical constraints
struct axis_settings_t
{
    int portNumber;
    int deviceNumber;
    AxisTitle axisTitle;
    float positionMin;
    float positionMax;
    float speedMin;
    float speedMax;
    float homeOffset;
    axis_settings_t() {}
    axis_settings_t(int aPortNumber, int aDeviceNumber, AxisTitle anAxisTitle,
                    float aPositionMin, float aPositionMax, float aSpeedMin,
                    float aSpeedMax, float aHomeOffset){
        portNumber = aPortNumber;
        deviceNumber = aDeviceNumber;
        axisTitle = anAxisTitle;
        positionMin = aPositionMin;
        positionMax = aPositionMax;
        speedMin = aSpeedMin;
        speedMax = aSpeedMax;
        homeOffset = aHomeOffset;
    }
};

/// A group of axis settings with other machine parameters
struct machine_settings_t
{
    axis_settings_t x_settings;
    axis_settings_t y_settings;
    axis_settings_t z_settings;
    axis_settings_t a_settings;
    axis_settings_t b_settings;

    machine_settings_t() {}
    machine_settings_t(axis_settings_t X_settings, axis_settings_t Y_settings,
                       axis_settings_t Z_settings, axis_settings_t A_settings,
                       axis_settings_t B_settings){
        x_settings = X_settings;
        y_settings = Y_settings;
        z_settings = Z_settings;
        a_settings = A_settings;
        b_settings = B_settings;
    }
};

/// message_t : A task grouped with one or more data values
///// a seneder of a message will set the task value in order to encode the type of task.
///// a receiever of a message_t will read the task value in order to interpret the data value.
///// The receiver must know the identity of the sender, as a message does not contain this info.
/// TaskMap - Lists the recognized tasks
///   [0] NONE : default value
///
///   [1] POSITION : data[0] -> change in position
///
///   [2] POSITION_SPEED : data[0] -> change in position, data[1] -> change in speed
///
///   [3] HOME : if(data[0] != 0) -> go Home
///
///   [4] RELATIVE : if(data[0] != 0) -> future positions are relative moves,
///                  else if(data[0] == 0) -> Absolute mode
///
///   [5] ENABLE : if(data[0] != 0) -> enable device,
///                else if(data[0] == 0) -> disable device
///
///   [6] ENABLE_POWER : data[0] -> enable/disable *Laser*, data[1] -> laser power
///
///   [7] POWER : data[0] -> laser power
///
///   [8] DWELL : data[0] -> delay time
///
enum TaskMap{NONE, POSITION, POSITION_SPEED, HOME, RELATIVE, ENABLE, ENABLE_POWER, POWER, DWELL};
struct message_t
{
    TaskMap map;    /// what to do
    float data0;  /// how to do it
    float data1;  /// how to do it
    /// constructors
    message_t() : map(NONE), data0(0), data1(0) {}
    message_t(TaskMap aMap, float d0, float d1)
    {
        map = aMap;
        data0 = d0;
        data1 = d1;
    }
    message_t(TaskMap aMap, float d0)
    {
        map = aMap;
        data0 = d0;
    }
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
///    Overloaded setters:
///         void set_{x,y,z,a,b}_axis(const message_t &myMessageToAnAxis)
///         void set_{x,y,z,a,b}_axis(const TaskMap m, const float d0);
///         void set_{x,y,z,a,b}_axis(const TaskMap m, const float d0, const float d1);
///
///   Outputs:
///     Qstring m_com_err - any comments present in the G code or errors generated when making the block
///     message_t {x,y,z,a,b}_axis() - instructions relevant to the {x,y,z,a,b} axis
///     message_t laser() - instructions relevant to the laser
///     message_t dwel()l - a dwell instruction
///     Code code() - a G code
///     bool newLayerFlag() - set high when the parser finds a "(NEW_LAYER)" comment
///     bool isBlockValid() - set high if no errors encountered
///
class Block{
public:
    Block();
    Block(const QString toParse, machine_settings_t *settings);

    message_t x_axis() const;
    void set_x_axis(const message_t &x_axis);
    void set_x_axis(const TaskMap m, const float d0);
    void set_x_axis(const TaskMap m, const float d0, const float d1);

    message_t y_axis() const;
    void set_y_axis(const message_t &y_axis);
    void set_y_axis(const TaskMap m, const float d0);
    void set_y_axis(const TaskMap m, const float d0, const float d1);

    message_t z_axis() const;
    void set_z_axis(const message_t &z_axis);
    void set_z_axis(const TaskMap m, const float d0);
    void set_z_axis(const TaskMap m, const float d0, const float d1);

    message_t a_axis() const;
    void set_a_axis(const message_t &a_axis);
    void set_a_axis(const TaskMap m, const float d0);
    void set_a_axis(const TaskMap m, const float d0, const float d1);

    message_t b_axis() const;
    void set_b_axis(const message_t &b_axis);
    void set_b_axis(const TaskMap m, const float d0);
    void set_b_axis(const TaskMap m, const float d0, const float d1);

    message_t laser() const;
    void set_laser(const message_t &laser);
    void set_laser(const TaskMap m, const float d0);
    void set_laser(const TaskMap m, const float d0, const float d1);

    message_t dwell() const;
    void set_dwell(const message_t &dwell);
    void set_dwell(const TaskMap m, const float d0);
    void set_dwell(const TaskMap m, const float d0, const float d1);

    bool newLayerFlag() const;
    void setNewLayer(bool flag);

    bool isBlockValid() const;
    void setBlockValid(bool valid);

    Code code() const;
    void setCode(const Code &code);

    QString com_err() const;
    void set_com_err(const QString &com_err);

private:
    QString m_com_err;
    message_t m_x_axis;
    message_t m_y_axis;
    message_t m_z_axis;
    message_t m_a_axis;
    message_t m_b_axis;
    message_t m_laser;
    message_t m_dwell;
    Code m_code;
    bool m_newLayer;
    bool m_blockValid;
    void makeBlock(const QString toParse, machine_settings_t *settings);

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
    Layer(QVector <Block> someBlocks);

    QVector<Block> get() const;
    Block getBlock(int blockNumber) const;

    void addBlock(Block aBlock);
    bool isLayerValid() const;
    void setLayerValid(bool layerValid);
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
    Part(QString fileName, machine_settings_t *settings);

    void addLayer(Layer aLayer);
    QVector<Layer> get() const;
    Layer getLayer(int layerNumber) const;
    Block getBlock(int LayerNumber, int blockNumber);
    bool isPartValid() const;
    void validatePart();
    QString displayAxis(QChar axisTitle, message_t axis);
    QString displayBlock(Block aBlock, bool errorOnly);
    QStringList debugPart(bool errorOnly);

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
