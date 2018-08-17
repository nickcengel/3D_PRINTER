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





// ****************************************************************************
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

static APP_DATA ClientApp;
static SYSTEM_APP_DATA volatile SystemLayer;
static HOST_MESSAGE_DATA volatile HostMessage;

// *****************************************************************************
// *****************************************************************************
// Section: Data Pointers
// *****************************************************************************
// *****************************************************************************

static APP_DATA * const client_data_ptr(void) {
    return &ClientApp;
}

static APP_GALVO_DATA * const galvo_ptr(void) {
    return &(ClientApp.GalvoController);
}

static APP_STATES * const client_state_ptr(void) {
    return &(ClientApp.state);
}

static DRV_SPI_CLIENT_DATA * const adc0_config_ptr(void) {
    return &(ClientApp.Device.SPI0.ADC0_clientData);
}

static DRV_SPI_CLIENT_DATA * const dac0_config_ptr(void) {
    return &(ClientApp.Device.SPI0.DAC0_clientData);
}

static HOST_MESSAGE_DATA volatile * const message_ptr(void) {
    return &HostMessage;
}

static SYSTEM_DEVICE_DATA volatile * const sys_dev_data_ptr(void) {
    return (&(SystemLayer.Device));
}

static SYSTEM_DEVICE_DATA_SPI volatile * const spi0_ptr(void) {
    return (&(SystemLayer.Device.SPI0));
}

static PACKET_STATES volatile * const packet_state_ptr(void) {
    return (&(SystemLayer.Device.USART0.packetState));
}


// *****************************************************************************
// *****************************************************************************
// Section: Local Calculator Functions
// *****************************************************************************
// *****************************************************************************

static uint32_t ComputeStepSize(uint32_t currentA, uint32_t finalA,
        uint32_t currentB, uint32_t finalB, float speed) {
    uint32_t deltaA = 0;
    uint32_t deltaB = 0;

    if (finalA > currentA)
        deltaA = finalA - currentA;
    else
        deltaA = currentA - finalA;

    if (finalB > currentB)
        deltaB = finalB - currentB;
    else
        deltaB = currentB - finalB;

    if ((deltaA > 0) && (speed > 0)) {
        uint32_t distance = ((uint32_t) sqrt((float) deltaA * (float) deltaA + (float) deltaB * (float) deltaB)) << 10;
        uint32_t duration = distance / speed;
        uint32_t numIncrements = (uint32_t) (((float) duration) / DAC_UPDATE_PERIOD_uS);

        if (numIncrements < 1)
            numIncrements = 1;

        return ((deltaA << 10) / numIncrements);

    } else
        return 0;
}


// *****************************************************************************
// *****************************************************************************
// Section: Local Application Processes
// *****************************************************************************
// *****************************************************************************

static void InitalizeDevices(void) {
    APP_DATA * const clientDataPtr = client_data_ptr();
    HOST_MESSAGE_DATA volatile * const messPtr = message_ptr();
    bool appInitialized = true;

    if (clientDataPtr->Device.USART0.driverHandle == DRV_HANDLE_INVALID) {
        clientDataPtr->Device.USART0.driverHandle =
                DRV_USART0_Open(DRV_USART_INDEX_0,
                DRV_IO_INTENT_READWRITE | DRV_IO_INTENT_NONBLOCKING);
        appInitialized &= (DRV_HANDLE_INVALID != clientDataPtr->Device.USART0.driverHandle);
    }
    if (clientDataPtr->Device.SPI0.driverHandle == DRV_HANDLE_INVALID) {
        clientDataPtr->Device.SPI0.driverHandle =
                DRV_SPI0_Open(DRV_SPI_INDEX_0,
                DRV_IO_INTENT_READWRITE | DRV_IO_INTENT_NONBLOCKING);
        appInitialized &= (DRV_HANDLE_INVALID != clientDataPtr->Device.SPI0.driverHandle);
    }    if (clientDataPtr->Device.SPI1.driverHandle == DRV_HANDLE_INVALID) {
        clientDataPtr->Device.SPI1.driverHandle =
                DRV_SPI1_Open(DRV_SPI_INDEX_1,
                DRV_IO_INTENT_READWRITE | DRV_IO_INTENT_NONBLOCKING);
        appInitialized &= (DRV_HANDLE_INVALID != clientDataPtr->Device.SPI1.driverHandle);
    }
    if (appInitialized) {
        SYSTEM_DEVICE_DATA_SPI volatile * const spi0Ptr = spi0_ptr();
        if (spi0Ptr->DAC_state == DAC_STATE_READY) {
            clientDataPtr->GalvoController.X_Axis.current = 0;
            clientDataPtr->GalvoController.X_Axis.final = DAC0_OFFSET;
            clientDataPtr->GalvoController.X_Axis.stepSize = 0;
            clientDataPtr->GalvoController.X_Axis.direction = DAC_DIRECTION_JUMP_TO_VALUE;
            clientDataPtr->GalvoController.X_Axis.Measurement.start = 0;
            clientDataPtr->GalvoController.X_Axis.Measurement.end = 0;
            clientDataPtr->GalvoController.X_Axis.Measurement.type = ADC_MEASUREMENT_BEGINNING;
            clientDataPtr->state = APP_READ_FROM_ADC;
            DRV_SPI0_ClientConfigure(adc0_config_ptr());
            messPtr->mesageReplyType = MESSAGE_REPLY_ADC_ONLY;


        }
    }
}

static void processHostMessage(HOST_MESSAGE_DATA volatile * const messPtr,
        APP_DATA * const clientDataPtr,
        SYSTEM_DEVICE_DATA volatile * const sysDevPtr) {

    if (messPtr->mesageReplyType == MESSAGE_REPLY_ADC_ONLY) {
        sysDevPtr->SPI0.ADC_state = ADC_STATE_READY;
        clientDataPtr->state = APP_READ_FROM_ADC;
        clientDataPtr->GalvoController.X_Axis.Measurement.type = ADC_MEASUREMENT_ONLY;
    } else {
        bool messageContainsData = false;

        PARAMETER_LABELS parameterIndex;

        for (parameterIndex = L_STATE; parameterIndex < END_PARAMETERS; parameterIndex++) {


            const bool parameterStatus = parameterIsActive(messPtr, parameterIndex);
            messageContainsData |= parameterStatus;
            if (parameterStatus != 0) {
                switch (parameterIndex) {
                    case L_STATE:
                    {
                        break;
                    }
                    case L_POWER:
                    {
                        break;
                    }
                    case G_STATE:
                    {
                        break;
                    }
                    case G_SPEED:
                    {
                        const float gSpeed = getMessageData(messPtr, G_SPEED);
                        if (gSpeed > 0)
                            clientDataPtr->GalvoController.speed = gSpeed;
                        break;
                    }
                    case X_POS:
                    {
                        if (messPtr->galvoState == RELATIVE_MOVE)
                            clientDataPtr->GalvoController.X_Axis.final =
                                getMessageData(messPtr, X_POS) + clientDataPtr->GalvoController.X_Axis.current;
                        else if (messPtr->galvoState == ABSOLUTE_MOVE)
                            clientDataPtr->GalvoController.X_Axis.final = getMessageData(messPtr, X_POS) + DAC0_OFFSET;
                            // for debugging ! REMOVE !
                        else
                            clientDataPtr->GalvoController.X_Axis.final = getMessageData(messPtr, X_POS) + DAC0_OFFSET;

                        if (clientDataPtr->GalvoController.X_Axis.final > DAC_MAX_VALUE)
                            clientDataPtr->GalvoController.X_Axis.final = DAC_MAX_VALUE;
                        else if (clientDataPtr->GalvoController.X_Axis.final < DAC_MIN_VALUE)
                            clientDataPtr->GalvoController.X_Axis.final = DAC_MIN_VALUE;

                        if (clientDataPtr->GalvoController.X_Axis.current != clientDataPtr->GalvoController.X_Axis.final) {
                            if (clientDataPtr->GalvoController.X_Axis.current < clientDataPtr->GalvoController.X_Axis.final)
                                clientDataPtr->GalvoController.X_Axis.direction = DAC_DIRECTION_INCREASE;
                            else
                                clientDataPtr->GalvoController.X_Axis.direction = DAC_DIRECTION_DECREASE;
                            clientDataPtr->GalvoController.X_Axis.stepSize = ComputeStepSize(
                                    clientDataPtr->GalvoController.X_Axis.current,
                                    clientDataPtr->GalvoController.X_Axis.final,
                                    clientDataPtr->GalvoController.Y_Axis.current,
                                    clientDataPtr->GalvoController.Y_Axis.final,
                                    clientDataPtr->GalvoController.speed);

                            clientDataPtr->state = APP_READ_FROM_ADC;
                            clientDataPtr->GalvoController.X_Axis.Measurement.type = ADC_MEASUREMENT_BEGINNING;

                            sysDevPtr->SPI0.DAC_state = DAC_STATE_READY;

                        }
                        //else {
                        //                            clientDataPtr->GalvoController.X_Axis.stepSize = 0;
                        //                        }
                        break;
                    }

                    case Y_POS:
                    {
                        //                        if (messPtr->galvoState == ABSOLUTE_MOVE)
                        //                            clientDataPtr->GalvoController.Y_Axis.final = getMessageData(messPtr, Y_POS) + DAC1_OFFSET;
                        //                        else if (messPtr->galvoState == RELATIVE_MOVE)
                        //                            clientDataPtr->GalvoController.Y_Axis.final = getMessageData(messPtr, Y_POS) + clientDataPtr->GalvoController.Y_Axis.current;
                        //                        if (clientDataPtr->GalvoController.Y_Axis.final > DAC_MAX_VALUE)
                        //                            clientDataPtr->GalvoController.Y_Axis.final = DAC_MAX_VALUE;
                        //                        else if (clientDataPtr->GalvoController.Y_Axis.final < DAC_MIN_VALUE)
                        //                            clientDataPtr->GalvoController.Y_Axis.final = DAC_MIN_VALUE;
                        //
                        //                        if (clientDataPtr->GalvoController.Y_Axis.current != clientDataPtr->GalvoController.Y_Axis.final) {
                        //                            if (clientDataPtr->GalvoController.Y_Axis.current < clientDataPtr->GalvoController.Y_Axis.final)
                        //                                clientDataPtr->GalvoController.Y_Axis.direction = DAC_DIRECTION_INCREASE;
                        //                            else
                        //                                clientDataPtr->GalvoController.Y_Axis.direction = DAC_DIRECTION_DECREASE;
                        //
                        //                            clientDataPtr->GalvoController.Y_Axis.stepSize = ComputeStepSize(
                        //                                    clientDataPtr->GalvoController.Y_Axis.current,
                        //                                    clientDataPtr->GalvoController.Y_Axis.final,
                        //                                    clientDataPtr->GalvoController.X_Axis.current,
                        //                                    clientDataPtr->GalvoController.X_Axis.final,
                        //                                    clientDataPtr->GalvoController.speed);
                        //
                        //                            clientDataPtr->state = APP_READ_FROM_ADC;
                        //                            clientDataPtr->GalvoController.Y_Axis.Measurement.type = ADC_MEASUREMENT_BEGINNING;
                        //                            clientDataPtr->GalvoController.Y_Axis.Measurement.start = 0;
                        //                            clientDataPtr->GalvoController.Y_Axis.Measurement.end = 0;
                        //
                        //                            sysDevPtr->SPI1.ADC_state = ADC_STATE_READY;
                        //                            sysDevPtr->SPI1.DAC_state = DAC_STATE_READY;
                        //                        } else {
                        //                            clientDataPtr->GalvoController.Y_Axis.stepSize = 0;
                        //                        }
                        //                        break;
                    }
                    default:
                        break;
                }
            }
        }

        if (!messageContainsData
                || ((clientDataPtr->GalvoController.X_Axis.current == clientDataPtr->GalvoController.X_Axis.final)
                && (clientDataPtr->GalvoController.Y_Axis.current == clientDataPtr->GalvoController.Y_Axis.final))) {
            clientDataPtr->state = APP_SEND_REPLY_TO_HOST;
            sysDevPtr->USART0.packetState = PACKET_SEND_START;
        }
    }
    DRV_SPI0_ClientConfigure(adc0_config_ptr());
}

static void GetMessageFromHost(void) {

    PACKET_STATES volatile * const pcktPtr = packet_state_ptr();
    HOST_MESSAGE_DATA volatile * const mssgPtr = message_ptr();

    switch (*pcktPtr) {
        case PACKET_EMPTY:
        {
            clearMessage(mssgPtr);
            *pcktPtr = PACKET_LOOK_FOR_START;
            break;
        }
        case PACKET_RECEIVE_COMPLETE:
        {
            APP_DATA * const clientDataPtr = client_data_ptr();
            SYSTEM_DEVICE_DATA volatile * const sysDevPtr = sys_dev_data_ptr();
            processHostMessage(mssgPtr, clientDataPtr, sysDevPtr);
            break;
        }
        default:
            break;
    }
}

static void generateClientReply(uint8_t *usartTXbuf, uint8_t *usartTXcount, uint8_t *tx_length) {
    HOST_MESSAGE_DATA volatile * const messPtr = message_ptr();
    APP_GALVO_DATA * const galvoPtr = galvo_ptr();

    memset(usartTXbuf, 0, USART0_TX_BUFF_SIZE);
    *tx_length = 0;
    *usartTXcount = 0;
    strcpy(usartTXbuf, "\r\n@ok:\r\n");
    PARAMETER_LABELS parameterIndex = 0;

    if (messPtr->mesageReplyType == MESSAGE_REPLY_VERBOSE) {
        for (parameterIndex = L_STATE; parameterIndex < END_PARAMETERS; parameterIndex++) {
            if (messPtr->activeParameter[parameterIndex]) {
                uint8_t messageValBuf[10];
                const int val = getMessageData(messPtr, parameterIndex);
                itoa(messageValBuf, val, 10);
                strcat(messageValBuf, "\r\n");
                if ((strlen(usartTXbuf) + strlen(messageValBuf)) < USART0_TX_BUFF_SIZE)
                    strcat(usartTXbuf, messageValBuf);

            } else if ((strlen(usartTXbuf) + strlen("~\r\n")) < USART0_TX_BUFF_SIZE) {

                strcat(usartTXbuf, "~\r\n");
            }
        }
    }
    if ((messPtr->mesageReplyType == MESSAGE_REPLY_VERBOSE)
            || (messPtr->mesageReplyType == MESSAGE_REPLY_ADC_ONLY)) {

        uint8_t sendADC0_buffer[10];

        if ((strlen(usartTXbuf) + strlen("ADC0 Start: ")) < USART0_TX_BUFF_SIZE)
            strcat(usartTXbuf, "ADC0 Start: ");

        itoa(sendADC0_buffer, (galvoPtr->X_Axis.Measurement.start - ADC0_OFFSET), 10);
        strcat(sendADC0_buffer, "\r\n");

        if ((strlen(usartTXbuf) + strlen(sendADC0_buffer) < USART0_TX_BUFF_SIZE))
            strcat(usartTXbuf, sendADC0_buffer);

        memset(sendADC0_buffer, 0, 10);

        if ((strlen(usartTXbuf) + strlen("ADC0 END: ")) < USART0_TX_BUFF_SIZE)
            strcat(usartTXbuf, "ADC0 END: ");

        itoa(sendADC0_buffer, (galvoPtr->X_Axis.Measurement.end - ADC0_OFFSET), 10);
        strcat(sendADC0_buffer, "\r\n \r\n \r\n");

        if ((strlen(usartTXbuf) + strlen(sendADC0_buffer)) < USART0_TX_BUFF_SIZE)
            strcat(usartTXbuf, sendADC0_buffer);
    }
    *tx_length = strlen(usartTXbuf);
    if (*tx_length > USART0_TX_BUFF_SIZE)
        *tx_length = USART0_TX_BUFF_SIZE;



    *packet_state_ptr() = PACKET_SEND_PENDING;
}

static void sendClientReply(uint8_t *usartTXbuf, uint8_t *usartTXcount, uint8_t *tx_length, PACKET_STATES volatile * const pcktPtr) {
    DRV_USART0_WriteByte(usartTXbuf[*usartTXcount]);
    (*usartTXcount)++;
    if (*usartTXcount >= (*tx_length - 1)) {
        *pcktPtr = PACKET_EMPTY;
        *client_state_ptr() = APP_GET_MESSAGE_FROM_HOST;
    }
}

static void SendReplyToHost(void) {
    static uint8_t USART0_TX_Buffer[USART0_TX_BUFF_SIZE];
    static uint8_t client_replyLength = 0;
    static uint8_t USART0_TX_Count = 0;

    PACKET_STATES volatile * const pcktPtr = packet_state_ptr();
    switch (*pcktPtr) {
        case PACKET_SEND_START:
        {
            generateClientReply(USART0_TX_Buffer, &USART0_TX_Count, &client_replyLength);
            if (client_replyLength < 1)

                break;
        }
        case PACKET_SEND_PENDING:
        {
            if (!DRV_USART0_TransmitBufferIsFull()) {
                sendClientReply(USART0_TX_Buffer, &USART0_TX_Count, &client_replyLength, pcktPtr);
            }
            break;
        }
        default:
            break;
    }
}

static void DAC0_Tasks(APP_GALVO_DATA_AXIS * const a_axis) {
    switch (a_axis->direction) {
        case DAC_DIRECTION_DECREASE:
        {
            a_axis->current -= a_axis->stepSize;
            if (a_axis->current < a_axis->final) {
                a_axis->current = a_axis->final;
            }
            break;
        }
        case DAC_DIRECTION_INCREASE:
        {
            a_axis->current += a_axis->stepSize;
            if (a_axis->current > a_axis->final) {
                a_axis->current = a_axis->final;
            }
            break;
        }
        case DAC_DIRECTION_JUMP_TO_VALUE:
        {
            a_axis->current = a_axis->final;
            break;
        }
        default:
            break;
    }
}

static void WriteToDAC(void) {
    static uint8_t SPI0_TX_Buffer[SPI0_TX_BUFF_SIZE];

    SYSTEM_DEVICE_DATA_SPI volatile * const spi0Ptr = spi0_ptr();
    APP_GALVO_DATA * const galvoPtr = galvo_ptr();
    APP_STATES * const client_statePtr = client_state_ptr();
    bool block_is_finished = 1;

    switch (spi0Ptr->DAC_state) {
        case DAC_STATE_READY:
        {
            DAC0_Tasks(&(galvoPtr->X_Axis));
            const uint32_t DAC0_DATA = galvoPtr->X_Axis.current;
            memset(SPI0_TX_Buffer, 0, SPI0_TX_BUFF_SIZE);
            SPI0_TX_Buffer[0] = DAC_DIN_REG_WRITE << 4;
            SPI0_TX_Buffer[0] |= (0xFF & (DAC0_DATA >> 14));
            SPI0_TX_Buffer[1] = (0xFF & (DAC0_DATA >> 6));
            SPI0_TX_Buffer[2] = (0xFF & (DAC0_DATA << 2));

            spi0Ptr->DAC_state = DAC_STATE_WRITE_PENDING;
            spi0Ptr->TX_handle = DRV_SPI0_BufferAddWrite(SPI0_TX_Buffer, 3, 0, 0);

            break;
        }

        case DAC_STATE_LATCHED:
        {
            if (spi0Ptr->TX_status == DRV_SPI_BUFFER_EVENT_COMPLETE) {
                APP_DAC0_UNLATCH();
                spi0Ptr->DAC_state = DAC_STATE_VALID;
                if (galvoPtr->X_Axis.current != galvoPtr->X_Axis.final)
                    block_is_finished = 0;
                else
                    block_is_finished &= 1;
            }
            break;
        }
        default:
            break;
    }
    if (spi0Ptr->DAC_state == DAC_STATE_VALID) {
        if (block_is_finished) {
            DRV_SPI0_ClientConfigure(adc0_config_ptr());
            spi0Ptr->ADC_state = ADC_STATE_READY;
            galvoPtr->X_Axis.Measurement.type = ADC_MEASUREMENT_ENDING;
            *client_statePtr = APP_READ_FROM_ADC;

        }
        spi0Ptr->DAC_state = DAC_STATE_READY;
    }
}

static uint32_t sampleAccumulator(uint32_t tempVal, bool *finishFlag) {
    static sampleIterator = 0;
    static runningVal = 0;

    sampleIterator += 1;
    runningVal += tempVal;

    uint32_t finalValue;
    if (sampleIterator < ADC_NUMBER_OF_SAMPLES) {
        *finishFlag = false;
        finalValue = 0;
    } else {
        *finishFlag = true;
        sampleIterator = 0;
        finalValue = (runningVal >> 3);
        runningVal = 0;

    }
    return finalValue;
}

static void ReadFromADC(void) {
    static APP_STATES adc0_next_app_state;
    static APP_STATES adc1_next_app_state = APP_READ_FROM_ADC;

    static uint8_t SPI0_RX_Buffer[SPI0_RX_BUFF_SIZE];
    SYSTEM_DEVICE_DATA_SPI volatile * const spi0Ptr = spi0_ptr();
    switch (spi0Ptr->ADC_state) {
        case ADC_STATE_READY:
        {   
            DRV_TMR0_Stop();
            adc0_next_app_state = APP_READ_FROM_ADC;
            spi0Ptr->ADC_state = ADC_STATE_WAIT;
            DRV_TMR1_CounterValueSet(0xFFFF - ADC_HOLDOFF_PERIOD_COUNTS);
            DRV_TMR1_Start();
            while (1) {
                if (spi0Ptr->ADC_state == ADC_STATE_CONTINUE) {
                    break;
                }
            }
            break;
        }
        case ADC_STATE_CONTINUE:
        {
            spi0Ptr->ADC_state = ADC_STATE_CONVERSION_START;
            memset(SPI0_RX_Buffer, 0, SPI0_RX_BUFF_SIZE);
            ADC0_START_PINOff();
            DRV_TMR1_CounterValueSet(0xFFFF - ADC_CONVERSION_PERIOD_COUNTS);
            DRV_TMR1_Start();
            while (1) {
                if (spi0Ptr->ADC_state == ADC_STATE_CONVERSION_COMPLETE) {
                    spi0Ptr->ADC_state = ADC_STATE_READ_VALUE;
                    break;
                }
            }
            spi0Ptr->RX_handle = DRV_SPI0_BufferAddRead(SPI0_RX_Buffer, 3, 0, 0);
            break;
        }
        case ADC_STATE_READ_VALUE:
        {
            if (spi0Ptr->RX_status == DRV_SPI_BUFFER_EVENT_COMPLETE) {

                uint32_t tempVal;
                tempVal = (0x3FC00 & (SPI0_RX_Buffer[0] << 10));
                tempVal |= (0x3FC & (SPI0_RX_Buffer[1] << 2));
                tempVal |= (0x3 & (SPI0_RX_Buffer[2] >> 6));
                tempVal &= 0x3FFFF;
                
                bool finishedReadingSamples = false;
                uint32_t avgVal = sampleAccumulator(tempVal, &finishedReadingSamples);

                if (finishedReadingSamples) {
                    APP_GALVO_DATA_AXIS * const x_axisPtr = &(galvo_ptr()->X_Axis);
                    switch (x_axisPtr->Measurement.type) {
                        case ADC_MEASUREMENT_BEGINNING:
                        {
                            DRV_SPI_CLIENT_DATA * const dac0ptr = dac0_config_ptr();
                            DRV_SPI0_ClientConfigure(dac0_config_ptr());
                            x_axisPtr->Measurement.start = avgVal;
                            spi0Ptr->DAC_state = DAC_STATE_READY;

                            adc0_next_app_state = APP_WRITE_TO_DAC;
                            DRV_TMR0_CounterValueSet(0xFFFF - DAC_UPDATE_PERIOD_COUNTS);
                            DRV_TMR0_Start();
                            break;
                        }
                        case ADC_MEASUREMENT_ENDING:
                        {
                            PACKET_STATES volatile * const pcktStatePtr = packet_state_ptr();
                            *pcktStatePtr = PACKET_SEND_START;
                            x_axisPtr->Measurement.end = avgVal;
                            adc0_next_app_state = APP_SEND_REPLY_TO_HOST;
                            break;
                        }
                        case ADC_MEASUREMENT_ONLY:
                        {
                            PACKET_STATES volatile * const pcktStatePtr = packet_state_ptr();
                            *pcktStatePtr = PACKET_SEND_START;
                            x_axisPtr->Measurement.start = x_axisPtr->Measurement.end;
                            x_axisPtr->Measurement.end = avgVal;
                            adc0_next_app_state = APP_SEND_REPLY_TO_HOST;
                            break;
                        }
                        default:
                        {
                            break;
                        }
                    }
                    spi0Ptr->ADC_state = ADC_STATE_READY;
                } else {
                    spi0Ptr->ADC_state = ADC_STATE_CONTINUE;
                }
            }
            break;
        }
        default:
            break;
    }

    adc1_next_app_state = adc0_next_app_state; // debug only!!!!
    if ((adc0_next_app_state != APP_READ_FROM_ADC) && (adc1_next_app_state != APP_READ_FROM_ADC))
        *client_state_ptr() = adc0_next_app_state;
}


// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

void APP_Initialize(void) {
    /* Place the App state machine in its initial state. */
    ClientApp.Device.SPI0.DAC0_clientData.baudRate = 50000000; // use default
    ClientApp.Device.SPI0.DAC0_clientData.operationStarting = SPI0_DAC0_CallBack_Start;
    ClientApp.Device.SPI0.DAC0_clientData.operationEnded = SPI0_DAC0_CallBack_End;

    ClientApp.Device.SPI0.ADC0_clientData.baudRate = 12500000; // use default
    ClientApp.Device.SPI0.ADC0_clientData.operationStarting = SPI0_ADC0_CallBack_Start;
    ClientApp.Device.SPI0.ADC0_clientData.operationEnded = SPI0_ADC0_CallBack_End;

    ClientApp.Device.SPI0.driverHandle = DRV_HANDLE_INVALID;

    ClientApp.Device.USART0.driverHandle = DRV_HANDLE_INVALID;

    ClientApp.state = APP_STATE_INIT;
    ClientApp.GalvoController.speed = DEFAULT_GALVO_SPEED;

    ClientApp.GalvoController.X_Axis.Measurement.type = ADC_MEASUREMENT_IDLE;

    clearMessage(&HostMessage);


    DRV_USART_ByteReceiveCallbackSet(DRV_USART_INDEX_0, APP_USARTReceiveEventHandler);

    DRV_TMR0_CounterValueSet(0xFFFF - DAC_UPDATE_PERIOD_COUNTS);
    DRV_TMR0_Start();

    DRV_TMR1_CounterValueSet(0xFFFF - ADC_CONVERSION_PERIOD_COUNTS);

    ADC0_START_PINOn();
    SystemLayer.Device.SPI0.DAC_state = DAC_STATE_READY;
    SystemLayer.Device.SPI0.ADC_state = ADC_STATE_READY;
}

void APP_Tasks(void) {
    /* Check the application's current state. */
    switch (*client_state_ptr()) {
            /* Application's initial state. */
        case APP_STATE_INIT:
        {

            InitalizeDevices();
            break;
        }

        case APP_GET_MESSAGE_FROM_HOST:
        {
            GetMessageFromHost();
            break;
        }

        case APP_SEND_REPLY_TO_HOST:
        {
            SendReplyToHost();
            break;
        }

        case APP_WRITE_TO_DAC:
        {

            WriteToDAC();
            break;
        }

        case APP_READ_FROM_ADC:
        {
            ReadFromADC();
            break;
        }
            /* The default state should never be executed. */
        default:
        {
            break;
        }
    }
}


// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

void APP_USARTReceiveEventHandler(const SYS_MODULE_INDEX index) {
    // Byte has been Received. Handle the event.
    // Read byte using DRV_USART_ReadByte.
    static uint8_t USART0_RX_Buffer[USART0_RX_BUFF_SIZE];
    static uint8_t USART0_RX_Count = 0;

    static PARAMETER_LABELS parameterIndex = 0;

    HOST_MESSAGE_DATA volatile * const mssgPtr = message_ptr();
    PACKET_STATES volatile * const pcktPtr = packet_state_ptr();

    const uint8_t currentByte = DRV_USART0_ReadByte();

    DRV_USART0_WriteByte(currentByte);

    if ((USART0_RX_Count < USART0_RX_BUFF_SIZE - 2)
            && (parameterIndex < END_PARAMETERS)) {

        switch (*pcktPtr) {
            case PACKET_LOOK_FOR_START:
            {
                if (currentByte == '/') {
                    *pcktPtr = PACKET_LOOK_FOR_DATA;
                    mssgPtr->mesageReplyType = MESSAGE_REPLY_VERBOSE;
                    parameterIndex = L_STATE;
                } else if (currentByte == '#') {
                    *pcktPtr = PACKET_RECEIVE_COMPLETE;
                    mssgPtr->mesageReplyType = MESSAGE_REPLY_ADC_ONLY;
                }
                break;
            } // END PACKET_LOOK_FOR_START
            case PACKET_LOOK_FOR_DATA:
            {
                if (((currentByte >= '0') && (currentByte <= '9'))
                        || ((currentByte == '-') && (USART0_RX_Count == 0))) {
                    USART0_RX_Buffer[USART0_RX_Count] = currentByte;
                    USART0_RX_Count++;
                } else if (currentByte == '~') {
                    parameterIndex++;
                    USART0_RX_Count = 0;
                } else if ((currentByte == ' ') && (USART0_RX_Count > 0)) {

                    int currentVal = stringToInt(USART0_RX_Buffer);
                    addActiveParameter(mssgPtr, parameterIndex, currentVal);
                    parameterIndex++;
                    memset(USART0_RX_Buffer, 0, USART0_RX_Count);
                    USART0_RX_Count = 0;
                    if (parameterIndex >= END_PARAMETERS) {
                        *pcktPtr = PACKET_RECEIVE_COMPLETE;
                        memset(USART0_RX_Buffer, 0, USART0_RX_Count);
                        USART0_RX_Count = 0;
                        parameterIndex = 0;

                    }
                } else if (currentByte == ';') {
                    if (USART0_RX_Count > 0) {
                        const int currentParameter = stringToInt(USART0_RX_Buffer);
                        addActiveParameter(mssgPtr, parameterIndex, currentParameter);
                    }
                    *pcktPtr = PACKET_RECEIVE_COMPLETE;
                    memset(USART0_RX_Buffer, 0, USART0_RX_Count);
                    USART0_RX_Count = 0;
                    parameterIndex = 0;
                }
                break;
            } // END PACKET_LOOK_FOR_DATA //

            default:
                break;
        }
    } else if ((USART0_RX_Count >= USART0_RX_BUFF_SIZE - 2)) {
        if (parameterIndex < END_PARAMETERS) {
            const int currentParameter = stringToInt(USART0_RX_Buffer);
            addActiveParameter(mssgPtr, parameterIndex, currentParameter);
            memset(USART0_RX_Buffer, 0, USART0_RX_Count);
            USART0_RX_Count = 0;
        } else {
            *pcktPtr = PACKET_RECEIVE_COMPLETE;
            memset(USART0_RX_Buffer, 0, sizeof (USART0_RX_Buffer));
            USART0_RX_Count = 0;
            parameterIndex = 0;
        }
        /* We received all the data we expected to get */
    } else if (parameterIndex >= END_PARAMETERS) {
        *pcktPtr = PACKET_RECEIVE_COMPLETE;
        memset(USART0_RX_Buffer, 0, sizeof (USART0_RX_Buffer));
        USART0_RX_Count = 0;
        parameterIndex = 0;
    }
}

void SPI0_DAC0_CallBack_Start(DRV_SPI_BUFFER_EVENT eEvent, DRV_SPI_BUFFER_HANDLE bufferHandle, void *context) {
    SYSTEM_DEVICE_DATA_SPI volatile * const spiPtr = spi0_ptr();
    spiPtr->TX_status = eEvent;
    APP_DAC0_SELECT();
}

void SPI0_DAC0_CallBack_End(DRV_SPI_BUFFER_EVENT eEvent, DRV_SPI_BUFFER_HANDLE bufferHandle, void *context) {
    SYSTEM_DEVICE_DATA_SPI volatile * const spiPtr = spi0_ptr();
    spiPtr->TX_status = eEvent;
    spiPtr->DAC_state = DAC_STATE_WRITE_COMPLETE;
    APP_DAC0_DESELECT();
}

void SPI0_ADC0_CallBack_Start(DRV_SPI_BUFFER_EVENT eEvent, DRV_SPI_BUFFER_HANDLE bufferHandle, void *context) {
    SYSTEM_DEVICE_DATA_SPI volatile * const spiPtr = spi0_ptr();
    spiPtr->RX_status = eEvent;
}

void SPI0_ADC0_CallBack_End(DRV_SPI_BUFFER_EVENT eEvent, DRV_SPI_BUFFER_HANDLE bufferHandle, void *context) {
    SYSTEM_DEVICE_DATA_SPI volatile * const spiPtr = spi0_ptr();
    spiPtr->RX_status = eEvent;
}

// *****************************************************************************
// *****************************************************************************
// Section: Timer Interrupt Vector Functions
// *****************************************************************************
// *****************************************************************************

void __ISR(_TIMER_1_VECTOR, ipl6AUTO) IntHandlerDrvTmrInstance0(void) {
    DRV_TMR0_CounterClear();
    SYSTEM_DEVICE_DATA_SPI volatile * const spiPtr = spi0_ptr();
    if (spiPtr->DAC_state == DAC_STATE_WRITE_COMPLETE) {
        spiPtr->DAC_state = DAC_STATE_LATCHED;
        APP_DAC0_LATCH();
    }
    DRV_TMR0_CounterValueSet(0xFFFF - DAC_UPDATE_PERIOD_COUNTS + DRV_TMR0_CounterValueGet());
    PLIB_INT_SourceFlagClear(INT_ID_0, INT_SOURCE_TIMER_1);
}

void __ISR(_TIMER_2_VECTOR, ipl3AUTO) IntHandlerDrvTmrInstance1(void) {
    DRV_TMR1_Stop();
    SYSTEM_DEVICE_DATA_SPI volatile * const spiPtr = spi0_ptr();
    if (spiPtr->ADC_state == ADC_STATE_CONVERSION_START) {
        ADC0_START_PINOn();
        spiPtr->ADC_state = ADC_STATE_CONVERSION_COMPLETE;
    } else if (spiPtr->ADC_state == ADC_STATE_WAIT) {
        spiPtr->ADC_state = ADC_STATE_CONTINUE;
    }
    PLIB_INT_SourceFlagClear(INT_ID_0, INT_SOURCE_TIMER_2);
}


/*******************************************************************************
 End of File */