/*******************************************************************************
* File Name: io_2.h  
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

#if !defined(CY_PINS_io_2_ALIASES_H) /* Pins io_2_ALIASES_H */
#define CY_PINS_io_2_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define io_2_0			(io_2__0__PC)
#define io_2_0_INTR	((uint16)((uint16)0x0001u << io_2__0__SHIFT))

#define io_2_INTR_ALL	 ((uint16)(io_2_0_INTR))

#endif /* End Pins io_2_ALIASES_H */


/* [] END OF FILE */
