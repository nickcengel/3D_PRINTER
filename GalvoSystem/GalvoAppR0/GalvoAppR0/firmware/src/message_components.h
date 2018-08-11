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
        MESSAGE_REPLY_NONE = 0,
        MESSAGE_REPLY_MIN = 1,
        MESSAGE_REPLY_ADC_ONLY = 2,
        MESSAGE_REPLY_VERBOSE = 3
    } MESSAGE_REPLY_TYPES;
    /* Data received over USART from master is stored in MESSAGE_DATA Struct */

    /* List of possible commanded states */
    typedef enum {
        DISABLE = 0,
        ENABLE = 1,
        RELATIVE_MOVE = 2,
        ABSOLUTE_MOVE = 3,
        NONE = 4
    } COMPONENT_STATES;

    /* List of data parameter labels in the order they are expected to arrive */
    typedef enum {
        L_STATE = 0,
        L_POWER = 1,
        G_STATE = 2,
        G_SPEED = 3,
        X_POS = 4,
        Y_POS = 5,
        END_PARAMETERS = 6
    } PARAMETER_LABELS;

    /* data type for storing information received from PC */
    typedef volatile struct {
        COMPONENT_STATES laserState;
        uint8_t laserPower;
        COMPONENT_STATES galvoState;
        int32_t gSpeed;
        int32_t xPosition;
        int32_t yPosition;

        // each bit in the array corresponds to a parameter.
        // Set true when valid data is read from PC 
        bool activeParameter[6];

        // Used to step through each parameter field
        // filling with data from PC

        MESSAGE_REPLY_TYPES mesageReplyType;
    } HOST_MESSAGE_DATA;

    int stringToInt(uint8_t *str);

    void clearMessage(HOST_MESSAGE_DATA * const m);

    /* getters and setters for Message Data */
    int getMessageData(HOST_MESSAGE_DATA * const m, PARAMETER_LABELS dataLabel);
    void setMessageData(HOST_MESSAGE_DATA * const m, PARAMETER_LABELS label, int value);

    void addActiveParameter(HOST_MESSAGE_DATA * const m, PARAMETER_LABELS label, int value);
    
    bool parameterIsActive(HOST_MESSAGE_DATA * const m, PARAMETER_LABELS label);

#endif 

    //DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif