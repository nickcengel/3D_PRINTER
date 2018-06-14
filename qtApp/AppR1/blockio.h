#ifndef BLOCKIO_H
#define BLOCKIO_H

#include <QTextStream>
#include <QDebug>
#include <qfiledialog.h>
#include <QString>
#include <QStringList>

// A "BLOCK" will represent a single line of GCODE. It serves as a intermediary data structure
// between the GCODE file and the GCODE interpreter.
// Each Block is filled by passing it a string that contains a single line from a GCODE document.
// A Block by default contains variables for holding all messages that can be sent to the machine
// from a GCODE file. A "pending" flag is used to indicate that the data of a particular variable is
// changed by the current instance of Block.

namespace BlockIO {

// Codes : lists the accepted commands:
//      M0 - PROGRAM PAUSE
//      M2 - END PROGRAM
//      M3 - TURN LASER ON
//      M5 - TURN LASER OFF
//      G0 - RAPID MOVE
//      G1 - LINEAR MOVE
//      G4 - DWELL
//      G28 - HOME AXIS
//      G90 - ABSOLUTE POSITIONING
//      G91 - RELATIVE POSITIONING
enum Code {NO_CODE, M0, M2, M3, M5, G0, G1, G4, G28, G90, G91};

// AxisTitle :  lists the supported axis:
enum AxisTitle{X,Y,Z,A,B};


// When a BLOCK is create from reading in a line of GCODE it populates the collection of struts below.
// Each struct contains a grouping of data along with a "pending" flag. This flag indicates that the
// corresponding line of GCODE has modified the respective data. This flag is used by the interpreter
// in order to pick out the relevant changes represented by the BLOCK and ignore the rest.

// A CODE_COMMAND holds one of the commands enumaerated by CODE_t
// Commands are cannonical, meaning a valid block can contain only one of these commands
struct code_t {
    Code code;
    bool pending;
};

// A numerical value, grouped with its pending flag, used by AXiS and LASER structs
struct num_t {
    float value;
    bool pending;
};
// A boolean value, grouped with its pending flag, used by AXSS and LASER structs
struct bin_t {
    bool state;
    bool pending;
};

// Each of the machines axis are represented inside of a BLOCK using the AXIS struct.
struct axis_t{
    AxisTitle axis; // which axis are we talking about?
    bin_t enabled; // Enable or disable motor. Not currently used
    num_t position; //  The absolute position of the axis
    num_t speed;   // The speed the axis is to use
    bin_t goHome;   // This is set true and pending when a blcok contains G28 code and no position data
};

// Messages from the GCODE document relevant to the laser are represented using the laser_t struct.
struct laser_t{
    bin_t enabled;    // Enable or disable the laser
    num_t power;  // Set the laser power
};


class Block{
public:
    // Default constructor creates an empty Block with no data and all pending flags false
    Block();
    // Constructor automatically populates Block with the data from string toParse_
    Block(const QString toParse, const int lineNumber, const int layerNumber);

    // Setters for populating a Block
    // values are public variables and can be accessed by the interpretor using the dot operator

    void setCode(const Code code);
    void setDwell(const float time);

    void setLaserState(const bool enable);
    void setLaserPower(const float power);

    void setState_x(const bool enable);
    void setState_y(const bool enable);
    void setState_z(const bool enable);
    void setState_a(const bool enable);
    void setState_b(const bool enable);

    void setPosition_x(const float x);
    void setPosition_y(const float y);
    void setPosition_z(const float z);
    void setPosition_a(const float a);
    void setPosition_b(const float b);

    void setSpeed_x(const float sx);
    void setSpeed_y(const float sy);
    void setSpeed_z(const float sz);
    void setSpeed_a(const float sa);
    void setSpeed_b(const float sb);

    void setGoHome_x();
    void setGoHome_y();
    void setGoHome_z();
    void setGoHome_a();
    void setGoHome_b();

    bool newLayerFlag();

    // Methods for debugging a block. Prints block data and error messages
    QString printAxis(axis_t a);
    QStringList printBlock();

private:
    // Contains the single cannonical command
    int m_lineNumber;
    int m_layerNumber;
    bool m_newLayerFlag;
    code_t m_command;

    // Contains the data for each of the 5 axis
    axis_t m_x_axis;
    axis_t m_y_axis;
    axis_t m_z_axis;
    axis_t m_a_axis;
    axis_t m_b_axis;

    // Contains the data for the laser
    laser_t m_laser;

    // contains gcode comments
    QString m_comment;

    // Contains the period of time to delay or "dwell"
    // A dwell can be initiated in two ways
    //  (1) As an isolate command: G4/'dwelltime' // not implemented
    //  (2) As a portion of another command using the P parameter: .... P'dwelltime'
    num_t m_dwell;

    // Put error messages here
    QStringList m_errors;

    // Initizing a Block sets all data and pending values to 0
    // The makeBlock method populates a Block with the data from the passed string.
    // This method does the work of parsing a line of GCODE into usable information.
    // See .cpp file for further documentation
    void initializeBlock(int lineNumber, int layerNumber);
    void makeBlock(const QString toParse);
};


typedef QVector<Block> layer_t;

QVector<layer_t> convertGcode(QString fileName);



}

#endif
