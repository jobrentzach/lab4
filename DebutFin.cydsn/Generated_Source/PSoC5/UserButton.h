/*******************************************************************************
* File Name: UserButton.h  
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

#if !defined(CY_PINS_UserButton_H) /* Pins UserButton_H */
#define CY_PINS_UserButton_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "UserButton_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 UserButton__PORT == 15 && ((UserButton__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    UserButton_Write(uint8 value);
void    UserButton_SetDriveMode(uint8 mode);
uint8   UserButton_ReadDataReg(void);
uint8   UserButton_Read(void);
void    UserButton_SetInterruptMode(uint16 position, uint16 mode);
uint8   UserButton_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the UserButton_SetDriveMode() function.
     *  @{
     */
        #define UserButton_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define UserButton_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define UserButton_DM_RES_UP          PIN_DM_RES_UP
        #define UserButton_DM_RES_DWN         PIN_DM_RES_DWN
        #define UserButton_DM_OD_LO           PIN_DM_OD_LO
        #define UserButton_DM_OD_HI           PIN_DM_OD_HI
        #define UserButton_DM_STRONG          PIN_DM_STRONG
        #define UserButton_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define UserButton_MASK               UserButton__MASK
#define UserButton_SHIFT              UserButton__SHIFT
#define UserButton_WIDTH              1u

/* Interrupt constants */
#if defined(UserButton__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in UserButton_SetInterruptMode() function.
     *  @{
     */
        #define UserButton_INTR_NONE      (uint16)(0x0000u)
        #define UserButton_INTR_RISING    (uint16)(0x0001u)
        #define UserButton_INTR_FALLING   (uint16)(0x0002u)
        #define UserButton_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define UserButton_INTR_MASK      (0x01u) 
#endif /* (UserButton__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define UserButton_PS                     (* (reg8 *) UserButton__PS)
/* Data Register */
#define UserButton_DR                     (* (reg8 *) UserButton__DR)
/* Port Number */
#define UserButton_PRT_NUM                (* (reg8 *) UserButton__PRT) 
/* Connect to Analog Globals */                                                  
#define UserButton_AG                     (* (reg8 *) UserButton__AG)                       
/* Analog MUX bux enable */
#define UserButton_AMUX                   (* (reg8 *) UserButton__AMUX) 
/* Bidirectional Enable */                                                        
#define UserButton_BIE                    (* (reg8 *) UserButton__BIE)
/* Bit-mask for Aliased Register Access */
#define UserButton_BIT_MASK               (* (reg8 *) UserButton__BIT_MASK)
/* Bypass Enable */
#define UserButton_BYP                    (* (reg8 *) UserButton__BYP)
/* Port wide control signals */                                                   
#define UserButton_CTL                    (* (reg8 *) UserButton__CTL)
/* Drive Modes */
#define UserButton_DM0                    (* (reg8 *) UserButton__DM0) 
#define UserButton_DM1                    (* (reg8 *) UserButton__DM1)
#define UserButton_DM2                    (* (reg8 *) UserButton__DM2) 
/* Input Buffer Disable Override */
#define UserButton_INP_DIS                (* (reg8 *) UserButton__INP_DIS)
/* LCD Common or Segment Drive */
#define UserButton_LCD_COM_SEG            (* (reg8 *) UserButton__LCD_COM_SEG)
/* Enable Segment LCD */
#define UserButton_LCD_EN                 (* (reg8 *) UserButton__LCD_EN)
/* Slew Rate Control */
#define UserButton_SLW                    (* (reg8 *) UserButton__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define UserButton_PRTDSI__CAPS_SEL       (* (reg8 *) UserButton__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define UserButton_PRTDSI__DBL_SYNC_IN    (* (reg8 *) UserButton__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define UserButton_PRTDSI__OE_SEL0        (* (reg8 *) UserButton__PRTDSI__OE_SEL0) 
#define UserButton_PRTDSI__OE_SEL1        (* (reg8 *) UserButton__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define UserButton_PRTDSI__OUT_SEL0       (* (reg8 *) UserButton__PRTDSI__OUT_SEL0) 
#define UserButton_PRTDSI__OUT_SEL1       (* (reg8 *) UserButton__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define UserButton_PRTDSI__SYNC_OUT       (* (reg8 *) UserButton__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(UserButton__SIO_CFG)
    #define UserButton_SIO_HYST_EN        (* (reg8 *) UserButton__SIO_HYST_EN)
    #define UserButton_SIO_REG_HIFREQ     (* (reg8 *) UserButton__SIO_REG_HIFREQ)
    #define UserButton_SIO_CFG            (* (reg8 *) UserButton__SIO_CFG)
    #define UserButton_SIO_DIFF           (* (reg8 *) UserButton__SIO_DIFF)
#endif /* (UserButton__SIO_CFG) */

/* Interrupt Registers */
#if defined(UserButton__INTSTAT)
    #define UserButton_INTSTAT            (* (reg8 *) UserButton__INTSTAT)
    #define UserButton_SNAP               (* (reg8 *) UserButton__SNAP)
    
	#define UserButton_0_INTTYPE_REG 		(* (reg8 *) UserButton__0__INTTYPE)
#endif /* (UserButton__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_UserButton_H */


/* [] END OF FILE */
