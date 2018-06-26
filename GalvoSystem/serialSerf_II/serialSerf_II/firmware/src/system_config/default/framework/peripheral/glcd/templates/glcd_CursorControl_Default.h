/*******************************************************************************
  GLCD Peripheral Library Template Implementation

  File Name:
    glcd_CursorControl_Default.h

  Summary:
    GLCD PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : CursorControl
    and its Variant : Default
    For following APIs :
        PLIB_GLCD_ExistsCursor
        PLIB_GLCD_CursorEnable
        PLIB_GLCD_CursorDisable
        PLIB_GLCD_CursorIsEnabled

*******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2013-2014 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
*******************************************************************************/

//DOM-IGNORE-END

#ifndef _GLCD_CURSORCONTROL_DEFAULT_H
#define _GLCD_CURSORCONTROL_DEFAULT_H

//******************************************************************************
/* Function :  GLCD_ExistsCursor_Default

  Summary:
    Implements Default variant of PLIB_GLCD_ExistsCursor

  Description:
    This template implements the Default variant of the PLIB_GLCD_ExistsCursor function.
*/
#define PLIB_GLCD_ExistsCursor PLIB_GLCD_ExistsCursor
PLIB_TEMPLATE bool GLCD_ExistsCursor_Default( GLCD_MODULE_ID index )
{
    return true;
}

//******************************************************************************
/* Function :  GLCD_CursorEnable_Default

  Summary:
    Implements Default variant of PLIB_GLCD_CursorEnable 

  Description:
    This template implements the Default variant of the PLIB_GLCD_CursorEnable function.
*/
PLIB_TEMPLATE void GLCD_CursorEnable_Default( GLCD_MODULE_ID index )
{
    GLCDMODEbits.CURSOREN = 1;
}

//******************************************************************************
/* Function :  GLCD_CursorDisable_Default

  Summary:
    Implements Default variant of PLIB_GLCD_CursorDisable 

  Description:
    This template implements the Default variant of the PLIB_GLCD_CursorDisable function.
*/
PLIB_TEMPLATE void GLCD_CursorDisable_Default( GLCD_MODULE_ID index )
{
    GLCDMODEbits.CURSOREN = 0;
}

//******************************************************************************
/* Function :  GLCD_CursorIsEnabled_Default

  Summary:
    Implements Default variant of PLIB_GLCD_CursorIsEnabled 

  Description:
    This template implements the Default variant of the PLIB_GLCD_CursorIsEnabled function.
*/
PLIB_TEMPLATE bool GLCD_CursorIsEnabled_Default( GLCD_MODULE_ID index )
{
    return GLCDMODEbits.CURSOREN;    
}

#endif /*_GLCD_CURSORCONTROL_DEFAULT_H*/

/******************************************************************************
 End of File
*/

