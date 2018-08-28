/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Company Name

  @File Name
    filename.c

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

/* This section lists the other files that are included in this file.
 */

#include "dev_dac_io.h"

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: File Scope or Global Data                                         */
/* ************************************************************************** */
/* ************************************************************************** */
DEV_DAC_OBJ gDacObject[2];

static uint8_t SPI0_TX_Buffer[SPI_TX_BUFF_SIZE];
static uint8_t SPI1_TX_Buffer[SPI_TX_BUFF_SIZE];

/* ************************************************************************** */
/* ************************************************************************** */
// Section: Local Functions                                                   */
/* ************************************************************************** */

/* ************************************************************************** */


void DEV_DAC0_Write(uint32_t value) {
    DEV_DAC_OBJ *pObj = (DEV_DAC_OBJ *) & gDacObject[DEV_DAC0_INDEX];
    DEV_DAC0_UNLATCH();
    SPI0_TX_Buffer[0] = DAC_DIN_REG_WRITE << 4;
    SPI0_TX_Buffer[0] |= (0xFF & (value >> 14));
    SPI0_TX_Buffer[1] = (0xFF & (value >> 6));
    SPI0_TX_Buffer[2] = (0xFF & (value << 2));
    pObj->bufferHandle = DRV_SPI0_BufferAddWrite(SPI0_TX_Buffer, 3, 0, pObj);
}

void DEV_DAC1_Write(uint32_t value) {
    DEV_DAC_OBJ *pObj = (DEV_DAC_OBJ *) & gDacObject[DEV_DAC1_INDEX];
    DEV_DAC1_UNLATCH();
    SPI1_TX_Buffer[0] = DAC_DIN_REG_WRITE << 4;
    SPI1_TX_Buffer[0] |= (0xFF & (value >> 14));
    SPI1_TX_Buffer[1] = (0xFF & (value >> 6));
    SPI1_TX_Buffer[2] = (0xFF & (value << 2));
    pObj->bufferHandle = DRV_SPI1_BufferAddWrite(SPI1_TX_Buffer, 3, 0, pObj);
}


/* ************************************************************************** */
/* ************************************************************************** */
// Section: Interface Functions                                               */
/* ************************************************************************** */

/* ************************************************************************** */

void DEV_DAC_Initialize(const SYS_MODULE_INDEX index) {
    DEV_DAC_OBJ *pObj = (DEV_DAC_OBJ *) & gDacObject[index];
    pObj->DacHandle = (DEV_HANDLE) index;
    pObj->state = DAC_STATE_INIT;
    pObj->connected = false;
    //    pObj->enabled = false;

    pObj->spiHandle = DRV_HANDLE_INVALID;
    pObj->spiClientData.baudRate = 50000000;
    pObj->spiClientData.operationStarting = DEV_DAC_CallBack_Start;
    pObj->spiClientData.operationEnded = DEV_DAC_CallBack_End;
}

DEV_HANDLE DEV_DAC_Open(const SYS_MODULE_INDEX index) {
    DEV_DAC_OBJ *pObj = (DEV_DAC_OBJ *) & gDacObject[index];
    switch (index) {
        case DEV_DAC0_INDEX:
        {
            if (pObj->spiHandle == DRV_HANDLE_INVALID) {
                pObj->spiHandle = DRV_SPI0_Open(DRV_SPI_INDEX_0,
                        DRV_IO_INTENT_WRITE | DRV_IO_INTENT_NONBLOCKING);
                pObj->state = DAC_STATE_IDLE;
            }
            break;
        }
        case DEV_DAC1_INDEX:
        {
            if (pObj->spiHandle == DRV_HANDLE_INVALID) {
                pObj->spiHandle = DRV_SPI1_Open(DRV_SPI_INDEX_1,
                        DRV_IO_INTENT_WRITE | DRV_IO_INTENT_NONBLOCKING);
                pObj->state = DAC_STATE_IDLE;
            }
            break;
        }
        default:
        {
            break;
        }
    }
    if (pObj->spiHandle != DRV_HANDLE_INVALID)
        return (pObj->DacHandle);
    else
        return DEV_HANDLE_INVALID;
}

DEV_HANDLE DEV_DAC_Connect(const SYS_MODULE_INDEX index) {
    DEV_DAC_OBJ *pObj = (DEV_DAC_OBJ *) & gDacObject[index];
    switch (index) {
        case DEV_DAC0_INDEX:
        {
            DRV_SPI0_ClientConfigure(&(pObj->spiClientData));
            pObj->bufferStatus = DRV_SPI_BUFFER_EVENT_COMPLETE;
            pObj->connected = true;
            pObj->state = DAC_STATE_LATCHED;
            break;
        }

        case DEV_DAC1_INDEX:
        {
            DRV_SPI1_ClientConfigure(&(pObj->spiClientData));
            pObj->bufferStatus = DRV_SPI_BUFFER_EVENT_COMPLETE;
            pObj->connected = true;
            pObj->state = DAC_STATE_LATCHED;
            break;
        }

        default:
        {
            pObj->connected = false;
            break;
        }
    }
    return (DEV_HANDLE) index;
}

void DEV_DAC_Disconnect(const SYS_MODULE_INDEX index) {
    DEV_DAC_OBJ *pObj = (DEV_DAC_OBJ *) & gDacObject[index];
    pObj->connected = false;
    pObj->state = DAC_STATE_IDLE;
}

bool DEV_DAC_Available(void) {
    if ((gDacObject[DEV_DAC0_INDEX].state == DAC_STATE_LATCHED)
            && (gDacObject[DEV_DAC1_INDEX].state == DAC_STATE_LATCHED))
        return true;
    else
        return false;
}

void DEV_DAC_Write(const SYS_MODULE_INDEX index, uint32_t val) {
    if (gDacObject[index].bufferStatus == DRV_SPI_BUFFER_EVENT_COMPLETE) {
        switch (index) {
            case DEV_DAC0_INDEX:
            {
                DEV_DAC0_Write(val);
                break;
            }
            case DEV_DAC1_INDEX:
            {
                DEV_DAC1_Write(val);
                break;
            }
            default:
                break;
        }
    }
}


// *****************************************************************************
// *****************************************************************************
// Section: CallBack Functions
// *****************************************************************************
// *****************************************************************************

void DEV_DAC_CallBack_Start(DRV_SPI_BUFFER_EVENT eEvent, DRV_SPI_BUFFER_HANDLE bufferHandle, void *context) {
//    DEV_DAC_OBJ *pObj = (DEV_DAC_OBJ *) context;
//    switch (pObj->DacHandle) {
//        case DEV_DAC0_INDEX:
//        {
//            DEV_DAC0_SELECT();
//            break;
//        }
//        case DEV_DAC1_INDEX:
//        {
//            DEV_DAC1_SELECT();
//            break;
//        }
//        default:
//            break;
//    }
//    pObj->bufferStatus = eEvent;
//    pObj->state = DAC_STATE_WRITE_STARTED;

}

void DEV_DAC_CallBack_End(DRV_SPI_BUFFER_EVENT eEvent, DRV_SPI_BUFFER_HANDLE bufferHandle, void *context) {
//    DEV_DAC_OBJ *pObj = (DEV_DAC_OBJ *) context;;
//
//    switch (pObj->DacHandle) {
//        case DEV_DAC0_INDEX:
//        {
//            DEV_DAC0_DESELECT();
//            break;
//        }
//        case DEV_DAC1_INDEX:
//        {
//            DEV_DAC1_DESELECT();
//            break;
//        }
//        default:
//            break;
//    }
//
//    pObj->bufferStatus = eEvent;
//    pObj->state = DAC_STATE_WRITE_COMPLETE;
}

void DEV_DAC_Confirm(void) {
    if ((gDacObject[DEV_DAC0_INDEX].state == DAC_STATE_WRITE_COMPLETE) &&
            (gDacObject[DEV_DAC1_INDEX].state == DAC_STATE_WRITE_COMPLETE)) {
        gDacObject[DEV_DAC0_INDEX].state = DAC_STATE_LATCHED;
        gDacObject[DEV_DAC1_INDEX].state = DAC_STATE_LATCHED;
        DEV_DAC0_LATCH();
        DEV_DAC1_LATCH();
    }
}

// *****************************************************************************
// *****************************************************************************
// Section: Timer Interrupt Vector Functions
// *****************************************************************************
// *****************************************************************************
//

//void __ISR(_TIMER_1_VECTOR, ipl5AUTO) IntHandlerDrvTmrInstance0(void) {
//    DRV_TMR0_CounterClear();
//    DEV_DAC_Confirm();
//    DRV_TMR0_CounterValueSet(0xFFFF - DAC_UPDATE_PERIOD_COUNTS + DRV_TMR0_CounterValueGet());
//    PLIB_INT_SourceFlagClear(INT_ID_0, INT_SOURCE_TIMER_1);
//}


/* *****************************************************************************
 End of File
 */
