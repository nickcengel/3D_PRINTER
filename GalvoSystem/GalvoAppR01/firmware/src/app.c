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

    APP_JOB_INFO_Initialize();
    APP_GALVO_Initialize();
    APP_LASER_Initialize();

    DRV_USART_ByteReceiveCallbackSet(DRV_USART_INDEX_0, APP_USARTReceiveEventHandler);
    HCI_Set_RX_Status(HCI_RX_LOOK_FOR_START);

    /* TODO: Initialize your application's state machine and other
     * parameters.
     */
}

void APP_GALVO_Initialize(void) {
    appData.Galvo.X.stepSize = 0;
    appData.Galvo.X.currentPosition = 0;
    appData.Galvo.X.finalPosition = DAC0_OFFSET;
    appData.Galvo.X.reading = 0;
    appData.Galvo.X.DAC_enabled = 0;
    appData.Galvo.X.ADC_enabled = 0;

    appData.Galvo.Y.stepSize = 0;
    appData.Galvo.Y.currentPosition = 0;
    appData.Galvo.Y.finalPosition = DAC0_OFFSET;
    appData.Galvo.Y.reading = 0;
    appData.Galvo.Y.DAC_enabled = 0;
    appData.Galvo.Y.ADC_enabled = 0;
}

void APP_LASER_Initialize(void) {
    appData.Laser.armed = 0;
    appData.Laser.enabled = 0;
    appData.Laser.power = 0;
}

void APP_JOB_INFO_Initialize(void) {
    appData.jobInfo.jobNumber = 0;
    appData.jobInfo.jobType = HCI_JOB_UNKNWN;
    appData.jobInfo.replyType = HOST_REQST_REPLY_UNKNWN;

}

void APP_HCI_Initialize(void) {
    HCI_Clear_Data();
    HCI_Clear_REG_Action();
    HCI_Set_RX_Status(HCI_RX_WAIT_FOR_PACKET);
    HCI_Set_TX_Status(HCI_TX_EMPTY);
}

void APP_Read_HCI_Job(void) {
    uint8_t a_index;
    for (a_index = 0; a_index < HCI_PACKET_SIZE; a_index++) {
        if (HCI_REG_Action(a_index) != NO_REG_ACTION) {
            switch (a_index) {
                case JOB_NUMBER:
                {
                    if (HCI_REG_Action(a_index) == REG_WRITE_REQSTD)
                        appData.jobInfo.jobNumber = HCI_REG_Value(a_index);
                    else if (HCI_REG_Action(a_index) == REG_READ_REQSTD)
                        HCI_REG_Set_Value(a_index, appData.jobInfo.jobNumber);
                    break;
                }
                case REPLY_TYPE:
                {
                    if (HCI_REG_Action(a_index) == REG_WRITE_REQSTD)
                        appData.jobInfo.replyType = HCI_REG_Value(a_index);
                    else if (HCI_REG_Action(a_index) == REG_READ_REQSTD)
                        HCI_REG_Set_Value(a_index, appData.jobInfo.replyType);
                    break;
                }
                case G_STATE:
                {
                    if (HCI_REG_Action(a_index) == REG_WRITE_REQSTD)
                        appData.Galvo.state = HCI_REG_Value(a_index);
                    else if (HCI_REG_Action(a_index) == REG_READ_REQSTD)
                        HCI_REG_Set_Value(a_index, appData.Galvo.state);
                    break;
                }
                case G_SPEED:
                {
                    if (HCI_REG_Action(a_index) == REG_WRITE_REQSTD)
                        appData.Galvo.speed = HCI_REG_Value(a_index);
                    else if (HCI_REG_Action(a_index) == REG_READ_REQSTD)
                        HCI_REG_Set_Value(a_index, appData.Galvo.speed);
                    break;
                }
                case X_START_POS:
                {
                    if (HCI_REG_Action(a_index) == REG_WRITE_REQSTD)
                        appData.Galvo.X.currentPosition = HCI_REG_Value(a_index) + DAC0_OFFSET;
                    else if (HCI_REG_Action(a_index) == REG_READ_REQSTD)
                        HCI_REG_Set_Value(a_index, (appData.Galvo.X.currentPosition - DAC0_OFFSET));
                    break;
                }
                case X_END_POS:
                {
                    if (HCI_REG_Action(a_index) == REG_WRITE_REQSTD)
                        appData.Galvo.X.finalPosition = HCI_REG_Value(a_index) + DAC0_OFFSET;
                    else if (HCI_REG_Action(a_index) == REG_READ_REQSTD)
                        HCI_REG_Set_Value(a_index, (appData.Galvo.X.finalPosition - DAC0_OFFSET));
                    break;
                }
                case Y_START_POS:
                {
                    if (HCI_REG_Action(a_index) == REG_WRITE_REQSTD)
                        appData.Galvo.Y.currentPosition = HCI_REG_Value(a_index) + DAC1_OFFSET;
                    else if (HCI_REG_Action(a_index) == REG_READ_REQSTD)
                        HCI_REG_Set_Value(a_index, (appData.Galvo.Y.currentPosition - DAC1_OFFSET));
                    break;
                }
                case Y_END_POS:
                {
                    if (HCI_REG_Action(a_index) == REG_WRITE_REQSTD)
                        appData.Galvo.Y.finalPosition = HCI_REG_Value(a_index) + DAC1_OFFSET;
                    else if (HCI_REG_Action(a_index) == REG_READ_REQSTD)
                        HCI_REG_Set_Value(a_index, (appData.Galvo.Y.finalPosition - DAC1_OFFSET));
                    break;
                }
                case X_MEASUREMENT:
                {
                    if (HCI_REG_Action(a_index) == REG_WRITE_REQSTD)
                        appData.Galvo.X.reading = HCI_REG_Value(a_index);
                    else if (HCI_REG_Action(a_index) == REG_READ_REQSTD)
                        HCI_REG_Set_Value(a_index, appData.Galvo.X.reading);
                    break;
                }
                case Y_MEASUREMENT:
                {
                    if (HCI_REG_Action(a_index) == REG_WRITE_REQSTD)
                        appData.Galvo.Y.reading = HCI_REG_Value(a_index);
                    else if (HCI_REG_Action(a_index) == REG_READ_REQSTD)
                        HCI_REG_Set_Value(a_index, appData.Galvo.Y.reading);
                    break;
                }
                case L_ARM:
                {
                    if (HCI_REG_Action(a_index) == REG_WRITE_REQSTD)
                        appData.Laser.armed = HCI_REG_Value(a_index);
                    else if (HCI_REG_Action(a_index) == REG_READ_REQSTD)
                        HCI_REG_Set_Value(a_index, appData.Laser.armed);
                    break;
                }
                case L_STATE:
                {
                    if (HCI_REG_Action(a_index) == REG_WRITE_REQSTD)
                        appData.Laser.enabled = HCI_REG_Value(a_index);
                    else if (HCI_REG_Action(a_index) == REG_READ_REQSTD)
                        HCI_REG_Set_Value(a_index, appData.Laser.enabled);
                    break;
                }
                case L_POWER:
                {
                    if (HCI_REG_Action(a_index) == REG_WRITE_REQSTD)
                        appData.Laser.power = HCI_REG_Value(a_index);
                    else if (HCI_REG_Action(a_index) == REG_READ_REQSTD)
                        HCI_REG_Set_Value(a_index, appData.Laser.power);
                    break;
                }
                case X_DAC_EN:
                {
                    if (HCI_REG_Action(a_index) == REG_WRITE_REQSTD)
                        appData.Galvo.X.DAC_enabled = HCI_REG_Value(a_index);
                    else if (HCI_REG_Action(a_index) == REG_READ_REQSTD)
                        HCI_REG_Set_Value(a_index, appData.Galvo.X.DAC_enabled);
                    break;
                }
                case Y_DAC_EN:
                {
                    if (HCI_REG_Action(a_index) == REG_WRITE_REQSTD)
                        appData.Galvo.Y.DAC_enabled = HCI_REG_Value(a_index);
                    else if (HCI_REG_Action(a_index) == REG_READ_REQSTD)
                        HCI_REG_Set_Value(a_index, appData.Galvo.Y.DAC_enabled);
                    break;
                }
                case X_ADC_EN:
                {
                    if (HCI_REG_Action(a_index) == REG_WRITE_REQSTD)
                        appData.Galvo.X.ADC_enabled = HCI_REG_Value(a_index);
                    else if (HCI_REG_Action(a_index) == REG_READ_REQSTD)
                        HCI_REG_Set_Value(a_index, appData.Galvo.X.ADC_enabled);
                    break;
                }
                case Y_ADC_EN:
                {
                    if (HCI_REG_Action(a_index) == REG_WRITE_REQSTD)
                        appData.Galvo.Y.ADC_enabled = HCI_REG_Value(a_index);
                    else if (HCI_REG_Action(a_index) == REG_READ_REQSTD)
                        HCI_REG_Set_Value(a_index, appData.Galvo.Y.ADC_enabled);
                    break;
                }
                default:
                    break;
            }
        }
    }
}

bool APP_Write_HCI_Reply(void) {
    static uint8_t USART0_TX_Buffer[USART0_TX_BUFF_SIZE];
    static uint8_t client_replyLength = 0;
    static uint8_t USART0_TX_Count = 0;

    uint8_t t_index;
    bool txComplete = 0;
    int32_t tempVal;
    uint8_t tempLength = 0;
    bool validIndex = 1;
    uint8_t tempNumBuf[6];
    uint8_t tempTextBuf[32];

    switch (HCI_TX_Status()) {
        case HCI_TX_EMPTY:
        {
            DRV_USART0_WriteByte('\r');
            DRV_USART0_WriteByte('\n');
            for (t_index = 0; t_index < (HCI_PACKET_SIZE - 1); t_index++) {
                if (HCI_REG_Action(t_index) != NO_REG_ACTION) {


                    switch (t_index) {
                        case JOB_NUMBER:
                        {
                            strcpy(tempTextBuf, "\r\nJob_#");
                            tempVal = HCI_REG_Value(JOB_NUMBER);
                            break;
                        }
                        case JOB_TYPE:
                        {
                            strcpy(tempTextBuf, "\r\nJob_t");
                            tempVal = HCI_REG_Value(JOB_TYPE);

                            break;
                        }
                        case REPLY_TYPE:
                        {
                            strcpy(tempTextBuf, "Reply_t");
                            tempVal = HCI_REG_Value(REPLY_TYPE);
                            break;
                        }
                        case G_STATE:
                        {
                            strcpy(tempTextBuf, "GalvoState");
                            tempVal = HCI_REG_Value(G_STATE);
                            break;
                        }
                        case G_SPEED:
                        {
                            strcpy(tempTextBuf, "GalvoSpeed");
                            tempVal = HCI_REG_Value(G_SPEED);
                            break;
                        }
                        case X_START_POS:
                        {
                            strcpy(tempTextBuf, "X_start");
                            tempVal = HCI_REG_Value(X_START_POS);
                            break;
                        }
                        case X_END_POS:
                        {
                            strcpy(tempTextBuf, "X_end");
                            tempVal = HCI_REG_Value(X_END_POS);
                            break;
                        }
                        case Y_START_POS:
                        {
                            strcpy(tempTextBuf, "Y_start");
                            tempVal = HCI_REG_Value(Y_START_POS);
                            break;
                        }
                        case Y_END_POS:
                        {
                            strcpy(tempTextBuf, "Y_end");
                            tempVal = HCI_REG_Value(Y_END_POS);
                            break;
                        }
                        case X_MEASUREMENT:
                        {
                            strcpy(tempTextBuf, "X_reading");
                            tempVal = HCI_REG_Value(X_MEASUREMENT);
                            break;
                        }
                        case Y_MEASUREMENT:
                        {
                            strcpy(tempTextBuf, "Y_reading");
                            tempVal = HCI_REG_Value(Y_MEASUREMENT);
                            break;
                        }
                        case L_ARM:
                        {
                            strcpy(tempTextBuf, "LaserArmed");
                            tempVal = HCI_REG_Value(L_ARM);
                            break;
                        }
                        case L_STATE:
                        {
                            strcpy(tempTextBuf, "LaserState");
                            tempVal = HCI_REG_Value(L_STATE);
                            break;
                        }
                        case L_POWER:
                        {
                            strcpy(tempTextBuf, "LaserPower");
                            tempVal = HCI_REG_Value(L_POWER);
                            break;
                        }
                        case X_DAC_EN:
                        {
                            strcpy(tempTextBuf, "X_DacEnabled");
                            tempVal = HCI_REG_Value(X_DAC_EN);
                            break;
                        }
                        case Y_DAC_EN:
                        {
                            strcpy(tempTextBuf, "Y_DacEnabled");
                            tempVal = HCI_REG_Value(Y_DAC_EN);
                            break;
                        }
                        case X_ADC_EN:
                        {
                            strcpy(tempTextBuf, "X_AdcEnabled");
                            tempVal = HCI_REG_Value(X_ADC_EN);
                            break;
                        }
                        case Y_ADC_EN:
                        {
                            strcpy(tempTextBuf, "Y_AdcEnabled");
                            tempVal = HCI_REG_Value(Y_ADC_EN);
                            break;
                        }
                        default:
                        {
                            validIndex = 0;
                            break;
                        }
                    }
                    if (validIndex) {
                        if (HCI_REG_Action(t_index) == REG_READ_REQSTD)
                            strcat(tempTextBuf, " -> ");
                        else if (HCI_REG_Action(t_index) == REG_WRITE_REQSTD)
                            strcat(tempTextBuf, " <- ");
                        itoa(tempNumBuf, tempVal, 10);
                        strcat(tempTextBuf, tempNumBuf);
                        strcat(tempTextBuf, "\r\n");
                        tempLength = strlen(tempTextBuf) + client_replyLength;
                        if (tempLength < USART0_TX_BUFF_SIZE) {
                            strcat(USART0_TX_Buffer, tempTextBuf);
                            client_replyLength = tempLength;
                            tempVal = 0;
                            tempLength = 0;
                            memset(tempNumBuf, 0, 6);
                            memset(tempTextBuf, 0, 32);
                        }
                    }
                }
            }

            strcat(USART0_TX_Buffer, "\r\n");

            HCI_Set_TX_Status(HCI_TX_PENDING);
            break;
        }
        case HCI_TX_PENDING:
        {
            if (USART0_TX_Count < client_replyLength) {
                if (!DRV_USART0_TransmitBufferIsFull()) {
                    DRV_USART0_WriteByte(USART0_TX_Buffer[USART0_TX_Count]);
                    USART0_TX_Count++;
                }
            } else {
                HCI_Set_TX_Status(HCI_TX_COMPLETE);

            }
            break;
        }
        case HCI_TX_COMPLETE:
        {
            memset(USART0_TX_Buffer, 0, client_replyLength);
            USART0_TX_Count = 0;
            client_replyLength = 0;
            HCI_Set_TX_Status(HCI_TX_EMPTY);
            txComplete = 1;

            break;
        }
        default:
            break;
    }
    return txComplete;
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

                appData.state = APP_READ_FROM_HOST;
            }
            break;
        }

        case APP_READ_FROM_HOST:
        {
            switch (HCI_RX_Status()) {
                case HCI_RX_WAIT_FOR_PACKET:
                {
                    HCI_Clear_Data();
                    HCI_Clear_REG_Action();
                    HCI_Set_RX_Status(HCI_RX_LOOK_FOR_START);
                    break;
                }
                case HCI_RX_COMPLETE:
                {
                    APP_Read_HCI_Job();
                    appData.state = APP_WRITE_TO_HOST;
                    break;
                }
                default:
                    break;
            }
            break;
        }
        case APP_WRITE_TO_HOST:
        {
            if (APP_Write_HCI_Reply() != 0) {
                HCI_Set_RX_Status(HCI_RX_WAIT_FOR_PACKET);
                appData.state = APP_READ_FROM_HOST;
            }
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

                if ((currentByte == '(') || (currentByte == '/')) {
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
                if ((currentByte == ')') || (currentByte == ';')) {
                    DRV_USART0_WriteByte(currentByte);
                    HCI_Set_RX_Status(HCI_RX_COMPLETE);
                    break;
                } else if ((currentByte == ' ') || (currentByte == ',')) {
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
                    case 'L':
                    {
                        regIndex = L_ARM;
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
                } else if (currentByte == '=') {
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
                        || (currentByte == ')') || (currentByte == ','))
                        & (USART0_RX_Count > 0)) {
                    DRV_USART0_WriteByte(currentByte);

                    int currentVal = stringToInt(USART0_RX_Buffer);
                    HCI_REG_Host_Add_Write(regIndex, currentVal);
                    memset(USART0_RX_Buffer, 0, USART0_RX_Count);
                    USART0_RX_Count = 0;
                    if ((currentByte == ' ') || (currentByte == ',')) {
                        HCI_Set_RX_Status(HCI_RX_LOOK_FOR_REG_INDEX);
                    } else {
                        HCI_Set_RX_Status(HCI_RX_COMPLETE);
                    }
                } else if ((HCI_REG_Value(JOB_TYPE) == HCI_RUN_JOB)
                        && (currentByte == '}')&& (USART0_RX_Count > 0)) {
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
