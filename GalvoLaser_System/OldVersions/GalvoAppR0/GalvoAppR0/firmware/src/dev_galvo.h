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

#ifndef _DEV_GALVO_H    /* Guard against multiple inclusion */
#define _DEV_GALVO_H


/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */
#include "dev_dac_io.h"
#include "dev_adc_io.h"

/* Provide C++ Compatibility */
#ifdef __cplusplus
extern "C" {
#endif


    /* ************************************************************************** */
    /* ************************************************************************** */
    /* Section: Constants                                                         */
    /* ************************************************************************** */
    /* ************************************************************************** */

#define X_AXIS DRV_SPI_INDEX_0
#define Y_AXIS DRV_SPI_INDEX_1
#define DAC_UPDATE_PERIOD_uS 10.0
#define DAC_UPDATE_PERIOD_COUNTS 117
#define GALVO_SPEED_DEFAULT 13.5
#define GALVO_JUNK_READ 0x80000
    
    // *****************************************************************************
    // *****************************************************************************
    // Section: Data Types
    // *****************************************************************************
    // *****************************************************************************
    typedef uint8_t GALVO_AXIS_INDEX;

    typedef enum {
        GALVO_STATE_INIT,
        GALVO_STATE_START_UP,
        GALVO_STATE_IDLE,
        GALVO_STATE_WRITE_ROUTINE,
        GALVO_STATE_WRITE_ROUTINE_CONFIRM,
        GALVO_STATE_READ_ROUTINE,
        GALVO_STATE_READ_ROUTINE_CONFIRM
    } GALVO_STATES;

    typedef enum {
        ADC_MEASUREMENT_START = 2,
        ADC_MEASUREMENT_END = 3,
    } GALVO_MEASUREMENT_TYPE;

    typedef struct {
        uint32_t start;
        uint32_t end;
        bool new_startVal;
        bool new_endVal;
        GALVO_MEASUREMENT_TYPE type;
    } GALVO_MEASUREMENT;

    typedef struct GALVO_MOVE_DATA {
        uint32_t to_x;
        uint32_t to_y;
        uint32_t from_x;
        uint32_t from_y;
        uint32_t step_x;
        uint32_t step_y;
        uint32_t speed;
        bool x_enabled;
        bool y_enabled;
    } _GALVO_MOVE_DATA;

    typedef struct {
        uint32_t position;
        uint32_t finalPosition;
        uint32_t stepSize;
        GALVO_MEASUREMENT Measurement;
    } GALVO_AXIS;

    typedef struct {
        GALVO_STATES volatile state;
        bool TX_ProcessFinished;
        bool RX_ProcessFinished;
        GALVO_AXIS Axis[2];
        bool enabled;
    } GALVO_OBJ;

    typedef struct {
        bool enabled;
        uint32_t power;
    } LASER_OBJ;



    /* ************************************************************************** */
    /* ************************************************************************** */
    // Section: Local Functions                                                   */
    /* ************************************************************************** */

    void ComputeStepSize(_GALVO_MOVE_DATA * mData);
    void Galvo_Axis_Write(GALVO_AXIS_INDEX axis, bool *flag);
    void Galvo_Write_Routine(void);
    void Galvo_Write_Routine_Confirm(void);

    void Galvo_Read_Routine(void);
    void Galvo_Read_Routine_Confirm(void);
    void Galvo_Set_Measurement(GALVO_AXIS_INDEX index, uint32_t val);

    // *****************************************************************************
    // *****************************************************************************
    // Section: Interface Functions
    // *****************************************************************************
    // *****************************************************************************

    void Galvo_Set_State(GALVO_STATES gState);
    GALVO_STATES Galvo_Get_State();

    void Galvo_Set_CurrentPosition(GALVO_AXIS_INDEX index, const uint32_t value);
    uint32_t Galvo_Get_Position(GALVO_AXIS_INDEX index);

    void Galvo_Set_FinalPosition(GALVO_AXIS_INDEX index, const uint32_t value);
    uint32_t Galvo_Get_FinalPosition(GALVO_AXIS_INDEX index);

    void Galvo_Set_StepSize(GALVO_AXIS_INDEX index, uint32_t step);
    uint32_t Galvo_Get_StepSize(GALVO_AXIS_INDEX index);


    void Galvo_Set_TX_ProcessComplete(void);
    bool Galvo_TX_ProcessComplete(void);

    void Galvo_Set_RX_ProcessComplete(void);
    bool Galvo_RX_ProcessComplete(void);

    void Galvo_Enable(void);
    void Galvo_Disable(void);
    bool Galvo_Is_Enabled(void);


    bool Galvo_MeasurementAvailable(GALVO_AXIS_INDEX index, GALVO_MEASUREMENT_TYPE type);
    uint32_t Galvo_Get_Measurement(GALVO_AXIS_INDEX index, GALVO_MEASUREMENT_TYPE type);

    /* ************************* Public Processes ******************************* */

    void Galvo_Initialize();
    DEV_HANDLE Galvo_Open();

    void Galvo_Add_TX_Process(_GALVO_MOVE_DATA * m);
    void Galvo_TX_Process(void);

    void Galvo_Add_RX_Process(GALVO_MEASUREMENT_TYPE mType);
    void Galvo_RX_Process(void);


    /* Provide C++ Compatibility */
#ifdef __cplusplus
}
#endif

#endif /* _EXAMPLE_FILE_NAME_H */

/* *****************************************************************************
 End of File
 */
