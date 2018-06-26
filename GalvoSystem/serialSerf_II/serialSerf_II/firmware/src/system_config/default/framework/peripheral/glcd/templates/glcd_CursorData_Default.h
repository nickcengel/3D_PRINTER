/*******************************************************************************
  GLCD Peripheral Library Template Implementation

  File Name:
    glcd_CursorData_Default.h

  Summary:
    GLCD PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : CursorData
    and its Variant : Default
    For following APIs :
        PLIB_GLCD_ExistsCursorData
        PLIB_GLCD_CursorDataSet
        PLIB_GLCD_CursorDataGet

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

#ifndef _GLCD_CURSORDATA_DEFAULT_H
#define _GLCD_CURSORDATA_DEFAULT_H

//******************************************************************************
/* Function :  GLCD_ExistsCursorData_Default

  Summary:
    Implements Default variant of PLIB_GLCD_ExistsCursorData

  Description:
    This template implements the Default variant of the PLIB_GLCD_ExistsCursorData function.
*/
#define PLIB_GLCD_ExistsCursorData PLIB_GLCD_ExistsCursorData
PLIB_TEMPLATE bool GLCD_ExistsCursorData_Default( GLCD_MODULE_ID index )
{
    return true;
}

//******************************************************************************
/* Function :  GLCD_CursorDataSet_Default

  Summary:
    Implements Default variant of PLIB_GLCD_CursorDataSet 

  Description:
    This template implements the Default variant of the PLIB_GLCD_CursorDataSet function.
*/
PLIB_TEMPLATE void GLCD_CursorDataSet_Default( GLCD_MODULE_ID  index , 
                                               uint32_t      * cursorData )
{
    uint32_t pixelIndex = 0;
    
    for( pixelIndex = 0; pixelIndex < 128; pixelIndex++ )
    {
		*((SFR_TYPE *)(( (&GLCDCURDATA0) + pixelIndex )))  =  (cursorData[ pixelIndex ] );
    }
}

//******************************************************************************
/* Function :  GLCD_CursorDataGet_Default

  Summary:
    Implements Default variant of PLIB_GLCD_CursorDataGet 

  Description:
    This template implements the Default variant of the PLIB_GLCD_CursorDataGet function.
*/
PLIB_TEMPLATE uint32_t GLCD_CursorDataGet_Default( GLCD_MODULE_ID index , 
                                                   uint32_t dataIndex )
{
	return  ( *((SFR_TYPE *)(( (&GLCDCURDATA0) + dataIndex ))) );
}

#endif /*_GLCD_CURSORDATA_DEFAULT_H*/

/******************************************************************************
 End of File
*/

