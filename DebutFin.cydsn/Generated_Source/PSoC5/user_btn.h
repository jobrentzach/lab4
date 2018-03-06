/*******************************************************************************
* File Name: user_btn.h  
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

#if !defined(CY_PINS_user_btn_H) /* Pins user_btn_H */
#define CY_PINS_user_btn_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "user_btn_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 user_btn__PORT == 15 && ((user_btn__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    user_btn_Write(uint8 value);
void    user_btn_SetDriveMode(uint8 mode);
uint8   user_btn_ReadDataReg(void);
uint8   user_btn_Read(void);
void    user_btn_SetInterruptMode(uint16 position, uint16 mode);
uint8   user_btn_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the user_btn_SetDriveMode() function.
     *  @{
     */
        #define user_btn_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define user_btn_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define user_btn_DM_RES_UP          PIN_DM_RES_UP
        #define user_btn_DM_RES_DWN         PIN_DM_RES_DWN
        #define user_btn_DM_OD_LO           PIN_DM_OD_LO
        #define user_btn_DM_OD_HI           PIN_DM_OD_HI
        #define user_btn_DM_STRONG          PIN_DM_STRONG
        #define user_btn_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define user_btn_MASK               user_btn__MASK
#define user_btn_SHIFT              user_btn__SHIFT
#define user_btn_WIDTH              1u

/* Interrupt constants */
#if defined(user_btn__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in user_btn_SetInterruptMode() function.
     *  @{
     */
        #define user_btn_INTR_NONE      (uint16)(0x0000u)
        #define user_btn_INTR_RISING    (uint16)(0x0001u)
        #define user_btn_INTR_FALLING   (uint16)(0x0002u)
        #define user_btn_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define user_btn_INTR_MASK      (0x01u) 
#endif /* (user_btn__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define user_btn_PS                     (* (reg8 *) user_btn__PS)
/* Data Register */
#define user_btn_DR                     (* (reg8 *) user_btn__DR)
/* Port Number */
#define user_btn_PRT_NUM                (* (reg8 *) user_btn__PRT) 
/* Connect to Analog Globals */                                                  
#define user_btn_AG                     (* (reg8 *) user_btn__AG)                       
/* Analog MUX bux enable */
#define user_btn_AMUX                   (* (reg8 *) user_btn__AMUX) 
/* Bidirectional Enable */                                                        
#define user_btn_BIE                    (* (reg8 *) user_btn__BIE)
/* Bit-mask for Aliased Register Access */
#define user_btn_BIT_MASK               (* (reg8 *) user_btn__BIT_MASK)
/* Bypass Enable */
#define user_btn_BYP                    (* (reg8 *) user_btn__BYP)
/* Port wide control signals */                                                   
#define user_btn_CTL                    (* (reg8 *) user_btn__CTL)
/* Drive Modes */
#define user_btn_DM0                    (* (reg8 *) user_btn__DM0) 
#define user_btn_DM1                    (* (reg8 *) user_btn__DM1)
#define user_btn_DM2                    (* (reg8 *) user_btn__DM2) 
/* Input Buffer Disable Override */
#define user_btn_INP_DIS                (* (reg8 *) user_btn__INP_DIS)
/* LCD Common or Segment Drive */
#define user_btn_LCD_COM_SEG            (* (reg8 *) user_btn__LCD_COM_SEG)
/* Enable Segment LCD */
#define user_btn_LCD_EN                 (* (reg8 *) user_btn__LCD_EN)
/* Slew Rate Control */
#define user_btn_SLW                    (* (reg8 *) user_btn__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define user_btn_PRTDSI__CAPS_SEL       (* (reg8 *) user_btn__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define user_btn_PRTDSI__DBL_SYNC_IN    (* (reg8 *) user_btn__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define user_btn_PRTDSI__OE_SEL0        (* (reg8 *) user_btn__PRTDSI__OE_SEL0) 
#define user_btn_PRTDSI__OE_SEL1        (* (reg8 *) user_btn__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define user_btn_PRTDSI__OUT_SEL0       (* (reg8 *) user_btn__PRTDSI__OUT_SEL0) 
#define user_btn_PRTDSI__OUT_SEL1       (* (reg8 *) user_btn__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define user_btn_PRTDSI__SYNC_OUT       (* (reg8 *) user_btn__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(user_btn__SIO_CFG)
    #define user_btn_SIO_HYST_EN        (* (reg8 *) user_btn__SIO_HYST_EN)
    #define user_btn_SIO_REG_HIFREQ     (* (reg8 *) user_btn__SIO_REG_HIFREQ)
    #define user_btn_SIO_CFG            (* (reg8 *) user_btn__SIO_CFG)
    #define user_btn_SIO_DIFF           (* (reg8 *) user_btn__SIO_DIFF)
#endif /* (user_btn__SIO_CFG) */

/* Interrupt Registers */
#if defined(user_btn__INTSTAT)
    #define user_btn_INTSTAT            (* (reg8 *) user_btn__INTSTAT)
    #define user_btn_SNAP               (* (reg8 *) user_btn__SNAP)
    
	#define user_btn_0_INTTYPE_REG 		(* (reg8 *) user_btn__0__INTTYPE)
#endif /* (user_btn__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_user_btn_H */


/* [] END OF FILE */
