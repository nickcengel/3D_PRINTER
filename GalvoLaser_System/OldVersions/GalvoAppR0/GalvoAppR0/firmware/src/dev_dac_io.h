/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Company Name

  @File Name
    filename.h

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

#ifndef _DEV_GALVO_DAC_H    /* Guard against multiple inclusion */
#define _DEV_GALVO_DAC_H


/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */


#include "system_config/default/framework/driver/spi/static/drv_spi_static.h"
#include  "system_config/default/system_definitions.h"

/* Provide C++ Compatibility */
#ifdef __cplusplus
extern "C" {
#endif


    /* ************************************************************************** */
    /* ************************************************************************** */
    /* Section: Constants                                                         */
    /* ************************************************************************** */
    /* ************************************************************************** */

#define SPI_TX_BUFF_SIZE 3

#define DAC_DIN_REG_WRITE 0x1
#define DAC_OFFSET_REG_WRITE 0x2    
#define DAC_GAIN_REG_WRITE 0x3
#define DAC_CONFIG_REG_WRITE 0x4    
#define DAC_DIN_REG_READ 0x9
#define DAC_OFFSET_REG_READ 0xA    
#define DAC_GAIN_REG_READ 0xB
#define DAC_CONFIG_REG_READ 0xC

#define DEV_DAC0_INDEX DRV_SPI_INDEX_0
#define DEV_DAC1_INDEX DRV_SPI_INDEX_1

#define DEV_GALVO_INDEX 2

#define DAC0_OFFSET  0x201EA // added to incoming signed number
#define DAC1_OFFSET  0x201EA // added to incoming signed number    

#define DAC_MIN_VALUE 0x0
#define DAC_MAX_VALUE 0x3FFFF
#define DEV_DAC0_DESELECT() SYS_PORTS_PinSet(PORTS_ID_0, PORT_CHANNEL_B, PORTS_BIT_POS_2)
#define DEV_DAC0_SELECT() SYS_PORTS_PinClear(PORTS_ID_0, PORT_CHANNEL_B, PORTS_BIT_POS_2)

#define DEV_DAC0_LATCH() SYS_PORTS_PinClear(PORTS_ID_0, PORT_CHANNEL_K, PORTS_BIT_POS_2)
#define DEV_DAC0_UNLATCH() SYS_PORTS_PinSet(PORTS_ID_0, PORT_CHANNEL_K, PORTS_BIT_POS_2)

#define DEV_DAC1_DESELECT() SYS_PORTS_PinSet(PORTS_ID_0, PORT_CHANNEL_D, PORTS_BIT_POS_14)
#define DEV_DAC1_SELECT() SYS_PORTS_PinClear(PORTS_ID_0, PORT_CHANNEL_D, PORTS_BIT_POS_14)

#define DEV_DAC1_LATCH() SYS_PORTS_PinSet(PORTS_ID_0, PORT_CHANNEL_J, PORTS_BIT_POS_2)
#define DEV_DAC1_UNLATCH()SYS_PORTS_PinClear(PORTS_ID_0, PORT_CHANNEL_J, PORTS_BIT_POS_2)

    // *****************************************************************************
    // *****************************************************************************
    // Section: Data Types
    // *****************************************************************************
    // *****************************************************************************

    typedef uintptr_t DEV_HANDLE;

    typedef SYS_MODULE_OBJ(* SYS_MODULE_INITIALIZE_ROUTINE) (
            const SYS_MODULE_INDEX index,
            const SYS_MODULE_INIT * const init);

    typedef enum {
        DAC_STATE_INIT = 0,
        DAC_STATE_IDLE = 1,
        DAC_STATE_JOB_PENDING = 2,
        DAC_STATE_WRITE_STARTED = 3,
        DAC_STATE_WRITE_COMPLETE = 4,
        DAC_STATE_LATCHED = 5,
        DAC_STATE_BUSY = 6
    } DEV_DAC_STATES;

    typedef struct {
        DEV_DAC_STATES volatile state;
        DRV_SPI_BUFFER_EVENT volatile bufferStatus;
        //bool enabled;
        bool connected;

        DRV_SPI_BUFFER_HANDLE bufferHandle;
        DRV_SPI_CLIENT_DATA spiClientData;
        DRV_HANDLE spiHandle;
        DEV_HANDLE DacHandle;
    } DEV_DAC_OBJ;


    /* ************************************************************************** */
    /* ************************************************************************** */
    // Section: Local Functions                                                   */
    /* ************************************************************************** */
    /* ************************************************************************** */

    void DEV_DAC0_Write(uint32_t value);
    void DEV_DAC1_Write(uint32_t value);
    


    // *****************************************************************************
    // *****************************************************************************
    // Section: Interface Functions
    // *****************************************************************************
    // *****************************************************************************

    void DEV_DAC_Initialize(const SYS_MODULE_INDEX index);
    DEV_HANDLE DEV_DAC_Open(const SYS_MODULE_INDEX index);
    DEV_HANDLE DEV_DAC_Connect(const SYS_MODULE_INDEX index);
    void DEV_DAC_Disconnect(const SYS_MODULE_INDEX index);
    
    bool DEV_DAC_Available(void);
    void DEV_DAC_Write(const SYS_MODULE_INDEX index, const uint32_t value);

    // *****************************************************************************
    // *****************************************************************************
    // Section: CallBack Functions
    // *****************************************************************************
    // *****************************************************************************

    void DEV_DAC_CallBack_Start(DRV_SPI_BUFFER_EVENT eEvent, DRV_SPI_BUFFER_HANDLE bufferHandle, void *context);
    void DEV_DAC_CallBack_End(DRV_SPI_BUFFER_EVENT eEvent, DRV_SPI_BUFFER_HANDLE bufferHandle, void *context);
    
    void DEV_DAC_Confirm(void);
    /* Provide C++ Compatibility */
#ifdef __cplusplus
}
#endif

#endif /* _EXAMPLE_FILE_NAME_H */

/* *****************************************************************************
 End of File
 */
