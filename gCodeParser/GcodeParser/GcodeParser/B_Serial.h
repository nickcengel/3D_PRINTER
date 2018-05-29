//
//  B_Serial.hpp
//  GcodeParser
//
//  Created by Nick Engel on 5/25/18.
//  Copyright © 2018 Nick Engel. All rights reserved.
//

#ifndef B_Serial_h
#define B_Serial_h
#include <cstdlib>
#include <time.h>



#define VERSION 1.0

#if defined(_WIN32)
#include <windows.h>
typedef HANDLE b_port;
#elif defined(__unix__) || defined(__APPLE__)
typedef int b_port;
#endif /* if defined(_WIN32) and other OS checks */

#define READ_TIMEOUT 2000

enum serial_returns {
    /** Everything is OK! */
    SERIAL_SUCCESS = 0,
    /** Something went wrong in system code */
    SERIAL_ERROR_SYSTEM_ERROR = -1,
    /** Tried to write to a buffer that wasn't long enough */
    SERIAL_ERROR_BUFFER_TOO_SMALL = -2,
    /** Was passed NULL when not expecting it */
    SERIAL_ERROR_NULL_PARAMETER = -3,
    /** Tried to set an unsupported baudrate */
    SERIAL_ERROR_INVALID_BAUDRATE = -4,
    /** Tried to decode a partial reply,
     * or a string that wasn't a reply at all */
    SERIAL_ERROR_COULD_NOT_DECODE = -5
};
void set_verbose(int value);
int connect(b_port *port, const char *port_name, uint32_t baudRate);
int disconnect(b_port port);
int send(b_port port, const char *command, int length);
int receive(b_port port, char *destination, int length);
int drain(b_port port);
int set_timeout(b_port port, int milliseconds);

#endif /* B_Serial_h */
