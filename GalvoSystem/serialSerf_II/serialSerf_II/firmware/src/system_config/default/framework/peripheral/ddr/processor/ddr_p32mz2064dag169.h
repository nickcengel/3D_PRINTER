/* Created by plibgen $Revision: 1.31 $ */

#ifndef _DDR_P32MZ2064DAG169_H
#define _DDR_P32MZ2064DAG169_H

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

    DDR_ID_0 = 0,
    DDR_NUMBER_OF_MODULES = 1

} DDR_MODULE_ID;

typedef enum {

    DDR_TARGET_0 = 0x00,
    DDR_TARGET_1 = 0x01,
    DDR_TARGET_2 = 0x02,
    DDR_TARGET_3 = 0x03,
    DDR_TARGET_4 = 0x04

} DDR_TARGET;

typedef enum {

    DDR_PHY_ODT_75_OHM = 0x00,
    DDR_PHY_ODT_150_OHM = 0x01

} DDR_PHY_ODT;

typedef enum {

    DDR_PHY_DRIVE_STRENGTH_60 = 0x00,
    DDR_PHY_DRIVE_STRENGTH_FULL = 0x01

} DDR_PHY_DRIVE_STRENGTH;

typedef enum {

    DDR_PHY_PREAMBLE_DLY_2_0 = 0x00,
    DDR_PHY_PREAMBLE_DLY_1_5 = 0x01,
    DDR_PHY_PREAMBLE_DLY_1_0 = 0x02

} DDR_PHY_PREAMBLE_DLY;

typedef enum {

    DDR_PHY_SCL_BURST_MODE_4 = 0x00,
    DDR_PHY_SCL_BURST_MODE_8 = 0x01

} DDR_PHY_SCL_BURST_MODE;

typedef enum {

    DDR_PHY_DDR_TYPE_DDR2 = 0x00,
    DDR_PHY_DDR_TYPE_DDR3 = 0x01

} DDR_PHY_DDR_TYPE;

typedef enum {

    DDR_PHY_SCL_DELAY_SINGLE = 0x00,
    DDR_PHY_SCL_DELAY_DOUBLE = 0x01

} DDR_PHY_SCL_DELAY;

typedef enum {

    DDR_HOST_CMD_REG_10 = 0x00,
    DDR_HOST_CMD_REG_11 = 0x01,
    DDR_HOST_CMD_REG_12 = 0x02,
    DDR_HOST_CMD_REG_13 = 0x03,
    DDR_HOST_CMD_REG_14 = 0x04,
    DDR_HOST_CMD_REG_15 = 0x05,
    DDR_HOST_CMD_REG_16 = 0x06,
    DDR_HOST_CMD_REG_17 = 0x07,
    DDR_HOST_CMD_REG_18 = 0x08,
    DDR_HOST_CMD_REG_19 = 0x09,
    DDR_HOST_CMD_REG_110 = 0x0A,
    DDR_HOST_CMD_REG_111 = 0x0B,
    DDR_HOST_CMD_REG_112 = 0x0C,
    DDR_HOST_CMD_REG_113 = 0x0D,
    DDR_HOST_CMD_REG_114 = 0x0E,
    DDR_HOST_CMD_REG_115 = 0x0F,
    DDR_HOST_CMD_REG_20 = 0x10,
    DDR_HOST_CMD_REG_21 = 0x11,
    DDR_HOST_CMD_REG_22 = 0x12,
    DDR_HOST_CMD_REG_23 = 0x13,
    DDR_HOST_CMD_REG_24 = 0x14,
    DDR_HOST_CMD_REG_25 = 0x15,
    DDR_HOST_CMD_REG_26 = 0x16,
    DDR_HOST_CMD_REG_27 = 0x17,
    DDR_HOST_CMD_REG_28 = 0x18,
    DDR_HOST_CMD_REG_29 = 0x19,
    DDR_HOST_CMD_REG_210 = 0x1A,
    DDR_HOST_CMD_REG_211 = 0x1B,
    DDR_HOST_CMD_REG_212 = 0x1C,
    DDR_HOST_CMD_REG_213 = 0x1D,
    DDR_HOST_CMD_REG_214 = 0x1E,
    DDR_HOST_CMD_REG_215 = 0x1F

} DDR_HOST_CMD_REG;

/* Section 2 - Feature variant inclusion */

#define PLIB_TEMPLATE PLIB_INLINE
#include "../templates/ddr_ArbitrationControl_Default.h"
#include "../templates/ddr_AddressMapping_Default.h"
#include "../templates/ddr_RefreshConfig_Default.h"
#include "../templates/ddr_AutoPowerDown_Default.h"
#include "../templates/ddr_AutoSelfRefresh_Default.h"
#include "../templates/ddr_AutoPrecharge_Default.h"
#include "../templates/ddr_TimingDelays_Default.h"
#include "../templates/ddr_ODTConfig_Default.h"
#include "../templates/ddr_DDRControllerConfig_Default.h"
#include "../templates/ddr_DDRCommands_Default.h"
#include "../templates/ddr_PHY_PadConfig_Default.h"
#include "../templates/ddr_PHY_DLLCalibration_Default.h"
#include "../templates/ddr_PHY_SCLConfig_Default.h"

/* Section 3 - PLIB dispatch function definitions */

PLIB_INLINE_API void PLIB_DDR_MinLimit(DDR_MODULE_ID index, uint8_t minLim, DDR_TARGET target)
{
     DDR_MinLimit_Default(index, minLim, target);
}

PLIB_INLINE_API void PLIB_DDR_ReqPeriod(DDR_MODULE_ID index, uint8_t reqPer, DDR_TARGET target)
{
     DDR_ReqPeriod_Default(index, reqPer, target);
}

PLIB_INLINE_API void PLIB_DDR_MinCommand(DDR_MODULE_ID index, uint8_t minCmd, DDR_TARGET target)
{
     DDR_MinCommand_Default(index, minCmd, target);
}

PLIB_INLINE_API bool PLIB_DDR_ExistsArbitrationControl(DDR_MODULE_ID index)
{
     return DDR_ExistsArbitrationControl_Default(index);
}

PLIB_INLINE_API void PLIB_DDR_RowAddressSet(DDR_MODULE_ID index, uint32_t rowShft, uint32_t rowMsk)
{
     DDR_RowAddressSet_Default(index, rowShft, rowMsk);
}

PLIB_INLINE_API void PLIB_DDR_ColumnAddressSet(DDR_MODULE_ID index, uint32_t colShft, uint32_t colMskLo, uint32_t colMskHi)
{
     DDR_ColumnAddressSet_Default(index, colShft, colMskLo, colMskHi);
}

PLIB_INLINE_API void PLIB_DDR_BankAddressSet(DDR_MODULE_ID index, uint32_t bnkShft, uint32_t bnkMsk)
{
     DDR_BankAddressSet_Default(index, bnkShft, bnkMsk);
}

PLIB_INLINE_API void PLIB_DDR_ChipSelectAddressSet(DDR_MODULE_ID index, uint32_t csShft, uint32_t csMsk)
{
     DDR_ChipSelectAddressSet_Default(index, csShft, csMsk);
}

PLIB_INLINE_API bool PLIB_DDR_ExistsAddressMapping(DDR_MODULE_ID index)
{
     return DDR_ExistsAddressMapping_Default(index);
}

PLIB_INLINE_API void PLIB_DDR_RefreshTimingSet(DDR_MODULE_ID index, uint32_t tRFC, uint32_t tRFI, uint32_t ctrlClkPer)
{
     DDR_RefreshTimingSet_Default(index, tRFC, tRFI, ctrlClkPer);
}

PLIB_INLINE_API void PLIB_DDR_MaxPendingRefSet(DDR_MODULE_ID index, uint8_t maxRefs)
{
     DDR_MaxPendingRefSet_Default(index, maxRefs);
}

PLIB_INLINE_API bool PLIB_DDR_ExistsRefreshConfig(DDR_MODULE_ID index)
{
     return DDR_ExistsRefreshConfig_Default(index);
}

PLIB_INLINE_API void PLIB_DDR_AutoPowerDownEnable(DDR_MODULE_ID index)
{
     DDR_AutoPowerDownEnable_Default(index);
}

PLIB_INLINE_API void PLIB_DDR_AutoPowerDownDisable(DDR_MODULE_ID index)
{
     DDR_AutoPowerDownDisable_Default(index);
}

PLIB_INLINE_API bool PLIB_DDR_ExistsAutoPowerDown(DDR_MODULE_ID index)
{
     return DDR_ExistsAutoPowerDown_Default(index);
}

PLIB_INLINE_API void PLIB_DDR_AutoSelfRefreshEnable(DDR_MODULE_ID index)
{
     DDR_AutoSelfRefreshEnable_Default(index);
}

PLIB_INLINE_API void PLIB_DDR_AutoSelfRefreshDisable(DDR_MODULE_ID index)
{
     DDR_AutoSelfRefreshDisable_Default(index);
}

PLIB_INLINE_API bool PLIB_DDR_ExistsAutoSelfRefresh(DDR_MODULE_ID index)
{
     return DDR_ExistsAutoSelfRefresh_Default(index);
}

PLIB_INLINE_API void PLIB_DDR_AutoPchrgEnable(DDR_MODULE_ID index)
{
     DDR_AutoPchrgEnable_Default(index);
}

PLIB_INLINE_API void PLIB_DDR_AutoPchrgDisable(DDR_MODULE_ID index)
{
     DDR_AutoPchrgDisable_Default(index);
}

PLIB_INLINE_API void PLIB_DDR_AutoPchrgPowerDownEnable(DDR_MODULE_ID index)
{
     DDR_AutoPchrgPowerDownEnable_Default(index);
}

PLIB_INLINE_API void PLIB_DDR_AutoPchrgPowerDownDisable(DDR_MODULE_ID index)
{
     DDR_AutoPchrgPowerDownDisable_Default(index);
}

PLIB_INLINE_API bool PLIB_DDR_ExistsAutoPrecharge(DDR_MODULE_ID index)
{
     return DDR_ExistsAutoPrecharge_Default(index);
}

PLIB_INLINE_API void PLIB_DDR_ReadWriteDelaySet(DDR_MODULE_ID index, uint8_t bLen, uint8_t wLat, uint8_t rLat)
{
     DDR_ReadWriteDelaySet_Default(index, bLen, wLat, rLat);
}

PLIB_INLINE_API void PLIB_DDR_WriteReadDelaySet(DDR_MODULE_ID index, uint32_t tWTR, uint8_t bLen, uint8_t wLat, uint32_t ctrlClkPer)
{
     DDR_WriteReadDelaySet_Default(index, tWTR, bLen, wLat, ctrlClkPer);
}

PLIB_INLINE_API void PLIB_DDR_ReadReadDelaySet(DDR_MODULE_ID index, uint8_t bLen)
{
     DDR_ReadReadDelaySet_Default(index, bLen);
}

PLIB_INLINE_API void PLIB_DDR_WriteWriteDelaySet(DDR_MODULE_ID index, uint8_t bLen)
{
     DDR_WriteWriteDelaySet_Default(index, bLen);
}

PLIB_INLINE_API void PLIB_DDR_SelfRefreshDelaySet(DDR_MODULE_ID index, uint32_t slfRefDly, uint32_t tCKE, uint32_t tDLLK)
{
     DDR_SelfRefreshDelaySet_Default(index, slfRefDly, tCKE, tDLLK);
}

PLIB_INLINE_API void PLIB_DDR_PowerDownDelaySet(DDR_MODULE_ID index, uint32_t pwrDnDly, uint32_t tCKE, uint32_t tXP)
{
     DDR_PowerDownDelaySet_Default(index, pwrDnDly, tCKE, tXP);
}

PLIB_INLINE_API void PLIB_DDR_PrechargAllBanksSet(DDR_MODULE_ID index, uint32_t tRP, uint32_t ctrlClkPer)
{
     DDR_PrechargAllBanksSet_Default(index, tRP, ctrlClkPer);
}

PLIB_INLINE_API void PLIB_DDR_ReadToPrechargeDelaySet(DDR_MODULE_ID index, uint32_t tRTP, uint8_t bLen, uint32_t ctrlClkPer)
{
     DDR_ReadToPrechargeDelaySet_Default(index, tRTP, bLen, ctrlClkPer);
}

PLIB_INLINE_API void PLIB_DDR_WriteToPrechargeDelaySet(DDR_MODULE_ID index, uint32_t tWR, uint8_t bLen, uint8_t wLat, uint32_t ctrlClkPer)
{
     DDR_WriteToPrechargeDelaySet_Default(index, tWR, bLen, wLat, ctrlClkPer);
}

PLIB_INLINE_API void PLIB_DDR_PrechargeToRASDelaySet(DDR_MODULE_ID index, uint32_t tRP, uint32_t ctrlClkPer)
{
     DDR_PrechargeToRASDelaySet_Default(index, tRP, ctrlClkPer);
}

PLIB_INLINE_API void PLIB_DDR_RASToPrechargeDelaySet(DDR_MODULE_ID index, uint32_t tRAS, uint32_t ctrlClkPer)
{
     DDR_RASToPrechargeDelaySet_Default(index, tRAS, ctrlClkPer);
}

PLIB_INLINE_API void PLIB_DDR_RASToRASBankDelaySet(DDR_MODULE_ID index, uint32_t tRC, uint32_t ctrlClkPer)
{
     DDR_RASToRASBankDelaySet_Default(index, tRC, ctrlClkPer);
}

PLIB_INLINE_API void PLIB_DDR_RASToRASDelaySet(DDR_MODULE_ID index, uint32_t tRRD, uint32_t ctrlClkPer)
{
     DDR_RASToRASDelaySet_Default(index, tRRD, ctrlClkPer);
}

PLIB_INLINE_API void PLIB_DDR_RASToCASDelaySet(DDR_MODULE_ID index, uint32_t tRCD, uint32_t ctrlClkPer)
{
     DDR_RASToCASDelaySet_Default(index, tRCD, ctrlClkPer);
}

PLIB_INLINE_API void PLIB_DDR_DataDelaySet(DDR_MODULE_ID index, uint8_t rLat, uint8_t wLat)
{
     DDR_DataDelaySet_Default(index, rLat, wLat);
}

PLIB_INLINE_API void PLIB_DDR_TfawDelaySet(DDR_MODULE_ID index, uint32_t tFaw, uint32_t ctrlClkPer)
{
     DDR_TfawDelaySet_Default(index, tFaw, ctrlClkPer);
}

PLIB_INLINE_API bool PLIB_DDR_ExistsTimingDelays(DDR_MODULE_ID index)
{
     return DDR_ExistsTimingDelays_Default(index);
}

PLIB_INLINE_API void PLIB_DDR_OdtReadEnable(DDR_MODULE_ID index, uint8_t odtCS)
{
     DDR_OdtReadEnable_Default(index, odtCS);
}

PLIB_INLINE_API void PLIB_DDR_OdtReadDisable(DDR_MODULE_ID index, uint8_t odtCS)
{
     DDR_OdtReadDisable_Default(index, odtCS);
}

PLIB_INLINE_API void PLIB_DDR_OdtWriteEnable(DDR_MODULE_ID index, uint8_t odtCS)
{
     DDR_OdtWriteEnable_Default(index, odtCS);
}

PLIB_INLINE_API void PLIB_DDR_OdtWriteDisable(DDR_MODULE_ID index, uint8_t odtCS)
{
     DDR_OdtWriteDisable_Default(index, odtCS);
}

PLIB_INLINE_API void PLIB_DDR_OdtWriteParamSet(DDR_MODULE_ID index, uint8_t wLen, uint8_t wDly)
{
     DDR_OdtWriteParamSet_Default(index, wLen, wDly);
}

PLIB_INLINE_API void PLIB_DDR_OdtReadParamSet(DDR_MODULE_ID index, uint8_t rLen, uint8_t rDly)
{
     DDR_OdtReadParamSet_Default(index, rLen, rDly);
}

PLIB_INLINE_API bool PLIB_DDR_ExistsODTConfig(DDR_MODULE_ID index)
{
     return DDR_ExistsODTConfig_Default(index);
}

PLIB_INLINE_API void PLIB_DDR_BigEndianSet(DDR_MODULE_ID index)
{
     DDR_BigEndianSet_Default(index);
}

PLIB_INLINE_API void PLIB_DDR_LittleEndianSet(DDR_MODULE_ID index)
{
     DDR_LittleEndianSet_Default(index);
}

PLIB_INLINE_API void PLIB_DDR_FullRateSet(DDR_MODULE_ID index)
{
     DDR_FullRateSet_Default(index);
}

PLIB_INLINE_API void PLIB_DDR_HalfRateSet(DDR_MODULE_ID index)
{
     DDR_HalfRateSet_Default(index);
}

PLIB_INLINE_API bool PLIB_DDR_ExistsDDRControllerConfig(DDR_MODULE_ID index)
{
     return DDR_ExistsDDRControllerConfig_Default(index);
}

PLIB_INLINE_API void PLIB_DDR_MaxCmdBrstCntSet(DDR_MODULE_ID index, int8_t maxCmds)
{
     DDR_MaxCmdBrstCntSet_Default(index, maxCmds);
}

PLIB_INLINE_API void PLIB_DDR_NumHostCmdsSet(DDR_MODULE_ID index, int8_t numCmds)
{
     DDR_NumHostCmdsSet_Default(index, numCmds);
}

PLIB_INLINE_API void PLIB_DDR_CmdDataWrite(DDR_MODULE_ID index, DDR_HOST_CMD_REG cmdReg, uint32_t cmdData)
{
     DDR_CmdDataWrite_Default(index, cmdReg, cmdData);
}

PLIB_INLINE_API void PLIB_DDR_CmdDataValid(DDR_MODULE_ID index)
{
     DDR_CmdDataValid_Default(index);
}

PLIB_INLINE_API void PLIB_DDR_CmdDataSend(DDR_MODULE_ID index)
{
     DDR_CmdDataSend_Default(index);
}

PLIB_INLINE_API bool PLIB_DDR_CmdDataIsComplete(DDR_MODULE_ID index)
{
     return DDR_CmdDataIsComplete_Default(index);
}

PLIB_INLINE_API void PLIB_DDR_ControllerEnable(DDR_MODULE_ID index)
{
     DDR_ControllerEnable_Default(index);
}

PLIB_INLINE_API bool PLIB_DDR_ExistsDDRCommands(DDR_MODULE_ID index)
{
     return DDR_ExistsDDRCommands_Default(index);
}

PLIB_INLINE_API void PLIB_DDR_PHY_OdtEnable(DDR_MODULE_ID index, DDR_PHY_ODT odtVal)
{
     DDR_PHY_OdtEnable_Default(index, odtVal);
}

PLIB_INLINE_API void PLIB_DDR_PHY_OdtDisable(DDR_MODULE_ID index)
{
     DDR_PHY_OdtDisable_Default(index);
}

PLIB_INLINE_API void PLIB_DDR_PHY_DataDriveStrengthSet(DDR_MODULE_ID index, DDR_PHY_DRIVE_STRENGTH drvStr)
{
     DDR_PHY_DataDriveStrengthSet_Default(index, drvStr);
}

PLIB_INLINE_API void PLIB_DDR_PHY_AddCtlDriveStrengthSet(DDR_MODULE_ID index, DDR_PHY_DRIVE_STRENGTH drvStr)
{
     DDR_PHY_AddCtlDriveStrengthSet_Default(index, drvStr);
}

PLIB_INLINE_API void PLIB_DDR_PHY_OdtCal(DDR_MODULE_ID index, uint8_t puCal, uint8_t pdCal)
{
     DDR_PHY_OdtCal_Default(index, puCal, pdCal);
}

PLIB_INLINE_API void PLIB_DDR_PHY_DrvStrgthCal(DDR_MODULE_ID index, uint8_t nFet, uint8_t pFet)
{
     DDR_PHY_DrvStrgthCal_Default(index, nFet, pFet);
}

PLIB_INLINE_API void PLIB_DDR_PHY_ExtraClockEnable(DDR_MODULE_ID index)
{
     DDR_PHY_ExtraClockEnable_Default(index);
}

PLIB_INLINE_API void PLIB_DDR_PHY_ExtraClockDisable(DDR_MODULE_ID index)
{
     DDR_PHY_ExtraClockDisable_Default(index);
}

PLIB_INLINE_API void PLIB_DDR_PHY_InternalDllEnable(DDR_MODULE_ID index)
{
     DDR_PHY_InternalDllEnable_Default(index);
}

PLIB_INLINE_API void PLIB_DDR_PHY_ExternalDllEnable(DDR_MODULE_ID index)
{
     DDR_PHY_ExternalDllEnable_Default(index);
}

PLIB_INLINE_API void PLIB_DDR_PHY_PadReceiveEnable(DDR_MODULE_ID index)
{
     DDR_PHY_PadReceiveEnable_Default(index);
}

PLIB_INLINE_API void PLIB_DDR_PHY_PadReceiveDisable(DDR_MODULE_ID index)
{
     DDR_PHY_PadReceiveDisable_Default(index);
}

PLIB_INLINE_API void PLIB_DDR_PHY_PreambleDlySet(DDR_MODULE_ID index, DDR_PHY_PREAMBLE_DLY preDly)
{
     DDR_PHY_PreambleDlySet_Default(index, preDly);
}

PLIB_INLINE_API void PLIB_DDR_PHY_HalfRateSet(DDR_MODULE_ID index)
{
     DDR_PHY_HalfRateSet_Default(index);
}

PLIB_INLINE_API void PLIB_DDR_PHY_WriteCmdDelayEnable(DDR_MODULE_ID index)
{
     DDR_PHY_WriteCmdDelayEnable_Default(index);
}

PLIB_INLINE_API void PLIB_DDR_PHY_WriteCmdDelayDisable(DDR_MODULE_ID index)
{
     DDR_PHY_WriteCmdDelayDisable_Default(index);
}

PLIB_INLINE_API bool PLIB_DDR_ExistsPHY_PadConfig(DDR_MODULE_ID index)
{
     return DDR_ExistsPHY_PadConfig_Default(index);
}

PLIB_INLINE_API void PLIB_DDR_PHY_DllRecalibEnable(DDR_MODULE_ID index, uint32_t recalibCnt)
{
     DDR_PHY_DllRecalibEnable_Default(index, recalibCnt);
}

PLIB_INLINE_API void PLIB_DDR_PHY_DllRecalibDisable(DDR_MODULE_ID index)
{
     DDR_PHY_DllRecalibDisable_Default(index);
}

PLIB_INLINE_API void PLIB_DDR_PHY_DllMasterDelayStartSet(DDR_MODULE_ID index, uint8_t dlyStart)
{
     DDR_PHY_DllMasterDelayStartSet_Default(index, dlyStart);
}

PLIB_INLINE_API bool PLIB_DDR_ExistsPHY_DLLCalibration(DDR_MODULE_ID index)
{
     return DDR_ExistsPHY_DLLCalibration_Default(index);
}

PLIB_INLINE_API void PLIB_DDR_PHY_SCLTestBurstModeSet(DDR_MODULE_ID index, DDR_PHY_SCL_BURST_MODE brstMode)
{
     DDR_PHY_SCLTestBurstModeSet_Default(index, brstMode);
}

PLIB_INLINE_API void PLIB_DDR_PHY_DDRTypeSet(DDR_MODULE_ID index, DDR_PHY_DDR_TYPE ddrType)
{
     DDR_PHY_DDRTypeSet_Default(index, ddrType);
}

PLIB_INLINE_API void PLIB_DDR_PHY_ReadCASLatencySet(DDR_MODULE_ID index, uint8_t rLat)
{
     DDR_PHY_ReadCASLatencySet_Default(index, rLat);
}

PLIB_INLINE_API void PLIB_DDR_PHY_WriteCASLatencySet(DDR_MODULE_ID index, uint8_t wLat)
{
     DDR_PHY_WriteCASLatencySet_Default(index, wLat);
}

PLIB_INLINE_API void PLIB_DDR_PHY_OdtCSEnable(DDR_MODULE_ID index)
{
     DDR_PHY_OdtCSEnable_Default(index);
}

PLIB_INLINE_API void PLIB_DDR_PHY_OdtCSDisable(DDR_MODULE_ID index)
{
     DDR_PHY_OdtCSDisable_Default(index);
}

PLIB_INLINE_API void PLIB_DDR_PHY_SCLDelay(DDR_MODULE_ID index, DDR_PHY_SCL_DELAY sclDly)
{
     DDR_PHY_SCLDelay_Default(index, sclDly);
}

PLIB_INLINE_API void PLIB_DDR_PHY_SCLEnable(DDR_MODULE_ID index, uint8_t cs)
{
     DDR_PHY_SCLEnable_Default(index, cs);
}

PLIB_INLINE_API void PLIB_DDR_PHY_SCLDDRClkDelaySet(DDR_MODULE_ID index, uint8_t ddrDly)
{
     DDR_PHY_SCLDDRClkDelaySet_Default(index, ddrDly);
}

PLIB_INLINE_API void PLIB_DDR_PHY_SCLCapClkDelaySet(DDR_MODULE_ID index, uint8_t capDly)
{
     DDR_PHY_SCLCapClkDelaySet_Default(index, capDly);
}

PLIB_INLINE_API void PLIB_DDR_PHY_SCLStart(DDR_MODULE_ID index)
{
     DDR_PHY_SCLStart_Default(index);
}

PLIB_INLINE_API bool PLIB_DDR_PHY_SCLStatus(DDR_MODULE_ID index)
{
     return DDR_PHY_SCLStatus_Default(index);
}

PLIB_INLINE_API bool PLIB_DDR_ExistsPHY_SCLConfig(DDR_MODULE_ID index)
{
     return DDR_ExistsPHY_SCLConfig_Default(index);
}

#endif
