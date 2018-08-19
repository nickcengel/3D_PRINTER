/*******************************************************************************
  MPLAB Harmony Application Header File

  Company:
    Microchip Technology Inc.

  File Name:
    app.h

  Summary:
    This header file provides prototypes and definitions for the application.

  Description:
    This header file provides function prototypes and data type definitions for
    the application.  Some of these are required by the system (such as the
    "APP_Initialize" and "APP_Tasks" prototypes) and some of them are only used
    internally by the application (such as the "APP_STATES" definition).  Both
    are defined here for convenience.
 *******************************************************************************/

//DOM-IGNORE-BEGIN
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
//DOM-IGNORE-END

#ifndef _APP_H
#define _APP_H

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <math.h>

#include "system_config.h"
#include "system_definitions.h"
#include "message_components.h"


// *****************************************************************************
// *****************************************************************************
// Section: Global Definitions
// *****************************************************************************
// *****************************************************************************

#define USART0_RX_BUFF_SIZE 16
#define USART0_TX_BUFF_SIZE 128

#define SPI0_RX_BUFF_SIZE 3
#define SPI0_TX_BUFF_SIZE 3

// 64 samples , so shift by 6
#define ADC_NUMBER_OF_SAMPLES 8

#define ADC_CONVERSION_PERIOD_COUNTS 8
#define ADC_HOLDOFF_PERIOD_COUNTS 2048
#define ADC0_OFFSET 0x1FFF7

#define DAC_DIN_REG_WRITE 0x1
#define DAC_OFFSET_REG_WRITE 0x2    
#define DAC_GAIN_REG_WRITE 0x3
#define DAC_CONFIG_REG_WRITE 0x4    
#define DAC_DIN_REG_READ 0x9
#define DAC_OFFSET_REG_READ 0xA    
#define DAC_GAIN_REG_READ 0xB
#define DAC_CONFIG_REG_READ 0xC

#define DAC_UPDATE_PERIOD_uS 10.0
#define DAC_UPDATE_PERIOD_COUNTS 117

#define DAC0_OFFSET  0x201EA // added to incoming signed number
#define DAC1_OFFSET  0x201EA // added to incoming signed number
#define DAC_MAX_VALUE 0x3FFFF
#define DAC_MIN_VALUE 0x0

#define DEFAULT_GALVO_SPEED  13.5

#define APP_DAC0_DESELECT() SYS_PORTS_PinSet(PORTS_ID_0, PORT_CHANNEL_B, PORTS_BIT_POS_2)
#define APP_DAC0_SELECT() SYS_PORTS_PinClear(PORTS_ID_0, PORT_CHANNEL_B, PORTS_BIT_POS_2)

#define APP_DAC0_LATCH() SYS_PORTS_PinClear(PORTS_ID_0, PORT_CHANNEL_K, PORTS_BIT_POS_2)
#define APP_DAC0_UNLATCH() SYS_PORTS_PinSet(PORTS_ID_0, PORT_CHANNEL_K, PORTS_BIT_POS_2)

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

extern "C" {

#endif
    // DOM-IGNORE-END 

    // *****************************************************************************
    // *****************************************************************************
    // Section: Type Definitions
    // *****************************************************************************
    // *****************************************************************************

    typedef enum {
        /* Application's state machine's initial state. */
        APP_STATE_INIT = 0,
        APP_GET_MESSAGE_FROM_HOST = 1,
        APP_SEND_REPLY_TO_HOST = 2,
        APP_WRITE_TO_DAC = 3,
        APP_READ_FROM_ADC = 4,
    } APP_STATES;

    typedef enum {
            DAC_STATE_READY = 0,
        DAC_STATE_WRITE_PENDING = 1,
        DAC_STATE_WRITE_COMPLETE = 2,
        DAC_STATE_LATCHED = 3,
        DAC_STATE_VALID = 4
    } DAC_STATES;

    typedef enum {
        DAC_DIRECTION_DECREASE = 0,
        DAC_DIRECTION_INCREASE = 1,
        DAC_DIRECTION_JUMP_TO_VALUE = 2
    } DAC_DIRECTIONS;

    typedef enum {
        ADC_STATE_READY = 0,
        ADC_STATE_WAIT = 1,
        ADC_STATE_CONTINUE = 2,
        ADC_STATE_CONVERSION_START = 3,
        ADC_STATE_CONVERSION_COMPLETE = 4,
        ADC_STATE_READ_PENDING = 5,
        ADC_STATE_READ_VALUE = 6,
    } ADC_STATES;

    typedef enum {
        ADC_MEASUREMENT_IDLE = 0,
        ADC_MEASUREMENT_ONLY = 1,
        ADC_MEASUREMENT_BEGINNING = 2,
        ADC_MEASUREMENT_ENDING = 3,
    } ADC_MEASUREMENTS;

    typedef enum {
        PACKET_EMPTY = 0,
        PACKET_LOOK_FOR_START = 1,
        PACKET_LOOK_FOR_DATA = 2,
        PACKET_RECEIVE_COMPLETE = 3,
        PACKET_SEND_START = 4,
        PACKET_SEND_PENDING = 5,
        PACKET_SEND_COMPLETE = 6,
        PACKET_ERROR = 6
    } PACKET_STATES;

    typedef volatile struct {
        ADC_STATES volatile ADC_state;
        DAC_STATES volatile DAC_state;
        DRV_SPI_BUFFER_EVENT volatile RX_status;
        DRV_SPI_BUFFER_EVENT volatile TX_status;
        DRV_SPI_BUFFER_HANDLE RX_handle;
        DRV_SPI_BUFFER_HANDLE TX_handle;
    } SYSTEM_DEVICE_DATA_SPI;

    typedef volatile struct {
        PACKET_STATES volatile packetState;
    } SYSTEM_DEVICE_DATA_USART;

    typedef volatile struct {
        SYSTEM_DEVICE_DATA_SPI volatile SPI0;
        SYSTEM_DEVICE_DATA_SPI volatile SPI1;
        SYSTEM_DEVICE_DATA_USART volatile USART0;
    } SYSTEM_DEVICE_DATA;

    typedef struct {
        DRV_SPI_CLIENT_DATA ADC0_clientData;
        DRV_SPI_CLIENT_DATA DAC0_clientData;
        DRV_HANDLE driverHandle;
    } APP_DEVICE_DATA_SPI;

    typedef struct {
        DRV_HANDLE driverHandle;
    } APP_DEVICE_DATA_USART;

    typedef struct {
        APP_DEVICE_DATA_SPI SPI0;
        APP_DEVICE_DATA_SPI SPI1;
        APP_DEVICE_DATA_USART USART0;

    } APP_DEVICE_DATA;

    typedef struct {
        uint32_t start;
        uint32_t end;
        ADC_MEASUREMENTS type;
    } APP_GALVO_DATA_AXIS_MEASUREMENT;

    typedef struct {
        uint32_t current;
        uint32_t final;
        uint32_t stepSize;
        DAC_DIRECTIONS direction;
        APP_GALVO_DATA_AXIS_MEASUREMENT Measurement;
    } APP_GALVO_DATA_AXIS;

    typedef struct {
        APP_GALVO_DATA_AXIS X_Axis;
        APP_GALVO_DATA_AXIS Y_Axis;
        float speed;

    } APP_GALVO_DATA;

    typedef volatile struct {
        SYSTEM_DEVICE_DATA Device;
    } SYSTEM_APP_DATA;

    typedef struct {
        APP_STATES state;
        APP_GALVO_DATA GalvoController;
        APP_DEVICE_DATA Device;
    } APP_DATA;

    // *****************************************************************************
    // *****************************************************************************
    // Section: Data Pointers
    // *****************************************************************************
    // *****************************************************************************

    static APP_DATA * const client_data_ptr(void);
    static APP_GALVO_DATA * const galvo_ptr(void);
    static APP_STATES * const client_state_ptr(void);

    static DRV_SPI_CLIENT_DATA * const adc0_config_ptr(void);
    static DRV_SPI_CLIENT_DATA * const dac0_config_ptr(void);

    static HOST_MESSAGE_DATA volatile * const message_ptr(void);

    static SYSTEM_DEVICE_DATA volatile * const sys_dev_data_ptr(void);
    static SYSTEM_DEVICE_DATA_SPI volatile * const spi0_ptr(void);
    static PACKET_STATES volatile * const packet_state_ptr(void);

    // *****************************************************************************
    // *****************************************************************************
    // Section: Local Calculator Functions
    // *****************************************************************************
    // *****************************************************************************

    /* ComputerStepSize : Returns the number of [DAC counts] 
     * (0x0 to 0x3FFFF Full Scale) the DAC'A'_currentValue is to be incremented by
     * for a single DAC update cycle */
    static uint32_t ComputeStepSize(uint32_t currentA, uint32_t finalA,
            uint32_t currentB, uint32_t finalB, float speed);

    // *****************************************************************************
    // *****************************************************************************
    // Section: Local Application Processes
    // *****************************************************************************
    // *****************************************************************************

    /* Utility opens driver connections and sets/gathers initial values */
    static void InitalizeDevices(void);

    /* Host<->Client Command/Response Methods */
    static void processHostMessage(HOST_MESSAGE_DATA volatile * const messPtr,
            APP_DATA * const clientDataPtr,
            SYSTEM_DEVICE_DATA volatile * const sysDevPtr);
    static void GetMessageFromHost(void);

    static void generateClientReply(uint8_t *usartTXbuf, uint8_t *usartTXcount, uint8_t *tx_length);
    static void sendClientReply(uint8_t *usartTXbuf, uint8_t *usartTXcoun, uint8_t *tx_length, PACKET_STATES volatile * const pcktPtr);
    static void SendReplyToHost(void);

    /* DAC Write Methods for Galvo */
    static void DAC0_Tasks(APP_GALVO_DATA_AXIS * const a_axis);
    static void WriteToDAC(void);

    /* ADC Read Methods for Galvo */
    static uint32_t sampleAccumulator(uint32_t tempVal, bool *finishFlag);
    static void ReadFromADC(void);

    // *****************************************************************************
    // *****************************************************************************
    // Section: Application Initialization and State Machine Functions
    // *****************************************************************************
    // *****************************************************************************

    /*******************************************************************************
      Function:
        void APP_Initialize ( void )

      Summary:
         MPLAB Harmony application initialization routine.

      Description:
        This function initializes the Harmony application.  It places the 
        application in its initial state and prepares it to run so that its 
        APP_Tasks function can be called.

      Precondition:
        All other system initialization routines should be called before calling
        this routine (in "SYS_Initialize").

      Remarks:
        This routine must be called from the SYS_Initialize function.
     */
    void APP_Initialize(void);

    /*******************************************************************************
      Function:
        void APP_Tasks ( void )

      Summary:
        MPLAB Harmony Demo application tasks function

      Description:
        This routine is the Harmony Demo application's tasks function.  It
        defines the application's state machine and core logic.

      Remarks:
        This routine must be called from SYS_Tasks() routine.
     */
    void APP_Tasks(void);

    // *****************************************************************************
    // *****************************************************************************
    // Section: Application Callback Routines
    // *****************************************************************************
    // *****************************************************************************
    /* These routines are called by drivers when certain events occur.*/

    void APP_USARTReceiveEventHandler(const SYS_MODULE_INDEX index);

    void SPI0_DAC0_CallBack_Start(DRV_SPI_BUFFER_EVENT eEvent, DRV_SPI_BUFFER_HANDLE bufferHandle, void *context);
    void SPI0_DAC0_CallBack_End(DRV_SPI_BUFFER_EVENT eEvent, DRV_SPI_BUFFER_HANDLE bufferHandle, void *context);

    void SPI0_ADC0_CallBack_Start(DRV_SPI_BUFFER_EVENT eEvent, DRV_SPI_BUFFER_HANDLE bufferHandle, void *context);
    void SPI0_ADC0_CallBack_End(DRV_SPI_BUFFER_EVENT eEvent, DRV_SPI_BUFFER_HANDLE bufferHandle, void *context);

#endif /* _APP_H */

    //DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

/*******************************************************************************
 End of File */