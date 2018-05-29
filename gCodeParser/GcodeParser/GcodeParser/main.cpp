#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <fstream>
#include <vector>
#include "BLOCK.h"
#include "ZaberController.h"


using namespace std;


int main() {
    ZaberController buildPlate(1);
    buildPlate.connectController("nameofPort",9600);
    buildPlate.goHome();
    buildPlate.getPosition();
    buildPlate.moveTo(4);
    buildPlate.read(ZaberController::zCommand::SET_DEVICE_MODE);
    buildPlate.set(ZaberController::zCommand::SET_HOLD_CURRENT, 5);
    buildPlate.stop();
    
    

// OPEN GCODE FILE //
    ifstream in;    // Create an input file stream.
    in.open("/Users/nickengel/Documents/github/3dPrinter/Parser/gpr-master/src/gcodetest.txt");
    if (!in){
        cout << "Error: Can't open the file\n";
    }
    
// READ IN LINES //
    vector<string> lines;
    while (in){  // Continue if the line was sucessfully read.
        string oneLine;
        getline(in,oneLine);   // Try to get another line.
        lines.push_back(oneLine);   // Add line to vector of lines
    }

// CREATE "BLOCKs" from Lines //
     vector<BLOCK> block;
     for(uint32_t i = 0; i < lines.size(); i++){
       block.push_back(BLOCK(lines[i]));
     }
    

    
    
}   // END MAIN
