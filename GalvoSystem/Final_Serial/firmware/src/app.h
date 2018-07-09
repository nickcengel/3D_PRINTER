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

#define USART_RX_BUFF_SIZE 30
#define USART_TX_BUFF_SIZE 33

#define SPI_TX_BUFF_SIZE 4

    bool tmr0_flag;

    typedef enum {
        /* Application's state machine's initial state. */
        APP_STATE_INIT = 0,
        APP_GET_NEW_MESSAGE,
        APP_PROCESS_MESSAGE,
        APP_WRITE_TO_DAC,
        APP_CONFIRM_DAC,
        APP_SEND_REPLY

        /* TODO: Define states used by the application state machine. */

    } APP_STATES;

    typedef enum {
        MESSAGE_IDLE,
        MESSAGE_LOOK_FOR_START,
        MESSAGE_LOOK_FOR_DATA,
        MESSAGE_RECEIVE_COMPLETE,
        MESSAGE_SEND_BUSY,
        MESSAGE_SEND_COMPLETE,

        MESSAGE_ERROR


    } MESSAGE_STATES;

    typedef enum {
        USART_INIT = 0,
        USART_IDLE,
        USART_GRAB_BYTE,
        USART_THROW_BYTE,


    } USART_STATES;

    typedef enum {
        SPI_IDLE = 0,
        SPI_WRITE_START,
        SPI_WRITE_COMPLETE,
        SPI_READ_START,
        SPI_READ_COMPLETE
    } SPI_STATES;
    // *****************************************************************************

    /* Application Data

      Summary:
        Holds application data

      Description:
        This structure holds the application's data.

      Remarks:
        Application strings and buffers are be defined outside this structure.
     */
    typedef enum {
        ENABLE = 1, DISABLE, RELATIVE_MOVE, ABSOLUTE_MOVE, NONE
    } COMPONENT_STATES;

    typedef enum {
        NO_PARAMETER = -1, L_STATE = 0, L_POWER, G_STATE, X_POS, Y_POS, G_SPEED, END_PARAMETERS
    } PARAMETER_LABELS;

    typedef struct {
        COMPONENT_STATES laserState;
        int laserPower;
        COMPONENT_STATES galvoState;
        int xPosition;
        int yPosition;
        int gSpeed;

        bool activeParameter[6];
        PARAMETER_LABELS parameterIterator;

    } MESSAGE_DATA;

    int getMessageData(MESSAGE_DATA *m, PARAMETER_LABELS dataLabel);
    void setMessageData(MESSAGE_DATA *m, PARAMETER_LABELS label, int value);

    void addActiveParameter(MESSAGE_DATA *m, int value);

    typedef struct {
        /* The application's current state */
        APP_STATES appState;
        MESSAGE_STATES messageState;

        USART_STATES usartState;
        DRV_HANDLE usartHandle;

        SPI_STATES spiState;
        DRV_HANDLE spiHandle;

        /* TODO: Define any additional data used by the application. */

    } APP_DATA;

    uint8_t usart_rx_buffer[USART_RX_BUFF_SIZE];
    uint8_t usart_tx_buffer[USART_TX_BUFF_SIZE];
    uint8_t usart_rx_count;
    uint8_t usart_tx_count;
    uint8_t usart_tx_length;
    
    uint8_t spi_tx_buffer[SPI_TX_BUFF_SIZE];
    DRV_SPI_BUFFER_HANDLE spi_buf_handle;
    DRV_SPI_BUFFER_EVENT spi_buf_status;




    // *****************************************************************************
    // *****************************************************************************
    // Section: Application Callback Routines
    // *****************************************************************************
    // *****************************************************************************
    /* These routines are called by drivers when certain events occur.
     */

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
    void SPI_Tasks(void);
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

