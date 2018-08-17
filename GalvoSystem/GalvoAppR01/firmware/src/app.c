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
    /* Place the App state machine in its initial state. */
    appData.state = APP_STATE_INIT;

    DRV_USART_ByteReceiveCallbackSet(DRV_USART_INDEX_0, APP_USARTReceiveEventHandler);
    HCI_Set_RX_Status(HCI_RX_LOOK_FOR_START);

    /* TODO: Initialize your application's state machine and other
     * parameters.
     */
}

/******************************************************************************
  Function:
    void APP_Tasks ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Tasks(void) {

    /* Check the application's current state. */
    switch (appData.state) {
            /* Application's initial state. */
        case APP_STATE_INIT:
        {
            bool appInitialized = true;



            if (appData.usart0_Handle == DRV_HANDLE_INVALID) {
                appData.usart0_Handle =
                        DRV_USART0_Open(DRV_USART_INDEX_0,
                        DRV_IO_INTENT_READWRITE | DRV_IO_INTENT_NONBLOCKING);
                appInitialized &= (DRV_HANDLE_INVALID != appData.usart0_Handle);
            }
            if (appInitialized) {

                appData.state = APP_STATE_SERVICE_TASKS;
            }
            break;
        }

        case APP_STATE_SERVICE_TASKS:
        {

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

void APP_USARTReceiveEventHandler(const SYS_MODULE_INDEX index) {

    //    const uint8_t currentByte = DRV_USART0_ReadByte();
    //    DRV_USART0_WriteByte(currentByte);
    // Byte has been Received. Handle the event.
    // Read byte using DRV_USART_ReadByte.
    static uint8_t USART0_RX_Buffer[USART0_RX_BUFF_SIZE];
    static uint8_t USART0_RX_Count = 0;
    static HCI_REG_INDEX regIndex = 0;

    const uint8_t currentByte = DRV_USART0_ReadByte();

    


    if ((USART0_RX_Count < (USART0_RX_BUFF_SIZE - 2))) {

        switch (HCI_RX_Status()) {
            case HCI_RX_LOOK_FOR_START:
            {
                if (currentByte == '$') {
                    DRV_USART0_WriteByte(currentByte);
                    HCI_Set_RX_Status(HCI_RX_LOOK_FOR_JOB_TYPE);
                }
                break;
            }
            case HCI_RX_LOOK_FOR_JOB_TYPE:
            {

                if ((currentByte == '(')||(currentByte == '/')) {
                    DRV_USART0_WriteByte(currentByte);
                    HCI_REG_Set_Value(JOB_TYPE, HCI_ADD_JOB);
                    HCI_Set_RX_Status(HCI_RX_LOOK_FOR_REG_INDEX);
                } else if (currentByte == '*') {
                    DRV_USART0_WriteByte(currentByte);
                    HCI_REG_Set_Value(JOB_TYPE, HCI_LIST_JOBS);
                    HCI_Set_RX_Status(HCI_RX_COMPLETE);
                } else if (currentByte == '-') {
                    DRV_USART0_WriteByte(currentByte);
                    HCI_REG_Set_Value(JOB_TYPE, HCI_CLEAR_JOBS);
                    HCI_Set_RX_Status(HCI_RX_COMPLETE);
                } else if (currentByte == '{') {
                    DRV_USART0_WriteByte(currentByte);
                    HCI_REG_Set_Value(JOB_TYPE, HCI_RUN_JOB);
                    HCI_Set_RX_Status(HCI_RX_LOOK_FOR_DATA);
                }
                break;
            }

            case HCI_RX_LOOK_FOR_REG_INDEX:
            {
                if((currentByte == ' ')||(currentByte == ',')){
                    DRV_USART0_WriteByte(currentByte);
                    break;
                }
                    switch (currentByte) {
                        case 'n':
                        {
                            regIndex = JOB_NUMBER;
                            break;
                        }
                        case '~':
                        {
                            regIndex = JOB_TYPE;
                            break;
                        }
                        case 'c':
                        {
                            regIndex = COMMAND_TYPE;
                            break;
                        }
                        case 'r':
                        {
                            regIndex = REPLY_TYPE;
                            break;
                        }
                        case 'g':
                        {
                            regIndex = G_STATE;
                            break;
                        }
                        case 's':
                        {
                            regIndex = G_SPEED;
                            break;
                        }

                        case 'x':
                        {
                            regIndex = X_START_POS;
                            break;
                        }
                        case 'X':
                        {
                            regIndex = X_END_POS;
                            break;
                        }
                        case 'y':
                        {
                            regIndex = Y_START_POS;
                            break;
                        }
                        case 'Y':
                        {
                            regIndex = Y_END_POS;
                            break;
                        }
                        case 'i':
                        {
                            regIndex = X_MEASUREMENT;
                            break;
                        }
                        case 'j':
                        {
                            regIndex = Y_MEASUREMENT;
                            break;
                        }
                        case 'l':
                        {
                            regIndex = L_STATE;
                            break;
                        }
                        case 'p':
                        {
                            regIndex = L_POWER;
                            break;
                        }
                        case 'Q':
                        {
                            regIndex = X_DAC_EN;
                            break;
                        }
                        case 'W':
                        {
                            regIndex = Y_DAC_EN;
                            break;
                        }
                        case 'T':
                        {
                            regIndex = X_ADC_EN;
                            break;
                        }
                        case 'V':
                        {
                            regIndex = Y_ADC_EN;
                            break;
                        }
                        case 'L':
                        {
                            regIndex = L_ARM;
                            break;
                        }
                        default:
                        {
                            regIndex = HCI_INVALID_REG_INDEX;
                            break;
                        }
                    }
                    if (regIndex != HCI_INVALID_REG_INDEX) {
                        DRV_USART0_WriteByte(currentByte);
                        HCI_Set_RX_Status(HCI_RX_LOOK_FOR_CMD_TYPE);
                    }
                break;
            }
            case HCI_RX_LOOK_FOR_CMD_TYPE:
            {
             
                 if (currentByte == ':') {
                    DRV_USART0_WriteByte(currentByte);
                    HCI_REG_Host_Add_Read(regIndex);
                    HCI_Set_RX_Status(HCI_RX_LOOK_FOR_REG_INDEX);
                }
                 else if (currentByte == '=') {
                    DRV_USART0_WriteByte(currentByte);
                    HCI_Set_RX_Status(HCI_RX_LOOK_FOR_DATA);
                } 
                break;
            }
            case HCI_RX_LOOK_FOR_DATA:
            {
                if (((currentByte >= '0') && (currentByte <= '9'))
                        || ((currentByte == '-') && (USART0_RX_Count == 0))) {
                    DRV_USART0_WriteByte(currentByte);
                    USART0_RX_Buffer[USART0_RX_Count] = currentByte;
                    USART0_RX_Count++;

                } else if (((currentByte == ' ') || (currentByte == ';')
                        || (currentByte == ')')||(currentByte == ','))
                        & (USART0_RX_Count > 0)) {
                    DRV_USART0_WriteByte(currentByte);

                    int currentVal = stringToInt(USART0_RX_Buffer);
                    HCI_REG_Host_Add_Write(regIndex, currentVal);
                    memset(USART0_RX_Buffer, 0, USART0_RX_Count);
                    USART0_RX_Count = 0;
                    if ((currentByte == ' ')||(currentByte == ',')) {
                        HCI_Set_RX_Status(HCI_RX_LOOK_FOR_REG_INDEX);
                    } else {
                        HCI_Set_RX_Status(HCI_RX_COMPLETE);
                    }
                }else if ((HCI_REG_Value(JOB_TYPE) == HCI_RUN_JOB)
                        && (currentByte == '}')&& (USART0_RX_Count > 0)){
                    DRV_USART0_WriteByte(currentByte);
                    int currentVal = stringToInt(USART0_RX_Buffer);
                    HCI_REG_Host_Add_Write(regIndex, currentVal);
                    memset(USART0_RX_Buffer, 0, USART0_RX_Count);
                    USART0_RX_Count = 0;
                    
                    HCI_Set_RX_Status(HCI_RX_COMPLETE);
                }
                    
                
                break;
            }
            case HCI_RX_COMPLETE:
            {
                HCI_Set_RX_Status(HCI_RX_LOOK_FOR_START);
                DRV_USART0_WriteByte('\r');
                DRV_USART0_WriteByte('\n');
                break;
            }
            default:
                break;
        }
    }
}



/*******************************************************************************
 End of File
 */
