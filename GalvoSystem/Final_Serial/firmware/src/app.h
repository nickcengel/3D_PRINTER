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

#include "message_components.h"
// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

extern "C" {

#endif
    // DOM-IGNORE-END 

#define DAC_DIN_REG_WRITE 0x1
#define DAC_OFFSET_REG_WRITE 0x2    
#define DAC_GAIN_REG_WRITE 0x3
#define DAC_CONFIG_REG_WRITE 0x4    
#define DAC_DIN_REG_READ 0x9
#define DAC_OFFSET_REG_READ 0xA    
#define DAC_GAIN_REG_READ 0xB
#define DAC_CONFIG_REG_READ 0xC



    /* MAX5318 SPI DAC SETUP  VALUES*/

    // so that outgoing unsigned number
    // maps to FS differential range 
    /* TMR0 controls chip-select/conversionstart timing for ADC*/

    volatile bool tmr0_flag;
    volatile bool tmr1_flag;
#define SPI_TX_BUFF_SIZE 4
#define SPI_RX_BUFF_SIZE 4
#define   DAC0_OFFSET  0x201EA // added to incoming signed number 
#define ADC0_OFFSET 0x1FFF4
#define DEFAULT_GALVO_SPEED  13.5
#define DAC_UPDATE_PERIOD  8.0




    //***** SOFTWARE STATES ******//

    /*Primary App states*/
    typedef enum {
        APP_STATE_INIT = 0,
        APP_GET_NEW_MESSAGE,
        APP_PROCESS_MESSAGE,
        APP_WRITE_TO_DAC,
        APP_READ_FROM_ADC,
        APP_SEND_REPLY
    } APP_STATES;

    /* message states for USART communication with PC */

    //*****************************//

    //***** HARDWARE STATES ******//

    /* USART function states*/
    typedef enum {
        USART_INIT = 0,
        USART_IDLE,
        USART_GRAB_BYTE,
        USART_THROW_BYTE,


    } USART_STATES;

    /* SPI function states */
    typedef enum {
        SPI_INIT_OFFSET = -2,
        SPI_INIT_GAIN = -1,
        SPI_IDLE = 0,
        SPI_WRITE_START,
        SPI_WRITE_BUSY,
        SPI_WRITE_COMPLETE,
        SPI_READ_START,
        SPI_READ_BUSY,
        SPI_READ_COMPLETE
    } SPI_STATES;

    //*****************************//

    /* persistent local app data*/
    typedef struct {
        APP_STATES appState;
        MESSAGE_DATA hostMessage;

        USART_STATES usart0State;
        DRV_HANDLE usart0Handle;

        SPI_STATES spi0State;
        DRV_HANDLE spi0Handle;

        uint32_t ADC0_value;

        DRV_SPI_BUFFER_HANDLE spi0_buf_handle;
        DRV_SPI_BUFFER_EVENT spi0_buf_status;

        uint8_t *spi0_tx_bufPtr;
        uint8_t *spi0_rx_bufPtr;
        uint8_t *usart0_tx_bufPtr;
        uint8_t *usart0_rx_bufPtr;
        
        
        uint8_t usart0_rx_count;
        uint8_t usart0_tx_count;
        uint8_t usart0_tx_length;


        uint32_t DAC0_currentValue;
        uint32_t DAC0_finalValue;
        uint32_t DAC1_currentValue;
        uint32_t DAC1_finalValue;
        uint32_t stepSizeX;
        uint32_t stepSizeY;
    } APP_DATA;


    int stringToInt(uint8_t *str);
    uint32_t stepSizeCalc(uint32_t currennt, uint32_t final, float speed);

    void USART0_TaskHandler(void);
    
    void set_DAC0_StartVal(uint32_t startVal);
    void DAC0_Write(void);
    void DAC0_Confirm_Write(void);
    
    uint32_t ADC0_Read(void);

    void APP_Initialize(void);
    void APP_Tasks(void);


    /* called by APP_Tasks tp handle communication with PC */
    /* internally advances appState */



#endif /* _APP_H */

    //DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

/*******************************************************************************
 End of File
 */

