//
//  B_Serial.cpp
//  GcodeParser
//
//  Created by Nick Engel on 5/25/18.
//  Copyright © 2018 Nick Engel. All rights reserved.
//

#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <limits.h>

#include "B_Serial.h"

static int b_verbose = 1;

void set_verbose(int value){
    b_verbose = value;
}


#if defined(_WIN32)
/* These macros save us a lot of repetition. Call the specified function,
 * and complain and return early with -1 if things go badly. */
//#if defined(NDEBUG)
//#define PRINT_ERROR(M)
//#define PRINT_SYSCALL_ERROR(M)
//#else
//#define PRINT_ERROR(M) do { if (b_verbose) { fprintf(stderr, "(%s: %d)" M\
//"\n", __FILE__, __LINE__); } } while(0)
//#define PRINT_SYSCALL_ERROR(M) do { if (b_verbose) { fprintf(stderr,\
//"(%s: %d) [ERROR] " M " failed with error code %d.\n",\
//__FILE__, __LINE__, GetLastError()); } } while(0)
//#endif
#define SYSCALL(F) do { if ((F) == 0) {\
PRINT_SYSCALL_ERROR(#F); return SERIAL_ERROR_SYSTEM_ERROR; } } while (0)

int connect(b_port *port, const char *port_name, uint32_t baudRate)
{
    DCB dcb = { 0 };
    COMMTIMEOUTS timeouts;
    
    if (port_name == NULL)
    {
        PRINT_ERROR("[ERROR] port name cannot be NULL.");
        return SERIAL_ERROR_NULL_PARAMETER;
    }
    
    *port = CreateFileA(port_name,
                        GENERIC_READ | GENERIC_WRITE,
                        0,
                        NULL,
                        OPEN_EXISTING,
                        0,
                        NULL);
    if (*port == INVALID_HANDLE_VALUE)
    {
        PRINT_SYSCALL_ERROR("CreateFileA");
        return SERIAL_ERROR_NULL_PARAMETER;
    }
    
    SYSCALL(GetCommState(*port, &dcb));
    dcb.DCBlength = sizeof(DCB);
    dcb.BaudRate = baudRate;
    dcb.fBinary = TRUE;  /* Binary Mode (skip EOF check) */
    dcb.fParity = FALSE;  /* Disable parity checking */
    dcb.fOutxCtsFlow = FALSE; /* No CTS handshaking on output */
    dcb.fOutxDsrFlow = FALSE; /* No DSR handshaking on output */
    dcb.fDtrControl = DTR_CONTROL_DISABLE;  /* Disable DTR Flow control */
    dcb.fDsrSensitivity = FALSE; /* No DSR Sensitivity */
    dcb.fTXContinueOnXoff = TRUE; /* Continue TX when Xoff sent */
    dcb.fOutX = FALSE; /* Disable output X-ON/X-OFF */
    dcb.fInX = FALSE;  /* Disable input X-ON/X-OFF */
    dcb.fErrorChar = FALSE;  /* Disable Err Replacement */
    dcb.fNull = FALSE; /* Disable Null stripping */
    dcb.fRtsControl = RTS_CONTROL_DISABLE;  /* Disable Rts Flow control */
    dcb.fAbortOnError = FALSE; /* Do not abort all reads and writes on Error */
    dcb.wReserved = 0; /* Not currently used, but must be set to 0 */
    dcb.XonLim = 0; /* Transmit X-ON threshold */
    dcb.XoffLim = 0;   /* Transmit X-OFF threshold */
    dcb.ByteSize = 8;  /* Number of bits/byte, 4-8 */
    dcb.Parity = NOPARITY; /* 0-4=None,Odd,Even,Mark,Space */
    dcb.StopBits = ONESTOPBIT;  /* 0,1,2 = 1, 1.5, 2 */
    SYSCALL(SetCommState(*port, &dcb));
    
    timeouts.ReadIntervalTimeout = MAXDWORD;
    timeouts.ReadTotalTimeoutMultiplier = MAXDWORD;
    timeouts.ReadTotalTimeoutConstant = READ_TIMEOUT; /* #defined in header */
    timeouts.WriteTotalTimeoutMultiplier = 0;
    timeouts.WriteTotalTimeoutConstant = 100;
    SYSCALL(SetCommTimeouts(*port, &timeouts));
    
    return SERIAL_SUCCESS;
}

int disconnect(b_port port)
{
    SYSCALL(CloseHandle(port));
    return SERIAL_SUCCESS;
}

int send(b_port port, const char *command, char bytesToWrite)
{
    DWORD nbytes;
    
    if (command == NULL)
    {
        PRINT_ERROR("[ERROR] command cannot be NULL.");
        return SERIAL_ERROR_NULL_PARAMETER;
    }
    
    SYSCALL(WriteFile(port, command, bytesToWrite, &nbytes, NULL));
    if (nbytes == bytesToWrite)
    {
        return (int) nbytes;
    }
    return SERIAL_ERROR_SYSTEM_ERROR;
}

/* We read bytes one-at-a-time as ReadFile(port, destination, 6, &nread, NULL)
 * often enough will "read" bytes of \0 in the middle of a message when it
 * should instead be waiting for a real byte of data down the line.
 * Worse, it reports afterwards that it has read a full 6 bytes, making this
 * behaviour hard to track and harder to debug and compensate for. */
int receive(b_port port, char *destination, char length){
    DWORD nread;
    int i;
    char c;
    
    for (i = 0; i < bytesToRead; i++)
    {
        SYSCALL(ReadFile(port, &c, 1, &nread, NULL));
        
        if (nread == 0) /* timed out */
        {
            PRINT_ERROR("[INFO] Read timed out.");
            break;
        }
        
        if (destination != NULL) destination[i] = c;
    }
    
    if (i == bytesToRead)
    {
        return i;
    }
    /* if we didn't read a whole 6 bytes, we count that as an error. */
    return SERIAL_ERROR_SYSTEM_ERROR;
}

int drain(b_port port)
{
    char c;
    DWORD nread,
    old_timeout;
    COMMTIMEOUTS timeouts;
    
    SYSCALL(PurgeComm(port, PURGE_RXCLEAR));
    SYSCALL(GetCommTimeouts(port, &timeouts));
    old_timeout = timeouts.ReadTotalTimeoutConstant;
    timeouts.ReadTotalTimeoutConstant = 100;
    SYSCALL(SetCommTimeouts(port, &timeouts));
    
    do
    {
        SYSCALL(ReadFile(port, &c, 1, &nread, NULL));
    }
    while (nread == 1);
    
    timeouts.ReadTotalTimeoutConstant = old_timeout;
    SYSCALL(SetCommTimeouts(port, &timeouts));
    
    return SERIAL_SUCCESS;
}

int set_timeout(b_port port, int milliseconds)
{
    COMMTIMEOUTS timeouts;
    
    SYSCALL(GetCommTimeouts(port, &timeouts));
    timeouts.ReadTotalTimeoutConstant = milliseconds;
    SYSCALL(SetCommTimeouts(port, &timeouts));
    
    return milliseconds;
}

#elif defined(__unix__) || defined(__APPLE__) /* end of if defined(_WIN32) */
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <termios.h>
#include <unistd.h>

/* A little sugar for checking return values from system calls.
 * I would have liked to use GNU/GCC's "statement expressions" so that one
 * do something like "z_port port = SYSCALL(open([parameters]))", but they're
 * a GNU extension, and therefore unfriendly to non-GCC compilers.
 * Workaround to avoid dependence on statement expressions for SYSCALL macro:
 * use SYSCALL on result of assignment instead. */
#if defined(NDEBUG)
#define PRINT_ERROR(M)
#define PRINT_SYSCALL_ERROR(M)
#else
#include <errno.h>
#define PRINT_ERROR(M) do { if (b_verbose) { fprintf(stderr, "(%s: %d)" M\
"\n", __FILE__, __LINE__); } } while(0)
#define PRINT_SYSCALL_ERROR(M) do { if (b_verbose) {\
fprintf(stderr, "(%s: %d) [ERROR] " M " failed: %s.\n",\
__FILE__, __LINE__, strerror(errno)); } } while(0)
#endif
/* A little sugar for checking return values from system calls.
 * I would have liked to use GNU/GCC's "statement expressions" so that one
 * do something like "z_port port = SYSCALL(open([parameters]))", but they're
 * a GNU extension, and therefore unfriendly to non-GCC compilers.
 * Workaround to avoid dependence on statement expressions for SYSCALL macro:
 * use SYSCALL on result of assignment instead. */
#define SYSCALL(F) do { if ((F) < 0) { PRINT_SYSCALL_ERROR(#F);\
return SERIAL_ERROR_SYSTEM_ERROR; } } while(0)

int connect(b_port *port, const char *port_name, uint32_t baudRate)
{
    struct termios tio, orig_tio;
    
    if (port == NULL || port_name == NULL)
    {
        PRINT_ERROR("[ERROR] port and port_name cannot be NULL.");
        return SERIAL_ERROR_NULL_PARAMETER;
    }
    
    /* blocking read/write */
    SYSCALL(*port = open(port_name, O_RDWR | O_NOCTTY));
    SYSCALL(tcgetattr(*port, &orig_tio));
    memcpy(&tio, &orig_tio, sizeof(struct termios)); /* copy padding too */
    
    /* cfmakeraw() without cfmakeraw() for cygwin compatibility */
    tio.c_iflag &= ~(IGNBRK | BRKINT | PARMRK | ISTRIP | INLCR
                     | IGNCR | ICRNL | IXON);
    tio.c_oflag &= ~OPOST;
    tio.c_lflag &= ~(ECHO | ECHONL | ICANON | ISIG | IEXTEN);
    tio.c_cflag &= ~(CSIZE | PARENB);
    /* end cfmakeraw() */
    tio.c_cflag = CS8|CREAD|CLOCAL;
    
    /* READ_TIMEOUT is defined in B_serial.h */
    if (READ_TIMEOUT % 100 != 0)
    {
        tio.c_cc[VTIME] = READ_TIMEOUT / 100 + 1; /* Round up */
    }
    else
    {
        tio.c_cc[VTIME] = READ_TIMEOUT / 100;
    }
    tio.c_cc[VMIN] = 0;
    
    speed_t brate;
    switch (baudRate) {
        case 9600:
            brate = B9600;
            break;
        case 19200:
            brate = B19200;
            break;
        case 38400:
            brate = B38400;
            break;
        case 57600:
            brate = B57600;
            break;
        case 115200:
            brate = B115200;
            break;
        case 230400:
            brate = B230400;
            break;
        default:
            brate = B9600;
            break;
    }
    
    SYSCALL(cfsetospeed(&tio, brate) & cfsetispeed(&tio, brate));
    
    while(memcmp(&orig_tio, &tio, sizeof(struct termios)) != 0)
    { /* memcmp is only OK here because we used memcpy above */
        SYSCALL(tcsetattr(*port, TCSAFLUSH, &tio));
        SYSCALL(tcgetattr(*port, &orig_tio));
    }
    
    return SERIAL_SUCCESS;
}

int disconnect(b_port port)
{
    SYSCALL(close(port));
    return SERIAL_SUCCESS;
}





int send(b_port port, const char *command, int length){
    int nlast,
    written = 0;
    
    if (command == NULL){
        return SERIAL_ERROR_NULL_PARAMETER;
    }
    SYSCALL(nlast = (int)write(port, command, length));
    written += nlast;
    if (nlast != length){ /* write can return a short write: test for it */
        return SERIAL_ERROR_SYSTEM_ERROR;
    }
    return written;
}

int receive(b_port port, char *destination, int length)
{
    int nread = 0,
    nlast;
    char c;
    
    for (;;){
        SYSCALL(nlast = (int) read(port, &c, 1));
        
        if (nlast == 0){ // TIMEOUT
            return SERIAL_ERROR_SYSTEM_ERROR;
        }
        if (destination != NULL){
            destination[nread] = c;
        }
        nread += nlast;
    
        if (nread > length){
            return SERIAL_ERROR_BUFFER_TOO_SMALL;
        }
        
        if (c == '\n' || nread == length){
            nread -= 2; /* prepare to cut off the "\r\n" */
            if (nread < 0){
                return SERIAL_ERROR_SYSTEM_ERROR;
            }
            if (destination != NULL){
                destination[nread] = '\0'; /* chomp the "\r\n" */
            }
            return nread;
        }
    }
}

int drain(b_port port)
{
    struct termios tio;
    int old_timeout;
    char c;
    
    /* set timeout to 0.1s */
    SYSCALL(tcgetattr(port, &tio));
    old_timeout = tio.c_cc[VTIME];
    tio.c_cc[VTIME] = 1;
    SYSCALL(tcsetattr(port, TCSANOW, &tio));
    
    /* flush and read whatever else comes in */
    SYSCALL(tcflush(port, TCIFLUSH));
    while(read(port, &c, 1) > 0);
    
    /* set timeout back to what it was */
    tio.c_cc[VTIME] = old_timeout;
    SYSCALL(tcsetattr(port, TCSANOW, &tio));
    
    return SERIAL_SUCCESS;
}

int set_timeout(b_port port, int milliseconds){
    struct termios tio;
    int new_time;
    
    if (milliseconds % 100 != 0)
    {
        new_time = milliseconds / 100 + 1;
    }
    else
    {
        new_time = milliseconds / 100; /* VTIME is in increments of 0.1s */
    }
    
    SYSCALL(tcgetattr(port, &tio));
    tio.c_cc[VTIME] = new_time;
    SYSCALL(tcsetattr(port, TCSANOW, &tio));
    
    return new_time * 100;
}



#endif

