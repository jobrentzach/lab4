/*******************************************************************************
* File Name: C.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_C_ALIASES_H) /* Pins C_ALIASES_H */
#define CY_PINS_C_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define C_0			(C__0__PC)
#define C_0_INTR	((uint16)((uint16)0x0001u << C__0__SHIFT))

#define C_1			(C__1__PC)
#define C_1_INTR	((uint16)((uint16)0x0001u << C__1__SHIFT))

#define C_2			(C__2__PC)
#define C_2_INTR	((uint16)((uint16)0x0001u << C__2__SHIFT))

#define C_3			(C__3__PC)
#define C_3_INTR	((uint16)((uint16)0x0001u << C__3__SHIFT))

#define C_INTR_ALL	 ((uint16)(C_0_INTR| C_1_INTR| C_2_INTR| C_3_INTR))
#define C_C1			(C__C1__PC)
#define C_C1_INTR	((uint16)((uint16)0x0001u << C__0__SHIFT))

#define C_C2			(C__C2__PC)
#define C_C2_INTR	((uint16)((uint16)0x0001u << C__1__SHIFT))

#define C_C3			(C__C3__PC)
#define C_C3_INTR	((uint16)((uint16)0x0001u << C__2__SHIFT))

#define C_C4			(C__C4__PC)
#define C_C4_INTR	((uint16)((uint16)0x0001u << C__3__SHIFT))

#endif /* End Pins C_ALIASES_H */


/* [] END OF FILE */
