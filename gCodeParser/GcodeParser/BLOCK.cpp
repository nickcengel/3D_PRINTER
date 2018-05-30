
#include "BLOCK.h"

#include <sstream>
#include <vector>

using namespace std;

BLOCK::BLOCK(){
    initializeBlock();
};

BLOCK::BLOCK(string toParse_){
    initializeBlock();
    makeBlock(toParse_);
};

void BLOCK::setCode(CODE_t code_){
    command.code = code_;
    command.pending = 1;
};

void BLOCK::setPosition_x(float cord_){
    x_axis.coordinate.value = cord_;
    x_axis.coordinate.pending = 1;
};
void BLOCK::setPosition_y(float cord_){
    y_axis.coordinate.value = cord_;
    y_axis.coordinate.pending = 1;
};
void BLOCK::setPosition_z(float cord_){
    z_axis.coordinate.value = cord_;
    z_axis.coordinate.pending = 1;
};
void BLOCK::setPosition_a(float cord_){
    a_axis.coordinate.value = cord_;
    a_axis.coordinate.pending = 1;
};
void BLOCK::setPosition_b(float cord_){
    b_axis.coordinate.value = cord_;
    b_axis.coordinate.pending = 1;
};

void BLOCK::setDwell(float time_){
    dwell.value = time_;
    dwell.pending = 1;
};

void BLOCK::setLaserPower(float power_){
    laser.power.value = power_;
    laser.power.pending = 1;
};

void BLOCK::setFeed_x(float feedrate_){
    x_axis.feed.value = feedrate_;
    x_axis.feed.pending = 1;
};
void BLOCK::setFeed_y(float feedrate_){
    y_axis.feed.value = feedrate_;
    y_axis.feed.pending = 1;
};
void BLOCK::setFeed_z(float feedrate_){
    z_axis.feed.value = feedrate_;
    z_axis.feed.pending = 1;
};
void BLOCK::setFeed_a(float feedrate_){
    a_axis.feed.value = feedrate_;
    a_axis.feed.pending = 1;
};
void BLOCK::setFeed_b(float feedrate_){
    b_axis.feed.value = feedrate_;
    b_axis.feed.pending = 1;
};

void BLOCK::initializeBlock(){
    command.pending = 0;
    
    x_axis.axis = X_AXIS;
    x_axis.state.pending = 0;
    x_axis.coordinate.pending = 0;
    x_axis.feed.pending = 0;
    
    y_axis.axis = Y_AXIS;
    y_axis.state.pending = 0;
    y_axis.coordinate.pending = 0;
    y_axis.feed.pending = 0;
    
    z_axis.axis = Z_AXIS;
    z_axis.state.pending = 0;
    z_axis.coordinate.pending = 0;
    z_axis.feed.pending = 0;
    
    a_axis.axis = A_AXIS;
    a_axis.state.pending = 0;
    a_axis.coordinate.pending = 0;
    a_axis.feed.pending = 0;
    
    b_axis.axis = B_AXIS;
    b_axis.state.pending = 0;
    b_axis.coordinate.pending = 0;
    b_axis.feed.pending = 0;
    
    laser.state.pending = 0;
    laser.power.pending = 0;
    
    dwell.pending = 0;
    comment.pending = 0;
};

void BLOCK::makeBlock(string lineToParse_){
    // PARSE LINE TO WORDS //
    string lineToParse = lineToParse_;
    std::istringstream iss(lineToParse);
    vector<string> words((istream_iterator<string>(iss)),
                         istream_iterator<string>());
    
    // CREATE BLOCK from Line //
    for(uint32_t i = 0; i < words.size(); i++){
        string aWord = words[i];
        switch (aWord[0]) {
            case 'G':
                if(aWord == "G0")
                    setCode(G0);
                else if(aWord == "G1")
                    setCode(G1);
                else if(aWord == "G4")
                    setCode(G4);
                else if(aWord == "G28")
                    setCode(G28);
                break;
                
            case 'M':
                if(aWord == "M0")
                    setCode(M0);
                else if(aWord == "M2")
                    setCode(M2);
                else if(aWord == "M3")
                    setCode(M3);
                else if(aWord == "M5")
                    setCode(M5);
                break;
                
            case 'X':
                aWord[0] = '0';
                setPosition_x(stof(aWord));
                break;
                
            case 'Y':
                aWord[0] = '0';
                setPosition_y(stof(aWord));
                break;
                
            case 'Z':
                aWord[0] = '0';
                setPosition_z(stof(aWord));
                break;
                
            case 'A':
                aWord[0] = '0';
                setPosition_a(stof(aWord));
                break;
                
            case 'B':
                aWord[0] = '0';
                setPosition_b(stof(aWord));
                break;
                
            case 'F':
                aWord[0] = '0';
                if(x_axis.coordinate.pending)
                    setFeed_x(stof(aWord));
                if(y_axis.coordinate.pending)
                    setFeed_y(stof(aWord));
                if(z_axis.coordinate.pending)
                    setFeed_z(stof(aWord));
                if(a_axis.coordinate.pending)
                    setFeed_a(stof(aWord));
                if(b_axis.coordinate.pending)
                    setFeed_b(stof(aWord));
                break;
                
            case 'P':
                aWord[0] = '0';
                setDwell(stof(aWord));
                break;
                
            case 'S':
                aWord[0] = '0';
                setLaserPower(stof(aWord));
                break;
                
            default:
                break;
        } //end switch
    } // end line
};
