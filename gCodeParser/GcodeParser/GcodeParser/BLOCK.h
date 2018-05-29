#ifndef BLOCK_h
#define BLOCK_h

#include <string>
using std::string;

class BLOCK{
public:
    enum CODE_t {NO_CODE, M0, M2, M3, M5, G0, G1, G4, G28};
    enum AXIS_t {NO_AXIS, X_AXIS, Y_AXIS, Z_AXIS, A_AXIS, B_AXIS};
    
    struct CODE_COMMAND {
        CODE_t code;
        bool pending;
    };
    
    struct NUM_COMMAND {
        float value;
        bool pending;
    };
    
    struct B_COMMAND{
        bool state;
        bool pending;
    };
    
    struct AXIS{
        AXIS_t axis;
        B_COMMAND state;
        NUM_COMMAND coordinate;
        NUM_COMMAND feed;
    };
    
    struct LASER{
        B_COMMAND state;
        NUM_COMMAND power;
    };
    
    struct COMMENT {
        string text;
        bool pending;
    };
    
    CODE_COMMAND command;
    
    AXIS x_axis;
    AXIS y_axis;
    AXIS z_axis;
    AXIS a_axis;
    AXIS b_axis;
    
    LASER laser;
    
    COMMENT comment;
    
    NUM_COMMAND dwell;
    
public:
    BLOCK();
    BLOCK(string toParse_);
    
    void setCode(CODE_t code_);
    void setPosition_x(float cord_);
    void setPosition_y(float cord_);
    void setPosition_z(float cord_);
    void setPosition_a(float cord_);
    void setPosition_b(float cord_);
    void setDwell(float time_);
    void setLaserPower(float power_);
    void setFeed_x(float feedrate_);
    void setFeed_y(float feedrate_);
    void setFeed_z(float feedrate_);
    void setFeed_a(float feedrate_);
    void setFeed_b(float feedrate_);
    void initializeBlock();
    
private:
    void makeBlock(string lineToParse_);
};

#endif
