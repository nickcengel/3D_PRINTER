//
//  ZBR.hpp
//  GcodeParser
//
//  Created by Nick Engel on 5/25/18.
//  Copyright © 2018 Nick Engel. All rights reserved.
//

#ifndef ZBR_h
#define ZBR_h

#include <vector>
#include "rs232/rs232.h"
#include <stdio.h>

using std::vector;

class ZBR{
public:
    enum ZBRCMND {
        RESET= 0,  // Hard restart, Reply: None
        HOME = 1,       // Decrease position until limit switch, then advance, Reply: Final position
        RENUMBER = 2,
        READ_REGISTER = 5,  // Get data at active register, Reply: Data
        SET_ACTIVE_REGISTER = 6,    // Set active register, Reply: Register address
        WRITE_REGISTER = 7, //  Write data to active register, Reply: Data
        MOVE_TRACKING = 8,  //  Reply: In tracking mode, current position returned at regular interval
        LIMIT_ACTIVE = 9,   //  Reply: Limit switch reached, returns position
        MANUAL_MOVE_TRACKING = 10,
        MANUAL_MOVE = 11,
        SLIP_TRACKING = 12,  // Reply: in slip tracking, returns position when slipping at regurlar interval
        UNEXPECTED_POSITION = 13,    // Reply: return if stopped in position other than requested one, returns position
        STORE_CURRENT_POSITION = 16, // Store position at non-volatile register addressed, reply: register address
        RETURN_STORED_POSITION = 17, // Return stored position at register addressed, reply: stored position
        MOVE_TO_STORED_POSITION = 18,    // || , Reply: position
        MOVE_ABSOLUTE = 20,  //Move to absolute position, Reply: position
        MOVE_RELATIVE = 21,
        MOVE_AT_CONSTANT_SPEED = 22,
        STOP = 23,   //18 Stop movement, Reply: final position
        SET_ACTIVE_AXIS = 25,
        SET_AXIS_DEVICE_NUMBER = 26,
        SET_AXIS_INVERSION = 27,
        SET_AXIS_VELOCITY_PROFILE = 28,
        SET_AXIS_VELOCITY_SCALE = 29,
        LOAD_EVENT_INSTRUCTION = 30,
        RETURN_EVENT_INSTRUCTION = 31,
        SET_JOYSTICK_CALIBRATION_MODE = 33,
        RESTORE_SETTINGS = 36,
        SET_MICROSTEP_RESOLUTION = 37,   // set microsteps, Reply: microsteps
        SET_RUNNING_CURRENT = 38,    //  set max running current in 14.1mA intervals, reply: value
        SET_HOLD_CURRENT = 39,   //  set max hold current in 20mA intervals, reply: value
        SET_DEVICE_MODE = 40,    // deprecated?
        SET_HOME_SPEED = 41, // set homing speed, Reply: value
        SET_TARGET_SPEED = 42, // set target speed, Reply: value
        SET_ACCELERATION = 43,    // set acceleration, Reply: value
        SET_MAXIMUM_POSITION = 44,   // set max position, Reply: position
        SET_CURRENT_POSITION = 45,   //  Overide current position value with new value, Reply: new position value (volatile)
        SET_HOME_OFFSET = 47,    // custom offset after limit switch reached and released, auto subtracted from MAXIMUM_POSITION
        SET_ALIAS_NUMBER = 48,
        RETURN_DEVICE_ID = 50,
        RETURN_FIRMWARE_VERSION = 51,
        RETURN_POWER_SUPPLY_VOLTAGE = 52,
        RETURN_SETTING = 53, // Use any "SET_" command to request that setting, Reply: setting value
        RETURN_STATUS = 54,  // Reply: status {idle = 0, homing = 1, ...}
        ECHO_DATA = 55,  // "Ping", returns whatever command data that was sent
        RETURN_FIRMWARE_BUILD = 56,
        RETURN_CURRENT_POSITION = 60,    // no command data, Reply: current position
        RETURN_SERIAL_NUMBER = 63,
        SET_PARK_STATE = 65, // Set with "1": current position stored (non-volatile), motor current disabled. Clear "0": Restore motor current
        SET_PERIPHERAL_ID = 66,
        RETURN_DIGITAL_INPUT_COUNT = 67,
        READ_DIGITAL_INPUT = 68, // Get value at specified pin number, Reply: value at pin
        READ_ALL_DIGITAL_INPUTS = 69,
        RETURN_DIGITAL_OUTPUT_COUNT = 70,
        READ_DIGITAL_OUTPUT = 71,    // Get value at specified pin number, Reply: value at pin
        READ_ALL_DIGITAL_OUTPUTS = 72,
        WRITE_DIGITAL_OUTPUT = 73,   // Write value at specified pin number, Reply: value at pin
        WRITE_ALL_DIGITAL_OUTPUTS = 74,
        RETURN_ANALOG_INPUT_COUNT = 75,
        READ_ANALOG_INPUT = 76,
        RETURN_ANALOG_OUTPUT_COUNT = 77,
        MOVE_INDEX = 78,
        SET_INDEX_DISTANCE = 79,
        SET_CYCLE_DISTANCE = 80,
        SET_FILTER_HOLDER_ID = 81,
        RETURN_ENCODER_COUNT = 82,
        RETURN_CALIBRATED_ENCODER_COUNT = 83,
        RETURN_CALIBRATION_TYPE = 84,
        RETURN_CALIBRATION_ERROR = 85,
        SET_PERIPHERAL_SERIAL_NUMBER = 86,
        FORCE_ABSOLUTE = 87,
        FORCE_OFF = 88,
        SET_AUTO_REPLY_DISABLED_MODE = 101,
        SET_MESSAGE_ID_MODE = 102,
        SET_HOME_STATUS = 103,    // Set 0 automatically at power up, 1 after homing or SET_CURRENT_POSITION executed
        SET_HOME_SENSOR_TYPE = 104,
        SET_AUTO_HOME_DISABLED_MODE = 105,
        SET_MINIMUM_POSITION = 106,   // set min position, default 0, Reply: min position
        SET_KNOB_DISABLED_MODE = 107,
        SET_KNOB_DIRECTION = 108,
        SET_KNOB_MOVEMENT_MODE = 109,
        SET_KNOB_JOG_SIZE = 110,
        SET_KNOB_VELOCITY_SCALE = 111,
        SET_KNOB_VELOCITY_PROFILE = 112,
        SET_ACCELERATION_ONLY = 113,  // sets only acceleration, Reply: value
        SET_DECELERATION_ONLY = 114,  // sets only deceleration, Reply: value
        SET_MOVE_TRACKING_MODE = 115, // set mode default 0, 1 = will respond with position regularly. Reply: mode
        SET_MANUAL_MOVE_TRACKING_DISABLED_MODE = 116,
        SET_MOVE_TRACKING_PERIOD = 117,
        SET_CLOSED_LOOP_MODE = 118,   // set mode default 3 "position correction, Reply: mode
        SET_SLIP_TRACKING_PERIOD = 119,
        SET_STALL_TIMEOUT = 120,
        SET_DEVICE_DIRECTION = 121,
        SET_BAUD_RATE = 122,
        SET_PROTOCOL = 123, // 1 = binary, 2 = ascii
        CONVERT_TO_ASCII = 124,
        ERROR = 255  // Reply: codes 1-6501
    };
    
    enum ZBRSTATUS {
        IDLE = 0,
        HOMING = 1,
        MANUAL_VELOCITY_MOVE = 10,
        MANUAL_DISPLACEMENT_MOVE = 11,
        STALLED_OR_DISPLACED = 13,
        STORED_POSITION_MOVE = 18,
        ABSOLUTE_MOVE = 20,
        RELATIVE_MOVE = 21,
        CONSTANT_SPEED_MOVE = 22,
        STOPPING = 23,
        PARKED = 65,
        INDEX_MOVE = 78,
        BUSY = 254,
        UNKNOWN = 255
    };
    
    struct reply_t {
        char deviceNum;
        int status;
        char instruction;
        int value;
    };
    
    struct param_t{
        int position_max;
        int position_min;
        int speed_max;
        int speed_min;
        int amps_max;
    }parameters;
    
    u_int8_t deviceNumber;
    int portIndex;
    int baudRate;
    const struct timespec ts = { 0, 100000000 };
    
    ZBR(char deviceNum, int portindex, int baudrate);
    
    
    
    int controllerStatus;
    int portStatus;
    int currentPosition;
    int speed;
    int acceleration;
    
    int connectController();
    void disconnectController();
    
    void decodeReply(const char *reply, reply_t *decodedReply);
    void encode(int val, char *v);
    
    int setParameter(ZBRCMND reg, int val);
    reply_t getParameter(ZBRCMND reg);
    
    void setup(param_t settings);
    
    reply_t getStatus();
    reply_t pollStatus(int endCondition, uint8_t maxTries);
    
    reply_t getPosition();
    
    int goHome();
    int moveTo(int position);
    int moveTo(int position, int speed_);
    int stop();
    
};

#endif /* ZBR_hpp */
