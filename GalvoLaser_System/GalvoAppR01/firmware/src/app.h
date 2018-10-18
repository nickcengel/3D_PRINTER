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
#include "system_config.h"
#include "system_definitions.h"
#include <math.h>
#include "app_host_client_interface.h"


// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

extern "C" {

#endif
    // DOM-IGNORE-END 

    // *****************************************************************************
    // *****************************************************************************
    // Section: App Definitions
    // *****************************************************************************
    // *****************************************************************************
#define USART0_RX_BUFF_SIZE 16
#define USART0_TX_BUFF_SIZE 48

#define SPI_TX_BUFF_SIZE 3
#define SPI_RX_BUFF_SIZE 3

#define DAC_DIN_REG_WRITE 0x1
#define DAC0_OFFSET 0x20000
#define DAC1_OFFSET 0x20000
#define DAC_UPDATE_PERIOD_COUNTS 774
#define DAC_UPDATE_PERIOD_uS 16.0
#define GALVO_DEFAULT_SPEED 1563
    
#define ADC0_OFFSET 0x20000
#define ADC1_OFFSET 0x20000
#define ADC_HOLDOFF_COUNTS 16
#define ADC_CNV_TRIG_COUNTS  10

    // *****************************************************************************
    // *****************************************************************************
    // Section: Type Definitions
    // *****************************************************************************
    // *****************************************************************************

    typedef enum {
        ADC_READY,
        ADC_READ_PENDING,
        ADC_DISABLED
    } APP_ADC_STATES;

    typedef struct {
        uint32_t stepSize;
        uint32_t currentPosition;
        uint32_t finalPosition;
        uint32_t reading;
        uint8_t DAC_enabled;
        uint8_t ADC_enabled;
        uint8_t processComplete;
        APP_ADC_STATES ADC_state;
    } APP_GALVO_AXIS_DATA;

    typedef struct {
        uint8_t DAC_jobPending;
        uint8_t ADC_jobPending;
        APP_GALVO_AXIS_DATA X;
        APP_GALVO_AXIS_DATA Y;
        HCI_DEVICE_STATES state;
        uint32_t speed;
    } APP_GALVO_DATA;

    typedef struct {
        uint8_t armed;
        uint8_t enabled;
        uint32_t power;
    } APP_LASER_DATA;

    typedef struct {
        uint16_t jobNumber;
        HCI_JOB_TYPE jobType;
        HCI_REPLY_TYPE replyType;
    } APP_JOB_INFO;

    typedef struct {
        DRV_HANDLE drvHandle;
        DRV_SPI_BUFFER_HANDLE tx_bufHandle;
        DRV_SPI_BUFFER_HANDLE rx_bufHandle;
        DRV_SPI_CLIENT_DATA ADC_clientData;
        DRV_SPI_CLIENT_DATA DAC_clientData;
    } APP_SPI_DATA;

    typedef enum {
        APP_STATE_INIT = 0,
        APP_READ_FROM_HOST,
        APP_WRITE_TO_HOST,
        APP_WRITE_TO_GALVO,
        APP_READ_FROM_GALVO
    } APP_STATES;

    typedef struct {
        APP_STATES state;
        APP_GALVO_DATA Galvo;
        APP_SPI_DATA drvSPI0;
        APP_SPI_DATA drvSPI1;
        APP_LASER_DATA Laser;
        uint8_t HCI_WritePending;
        APP_JOB_INFO jobInfo;
        DRV_HANDLE usart0_Handle;
    } APP_DATA;

    // *****************************************************************************
    // *****************************************************************************
    // Section: Global Data Access
    // *****************************************************************************
    // *****************************************************************************

    DRV_SPI_BUFFER_EVENT volatile APP_SPI0_TX_Status(void);

    DRV_SPI_BUFFER_EVENT volatile APP_SPI0_RX_Status(void);

    DRV_SPI_BUFFER_EVENT volatile APP_SPI1_TX_Status(void);

    DRV_SPI_BUFFER_EVENT volatile APP_SPI1_RX_Status(void);

    // *****************************************************************************
    // *****************************************************************************
    // Section: Application Callback Routines
    // *****************************************************************************
    // *****************************************************************************

    void APP_USARTReceiveEventHandler(const SYS_MODULE_INDEX index);

    void APP_DAC0_CallBack_Start(DRV_SPI_BUFFER_EVENT eEvent, DRV_SPI_BUFFER_HANDLE bufferHandle, void *context);

    void APP_DAC0_CallBack_End(DRV_SPI_BUFFER_EVENT eEvent, DRV_SPI_BUFFER_HANDLE bufferHandle, void *context);

    void APP_ADC0_CallBack_Start(DRV_SPI_BUFFER_EVENT eEvent, DRV_SPI_BUFFER_HANDLE bufferHandle, void *context);

    void APP_ADC0_CallBack_End(DRV_SPI_BUFFER_EVENT eEvent, DRV_SPI_BUFFER_HANDLE bufferHandle, void *context);

    void APP_DAC1_CallBack_Start(DRV_SPI_BUFFER_EVENT eEvent, DRV_SPI_BUFFER_HANDLE bufferHandle, void *context);

    void APP_DAC1_CallBack_End(DRV_SPI_BUFFER_EVENT eEvent, DRV_SPI_BUFFER_HANDLE bufferHandle, void *context);

    void APP_ADC1_CallBack_Start(DRV_SPI_BUFFER_EVENT eEvent, DRV_SPI_BUFFER_HANDLE bufferHandle, void *context);

    void APP_ADC1_CallBack_End(DRV_SPI_BUFFER_EVENT eEvent, DRV_SPI_BUFFER_HANDLE bufferHandle, void *context);

    // *****************************************************************************
    // *****************************************************************************
    // Section: Application Local Functions
    // *****************************************************************************
    // *****************************************************************************

    int32_t APP_Convert_String_To_Int(uint8_t *str);

    void APP_Compute_StepSize(void);

    // *****************************************************************************
    // *****************************************************************************
    // Section: Application Initialization and State Machine Functions
    // *****************************************************************************
    // *****************************************************************************

    // Initialization
    // *****************************************************************************
    void APP_SPI0_Initialize(void);

    void APP_SPI1_Initialize(void);

    void APP_GALVO_Initialize(void);

    void APP_LASER_Initialize(void);

    void APP_JOB_INFO_Initialize(void);

    void APP_HCI_Initialize(void);

    void APP_Initialize(void);

    // Host<->Client Interface
    // *****************************************************************************
    void APP_Open_HCI_Packet(void);

    void APP_Write_HCI_Packet(void);

    // Galvo Interface 
    // *****************************************************************************
    void APP_GALVO_Launch_DAC_Process(void);

    void APP_GALVO_Run_DAC_Process(void);

    void APP_GALVO_Launch_ADC_Process(void);

    void APP_GALVO_Run_ADC_Process(void);

    // Application State Machine 
    // *****************************************************************************
    void APP_Next_Task(void);

    void APP_Tasks(void);

#endif /* _APP_H */

    //DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

/*******************************************************************************
 End of File
 */

