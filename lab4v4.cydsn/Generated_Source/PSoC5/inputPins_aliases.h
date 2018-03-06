/*******************************************************************************
* File Name: inputPins.h  
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

#if !defined(CY_PINS_inputPins_ALIASES_H) /* Pins inputPins_ALIASES_H */
#define CY_PINS_inputPins_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define inputPins_0			(inputPins__0__PC)
#define inputPins_0_INTR	((uint16)((uint16)0x0001u << inputPins__0__SHIFT))

#define inputPins_1			(inputPins__1__PC)
#define inputPins_1_INTR	((uint16)((uint16)0x0001u << inputPins__1__SHIFT))

#define inputPins_2			(inputPins__2__PC)
#define inputPins_2_INTR	((uint16)((uint16)0x0001u << inputPins__2__SHIFT))

#define inputPins_3			(inputPins__3__PC)
#define inputPins_3_INTR	((uint16)((uint16)0x0001u << inputPins__3__SHIFT))

#define inputPins_INTR_ALL	 ((uint16)(inputPins_0_INTR| inputPins_1_INTR| inputPins_2_INTR| inputPins_3_INTR))

#endif /* End Pins inputPins_ALIASES_H */


/* [] END OF FILE */
