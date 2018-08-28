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

#ifndef _APP_HOST_CLIENT_INTERFACE_H    /* Guard against multiple inclusion */
#define _APP_HOST_CLIENT_INTERFACE_H


/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>

#define HCI_PACKET_SIZE 19
#define HCI_INVALID_REG_INDEX 24
/* Provide C++ Compatibility */
#ifdef __cplusplus
extern "C" {
#endif

    // *****************************************************************************
    // *****************************************************************************
    // Section: Data Types
    // *****************************************************************************
    // *****************************************************************************

    typedef enum {
        HOST_REQST_REPLY_UNKNWN,
        HOST_REQST_REPLY_OK_ONLY,
        HOST_REQST_REPLY_REG_DATA
    } HCI_REPLY_TYPE;

    typedef enum {
        HCI_JOB_UNKNWN,
        HCI_JOB_PENDING,
        HCI_LIST_JOBS,
        HCI_CLEAR_JOBS,
        HCI_ADD_JOB,
        HCI_RUN_JOB,
    } HCI_JOB_TYPE;

    typedef enum {
        DEV_STATE_UNKNWN,
        DEV_DISABLE,
        DEV_ENABLE,
        GVO_RELATIVE_MOVE,
        GVO_ABSOLUTE_MOVE
    } HCI_DEVICE_STATES;

    typedef enum {
        JOB_NUMBER = 0,
        JOB_TYPE,
        REPLY_TYPE,

        G_STATE,
        G_SPEED,
        X_START_POS,
        X_END_POS,

        Y_START_POS,
        Y_END_POS,
        X_MEASUREMENT,
        Y_MEASUREMENT,

        L_ARM,
        L_STATE,
        L_POWER,

        X_DAC_EN,
        Y_DAC_EN,
        X_ADC_EN,
        Y_ADC_EN,
    } HCI_REG_INDEX;

    typedef enum {
        NO_REG_ACTION,
        REG_READ_REQSTD,
        REG_WRITE_REQSTD,
    } HCI_REG_ACTION;

    typedef enum {
        HCI_RX_WAIT_FOR_PACKET,
        HCI_RX_LOOK_FOR_START,
        HCI_RX_LOOK_FOR_REG_INDEX,
        HCI_RX_LOOK_FOR_JOB_TYPE,
        HCI_RX_LOOK_FOR_CMD_TYPE,
        HCI_RX_LOOK_FOR_DATA,
        HCI_RX_COMPLETE
    } HCI_RX_PACKET_STATUS;

    typedef enum {
        HCI_TX_EMPTY,
        HCI_TX_PENDING,
        HCI_TX_COMPLETE
    } HCI_TX_PACKET_STATUS;

    typedef struct {
        uint16_t jobNumber;
        HCI_JOB_TYPE jobType;
        HCI_REPLY_TYPE replyType;

        HCI_DEVICE_STATES galvoState;
        uint32_t galvoSpeed;
        int32_t startPosition_x;
        int32_t endPosition_x;
        int32_t startPosition_y;
        int32_t endPosition_y;
        int32_t measurement_x;
        int32_t measurement_y;

        uint8_t laserArmed;
        uint8_t DAC_enabled_x;
        uint8_t DAC_enabled_y;
        uint8_t ADC_enabled_x;
        uint8_t ADC_enabled_y;


        HCI_DEVICE_STATES laserState;
        uint32_t laserPower;

        HCI_RX_PACKET_STATUS RX_status;
        HCI_TX_PACKET_STATUS TX_status;
    } HCI_DATA;

    // *****************************************************************************
    // *****************************************************************************
    // Section: Interface Functions
    // *****************************************************************************
    // *****************************************************************************

    void HCI_Clear_Data(void);
    void HCI_Clear_REG_Action(void);

    int32_t HCI_REG_Value(HCI_REG_INDEX r_index);
    void HCI_REG_Set_Value(HCI_REG_INDEX r_index, int32_t r_value);

    HCI_REG_ACTION HCI_REG_Action(HCI_REG_INDEX r_index);
    void HCI_REG_Set_Action(HCI_REG_INDEX r_index, HCI_REG_ACTION r_action);


    HCI_RX_PACKET_STATUS HCI_RX_Status(void);
    void HCI_Set_RX_Status(HCI_RX_PACKET_STATUS r_status);

    HCI_TX_PACKET_STATUS HCI_TX_Status(void);
    void HCI_Set_TX_Status(HCI_TX_PACKET_STATUS t_status);

    /* Provide C++ Compatibility */
#ifdef __cplusplus
}
#endif

#endif /* APP_HOST_CLIENT_INTERFACE */

/* *****************************************************************************
 End of File
 */
