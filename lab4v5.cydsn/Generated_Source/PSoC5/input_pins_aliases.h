/*******************************************************************************
* File Name: input_pins.h  
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

#if !defined(CY_PINS_input_pins_ALIASES_H) /* Pins input_pins_ALIASES_H */
#define CY_PINS_input_pins_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define input_pins_0			(input_pins__0__PC)
#define input_pins_0_INTR	((uint16)((uint16)0x0001u << input_pins__0__SHIFT))

#define input_pins_1			(input_pins__1__PC)
#define input_pins_1_INTR	((uint16)((uint16)0x0001u << input_pins__1__SHIFT))

#define input_pins_2			(input_pins__2__PC)
#define input_pins_2_INTR	((uint16)((uint16)0x0001u << input_pins__2__SHIFT))

#define input_pins_3			(input_pins__3__PC)
#define input_pins_3_INTR	((uint16)((uint16)0x0001u << input_pins__3__SHIFT))

#define input_pins_INTR_ALL	 ((uint16)(input_pins_0_INTR| input_pins_1_INTR| input_pins_2_INTR| input_pins_3_INTR))

#endif /* End Pins input_pins_ALIASES_H */


/* [] END OF FILE */
