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

    // *****************************************************************************

    /* Application states

      Summary:
        Application states enumeration

      Description:
        This enumeration defines the valid application states.  These states
        determine the behavior of the application at various times.
     */
    /* MAX5318 SPI DAC COMMAND REGISTER VALUES*/
#define DAC_DIN_REG_WRITE 0x1
#define DAC_OFFSET_REG_WRITE 0x2    
#define DAC_GAIN_REG_WRITE 0x3
#define DAC_CONFIG_REG_WRITE 0x4    
#define DAC_DIN_REG_READ 0x9
#define DAC_OFFSET_REG_READ 0xA    
#define DAC_GAIN_REG_READ 0xB
#define DAC_CONFIG_REG_READ 0xC

    /* MAX5318 SPI DAC SETUP  VALUES*/
    const uint32_t dac0_offset_val = 0x201EA; // added to incoming signed number 
    // so that outgoing unsigned number
    // maps to FS differential range  

#define SPI_TX_BUFF_SIZE 4
#define SPI_RX_BUFF_SIZE 4

    uint8_t spi0_tx_buffer[SPI_TX_BUFF_SIZE];
    uint8_t spi0_rx_buffer[SPI_RX_BUFF_SIZE];

    DRV_SPI_BUFFER_HANDLE spi0_buf_handle;
    DRV_SPI_BUFFER_EVENT spi0_buf_status;

    
#define USART0_RX_BUFF_SIZE 30
#define USART0_TX_BUFF_SIZE 33

    uint8_t usart0_rx_buffer[USART0_RX_BUFF_SIZE];
    uint8_t usart0_tx_buffer[USART0_TX_BUFF_SIZE];
    uint8_t usart0_rx_count;
    uint8_t usart0_tx_count;
    uint8_t usart0_tx_length;

    
    /* TMR0 controls chip-select/conversionstart timing for ADC*/
    volatile bool tmr0_flag;

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
    typedef enum {
        MESSAGE_IDLE,
        MESSAGE_LOOK_FOR_START,
        MESSAGE_LOOK_FOR_DATA,
        MESSAGE_RECEIVE_COMPLETE,
        MESSAGE_SEND_BUSY,
        MESSAGE_SEND_COMPLETE,
        MESSAGE_ERROR
    } MESSAGE_STATES;

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


    /* Data received over USART from master is stored in MESSAGE_DATA Struct */

    /* List of possible commanded states */
    typedef enum {
        ENABLE = 1, DISABLE, RELATIVE_MOVE, ABSOLUTE_MOVE, NONE
    } COMPONENT_STATES;

    /* List of data parameter labels in the order they are expected to arrive */
    typedef enum {
        NO_PARAMETER = -1, L_STATE = 0, L_POWER, G_STATE, X_POS, Y_POS, G_SPEED, END_PARAMETERS
    } PARAMETER_LABELS;

    /* data type for storing information received from PC */
    typedef struct {
        COMPONENT_STATES laserState;
        int laserPower;
        COMPONENT_STATES galvoState;
        int xPosition;
        int yPosition;
        int gSpeed;

        bool activeParameter[6]; // each bit in the array corresponds to a parameter.
        // Set true when valid data is read from PC

        PARAMETER_LABELS parameterIterator; // Used to step through each parameter field
        // filling with data from PC
    } MESSAGE_DATA;

    /* getters and setters for Message Data */
    int getMessageData(MESSAGE_DATA *m, PARAMETER_LABELS dataLabel);
    void setMessageData(MESSAGE_DATA *m, PARAMETER_LABELS label, int value);

    /* automatically increments parameterIterator used to fill data from PC */
    void addActiveParameter(MESSAGE_DATA *m, int value);

    /* persistent local app data*/
    typedef struct {
        APP_STATES appState;
        MESSAGE_STATES messageState;

        USART_STATES usart0State;
        DRV_HANDLE usart0Handle;

        SPI_STATES spi0State;
        DRV_HANDLE spi0Handle;

    } APP_DATA;

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

      Parameters:
        None.

      Returns:
        None.

      Example:
        <code>
        APP_Initialize();
        </code>

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

      Precondition:
        The system and application initialization ("SYS_Initialize") should be
        called before calling this.

      Parameters:
        None.

      Returns:
        None.

      Example:
        <code>
        APP_Tasks();
        </code>

      Remarks:
        This routine must be called from SYS_Tasks() routine.
     */

    void APP_Tasks(void);
    
    /* called by APP_Tasks tp handle communication with PC */
    /* internally advances appState */
    void USART_Tasks(void);

#endif /* _APP_H */

    //DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

/*******************************************************************************
 End of File
 */

