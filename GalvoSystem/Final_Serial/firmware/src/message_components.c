#include "message_components.h"

/* Message_Data type helper functions */
int getMessageData(MESSAGE_DATA *m, PARAMETER_LABELS label) {

    switch (label) {
        case L_STATE:
            return (int) m->laserState;

        case L_POWER:
            return m->laserPower;

        case G_STATE:
            return (int) m->galvoState;

        case X_POS:
            return m->xPosition;

        case Y_POS:
            return m->yPosition;

        case G_SPEED:
            return m->gSpeed;


        default:
            return 0;
    }
}

void setMessageData(MESSAGE_DATA *m, PARAMETER_LABELS label, int value) {

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

        case X_POS:
            m->xPosition = value;
            break;

        case Y_POS:
            m->yPosition = value;
            break;

        case G_SPEED:
            m->gSpeed = value;
            break;

        default:
            break;
    }
}

void addActiveParameter(MESSAGE_DATA *m, int value) {

    switch (m->parameterIterator) {
        case L_STATE:
        {
            m->laserState = (COMPONENT_STATES) value;
            m->activeParameter[m->parameterIterator] = 1;
            m->parameterIterator++;
            break;
        }
        case L_POWER:
        {
            m->laserPower = value;
            m->activeParameter[m->parameterIterator] = 1;
            m->parameterIterator++;
            break;
        }
        case G_STATE:
        {
            m->galvoState = (COMPONENT_STATES) value;
            m->activeParameter[m->parameterIterator] = 1;
            m->parameterIterator++;
            break;
        }
        case X_POS:
        {
            m->xPosition = value;
            m->activeParameter[m->parameterIterator] = 1;
            m->parameterIterator++;
            break;
        }
        case Y_POS:
        {
            m->yPosition = value;
            m->activeParameter[m->parameterIterator] = 1;
            m->parameterIterator++;
            break;
        }
        case G_SPEED:
        {
            m->gSpeed = value;
            m->activeParameter[m->parameterIterator] = 1;
            m->parameterIterator = END_PARAMETERS;
            break;
        }

        default:
            break;
    }
}