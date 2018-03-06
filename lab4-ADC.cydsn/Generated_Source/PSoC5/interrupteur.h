/*******************************************************************************
* File Name: interrupteur.h
* Version 1.70
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_ISR_interrupteur_H)
#define CY_ISR_interrupteur_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void interrupteur_Start(void);
void interrupteur_StartEx(cyisraddress address);
void interrupteur_Stop(void);

CY_ISR_PROTO(interrupteur_Interrupt);

void interrupteur_SetVector(cyisraddress address);
cyisraddress interrupteur_GetVector(void);

void interrupteur_SetPriority(uint8 priority);
uint8 interrupteur_GetPriority(void);

void interrupteur_Enable(void);
uint8 interrupteur_GetState(void);
void interrupteur_Disable(void);

void interrupteur_SetPending(void);
void interrupteur_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the interrupteur ISR. */
#define interrupteur_INTC_VECTOR            ((reg32 *) interrupteur__INTC_VECT)

/* Address of the interrupteur ISR priority. */
#define interrupteur_INTC_PRIOR             ((reg8 *) interrupteur__INTC_PRIOR_REG)

/* Priority of the interrupteur interrupt. */
#define interrupteur_INTC_PRIOR_NUMBER      interrupteur__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable interrupteur interrupt. */
#define interrupteur_INTC_SET_EN            ((reg32 *) interrupteur__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the interrupteur interrupt. */
#define interrupteur_INTC_CLR_EN            ((reg32 *) interrupteur__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the interrupteur interrupt state to pending. */
#define interrupteur_INTC_SET_PD            ((reg32 *) interrupteur__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the interrupteur interrupt. */
#define interrupteur_INTC_CLR_PD            ((reg32 *) interrupteur__INTC_CLR_PD_REG)


#endif /* CY_ISR_interrupteur_H */


/* [] END OF FILE */
