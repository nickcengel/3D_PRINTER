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

/* TODO:  Add any necessary local functions.
 */

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
  appData.app_state = APP_STATE_INIT;
  appData.port_state = PORT_UNAVAILABLE;
  appData.read_state = READ_EMPTY;
  appData.write_state = WRITE_EMPTY;
  appData.process_state = PROCESS_EMPTY;

  appData.readIndex = 0;

  DRV_USART0_Initialize();

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
  switch (appData.app_state) {
    /* Application's initial state. */
  case APP_STATE_INIT: {
    bool appInitialized = true;

    if (appInitialized) {

      appData.app_state = APP_GET_PORT_STATUS;
    }
    break;
  }

  case APP_GET_PORT_STATUS: {
    appData.port_state = PORT_AVAILABLE;

    appData.app_state = APP_IDLE;

    break;
  }

  case APP_PORT_NOT_CONNECTED: {

    break;
  }

  case APP_IDLE: {
    if (appData.read_state >= READ_FINISHED &&
        appData.write_state >= WRITE_FINISHED)
      appData.app_state = APP_READ_FROM_MASTER;
    // else, wait
    break;
  }

  case APP_READ_FROM_MASTER: {
    switch (appData.read_state) {
    case READ_EMPTY: {
      if (!DRV_USART0_ReceiverBufferIsEmpty())
        appData.read_state = READ_READY;
      break;
    }
    case READ_READY: {
      appData.readIndex = 0;
      appData.read_state = READ_FIND_START;
      break;
    }
    case READ_FIND_START: {
      while (!DRV_USART0_ReceiverBufferIsEmpty()) {
        const char c = DRV_USART0_ReadByte();
        if (c == '/') {
          appData.incomingMessage[appData.readIndex] = c;
          appData.readIndex++;
          appData.read_state = READ_FIND_DATA;
          break;
        }
      }
      break;
    }
    case READ_FIND_DATA: {

      while (!DRV_USART0_ReceiverBufferIsEmpty()) {
        const char c = DRV_USART0_ReadByte();
        appData.incomingMessage[appData.readIndex] = c;
        appData.readIndex++;
        if ((c == ';') || (appData.readIndex > READ_SIZE - 2)) {

          break;
        }
      }
        appData.read_state = READ_FINISHED;
        appData.readMessageLength = appData.readIndex;
        appData.app_state = APP_PROCESS_MESSAGE_FROM_MASTER;
      break;
    }
    default:
      break;
    }
    break;
  }

  case APP_PROCESS_MESSAGE_FROM_MASTER: {
    if (appData.read_state == READ_FINISHED)
      appData.process_state = PROCESS_READ_BUSY;

    /// ....
    //// at the end
    appData.process_state = PROCESS_READ_FINISHED;
    appData.app_state = APP_COMPOSE_REPLY_TO_MASTER;
    break;
  }
  case APP_COMPOSE_REPLY_TO_MASTER: {
    if (appData.process_state == PROCESS_READ_FINISHED) {
      appData.process_state = PROCESS_WRITE_BUSY;
      appData.outgoingMessage = "@OK";
      appData.writeMessageLength = 3;
    }
    /////// .....
    if ((appData.write_state == PROCESS_WRITE_BUSY) &&
        (appData.writeMessageLength > 0)) {
      appData.process_state = PROCESS_WRITE_FINISHED;
      appData.write_state = WRITE_READY;
      appData.app_state = APP_WRITE_TO_MASTER;
    }
    break;
  }
  case APP_WRITE_TO_MASTER: {
    if ((appData.write_state == WRITE_READY) &&
        (appData.process_state == PROCESS_WRITE_FINISHED) &&
        appData.writeMessageLength < WRITE_SIZE - 1) {
      appData.write_state = WRITE_BUSY;
      appData.writeIndex = 0;
    }

    if (appData.write_state == WRITE_BUSY) {
      while ((!DRV_USART0_TransmitBufferIsFull()) &&
             (appData.writeIndex < appData.writeMessageLength)) {
        const uint8_t c = appData.outgoingMessage[appData.writeIndex];
        DRV_USART0_WriteByte(c);
        appData.writeIndex++;
        if (appData.writeIndex == appData.writeMessageLength) {
          appData.write_state = WRITE_FINISHED;
          appData.app_state = APP_CLEAN_UP;
          break;
        }
      }
    }

    break;
  }
  case APP_CLEAN_UP: {
    if (appData.write_state == WRITE_FINISHED) {

      appData.read_state = READ_EMPTY;
      for (appData.readIndex = 0; appData.readIndex < appData.readMessageLength; appData.readIndex++)
        appData.incomingMessage[appData.readIndex] = 0;

      appData.readIndex = 0;

      appData.process_state = PROCESS_EMPTY;

      appData.write_state = WRITE_EMPTY;
      for (appData.writeIndex = 0; appData.writeIndex < appData.writeMessageLength; appData.writeIndex++)
        appData.outgoingMessage[appData.writeIndex] = 0;

      appData.writeIndex = 0;

      appData.app_state = APP_IDLE;
    }

    break;
  }
  case APP_HANDLE_ERRORS: {

    break;
  }

  /* The default state should never be executed. */
  default: { break; }
  }
}

/*******************************************************************************
 End of File
 */
