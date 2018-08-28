/* ************************************************************************** */

/* ************************************************************************** */

#ifndef _DEV_GALVO_ADC_H    /* Guard against multiple inclusion */
#define _DEV_GALVO_ADC_H


/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

#include  "system_config/default/system_definitions.h"
#include "system_config/default/framework/driver/spi/static/drv_spi_static.h"

/* Provide C++ Compatibility */
#ifdef __cplusplus
extern "C" {
#endif


    /* ************************************************************************** */
    /* ************************************************************************** */
    /* Section: Constants                                                         */
    /* ************************************************************************** */
    /* ************************************************************************** */

#define SPI_RX_BUFF_SIZE 3
#define ADC_NUMBER_OF_SAMPLES 8
#define ADC_CONVERSION_PERIOD_COUNTS 8
#define ADC_HOLDOFF_PERIOD_COUNTS 2048

#define ADC0_OFFSET 0x1FFF7
#define ADC0_START_PINOn() SYS_PORTS_PinSet(PORTS_ID_0, PORT_CHANNEL_K, PORTS_BIT_POS_1)
#define ADC0_START_PINOff() SYS_PORTS_PinClear(PORTS_ID_0, PORT_CHANNEL_K, PORTS_BIT_POS_1)

#define ADC1_OFFSET 0x1FFF7
#define ADC1_START_PINOn() SYS_PORTS_PinSet(PORTS_ID_0, PORT_CHANNEL_H, PORTS_BIT_POS_12)
#define ADC1_START_PINOff() SYS_PORTS_PinClear(PORTS_ID_0, PORT_CHANNEL_H, PORTS_BIT_POS_12)    

#define DEV_ADC0_INDEX DRV_SPI_INDEX_0
#define DEV_ADC1_INDEX DRV_SPI_INDEX_1

    // *****************************************************************************
    // *****************************************************************************
    // Section: Data Types
    // *****************************************************************************
    // *****************************************************************************
    typedef uintptr_t DEV_HANDLE;

    typedef enum {
        ADC_STATE_INIT = 0,
        ADC_STATE_IDLE = 1,
        ADC_STATE_CONVERSION_START = 2,
        ADC_STATE_READ_PENDING = 3,        
        ADC_STATE_DATA_PENDING = 4,
        ADC_STATE_DATA_READY = 5,
        ADC_STATE_READ_DATA = 6

    } DEV_ADC_STATES;

    typedef struct {
        DEV_ADC_STATES state;
        DRV_SPI_BUFFER_EVENT volatile bufferStatus;
        //bool enabled;
        bool connected;
        DRV_SPI_BUFFER_HANDLE bufferHandle;
        DRV_SPI_CLIENT_DATA spiClientData;
        DRV_HANDLE spiHandle;
        DEV_HANDLE adcHandle;
    } DEV_ADC_OBJ;

    // *****************************************************************************
    // *****************************************************************************
    // Section: Local Functions
    // *****************************************************************************
    // *****************************************************************************

    // *****************************************************************************
    // *****************************************************************************
    // Section: Interface Functions
    // *****************************************************************************
    // *****************************************************************************

    void DEV_ADC_Initialize(const SYS_MODULE_INDEX index);
    DEV_HANDLE DEV_ADC_Open(const SYS_MODULE_INDEX index);

    DEV_HANDLE DEV_ADC_Connect(const SYS_MODULE_INDEX index);
    void DEV_ADC_Disconnect(const SYS_MODULE_INDEX index);

    void DEV_ADC_Read_Begin(const SYS_MODULE_INDEX index);

    // *****************************************************************************
    // *****************************************************************************
    // Section: CallBack Functions
    // *****************************************************************************
    // *****************************************************************************
    void DEV_ADC_CallBack_Start(DRV_SPI_BUFFER_EVENT eEvent, DRV_SPI_BUFFER_HANDLE bufferHandle, void *context);
    void DEV_ADC_CallBack_End(DRV_SPI_BUFFER_EVENT eEvent, DRV_SPI_BUFFER_HANDLE bufferHandle, void *context);
    
    void DEV_ADC0_TMR1_CallBack(void);
    void DEV_ADC1_TMR2_CallBack();
    /* Provide C++ Compatibility */
#ifdef __cplusplus
}
#endif

#endif /* _EXAMPLE_FILE_NAME_H */

/* *****************************************************************************
 End of File
 */
