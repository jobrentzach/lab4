/*******************************************************************************
* File Name: inputPins.h  
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

#if !defined(CY_PINS_inputPins_H) /* Pins inputPins_H */
#define CY_PINS_inputPins_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "inputPins_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 inputPins__PORT == 15 && ((inputPins__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    inputPins_Write(uint8 value);
void    inputPins_SetDriveMode(uint8 mode);
uint8   inputPins_ReadDataReg(void);
uint8   inputPins_Read(void);
void    inputPins_SetInterruptMode(uint16 position, uint16 mode);
uint8   inputPins_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the inputPins_SetDriveMode() function.
     *  @{
     */
        #define inputPins_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define inputPins_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define inputPins_DM_RES_UP          PIN_DM_RES_UP
        #define inputPins_DM_RES_DWN         PIN_DM_RES_DWN
        #define inputPins_DM_OD_LO           PIN_DM_OD_LO
        #define inputPins_DM_OD_HI           PIN_DM_OD_HI
        #define inputPins_DM_STRONG          PIN_DM_STRONG
        #define inputPins_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define inputPins_MASK               inputPins__MASK
#define inputPins_SHIFT              inputPins__SHIFT
#define inputPins_WIDTH              4u

/* Interrupt constants */
#if defined(inputPins__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in inputPins_SetInterruptMode() function.
     *  @{
     */
        #define inputPins_INTR_NONE      (uint16)(0x0000u)
        #define inputPins_INTR_RISING    (uint16)(0x0001u)
        #define inputPins_INTR_FALLING   (uint16)(0x0002u)
        #define inputPins_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define inputPins_INTR_MASK      (0x01u) 
#endif /* (inputPins__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define inputPins_PS                     (* (reg8 *) inputPins__PS)
/* Data Register */
#define inputPins_DR                     (* (reg8 *) inputPins__DR)
/* Port Number */
#define inputPins_PRT_NUM                (* (reg8 *) inputPins__PRT) 
/* Connect to Analog Globals */                                                  
#define inputPins_AG                     (* (reg8 *) inputPins__AG)                       
/* Analog MUX bux enable */
#define inputPins_AMUX                   (* (reg8 *) inputPins__AMUX) 
/* Bidirectional Enable */                                                        
#define inputPins_BIE                    (* (reg8 *) inputPins__BIE)
/* Bit-mask for Aliased Register Access */
#define inputPins_BIT_MASK               (* (reg8 *) inputPins__BIT_MASK)
/* Bypass Enable */
#define inputPins_BYP                    (* (reg8 *) inputPins__BYP)
/* Port wide control signals */                                                   
#define inputPins_CTL                    (* (reg8 *) inputPins__CTL)
/* Drive Modes */
#define inputPins_DM0                    (* (reg8 *) inputPins__DM0) 
#define inputPins_DM1                    (* (reg8 *) inputPins__DM1)
#define inputPins_DM2                    (* (reg8 *) inputPins__DM2) 
/* Input Buffer Disable Override */
#define inputPins_INP_DIS                (* (reg8 *) inputPins__INP_DIS)
/* LCD Common or Segment Drive */
#define inputPins_LCD_COM_SEG            (* (reg8 *) inputPins__LCD_COM_SEG)
/* Enable Segment LCD */
#define inputPins_LCD_EN                 (* (reg8 *) inputPins__LCD_EN)
/* Slew Rate Control */
#define inputPins_SLW                    (* (reg8 *) inputPins__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define inputPins_PRTDSI__CAPS_SEL       (* (reg8 *) inputPins__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define inputPins_PRTDSI__DBL_SYNC_IN    (* (reg8 *) inputPins__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define inputPins_PRTDSI__OE_SEL0        (* (reg8 *) inputPins__PRTDSI__OE_SEL0) 
#define inputPins_PRTDSI__OE_SEL1        (* (reg8 *) inputPins__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define inputPins_PRTDSI__OUT_SEL0       (* (reg8 *) inputPins__PRTDSI__OUT_SEL0) 
#define inputPins_PRTDSI__OUT_SEL1       (* (reg8 *) inputPins__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define inputPins_PRTDSI__SYNC_OUT       (* (reg8 *) inputPins__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(inputPins__SIO_CFG)
    #define inputPins_SIO_HYST_EN        (* (reg8 *) inputPins__SIO_HYST_EN)
    #define inputPins_SIO_REG_HIFREQ     (* (reg8 *) inputPins__SIO_REG_HIFREQ)
    #define inputPins_SIO_CFG            (* (reg8 *) inputPins__SIO_CFG)
    #define inputPins_SIO_DIFF           (* (reg8 *) inputPins__SIO_DIFF)
#endif /* (inputPins__SIO_CFG) */

/* Interrupt Registers */
#if defined(inputPins__INTSTAT)
    #define inputPins_INTSTAT            (* (reg8 *) inputPins__INTSTAT)
    #define inputPins_SNAP               (* (reg8 *) inputPins__SNAP)
    
	#define inputPins_0_INTTYPE_REG 		(* (reg8 *) inputPins__0__INTTYPE)
	#define inputPins_1_INTTYPE_REG 		(* (reg8 *) inputPins__1__INTTYPE)
	#define inputPins_2_INTTYPE_REG 		(* (reg8 *) inputPins__2__INTTYPE)
	#define inputPins_3_INTTYPE_REG 		(* (reg8 *) inputPins__3__INTTYPE)
#endif /* (inputPins__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_inputPins_H */


/* [] END OF FILE */
