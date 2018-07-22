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
#include "math.h"
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
APP_DATA appData;

MESSAGE_DATA myMessage = {0, 0, 0, 0, 0, 0,
    {0, 0, 0, 0, 0, 0}, 0};

uint32_t ADC0_value = 0x0000;

uint32_t DAC0_currentValue = 0x0000;
uint32_t DAC0_finalValue = 0x0000;
uint32_t DAC1_currentValue = 0x0000;
uint32_t DAC1_finalValue = 0x0000;
uint32_t stepSizeX;
uint32_t stepSizeY;
float defaultGalvoSpeed = 13.5;

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************

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

/* converter for signed numbers */
int stringToInt(uint8_t *str) {
    int8_t sign = 1;

    if (str[0] == '-') {
        sign = -1;
        str[0] = ' ';
    }
    return (sign * atoi(str));
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
    appData.appState = APP_STATE_INIT;

    appData.messageState = MESSAGE_IDLE;

    myMessage.parameterIterator = NO_PARAMETER;

    appData.usart0Handle = DRV_HANDLE_INVALID;
    appData.usart0State = USART_INIT;
    memset(usart0_rx_buffer, 0, USART0_RX_BUFF_SIZE);
    usart0_rx_count = 0;
    memset(usart0_tx_buffer, 0, USART0_TX_BUFF_SIZE);
    usart0_tx_count = 0;

    appData.spi0Handle = DRV_HANDLE_INVALID;
    appData.spi0State = SPI_INIT_OFFSET;
    memset(spi0_rx_buffer, 0, SPI_RX_BUFF_SIZE);
    memset(spi0_tx_buffer, 0, SPI_TX_BUFF_SIZE);

    DRV_TMR0_CounterValueSet(0xFFFF - 10);
    tmr0_flag = 0;
}

void USART_Tasks(void) {
    switch (appData.usart0State) { /// BEGIN USART STATE SWITCH ///

        case USART_INIT:
        {
            usart0_rx_count = 0;
            appData.usart0State = USART_IDLE;
            break;
        } // END USART_INIT //

            /* Clear / Prepare buffers, Advance USART state */
        case USART_IDLE:
        {
            if (appData.appState == APP_GET_NEW_MESSAGE) {
                if (usart0_rx_count != 0) {
                    memset(usart0_rx_buffer, 0, USART0_RX_BUFF_SIZE);
                    usart0_rx_count = 0;
                }

                appData.usart0State = USART_GRAB_BYTE;
                appData.messageState = MESSAGE_LOOK_FOR_START;

                BSP_LEDStateSet(BSP_LED_2, BSP_LED_STATE_ON);

                LDAC0Off();

                int i;
                for (i = 0; i < 6; i++)
                    myMessage.activeParameter[i] = 0;

                myMessage.parameterIterator = L_STATE;


            } else if (appData.appState == APP_SEND_REPLY) {
                usart0_tx_count = 0;

                appData.usart0State = USART_THROW_BYTE;
                appData.messageState = MESSAGE_SEND_BUSY;

                BSP_LEDStateSet(BSP_LED_3, BSP_LED_STATE_ON);
            }

            break;
        } // END USART_IDLE //

            /* Read a byte from the PC over USART */
        case USART_GRAB_BYTE:
        {
            /* see if there is new data and if there is a place to put it */
            if (!DRV_USART0_ReceiverBufferIsEmpty()
                    && (usart0_rx_count < USART0_RX_BUFF_SIZE - 2)
                    && (myMessage.parameterIterator < END_PARAMETERS)) {

                const uint8_t currentByte = DRV_USART0_ReadByte();

                switch (appData.messageState) { /// BEGIN MESSAGE STATE SWITCH ///

                        /* Find the beginning of message demarcated by "/" */
                    case MESSAGE_LOOK_FOR_START:
                    {
                        if (currentByte == '/')

                            appData.messageState = MESSAGE_LOOK_FOR_DATA;


                        break;
                    } // END MESSAGE_LOOK_FOR_START

                        /* Read in  ASCII numerical characters until space or ";" */
                    case MESSAGE_LOOK_FOR_DATA:
                    {
                        if (((currentByte >= '0') && (currentByte <= '9'))
                                || ((currentByte == '-') && (usart0_rx_count == 0))) {
                            usart0_rx_buffer[usart0_rx_count] = currentByte;
                            usart0_rx_count++;
                        } else if (currentByte == '~') {
                            myMessage.parameterIterator++;
                        } else if ((currentByte == ' ') && (usart0_rx_count > 0)) {

                            if (strlen(usart0_rx_buffer) > 0) {
                                const int currentParameter = stringToInt(usart0_rx_buffer);
                                addActiveParameter(&myMessage, currentParameter);
                            }
                            memset(usart0_rx_buffer, 0, usart0_rx_count);
                            usart0_rx_count = 0;
                            if (myMessage.parameterIterator >= END_PARAMETERS) {
                                appData.messageState = MESSAGE_RECEIVE_COMPLETE;
                                appData.appState = APP_PROCESS_MESSAGE;
                                appData.usart0State = USART_IDLE;
                            }
                        } else if (currentByte == ';') {
                            if (strlen(usart0_rx_buffer) > 0) {
                                const int currentParameter = stringToInt(usart0_rx_buffer);
                                addActiveParameter(&myMessage, currentParameter);
                            }
                            memset(usart0_rx_buffer, 0, usart0_rx_count);
                            usart0_rx_count = 0;
                            appData.messageState = MESSAGE_RECEIVE_COMPLETE;
                            appData.appState = APP_PROCESS_MESSAGE;
                            appData.usart0State = USART_IDLE;
                        }
                        break;
                    } // END MESSAGE_LOOK_FOR_DATA //

                    default:
                        break;
                } /// END MESSAGE STATE SWITCH ///

                /* We are out of room */
            } else if ((usart0_rx_count >= USART0_RX_BUFF_SIZE - 2)) {
                if (myMessage.parameterIterator < END_PARAMETERS) {
                    const int currentParameter = stringToInt(usart0_rx_buffer);

                    addActiveParameter(&myMessage, currentParameter);
                    memset(usart0_rx_buffer, 0, usart0_rx_count);
                    usart0_rx_count = 0;
                } else {
                    appData.messageState = MESSAGE_RECEIVE_COMPLETE;
                    appData.appState = APP_PROCESS_MESSAGE;
                    appData.usart0State = USART_IDLE;
                    memset(usart0_rx_buffer, 0, sizeof (usart0_rx_buffer));
                    usart0_rx_count = 0;
                }
                /* We received all the data we expected to get */
            } else if (myMessage.parameterIterator >= END_PARAMETERS) {
                appData.messageState = MESSAGE_RECEIVE_COMPLETE;
                appData.appState = APP_PROCESS_MESSAGE;
                appData.usart0State = USART_IDLE;
                memset(usart0_rx_buffer, 0, sizeof (usart0_rx_buffer));
                usart0_rx_count = 0;
            }
            break;
        } // END USART_GRAB_BYTE //

            /* Send a byte back to PC over USART */
        case USART_THROW_BYTE:
        {
            if (!DRV_USART0_TransmitBufferIsFull() && (usart0_tx_count < usart0_tx_length)) {
                DRV_USART0_WriteByte(usart0_tx_buffer[usart0_tx_count]);
                usart0_tx_count++;
            } else if (usart0_tx_count == usart0_tx_length) {
                appData.messageState = MESSAGE_SEND_COMPLETE;
                appData.appState = APP_GET_NEW_MESSAGE;
                appData.usart0State = USART_IDLE;
            }
            break;
        }// END USART_THROW_BYTE //

        default:
            break;
    }/// END USART STATE SWITCH ///

} /// END USART_TASKS() //

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

            if (appData.usart0Handle == DRV_HANDLE_INVALID) {
                appData.usart0Handle =
                        DRV_USART0_Open(DRV_USART_INDEX_0,
                        DRV_IO_INTENT_READWRITE | DRV_IO_INTENT_NONBLOCKING);
                appInitialized &= (DRV_HANDLE_INVALID != appData.usart0Handle);
            }

            if (appData.spi0Handle == DRV_HANDLE_INVALID) {
                appData.spi0Handle =
                        DRV_SPI0_Open(DRV_SPI_INDEX_0,
                        DRV_IO_INTENT_READWRITE | DRV_IO_INTENT_NONBLOCKING);
                appInitialized &= (DRV_HANDLE_INVALID != appData.spi0Handle);
                LDAC0On();
            }

            if (appInitialized) {
                appData.spi0State = SPI_IDLE;
                appData.usart0State = USART_INIT;
                appData.appState = APP_GET_NEW_MESSAGE;

                BSP_LEDStateSet(BSP_LED_1, BSP_LED_STATE_ON);
            }
            break;
        } // END APP_INIT CASE

        case APP_GET_NEW_MESSAGE:
        {
            DRV_USART_TasksReceive(sysObj.drvUsart0);
            USART_Tasks();
            break;
        }

        case APP_PROCESS_MESSAGE:
        {
            DAC0_finalValue = getMessageData(&myMessage, L_STATE) + dac0_offset_val;
            uint32_t deltaX = DAC0_finalValue - (DAC0_currentValue >> 4);
            uint32_t deltaY = DAC1_finalValue - (DAC1_currentValue >> 4);

            float duration = sqrt(deltaX * deltaX + deltaY * deltaY) / defaultGalvoSpeed;
            uint32_t numSteps = ceil(duration / DAC_UPDATE_PERIOD);

            DAC0_finalValue <<=  4;
            DAC1_finalValue <<=  4;
            stepSizeX = (deltaX / numSteps)<<4;
            stepSizeY = (deltaY / numSteps)<<4;

            appData.appState = APP_WRITE_TO_DAC;
            appData.spi0State = SPI_WRITE_START;
            break;
        }

        case APP_WRITE_TO_DAC:
        {
            if (appData.spi0State == SPI_WRITE_START) {

                if (DAC0_finalValue > (DAC0_currentValue + stepSizeX))
                    DAC0_currentValue += stepSizeX;
                else if (DAC0_finalValue < (DAC0_currentValue - stepSizeX))
                    DAC0_currentValue -= stepSizeX;
                else
                    DAC0_currentValue = DAC0_finalValue;

                uint32_t DAC0_DATA = DAC0_currentValue >> 4;

                spi0_tx_buffer[3] = DAC_DIN_REG_WRITE << 4;
                spi0_tx_buffer[3] |= (0xFF & (DAC0_DATA >> 14));
                spi0_tx_buffer[2] = (0xFF & (DAC0_DATA >> 6));
                spi0_tx_buffer[1] = (0xFF & DAC0_DATA) << 2;

                appData.spi0State = SPI_WRITE_BUSY;
                LDAC0On();

                spi0_buf_handle = DRV_SPI0_BufferAddWrite(spi0_tx_buffer, 4, 0, 0);
                DRV_SPI_Tasks(sysObj.spiObjectIdx0);

            } else if (appData.spi0State == SPI_WRITE_BUSY) {

                DRV_SPI_Tasks(sysObj.spiObjectIdx0);
                spi0_buf_status = DRV_SPI0_BufferStatus(spi0_buf_handle);

                if (spi0_buf_status == DRV_SPI_BUFFER_EVENT_COMPLETE) {
                    SPI2_CS0On();
                    LDAC0Off();
                    if (DAC0_currentValue != DAC0_finalValue)
                        appData.spi0State = SPI_WRITE_START;
                    else {
                        appData.spi0State = SPI_READ_START;
                        appData.appState = APP_READ_FROM_ADC;
                    }
                }
            }
            break;
        } // END APP_WRITE_TO_DAC CASE

        case APP_READ_FROM_ADC:
        {
            DRV_SPI_Tasks(sysObj.spiObjectIdx0);
            if (appData.spi0State == SPI_READ_START) {
                tmr0_flag = 0;
                SPI2_CS1Off();
                DRV_TMR0_Start();
                while (1) {
                    if (tmr0_flag != 0)
                        break;
                }
                spi0_buf_handle = DRV_SPI0_BufferAddRead(spi0_rx_buffer, 4, 0, 0);
                appData.spi0State = SPI_READ_BUSY;
            } else if (appData.spi0State == SPI_READ_BUSY) {
                spi0_buf_status = DRV_SPI0_BufferStatus(spi0_buf_handle);
                if (spi0_buf_status == DRV_SPI_BUFFER_EVENT_COMPLETE) {
                    appData.spi0State = SPI_READ_COMPLETE;
                    appData.appState = APP_SEND_REPLY;
                    ADC0_value = 0x0000;
                    ADC0_value |= (uint32_t) (spi0_rx_buffer[3] << 10);
                    ADC0_value |= (uint32_t) (spi0_rx_buffer[2] << 2);
                    ADC0_value |= (uint32_t) (spi0_rx_buffer[1] >> 6);
                    ADC0_value -= 0x1FFF4;
                }
            }
            break;
        } // END APP_READ_FROM_ADC CASE

        case APP_SEND_REPLY:
        {
            DRV_USART_TasksTransmit(sysObj.drvUsart0);
            if (appData.usart0State == USART_IDLE) {

                memset(usart0_tx_buffer, 0, USART0_TX_BUFF_SIZE);
                strcpy(usart0_tx_buffer, "\r\n@ok:\r\n");

                uint8_t buf[8] = {0, 0, 0, 0, 0, 0, 0, 0};
                itoa(buf, ADC0_value, 10);
                strcat(buf, "\r\n");
                strcat(usart0_tx_buffer, buf);

                //                memset(buf, 0, 4);
                //                itoa(buf, spi_rx_buffer[1], 10);
                //                strcat(buf, "\r\n");
                //                strcat(usart_tx_buffer, buf);
                //                memset(buf, 0, 4);
                //                itoa(buf, spi_rx_buffer[2], 10);
                //                strcat(buf, "\r\n");
                //                strcat(usart_tx_buffer, buf);
                //                memset(buf,0,4);
                //                itoa(buf, spi_rx_buffer[3], 10);
                //                strcat(buf, "\r\n");
                //                strcat(usart_tx_buffer, buf);


                //                int i;
                //                for (i = 1; i < END_PARAMETERS; i++) {
                //                    if (myMessage.activeParameter[i]) {
                //                        int value = getMessageData(&myMessage, (PARAMETER_LABELS) i);
                //                        if (value < 0) {
                //                            value *= -1;
                //                            strcat(usart_tx_buffer, "-");
                //                        }
                //                        uint8_t buf[8];
                //                        itoa(buf, value, 10);
                //                        strcat(buf, "\r\n");
                //                        strcat(usart_tx_buffer, buf);
                //                    } else {
                //                        strcat(usart_tx_buffer, "~\r\n");
                //                    }
                //              }
                usart0_tx_length = strlen(usart0_tx_buffer);
            }
            USART_Tasks();

            break;
        } // END REPLY CASE

            /* The default state should never be executed. */
        default:
        {
            /* TODO: Handle error in application's state machine. */
            break;
        }
    } // END APP_STATE SWITCH
} // END APP_TASKS()



/*******************************************************************************
 End of File
 */
