//
//  ZaberController.cpp
//  GcodeParser
//
//  Created by Nick Engel on 5/25/18.
//  Copyright © 2018 Nick Engel. All rights reserved.
//

#include "ZaberController.h"


ZaberController::ZaberController(char deviceNum){
    deviceNumber = deviceNum;
    status = zStatus::UNKNOWN;
};

int ZaberController::connectController(const char *port_name, uint16_t baudRate){
    return connect(&myPort, port_name, baudRate);
};


void ZaberController::decodeReply(const char *reply, reply_t *decodedReply){
    decodedReply->deviceNum = reply[0];
    decodedReply->instruction = reply[1];
    int data = 256^3 * reply[5] + 256^2 * reply[4] + 256 * reply[3] + reply[2];
    if(reply[5] > 127)
        data = data - 256^4;
    decodedReply->value = data;
}

ZaberController::zStatus ZaberController::pollStatus(zStatus endCondition){
    char tries = 0;
    memset(toWrite, 0, sizeof(toWrite));
    memset(received, 0, sizeof(received));
    drain(myPort);
    for(;;){
        toWrite[0] = deviceNumber;
        toWrite[1] = zCommand::RETURN_STATUS;
        send(myPort, toWrite, 6);
        
        receive(myPort, received, 6);
        reply_t reply;
        decodeReply(received, &reply);
        if((reply.value == !endCondition)&&(tries < 10)){
            nanosleep(&ts, NULL);
            status = zStatus::BUSY;
            tries++;
        }
        else{
            status = endCondition;
            break;
        }
    }
    return status;
}

int ZaberController::goHome(){
    memset(toWrite, 0, sizeof(toWrite));
    toWrite[0] = deviceNumber;
    toWrite[1] = zCommand::HOME;
    send(myPort, toWrite, 6);

    if(pollStatus(zStatus::IDLE) == zStatus::IDLE)
        return 0;
    else
        return -1;
}



void ZaberController::encode(int val, char *v){
    if(val < 0)
        val = 256^4 + val;
    v[5] = val / 256^3; // MSB
    val = val - 256^3 * v[3];
    v[4] = val / 256^2;
    val = val - 256^2 * v[2];
    v[3] = val / 256;
    val = val - 256 * v[1];
    v[2] = val; // LSB
}

int ZaberController::moveTo(int position){
    toWrite[0] = deviceNumber;
    toWrite[1] = zCommand::MOVE_ABSOLUTE;
    encode(position, toWrite);
    send(myPort, toWrite, 6);
    
    if(pollStatus(zStatus::IDLE) == zStatus::IDLE)
        return 0;
    else
        return -1;
}

int ZaberController::stop(){
    memset(toWrite, 0, sizeof(toWrite));
    toWrite[0] = deviceNumber;
    toWrite[1] = zCommand::STOP;
    send(myPort, toWrite, 6);
    if(pollStatus(zStatus::IDLE) == zStatus::IDLE)
        return 0;
    else
        return -1;
}

int ZaberController::getPosition(){
    memset(toWrite, 0, sizeof(toWrite));
    toWrite[0] = deviceNumber;
    toWrite[1] = zCommand::RETURN_SETTING;
    toWrite[2] = zCommand::SET_CURRENT_POSITION;
    send(myPort, toWrite, 6);
    
    reply_t reply;
    receive(myPort, received, 6);
    decodeReply(received, &reply);
    if((reply.deviceNum = deviceNumber)&&(reply.instruction == zCommand::SET_CURRENT_POSITION))
        return reply.value;
    else
        return SERIAL_ERROR_COULD_NOT_DECODE;
}

int ZaberController::set(zCommand reg, int val){
    drain(myPort);
    memset(toWrite, 0, sizeof(toWrite));
    memset(received, 0, sizeof(received));
    toWrite[0] = deviceNumber;
    toWrite[1] = reg;
    encode(val, toWrite);
    send(myPort, toWrite, 6);
    
    reply_t reply;
    receive(myPort, received, 6);
    decodeReply(received, &reply);
    if((reply.value = val)&&(reply.instruction == reg))
        return 0;
    else
        return SERIAL_ERROR_COULD_NOT_DECODE;
}

int ZaberController::read(zCommand reg){
    drain(myPort);
    memset(toWrite, 0, sizeof(toWrite));
    memset(received, 0, sizeof(received));
    toWrite[0] = deviceNumber;
    toWrite[1] = zCommand::RETURN_SETTING;
    toWrite[2] = reg;
    send(myPort, toWrite, 6);
    
    reply_t reply;
    receive(myPort, received, 6);
    decodeReply(received, &reply);
    if((reply.deviceNum = deviceNumber)&&(reply.instruction == reg))
        return reply.value;
    else
        return SERIAL_ERROR_COULD_NOT_DECODE;
}

int  ZaberController::disconnectController(){
    return disconnect(myPort);
}



