/* Created by plibgen $Revision: 1.31 $ */

#ifndef _GLCD_P32MZ2064DAG169_H
#define _GLCD_P32MZ2064DAG169_H

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

    GLCD_ID_0 = 0,
    GLCD_NUMBER_OF_MODULES = 1

} GLCD_MODULE_ID;

typedef enum {

    GLCD_RGB_MODE_PARALLEL_RGB565 = 0x00000000,
    GLCD_RGB_MODE_PARALLEL_RGB888 = 0x00000001,
    GLCD_RGB_MODE_SERIAL_RGB_3 = 0x00000002,
    GLCD_RGB_MODE_SERIAL_RGBA_4 = 0x00000003,
    GLCD_RGB_MODE_SERIAL_12BIT = 0x00000004,
    GLCD_RGB_MODE_YUYV_16BIT = 0x00000005,
    GLCD_RGB_MODE_BT_656 = 0x00000006

} GLCD_RGB_MODE;

typedef enum {

    GLCD_POLARITY_POSITIVE = 0x00000000,
    GLCD_PIXEL_CLOCK_POLARITY_NEGATIVE = 0x00400000,
    GLCD_DE_POLARITY_NEGATIVE = 0x04000000,
    GLCD_HSYNC_POLARITY_NEGATIVE = 0x08000000,
    GLCD_VSYNC_POLARITY_NEGATIVE = 0x10000000

} GLCD_SIGNAL_POLARITY;

typedef enum {

    GLCD_LAYER_ID_0 = 0x0,
    GLCD_LAYER_ID_1 = 0x1,
    GLCD_LAYER_ID_2 = 0x2,
    GLCD_LAYER_ID_MAX = 0x3

} GLCD_LAYER_ID;

typedef enum {

    GLCD_LAYER_COLOR_MODE_LUT8 = 0x0,
    GLCD_LAYER_COLOR_MODE_RGBA5551 = 0x1,
    GLCD_LAYER_COLOR_MODE_RGBA8888 = 0x2,
    GLCD_LAYER_COLOR_MODE_RGB332 = 0x4,
    GLCD_LAYER_COLOR_MODE_RGB565 = 0x5,
    GLCD_LAYER_COLOR_MODE_ARGB8888 = 0x6,
    GLCD_LAYER_COLOR_MODE_L8 = 0x7,
    GLCD_LAYER_COLOR_MODE_L1 = 0x8,
    GLCD_LAYER_COLOR_MODE_L4 = 0x9,
    GLCD_LAYER_COLOR_MODE_YUYV = 0xA,
    GLCD_LAYER_COLOR_MODE_RGB888 = 0xB

} GLCD_LAYER_COLOR_MODE;

typedef enum {

    GLCD_LAYER_SRC_BLEND_BLACK = 0x0000,
    GLCD_LAYER_SRC_BLEND_WHITE = 0x0100,
    GLCD_LAYER_SRC_BLEND_ALPHA_SRC = 0x0200,
    GLCD_LAYER_SRC_BLEND_ALPHA_GBL = 0x0300,
    GLCD_LAYER_SRC_BLEND_ALPHA_SRCGBL = 0x0400,
    GLCD_LAYER_SRC_BLEND_INV_SRC = 0x0500,
    GLCD_LAYER_SRC_BLEND_INV_GBL = 0x0600,
    GLCD_LAYER_SRC_BLEND_INV_SRCGBL = 0x0700,
    GLCD_LAYER_SRC_BLEND_ALPHA_DST = 0x0A00,
    GLCD_LAYER_SRC_BLEND_INV_DST = 0x0D00

} GLCD_LAYER_SRC_BLEND_FUNC;

typedef enum {

    GLCD_LAYER_DEST_BLEND_BLACK = 0x0000,
    GLCD_LAYER_DEST_BLEND_WHITE = 0x1000,
    GLCD_LAYER_DEST_BLEND_ALPHA_SRC = 0x2000,
    GLCD_LAYER_DEST_BLEND_ALPHA_GBL = 0x3000,
    GLCD_LAYER_DEST_BLEND_ALPHA_SRCGBL = 0x4000,
    GLCD_LAYER_DEST_BLEND_INV_SRC = 0x5000,
    GLCD_LAYER_DEST_BLEND_INV_GBL = 0x6000,
    GLCD_LAYER_DEST_BLEND_INV_SRCGBL = 0x7000,
    GLCD_LAYER_DEST_BLEND_ALPHA_DST = 0xA000,
    GLCD_LAYER_DEST_BLEND_INV_DST = 0xD000

} GLCD_LAYER_DEST_BLEND_FUNC;

typedef enum {

    GLCD_IRQ_TRIGGER_LEVEL = 0x00000000,
    GLCD_IRQ_TRIGGER_EDGE = 0x80000000

} GLCD_IRQ_TRIGGER_CONTROL;

/* Section 2 - Feature variant inclusion */

#define PLIB_TEMPLATE PLIB_INLINE
#include "../templates/glcd_RGBSequentialMode_Default.h"
#include "../templates/glcd_FormattingClockDivideControl_Default.h"
#include "../templates/glcd_YUVOutputControl_Default.h"
#include "../templates/glcd_ForceOutputBlankControl_Default.h"
#include "../templates/glcd_PaletteGammaRampControl_Default.h"
#include "../templates/glcd_SignalPolarityMode_Default.h"
#include "../templates/glcd_SingleCyclePerLineVsyncControl_Default.h"
#include "../templates/glcd_DitheringControl_Default.h"
#include "../templates/glcd_CursorControl_Default.h"
#include "../templates/glcd_EnableControl_Default.h"
#include "../templates/glcd_ClockDivider_Default.h"
#include "../templates/glcd_LinesPrefetch_Default.h"
#include "../templates/glcd_BackgroundColor_Default.h"
#include "../templates/glcd_ResolutionXY_Default.h"
#include "../templates/glcd_FrontPorchXY_Default.h"
#include "../templates/glcd_BlankingXY_Default.h"
#include "../templates/glcd_BackPorchXY_Default.h"
#include "../templates/glcd_CursorXY_Default.h"
#include "../templates/glcd_LayerColorMode_Default.h"
#include "../templates/glcd_LayerSrcBlendFuncMode_Default.h"
#include "../templates/glcd_LayerDestBlendFuncMode_Default.h"
#include "../templates/glcd_LayerGlobalAlpha_Default.h"
#include "../templates/glcd_LayerPreMultiplyImageAlphaControl_Default.h"
#include "../templates/glcd_LayerForceWithGlobalAlphaControl_Default.h"
#include "../templates/glcd_LayerBilinearFilterControl_Default.h"
#include "../templates/glcd_LayerControl_Default.h"
#include "../templates/glcd_LayerStartXY_Default.h"
#include "../templates/glcd_LayerSizeXY_Default.h"
#include "../templates/glcd_LayerBaseAddress_Default.h"
#include "../templates/glcd_LayerStride_Default.h"
#include "../templates/glcd_LayerResXY_Default.h"
#include "../templates/glcd_HSyncInterruptControl_Default.h"
#include "../templates/glcd_VSyncInterruptControl_Default.h"
#include "../templates/glcd_IRQTriggerControl_Default.h"
#include "../templates/glcd_VerticalBlankingActiveState_Default.h"
#include "../templates/glcd_DESignalLevel_Default.h"
#include "../templates/glcd_HSyncSignalLevel_Default.h"
#include "../templates/glcd_VSyncSignalLevel_Default.h"
#include "../templates/glcd_LastRowState_Default.h"
#include "../templates/glcd_GlobalColorLUT_Default.h"
#include "../templates/glcd_CursorData_Default.h"
#include "../templates/glcd_CursorLUT_Default.h"

/* Section 3 - PLIB dispatch function definitions */

PLIB_INLINE_API bool PLIB_GLCD_ExistsRGBSequentialMode(GLCD_MODULE_ID index)
{
     return GLCD_ExistsRGBSequentialMode_Default(index);
}

PLIB_INLINE_API void PLIB_GLCD_RGBSequentialModeSet(GLCD_MODULE_ID index, GLCD_RGB_MODE mode)
{
     GLCD_RGBSequentialModeSet_Default(index, mode);
}

PLIB_INLINE_API GLCD_RGB_MODE PLIB_GLCD_RGBSequentialModeGet(GLCD_MODULE_ID index)
{
     return GLCD_RGBSequentialModeGet_Default(index);
}

PLIB_INLINE_API bool PLIB_GLCD_ExistsFormattingClockDivide(GLCD_MODULE_ID index)
{
     return GLCD_ExistsFormattingClockDivide_Default(index);
}

PLIB_INLINE_API void PLIB_GLCD_FormattingClockDivideEnable(GLCD_MODULE_ID index)
{
     GLCD_FormattingClockDivideEnable_Default(index);
}

PLIB_INLINE_API void PLIB_GLCD_FormattingClockDivideDisable(GLCD_MODULE_ID index)
{
     GLCD_FormattingClockDivideDisable_Default(index);
}

PLIB_INLINE_API bool PLIB_GLCD_FormattingClockDivideIsEnabled(GLCD_MODULE_ID index)
{
     return GLCD_FormattingClockDivideIsEnabled_Default(index);
}

PLIB_INLINE_API bool PLIB_GLCD_ExistsYUVOutput(GLCD_MODULE_ID index)
{
     return GLCD_ExistsYUVOutput_Default(index);
}

PLIB_INLINE_API void PLIB_GLCD_YUVOutputEnable(GLCD_MODULE_ID index)
{
     GLCD_YUVOutputEnable_Default(index);
}

PLIB_INLINE_API void PLIB_GLCD_YUVOutputDisable(GLCD_MODULE_ID index)
{
     GLCD_YUVOutputDisable_Default(index);
}

PLIB_INLINE_API bool PLIB_GLCD_YUVOutputIsEnabled(GLCD_MODULE_ID index)
{
     return GLCD_YUVOutputIsEnabled_Default(index);
}

PLIB_INLINE_API bool PLIB_GLCD_ExistsForceOutputBlank(GLCD_MODULE_ID index)
{
     return GLCD_ExistsForceOutputBlank_Default(index);
}

PLIB_INLINE_API void PLIB_GLCD_ForceOutputBlankEnable(GLCD_MODULE_ID index)
{
     GLCD_ForceOutputBlankEnable_Default(index);
}

PLIB_INLINE_API void PLIB_GLCD_ForceOutputBlankDisable(GLCD_MODULE_ID index)
{
     GLCD_ForceOutputBlankDisable_Default(index);
}

PLIB_INLINE_API bool PLIB_GLCD_ForceOutputBlankIsEnabled(GLCD_MODULE_ID index)
{
     return GLCD_ForceOutputBlankIsEnabled_Default(index);
}

PLIB_INLINE_API bool PLIB_GLCD_ExistsPaletteGammaRamp(GLCD_MODULE_ID index)
{
     return GLCD_ExistsPaletteGammaRamp_Default(index);
}

PLIB_INLINE_API void PLIB_GLCD_PaletteGammaRampEnable(GLCD_MODULE_ID index)
{
     GLCD_PaletteGammaRampEnable_Default(index);
}

PLIB_INLINE_API void PLIB_GLCD_PaletteGammaRampDisable(GLCD_MODULE_ID index)
{
     GLCD_PaletteGammaRampDisable_Default(index);
}

PLIB_INLINE_API bool PLIB_GLCD_PaletteGammaRampIsEnabled(GLCD_MODULE_ID index)
{
     return GLCD_PaletteGammaRampIsEnabled_Default(index);
}

PLIB_INLINE_API bool PLIB_GLCD_ExistsSignalPolarity(GLCD_MODULE_ID index)
{
     return GLCD_ExistsSignalPolarity_Default(index);
}

PLIB_INLINE_API void PLIB_GLCD_SignalPolaritySet(GLCD_MODULE_ID index, GLCD_SIGNAL_POLARITY polarity)
{
     GLCD_SignalPolaritySet_Default(index, polarity);
}

PLIB_INLINE_API GLCD_SIGNAL_POLARITY PLIB_GLCD_SignalPolarityGet(GLCD_MODULE_ID index)
{
     return GLCD_SignalPolarityGet_Default(index);
}

PLIB_INLINE_API bool PLIB_GLCD_ExistsSingleCyclePerLineVsync(GLCD_MODULE_ID index)
{
     return GLCD_ExistsSingleCyclePerLineVsync_Default(index);
}

PLIB_INLINE_API void PLIB_GLCD_SingleCyclePerLineVsyncEnable(GLCD_MODULE_ID index)
{
     GLCD_SingleCyclePerLineVsyncEnable_Default(index);
}

PLIB_INLINE_API void PLIB_GLCD_SingleCyclePerLineVsyncDisable(GLCD_MODULE_ID index)
{
     GLCD_SingleCyclePerLineVsyncDisable_Default(index);
}

PLIB_INLINE_API bool PLIB_GLCD_SingleCyclePerLineVsyncIsEnabled(GLCD_MODULE_ID index)
{
     return GLCD_SingleCyclePerLineVsyncIsEnabled_Default(index);
}

PLIB_INLINE_API bool PLIB_GLCD_ExistsDithering(GLCD_MODULE_ID index)
{
     return GLCD_ExistsDithering_Default(index);
}

PLIB_INLINE_API void PLIB_GLCD_DitheringEnable(GLCD_MODULE_ID index)
{
     GLCD_DitheringEnable_Default(index);
}

PLIB_INLINE_API void PLIB_GLCD_DitheringDisable(GLCD_MODULE_ID index)
{
     GLCD_DitheringDisable_Default(index);
}

PLIB_INLINE_API bool PLIB_GLCD_DitheringIsEnabled(GLCD_MODULE_ID index)
{
     return GLCD_DitheringIsEnabled_Default(index);
}

PLIB_INLINE_API bool PLIB_GLCD_ExistsCursor(GLCD_MODULE_ID index)
{
     return GLCD_ExistsCursor_Default(index);
}

PLIB_INLINE_API void PLIB_GLCD_CursorEnable(GLCD_MODULE_ID index)
{
     GLCD_CursorEnable_Default(index);
}

PLIB_INLINE_API void PLIB_GLCD_CursorDisable(GLCD_MODULE_ID index)
{
     GLCD_CursorDisable_Default(index);
}

PLIB_INLINE_API bool PLIB_GLCD_CursorIsEnabled(GLCD_MODULE_ID index)
{
     return GLCD_CursorIsEnabled_Default(index);
}

PLIB_INLINE_API bool PLIB_GLCD_ExistsEnable(GLCD_MODULE_ID index)
{
     return GLCD_ExistsEnable_Default(index);
}

PLIB_INLINE_API void PLIB_GLCD_Enable(GLCD_MODULE_ID index)
{
     GLCD_Enable_Default(index);
}

PLIB_INLINE_API void PLIB_GLCD_Disable(GLCD_MODULE_ID index)
{
     GLCD_Disable_Default(index);
}

PLIB_INLINE_API bool PLIB_GLCD_IsEnabled(GLCD_MODULE_ID index)
{
     return GLCD_IsEnabled_Default(index);
}

PLIB_INLINE_API bool PLIB_GLCD_ExistsClockDivider(GLCD_MODULE_ID index)
{
     return GLCD_ExistsClockDivider_Default(index);
}

PLIB_INLINE_API void PLIB_GLCD_ClockDividerSet(GLCD_MODULE_ID index, uint32_t clockDivider)
{
     GLCD_ClockDividerSet_Default(index, clockDivider);
}

PLIB_INLINE_API uint32_t PLIB_GLCD_ClockDividerGet(GLCD_MODULE_ID index)
{
     return GLCD_ClockDividerGet_Default(index);
}

PLIB_INLINE_API bool PLIB_GLCD_ExistsLinesPrefetch(GLCD_MODULE_ID index)
{
     return GLCD_ExistsLinesPrefetch_Default(index);
}

PLIB_INLINE_API void PLIB_GLCD_LinesPrefetchSet(GLCD_MODULE_ID index, uint32_t linesPrefetch)
{
     GLCD_LinesPrefetchSet_Default(index, linesPrefetch);
}

PLIB_INLINE_API uint32_t PLIB_GLCD_LinesPrefetchGet(GLCD_MODULE_ID index)
{
     return GLCD_LinesPrefetchGet_Default(index);
}

PLIB_INLINE_API bool PLIB_GLCD_ExistsBackgroundColor(GLCD_MODULE_ID index)
{
     return GLCD_ExistsBackgroundColor_Default(index);
}

PLIB_INLINE_API void PLIB_GLCD_BackgroundColorSet(GLCD_MODULE_ID index, uint32_t bgColor)
{
     GLCD_BackgroundColorSet_Default(index, bgColor);
}

PLIB_INLINE_API uint32_t PLIB_GLCD_BackgroundColorGet(GLCD_MODULE_ID index)
{
     return GLCD_BackgroundColorGet_Default(index);
}

PLIB_INLINE_API bool PLIB_GLCD_ExistsResolutionXY(GLCD_MODULE_ID index)
{
     return GLCD_ExistsResolutionXY_Default(index);
}

PLIB_INLINE_API void PLIB_GLCD_ResolutionXYSet(GLCD_MODULE_ID index, uint32_t resolutionX, uint32_t resolutionY)
{
     GLCD_ResolutionXYSet_Default(index, resolutionX, resolutionY);
}

PLIB_INLINE_API uint32_t PLIB_GLCD_ResolutionXGet(GLCD_MODULE_ID index)
{
     return GLCD_ResolutionXGet_Default(index);
}

PLIB_INLINE_API uint32_t PLIB_GLCD_ResolutionYGet(GLCD_MODULE_ID index)
{
     return GLCD_ResolutionYGet_Default(index);
}

PLIB_INLINE_API bool PLIB_GLCD_ExistsFrontPorchXY(GLCD_MODULE_ID index)
{
     return GLCD_ExistsFrontPorchXY_Default(index);
}

PLIB_INLINE_API void PLIB_GLCD_FrontPorchXYSet(GLCD_MODULE_ID index, uint32_t frontPorchX, uint32_t frontPorchY)
{
     GLCD_FrontPorchXYSet_Default(index, frontPorchX, frontPorchY);
}

PLIB_INLINE_API uint32_t PLIB_GLCD_FrontPorchXGet(GLCD_MODULE_ID index)
{
     return GLCD_FrontPorchXGet_Default(index);
}

PLIB_INLINE_API uint32_t PLIB_GLCD_FrontPorchYGet(GLCD_MODULE_ID index)
{
     return GLCD_FrontPorchYGet_Default(index);
}

PLIB_INLINE_API bool PLIB_GLCD_ExistsBlankingXY(GLCD_MODULE_ID index)
{
     return GLCD_ExistsBlankingXY_Default(index);
}

PLIB_INLINE_API void PLIB_GLCD_BlankingXYSet(GLCD_MODULE_ID index, uint32_t blankingX, uint32_t blankingY)
{
     GLCD_BlankingXYSet_Default(index, blankingX, blankingY);
}

PLIB_INLINE_API uint32_t PLIB_GLCD_BlankingXGet(GLCD_MODULE_ID index)
{
     return GLCD_BlankingXGet_Default(index);
}

PLIB_INLINE_API uint32_t PLIB_GLCD_BlankingYGet(GLCD_MODULE_ID index)
{
     return GLCD_BlankingYGet_Default(index);
}

PLIB_INLINE_API bool PLIB_GLCD_ExistsBackPorchXY(GLCD_MODULE_ID index)
{
     return GLCD_ExistsBackPorchXY_Default(index);
}

PLIB_INLINE_API void PLIB_GLCD_BackPorchXYSet(GLCD_MODULE_ID index, uint32_t backPorchX, uint32_t backPorchY)
{
     GLCD_BackPorchXYSet_Default(index, backPorchX, backPorchY);
}

PLIB_INLINE_API uint32_t PLIB_GLCD_BackPorchXGet(GLCD_MODULE_ID index)
{
     return GLCD_BackPorchXGet_Default(index);
}

PLIB_INLINE_API uint32_t PLIB_GLCD_BackPorchYGet(GLCD_MODULE_ID index)
{
     return GLCD_BackPorchYGet_Default(index);
}

PLIB_INLINE_API bool PLIB_GLCD_ExistsCursorXY(GLCD_MODULE_ID index)
{
     return GLCD_ExistsCursorXY_Default(index);
}

PLIB_INLINE_API void PLIB_GLCD_CursorXYSet(GLCD_MODULE_ID index, uint32_t cursorX, uint32_t cursorY)
{
     GLCD_CursorXYSet_Default(index, cursorX, cursorY);
}

PLIB_INLINE_API uint32_t PLIB_GLCD_CursorXGet(GLCD_MODULE_ID index)
{
     return GLCD_CursorXGet_Default(index);
}

PLIB_INLINE_API uint32_t PLIB_GLCD_CursorYGet(GLCD_MODULE_ID index)
{
     return GLCD_CursorYGet_Default(index);
}

PLIB_INLINE_API bool PLIB_GLCD_ExistsLayerColorMode(GLCD_MODULE_ID index)
{
     return GLCD_ExistsLayerColorMode_Default(index);
}

PLIB_INLINE_API void PLIB_GLCD_LayerColorModeSet(GLCD_MODULE_ID index, GLCD_LAYER_ID layerId, GLCD_LAYER_COLOR_MODE colorMode)
{
     GLCD_LayerColorModeSet_Default(index, layerId, colorMode);
}

PLIB_INLINE_API GLCD_LAYER_COLOR_MODE PLIB_GLCD_LayerColorModeGet(GLCD_MODULE_ID index, GLCD_LAYER_ID layerId)
{
     return GLCD_LayerColorModeGet_Default(index, layerId);
}

PLIB_INLINE_API bool PLIB_GLCD_ExistsLayerSrcBlendFunc(GLCD_MODULE_ID index)
{
     return GLCD_ExistsLayerSrcBlendFunc_Default(index);
}

PLIB_INLINE_API void PLIB_GLCD_LayerSrcBlendFuncSet(GLCD_MODULE_ID index, GLCD_LAYER_ID layerId, GLCD_LAYER_SRC_BLEND_FUNC blendFunc)
{
     GLCD_LayerSrcBlendFuncSet_Default(index, layerId, blendFunc);
}

PLIB_INLINE_API GLCD_LAYER_SRC_BLEND_FUNC PLIB_GLCD_LayerSrcBlendFuncGet(GLCD_MODULE_ID index, GLCD_LAYER_ID layerId)
{
     return GLCD_LayerSrcBlendFuncGet_Default(index, layerId);
}

PLIB_INLINE_API bool PLIB_GLCD_ExistsLayerDestBlendFunc(GLCD_MODULE_ID index)
{
     return GLCD_ExistsLayerDestBlendFunc_Default(index);
}

PLIB_INLINE_API void PLIB_GLCD_LayerDestBlendFuncSet(GLCD_MODULE_ID index, GLCD_LAYER_ID layerId, GLCD_LAYER_DEST_BLEND_FUNC blendFunc)
{
     GLCD_LayerDestBlendFuncSet_Default(index, layerId, blendFunc);
}

PLIB_INLINE_API GLCD_LAYER_DEST_BLEND_FUNC PLIB_GLCD_LayerDestBlendFuncGet(GLCD_MODULE_ID index, GLCD_LAYER_ID layerId)
{
     return GLCD_LayerDestBlendFuncGet_Default(index, layerId);
}

PLIB_INLINE_API bool PLIB_GLCD_ExistsLayerGlobalAlpha(GLCD_MODULE_ID index)
{
     return GLCD_ExistsLayerGlobalAlpha_Default(index);
}

PLIB_INLINE_API void PLIB_GLCD_LayerGlobalAlphaSet(GLCD_MODULE_ID index, GLCD_LAYER_ID layerId, uint8_t value)
{
     GLCD_LayerGlobalAlphaSet_Default(index, layerId, value);
}

PLIB_INLINE_API uint8_t PLIB_GLCD_LayerGlobalAlphaGet(GLCD_MODULE_ID index, GLCD_LAYER_ID layerId)
{
     return GLCD_LayerGlobalAlphaGet_Default(index, layerId);
}

PLIB_INLINE_API bool PLIB_GLCD_ExistsLayerPreMultiplyImageAlpha(GLCD_MODULE_ID index)
{
     return GLCD_ExistsLayerPreMultiplyImageAlpha_Default(index);
}

PLIB_INLINE_API void PLIB_GLCD_LayerPreMultiplyImageAlphaEnable(GLCD_MODULE_ID index, GLCD_LAYER_ID layerId)
{
     GLCD_LayerPreMultiplyImageAlphaEnable_Default(index, layerId);
}

PLIB_INLINE_API void PLIB_GLCD_LayerPreMultiplyImageAlphaDisable(GLCD_MODULE_ID index, GLCD_LAYER_ID layerId)
{
     GLCD_LayerPreMultiplyImageAlphaDisable_Default(index, layerId);
}

PLIB_INLINE_API bool PLIB_GLCD_LayerPreMultiplyImageAlphaIsEnabled(GLCD_MODULE_ID index, GLCD_LAYER_ID layerId)
{
     return GLCD_LayerPreMultiplyImageAlphaIsEnabled_Default(index, layerId);
}

PLIB_INLINE_API bool PLIB_GLCD_ExistsLayerForceWithGlobalAlpha(GLCD_MODULE_ID index)
{
     return GLCD_ExistsLayerForceWithGlobalAlpha_Default(index);
}

PLIB_INLINE_API void PLIB_GLCD_LayerForceWithGlobalAlphaEnable(GLCD_MODULE_ID index, GLCD_LAYER_ID layerId)
{
     GLCD_LayerForceWithGlobalAlphaEnable_Default(index, layerId);
}

PLIB_INLINE_API void PLIB_GLCD_LayerForceWithGlobalAlphaDisable(GLCD_MODULE_ID index, GLCD_LAYER_ID layerId)
{
     GLCD_LayerForceWithGlobalAlphaDisable_Default(index, layerId);
}

PLIB_INLINE_API bool PLIB_GLCD_LayerForceWithGlobalAlphaIsEnabled(GLCD_MODULE_ID index, GLCD_LAYER_ID layerId)
{
     return GLCD_LayerForceWithGlobalAlphaIsEnabled_Default(index, layerId);
}

PLIB_INLINE_API bool PLIB_GLCD_ExistsLayerBilinearFilterEnable(GLCD_MODULE_ID index)
{
     return GLCD_ExistsLayerBilinearFilterEnable_Default(index);
}

PLIB_INLINE_API void PLIB_GLCD_LayerBilinearFilterEnable(GLCD_MODULE_ID index, GLCD_LAYER_ID layerId)
{
     GLCD_LayerBilinearFilterEnable_Default(index, layerId);
}

PLIB_INLINE_API void PLIB_GLCD_LayerBilinearFilterDisable(GLCD_MODULE_ID index, GLCD_LAYER_ID layerId)
{
     GLCD_LayerBilinearFilterDisable_Default(index, layerId);
}

PLIB_INLINE_API bool PLIB_GLCD_LayerBilinearFilterIsEnabled(GLCD_MODULE_ID index, GLCD_LAYER_ID layerId)
{
     return GLCD_LayerBilinearFilterIsEnabled_Default(index, layerId);
}

PLIB_INLINE_API bool PLIB_GLCD_ExistsLayerEnable(GLCD_MODULE_ID index)
{
     return GLCD_ExistsLayerEnable_Default(index);
}

PLIB_INLINE_API void PLIB_GLCD_LayerEnable(GLCD_MODULE_ID index, GLCD_LAYER_ID layerId)
{
     GLCD_LayerEnable_Default(index, layerId);
}

PLIB_INLINE_API void PLIB_GLCD_LayerDisable(GLCD_MODULE_ID index, GLCD_LAYER_ID layerId)
{
     GLCD_LayerDisable_Default(index, layerId);
}

PLIB_INLINE_API bool PLIB_GLCD_LayerIsEnabled(GLCD_MODULE_ID index, GLCD_LAYER_ID layerId)
{
     return GLCD_LayerIsEnabled_Default(index, layerId);
}

PLIB_INLINE_API bool PLIB_GLCD_ExistsLayerStartXY(GLCD_MODULE_ID index)
{
     return GLCD_ExistsLayerStartXY_Default(index);
}

PLIB_INLINE_API void PLIB_GLCD_LayerStartXYSet(GLCD_MODULE_ID index, GLCD_LAYER_ID layerId, uint32_t startX, uint32_t startY)
{
     GLCD_LayerStartXYSet_Default(index, layerId, startX, startY);
}

PLIB_INLINE_API uint32_t PLIB_GLCD_LayerStartXGet(GLCD_MODULE_ID index, GLCD_LAYER_ID layerId)
{
     return GLCD_LayerStartXGet_Default(index, layerId);
}

PLIB_INLINE_API uint32_t PLIB_GLCD_LayerStartYGet(GLCD_MODULE_ID index, GLCD_LAYER_ID layerId)
{
     return GLCD_LayerStartYGet_Default(index, layerId);
}

PLIB_INLINE_API bool PLIB_GLCD_ExistsLayerSizeXY(GLCD_MODULE_ID index)
{
     return GLCD_ExistsLayerSizeXY_Default(index);
}

PLIB_INLINE_API void PLIB_GLCD_LayerSizeXYSet(GLCD_MODULE_ID index, GLCD_LAYER_ID layerId, uint32_t sizeX, uint32_t sizeY)
{
     GLCD_LayerSizeXYSet_Default(index, layerId, sizeX, sizeY);
}

PLIB_INLINE_API uint32_t PLIB_GLCD_LayerSizeXGet(GLCD_MODULE_ID index, GLCD_LAYER_ID layerId)
{
     return GLCD_LayerSizeXGet_Default(index, layerId);
}

PLIB_INLINE_API uint32_t PLIB_GLCD_LayerSizeYGet(GLCD_MODULE_ID index, GLCD_LAYER_ID layerId)
{
     return GLCD_LayerSizeYGet_Default(index, layerId);
}

PLIB_INLINE_API bool PLIB_GLCD_ExistsLayerBaseAddress(GLCD_MODULE_ID index)
{
     return GLCD_ExistsLayerBaseAddress_Default(index);
}

PLIB_INLINE_API void PLIB_GLCD_LayerBaseAddressSet(GLCD_MODULE_ID index, GLCD_LAYER_ID layerId, uint32_t baseAddress)
{
     GLCD_LayerBaseAddressSet_Default(index, layerId, baseAddress);
}

PLIB_INLINE_API uint32_t PLIB_GLCD_LayerBaseAddressGet(GLCD_MODULE_ID index, GLCD_LAYER_ID layerId)
{
     return GLCD_LayerBaseAddressGet_Default(index, layerId);
}

PLIB_INLINE_API bool PLIB_GLCD_ExistsLayerStride(GLCD_MODULE_ID index)
{
     return GLCD_ExistsLayerStride_Default(index);
}

PLIB_INLINE_API void PLIB_GLCD_LayerStrideSet(GLCD_MODULE_ID index, GLCD_LAYER_ID layerId, uint32_t stride)
{
     GLCD_LayerStrideSet_Default(index, layerId, stride);
}

PLIB_INLINE_API uint32_t PLIB_GLCD_LayerStrideGet(GLCD_MODULE_ID index, GLCD_LAYER_ID layerId)
{
     return GLCD_LayerStrideGet_Default(index, layerId);
}

PLIB_INLINE_API bool PLIB_GLCD_ExistsLayerResXY(GLCD_MODULE_ID index)
{
     return GLCD_ExistsLayerResXY_Default(index);
}

PLIB_INLINE_API void PLIB_GLCD_LayerResXYSet(GLCD_MODULE_ID index, GLCD_LAYER_ID layerId, uint32_t resolutionX, uint32_t resolutionY)
{
     GLCD_LayerResXYSet_Default(index, layerId, resolutionX, resolutionY);
}

PLIB_INLINE_API uint32_t PLIB_GLCD_LayerResXGet(GLCD_MODULE_ID index, GLCD_LAYER_ID layerId)
{
     return GLCD_LayerResXGet_Default(index, layerId);
}

PLIB_INLINE_API uint32_t PLIB_GLCD_LayerResYGet(GLCD_MODULE_ID index, GLCD_LAYER_ID layerId)
{
     return GLCD_LayerResYGet_Default(index, layerId);
}

PLIB_INLINE_API bool PLIB_GLCD_ExistsHSyncInterruptEnable(GLCD_MODULE_ID index)
{
     return GLCD_ExistsHSyncInterruptEnable_Default(index);
}

PLIB_INLINE_API void PLIB_GLCD_HSyncInterruptEnable(GLCD_MODULE_ID index)
{
     GLCD_HSyncInterruptEnable_Default(index);
}

PLIB_INLINE_API void PLIB_GLCD_HSyncInterruptDisable(GLCD_MODULE_ID index)
{
     GLCD_HSyncInterruptDisable_Default(index);
}

PLIB_INLINE_API bool PLIB_GLCD_HSyncInterruptIsEnabled(GLCD_MODULE_ID index)
{
     return GLCD_HSyncInterruptIsEnabled_Default(index);
}

PLIB_INLINE_API bool PLIB_GLCD_ExistsVSyncInterruptEnable(GLCD_MODULE_ID index)
{
     return GLCD_ExistsVSyncInterruptEnable_Default(index);
}

PLIB_INLINE_API void PLIB_GLCD_VSyncInterruptEnable(GLCD_MODULE_ID index)
{
     GLCD_VSyncInterruptEnable_Default(index);
}

PLIB_INLINE_API void PLIB_GLCD_VSyncInterruptDisable(GLCD_MODULE_ID index)
{
     GLCD_VSyncInterruptDisable_Default(index);
}

PLIB_INLINE_API bool PLIB_GLCD_VSyncInterruptIsEnabled(GLCD_MODULE_ID index)
{
     return GLCD_VSyncInterruptIsEnabled_Default(index);
}

PLIB_INLINE_API bool PLIB_GLCD_ExistsIRQTriggerControl(GLCD_MODULE_ID index)
{
     return GLCD_ExistsIRQTriggerControl_Default(index);
}

PLIB_INLINE_API void PLIB_GLCD_IRQTriggerControlSet(GLCD_MODULE_ID index, GLCD_IRQ_TRIGGER_CONTROL irqControl)
{
     GLCD_IRQTriggerControlSet_Default(index, irqControl);
}

PLIB_INLINE_API GLCD_IRQ_TRIGGER_CONTROL PLIB_GLCD_IRQTriggerControlGet(GLCD_MODULE_ID index)
{
     return GLCD_IRQTriggerControlGet_Default(index);
}

PLIB_INLINE_API bool PLIB_GLCD_ExistsIsVerticalBlankingActive(GLCD_MODULE_ID index)
{
     return GLCD_ExistsIsVerticalBlankingActive_Default(index);
}

PLIB_INLINE_API bool PLIB_GLCD_IsVerticalBlankingActive(GLCD_MODULE_ID index)
{
     return GLCD_IsVerticalBlankingActive_Default(index);
}

PLIB_INLINE_API bool PLIB_GLCD_ExistsDESignalLevel(GLCD_MODULE_ID index)
{
     return GLCD_ExistsDESignalLevel_Default(index);
}

PLIB_INLINE_API bool PLIB_GLCD_DESignalLevelGet(GLCD_MODULE_ID index)
{
     return GLCD_DESignalLevelGet_Default(index);
}

PLIB_INLINE_API bool PLIB_GLCD_ExistsHSyncSignalLevel(GLCD_MODULE_ID index)
{
     return GLCD_ExistsHSyncSignalLevel_Default(index);
}

PLIB_INLINE_API bool PLIB_GLCD_HSyncSignalLevelGet(GLCD_MODULE_ID index)
{
     return GLCD_HSyncSignalLevelGet_Default(index);
}

PLIB_INLINE_API bool PLIB_GLCD_ExistsVSyncSignalLevel(GLCD_MODULE_ID index)
{
     return GLCD_ExistsVSyncSignalLevel_Default(index);
}

PLIB_INLINE_API bool PLIB_GLCD_VSyncSignalLevelGet(GLCD_MODULE_ID index)
{
     return GLCD_VSyncSignalLevelGet_Default(index);
}

PLIB_INLINE_API bool PLIB_GLCD_ExistsIsLastRow(GLCD_MODULE_ID index)
{
     return GLCD_ExistsIsLastRow_Default(index);
}

PLIB_INLINE_API bool PLIB_GLCD_IsLastRow(GLCD_MODULE_ID index)
{
     return GLCD_IsLastRow_Default(index);
}

PLIB_INLINE_API bool PLIB_GLCD_ExistsGlobalColorLUT(GLCD_MODULE_ID index)
{
     return GLCD_ExistsGlobalColorLUT_Default(index);
}

PLIB_INLINE_API void PLIB_GLCD_GlobalColorLUTSet(GLCD_MODULE_ID index, uint32_t* globalLUT)
{
     GLCD_GlobalColorLUTSet_Default(index, globalLUT);
}

PLIB_INLINE_API uint32_t PLIB_GLCD_GlobalColorLUTGet(GLCD_MODULE_ID index, uint32_t lutIndex)
{
     return GLCD_GlobalColorLUTGet_Default(index, lutIndex);
}

PLIB_INLINE_API bool PLIB_GLCD_ExistsCursorData(GLCD_MODULE_ID index)
{
     return GLCD_ExistsCursorData_Default(index);
}

PLIB_INLINE_API void PLIB_GLCD_CursorDataSet(GLCD_MODULE_ID index, uint32_t* cursorData)
{
     GLCD_CursorDataSet_Default(index, cursorData);
}

PLIB_INLINE_API uint32_t PLIB_GLCD_CursorDataGet(GLCD_MODULE_ID index, uint32_t dataIndex)
{
     return GLCD_CursorDataGet_Default(index, dataIndex);
}

PLIB_INLINE_API bool PLIB_GLCD_ExistsCursorLUT(GLCD_MODULE_ID index)
{
     return GLCD_ExistsCursorLUT_Default(index);
}

PLIB_INLINE_API void PLIB_GLCD_CursorLUTSet(GLCD_MODULE_ID index, uint32_t* cursorLUT)
{
     GLCD_CursorLUTSet_Default(index, cursorLUT);
}

PLIB_INLINE_API uint32_t PLIB_GLCD_CursorLUTGet(GLCD_MODULE_ID index, uint32_t lutIndex)
{
     return GLCD_CursorLUTGet_Default(index, lutIndex);
}

#endif
