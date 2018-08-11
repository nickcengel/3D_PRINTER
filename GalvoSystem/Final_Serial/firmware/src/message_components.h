#ifndef _MESSAGE_COMPONENTS_H
#define _MESSAGE_COMPONENTS_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus  // Provide C++ Compatibility

extern "C" {

#endif
    
typedef enum {
        MESSAGE_IDLE,
        MESSAGE_LOOK_FOR_START,
        MESSAGE_LOOK_FOR_DATA,
        MESSAGE_RECEIVE_COMPLETE,
        MESSAGE_SEND_BUSY,
        MESSAGE_SEND_COMPLETE,
        MESSAGE_ERROR
    } MESSAGE_STATES;
    /* Data received over USART from master is stored in MESSAGE_DATA Struct */

    /* List of possible commanded states */
    typedef enum {
        ENABLE = 1, DISABLE, RELATIVE_MOVE, ABSOLUTE_MOVE, NONE
    } COMPONENT_STATES;

    /* List of data parameter labels in the order they are expected to arrive */
    typedef enum {
        NO_PARAMETER = -1, L_STATE = 0, L_POWER, G_STATE, X_POS, Y_POS, G_SPEED, END_PARAMETERS
    } PARAMETER_LABELS;

    /* data type for storing information received from PC */
    typedef struct {
        
        COMPONENT_STATES laserState;
        int laserPower;
        COMPONENT_STATES galvoState;
        int32_t xPosition;
        int32_t yPosition;
        int32_t gSpeed;

        bool activeParameter[6]; // each bit in the array corresponds to a parameter.
        // Set true when valid data is read from PC

        PARAMETER_LABELS parameterIterator; // Used to step through each parameter field
        // filling with data from PC
        MESSAGE_STATES messageState;
    } MESSAGE_DATA;
    
        /* getters and setters for Message Data */
    int getMessageData(MESSAGE_DATA *m, PARAMETER_LABELS dataLabel);
    void setMessageData(MESSAGE_DATA *m, PARAMETER_LABELS label, int value);

    /* automatically increments parameterIterator used to fill data from PC */
    void addActiveParameter(MESSAGE_DATA *m, int value);
    
    #endif 

    //DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif