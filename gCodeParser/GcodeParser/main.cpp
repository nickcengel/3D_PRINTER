#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <fstream>
#include <vector>

#include "BLOCK.h"
#include "rs232/rs232.h"
#include "ZBR.h"


using namespace std;


int main() {
    
//// Print out list of ports
//    int numPorts = comEnumerate();
//    cout<<"number of Ports: "<<numPorts<<endl;
//    for(int i = 0; i < numPorts; i++){
//        cout<<"Port_"<<i<<": "<<comGetInternalName(i)<<endl;
//    }
//
//// Create Zaber controller object
//    const char * buildPlatePortName = "/dev/tty.blah";
//    int buildPlatePortIndex = comFindPort(buildPlatePortName);
//    int buildPlateDeviceNum = 1;
//    ZBR BuildPlate(buildPlateDeviceNum, buildPlatePortIndex, 9600);
//    ZBR::param_t settings = {1,-1,10,1,1};
//    BuildPlate.setup(settings);
//    BuildPlate.goHome();
//
//
//
//
//
// OPEN GCODE FILE
    ifstream in;    // Create an input file stream.
    in.open("/Users/nickengel/Documents/github/3D_PRINTER/GcodeParser/GcodeParser/Body1.txt");
    if (!in){
        cout << "Error: Can't open the file\n";
    }
// READ IN LINES
    vector<string> lines;
    while (in){  // Continue if the line was sucessfully read.
        string oneLine;
        getline(in,oneLine);   // Try to get another line.
        if(oneLine.size()>1)
            lines.push_back(oneLine);   // Add line to vector of lines
    }
// CREATE "BLOCKs" from Lines
     vector<BLOCK> block;
     for(uint32_t i = 0; i < lines.size()-1; i++){
       block.push_back(BLOCK(lines[i]));
     }
    
//    BLOCK myblock("(This is a comment to test the comments!) G1 X-2 Y2 Z3 A-3 B4 F6 S7 E9");
//
    for(uint32_t i = 0; i < block.size(); i++){
        block[i].printBlock();
    }
    
}   // END MAIN
