//
//  ZBR.cpp
//  GcodeParser
//
//  Created by Nick Engel on 5/25/18.
//  Copyright © 2018 Nick Engel. All rights reserved.
//

#include "ZBR.h"

ZBR::ZBR(char deviceNum, int portindex, int baudrate){
    deviceNumber = deviceNum;
    portIndex = portindex;
    baudRate = baudrate;
    controllerStatus = ZBRSTATUS::UNKNOWN;
    if(! comOpen(portIndex, baudRate))
        portStatus = RS232::STATUS::NOT_CONNECTED;
    else
        portStatus = RS232::STATUS::CONNECTED;
}

int ZBR::connectController(){
    controllerStatus = ZBRSTATUS::UNKNOWN;
    if(! comOpen(portIndex, baudRate))
        portStatus = RS232::STATUS::NOT_CONNECTED;
    else
        portStatus = RS232::STATUS::CONNECTED;
    return portStatus;
}

void ZBR::disconnectController(){
    controllerStatus = ZBRSTATUS::UNKNOWN;
    comClose(portIndex);
    portStatus = RS232::STATUS::NOT_CONNECTED;
}

void ZBR::decodeReply(const char *reply, reply_t *decodedReply){
    decodedReply->deviceNum = reply[0];
    decodedReply->instruction = reply[1];
    int data = 256^3 * reply[5] + 256^2 * reply[4] + 256 * reply[3] + reply[2];
    if(reply[5] > 127)
        data = data - 256^4;
    decodedReply->value = data;
}

void ZBR::encode(int val, char *v){
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

int ZBR::setParameter(ZBRCMND reg, int val){
    char tx_buf[6] = {0};
    tx_buf[0] = deviceNumber;
    tx_buf[1] = reg;
    encode(val, tx_buf);
    RS232::SERIAL_TX tx = comWrite(portIndex, tx_buf, 6);
    
    if(tx.status != RS232::STATUS::WRITE_COMPLETE){
        portStatus = tx.status;
        return portStatus;
    }
    if(tx.bytesWritten != 6){
        portStatus = RS232::STATUS::SEND_FAILED;
        return portStatus;
    }
    char rx_buf[6] = {0};
    RS232::SERIAL_RX rx = comRead(portIndex, rx_buf, 6);
    
    if(rx.status != RS232::STATUS::READ_COMPLETE){
        portStatus = rx.status;
        return portStatus;
    }
    if(rx.bytesRead != 6)
        return RS232::STATUS::RECEIVE_FAILED;
    
    reply_t reply;
    decodeReply(rx_buf, &reply);
    if((reply.deviceNum == deviceNumber)&&(reply.instruction == reg)&&(reply.value == val)){
        return RS232::STATUS::SEND_COMPLETE;
    }
    else
        return RS232::STATUS::SEND_UNCONFIRMED;
}

ZBR::reply_t ZBR::getParameter(ZBRCMND reg){
    reply_t reply;
    char tx_buf[6] = {0};
    tx_buf[0] = deviceNumber;
    tx_buf[1] = ZBRCMND::RETURN_SETTING;
    tx_buf[2] = reg;
    RS232::SERIAL_TX tx = comWrite(portIndex, tx_buf, 6);
    
    if(tx.status != RS232::STATUS::WRITE_COMPLETE){
        reply.status = tx.status;
        portStatus = tx.status;
        return reply;
    }
    if(tx.bytesWritten != 6){
        reply.status = RS232::STATUS::SEND_FAILED;
        portStatus = reply.status;
        return reply;
    }
    
    char rx_buf[6] = {0};
    RS232::SERIAL_RX rx = comRead(portIndex, rx_buf, 6);
    
    if(rx.status != RS232::STATUS::READ_COMPLETE){
        reply.status = rx.status;
        portStatus = rx.status;
        return reply;
    }
    if(rx.bytesRead != 6){
        reply.status = RS232::STATUS::RECEIVE_FAILED;
        portStatus = reply.status;
        return reply;
    }
    
    decodeReply(rx_buf, &reply);
    if((reply.deviceNum == deviceNumber)&&(reply.instruction == reg)){
        reply.status = RS232::STATUS::RECEIVE_COMPLETE;
        portStatus = reply.status;
        return reply;
    }
    else{
        reply.status = RS232::STATUS::RECEIVE_FAILED;
        portStatus = reply.status;
        return reply;
    }
}


ZBR::reply_t ZBR::pollStatus(int endCondition, uint8_t maxTries){
    uint8_t tries = 0;
    char tx_buf[6] = {0};
    char rx_buf[6] = {0};
    
    RS232::SERIAL_TX tx;
    RS232::SERIAL_RX rx;
    ZBR::reply_t reply;
    
    for(;;){
        tx_buf[0] = deviceNumber;
        tx_buf[1] = ZBRCMND::RETURN_STATUS;
        tx = comWrite(portIndex, tx_buf, 6);
        if(tx.bytesWritten < 6)
            continue;
        
        if(tx.status != RS232::STATUS::WRITE_COMPLETE){
            reply.status = tx.status;
            reply.value = ZBRSTATUS::UNKNOWN;
            portStatus = reply.status;
            controllerStatus = reply.value;
            break;
        }
        
        rx = comRead(portIndex, rx_buf, 6);
        if(rx.status != RS232::STATUS::READ_COMPLETE){
            reply.status = rx.status;
            reply.value = ZBRSTATUS::UNKNOWN;
            portStatus = reply.status;
            controllerStatus = reply.value;
            break;
        }
        
        decodeReply(rx_buf, &reply);
        if((reply.deviceNum == deviceNumber)&&(reply.instruction == ZBRCMND::RETURN_STATUS)){
            if (reply.value == endCondition) {
                reply.status = rx.status;
                portStatus = rx.status;
                controllerStatus = reply.value;
                break;
            }
            else if(tries > maxTries){
                reply.status = RS232::STATUS::TIMEOUT;
                portStatus = reply.status;
                controllerStatus = reply.value;
                break;
            }
            else
                tries++;
        }
    }
    return reply;
}

void ZBR::setup(param_t settings){
    parameters.position_max = settings.position_max;
    parameters.position_min = settings.position_min;
    parameters.speed_max = settings.speed_max;
    parameters.speed_min = settings.speed_min;
    parameters.amps_max = settings.amps_max;
}


ZBR::reply_t ZBR::getStatus(){
    reply_t s = getParameter(ZBRCMND::RETURN_STATUS);
    if(s.status == RS232::STATUS::RECEIVE_COMPLETE){
        controllerStatus = s.value;
        portStatus = s.status;
    }
    return s;
}



ZBR::reply_t ZBR::getPosition(){
    reply_t p = getParameter(ZBRCMND::SET_CURRENT_POSITION);
    if(p.status == RS232::STATUS::RECEIVE_COMPLETE){
        currentPosition = p.value;
        portStatus = p.status;
    }
    return p;
}

int ZBR::moveTo(int position){
    int m = setParameter(ZBRCMND::MOVE_ABSOLUTE, position);
    if(m == RS232::STATUS::SEND_COMPLETE)
        currentPosition = position;
    return m;
}


int ZBR::goHome(){
    setParameter(ZBRCMND::HOME, 0);
    return pollStatus(ZBRSTATUS::IDLE, 10).status;
}

int ZBR::stop(){
    setParameter(ZBRCMND::STOP,0);
    return pollStatus(ZBRSTATUS::IDLE, 10).status;
}
