/*******************************************************************************
  MPLAB Harmony Application Source File
  
  Company:
    Microchip Technology Inc.
  
  File Name:
    app.c

  Summary:
    This file contains the source code for the MPLAB Harmony application.

  Description:
    This file contains the source code for the MPLAB Harmony application.  It 
    implements the logic of the application's state machine and it may call 
    API routines of other MPLAB Harmony modules in the system, such as drivers,
    system services, and middleware.  However, it does not call any of the
    system interfaces (such as the "Initialize" and "Tasks" functions) of any of
    the modules in the system or make any assumptions about when those functions
    are called.  That is the responsibility of the configuration-specific system
    files.
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2013-2014 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
 *******************************************************************************/
// DOM-IGNORE-END


// *****************************************************************************
// *****************************************************************************
// Section: Included Files 
// *****************************************************************************
// *****************************************************************************

#include "app.h"
#include "string.h"
// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************

/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    This structure should be initialized by the APP_Initialize function.
    
    Application strings and buffers are be defined outside this structure.
 */

int stringToInt(uint8_t *str) {
    int8_t sign = 1;

    if (str[0] == '-')
    {
        sign = -1;
        str[0] = ' ';
    }
    return (sign*atoi(str));
}

APP_DATA appData;

MESSAGE_DATA myMessage = {0, 0, 0, 0, 0, 0,
    {0, 0, 0, 0, 0, 0}, 0};
// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

/* TODO:  Add any necessary callback functions.
 */

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************

/* TODO:  Add any necessary local functions.
 */

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

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_Initialize ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Initialize(void) {
    /* Place the App state machine in its initial state. */

    appData.handleUSART0 = DRV_HANDLE_INVALID;
    appData.appState = APP_STATE_INIT;
    appData.messageState = MESSAGE_IDLE;
    appData.usartState = USART_INIT;

    memset(usart_rx_buffer, 0, USART_RX_BUFF_SIZE);
    appData.rx_count = 0;

    memset(usart_tx_buffer, 0, USART_TX_BUFF_SIZE);
    appData.tx_count = 0;

    myMessage.parameterIterator = NO_PARAMETER;

    int i;
    for (i = 0; i < 6; i++)
        myMessage.activeParameter[i] = 0;





    /* TODO: Initialize your application's state machine and other
     * parameters.
     */
}

void USART_Tasks(void) {

    switch (appData.usartState) {

        case USART_INIT:
        {
            appData.rx_count = 0;
            appData.usartState = USART_IDLE;
            break;
        }

        case USART_IDLE:
        {
            if (appData.appState == APP_GET_NEW_MESSAGE) {
                if (appData.rx_count != 0) {
                    memset(usart_rx_buffer, 0, USART_RX_BUFF_SIZE);
                    appData.rx_count = 0;
                }

                appData.usartState = USART_GRAB_BYTE;
                appData.messageState = MESSAGE_LOOK_FOR_START;

                BSP_LEDStateSet(BSP_LED_2, BSP_LED_STATE_ON);

                int i;
                for (i = 0; i < 6; i++)
                    myMessage.activeParameter[i] = 0;

                myMessage.parameterIterator = L_STATE;
            }

            else if (appData.appState == APP_SEND_REPLY) {
                appData.tx_count = 0;

                appData.usartState = USART_THROW_BYTE;
                appData.messageState = MESSAGE_SEND_BUSY;
                
                BSP_LEDStateSet(BSP_LED_3, BSP_LED_STATE_ON);
            }

            break;
        }


        case USART_GRAB_BYTE:
        {
            if (!DRV_USART0_ReceiverBufferIsEmpty()
                    && (appData.rx_count < USART_RX_BUFF_SIZE - 2)
                    && (myMessage.parameterIterator < END_PARAMETERS)) {

                const uint8_t currentByte = DRV_USART0_ReadByte();

                switch (appData.messageState) {

                    case MESSAGE_LOOK_FOR_START:
                    {
                        if (currentByte == '/')
                            appData.messageState = MESSAGE_LOOK_FOR_DATA;

                        break;
                    }


                    case MESSAGE_LOOK_FOR_DATA:
                    {
                        
                        
                        
                        
                        
                        if (((currentByte >= '0') && (currentByte <= '9'))
                                || ((currentByte == '-') && (appData.rx_count == 0))) {
                            usart_rx_buffer[appData.rx_count] = currentByte;
                            appData.rx_count++;
                        } else if (currentByte == '~') {
                            myMessage.parameterIterator++;
                        } else if ((currentByte == ' ') && (appData.rx_count > 0)) {

                            if(strlen(usart_rx_buffer) > 0){
                            const int currentParameter = stringToInt(usart_rx_buffer);
                            addActiveParameter(&myMessage, currentParameter);
                            }
                            memset(usart_rx_buffer, 0, appData.rx_count);
                            appData.rx_count = 0;
                            if (myMessage.parameterIterator >= END_PARAMETERS) {
                                appData.messageState = MESSAGE_RECEIVE_COMPLETE;
                                appData.appState = APP_PROCESS_MESSAGE;
                                appData.usartState = USART_IDLE;
                            }
                        } else if (currentByte == ';') {
                            if(strlen(usart_rx_buffer) > 0){
                                const int currentParameter = stringToInt(usart_rx_buffer);
                            addActiveParameter(&myMessage, currentParameter);
                            }
                            
                            memset(usart_rx_buffer, 0, appData.rx_count);
                            appData.rx_count = 0;
                            appData.messageState = MESSAGE_RECEIVE_COMPLETE;
                            appData.appState = APP_PROCESS_MESSAGE;
                            appData.usartState = USART_IDLE;
                        }


                        break;
                    }

                    default:
                        break;
                }
            } 
            
            else if ((appData.rx_count >= USART_RX_BUFF_SIZE - 2)) {
                if (myMessage.parameterIterator < END_PARAMETERS) {
                    const int currentParameter = stringToInt(usart_rx_buffer);;
                    addActiveParameter(&myMessage, currentParameter);
                    memset(usart_rx_buffer, 0, appData.rx_count);
                    appData.rx_count = 0;
                } else {
                    appData.messageState = MESSAGE_RECEIVE_COMPLETE;
                    appData.appState = APP_PROCESS_MESSAGE;
                    appData.usartState = USART_IDLE;
                    memset(usart_rx_buffer, 0, sizeof (usart_rx_buffer));
                    appData.rx_count = 0;
                }
            } else if (myMessage.parameterIterator >= END_PARAMETERS) {
                appData.messageState = MESSAGE_RECEIVE_COMPLETE;
                appData.appState = APP_PROCESS_MESSAGE;
                appData.usartState = USART_IDLE;
                memset(usart_rx_buffer, 0, sizeof (usart_rx_buffer));
                appData.rx_count = 0;
            }

            break;
        }

                    case USART_THROW_BYTE:
                    {
                        if (!DRV_USART0_TransmitBufferIsFull() && (appData.tx_count < appData.tx_length)) {
                            DRV_USART0_WriteByte(usart_tx_buffer[appData.tx_count]);
                            appData.tx_count++;
                        } else if (appData.tx_count == appData.tx_length) {
                            appData.messageState = MESSAGE_SEND_COMPLETE;
                            appData.appState = APP_GET_NEW_MESSAGE;
                            appData.usartState = USART_IDLE;
                        }
            
                        break;
                    }



        default:
            break;
    }
}

/******************************************************************************
  Function:
    void APP_Tasks ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Tasks(void) {

    /* Check the application's current state. */
    switch (appData.appState) {
            /* Application's initial state. */
        case APP_STATE_INIT:
        {
            bool appInitialized = true;


            if (appData.handleUSART0 == DRV_HANDLE_INVALID) {
                appData.handleUSART0 =
                        DRV_USART0_Open(DRV_USART_INDEX_0,
                        DRV_IO_INTENT_READWRITE | DRV_IO_INTENT_NONBLOCKING);
                appInitialized &= (DRV_HANDLE_INVALID != appData.handleUSART0);
            }

            if (appInitialized) {
                /* initialize the USART state machine */
                appData.usartState = USART_INIT;

                BSP_LEDStateSet(BSP_LED_1, BSP_LED_STATE_ON);

                appData.appState = APP_GET_NEW_MESSAGE;
            }

            break;
        }

        case APP_GET_NEW_MESSAGE:
        {

            USART_Tasks();

            break;
        }

        case APP_PROCESS_MESSAGE:
        {
            memset(usart_tx_buffer, 0, USART_TX_BUFF_SIZE);
            strcpy(usart_tx_buffer, "\r\n@ ok:\r\n");


            int i;
            for (i = 0; i < END_PARAMETERS; i++) {
                if (myMessage.activeParameter[i]) {
                    int value = getMessageData(&myMessage, (PARAMETER_LABELS) i);
                    if(value < 0)
                    {
                        value *= -1;
                        strcat(usart_tx_buffer, "-");
                    }
                    uint8_t buf[8];
                    itoa(buf, value, 10);
                    strcat(buf, "\r\n");
                    strcat(usart_tx_buffer, buf);
                } else {
                    strcat(usart_tx_buffer, "~\r\n");
                }
            }

            appData.appState = APP_SEND_REPLY;
            appData.tx_length = strlen(usart_tx_buffer);


            break;
        }

        case APP_SEND_REPLY:
        {
            USART_Tasks();

            break;
        }

            /* TODO: implement your application state machine.*/


            /* The default state should never be executed. */
        default:
        {
            /* TODO: Handle error in application's state machine. */
            break;
        }
    }
}



/*******************************************************************************
 End of File
 */
