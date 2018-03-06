/*******************************************************************************
* File Name: input_pins.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_input_pins_H) /* Pins input_pins_H */
#define CY_PINS_input_pins_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "input_pins_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 input_pins__PORT == 15 && ((input_pins__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    input_pins_Write(uint8 value);
void    input_pins_SetDriveMode(uint8 mode);
uint8   input_pins_ReadDataReg(void);
uint8   input_pins_Read(void);
void    input_pins_SetInterruptMode(uint16 position, uint16 mode);
uint8   input_pins_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the input_pins_SetDriveMode() function.
     *  @{
     */
        #define input_pins_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define input_pins_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define input_pins_DM_RES_UP          PIN_DM_RES_UP
        #define input_pins_DM_RES_DWN         PIN_DM_RES_DWN
        #define input_pins_DM_OD_LO           PIN_DM_OD_LO
        #define input_pins_DM_OD_HI           PIN_DM_OD_HI
        #define input_pins_DM_STRONG          PIN_DM_STRONG
        #define input_pins_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define input_pins_MASK               input_pins__MASK
#define input_pins_SHIFT              input_pins__SHIFT
#define input_pins_WIDTH              4u

/* Interrupt constants */
#if defined(input_pins__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in input_pins_SetInterruptMode() function.
     *  @{
     */
        #define input_pins_INTR_NONE      (uint16)(0x0000u)
        #define input_pins_INTR_RISING    (uint16)(0x0001u)
        #define input_pins_INTR_FALLING   (uint16)(0x0002u)
        #define input_pins_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define input_pins_INTR_MASK      (0x01u) 
#endif /* (input_pins__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define input_pins_PS                     (* (reg8 *) input_pins__PS)
/* Data Register */
#define input_pins_DR                     (* (reg8 *) input_pins__DR)
/* Port Number */
#define input_pins_PRT_NUM                (* (reg8 *) input_pins__PRT) 
/* Connect to Analog Globals */                                                  
#define input_pins_AG                     (* (reg8 *) input_pins__AG)                       
/* Analog MUX bux enable */
#define input_pins_AMUX                   (* (reg8 *) input_pins__AMUX) 
/* Bidirectional Enable */                                                        
#define input_pins_BIE                    (* (reg8 *) input_pins__BIE)
/* Bit-mask for Aliased Register Access */
#define input_pins_BIT_MASK               (* (reg8 *) input_pins__BIT_MASK)
/* Bypass Enable */
#define input_pins_BYP                    (* (reg8 *) input_pins__BYP)
/* Port wide control signals */                                                   
#define input_pins_CTL                    (* (reg8 *) input_pins__CTL)
/* Drive Modes */
#define input_pins_DM0                    (* (reg8 *) input_pins__DM0) 
#define input_pins_DM1                    (* (reg8 *) input_pins__DM1)
#define input_pins_DM2                    (* (reg8 *) input_pins__DM2) 
/* Input Buffer Disable Override */
#define input_pins_INP_DIS                (* (reg8 *) input_pins__INP_DIS)
/* LCD Common or Segment Drive */
#define input_pins_LCD_COM_SEG            (* (reg8 *) input_pins__LCD_COM_SEG)
/* Enable Segment LCD */
#define input_pins_LCD_EN                 (* (reg8 *) input_pins__LCD_EN)
/* Slew Rate Control */
#define input_pins_SLW                    (* (reg8 *) input_pins__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define input_pins_PRTDSI__CAPS_SEL       (* (reg8 *) input_pins__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define input_pins_PRTDSI__DBL_SYNC_IN    (* (reg8 *) input_pins__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define input_pins_PRTDSI__OE_SEL0        (* (reg8 *) input_pins__PRTDSI__OE_SEL0) 
#define input_pins_PRTDSI__OE_SEL1        (* (reg8 *) input_pins__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define input_pins_PRTDSI__OUT_SEL0       (* (reg8 *) input_pins__PRTDSI__OUT_SEL0) 
#define input_pins_PRTDSI__OUT_SEL1       (* (reg8 *) input_pins__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define input_pins_PRTDSI__SYNC_OUT       (* (reg8 *) input_pins__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(input_pins__SIO_CFG)
    #define input_pins_SIO_HYST_EN        (* (reg8 *) input_pins__SIO_HYST_EN)
    #define input_pins_SIO_REG_HIFREQ     (* (reg8 *) input_pins__SIO_REG_HIFREQ)
    #define input_pins_SIO_CFG            (* (reg8 *) input_pins__SIO_CFG)
    #define input_pins_SIO_DIFF           (* (reg8 *) input_pins__SIO_DIFF)
#endif /* (input_pins__SIO_CFG) */

/* Interrupt Registers */
#if defined(input_pins__INTSTAT)
    #define input_pins_INTSTAT            (* (reg8 *) input_pins__INTSTAT)
    #define input_pins_SNAP               (* (reg8 *) input_pins__SNAP)
    
	#define input_pins_0_INTTYPE_REG 		(* (reg8 *) input_pins__0__INTTYPE)
	#define input_pins_1_INTTYPE_REG 		(* (reg8 *) input_pins__1__INTTYPE)
	#define input_pins_2_INTTYPE_REG 		(* (reg8 *) input_pins__2__INTTYPE)
	#define input_pins_3_INTTYPE_REG 		(* (reg8 *) input_pins__3__INTTYPE)
#endif /* (input_pins__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_input_pins_H */


/* [] END OF FILE */
