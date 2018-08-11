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
#include "message_components.h"
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
    
   
 */
uint8_t spi0_tx_buffer[SPI_TX_BUFF_SIZE];
uint8_t spi0_rx_buffer[SPI_RX_BUFF_SIZE];

uint8_t usart0_rx_buffer[USART0_RX_BUFF_SIZE];
uint8_t usart0_tx_buffer[USART0_TX_BUFF_SIZE];

APP_DATA appData;
// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************

/* converter for signed numbers */
int stringToInt(uint8_t *str) {
    int8_t sign = 1;

    if (str[0] == '-') {
        sign = -1;
        str[0] = ' ';
    }
    return (sign * atoi(str));
}

uint32_t stepSizeCalc(uint32_t currenntX, uint32_t finalX, float speed) {
    uint32_t deltaX = 0;
    uint32_t deltaY = 0;

    if (finalX > currenntX)
        deltaX = finalX - currenntX;
    else
        deltaX = currenntX - finalX;

    if (deltaX > 0) {
        uint32_t distance = ((uint32_t) sqrt((float) deltaX * (float) deltaX + (float) deltaY * (float) deltaY)) << 10;
        uint32_t duration = distance / speed;
        uint32_t numIncrements = (uint32_t) (((float) duration) / DAC_UPDATE_PERIOD);
        return (distance / numIncrements);
    }
}

void USART0_TaskHandler(void) {
    switch (appData.usart0State) { /// BEGIN USART STATE SWITCH ///

        case USART_INIT:
        {
            appData.usart0_rx_count = 0;
            appData.usart0State = USART_IDLE;
            break;
        } // END USART_INIT //

            /* Clear / Prepare buffers, Advance USART state */
        case USART_IDLE:
        {
            
            if (appData.appState == APP_GET_NEW_MESSAGE) {
                if (appData.usart0_rx_count != 0) {
                    memset(appData.usart0_rx_bufPtr, 0, USART0_RX_BUFF_SIZE);
                    appData.usart0_rx_count = 0;
                }

                appData.usart0State = USART_GRAB_BYTE;
                appData.hostMessage.messageState = MESSAGE_LOOK_FOR_START;

                int i;
                for (i = 0; i < 6; i++)
                    appData.hostMessage.activeParameter[i] = 0;

                appData.hostMessage.parameterIterator = L_STATE;


            } else if (appData.appState == APP_SEND_REPLY) {
                appData.usart0_tx_count = 0;

                appData.usart0State = USART_THROW_BYTE;
                appData.hostMessage.messageState = MESSAGE_SEND_BUSY;

            }

            break;
        } // END USART_IDLE //

            /* Read a byte from the PC over USART */
        case USART_GRAB_BYTE:
        {
            /* see if there is new data and if there is a place to put it */
            if (!DRV_USART0_ReceiverBufferIsEmpty()
                    && (appData.usart0_rx_count < USART0_RX_BUFF_SIZE - 2)
                    && (appData.hostMessage.parameterIterator < END_PARAMETERS)) {

                const uint8_t currentByte = DRV_USART0_ReadByte();

                switch (appData.hostMessage.messageState) { /// BEGIN MESSAGE STATE SWITCH ///

                        /* Find the beginning of message demarcated by "/" */
                    case MESSAGE_LOOK_FOR_START:
                    {
                        if (currentByte == '/')

                            appData.hostMessage.messageState = MESSAGE_LOOK_FOR_DATA;


                        break;
                    } // END MESSAGE_LOOK_FOR_START

                        /* Read in  ASCII numerical characters until space or ";" */
                    case MESSAGE_LOOK_FOR_DATA:
                    {
                        if (((currentByte >= '0') && (currentByte <= '9'))
                                || ((currentByte == '-') && (appData.usart0_rx_count == 0))) {
                            appData.usart0_rx_bufPtr[ appData.usart0_rx_count] = currentByte;
                            appData.usart0_rx_count++;
                        } else if (currentByte == '~') {
                            appData.hostMessage.parameterIterator++;
                        } else if ((currentByte == ' ') && (appData.usart0_rx_count > 0)) {

                            if (strlen(appData.usart0_rx_bufPtr) > 0) {
                                const int currentParameter = stringToInt(appData.usart0_rx_bufPtr);
                                addActiveParameter(&appData.hostMessage, currentParameter);
                            }
                            memset(appData.usart0_rx_bufPtr, 0, appData.usart0_rx_count);
                            appData.usart0_rx_count = 0;
                            if (appData.hostMessage.parameterIterator >= END_PARAMETERS) {
                                appData.hostMessage.messageState = MESSAGE_RECEIVE_COMPLETE;
                                appData.appState = APP_PROCESS_MESSAGE;
                                appData.usart0State = USART_IDLE;
                            }
                        } else if (currentByte == ';') {
                            if (strlen(appData.usart0_rx_bufPtr) > 0) {
                                const int currentParameter = stringToInt(appData.usart0_rx_bufPtr);
                                addActiveParameter(&appData.hostMessage, currentParameter);
                            }
                            memset(appData.usart0_rx_bufPtr, 0, appData.usart0_rx_count);
                            appData.usart0_rx_count = 0;
                            appData.hostMessage.messageState = MESSAGE_RECEIVE_COMPLETE;
                            appData.appState = APP_PROCESS_MESSAGE;
                            appData.usart0State = USART_IDLE;
                        }
                        break;
                    } // END MESSAGE_LOOK_FOR_DATA //

                    default:
                        break;
                } /// END MESSAGE STATE SWITCH ///

                /* We are out of room */
            } else if ((appData.usart0_rx_count >= USART0_RX_BUFF_SIZE - 2)) {
                if (appData.hostMessage.parameterIterator < END_PARAMETERS) {
                    const int currentParameter = stringToInt(appData.usart0_rx_bufPtr);

                    addActiveParameter(&appData.hostMessage, currentParameter);
                    memset(appData.usart0_rx_bufPtr, 0, appData.usart0_rx_count);
                    appData.usart0_rx_count = 0;
                } else {
                    appData.hostMessage.messageState = MESSAGE_RECEIVE_COMPLETE;
                    appData.appState = APP_PROCESS_MESSAGE;
                    appData.usart0State = USART_IDLE;
                    memset(appData.usart0_rx_bufPtr, 0, sizeof (appData.usart0_rx_bufPtr));
                    appData.usart0_rx_count = 0;
                }
                /* We received all the data we expected to get */
            } else if (appData.hostMessage.parameterIterator >= END_PARAMETERS) {
                appData.hostMessage.messageState = MESSAGE_RECEIVE_COMPLETE;
                appData.appState = APP_PROCESS_MESSAGE;
                appData.usart0State = USART_IDLE;
                memset(appData.usart0_rx_bufPtr, 0, sizeof (appData.usart0_rx_bufPtr));
                appData.usart0_rx_count = 0;
            }
            break;
        } // END USART_GRAB_BYTE //

            /* Send a byte back to PC over USART */
        case USART_THROW_BYTE:
        {
            if (!DRV_USART0_TransmitBufferIsFull() && (appData.usart0_tx_count < appData.usart0_tx_length)) {
                DRV_USART0_WriteByte(appData.usart0_tx_bufPtr[appData.usart0_tx_count]);
                appData.usart0_tx_count++;
            } else if (appData.usart0_tx_count == appData.usart0_tx_length) {
                appData.hostMessage.messageState = MESSAGE_SEND_COMPLETE;
                appData.appState = APP_GET_NEW_MESSAGE;
                appData.usart0State = USART_IDLE;
            }
            break;
        }// END USART_THROW_BYTE //

        default:
            break;
    }/// END USART STATE SWITCH ///

} /// END USART_TASKS() //

void set_DAC0_StartVal(uint32_t startVal) {
    if (appData.spi0State == SPI_IDLE) {
        memset(appData.spi0_tx_bufPtr, 0, 4);
        appData.DAC0_currentValue = startVal;
        uint32_t DAC0_DATA = appData.DAC0_currentValue;
        appData.spi0_tx_bufPtr[3] = DAC_DIN_REG_WRITE << 4;
        appData.spi0_tx_bufPtr[3] |= (0xFF & (DAC0_DATA >> 14));
        appData.spi0_tx_bufPtr[2] = (0xFF & (DAC0_DATA >> 6));
        appData.spi0_tx_bufPtr[1] = (0xFF DAC0_DATA) << 2;

        appData.spi0_buf_handle = DRV_SPI0_BufferAddWrite(appData.spi0_tx_bufPtr, 4, 0, 0);
        DRV_SPI_Tasks(sysObj.spiObjectIdx0);
        appData.spi0State = SPI_WRITE_BUSY;
    } else {
        DRV_SPI_Tasks(sysObj.spiObjectIdx0);
        appData.spi0_buf_status = DRV_SPI0_BufferStatus(appData.spi0_buf_handle);
        if (appData.spi0_buf_status == DRV_SPI_BUFFER_EVENT_COMPLETE) {
            LDAC0Off();
            appData.spi0State = SPI_IDLE;
            appData.appState = APP_GET_NEW_MESSAGE;
        }
    }
}

void DAC0_Write(void) {
    LDAC0On();
    if (appData.DAC0_currentValue < appData.DAC0_finalValue) {
        appData.DAC0_currentValue += appData.stepSizeX;
        if (appData.DAC0_currentValue > appData.DAC0_finalValue)
            appData.DAC0_currentValue = appData.DAC0_finalValue;
    } else if (appData.DAC0_currentValue > appData.DAC0_finalValue) {
        appData.DAC0_currentValue -= appData.stepSizeX;
        if (appData.DAC0_currentValue < appData.DAC0_finalValue)
            appData.DAC0_currentValue = appData.DAC0_finalValue;
    }

    const uint32_t DAC0_DATA = appData.DAC0_currentValue;

    appData.spi0_tx_bufPtr[3] = DAC_DIN_REG_WRITE << 4;
    appData.spi0_tx_bufPtr[3] |= (0xFF & (DAC0_DATA >> 14));
    appData.spi0_tx_bufPtr[2] = (0xFF & (DAC0_DATA >> 6));
    appData.spi0_tx_bufPtr[1] = (0xFF & DAC0_DATA) << 2;

    appData.spi0_buf_handle = DRV_SPI0_BufferAddWrite((uint8_t *) & appData.spi0_tx_bufPtr, 4, 0, 0);

    DRV_SPI_Tasks(sysObj.spiObjectIdx0);

    appData.spi0State = SPI_WRITE_BUSY;

}

void DAC0_Confirm_Write(void) {

    DRV_SPI_Tasks(sysObj.spiObjectIdx0);
    appData.spi0_buf_status = DRV_SPI0_BufferStatus(appData.spi0_buf_handle);

    if (appData.spi0_buf_status == DRV_SPI_BUFFER_EVENT_COMPLETE) {
        tmr1_flag = 1;

        if (appData.DAC0_currentValue == appData.DAC0_finalValue) {
            appData.spi0State = SPI_READ_START;
            appData.appState = APP_READ_FROM_ADC;
        } else {
            appData.spi0State = SPI_WRITE_START;
        }
    }
}

uint32_t ADC0_Read(void) {
    uint32_t adc0val = 0;

    if (appData.spi0State == SPI_READ_START) {

        SPI2_CS1Off();
        DRV_TMR0_Start();
        while (1) {
            if (tmr0_flag != 0)
                break;
        }

        appData.spi0_buf_handle = DRV_SPI0_BufferAddRead((uint8_t *) & appData.spi0_rx_bufPtr, 4, 0, 0);
        DRV_SPI_Tasks(sysObj.spiObjectIdx0);
        appData.spi0State = SPI_READ_BUSY;
    } else if (appData.spi0State == SPI_READ_BUSY) {
        DRV_SPI_Tasks(sysObj.spiObjectIdx0);
        appData.spi0_buf_status = DRV_SPI0_BufferStatus(appData.spi0_buf_handle);
        if (appData.spi0_buf_status == DRV_SPI_BUFFER_EVENT_COMPLETE) {

            adc0val = 0;
            adc0val |= (uint32_t) (appData.spi0_rx_bufPtr[3] << 10);
            adc0val |= (uint32_t) (appData.spi0_rx_bufPtr[2] << 2);
            adc0val |= (uint32_t) (appData.spi0_rx_bufPtr[1] >> 6);
            adc0val -= ADC0_OFFSET;

            appData.spi0State = SPI_READ_COMPLETE;
            appData.appState = APP_SEND_REPLY;
        }
    }
    return adc0val;
}

void APP_Initialize(void) {
    appData.appState = APP_STATE_INIT;

    appData.hostMessage.messageState = MESSAGE_IDLE;
    appData.hostMessage.parameterIterator = NO_PARAMETER;
    memset(appData.hostMessage.activeParameter, 0, 6);
    appData.hostMessage.laserState = NONE;
    appData.hostMessage.laserPower = 0;
    appData.hostMessage.galvoState = NONE;
    appData.hostMessage.xPosition = 0;
    appData.hostMessage.yPosition = 0;
    appData.hostMessage.gSpeed = DEFAULT_GALVO_SPEED;
    
    appData.spi0_tx_bufPtr = &spi0_tx_buffer[0];
    appData.spi0_rx_bufPtr = &spi0_rx_buffer[0];

    
    memset(appData.spi0_rx_bufPtr, 0, SPI_RX_BUFF_SIZE);
    memset(appData.spi0_tx_bufPtr, 0, SPI_TX_BUFF_SIZE);

    appData.usart0Handle = DRV_HANDLE_INVALID;
    appData.usart0State = USART_INIT;
    memset(appData.usart0_rx_bufPtr, 0, USART0_RX_BUFF_SIZE);
    appData.usart0_rx_count = 0;
    memset(appData.usart0_tx_bufPtr, 0, USART0_TX_BUFF_SIZE);
    appData.usart0_tx_count = 0;

    appData.spi0Handle = DRV_HANDLE_INVALID;
    appData.spi0State = SPI_INIT_OFFSET;


    DRV_TMR0_CounterValueSet(0xFFFF - 10);
    tmr0_flag = 0;
}

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
                //  LDAC0On();
                appData.spi0State = SPI_IDLE;
            }
            if (appInitialized) {
                set_DAC0_StartVal(0);
                appData.usart0State = USART_INIT;
            }
            break;
        } // END APP_INIT CASE

        case APP_GET_NEW_MESSAGE:
        {
            DRV_USART_TasksReceive(sysObj.drvUsart0);
            USART0_TaskHandler();
            break;
        }

        case APP_PROCESS_MESSAGE:
        {
            appData.DAC0_finalValue = getMessageData(&appData.hostMessage, L_STATE) + DAC0_OFFSET;
            if (appData.DAC0_finalValue > 0x3FFFF)
                appData.DAC0_finalValue = 0x3FFFF;
            else if (appData.DAC0_finalValue < 0)
                appData.DAC0_finalValue = 0;
            if (appData.DAC0_currentValue != appData.DAC0_finalValue) {

                appData.stepSizeX = stepSizeCalc(appData.DAC0_currentValue, appData.DAC0_finalValue, DEFAULT_GALVO_SPEED);

                appData.appState = APP_WRITE_TO_DAC;
                appData.spi0State = SPI_WRITE_START;
                LDAC0On();
                tmr1_flag = 0;
                DRV_TMR1_CounterValueSet(0xFFFF - 188);
                DRV_TMR1_Start();
            } else {
                appData.spi0State = SPI_READ_START;
                appData.appState = APP_READ_FROM_ADC;
            }
            break;
        }

        case APP_WRITE_TO_DAC:
        {
            if ((appData.spi0State == SPI_WRITE_START)&&(tmr1_flag == 0))
                DAC0_Write();
            else if (appData.spi0State == SPI_WRITE_BUSY)
                DAC0_Confirm_Write();

            break;
        } // END APP_WRITE_TO_DAC CASE

        case APP_READ_FROM_ADC:
        {
            appData.ADC0_value = ADC0_Read();
            break;
        } // END APP_READ_FROM_ADC CASE

        case APP_SEND_REPLY:
        {
            DRV_USART_TasksTransmit(sysObj.drvUsart0);
            if (appData.usart0State == USART_IDLE) {

                memset(appData.usart0_tx_bufPtr, 0, USART0_TX_BUFF_SIZE);
                strcpy(appData.usart0_tx_bufPtr, "\r\n@ok:\r\n");
                int j;
                for(j = 0; j < appData.hostMessage.parameterIterator)
                {
                
                
                uint8_t buf[8] = {0, 0, 0, 0, 0, 0, 0, 0};
                uint8_t val = getMessageData(&appData.hostMessage, j);
                
                itoa(buf, appData.hostMessage., 10);
                strcat(buf, "\r\n");
                strcat(appData.usart0_tx_bufPtr, buf);

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
                appData.usart0_tx_length = strlen(appData.usart0_tx_bufPtr);
            }
            USART0_TaskHandler();

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
