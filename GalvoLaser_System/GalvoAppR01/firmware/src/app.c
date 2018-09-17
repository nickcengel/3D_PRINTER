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

APP_DATA appData;

uint8_t volatile GALVO_ADC_Flag;
uint8_t volatile GALVO_DAC_Latched;

DRV_SPI_BUFFER_EVENT volatile spi0_tx_status;
DRV_SPI_BUFFER_EVENT volatile spi0_rx_status;
DRV_SPI_BUFFER_EVENT volatile spi1_tx_status;
DRV_SPI_BUFFER_EVENT volatile spi1_rx_status;

DRV_SPI_BUFFER_EVENT volatile APP_SPI0_RX_Status(void) {
    return spi0_rx_status;
}

DRV_SPI_BUFFER_EVENT volatile APP_SPI0_TX_Status(void) {
    return spi0_tx_status;
}

DRV_SPI_BUFFER_EVENT volatile APP_SPI1_RX_Status(void) {
    return spi1_rx_status;
}

DRV_SPI_BUFFER_EVENT volatile APP_SPI1_TX_Status(void) {
    return spi1_tx_status;
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

void APP_USARTReceiveEventHandler(const SYS_MODULE_INDEX index) {
    static uint8_t USART0_RX_Buffer[USART0_RX_BUFF_SIZE];
    static uint8_t USART0_RX_Count = 0;
    static HCI_REG_INDEX regIndex = 0;
    const uint8_t currentByte = DRV_USART0_ReadByte();
    if (USART0_RX_Count < (USART0_RX_BUFF_SIZE - 2)) {
        switch (HCI_RX_Status()) {
            case HCI_RX_LOOK_FOR_START:
            {
                if (currentByte == '$') {
                   // DRV_USART0_WriteByte(currentByte);
                    HCI_Set_RX_Status(HCI_RX_LOOK_FOR_JOB_TYPE);
                }
                break;
            }
            case HCI_RX_LOOK_FOR_JOB_TYPE:
            {
                if ((currentByte == '(') || (currentByte == '/')) {
                 //   DRV_USART0_WriteByte(currentByte);
                    HCI_REG_Set_Value(JOB_TYPE, HCI_ADD_JOB);
                    HCI_Set_RX_Status(HCI_RX_LOOK_FOR_REG_INDEX);
                } else if (currentByte == '*') {
                  //  DRV_USART0_WriteByte(currentByte);
                    HCI_REG_Set_Value(JOB_TYPE, HCI_LIST_JOBS);
                    HCI_Set_RX_Status(HCI_RX_COMPLETE);
                } else if (currentByte == '-') {
                   // DRV_USART0_WriteByte(currentByte);
                    HCI_REG_Set_Value(JOB_TYPE, HCI_CLEAR_JOBS);
                    HCI_Set_RX_Status(HCI_RX_COMPLETE);
                } else if (currentByte == '{') {
                   // DRV_USART0_WriteByte(currentByte);
                    HCI_REG_Set_Value(JOB_TYPE, HCI_RUN_JOB);
                    HCI_Set_RX_Status(HCI_RX_LOOK_FOR_DATA);
                } else if (currentByte == 'E') {
                  //  DRV_USART0_WriteByte(currentByte);
                    DRV0_EN_PINOff();
                    DRV1_EN_PINOff();
                    HCI_Set_RX_Status(HCI_RX_COMPLETE);
                } else if (currentByte == 'e') {
                    DRV_USART0_WriteByte(currentByte);
                    DRV0_EN_PINOn();
                    DRV1_EN_PINOn();
                    HCI_Set_RX_Status(HCI_RX_COMPLETE);
                } else if (currentByte == 'R') {
                   // DRV_USART0_WriteByte(currentByte);
                    SYS_INT_StatusGetAndDisable();
                    SYS_RESET_SoftwareReset();
                }
                break;
            }
            case HCI_RX_LOOK_FOR_REG_INDEX:
            {
                if ((currentByte == ')') || (currentByte == ';')) {
                    //DRV_USART0_WriteByte(currentByte);
                    HCI_Set_RX_Status(HCI_RX_COMPLETE);
                    break;
                } else if ((currentByte == ' ') || (currentByte == ',')) {
                   // DRV_USART0_WriteByte(currentByte);
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
                    //DRV_USART0_WriteByte(currentByte);
                    HCI_Set_RX_Status(HCI_RX_LOOK_FOR_CMD_TYPE);
                }
                break;
            }
            case HCI_RX_LOOK_FOR_CMD_TYPE:
            {
                if (currentByte == ':') {
                    //DRV_USART0_WriteByte(currentByte);
                    HCI_REG_Host_Add_Read(regIndex);
                    HCI_Set_RX_Status(HCI_RX_LOOK_FOR_REG_INDEX);
                } else if (currentByte == '=') {
                    //DRV_USART0_WriteByte(currentByte);
                    HCI_Set_RX_Status(HCI_RX_LOOK_FOR_DATA);
                }
                break;
            }
            case HCI_RX_LOOK_FOR_DATA:
            {
                if (((currentByte >= '0') && (currentByte <= '9'))
                        || ((currentByte == '-') && (USART0_RX_Count == 0))) {
                    //DRV_USART0_WriteByte(currentByte);
                    USART0_RX_Buffer[USART0_RX_Count] = currentByte;
                    USART0_RX_Count++;
                } else if (((currentByte == ' ') || (currentByte == ';')
                        || (currentByte == ')') || (currentByte == ','))
                        & (USART0_RX_Count > 0)) {
                    //DRV_USART0_WriteByte(currentByte);

                    int currentVal = APP_Convert_String_To_Int(USART0_RX_Buffer);
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
                    //DRV_USART0_WriteByte(currentByte);
                    int currentVal = APP_Convert_String_To_Int(USART0_RX_Buffer);
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
//                DRV_USART0_WriteByte('\r');
//                DRV_USART0_WriteByte('\n');
                break;
            }
            default:
                break;
        }
    }
}

void APP_DAC0_CallBack_Start(DRV_SPI_BUFFER_EVENT eEvent, DRV_SPI_BUFFER_HANDLE bufferHandle, void *context) {
    DAC0_LATCH_PINOn();
    DAC0_CS_PINOff();
    GALVO_DAC_Latched = 0;
    spi0_tx_status = eEvent;
}

void APP_DAC0_CallBack_End(DRV_SPI_BUFFER_EVENT eEvent, DRV_SPI_BUFFER_HANDLE bufferHandle, void *context) {
    DAC0_CS_PINOn();
    spi0_tx_status = eEvent;
}

void APP_ADC0_CallBack_Start(DRV_SPI_BUFFER_EVENT eEvent, DRV_SPI_BUFFER_HANDLE bufferHandle, void *context) {
    spi0_rx_status = eEvent;
}

void APP_ADC0_CallBack_End(DRV_SPI_BUFFER_EVENT eEvent, DRV_SPI_BUFFER_HANDLE bufferHandle, void *context) {
    spi0_rx_status = eEvent;
}

void APP_DAC1_CallBack_Start(DRV_SPI_BUFFER_EVENT eEvent, DRV_SPI_BUFFER_HANDLE bufferHandle, void *context) {
    DAC1_LATCH_PINOn();
    DAC1_CS_PINOff();
    GALVO_DAC_Latched = 0;
    spi1_tx_status = eEvent;
}

void APP_DAC1_CallBack_End(DRV_SPI_BUFFER_EVENT eEvent, DRV_SPI_BUFFER_HANDLE bufferHandle, void *context) {
    DAC1_CS_PINOn();
    spi1_tx_status = eEvent;
}

void APP_ADC1_CallBack_Start(DRV_SPI_BUFFER_EVENT eEvent, DRV_SPI_BUFFER_HANDLE bufferHandle, void *context) {
    spi1_rx_status = eEvent;
}

void APP_ADC1_CallBack_End(DRV_SPI_BUFFER_EVENT eEvent, DRV_SPI_BUFFER_HANDLE bufferHandle, void *context) {
    spi1_rx_status = eEvent;
}

void __ISR(_TIMER_2_VECTOR, ipl2AUTO) IntHandlerDrvTmrInstance0(void) {
    DRV_TMR0_CounterValueSet(0xFFFF - DAC_UPDATE_PERIOD_COUNTS);
    if ((spi0_tx_status == DRV_SPI_BUFFER_EVENT_COMPLETE)
            && (spi1_tx_status == DRV_SPI_BUFFER_EVENT_COMPLETE)) {
        DAC0_LATCH_PINOff();
        DAC1_LATCH_PINOff();
        GALVO_DAC_Latched = 1;
    }
    PLIB_INT_SourceFlagClear(INT_ID_0, INT_SOURCE_TIMER_2);
}

void __ISR(_TIMER_4_VECTOR, ipl2AUTO) IntHandlerDrvTmrInstance1(void) {
    DRV_TMR1_Stop();
    GALVO_ADC_Flag = 1;
    PLIB_INT_SourceFlagClear(INT_ID_0, INT_SOURCE_TIMER_4);
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************

int32_t APP_Convert_String_To_Int(uint8_t *str) {
    int8_t sign = 1;

    if (str[0] == '-') {
        sign = -1;
        str[0] = ' ';
    }
    return (sign * atoi(str));
}

void APP_Compute_StepSize(void) {

    uint32_t deltaX = 0;
    uint32_t deltaY = 0;

    if (appData.Galvo.X.finalPosition > appData.Galvo.X.currentPosition)
        deltaX = appData.Galvo.X.finalPosition - appData.Galvo.X.currentPosition;
    else
        deltaX = appData.Galvo.X.currentPosition - appData.Galvo.X.finalPosition;

    if (appData.Galvo.Y.finalPosition > appData.Galvo.Y.currentPosition)
        deltaY = appData.Galvo.Y.finalPosition - appData.Galvo.Y.currentPosition;
    else
        deltaY = appData.Galvo.Y.currentPosition - appData.Galvo.Y.finalPosition;

    uint32_t distance = ((uint32_t) sqrt((float) deltaX * (float) deltaX + (float) deltaY * (float) deltaY)) << 10;
    if (distance > 0) {
        if ((appData.Galvo.speed >> 10) < 0x400)
            appData.Galvo.speed = 0x400;
        uint32_t duration = ((distance / appData.Galvo.speed) << 10);
        uint32_t numIncrements = (uint32_t) (((float) duration) / DAC_UPDATE_PERIOD_uS);
        if (numIncrements < 1)
            numIncrements = 1;
        appData.Galvo.X.stepSize = ((deltaX << 10) / numIncrements);
        appData.Galvo.Y.stepSize = ((deltaY << 10) / numIncrements);
    } else {
        appData.Galvo.X.stepSize = 0;
        appData.Galvo.Y.stepSize = 0;
    }
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

// Initialization
// *****************************************************************************

void APP_SPI0_Initialize(void) {
    appData.drvSPI0.drvHandle = DRV_HANDLE_INVALID;
    appData.drvSPI0.DAC_clientData.baudRate = 25000000;
    appData.drvSPI0.DAC_clientData.operationStarting = APP_DAC0_CallBack_Start;
    appData.drvSPI0.DAC_clientData.operationEnded = APP_DAC0_CallBack_End;
    spi0_tx_status = DRV_SPI_BUFFER_EVENT_COMPLETE;
    appData.drvSPI0.ADC_clientData.baudRate = 12500000;
    appData.drvSPI0.ADC_clientData.operationStarting = APP_ADC0_CallBack_Start;
    appData.drvSPI0.ADC_clientData.operationEnded = APP_ADC0_CallBack_End;
    spi0_rx_status = DRV_SPI_BUFFER_EVENT_COMPLETE;
}

void APP_SPI1_Initialize(void) {
    appData.drvSPI1.drvHandle = DRV_HANDLE_INVALID;
    appData.drvSPI1.DAC_clientData.baudRate = 25000000;
    appData.drvSPI1.DAC_clientData.operationStarting = APP_DAC1_CallBack_Start;
    appData.drvSPI1.DAC_clientData.operationEnded = APP_DAC1_CallBack_End;
    spi1_tx_status = DRV_SPI_BUFFER_EVENT_COMPLETE;
    appData.drvSPI1.ADC_clientData.baudRate = 12500000;
    appData.drvSPI1.ADC_clientData.operationStarting = APP_ADC1_CallBack_Start;
    appData.drvSPI1.ADC_clientData.operationEnded = APP_ADC1_CallBack_End;
    spi1_rx_status = DRV_SPI_BUFFER_EVENT_COMPLETE;
}

void APP_GALVO_Initialize(void) {
    appData.Galvo.state = GVO_ABSOLUTE_MOVE;
    appData.Galvo.X.processComplete = 0;
    appData.Galvo.X.stepSize = 0;
    appData.Galvo.X.currentPosition = DAC0_OFFSET;
    appData.Galvo.X.finalPosition = DAC0_OFFSET;
    appData.Galvo.X.reading = 0;
    appData.Galvo.X.DAC_enabled = 0;
    appData.Galvo.X.ADC_enabled = 0;
    appData.Galvo.Y.processComplete = 0;
    appData.Galvo.Y.stepSize = 0;
    appData.Galvo.Y.currentPosition = DAC1_OFFSET;
    appData.Galvo.Y.finalPosition = DAC1_OFFSET;
    appData.Galvo.Y.reading = 0;
    appData.Galvo.Y.DAC_enabled = 0;
    appData.Galvo.Y.ADC_enabled = 0;
    appData.Galvo.speed = GALVO_DEFAULT_SPEED;
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

void APP_Initialize(void) {
    DRV0_EN_PINOff();
    DRV1_EN_PINOff();
    appData.state = APP_STATE_INIT;
    GALVO_ADC_Flag = 0;
    GALVO_DAC_Latched = 0;
    APP_SPI0_Initialize();
    APP_SPI1_Initialize();
    APP_JOB_INFO_Initialize();
    APP_GALVO_Initialize();
    APP_LASER_Initialize();
    DRV_USART_ByteReceiveCallbackSet(DRV_USART_INDEX_0, APP_USARTReceiveEventHandler);
    HCI_Set_RX_Status(HCI_RX_LOOK_FOR_START);
}

// Host<->Client Interface Processes
// *****************************************************************************

void APP_Open_HCI_Packet(void) {
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
                    if ((HCI_REG_Action(a_index) == REG_WRITE_REQSTD)&&(appData.Galvo.state != GVO_RELATIVE_MOVE))
                        appData.Galvo.X.currentPosition = ((HCI_REG_Value(a_index) + DAC0_OFFSET));
                    else if (HCI_REG_Action(a_index) == REG_READ_REQSTD)
                        HCI_REG_Set_Value(a_index, ((appData.Galvo.X.currentPosition) - DAC0_OFFSET));
                    break;
                }
                case X_END_POS:
                {
                    if (HCI_REG_Action(a_index) == REG_WRITE_REQSTD) {
                        if (appData.Galvo.state == GVO_RELATIVE_MOVE)
                            appData.Galvo.X.finalPosition = HCI_REG_Value(a_index) + appData.Galvo.X.currentPosition;
                        else
                            appData.Galvo.X.finalPosition = HCI_REG_Value(a_index) + DAC0_OFFSET;
                    } else if (HCI_REG_Action(a_index) == REG_READ_REQSTD)
                        HCI_REG_Set_Value(a_index, ((appData.Galvo.X.finalPosition) - DAC0_OFFSET));
                    break;
                }
                case Y_START_POS:
                {
                    if ((HCI_REG_Action(a_index) == REG_WRITE_REQSTD)&&(appData.Galvo.state != GVO_RELATIVE_MOVE))
                        appData.Galvo.Y.finalPosition = ((HCI_REG_Value(a_index) + DAC1_OFFSET));
                    else if (HCI_REG_Action(a_index) == REG_READ_REQSTD)
                        HCI_REG_Set_Value(a_index, ((appData.Galvo.Y.finalPosition) - DAC1_OFFSET));
                    break;
                }
                case Y_END_POS:
                {
                    if (HCI_REG_Action(a_index) == REG_WRITE_REQSTD) {
                        if (appData.Galvo.state == GVO_RELATIVE_MOVE)
                            appData.Galvo.Y.finalPosition = HCI_REG_Value(a_index) + appData.Galvo.Y.currentPosition;
                        else
                            appData.Galvo.Y.finalPosition = HCI_REG_Value(a_index) + DAC1_OFFSET;
                    } else if (HCI_REG_Action(a_index) == REG_READ_REQSTD)
                        HCI_REG_Set_Value(a_index, ((appData.Galvo.Y.finalPosition) - DAC1_OFFSET));
                    break;
                }
                case X_MEASUREMENT:
                {
                    break;
                }
                case Y_MEASUREMENT:
                {
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
    if ((appData.Galvo.X.DAC_enabled || appData.Galvo.Y.DAC_enabled)
            && ((HCI_REG_Action(X_END_POS) == REG_WRITE_REQSTD)
            || (HCI_REG_Action(Y_END_POS) == REG_WRITE_REQSTD))) {
        appData.Galvo.DAC_jobPending = 1;
    }
    if ((appData.Galvo.X.ADC_enabled || appData.Galvo.Y.ADC_enabled)
            && ((HCI_REG_Action(X_MEASUREMENT) == REG_READ_REQSTD)
            || (HCI_REG_Action(Y_MEASUREMENT) == REG_READ_REQSTD))) {

        appData.Galvo.ADC_jobPending = 1;
    }
}

void APP_Write_HCI_Packet(void) {
    static uint8_t USART0_TX_Buffer[USART0_TX_BUFF_SIZE];
    static uint8_t client_replyLength = 0;
    static uint8_t USART0_TX_Count = 0;

    uint8_t t_index;
    int32_t tempVal;
    uint8_t tempLength = 0;
    bool validIndex = 1;
    uint8_t tempNumBuf[6];
    uint8_t tempTextBuf[32];

    switch (HCI_TX_Status()) {
        case HCI_TX_EMPTY:
        {
            
//            DRV_USART0_WriteByte('\r');
//            DRV_USART0_WriteByte('\n');
//            for (t_index = 0; t_index < (HCI_PACKET_SIZE - 1); t_index++) {
//                if (HCI_REG_Action(t_index) != NO_REG_ACTION) {
//                    switch (t_index) {
//                        case JOB_NUMBER:
//                        {
//                            strcpy(tempTextBuf, "\r\nJob_#");
//                            tempVal = HCI_REG_Value(JOB_NUMBER);
//                            break;
//                        }
//                        case JOB_TYPE:
//                        {
//                            strcpy(tempTextBuf, "\r\nJob_t");
//                            tempVal = HCI_REG_Value(JOB_TYPE);
//
//                            break;
//                        }
//                        case REPLY_TYPE:
//                        {
//                            strcpy(tempTextBuf, "Reply_t");
//                            tempVal = HCI_REG_Value(REPLY_TYPE);
//                            break;
//                        }
//                        case G_STATE:
//                        {
//                            strcpy(tempTextBuf, "GalvoState");
//                            tempVal = HCI_REG_Value(G_STATE);
//                            break;
//                        }
//                        case G_SPEED:
//                        {
//                            strcpy(tempTextBuf, "GalvoSpeed");
//                            tempVal = HCI_REG_Value(G_SPEED);
//                            break;
//                        }
//                        case X_START_POS:
//                        {
//                            strcpy(tempTextBuf, "X_start");
//                            tempVal = HCI_REG_Value(X_START_POS);
//                            break;
//                        }
//                        case X_END_POS:
//                        {
//                            strcpy(tempTextBuf, "X_end");
//                            tempVal = HCI_REG_Value(X_END_POS);
//                            break;
//                        }
//                        case Y_START_POS:
//                        {
//                            strcpy(tempTextBuf, "Y_start");
//                            tempVal = HCI_REG_Value(Y_START_POS);
//                            break;
//                        }
//                        case Y_END_POS:
//                        {
//                            strcpy(tempTextBuf, "Y_end");
//                            tempVal = HCI_REG_Value(Y_END_POS);
//                            break;
//                        }
//                        case X_MEASUREMENT:
//                        {
//                            strcpy(tempTextBuf, "X_reading");
//                            tempVal = appData.Galvo.X.reading - ADC0_OFFSET;
//                            break;
//                        }
//                        case Y_MEASUREMENT:
//                        {
//                            strcpy(tempTextBuf, "Y_reading");
//                            tempVal = appData.Galvo.Y.reading - ADC1_OFFSET;
//                            break;
//                        }
//                        case L_ARM:
//                        {
//                            strcpy(tempTextBuf, "LaserArmed");
//                            tempVal = HCI_REG_Value(L_ARM);
//                            break;
//                        }
//                        case L_STATE:
//                        {
//                            strcpy(tempTextBuf, "LaserState");
//                            tempVal = HCI_REG_Value(L_STATE);
//                            break;
//                        }
//                        case L_POWER:
//                        {
//                            strcpy(tempTextBuf, "LaserPower");
//                            tempVal = HCI_REG_Value(L_POWER);
//                            break;
//                        }
//                        case X_DAC_EN:
//                        {
//                            strcpy(tempTextBuf, "X_DacEnabled");
//                            tempVal = HCI_REG_Value(X_DAC_EN);
//                            break;
//                        }
//                        case Y_DAC_EN:
//                        {
//                            strcpy(tempTextBuf, "Y_DacEnabled");
//                            tempVal = HCI_REG_Value(Y_DAC_EN);
//                            break;
//                        }
//                        case X_ADC_EN:
//                        {
//                            strcpy(tempTextBuf, "X_AdcEnabled");
//                            tempVal = HCI_REG_Value(X_ADC_EN);
//                            break;
//                        }
//                        case Y_ADC_EN:
//                        {
//                            strcpy(tempTextBuf, "Y_AdcEnabled");
//                            tempVal = HCI_REG_Value(Y_ADC_EN);
//                            break;
//                        }
//                        default:
//                        {
//                            validIndex = 0;
//                            break;
//                        }
//                    }
//                    if (validIndex) {
//                        if (HCI_REG_Action(t_index) == REG_READ_REQSTD)
//                            strcat(tempTextBuf, " -> ");
//                        else if (HCI_REG_Action(t_index) == REG_WRITE_REQSTD)
//                            strcat(tempTextBuf, " <- ");
//                        itoa(tempNumBuf, tempVal, 10);
//                        strcat(tempTextBuf, tempNumBuf);
//                        strcat(tempTextBuf, "\r\n");
//                        tempLength = strlen(tempTextBuf) + client_replyLength;
//                        if (tempLength < USART0_TX_BUFF_SIZE) {
//                            strcat(USART0_TX_Buffer, tempTextBuf);
//                            client_replyLength = tempLength;
//                            tempVal = 0;
//                            tempLength = 0;
//                            memset(tempNumBuf, 0, 6);
//                            memset(tempTextBuf, 0, 32);
//                        }
//                    }
//                }
//            }
            
            strcpy(USART0_TX_Buffer, "@ok");
            client_replyLength = strlen(USART0_TX_Buffer);
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
            appData.HCI_WritePending = 0;

            break;
        }
        default:
            break;
    }
}

// Galvo Interface Processes
// *****************************************************************************

void APP_GALVO_Launch_DAC_Process(void) {
    if (appData.Galvo.X.DAC_enabled) {
        DRV_SPI0_ClientConfigure(&(appData.drvSPI0.DAC_clientData));
        appData.Galvo.X.processComplete = 0;
    } else
        appData.Galvo.X.processComplete = 1;
    if (appData.Galvo.Y.DAC_enabled) {
        DRV_SPI1_ClientConfigure(&(appData.drvSPI1.DAC_clientData));
        appData.Galvo.Y.processComplete = 0;
    } else
        appData.Galvo.Y.processComplete = 1;

    APP_Compute_StepSize();
    DRV_TMR0_CounterValueSet(0xFFFF - DAC_UPDATE_PERIOD_COUNTS);
    DRV_TMR0_Start();
    appData.state = APP_WRITE_TO_GALVO;

}

void APP_GALVO_Run_DAC_Process(void) {
    static uint8_t SPI0_TX_Buffer[SPI_TX_BUFF_SIZE];
    static uint8_t SPI1_TX_Buffer[SPI_TX_BUFF_SIZE];
    while (appData.Galvo.DAC_jobPending) {

        if (appData.Galvo.X.DAC_enabled) {
            if (appData.Galvo.X.currentPosition < appData.Galvo.X.finalPosition) {
                appData.Galvo.X.currentPosition += appData.Galvo.X.stepSize;
                if (appData.Galvo.X.currentPosition > appData.Galvo.X.finalPosition) {
                    appData.Galvo.X.currentPosition = appData.Galvo.X.finalPosition;
                    appData.Galvo.X.processComplete = 1;
                }
            } else if (appData.Galvo.X.currentPosition > appData.Galvo.X.finalPosition) {
                appData.Galvo.X.currentPosition -= appData.Galvo.X.stepSize;
                if (appData.Galvo.X.currentPosition < appData.Galvo.X.finalPosition) {
                    appData.Galvo.X.currentPosition = appData.Galvo.X.finalPosition;
                    appData.Galvo.X.processComplete = 1;
                }
            } else
                appData.Galvo.X.processComplete = 1;

            const uint32_t datax = appData.Galvo.X.currentPosition;

            SPI0_TX_Buffer[0] = DAC_DIN_REG_WRITE << 4;
            SPI0_TX_Buffer[0] |= (0xFF & (datax >> 14));
            SPI0_TX_Buffer[1] = (0xFF & (datax >> 6));
            SPI0_TX_Buffer[2] = (0xFF & (datax << 2));
            DRV_SPI0_BufferAddWrite(SPI0_TX_Buffer, 3, 0, 0);
        }

        if (appData.Galvo.Y.DAC_enabled) {
            if (appData.Galvo.Y.currentPosition < appData.Galvo.Y.finalPosition) {
                appData.Galvo.Y.currentPosition += appData.Galvo.Y.stepSize;
                if (appData.Galvo.Y.currentPosition > appData.Galvo.Y.finalPosition) {
                    appData.Galvo.Y.currentPosition = appData.Galvo.Y.finalPosition;
                    appData.Galvo.Y.processComplete = 1;
                }
            } else if (appData.Galvo.Y.currentPosition > appData.Galvo.Y.finalPosition) {
                appData.Galvo.Y.currentPosition -= appData.Galvo.Y.stepSize;
                if (appData.Galvo.Y.currentPosition < appData.Galvo.Y.finalPosition) {
                    appData.Galvo.Y.currentPosition = appData.Galvo.Y.finalPosition;
                    appData.Galvo.Y.processComplete = 1;
                }
            } else
                appData.Galvo.Y.processComplete = 1;

            const uint32_t datay = appData.Galvo.Y.currentPosition;

            SPI1_TX_Buffer[0] = DAC_DIN_REG_WRITE << 4;
            SPI1_TX_Buffer[0] |= (0xFF & (datay >> 14));
            SPI1_TX_Buffer[1] = (0xFF & (datay >> 6));
            SPI1_TX_Buffer[2] = (0xFF & (datay << 2));
            DRV_SPI1_BufferAddWrite(SPI1_TX_Buffer, 3, 0, 0);

        }

        while (!GALVO_DAC_Latched);

        if (appData.Galvo.X.processComplete && appData.Galvo.Y.processComplete) {

            DRV_TMR0_Stop();
            appData.Galvo.DAC_jobPending = 0;
        }
    }
}

void APP_GALVO_Launch_ADC_Process(void) {
    if (appData.Galvo.X.ADC_enabled) {
        DRV_SPI0_ClientConfigure(&(appData.drvSPI0.ADC_clientData));
        appData.Galvo.X.processComplete = 0;
    } else {
        appData.Galvo.X.processComplete = 1;
    }
    if (appData.Galvo.Y.ADC_enabled) {
        DRV_SPI1_ClientConfigure(&(appData.drvSPI1.ADC_clientData));
        appData.Galvo.Y.processComplete = 0;
    } else {

        appData.Galvo.Y.processComplete = 1;
    }
    appData.state = APP_READ_FROM_GALVO;
}

void APP_GALVO_Run_ADC_Process(void) {
    static uint8_t SPI0_RX_Buffer[SPI_TX_BUFF_SIZE];
    static uint8_t SPI1_RX_Buffer[SPI_TX_BUFF_SIZE];
    while (appData.Galvo.ADC_jobPending) {
        if (appData.Galvo.X.ADC_enabled) {
            uint32_t tempValx;
            DRV_TMR1_CounterValueSet(0xFFFF - ADC_HOLDOFF_COUNTS);
            GALVO_ADC_Flag = 0;
            DRV_TMR1_Start();
            while (GALVO_ADC_Flag != 1);

            DRV_TMR1_CounterValueSet(0xFFFF - ADC_CNV_TRIG_COUNTS);
            GALVO_ADC_Flag = 0;
            ADC0_CS_PINOff();
            DRV_TMR1_Start();
            while (GALVO_ADC_Flag != 1);
            ADC0_CS_PINOn();

            DRV_SPI0_BufferAddRead(SPI0_RX_Buffer, 3, 0, 0);
            while (APP_SPI0_RX_Status() != DRV_SPI_BUFFER_EVENT_COMPLETE);

            tempValx = (0x3FC00 & (SPI0_RX_Buffer[0] << 10));
            tempValx |= (0x3FC & (SPI0_RX_Buffer[1] << 2));
            tempValx |= (0x3 & (SPI0_RX_Buffer[2] >> 6));
            tempValx &= 0x3FFFF;

            appData.Galvo.X.reading = tempValx;
            appData.Galvo.X.processComplete = 1;
        }
        if (appData.Galvo.Y.ADC_enabled) {
            uint32_t tempValy;
            DRV_TMR1_CounterValueSet(0xFFFF - ADC_HOLDOFF_COUNTS);
            GALVO_ADC_Flag = 0;
            DRV_TMR1_Start();
            while (GALVO_ADC_Flag != 1);

            DRV_TMR1_CounterValueSet(0xFFFF - ADC_CNV_TRIG_COUNTS);
            GALVO_ADC_Flag = 0;
            ADC1_CS_PINOff();
            DRV_TMR1_Start();
            while (GALVO_ADC_Flag != 1);
            ADC1_CS_PINOn();

            DRV_SPI1_BufferAddRead(SPI1_RX_Buffer, 3, 0, 0);
            while (APP_SPI1_RX_Status() != DRV_SPI_BUFFER_EVENT_COMPLETE);

            tempValy = (0x3FC00 & (SPI1_RX_Buffer[0] << 10));
            tempValy |= (0x3FC & (SPI1_RX_Buffer[1] << 2));
            tempValy |= (0x3 & (SPI1_RX_Buffer[2] >> 6));
            tempValy &= 0x3FFFF;

            appData.Galvo.Y.reading = tempValy;
            appData.Galvo.Y.processComplete = 1;
        }

        if (appData.Galvo.X.processComplete && appData.Galvo.Y.processComplete) {

            appData.Galvo.ADC_jobPending = 0;

        }
    }
}

// Application State Machine Implementation
// *****************************************************************************

void APP_Next_Task(void) {
    switch (appData.state) {
        case APP_STATE_INIT:
        {
            appData.Galvo.X.DAC_enabled = 1;
            appData.Galvo.X.ADC_enabled = 1;

            appData.Galvo.Y.DAC_enabled = 1;
            appData.Galvo.Y.ADC_enabled = 1;

            appData.Galvo.DAC_jobPending = 1;
            appData.Galvo.ADC_jobPending = 1;
            APP_GALVO_Launch_DAC_Process();
            break;
        }
        case APP_READ_FROM_HOST:
        {
            if (appData.Galvo.DAC_jobPending) {
                APP_GALVO_Launch_DAC_Process();
            } else if (appData.Galvo.ADC_jobPending)
                APP_GALVO_Launch_ADC_Process();
            else {
                appData.HCI_WritePending = 1;
                appData.state = APP_WRITE_TO_HOST;
            }
            break;
        }
        case APP_WRITE_TO_HOST:
        {
            HCI_Set_RX_Status(HCI_RX_WAIT_FOR_PACKET);
            appData.state = APP_READ_FROM_HOST;
            break;
        }
        case APP_WRITE_TO_GALVO:
        {
            if (appData.Galvo.ADC_jobPending) {
                APP_GALVO_Launch_ADC_Process();
            } else {
                appData.HCI_WritePending = 1;
                appData.state = APP_WRITE_TO_HOST;
            }
            break;
        }
        case APP_READ_FROM_GALVO:
        {
            if (appData.Galvo.DAC_jobPending) {
                APP_GALVO_Launch_DAC_Process();
            } else {

                appData.HCI_WritePending = 1;
                appData.state = APP_WRITE_TO_HOST;
            }
            break;
        }
        default:
            break;
    }
}

void APP_Tasks(void) {
    switch (appData.state) {
        case APP_STATE_INIT:
        {
            bool appInitialized = true;

            if (appData.usart0_Handle == DRV_HANDLE_INVALID) {
                appData.usart0_Handle =
                        DRV_USART0_Open(DRV_USART_INDEX_0,
                        DRV_IO_INTENT_READWRITE | DRV_IO_INTENT_NONBLOCKING);
                appInitialized &= (DRV_HANDLE_INVALID != appData.usart0_Handle);
            }
            if (appData.drvSPI0.drvHandle == DRV_HANDLE_INVALID) {
                appData.drvSPI0.drvHandle =
                        DRV_SPI0_Open(DRV_USART_INDEX_0,
                        DRV_IO_INTENT_READWRITE | DRV_IO_INTENT_NONBLOCKING);
                appInitialized &= (DRV_HANDLE_INVALID != appData.drvSPI0.drvHandle);
            }
            if (appData.drvSPI1.drvHandle == DRV_HANDLE_INVALID) {
                appData.drvSPI1.drvHandle =
                        DRV_SPI1_Open(DRV_USART_INDEX_1,
                        DRV_IO_INTENT_READWRITE | DRV_IO_INTENT_NONBLOCKING);
                appInitialized &= (DRV_HANDLE_INVALID != appData.drvSPI1.drvHandle);
            }
            if (appInitialized) {
                APP_Next_Task();
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
                    APP_Open_HCI_Packet();
                    APP_Next_Task();
                    break;
                }
                default:
                    break;
            }
            break;
        }

        case APP_WRITE_TO_HOST:
        {
            if (appData.HCI_WritePending)
                APP_Write_HCI_Packet();
            else
                APP_Next_Task();
            break;
        }

        case APP_WRITE_TO_GALVO:
        {
            APP_GALVO_Run_DAC_Process();

            APP_Next_Task();
            break;
        }

        case APP_READ_FROM_GALVO:
        {
            APP_GALVO_Run_ADC_Process();

            APP_Next_Task();
            break;
        }

        default:
        {
            break;
        }
    }
}

/*******************************************************************************
 End of File
 */