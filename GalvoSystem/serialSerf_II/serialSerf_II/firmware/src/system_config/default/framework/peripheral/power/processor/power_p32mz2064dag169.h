/* Created by plibgen $Revision: 1.31 $ */

#ifndef _POWER_P32MZ2064DAG169_H
#define _POWER_P32MZ2064DAG169_H

/* Section 1 - Enumerate instances, define constants, VREGs */

#include <xc.h>
#include <stdbool.h>

#include "peripheral/peripheral_common_32bit.h"

/* Default definition used for all API dispatch functions */
#ifndef PLIB_INLINE_API
    #define PLIB_INLINE_API extern inline
#endif

/* Default definition used for all other functions */
#ifndef PLIB_INLINE
    #define PLIB_INLINE extern inline
#endif

typedef enum {

    POWER_ID_0 = 0,
    POWER_NUMBER_OF_MODULES = 1

} POWER_MODULE_ID;

typedef enum {

    POWER_MODULE_ADC1 = 0x00,
    POWER_MODULE_CTMU = 0x08,
    POWER_MODULE_CVR = 0x0C,
    POWER_MODULE_HLVD = 0x14,
    POWER_MODULE_HVD1V8 = 0x1C,
    POWER_MODULE_CMP1 = 0x20,
    POWER_MODULE_CMP2 = 0x21,
    POWER_MODULE_IC1 = 0x40,
    POWER_MODULE_IC2 = 0x41,
    POWER_MODULE_IC3 = 0x42,
    POWER_MODULE_IC4 = 0x43,
    POWER_MODULE_IC5 = 0x44,
    POWER_MODULE_IC6 = 0x45,
    POWER_MODULE_IC7 = 0x46,
    POWER_MODULE_IC8 = 0x47,
    POWER_MODULE_IC9 = 0x48,
    POWER_MODULE_OC1 = 0x50,
    POWER_MODULE_OC2 = 0x51,
    POWER_MODULE_OC3 = 0x52,
    POWER_MODULE_OC4 = 0x53,
    POWER_MODULE_OC5 = 0x54,
    POWER_MODULE_OC6 = 0x55,
    POWER_MODULE_OC7 = 0x56,
    POWER_MODULE_OC8 = 0x57,
    POWER_MODULE_OC9 = 0x58,
    POWER_MODULE_TMR1 = 0x60,
    POWER_MODULE_TMR2 = 0x61,
    POWER_MODULE_TMR3 = 0x62,
    POWER_MODULE_TMR4 = 0x63,
    POWER_MODULE_TMR5 = 0x64,
    POWER_MODULE_TMR6 = 0x65,
    POWER_MODULE_TMR7 = 0x66,
    POWER_MODULE_TMR8 = 0x67,
    POWER_MODULE_TMR9 = 0x68,
    POWER_MODULE_UART1 = 0x80,
    POWER_MODULE_UART2 = 0x81,
    POWER_MODULE_UART3 = 0x82,
    POWER_MODULE_UART4 = 0x83,
    POWER_MODULE_UART5 = 0x84,
    POWER_MODULE_UART6 = 0x85,
    POWER_MODULE_SPI1 = 0x88,
    POWER_MODULE_SPI2 = 0x89,
    POWER_MODULE_SPI3 = 0x8A,
    POWER_MODULE_SPI4 = 0x8B,
    POWER_MODULE_SPI5 = 0x8C,
    POWER_MODULE_SPI6 = 0x8D,
    POWER_MODULE_I2C1 = 0x90,
    POWER_MODULE_I2C2 = 0x91,
    POWER_MODULE_I2C3 = 0x92,
    POWER_MODULE_I2C4 = 0x93,
    POWER_MODULE_I2C5 = 0x94,
    POWER_MODULE_USB = 0x98,
    POWER_MODULE_CAN1 = 0x9C,
    POWER_MODULE_CAN2 = 0x9D,
    POWER_MODULE_REF_CLK_OUTPUT1 = 0xA8,
    POWER_MODULE_REF_CLK_OUTPUT2 = 0xA9,
    POWER_MODULE_REF_CLK_OUTPUT3 = 0xAA,
    POWER_MODULE_REF_CLK_OUTPUT4 = 0xAB,
    POWER_MODULE_REF_CLK_OUTPUT5 = 0xAC,
    POWER_MODULE_PMP = 0xB0,
    POWER_MODULE_EBI = 0xB1,
    POWER_MODULE_GPU = 0xB2,
    POWER_MODULE_GLCD = 0xB4,
    POWER_MODULE_SDHC = 0xB5,
    POWER_MODULE_SQI1 = 0xB6,
    POWER_MODULE_ETHERNET = 0xBB,
    POWER_MODULE_DMA = 0xC4,
    POWER_MODULE_RANDOM_NUM_GENERATOR = 0xD4,
    POWER_MODULE_DDR2 = 0xDC

} POWER_MODULE;

typedef enum {

    HLVD_LIMIT_TRIP_POINT_4 = 0x00000100,
    HLVD_LIMIT_TRIP_POINT_5 = 0x00000101,
    HLVD_LIMIT_TRIP_POINT_6 = 0x00000110,
    HLVD_LIMIT_TRIP_POINT_7 = 0x00000111,
    HLVD_LIMIT_TRIP_POINT_8 = 0x00001000,
    HLVD_LIMIT_TRIP_POINT_9 = 0x00001001,
    HLVD_LIMIT_TRIP_POINT_10 = 0x00001010,
    HLVD_LIMIT_TRIP_POINT_11 = 0x00001011,
    HLVD_LIMIT_TRIP_POINT_12 = 0x00001100,
    HLVD_LIMIT_TRIP_POINT_13 = 0x00001101,
    HLVD_LIMIT_TRIP_POINT_14 = 0x00001110,
    HLVD_LIMIT_ANALOG_INPUT_ON_HLVDIN = 0x00001111

} HLVD_LIMIT;

typedef enum {

    HLVD_MODE_LOW_VOLTAGE_DETECTION = 0,
    HLVD_MODE_HIGH_VOLTAGE_DETECTION = 1

} HLVD_MODE;

typedef enum {

    DEEP_SLEEP_MODULE_RTCC = 0x00001000

} DEEP_SLEEP_MODULE;

typedef enum {

    DEEP_SLEEP_WAKE_UP_EVENT_RTCC = 0x00000100,
    DEEP_SLEEP_WAKE_UP_EVENT_EXTERNAL_INTERRUPT = 0x00000004

} DEEP_SLEEP_WAKE_UP_EVENT;

typedef enum {

    DEEP_SLEEP_EVENT_BOR = 0x00000002,
    DEEP_SLEEP_EVENT_RTCC_ALARM = 0x00000008,
    DEEP_SLEEP_EVENT_EXTERNAL_INTERRUPT = 0x00000100,
    DEEP_SLEEP_EVENT_FAULT_DETECTION = 0x00000080,
    DEEP_SLEEP_EVENT_WDT_TIMEOUT = 0x00000010,
    DEEP_SLEEP_EVENT_MCLR = 0x00000004

} DEEP_SLEEP_EVENT;

typedef enum {

    DEEP_SLEEP_GPR_0 = 0x00,
    DEEP_SLEEP_GPR_1 = 0x01,
    DEEP_SLEEP_GPR_2 = 0x02,
    DEEP_SLEEP_GPR_3 = 0x03,
    DEEP_SLEEP_GPR_4 = 0x04,
    DEEP_SLEEP_GPR_5 = 0x05,
    DEEP_SLEEP_GPR_6 = 0x06,
    DEEP_SLEEP_GPR_7 = 0x07,
    DEEP_SLEEP_GPR_8 = 0x08,
    DEEP_SLEEP_GPR_9 = 0x09,
    DEEP_SLEEP_GPR_10 = 0x0A,
    DEEP_SLEEP_GPR_11 = 0x0B,
    DEEP_SLEEP_GPR_12 = 0x0C,
    DEEP_SLEEP_GPR_13 = 0x0D,
    DEEP_SLEEP_GPR_14 = 0x0E,
    DEEP_SLEEP_GPR_15 = 0x0F,
    DEEP_SLEEP_GPR_16 = 0x10,
    DEEP_SLEEP_GPR_17 = 0x11,
    DEEP_SLEEP_GPR_18 = 0x12,
    DEEP_SLEEP_GPR_19 = 0x13,
    DEEP_SLEEP_GPR_20 = 0x14,
    DEEP_SLEEP_GPR_21 = 0x15,
    DEEP_SLEEP_GPR_22 = 0x16,
    DEEP_SLEEP_GPR_23 = 0x17,
    DEEP_SLEEP_GPR_24 = 0x18,
    DEEP_SLEEP_GPR_25 = 0x19,
    DEEP_SLEEP_GPR_26 = 0x1A,
    DEEP_SLEEP_GPR_27 = 0x1B,
    DEEP_SLEEP_GPR_28 = 0x1C,
    DEEP_SLEEP_GPR_29 = 0x1D,
    DEEP_SLEEP_GPR_30 = 0x1E,
    DEEP_SLEEP_GPR_31 = 0x1F,
    DEEP_SLEEP_GPR_32 = 0x20

} DEEP_SLEEP_GPR;

/* Section 2 - Feature variant inclusion */

#define PLIB_TEMPLATE PLIB_INLINE
#include "../templates/power_PeripheralModuleControl_PIC32_2.h"
#include "../templates/power_VoltageRegulatorControl_Default_1.h"
#include "../templates/power_SleepStatus_Default.h"
#include "../templates/power_IdleStatus_Default.h"
#include "../templates/power_HighVoltageOnVDD1V8_Default.h"
#include "../templates/power_DeepSleepModeOccurrence_Default.h"
#include "../templates/power_HLVDEnableControl_Default.h"
#include "../templates/power_HLVDStopInIdleControl_Default.h"
#include "../templates/power_HLVDStatus_Default.h"
#include "../templates/power_HLVDModeControl_Default.h"
#include "../templates/power_HLVDBandGapVoltageStability_Default.h"
#include "../templates/power_HLVDLimitSelection_Default.h"
#include "../templates/power_DeepSleepModeControl_Default.h"
#include "../templates/power_DeepSleepGPRsRetentionControl_Default.h"
#include "../templates/power_DeepSleepModuleControl_Default.h"
#include "../templates/power_DeepSleepWakeupEventControl_Default.h"
#include "../templates/power_DeepSleepPortPinsStateControl_Default.h"
#include "../templates/power_DeepSleepEventStatus_Default.h"
#include "../templates/power_DeepSleepGPROperation_Default.h"

/* Section 3 - PLIB dispatch function definitions */

PLIB_INLINE_API bool PLIB_POWER_ExistsPeripheralModuleControl(POWER_MODULE_ID index)
{
     return POWER_ExistsPeripheralModuleControl_PIC32_2(index);
}

PLIB_INLINE_API void PLIB_POWER_PeripheralModuleDisable(POWER_MODULE_ID index, POWER_MODULE source)
{
     POWER_PeripheralModuleDisable_PIC32_2(index, source);
}

PLIB_INLINE_API void PLIB_POWER_PeripheralModuleEnable(POWER_MODULE_ID index, POWER_MODULE source)
{
     POWER_PeripheralModuleEnable_PIC32_2(index, source);
}

PLIB_INLINE_API bool PLIB_POWER_PeripheralModuleIsEnabled(POWER_MODULE_ID index, POWER_MODULE source)
{
     return POWER_PeripheralModuleIsEnabled_PIC32_2(index, source);
}

PLIB_INLINE_API bool PLIB_POWER_ExistsVoltageRegulatorControl(POWER_MODULE_ID index)
{
     return POWER_ExistsVoltageRegulatorControl_Default_1(index);
}

PLIB_INLINE_API void PLIB_POWER_VoltageRegulatorEnable(POWER_MODULE_ID index)
{
     POWER_VoltageRegulatorEnable_Default_1(index);
}

PLIB_INLINE_API void PLIB_POWER_VoltageRegulatorDisable(POWER_MODULE_ID index)
{
     POWER_VoltageRegulatorDisable_Default_1(index);
}

PLIB_INLINE_API bool PLIB_POWER_VoltageRegulatorIsEnabled(POWER_MODULE_ID index)
{
     return POWER_VoltageRegulatorIsEnabled_Default_1(index);
}

PLIB_INLINE_API bool PLIB_POWER_ExistsSleepStatus(POWER_MODULE_ID index)
{
     return POWER_ExistsSleepStatus_Default(index);
}

PLIB_INLINE_API bool PLIB_POWER_DeviceWasInSleepMode(POWER_MODULE_ID index)
{
     return POWER_DeviceWasInSleepMode_Default(index);
}

PLIB_INLINE_API void PLIB_POWER_ClearSleepStatus(POWER_MODULE_ID index)
{
     POWER_ClearSleepStatus_Default(index);
}

PLIB_INLINE_API bool PLIB_POWER_ExistsIdleStatus(POWER_MODULE_ID index)
{
     return POWER_ExistsIdleStatus_Default(index);
}

PLIB_INLINE_API bool PLIB_POWER_DeviceWasInIdleMode(POWER_MODULE_ID index)
{
     return POWER_DeviceWasInIdleMode_Default(index);
}

PLIB_INLINE_API void PLIB_POWER_ClearIdleStatus(POWER_MODULE_ID index)
{
     POWER_ClearIdleStatus_Default(index);
}

PLIB_INLINE_API bool PLIB_POWER_ExistsHighVoltageOnVDD1V8(POWER_MODULE_ID index)
{
     return POWER_ExistsHighVoltageOnVDD1V8_Default(index);
}

PLIB_INLINE_API bool PLIB_POWER_HighVoltageOnVDD1V8HasOccurred(POWER_MODULE_ID index)
{
     return POWER_HighVoltageOnVDD1V8HasOccurred_Default(index);
}

PLIB_INLINE_API bool PLIB_POWER_ExistsDeepSleepModeOccurrence(POWER_MODULE_ID index)
{
     return POWER_ExistsDeepSleepModeOccurrence_Default(index);
}

PLIB_INLINE_API bool PLIB_POWER_DeepSleepModeHasOccurred(POWER_MODULE_ID index)
{
     return POWER_DeepSleepModeHasOccurred_Default(index);
}

PLIB_INLINE_API void PLIB_POWER_DeepSleepStatusClear(POWER_MODULE_ID index)
{
     POWER_DeepSleepStatusClear_Default(index);
}

PLIB_INLINE_API bool PLIB_POWER_ExistsHLVDEnableControl(POWER_MODULE_ID index)
{
     return POWER_ExistsHLVDEnableControl_Default(index);
}

PLIB_INLINE_API void PLIB_POWER_HLVDEnable(POWER_MODULE_ID index)
{
     POWER_HLVDEnable_Default(index);
}

PLIB_INLINE_API void PLIB_POWER_HLVDDisable(POWER_MODULE_ID index)
{
     POWER_HLVDDisable_Default(index);
}

PLIB_INLINE_API bool PLIB_POWER_HLVDIsEnabled(POWER_MODULE_ID index)
{
     return POWER_HLVDIsEnabled_Default(index);
}

PLIB_INLINE_API bool PLIB_POWER_ExistsHLVDStopInIdleControl(POWER_MODULE_ID index)
{
     return POWER_ExistsHLVDStopInIdleControl_Default(index);
}

PLIB_INLINE_API void PLIB_POWER_HLVDStopInIdleEnable(POWER_MODULE_ID index)
{
     POWER_HLVDStopInIdleEnable_Default(index);
}

PLIB_INLINE_API void PLIB_POWER_HLVDStopInIdleDisable(POWER_MODULE_ID index)
{
     POWER_HLVDStopInIdleDisable_Default(index);
}

PLIB_INLINE_API bool PLIB_POWER_HLVDStopInIdleIsEnabled(POWER_MODULE_ID index)
{
     return POWER_HLVDStopInIdleIsEnabled_Default(index);
}

PLIB_INLINE_API bool PLIB_POWER_ExistsHLVDStatus(POWER_MODULE_ID index)
{
     return POWER_ExistsHLVDStatus_Default(index);
}

PLIB_INLINE_API bool PLIB_POWER_HLVDStatusGet(POWER_MODULE_ID index)
{
     return POWER_HLVDStatusGet_Default(index);
}

PLIB_INLINE_API bool PLIB_POWER_ExistsHLVDModeControl(POWER_MODULE_ID index)
{
     return POWER_ExistsHLVDModeControl_Default(index);
}

PLIB_INLINE_API void PLIB_POWER_HLVDModeSelect(POWER_MODULE_ID index, HLVD_MODE mode)
{
     POWER_HLVDModeSelect_Default(index, mode);
}

PLIB_INLINE_API bool PLIB_POWER_ExistsHLVDBandGapVoltageStability(POWER_MODULE_ID index)
{
     return POWER_ExistsHLVDBandGapVoltageStability_Default(index);
}

PLIB_INLINE_API bool PLIB_POWER_HLVDBandGapVoltageIsStable(POWER_MODULE_ID index)
{
     return POWER_HLVDBandGapVoltageIsStable_Default(index);
}

PLIB_INLINE_API bool PLIB_POWER_ExistsHLVDLimitSelection(POWER_MODULE_ID index)
{
     return POWER_ExistsHLVDLimitSelection_Default(index);
}

PLIB_INLINE_API void PLIB_POWER_HLVDLimitSelect(POWER_MODULE_ID index, HLVD_LIMIT limit)
{
     POWER_HLVDLimitSelect_Default(index, limit);
}

PLIB_INLINE_API bool PLIB_POWER_ExistsDeepSleepMode(POWER_MODULE_ID index)
{
     return POWER_ExistsDeepSleepMode_Default(index);
}

PLIB_INLINE_API void PLIB_POWER_DeepSleepModeEnable(POWER_MODULE_ID index)
{
     POWER_DeepSleepModeEnable_Default(index);
}

PLIB_INLINE_API void PLIB_POWER_DeepSleepModeDisable(POWER_MODULE_ID index)
{
     POWER_DeepSleepModeDisable_Default(index);
}

PLIB_INLINE_API bool PLIB_POWER_DeepSleepModeIsEnabled(POWER_MODULE_ID index)
{
     return POWER_DeepSleepModeIsEnabled_Default(index);
}

PLIB_INLINE_API bool PLIB_POWER_ExistsDeepSleepGPRsRetentionControl(POWER_MODULE_ID index)
{
     return POWER_ExistsDeepSleepGPRsRetentionControl_Default(index);
}

PLIB_INLINE_API void PLIB_POWER_DeepSleepGPRsRetentionEnable(POWER_MODULE_ID index)
{
     POWER_DeepSleepGPRsRetentionEnable_Default(index);
}

PLIB_INLINE_API void PLIB_POWER_DeepSleepGPRsRetentionDisable(POWER_MODULE_ID index)
{
     POWER_DeepSleepGPRsRetentionDisable_Default(index);
}

PLIB_INLINE_API bool PLIB_POWER_ExistsDeepSleepModuleControl(POWER_MODULE_ID index)
{
     return POWER_ExistsDeepSleepModuleControl_Default(index);
}

PLIB_INLINE_API void PLIB_POWER_DeepSleepModuleEnable(POWER_MODULE_ID index, DEEP_SLEEP_MODULE module)
{
     POWER_DeepSleepModuleEnable_Default(index, module);
}

PLIB_INLINE_API void PLIB_POWER_DeepSleepModuleDisable(POWER_MODULE_ID index, DEEP_SLEEP_MODULE module)
{
     POWER_DeepSleepModuleDisable_Default(index, module);
}

PLIB_INLINE_API bool PLIB_POWER_ExistsDeepSleepWakeupEventControl(POWER_MODULE_ID index)
{
     return POWER_ExistsDeepSleepWakeupEventControl_Default(index);
}

PLIB_INLINE_API void PLIB_POWER_DeepSleepWakeupEventEnable(POWER_MODULE_ID index, DEEP_SLEEP_WAKE_UP_EVENT event)
{
     POWER_DeepSleepWakeupEventEnable_Default(index, event);
}

PLIB_INLINE_API void PLIB_POWER_DeepSleepWakeupEventDisable(POWER_MODULE_ID index, DEEP_SLEEP_WAKE_UP_EVENT event)
{
     POWER_DeepSleepWakeupEventDisable_Default(index, event);
}

PLIB_INLINE_API bool PLIB_POWER_ExistsDeepSleepPortPinsStateControl(POWER_MODULE_ID index)
{
     return POWER_ExistsDeepSleepPortPinsStateControl_Default(index);
}

PLIB_INLINE_API void PLIB_POWER_DeepSleepPortPinsStateRetain(POWER_MODULE_ID index)
{
     POWER_DeepSleepPortPinsStateRetain_Default(index);
}

PLIB_INLINE_API void PLIB_POWER_DeepSleepPortPinsStateRelease(POWER_MODULE_ID index)
{
     POWER_DeepSleepPortPinsStateRelease_Default(index);
}

PLIB_INLINE_API bool PLIB_POWER_ExistsDeepSleepEventStatus(POWER_MODULE_ID index)
{
     return POWER_ExistsDeepSleepEventStatus_Default(index);
}

PLIB_INLINE_API DEEP_SLEEP_EVENT PLIB_POWER_DeepSleepEventStatusGet(POWER_MODULE_ID index)
{
     return POWER_DeepSleepEventStatusGet_Default(index);
}

PLIB_INLINE_API void PLIB_POWER_DeepSleepEventStatusClear(POWER_MODULE_ID index, DEEP_SLEEP_EVENT event)
{
     POWER_DeepSleepEventStatusClear_Default(index, event);
}

PLIB_INLINE_API bool PLIB_POWER_ExistsDeepSleepGPROperation(POWER_MODULE_ID index)
{
     return POWER_ExistsDeepSleepGPROperation_Default(index);
}

PLIB_INLINE_API void PLIB_POWER_DeepSleepGPRWrite(POWER_MODULE_ID index, DEEP_SLEEP_GPR gpr, uint32_t data)
{
     POWER_DeepSleepGPRWrite_Default(index, gpr, data);
}

PLIB_INLINE_API uint32_t PLIB_POWER_DeepSleepGPRRead(POWER_MODULE_ID index, DEEP_SLEEP_GPR gpr)
{
     return POWER_DeepSleepGPRRead_Default(index, gpr);
}

#endif
