#include "message_components.h"

int stringToInt(uint8_t *str) {
    int8_t sign = 1;

    if (str[0] == '-') {
        sign = -1;
        str[0] = ' ';
    }
    return (sign * atoi(str));
}

void clearMessage(HOST_MESSAGE_DATA * const m) {
    m->laserState = NONE;
    m->laserPower = 0;
    m->galvoState = NONE;
    m->xPosition = 0;
    m->yPosition = 0;
    m->gSpeed = 0;

    uint8_t i;
    for (i = L_STATE; i < END_PARAMETERS; i++)
        m->activeParameter[i] = 0;
}

/* Message_Data type helper functions */
int getMessageData(HOST_MESSAGE_DATA * const m, PARAMETER_LABELS label) {

    switch (label) {
        case L_STATE:
        {
            return (int) m->laserState;
            break;
        }
        case L_POWER:
        {
            return m->laserPower;
            break;
        }
        case G_STATE:
        {
            return (int) m->galvoState;
            break;
        }
        case G_SPEED:
        {
            return m->gSpeed;
            break;
        }
        case X_POS:
        {
            return m->xPosition;
            break;
        }
        case Y_POS:
        {
            return m->yPosition;
            break;
        }
        default:
        {
            return 0;
            break;
        }
    }
}

void setMessageData(HOST_MESSAGE_DATA * const m, PARAMETER_LABELS label, int value) {

    switch (label) {
        case L_STATE:
            m->laserState = (COMPONENT_STATES) value;
            break;

        case L_POWER:
            m->laserPower = value;
            break;

        case G_STATE:
            m->galvoState = (COMPONENT_STATES) value;
            break;

        case G_SPEED:
            m->gSpeed = value;
            break;

        case X_POS:
            m->xPosition = value;
            break;

        case Y_POS:
            m->yPosition = value;
            break;



        default:
            break;
    }
}

void addActiveParameter(HOST_MESSAGE_DATA * const m, PARAMETER_LABELS label, int value) {

    switch (label) {
        case L_STATE:
        {
            m->laserState = (COMPONENT_STATES) value;
            m->activeParameter[L_STATE] = 1;
            break;
        }

        case L_POWER:
        {
            m->laserPower = value;
            m->activeParameter[L_POWER] = 1;
            break;
        }

        case G_STATE:
        {
            m->galvoState = (COMPONENT_STATES) value;
            m->activeParameter[G_STATE] = 1;
            break;
        }

        case G_SPEED:
        {
            m->gSpeed = value;
            m->activeParameter[G_SPEED] = 1;
            break;
        }

        case X_POS:
        {
            m->xPosition = value;
            m->activeParameter[X_POS] = 1;
            break;
        }

        case Y_POS:
        {
            m->yPosition = value;
            m->activeParameter[Y_POS] = 1;
            break;
        }

        default:
            break;
    }
}

bool parameterIsActive(HOST_MESSAGE_DATA * const m, PARAMETER_LABELS label){
    bool g = m->activeParameter[label];
    return g;
}