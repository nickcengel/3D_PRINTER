#ifndef BLOCK_h
#define BLOCK_h

#include <string>
#include <vector>
#include <iostream>

using std::vector;
using std::string;

// returns true if stringNum is a valid float
bool validNumber(string stringNumIn, float *floatNumOut);

// A "BLOCK" will represent a single line of GCODE. It serves as a intermediary data structure
// between the GCODE file and the GCODE interpreter.
// Each BLOCK is filled by passing it a string that contains a single line from a GCODE document.
// A BLOCK by default contains variables for holding all messages that can be sent to the machine
// from a GCODE file. A "pending" flag is used to indicate that the data of a particular variable is
// changed by the current instance of BLOCK.

class BLOCK{
public:
    // The BLOCK class contains the following enumerations:
    
    // CODE_t : lists the accepted commands:
    //      M0 - PROGRAM PAUSE
    //      M2 - END PROGRAM
    //      M3 - TURN LASER ON
    //      M5 - TURN LASER OFF
    //      G0 - RAPID MOVE
    //      G1 - LINEAR MOVE
    //      G4 - DWELL
    //      G28 - HOME AXIS
    enum CODE_t {NO_CODE, M0, M2, M3, M5, G0, G1, G4, G28};
    
    // AXIS_t :  lists the supported axis:
    //      X_AXIS - X coordinate of laser scanner
    //      Y_AXIS - Y coordinate of laser scanner
    //      Z_AXIS - Z coordinate of the build plate
    //      A_AXIS - Z coordinate of the hopper plate
    //      B_AXIS - X coordinate of wiper blade assembly
    enum AXIS_t {NO_AXIS, X_AXIS, Y_AXIS, Z_AXIS, A_AXIS, B_AXIS};
    
    // When a BLOCK is create from reading in a line of GCODE it populates the collection of struts below.
    // Each struct contains a grouping of data along with a "pending" flag. This flag indicates that the
    // corresponding line of GCODE has modified the respective data. This flag is used by the interpreter
    // in order to pick out the relevant changes represented by the BLOCK and ignore the rest.
    
    // A CODE_COMMAND holds one of the commands enumaerated by CODE_t
    // Commands are cannonical, meaning a valid block can contain only one of these commands
    struct CODE_COMMAND {
        CODE_t code;
        bool pending;
    };
    
    // A numerical value, grouped with its pending flag, used by AXiS and LASER structs
    struct NUM_COMMAND {
        float value;
        bool pending;
    };
    // A boolean value, grouped with its pending flag, used by AXiS and LASER structs
    struct B_COMMAND {
        bool state;
        bool pending;
    };
    
    // Each of the machines axis are represented inside of a BLOCK using the AXIS struct.
    struct AXIS{
        AXIS_t axis; // which axis are we talking about?
        B_COMMAND status; // Enable or disable motor. Not currently used
        NUM_COMMAND coordinate; //  The absolute position of the axis
        NUM_COMMAND feed;   // The feedrate the axis is to use
        B_COMMAND goHome;   // This is set true and pending when a blcok contains G28 code and no position data
    };
    
    // Messages from the GCODE document relevant to the laser are represented using the LASER struct.
    struct LASER{
        B_COMMAND status;    // Enable or disable the laser
        NUM_COMMAND power;  // Set the laser power
    };
    
    // Comment strings, bracketed by '()' are represented as a COMMENT
    struct COMMENT {
        string text;
        bool pending;
    };
    
    // Contains the single cannonical command
    CODE_COMMAND command;
    
    // Contains the data for each of the 5 axis
    AXIS x_axis;
    AXIS y_axis;
    AXIS z_axis;
    AXIS a_axis;
    AXIS b_axis;
    
    // Contains the data for the laser
    LASER laser;
    
    // contains gcode comments
    COMMENT comment;
    
    // Contains the period of time to delay or "dwell"
    // A dwell can be initiated in two ways
    //  (1) As an isolate command: G4/'dwelltime' // not implemented
    //  (2) As a portion of another command using the P parameter: .... P'dwelltime'
    NUM_COMMAND dwell;
    
    
public:
    // Default constructor creates an empty BLOCK with no data and all pending flags false
    BLOCK();
    // Constructor automatically populates BLOCK with the data from string toParse_
    BLOCK(string toParse_);
    
    // Setters for populating a BLOCK
    // values are public variables and can be accessed by the interpretor using the dot operator
    void setCode(CODE_t code_);
    void setDwell(float time_);
    
    void setLaserState(bool state_);
    void setLaserPower(float power_);
    
    void setState_x(bool state_);
    void setState_y(bool state_);
    void setState_z(bool state_);
    void setState_a(bool state_);
    void setState_b(bool state_);
    
    void setPosition_x(float cord_);
    void setPosition_y(float cord_);
    void setPosition_z(float cord_);
    void setPosition_a(float cord_);
    void setPosition_b(float cord_);
    
    void setFeed_x(float feedrate_);
    void setFeed_y(float feedrate_);
    void setFeed_z(float feedrate_);
    void setFeed_a(float feedrate_);
    void setFeed_b(float feedrate_);
    
    void setGoHome_x();
    void setGoHome_y();
    void setGoHome_z();
    void setGoHome_a();
    void setGoHome_b();

    // Initizing a BLOCK sets all data and pending values to 0
    void initializeBlock();
    
    // Methods for debugging a block. Prints block data and error messages
    void printAxis(AXIS a);
    void printBlock();
private:
    // The makeBlock method populates a BLOCK with the data from the passed string.
    // This method does the work of parsing a line of GCODE into usable information.
    // See .cpp file for further documentation
    void makeBlock(string lineToParse_);
    
    vector<string> errors;
};

#endif
