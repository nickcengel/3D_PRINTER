/* ************************************************************************** */
/* ************************************************************************** */

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */
#include "dev_adc_io.h"


/* ************************************************************************** */
/* ************************************************************************** */
/* Section: File Scope or Global Data                                         */
/* ************************************************************************** */
/* ************************************************************************** */
DEV_ADC_OBJ gAdcObject[2];
static uint8_t SPI0_RX_Buffer[SPI_RX_BUFF_SIZE];
static uint8_t SPI1_RX_Buffer[SPI_RX_BUFF_SIZE];
/* ************************************************************************** */
/* ************************************************************************** */
// Section: Local Functions                                                   */
/* ************************************************************************** */
/* ************************************************************************** */


/* ************************************************************************** */
/* ************************************************************************** */
// Section: Interface Functions                                               */
/* ************************************************************************** */

/* ************************************************************************** */

DEV_ADC_STATES DEV_ADC_Get_Status(const SYS_MODULE_INDEX index) {
    DEV_ADC_OBJ *pObj = (DEV_ADC_OBJ *) & gAdcObject[index];
    return pObj->state;
}

void DEV_ADC_Initialize(const SYS_MODULE_INDEX index) {
    DEV_ADC_OBJ *pObj = (DEV_ADC_OBJ *) & gAdcObject[index];
    pObj->adcHandle = (DEV_HANDLE) index;
    pObj->spiHandle = DRV_HANDLE_INVALID;
    pObj->connected = false;
    pObj->state = ADC_STATE_INIT;
    pObj->spiClientData.baudRate = 12500000;
    pObj->spiClientData.operationStarting = DEV_ADC_CallBack_Start;
    pObj->spiClientData.operationEnded = DEV_ADC_CallBack_End;
}

DEV_HANDLE DEV_ADC_Open(const SYS_MODULE_INDEX index) {
    DEV_ADC_OBJ *pObj = (DEV_ADC_OBJ *) & gAdcObject[index];
    switch (index) {
        case DEV_ADC0_INDEX:
        {
            if (pObj->spiHandle == DRV_HANDLE_INVALID) {
                pObj->spiHandle = DRV_SPI0_Open(DRV_SPI_INDEX_0,
                        DRV_IO_INTENT_READ | DRV_IO_INTENT_NONBLOCKING);
                pObj->state == ADC_STATE_IDLE;
            }
            break;
        }
        case DEV_ADC1_INDEX:
        {
            if (pObj->spiHandle == DRV_HANDLE_INVALID) {
                pObj->spiHandle = DRV_SPI1_Open(DRV_SPI_INDEX_1,
                        DRV_IO_INTENT_READ | DRV_IO_INTENT_NONBLOCKING);
                pObj->state == ADC_STATE_IDLE;
            }
            break;
        }
        default:
        {
            break;
        }
    }
    if (pObj->spiHandle != DRV_HANDLE_INVALID)
        return (pObj->adcHandle);
    else
        return DEV_HANDLE_INVALID;
}

DEV_HANDLE DEV_ADC_Connect(const SYS_MODULE_INDEX index) {
    DEV_ADC_OBJ *pObj = (DEV_ADC_OBJ *) & gAdcObject[index];
    switch (index) {
        case DEV_ADC0_INDEX:
        {
            DRV_SPI0_ClientConfigure(&(pObj->spiClientData));
            pObj->connected = true;
            pObj->bufferStatus = DRV_SPI_BUFFER_EVENT_COMPLETE;
            break;
        }
        case DEV_ADC1_INDEX:
        {
            DRV_SPI1_ClientConfigure(&(pObj->spiClientData));
            pObj->connected = true;
            pObj->bufferStatus = DRV_SPI_BUFFER_EVENT_COMPLETE;
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

void DEV_ADC_Disconnect(const SYS_MODULE_INDEX index) {
    DEV_ADC_OBJ *pObj = (DEV_ADC_OBJ *) & gAdcObject[index];
    pObj->connected = false;
    pObj->state = ADC_STATE_IDLE;
}

void DEV_ADC_Read_Begin(const SYS_MODULE_INDEX index) {
    DEV_ADC_OBJ *pObj = (DEV_ADC_OBJ *) & gAdcObject[index];
    switch (index) {
        case DEV_ADC0_INDEX:
        {
            if (pObj->state == ADC_STATE_IDLE) {
                pObj->state = ADC_STATE_CONVERSION_START;
                ADC0_START_PINOff();
//                DRV_TMR1_CounterValueSet(0xFFFF - ADC_CONVERSION_PERIOD_COUNTS);
//                DRV_TMR1_Start();
                while (1) {
                    if (pObj->state == ADC_STATE_READ_PENDING) {
                        break;
                    }
                }
            }
            ADC0_START_PINOn();
            memset(SPI0_RX_Buffer, 0, SPI_RX_BUFF_SIZE);
            DRV_SPI0_BufferAddRead(SPI0_RX_Buffer, 3, 0, 0);
            break;
        }
        case DEV_ADC1_INDEX:
        {
            if (pObj->state == ADC_STATE_IDLE) {
                pObj->state = ADC_STATE_CONVERSION_START;
                ADC1_START_PINOff();
//                DRV_TMR2_CounterValueSet(0xFFFF - ADC_CONVERSION_PERIOD_COUNTS);
//                DRV_TMR2_Start();
                while (1) {
                    if (pObj->state == ADC_STATE_READ_PENDING) {
                        break;
                    }
                }
            }
            ADC1_START_PINOn();
            memset(SPI1_RX_Buffer, 0, SPI_RX_BUFF_SIZE);
            DRV_SPI1_BufferAddRead(SPI1_RX_Buffer, 3, 0, 0);
            break;
        }
        default:
            break;
    }
}

uint32_t DEV_ADC_Read_Value(const SYS_MODULE_INDEX index) {
    DEV_ADC_OBJ *pObj = (DEV_ADC_OBJ *) & gAdcObject[index];
    uint32_t tempVal;
    switch (index) {
        case DEV_ADC0_INDEX:
        {
            tempVal = (0x3FC00 & (SPI0_RX_Buffer[0] << 10));
            tempVal |= (0x3FC & (SPI0_RX_Buffer[1] << 2));
            tempVal |= (0x3 & (SPI0_RX_Buffer[2] >> 6));
            tempVal &= 0x3FFFF;
            break;
        }
        case DEV_ADC1_INDEX:
        {
            uint32_t tempVal;
            tempVal = (0x3FC00 & (SPI1_RX_Buffer[0] << 10));
            tempVal |= (0x3FC & (SPI1_RX_Buffer[1] << 2));
            tempVal |= (0x3 & (SPI1_RX_Buffer[2] >> 6));
            tempVal &= 0x3FFFF;
            break;
        }
        default:
            break;
    }
    return tempVal;
}

bool DEV_ADC_Available(void) {
    if ((gAdcObject[DEV_ADC1_INDEX].state == gAdcObject[DEV_ADC0_INDEX].state)
            && ((gAdcObject[DEV_ADC0_INDEX].state == ADC_STATE_IDLE)
            || (gAdcObject[DEV_ADC0_INDEX].state == ADC_STATE_DATA_READY)))
        return true;
    else
        return false;
}

DEV_ADC_Tasks(const SYS_MODULE_INDEX index, uint32_t *value) {
    DEV_ADC_OBJ *pObj = (DEV_ADC_OBJ *) & gAdcObject[index];
    if (pObj->bufferStatus == DRV_SPI_BUFFER_EVENT_COMPLETE) {
        switch (pObj->state) {
            case ADC_STATE_IDLE:
            {
                DEV_ADC_Read_Begin(index);
                break;
            }
            case ADC_STATE_DATA_READY:
            {
                *value = DEV_ADC_Read_Value(index);
            }
        }
    }
}


// *****************************************************************************
// *****************************************************************************
// Section: CallBack Functions
// *****************************************************************************
// *****************************************************************************

void DEV_ADC_CallBack_Start(DRV_SPI_BUFFER_EVENT eEvent, DRV_SPI_BUFFER_HANDLE bufferHandle, void *context) {
    DEV_ADC_OBJ *pObj = (DEV_ADC_OBJ *) context;
    pObj->bufferStatus = eEvent;
    pObj->state = ADC_STATE_DATA_PENDING;
}

void DEV_ADC_CallBack_End(DRV_SPI_BUFFER_EVENT eEvent, DRV_SPI_BUFFER_HANDLE bufferHandle, void *context) {
    DEV_ADC_OBJ *pObj = (DEV_ADC_OBJ *) context;
    pObj->bufferStatus = eEvent;
    pObj->state = ADC_STATE_DATA_READY;
}

void DEV_ADC0_TMR1_CallBack(void) {
    DEV_ADC_OBJ *pObj = (DEV_ADC_OBJ *) & gAdcObject[DEV_ADC0_INDEX];
    if (pObj->state == ADC_STATE_CONVERSION_START)
        pObj->state = ADC_STATE_READ_PENDING;
}

void DEV_ADC1_TMR2_CallBack(void) {
    DEV_ADC_OBJ *pObj = (DEV_ADC_OBJ *) & gAdcObject[DEV_ADC1_INDEX];
    if (pObj->state == ADC_STATE_CONVERSION_START)
        pObj->state = ADC_STATE_READ_PENDING;
}

//void __ISR(_TIMER_2_VECTOR, ipl3AUTO) IntHandlerDrvTmrInstance1(void) {
//    DRV_TMR1_Stop();
//
//    DEV_ADC0_TMR1_CallBack();
//
//    PLIB_INT_SourceFlagClear(INT_ID_0, INT_SOURCE_TIMER_2);
//}
////
//
//void __ISR(_TIMER_4_VECTOR, ipl3AUTO) IntHandlerDrvTmrInstance2(void) {
//    DRV_TMR2_Stop();
//
//    DEV_ADC1_TMR2_CallBack;
//
//    PLIB_INT_SourceFlagClear(INT_ID_0, INT_SOURCE_TIMER_4);
//}
//

/* *****************************************************************************
 End of File
 */
