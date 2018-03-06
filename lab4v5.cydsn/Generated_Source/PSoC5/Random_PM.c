/*******************************************************************************
* File Name: Random_PM.c
* Version 2.70
*
*  Description:
*     This file provides the power management source code to API for the
*     Timer.
*
*   Note:
*     None
*
*******************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#include "Random.h"

static Random_backupStruct Random_backup;


/*******************************************************************************
* Function Name: Random_SaveConfig
********************************************************************************
*
* Summary:
*     Save the current user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  Random_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void Random_SaveConfig(void) 
{
    #if (!Random_UsingFixedFunction)
        Random_backup.TimerUdb = Random_ReadCounter();
        Random_backup.InterruptMaskValue = Random_STATUS_MASK;
        #if (Random_UsingHWCaptureCounter)
            Random_backup.TimerCaptureCounter = Random_ReadCaptureCount();
        #endif /* Back Up capture counter register  */

        #if(!Random_UDB_CONTROL_REG_REMOVED)
            Random_backup.TimerControlRegister = Random_ReadControlRegister();
        #endif /* Backup the enable state of the Timer component */
    #endif /* Backup non retention registers in UDB implementation. All fixed function registers are retention */
}


/*******************************************************************************
* Function Name: Random_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  Random_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void Random_RestoreConfig(void) 
{   
    #if (!Random_UsingFixedFunction)

        Random_WriteCounter(Random_backup.TimerUdb);
        Random_STATUS_MASK =Random_backup.InterruptMaskValue;
        #if (Random_UsingHWCaptureCounter)
            Random_SetCaptureCount(Random_backup.TimerCaptureCounter);
        #endif /* Restore Capture counter register*/

        #if(!Random_UDB_CONTROL_REG_REMOVED)
            Random_WriteControlRegister(Random_backup.TimerControlRegister);
        #endif /* Restore the enable state of the Timer component */
    #endif /* Restore non retention registers in the UDB implementation only */
}


/*******************************************************************************
* Function Name: Random_Sleep
********************************************************************************
*
* Summary:
*     Stop and Save the user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  Random_backup.TimerEnableState:  Is modified depending on the
*  enable state of the block before entering sleep mode.
*
*******************************************************************************/
void Random_Sleep(void) 
{
    #if(!Random_UDB_CONTROL_REG_REMOVED)
        /* Save Counter's enable state */
        if(Random_CTRL_ENABLE == (Random_CONTROL & Random_CTRL_ENABLE))
        {
            /* Timer is enabled */
            Random_backup.TimerEnableState = 1u;
        }
        else
        {
            /* Timer is disabled */
            Random_backup.TimerEnableState = 0u;
        }
    #endif /* Back up enable state from the Timer control register */
    Random_Stop();
    Random_SaveConfig();
}


/*******************************************************************************
* Function Name: Random_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  Random_backup.enableState:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Random_Wakeup(void) 
{
    Random_RestoreConfig();
    #if(!Random_UDB_CONTROL_REG_REMOVED)
        if(Random_backup.TimerEnableState == 1u)
        {     /* Enable Timer's operation */
                Random_Enable();
        } /* Do nothing if Timer was disabled before */
    #endif /* Remove this code section if Control register is removed */
}


/* [] END OF FILE */
