/*******************************************************************************
* File Name: Clock20ms.h
* Version 2.20
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_Clock20ms_H)
#define CY_CLOCK_Clock20ms_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
* Conditional Compilation Parameters
***************************************/

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component cy_clock_v2_20 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5LP) */


/***************************************
*        Function Prototypes
***************************************/

void Clock20ms_Start(void) ;
void Clock20ms_Stop(void) ;

#if(CY_PSOC3 || CY_PSOC5LP)
void Clock20ms_StopBlock(void) ;
#endif /* (CY_PSOC3 || CY_PSOC5LP) */

void Clock20ms_StandbyPower(uint8 state) ;
void Clock20ms_SetDividerRegister(uint16 clkDivider, uint8 restart) 
                                ;
uint16 Clock20ms_GetDividerRegister(void) ;
void Clock20ms_SetModeRegister(uint8 modeBitMask) ;
void Clock20ms_ClearModeRegister(uint8 modeBitMask) ;
uint8 Clock20ms_GetModeRegister(void) ;
void Clock20ms_SetSourceRegister(uint8 clkSource) ;
uint8 Clock20ms_GetSourceRegister(void) ;
#if defined(Clock20ms__CFG3)
void Clock20ms_SetPhaseRegister(uint8 clkPhase) ;
uint8 Clock20ms_GetPhaseRegister(void) ;
#endif /* defined(Clock20ms__CFG3) */

#define Clock20ms_Enable()                       Clock20ms_Start()
#define Clock20ms_Disable()                      Clock20ms_Stop()
#define Clock20ms_SetDivider(clkDivider)         Clock20ms_SetDividerRegister(clkDivider, 1u)
#define Clock20ms_SetDividerValue(clkDivider)    Clock20ms_SetDividerRegister((clkDivider) - 1u, 1u)
#define Clock20ms_SetMode(clkMode)               Clock20ms_SetModeRegister(clkMode)
#define Clock20ms_SetSource(clkSource)           Clock20ms_SetSourceRegister(clkSource)
#if defined(Clock20ms__CFG3)
#define Clock20ms_SetPhase(clkPhase)             Clock20ms_SetPhaseRegister(clkPhase)
#define Clock20ms_SetPhaseValue(clkPhase)        Clock20ms_SetPhaseRegister((clkPhase) + 1u)
#endif /* defined(Clock20ms__CFG3) */


/***************************************
*             Registers
***************************************/

/* Register to enable or disable the clock */
#define Clock20ms_CLKEN              (* (reg8 *) Clock20ms__PM_ACT_CFG)
#define Clock20ms_CLKEN_PTR          ((reg8 *) Clock20ms__PM_ACT_CFG)

/* Register to enable or disable the clock */
#define Clock20ms_CLKSTBY            (* (reg8 *) Clock20ms__PM_STBY_CFG)
#define Clock20ms_CLKSTBY_PTR        ((reg8 *) Clock20ms__PM_STBY_CFG)

/* Clock LSB divider configuration register. */
#define Clock20ms_DIV_LSB            (* (reg8 *) Clock20ms__CFG0)
#define Clock20ms_DIV_LSB_PTR        ((reg8 *) Clock20ms__CFG0)
#define Clock20ms_DIV_PTR            ((reg16 *) Clock20ms__CFG0)

/* Clock MSB divider configuration register. */
#define Clock20ms_DIV_MSB            (* (reg8 *) Clock20ms__CFG1)
#define Clock20ms_DIV_MSB_PTR        ((reg8 *) Clock20ms__CFG1)

/* Mode and source configuration register */
#define Clock20ms_MOD_SRC            (* (reg8 *) Clock20ms__CFG2)
#define Clock20ms_MOD_SRC_PTR        ((reg8 *) Clock20ms__CFG2)

#if defined(Clock20ms__CFG3)
/* Analog clock phase configuration register */
#define Clock20ms_PHASE              (* (reg8 *) Clock20ms__CFG3)
#define Clock20ms_PHASE_PTR          ((reg8 *) Clock20ms__CFG3)
#endif /* defined(Clock20ms__CFG3) */


/**************************************
*       Register Constants
**************************************/

/* Power manager register masks */
#define Clock20ms_CLKEN_MASK         Clock20ms__PM_ACT_MSK
#define Clock20ms_CLKSTBY_MASK       Clock20ms__PM_STBY_MSK

/* CFG2 field masks */
#define Clock20ms_SRC_SEL_MSK        Clock20ms__CFG2_SRC_SEL_MASK
#define Clock20ms_MODE_MASK          (~(Clock20ms_SRC_SEL_MSK))

#if defined(Clock20ms__CFG3)
/* CFG3 phase mask */
#define Clock20ms_PHASE_MASK         Clock20ms__CFG3_PHASE_DLY_MASK
#endif /* defined(Clock20ms__CFG3) */

#endif /* CY_CLOCK_Clock20ms_H */


/* [] END OF FILE */
