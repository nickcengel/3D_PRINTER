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

#include "app_host_client_interface.h"


/* ************************************************************************** */
/* ************************************************************************** */
/* Section: File Scope or Global Data                                         */
/* ************************************************************************** */
/* ************************************************************************** */
HCI_DATA gHCI_Data;
HCI_REG_ACTION gHCI_Action[HCI_PACKET_SIZE];


/* ************************************************************************** */
/* ************************************************************************** */
// Section: Local Functions                                                   */
/* ************************************************************************** */

/* ************************************************************************** */
//void sampleSwitch(void) {
//    int i;
//    switch (i) {
//        case JOB_TYPE:
//        {
//
//            break;
//        }
//        case COMMAND_TYPE:
//        {
//
//            break;
//        }
//        case REPLY_TYPE:
//        {
//
//            break;
//        }
//
//        case G_STATE:
//        {
//
//            break;
//        }
//        case G_SPEED:
//        {
//
//            break;
//        }
//        case X_POSITION:
//        {
//
//            break;
//        }
//        case Y_POSITION:
//        {
//
//            break;
//        }
//
//        case L_STATE:
//        {
//
//            break;
//        }
//        case L_POWER:
//        {
//
//            break;
//        }
//        case X_MEASUREMENT:
//        {
//
//            break;
//        }
//        case Y_MEASUREMENT:
//        {
//
//            break;
//        }
//        default:
//            break;
//    }
//}
/* ************************************************************************** */
/* ************************************************************************** */
// Section: Interface Functions                                               */
/* ************************************************************************** */

/* ************************************************************************** */

int32_t HCI_REG_Value(HCI_REG_INDEX r_index) {
    switch (r_index) {
        case JOB_NUMBER:
        {
            return gHCI_Data.jobNumber;
        }
        case JOB_TYPE:
        {
            return gHCI_Data.jobType;
        }
        case COMMAND_TYPE:
        {
            return gHCI_Data.commandType;
        }
        case REPLY_TYPE:
        {
            return gHCI_Data.replyType;
        }

        case G_STATE:
        {
            return gHCI_Data.galvoState;
        }
        case G_SPEED:
        {
            return gHCI_Data.galvoSpeed;
        }

        case X_START_POS:
        {
            return gHCI_Data.startPosition_x;
        }
        case X_END_POS:
        {
            return gHCI_Data.endPosition_x;
        }
        case Y_START_POS:
        {
            return gHCI_Data.startPosition_y;
        }
        case Y_END_POS:
        {
            return gHCI_Data.endPosition_y;
        }
        case X_MEASUREMENT:
        {
            return gHCI_Data.measurement_x;
        }
        case Y_MEASUREMENT:
        {
            return gHCI_Data.measurement_y;
        }
        case L_ARM:
        {
            return gHCI_Data.laserArmed;
        }
        case L_STATE:
        {
            return gHCI_Data.DAC_enabled_x;
        }
        case L_POWER:
        {
            return gHCI_Data.DAC_enabled_y;
        }
        case X_DAC_EN:
        {
            return gHCI_Data.ADC_enabled_x;
        }
        case Y_DAC_EN:
        {
            return gHCI_Data.ADC_enabled_y;
        }
        case X_ADC_EN:
        {
            return gHCI_Data.laserState;
        }
        case Y_ADC_EN:
        {
            return gHCI_Data.laserPower;
        }

        default:
            return HCI_INVALID_REG_INDEX;
    }
}

void HCI_REG_Set_Value(HCI_REG_INDEX r_index, int32_t r_value) {
    switch (r_index) {
        case JOB_TYPE:
        {
            gHCI_Data.jobType = r_value;
            break;
        }
        case COMMAND_TYPE:
        {
            gHCI_Data.commandType = r_value;
            break;
        }
        case REPLY_TYPE:
        {
            gHCI_Data.replyType = r_value;
            break;
        }
        case G_STATE:
        {
            gHCI_Data.galvoState = r_value;
            break;
        }
        case G_SPEED:
        {
            gHCI_Data.galvoSpeed = r_value;
            break;
        }
        case X_START_POS:
        {
            gHCI_Data.startPosition_x = r_value;
            break;
        }
        case X_END_POS:
        {
            gHCI_Data.endPosition_x = r_value;
            break;
        }
        case Y_START_POS:
        {
            gHCI_Data.startPosition_y = r_value;
            break;
        }
        case Y_END_POS:
        {
            gHCI_Data.endPosition_y = r_value;
            break;
        }
        case X_MEASUREMENT:
        {
            gHCI_Data.measurement_x = r_value;
            break;
        }
        case Y_MEASUREMENT:
        {
            gHCI_Data.measurement_y = r_value;
            break;
        }
        case L_ARM:
        {
            gHCI_Data.laserArmed = r_value;
            break;
        }
        case L_STATE:
        {
            gHCI_Data.laserState = r_value;
            break;
        }
        case L_POWER:
        {
            gHCI_Data.laserPower = r_value;
            break;
        }
        default:
            break;
    }
}

HCI_REG_ACTION HCI_REG_Action(HCI_REG_INDEX r_index) {
    if ((r_index >= 0)&&(r_index < HCI_PACKET_SIZE))
        return gHCI_Action[r_index];
    else
        return HCI_INVALID_REG_INDEX;
}

void HCI_REG_Set_Action(HCI_REG_INDEX r_index, HCI_REG_ACTION r_action) {
    if ((r_index >= 0)&&(r_index < HCI_PACKET_SIZE))
        gHCI_Action[r_index] = r_action;
}

void HCI_REG_Host_Add_Write(HCI_REG_INDEX r_index, int32_t r_value) {
    HCI_REG_Set_Action(r_index, REG_WRITE_REQSTD);
    HCI_REG_Set_Value(r_index, r_value);

}

void HCI_REG_Host_Add_Read(HCI_REG_INDEX r_index) {
    HCI_REG_Set_Action(r_index, REG_READ_REQSTD);
}

HCI_RX_PACKET_STATUS HCI_RX_Status(void) {
    return gHCI_Data.RX_status;
}

void HCI_Set_RX_Status(HCI_RX_PACKET_STATUS r_status) {
    gHCI_Data.RX_status = r_status;
}
/* *****************************************************************************
 End of File
 */
