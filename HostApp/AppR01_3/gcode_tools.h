#ifndef GCODE_TOOLS_H
#define GCODE_TOOLS_H

#include <QObject>
#include <QTextStream>
#include <QDebug>
#include <qfiledialog.h>
#include <QString>
#include <QStringList>
#include <QMetaType>

#include "hardware_drivers.h"

using namespace HARDWARE_NS;


namespace GCODE_BLOCK_NS {

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

enum CODE {NO_CODE, M0, M2, M3, M5, G0, G1, G4, G28, G90, G91};

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
///
///
class Block
{
public:
    Block();
    Block(const QString &toParse, const POSITION_MODE previousMode, machine_settings_t *settings);

    Laser_Galvo_Device *Laser_Galvo();
    Material_Delivery_Device *Plate();
    Material_Delivery_Device *Hopper();
    Material_Delivery_Device *Spreader();



    float getDwell() const;
    void setDwell(const float dwell);

    CODE getCode() const;
    void setCode(const CODE code);

    QString getComments() const;
    void setComments(const QString &comments);

    QString getErrors() const;
    void setErrors(const QString &errors);

    bool isNewLayer() const;
    void setNewLayer(const bool newLayer);

    bool isBlockValid() const;
    void setBlockValid(const bool blockValid);

    POSITION_MODE getPreviousMode() const;
    void setPreviousMode(const POSITION_MODE previousMode);

private:

    Laser_Galvo_Device m_laser_galvo;
    Material_Delivery_Device m_plate;
    Material_Delivery_Device m_hopper;
    Material_Delivery_Device m_spreader;

    float m_dwell;

    CODE m_code;

    POSITION_MODE m_previousMode;

    QString m_comments;
    QString m_errors;

    bool m_newLayer;

    bool m_blockValid;

    void makeBlock(const QString &toParse, const POSITION_MODE previousMode, machine_settings_t *settings);
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

    int getBlockCount();

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
    QString displayBlock( Block &aBlock, const bool errorOnly);
    QStringList debugPart(const bool errorOnly);

    int get_LayerCount();
    int get_BlockCount();
private:
    bool m_partValid;
    QString m_fileName;
    machine_settings_t *m_settings;
    QVector <Layer> m_part;
    int layerCount;
    int blockCount;
    void makePart();    /// used by constructor

};

////////////////////////////////////////// END PART CLASS //////////////////////////////////////////


}
//Q_DECLARE_METATYPE(GCODE_BLOCK_NS::Part);




#endif
