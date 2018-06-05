
#include "BLOCK.h"

#include <sstream>
#include <vector>

using namespace std;

bool validNumber(string stringNum, float *num){
    int sign = 1;
    bool anumber = false;
    for (int i = 0; i < stringNum.length(); i++) {
        if(stringNum[i] == '.'||stringNum[i]==' ')
            continue;
        else if(stringNum[i]=='-'){
            sign = -1;
            stringNum[i] = '0';
        }
        else if((stringNum[i] < '0')||(stringNum[i] > '9')){
            anumber = false;
            return anumber;
        }
    }
    anumber = true;
    *num = sign*stof(stringNum);
    return anumber;
}



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

void BLOCK::setState_x(bool state_){
    x_axis.status.state = state_;
    x_axis.status.pending = 1;
}

void BLOCK::setState_y(bool state_){
    y_axis.status.state = state_;
    y_axis.status.pending = 1;
}

void BLOCK::setState_z(bool state_){
    z_axis.status.state = state_;
    z_axis.status.pending = 1;
}

void BLOCK::setState_a(bool state_){
    a_axis.status.state = state_;
    a_axis.status.pending = 1;
}

void BLOCK::setState_b(bool state_){
    b_axis.status.state = state_;
    b_axis.status.pending = 1;
}

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

void BLOCK::setGoHome_x(){
    x_axis.goHome.state = 1;
    x_axis.goHome.pending = 1;
};
void BLOCK::setGoHome_y(){
    y_axis.goHome.state = 1;
    y_axis.goHome.pending = 1;
};
void BLOCK::setGoHome_z(){
    z_axis.goHome.state = 1;
    z_axis.goHome.pending = 1;
};
void BLOCK::setGoHome_a(){
    a_axis.goHome.state = 1;
    a_axis.goHome.pending = 1;
};
void BLOCK::setGoHome_b(){
    b_axis.goHome.state = 1;
    b_axis.goHome.pending = 1;
};

void BLOCK::setDwell(float time_){
    dwell.value = time_;
    dwell.pending = 1;
};

void BLOCK::setLaserPower(float power_){
    laser.power.value = power_;
    laser.power.pending = 1;
};
void BLOCK::setLaserState(bool state_){
    laser.status.state = state_;
    laser.status.pending = 1;
}

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
    x_axis.status.pending = 0;
    x_axis.coordinate.pending = 0;
    x_axis.feed.pending = 0;
    x_axis.goHome.pending = 0;
    
    y_axis.axis = Y_AXIS;
    y_axis.status.pending = 0;
    y_axis.coordinate.pending = 0;
    y_axis.feed.pending = 0;
    y_axis.goHome.pending = 0;
    
    
    z_axis.axis = Z_AXIS;
    z_axis.status.pending = 0;
    z_axis.coordinate.pending = 0;
    z_axis.feed.pending = 0;
    z_axis.goHome.pending = 0;
    
    
    a_axis.axis = A_AXIS;
    a_axis.status.pending = 0;
    a_axis.coordinate.pending = 0;
    a_axis.feed.pending = 0;
    a_axis.goHome.pending = 0;
    
    
    b_axis.axis = B_AXIS;
    b_axis.status.pending = 0;
    b_axis.coordinate.pending = 0;
    b_axis.feed.pending = 0;
    b_axis.goHome.pending = 0;
    
    
    laser.status.pending = 0;
    laser.power.pending = 0;
    
    dwell.pending = 0;
    comment.pending = 0;
};

void BLOCK::printAxis(AXIS a){
    if(a.goHome.pending||a.coordinate.pending){
        switch (a.axis) {
            case X_AXIS:
                cout<<"X Axis ";
                break;
            case Y_AXIS:
                cout<<"Y Axis";
                break;
            case Z_AXIS:
                cout<<"Z Axis";
                break;
            case A_AXIS:
                cout<<"A Axis";
                break;
            case B_AXIS:
                cout<<"B Axis";
                break;
            default:
                break;
        }
        if(a.goHome.pending)
            cout<<" goes home\n";
        else if(a.coordinate.pending){
            cout<<" moves to "<<a.coordinate.value;
            if(a.feed.pending)
                cout<<" at a speed of "<<a.feed.value<<"\n";
            else
                cout<<"\n";
        }
    }
}

void BLOCK::printBlock(){
    if (comment.pending)
        cout<<"Comment: "<<comment.text<<"\n";
    
    if(command.pending){
        cout<<"Command: ";
        switch (command.code) {
            case M0:
                cout<<"M0 - PAUSE\n";
                break;
            case M2:
                cout<<"M2 - END\n";
                break;
            case M3:
                cout<<"M3 - LASER ON\n";
                break;
            case M5:
                cout<<"M5 - LASER OFF\n";
                break;
            case G0:
                cout<<"G0 - RAPID MOVE\n";
                break;
            case G1:
                cout<<"G1 - LINEAR MOVE\n";
                break;
            case G4:
                cout<<"G4 - DWELL\n";
                break;
            case G28:
                cout<<"G28 - HOME\n";
                break;
            default:
                cout<<"unknown";
                break;
        }
    }
    printAxis(x_axis);
    printAxis(y_axis);
    printAxis(z_axis);
    printAxis(a_axis);
    printAxis(b_axis);
    
    if (laser.status.pending) {
        cout<<"Laser is ";
        if (laser.status.state) {
            cout<<"on. ";
            if (laser.power.pending)
                cout<<"Laser power = "<<laser.power.value<<"\n";
            else
                cout<<"\n";
        }
        else
            cout<<"off.\n";
    }
    
    if(dwell.pending){
        cout<<"delay for "<<dwell.value<<"\n";
    }
    if(errors.size() > 0){
        cout<<"\nErrors:\n";
        for (int i = 0; i < errors.size(); i++) {
            cout<<errors[i];
        }
    }
    cout<<endl;
}




//  The makeBlock method is the heart of the GCODE Parser. It fills a Block with the data from a single line
//  * NOTE: We require spaces between items, but not between the item and the value itself.
//      GOOD: G0 X1 Y1.42 Z4.0 (comments look like this)
//      BAD: G0X1Y1.42Z4.0 comments all over the place
//      ALSO BAD: G0 X 1 Y 1.42 Z 4.0 *//
void BLOCK::makeBlock(string lineToParse_){
    string line = lineToParse_;
    
    // Handle comments
    std::size_t startComment = line.find("(");
    if(startComment != std::string::npos){
        std::size_t endComment = line.find(")");
        if ((endComment != std::string::npos)){
            comment.text = line.substr(startComment+1,endComment-startComment-1);
            comment.pending = true;
            line.erase(startComment,endComment-startComment+1);
        }
        else
            errors.push_back("Could not find end of comment.\n");
    }
    
    
    // For safety, begin with the laser turned off for each block
    setLaserState(false);
    // and fill the resulting vector, "words" with these elements
    
    // Seperate incoming line into elements using a space delimeter
    // fill the resulting vector, "words" with these elements
    
    std::istringstream iss(line);
    vector<string> words((istream_iterator<string>(iss)),
                         istream_iterator<string>());
    
    // CREATE BLOCK from a line by iterating through each element in "words"
    // A word is a chunck of a line seperated by spaces
    for(uint32_t i = 0; i < words.size(); i++){
        
        string aWord = words[i];    // current word to be analyzed
        float aValue;
        
        //  First we look at the first character in the word.
        switch (aWord[0]) {
                // If we find G or M, we have a code command
            case 'G':
                // So setCode with matching enumerated code
                if(aWord == "G0") // RAPID MOVE
                    setCode(G0);
                else if(aWord == "G1")  // LINEAR MOVE
                    setCode(G1);
                else if(aWord == "G4")  // DWELL (not currently implemented. Use P)
                    setCode(G4);
                else if(aWord == "G28") // HOME AXIS
                    setCode(G28);
                else
                    errors.push_back("Did not recognize instruction: \"G"+aWord+"\"\n");
                break;
            case 'M':
                // So setCode with matching enumerated code
                if(aWord == "M0")   // PAUSE
                    setCode(M0);
                else if(aWord == "M2")  //  END PROGRAM
                    setCode(M2);
                else if(aWord == "M3"){  // LASER ON
                    setCode(M3);
                    setLaserState(true);
                }
                else if(aWord == "M5"){  // LASER OFF
                    setCode(M5);
                    setLaserState(false);
                }
                else
                   errors.push_back("Did not recognize instruction: \"M"+aWord+"\"\n");
                break;
                
                // If the first character is X,Y,Z,A,or B, we are talking about an axis
            case 'X':
                aWord.erase(0,1);; // get rid of axis label
                // No position data means we want to return axis to home
                if((aWord[1] == '\0') && (command.code == G28))
                    setGoHome_x();
                // Otherwise check that a relevant command is requested and set new position
                // also check if the position is a valid number
                else if((validNumber(aWord, &aValue))&&((command.code == G0)||(command.code == G1))){
                    setPosition_x(aValue);
                }
                else
                    errors.push_back("Did not recognize instruction: \"X"+aWord+"\"\n");
                break;
                
            case 'Y':
                aWord.erase(0,1);
                if((aWord[1] == '\0') && (command.code == G28))
                    setGoHome_y();
                else if((validNumber(aWord, &aValue))&&((command.code == G0)||(command.code == G1))){
                    setPosition_y(aValue);
                }
                else
                    errors.push_back("Did not recognize instruction: \"Y"+aWord+"\"\n");
                break;
                
            case 'Z':
                aWord.erase(0,1);
                if((aWord[1] == '\0') && (command.code == G28))
                    setGoHome_z();
                else if((validNumber(aWord, &aValue))&&((command.code == G0)||(command.code == G1))){
                    setPosition_z(aValue);
                }
                else
                    errors.push_back("Did not recognize instruction: \"Z"+aWord+"\"\n");
                break;
                
            case 'A':
                aWord.erase(0,1);
                if((aWord[1] == '\0') && (command.code == G28))
                    setGoHome_a();
                else if((validNumber(aWord, &aValue))&&((command.code == G0)||(command.code == G1))){
                    setPosition_a(aValue);
                }
                else
                    errors.push_back("Did not recognize instruction: \"A"+aWord+"\"\n");
                break;
                
                
            case 'B':
                aWord.erase(0,1);
                if((aWord[1] == '\0') && (command.code == G28))
                    setGoHome_b();
                else if((validNumber(aWord, &aValue))&&((command.code == G0)||(command.code == G1))){
                    setPosition_b(aValue);
                }
                else
                    errors.push_back("Did not recognize instruction: \"B"+aWord+"\"\n");
                break;
                
                // E used to indicate the current movement corresponds to an active print command.
                // This follows from the extrusion printer convention. Where E is used to control
                // the amount of material extruded. In our cases, we simpply check if a line contains
                // 'E'. This means we should turn the laser on.
            case 'E':
                // But first, check that this line will in fact move the x/y axes.
                if((command.code == G1)&&(x_axis.coordinate.pending || y_axis.coordinate.pending))
                    setLaserState(true);    // This is equivalent to prefaicing a move with M3/M5
                break;
                
                // F used to modify feedrate. We only want to set the feedrate for an axis we intend
                // to move with this block, so check to see if each axis has a pending move.
            case 'F':
                aWord.erase(0,1);
                if(validNumber(aWord, &aValue)){
                    if(x_axis.coordinate.pending)
                        setFeed_x(aValue);
                    if(y_axis.coordinate.pending)
                        setFeed_y(aValue);
                    if(z_axis.coordinate.pending)
                        setFeed_z(aValue);
                    if(a_axis.coordinate.pending)
                        setFeed_a(aValue);
                    if(b_axis.coordinate.pending)
                        setFeed_b(aValue);
                }
                else
                    errors.push_back("Did not recognize instruction: \"F"+aWord+"\"\n");
                break;
            
                // P signals a dwell time is to be set and observed.
            case 'P':
                aWord.erase(0,1);
                if(validNumber(aWord, &aValue))
                    setDwell(aValue);
                else
                    errors.push_back("Did not recognize instruction: \"P"+aWord+"\"\n");
                
                break;
                
                // S used to modify laser power.
            case 'S':
                aWord.erase(0,1);
                if(validNumber(aWord, &aValue))
                    setLaserPower(aValue);
                else
                    errors.push_back("Did not recognize instruction: \"S"+aWord+"\"\n");
                break;
                
            default:
                errors.push_back("Did not recognize instruction: \" ");
                errors.push_back(aWord);
                errors.push_back(" \" \n");
                break;
        } //end switch
    } // end line
};  // end makeBlock
