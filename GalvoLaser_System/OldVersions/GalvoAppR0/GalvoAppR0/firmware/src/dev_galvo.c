/* ************************************************************************** */
/* ************************************************************************** */

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

#include "dev_galvo.h"

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: File Scope or Global Data                                         */
/* ************************************************************************** */
/* ************************************************************************** */

GALVO_OBJ gGalvoObj;

/* ************************************************************************** */
/* ************************************************************************** */
// Section: Local Functions                                                   */
/* ************************************************************************** */
/* ************************************************************************** */

/* ComputerStepSize : Returns the number of [DAC counts] 
 * (0x0 to 0x3FFFF Full Scale) the DAC'A'_currentValue is to be incremented by
 * for a single DAC update cycle */

void ComputeStepSize(_GALVO_MOVE_DATA * mData) {
    uint32_t delta_X = 0;
    uint32_t delta_Y = 0;

    if (mData->to_x > mData->from_x)
        delta_X = mData->to_x - mData->from_x;
    else if (mData->to_x < mData->from_x)
        delta_X = mData->from_x - mData->to_x;

    if (mData->to_y > mData->from_y)
        delta_Y = mData->to_y - mData->from_y;
    else if (mData->to_y < mData->from_y)
        delta_Y = mData->from_y - mData->to_y;

    uint32_t distance = ((uint32_t) sqrt((float) delta_X * (float) delta_X
            + (float) delta_Y * (float) delta_Y)) << 10;
    uint32_t duration = (((distance)/ (mData->speed)) << 10);
    uint32_t numIncrements = (uint32_t) (((float) duration) / DAC_UPDATE_PERIOD_uS);
    if (numIncrements < 1)
        numIncrements = 1;

    if ((mData->x_enabled) && (delta_X > 0) && (mData->speed > 0)) {
        mData->step_x = ((delta_X << 10) / numIncrements);
    } else
        mData-> step_x = 0;


    if ((mData->y_enabled) && (delta_Y > 0) && (mData->speed > 0)) {
        mData->step_y = ((delta_Y << 10) / numIncrements);
    } else
        mData-> step_y = 0;
}

void Galvo_Axis_Write(GALVO_AXIS_INDEX axis, bool *flag) {
    GALVO_AXIS *pObj = &(gGalvoObj.Axis[axis]);

    uint32_t tempVal = pObj->position;
    uint32_t endVal = pObj->finalPosition;

    if (tempVal < endVal) {
        *flag = 0;
        tempVal += pObj->stepSize;
        if (tempVal > endVal) {
            tempVal = endVal;
            *flag &= 1;
        }
    } else if (tempVal > endVal) {
        *flag = 0;
        tempVal -= pObj->stepSize;
        if (tempVal < endVal) {
            tempVal = endVal;
            *flag &= 1;
        }
    } else if (tempVal == endVal) {
        *flag &= 1;
    }
    DEV_DAC_Write(axis, tempVal);
    pObj->position = tempVal;
}

void Galvo_Write_Routine(void) {
    bool xFlag = 1;
    bool yFlag = 1;

    Galvo_Axis_Write(X_AXIS, &xFlag);
    Galvo_Axis_Write(Y_AXIS, &yFlag);
    if (xFlag && yFlag) {
        Galvo_Set_State(GALVO_STATE_WRITE_ROUTINE_CONFIRM);
    }
}

void Galvo_Write_Routine_Confirm(void) {
    GALVO_AXIS *xObj = &(gGalvoObj.Axis[X_AXIS]);
    GALVO_AXIS *yObj = &(gGalvoObj.Axis[Y_AXIS]);

    if ((xObj->position == xObj->finalPosition)
            && (yObj->position == yObj->finalPosition)) {
        DEV_DAC_Disconnect(DEV_DAC0_INDEX);
        DEV_DAC_Disconnect(DEV_DAC1_INDEX);
        Galvo_Set_TX_ProcessComplete();
    }
}

void Galvo_Read_Routine(void) {
    uint32_t tempVal0 = GALVO_JUNK_READ;
    uint32_t tempVal1 = GALVO_JUNK_READ;
    DEV_ADC_Tasks(DEV_ADC0_INDEX, &tempVal0);
    DEV_ADC_Tasks(DEV_ADC1_INDEX, &tempVal1);
    if ((tempVal0 != GALVO_JUNK_READ) && (tempVal1 != GALVO_JUNK_READ)) {
        Galvo_Set_Measurement(X_AXIS, tempVal0);
        Galvo_Set_Measurement(Y_AXIS, tempVal1);
        Galvo_Set_State(GALVO_STATE_READ_ROUTINE_CONFIRM);
    }
}

void Galvo_Read_Routine_Confirm(void) {
    DEV_ADC_Disconnect(DEV_ADC0_INDEX);
    DEV_ADC_Disconnect(DEV_ADC1_INDEX);
    Galvo_Set_RX_ProcessComplete();
}

void Galvo_Set_Measurement(GALVO_AXIS_INDEX index, uint32_t val) {
    switch (gGalvoObj.Axis[index].Measurement.type) {
        case ADC_MEASUREMENT_START:
        {
            gGalvoObj.Axis[index].Measurement.start = val;
            gGalvoObj.Axis[index].Measurement.new_startVal = 1;
            break;
        }
        case ADC_MEASUREMENT_END:
        {
            gGalvoObj.Axis[index].Measurement.end = val;
            gGalvoObj.Axis[index].Measurement.new_endVal = 1;
            break;
        }
        default:
            break;
    }
}

/* ************************************************************************** */
/* ************************************************************************** */
// Section: Interface Functions                                               */
/* ************************************************************************** */
/* ************************************************************************** */

/* ********************** Getters and Setters ******************************* */

void Galvo_Set_State(GALVO_STATES gState) {
    GALVO_OBJ *pObj = &gGalvoObj;
    pObj->state = gState;
}

GALVO_STATES Galvo_Get_State(void) {
    GALVO_OBJ *pObj = &gGalvoObj;
    return pObj->state;
}

void Galvo_Set_CurrentPosition(GALVO_AXIS_INDEX index, uint32_t value) {

    GALVO_AXIS *pObj = &(gGalvoObj.Axis[index]);
    pObj->position = value;
}

uint32_t Galvo_Get_Position(GALVO_AXIS_INDEX index) {
    GALVO_AXIS *pObj = &(gGalvoObj.Axis[index]);
    return (pObj->position);
}

void Galvo_Set_FinalPosition(GALVO_AXIS_INDEX index, uint32_t value) {

    GALVO_AXIS *pObj = &(gGalvoObj.Axis[index]);
    pObj->finalPosition = value;
}

uint32_t Galvo_Get_FinalPosition(GALVO_AXIS_INDEX index) {
    GALVO_AXIS *pObj = &(gGalvoObj.Axis[index]);
    return (pObj->finalPosition);
}

void Galvo_Set_StepSize(GALVO_AXIS_INDEX index, uint32_t step) {
    GALVO_AXIS *pObj = &(gGalvoObj.Axis[index]);
    pObj->stepSize = step;
}

uint32_t Galvo_Get_StepSize(GALVO_AXIS_INDEX index) {
    GALVO_AXIS *pObj = &(gGalvoObj.Axis[index]);
    return (pObj->stepSize);
}

void Galvo_Set_TX_ProcessComplete(void) {
    GALVO_OBJ *pObj = &gGalvoObj;
    pObj->TX_ProcessFinished = true;
    pObj->state = GALVO_STATE_IDLE;
}

bool Galvo_TX_ProcessComplete(void) {
    return gGalvoObj.TX_ProcessFinished;
}

void Galvo_Set_RX_ProcessComplete(void) {
    GALVO_OBJ *pObj = &gGalvoObj;
    pObj->RX_ProcessFinished = true;
    pObj->state = GALVO_STATE_IDLE;
}

bool Galvo_RX_ProcessComplete(void) {
    return gGalvoObj.RX_ProcessFinished;
}

bool Galvo_Is_Enabled(void) {
    return gGalvoObj.enabled;
}

void Galvo_Enable(void) {
    gGalvoObj.enabled = 1;
}

void Galvo_Disable(void) {
    gGalvoObj.enabled = 0;
}

bool Galvo_MeasurementAvailable(GALVO_AXIS_INDEX index, GALVO_MEASUREMENT_TYPE type) {
    GALVO_AXIS *pObj = &(gGalvoObj.Axis[index]);
    switch (type) {
        case ADC_MEASUREMENT_START:
        {
            return pObj->Measurement.new_startVal;
            break;
        }
        case ADC_MEASUREMENT_END:
        {
            return pObj->Measurement.new_endVal;
            break;
        }
        default:
            break;
    }
}

uint32_t Galvo_Get_Measurement(GALVO_AXIS_INDEX index, GALVO_MEASUREMENT_TYPE type) {
    GALVO_AXIS *pObj = &(gGalvoObj.Axis[index]);
    switch (type) {
        case ADC_MEASUREMENT_START:
        {
            return pObj->Measurement.start;
            break;
        }
        case ADC_MEASUREMENT_END:
        {
            return pObj->Measurement.end;
            break;
        }
        default:
            break;
    }
}

/* ************************* Public Processes ******************************* */

void Galvo_Initialize(void) {
    GALVO_OBJ *pObj = &gGalvoObj;
    pObj->state = GALVO_STATE_INIT;
    pObj->TX_ProcessFinished = false;
    pObj->RX_ProcessFinished = false;
    DEV_DAC_Initialize(DEV_DAC0_INDEX);
    DEV_DAC_Initialize(DEV_DAC1_INDEX);
}

DEV_HANDLE Galvo_Open(void) {
    GALVO_OBJ *pObj = &gGalvoObj;
    bool openFlag = 1;

    if (DEV_DAC_Open(DEV_DAC0_INDEX) != DEV_HANDLE_INVALID)
        openFlag &= 1;
    else
        openFlag = 0;

    if (DEV_DAC_Open(DEV_DAC0_INDEX) != DEV_HANDLE_INVALID)
        openFlag &= 1;
    else
        openFlag = 0;

    if (openFlag) {
        pObj->state = GALVO_STATE_START_UP;
        return DEV_GALVO_INDEX;
    } else
        return DEV_HANDLE_INVALID;
}

void Galvo_Add_TX_Process(_GALVO_MOVE_DATA * mData) {

    ComputeStepSize(mData);

    Galvo_Set_FinalPosition(X_AXIS, mData->to_x);
    Galvo_Set_StepSize(X_AXIS, mData->step_x);
    Galvo_Set_FinalPosition(Y_AXIS, mData->to_y);
    Galvo_Set_StepSize(Y_AXIS, mData->step_y);

    DEV_DAC_Connect(DEV_DAC0_INDEX);
    DEV_DAC_Connect(DEV_DAC1_INDEX);

    GALVO_OBJ *pObj = &gGalvoObj;
    pObj->state = GALVO_STATE_WRITE_ROUTINE;
    pObj->TX_ProcessFinished = false;
}

void Galvo_TX_Process(void) {
    if (DEV_DAC_Available()) {
        switch (Galvo_Get_State()) {
            case GALVO_STATE_WRITE_ROUTINE:
                Galvo_Write_Routine();
                break;
            case GALVO_STATE_WRITE_ROUTINE_CONFIRM:
                Galvo_Write_Routine_Confirm();
                break;
            default:
                break;
        }
    }
}

void Galvo_Add_RX_Process(GALVO_MEASUREMENT_TYPE mType) {
    GALVO_OBJ *pObj = &gGalvoObj;
    pObj->Axis[X_AXIS].Measurement.type = mType;
    pObj->Axis[Y_AXIS].Measurement.type = mType;
    pObj->RX_ProcessFinished = false;
    pObj->state = GALVO_STATE_READ_ROUTINE;
    DEV_ADC_Connect(DEV_ADC0_INDEX);
    DEV_ADC_Connect(DEV_ADC1_INDEX);
}

void Galvo_RX_Process(void) {
    if (DEV_ADC_Available()) {
        switch (Galvo_Get_State()) {
            case GALVO_STATE_READ_ROUTINE:
            {
                Galvo_Read_Routine();
                break;
            }
            case GALVO_STATE_READ_ROUTINE_CONFIRM:
            {
                Galvo_Read_Routine_Confirm();
                break;
            }
            default:
                break;
        }
    }
}

/* *****************************************************************************
 End of File
 */
