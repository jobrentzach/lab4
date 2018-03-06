/*******************************************************************************
* File Name: Random.h
* Version 2.70
*
*  Description:
*     Contains the function prototypes and constants available to the timer
*     user module.
*
*   Note:
*     None
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#if !defined(CY_Timer_v2_60_Random_H)
#define CY_Timer_v2_60_Random_H

#include "cytypes.h"
#include "cyfitter.h"
#include "CyLib.h" /* For CyEnterCriticalSection() and CyExitCriticalSection() functions */

extern uint8 Random_initVar;

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component Timer_v2_70 requires cy_boot v3.0 or later
#endif /* (CY_ PSOC5LP) */


/**************************************
*           Parameter Defaults
**************************************/

#define Random_Resolution                 32u
#define Random_UsingFixedFunction         0u
#define Random_UsingHWCaptureCounter      0u
#define Random_SoftwareCaptureMode        0u
#define Random_SoftwareTriggerMode        0u
#define Random_UsingHWEnable              0u
#define Random_EnableTriggerMode          0u
#define Random_InterruptOnCaptureCount    0u
#define Random_RunModeUsed                0u
#define Random_ControlRegRemoved          0u

#if defined(Random_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_REG)
    #define Random_UDB_CONTROL_REG_REMOVED            (0u)
#elif  (Random_UsingFixedFunction)
    #define Random_UDB_CONTROL_REG_REMOVED            (0u)
#else 
    #define Random_UDB_CONTROL_REG_REMOVED            (1u)
#endif /* End Random_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_REG */


/***************************************
*       Type defines
***************************************/


/**************************************************************************
 * Sleep Wakeup Backup structure for Timer Component
 *************************************************************************/
typedef struct
{
    uint8 TimerEnableState;
    #if(!Random_UsingFixedFunction)

        uint32 TimerUdb;
        uint8 InterruptMaskValue;
        #if (Random_UsingHWCaptureCounter)
            uint8 TimerCaptureCounter;
        #endif /* variable declarations for backing up non retention registers in CY_UDB_V1 */

        #if (!Random_UDB_CONTROL_REG_REMOVED)
            uint8 TimerControlRegister;
        #endif /* variable declaration for backing up enable state of the Timer */
    #endif /* define backup variables only for UDB implementation. Fixed function registers are all retention */

}Random_backupStruct;


/***************************************
*       Function Prototypes
***************************************/

void    Random_Start(void) ;
void    Random_Stop(void) ;

void    Random_SetInterruptMode(uint8 interruptMode) ;
uint8   Random_ReadStatusRegister(void) ;
/* Deprecated function. Do not use this in future. Retained for backward compatibility */
#define Random_GetInterruptSource() Random_ReadStatusRegister()

#if(!Random_UDB_CONTROL_REG_REMOVED)
    uint8   Random_ReadControlRegister(void) ;
    void    Random_WriteControlRegister(uint8 control) ;
#endif /* (!Random_UDB_CONTROL_REG_REMOVED) */

uint32  Random_ReadPeriod(void) ;
void    Random_WritePeriod(uint32 period) ;
uint32  Random_ReadCounter(void) ;
void    Random_WriteCounter(uint32 counter) ;
uint32  Random_ReadCapture(void) ;
void    Random_SoftwareCapture(void) ;

#if(!Random_UsingFixedFunction) /* UDB Prototypes */
    #if (Random_SoftwareCaptureMode)
        void    Random_SetCaptureMode(uint8 captureMode) ;
    #endif /* (!Random_UsingFixedFunction) */

    #if (Random_SoftwareTriggerMode)
        void    Random_SetTriggerMode(uint8 triggerMode) ;
    #endif /* (Random_SoftwareTriggerMode) */

    #if (Random_EnableTriggerMode)
        void    Random_EnableTrigger(void) ;
        void    Random_DisableTrigger(void) ;
    #endif /* (Random_EnableTriggerMode) */


    #if(Random_InterruptOnCaptureCount)
        void    Random_SetInterruptCount(uint8 interruptCount) ;
    #endif /* (Random_InterruptOnCaptureCount) */

    #if (Random_UsingHWCaptureCounter)
        void    Random_SetCaptureCount(uint8 captureCount) ;
        uint8   Random_ReadCaptureCount(void) ;
    #endif /* (Random_UsingHWCaptureCounter) */

    void Random_ClearFIFO(void) ;
#endif /* UDB Prototypes */

/* Sleep Retention APIs */
void Random_Init(void)          ;
void Random_Enable(void)        ;
void Random_SaveConfig(void)    ;
void Random_RestoreConfig(void) ;
void Random_Sleep(void)         ;
void Random_Wakeup(void)        ;


/***************************************
*   Enumerated Types and Parameters
***************************************/

/* Enumerated Type B_Timer__CaptureModes, Used in Capture Mode */
#define Random__B_TIMER__CM_NONE 0
#define Random__B_TIMER__CM_RISINGEDGE 1
#define Random__B_TIMER__CM_FALLINGEDGE 2
#define Random__B_TIMER__CM_EITHEREDGE 3
#define Random__B_TIMER__CM_SOFTWARE 4



/* Enumerated Type B_Timer__TriggerModes, Used in Trigger Mode */
#define Random__B_TIMER__TM_NONE 0x00u
#define Random__B_TIMER__TM_RISINGEDGE 0x04u
#define Random__B_TIMER__TM_FALLINGEDGE 0x08u
#define Random__B_TIMER__TM_EITHEREDGE 0x0Cu
#define Random__B_TIMER__TM_SOFTWARE 0x10u


/***************************************
*    Initialial Parameter Constants
***************************************/

#define Random_INIT_PERIOD             4294967295u
#define Random_INIT_CAPTURE_MODE       ((uint8)((uint8)0u << Random_CTRL_CAP_MODE_SHIFT))
#define Random_INIT_TRIGGER_MODE       ((uint8)((uint8)0u << Random_CTRL_TRIG_MODE_SHIFT))
#if (Random_UsingFixedFunction)
    #define Random_INIT_INTERRUPT_MODE (((uint8)((uint8)0u << Random_STATUS_TC_INT_MASK_SHIFT)) | \
                                                  ((uint8)((uint8)0 << Random_STATUS_CAPTURE_INT_MASK_SHIFT)))
#else
    #define Random_INIT_INTERRUPT_MODE (((uint8)((uint8)0u << Random_STATUS_TC_INT_MASK_SHIFT)) | \
                                                 ((uint8)((uint8)0 << Random_STATUS_CAPTURE_INT_MASK_SHIFT)) | \
                                                 ((uint8)((uint8)0 << Random_STATUS_FIFOFULL_INT_MASK_SHIFT)))
#endif /* (Random_UsingFixedFunction) */
#define Random_INIT_CAPTURE_COUNT      (2u)
#define Random_INIT_INT_CAPTURE_COUNT  ((uint8)((uint8)(1u - 1u) << Random_CTRL_INTCNT_SHIFT))


/***************************************
*           Registers
***************************************/

#if (Random_UsingFixedFunction) /* Implementation Specific Registers and Register Constants */


    /***************************************
    *    Fixed Function Registers
    ***************************************/

    #define Random_STATUS         (*(reg8 *) Random_TimerHW__SR0 )
    /* In Fixed Function Block Status and Mask are the same register */
    #define Random_STATUS_MASK    (*(reg8 *) Random_TimerHW__SR0 )
    #define Random_CONTROL        (*(reg8 *) Random_TimerHW__CFG0)
    #define Random_CONTROL2       (*(reg8 *) Random_TimerHW__CFG1)
    #define Random_CONTROL2_PTR   ( (reg8 *) Random_TimerHW__CFG1)
    #define Random_RT1            (*(reg8 *) Random_TimerHW__RT1)
    #define Random_RT1_PTR        ( (reg8 *) Random_TimerHW__RT1)

    #if (CY_PSOC3 || CY_PSOC5LP)
        #define Random_CONTROL3       (*(reg8 *) Random_TimerHW__CFG2)
        #define Random_CONTROL3_PTR   ( (reg8 *) Random_TimerHW__CFG2)
    #endif /* (CY_PSOC3 || CY_PSOC5LP) */
    #define Random_GLOBAL_ENABLE  (*(reg8 *) Random_TimerHW__PM_ACT_CFG)
    #define Random_GLOBAL_STBY_ENABLE  (*(reg8 *) Random_TimerHW__PM_STBY_CFG)

    #define Random_CAPTURE_LSB         (* (reg16 *) Random_TimerHW__CAP0 )
    #define Random_CAPTURE_LSB_PTR       ((reg16 *) Random_TimerHW__CAP0 )
    #define Random_PERIOD_LSB          (* (reg16 *) Random_TimerHW__PER0 )
    #define Random_PERIOD_LSB_PTR        ((reg16 *) Random_TimerHW__PER0 )
    #define Random_COUNTER_LSB         (* (reg16 *) Random_TimerHW__CNT_CMP0 )
    #define Random_COUNTER_LSB_PTR       ((reg16 *) Random_TimerHW__CNT_CMP0 )


    /***************************************
    *    Register Constants
    ***************************************/

    /* Fixed Function Block Chosen */
    #define Random_BLOCK_EN_MASK                     Random_TimerHW__PM_ACT_MSK
    #define Random_BLOCK_STBY_EN_MASK                Random_TimerHW__PM_STBY_MSK

    /* Control Register Bit Locations */
    /* Interrupt Count - Not valid for Fixed Function Block */
    #define Random_CTRL_INTCNT_SHIFT                  0x00u
    /* Trigger Polarity - Not valid for Fixed Function Block */
    #define Random_CTRL_TRIG_MODE_SHIFT               0x00u
    /* Trigger Enable - Not valid for Fixed Function Block */
    #define Random_CTRL_TRIG_EN_SHIFT                 0x00u
    /* Capture Polarity - Not valid for Fixed Function Block */
    #define Random_CTRL_CAP_MODE_SHIFT                0x00u
    /* Timer Enable - As defined in Register Map, part of TMRX_CFG0 register */
    #define Random_CTRL_ENABLE_SHIFT                  0x00u

    /* Control Register Bit Masks */
    #define Random_CTRL_ENABLE                        ((uint8)((uint8)0x01u << Random_CTRL_ENABLE_SHIFT))

    /* Control2 Register Bit Masks */
    /* As defined in Register Map, Part of the TMRX_CFG1 register */
    #define Random_CTRL2_IRQ_SEL_SHIFT                 0x00u
    #define Random_CTRL2_IRQ_SEL                      ((uint8)((uint8)0x01u << Random_CTRL2_IRQ_SEL_SHIFT))

    #if (CY_PSOC5A)
        /* Use CFG1 Mode bits to set run mode */
        /* As defined by Verilog Implementation */
        #define Random_CTRL_MODE_SHIFT                 0x01u
        #define Random_CTRL_MODE_MASK                 ((uint8)((uint8)0x07u << Random_CTRL_MODE_SHIFT))
    #endif /* (CY_PSOC5A) */
    #if (CY_PSOC3 || CY_PSOC5LP)
        /* Control3 Register Bit Locations */
        #define Random_CTRL_RCOD_SHIFT        0x02u
        #define Random_CTRL_ENBL_SHIFT        0x00u
        #define Random_CTRL_MODE_SHIFT        0x00u

        /* Control3 Register Bit Masks */
        #define Random_CTRL_RCOD_MASK  ((uint8)((uint8)0x03u << Random_CTRL_RCOD_SHIFT)) /* ROD and COD bit masks */
        #define Random_CTRL_ENBL_MASK  ((uint8)((uint8)0x80u << Random_CTRL_ENBL_SHIFT)) /* HW_EN bit mask */
        #define Random_CTRL_MODE_MASK  ((uint8)((uint8)0x03u << Random_CTRL_MODE_SHIFT)) /* Run mode bit mask */

        #define Random_CTRL_RCOD       ((uint8)((uint8)0x03u << Random_CTRL_RCOD_SHIFT))
        #define Random_CTRL_ENBL       ((uint8)((uint8)0x80u << Random_CTRL_ENBL_SHIFT))
    #endif /* (CY_PSOC3 || CY_PSOC5LP) */

    /*RT1 Synch Constants: Applicable for PSoC3 and PSoC5LP */
    #define Random_RT1_SHIFT                       0x04u
    /* Sync TC and CMP bit masks */
    #define Random_RT1_MASK                        ((uint8)((uint8)0x03u << Random_RT1_SHIFT))
    #define Random_SYNC                            ((uint8)((uint8)0x03u << Random_RT1_SHIFT))
    #define Random_SYNCDSI_SHIFT                   0x00u
    /* Sync all DSI inputs with Mask  */
    #define Random_SYNCDSI_MASK                    ((uint8)((uint8)0x0Fu << Random_SYNCDSI_SHIFT))
    /* Sync all DSI inputs */
    #define Random_SYNCDSI_EN                      ((uint8)((uint8)0x0Fu << Random_SYNCDSI_SHIFT))

    #define Random_CTRL_MODE_PULSEWIDTH            ((uint8)((uint8)0x01u << Random_CTRL_MODE_SHIFT))
    #define Random_CTRL_MODE_PERIOD                ((uint8)((uint8)0x02u << Random_CTRL_MODE_SHIFT))
    #define Random_CTRL_MODE_CONTINUOUS            ((uint8)((uint8)0x00u << Random_CTRL_MODE_SHIFT))

    /* Status Register Bit Locations */
    /* As defined in Register Map, part of TMRX_SR0 register */
    #define Random_STATUS_TC_SHIFT                 0x07u
    /* As defined in Register Map, part of TMRX_SR0 register, Shared with Compare Status */
    #define Random_STATUS_CAPTURE_SHIFT            0x06u
    /* As defined in Register Map, part of TMRX_SR0 register */
    #define Random_STATUS_TC_INT_MASK_SHIFT        (Random_STATUS_TC_SHIFT - 0x04u)
    /* As defined in Register Map, part of TMRX_SR0 register, Shared with Compare Status */
    #define Random_STATUS_CAPTURE_INT_MASK_SHIFT   (Random_STATUS_CAPTURE_SHIFT - 0x04u)

    /* Status Register Bit Masks */
    #define Random_STATUS_TC                       ((uint8)((uint8)0x01u << Random_STATUS_TC_SHIFT))
    #define Random_STATUS_CAPTURE                  ((uint8)((uint8)0x01u << Random_STATUS_CAPTURE_SHIFT))
    /* Interrupt Enable Bit-Mask for interrupt on TC */
    #define Random_STATUS_TC_INT_MASK              ((uint8)((uint8)0x01u << Random_STATUS_TC_INT_MASK_SHIFT))
    /* Interrupt Enable Bit-Mask for interrupt on Capture */
    #define Random_STATUS_CAPTURE_INT_MASK         ((uint8)((uint8)0x01u << Random_STATUS_CAPTURE_INT_MASK_SHIFT))

#else   /* UDB Registers and Register Constants */


    /***************************************
    *           UDB Registers
    ***************************************/

    #define Random_STATUS              (* (reg8 *) Random_TimerUDB_rstSts_stsreg__STATUS_REG )
    #define Random_STATUS_MASK         (* (reg8 *) Random_TimerUDB_rstSts_stsreg__MASK_REG)
    #define Random_STATUS_AUX_CTRL     (* (reg8 *) Random_TimerUDB_rstSts_stsreg__STATUS_AUX_CTL_REG)
    #define Random_CONTROL             (* (reg8 *) Random_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_REG )
    
    #if(Random_Resolution <= 8u) /* 8-bit Timer */
        #define Random_CAPTURE_LSB         (* (reg8 *) Random_TimerUDB_sT32_timerdp_u0__F0_REG )
        #define Random_CAPTURE_LSB_PTR       ((reg8 *) Random_TimerUDB_sT32_timerdp_u0__F0_REG )
        #define Random_PERIOD_LSB          (* (reg8 *) Random_TimerUDB_sT32_timerdp_u0__D0_REG )
        #define Random_PERIOD_LSB_PTR        ((reg8 *) Random_TimerUDB_sT32_timerdp_u0__D0_REG )
        #define Random_COUNTER_LSB         (* (reg8 *) Random_TimerUDB_sT32_timerdp_u0__A0_REG )
        #define Random_COUNTER_LSB_PTR       ((reg8 *) Random_TimerUDB_sT32_timerdp_u0__A0_REG )
    #elif(Random_Resolution <= 16u) /* 8-bit Timer */
        #if(CY_PSOC3) /* 8-bit addres space */
            #define Random_CAPTURE_LSB         (* (reg16 *) Random_TimerUDB_sT32_timerdp_u0__F0_REG )
            #define Random_CAPTURE_LSB_PTR       ((reg16 *) Random_TimerUDB_sT32_timerdp_u0__F0_REG )
            #define Random_PERIOD_LSB          (* (reg16 *) Random_TimerUDB_sT32_timerdp_u0__D0_REG )
            #define Random_PERIOD_LSB_PTR        ((reg16 *) Random_TimerUDB_sT32_timerdp_u0__D0_REG )
            #define Random_COUNTER_LSB         (* (reg16 *) Random_TimerUDB_sT32_timerdp_u0__A0_REG )
            #define Random_COUNTER_LSB_PTR       ((reg16 *) Random_TimerUDB_sT32_timerdp_u0__A0_REG )
        #else /* 16-bit address space */
            #define Random_CAPTURE_LSB         (* (reg16 *) Random_TimerUDB_sT32_timerdp_u0__16BIT_F0_REG )
            #define Random_CAPTURE_LSB_PTR       ((reg16 *) Random_TimerUDB_sT32_timerdp_u0__16BIT_F0_REG )
            #define Random_PERIOD_LSB          (* (reg16 *) Random_TimerUDB_sT32_timerdp_u0__16BIT_D0_REG )
            #define Random_PERIOD_LSB_PTR        ((reg16 *) Random_TimerUDB_sT32_timerdp_u0__16BIT_D0_REG )
            #define Random_COUNTER_LSB         (* (reg16 *) Random_TimerUDB_sT32_timerdp_u0__16BIT_A0_REG )
            #define Random_COUNTER_LSB_PTR       ((reg16 *) Random_TimerUDB_sT32_timerdp_u0__16BIT_A0_REG )
        #endif /* CY_PSOC3 */
    #elif(Random_Resolution <= 24u)/* 24-bit Timer */
        #define Random_CAPTURE_LSB         (* (reg32 *) Random_TimerUDB_sT32_timerdp_u0__F0_REG )
        #define Random_CAPTURE_LSB_PTR       ((reg32 *) Random_TimerUDB_sT32_timerdp_u0__F0_REG )
        #define Random_PERIOD_LSB          (* (reg32 *) Random_TimerUDB_sT32_timerdp_u0__D0_REG )
        #define Random_PERIOD_LSB_PTR        ((reg32 *) Random_TimerUDB_sT32_timerdp_u0__D0_REG )
        #define Random_COUNTER_LSB         (* (reg32 *) Random_TimerUDB_sT32_timerdp_u0__A0_REG )
        #define Random_COUNTER_LSB_PTR       ((reg32 *) Random_TimerUDB_sT32_timerdp_u0__A0_REG )
    #else /* 32-bit Timer */
        #if(CY_PSOC3 || CY_PSOC5) /* 8-bit address space */
            #define Random_CAPTURE_LSB         (* (reg32 *) Random_TimerUDB_sT32_timerdp_u0__F0_REG )
            #define Random_CAPTURE_LSB_PTR       ((reg32 *) Random_TimerUDB_sT32_timerdp_u0__F0_REG )
            #define Random_PERIOD_LSB          (* (reg32 *) Random_TimerUDB_sT32_timerdp_u0__D0_REG )
            #define Random_PERIOD_LSB_PTR        ((reg32 *) Random_TimerUDB_sT32_timerdp_u0__D0_REG )
            #define Random_COUNTER_LSB         (* (reg32 *) Random_TimerUDB_sT32_timerdp_u0__A0_REG )
            #define Random_COUNTER_LSB_PTR       ((reg32 *) Random_TimerUDB_sT32_timerdp_u0__A0_REG )
        #else /* 32-bit address space */
            #define Random_CAPTURE_LSB         (* (reg32 *) Random_TimerUDB_sT32_timerdp_u0__32BIT_F0_REG )
            #define Random_CAPTURE_LSB_PTR       ((reg32 *) Random_TimerUDB_sT32_timerdp_u0__32BIT_F0_REG )
            #define Random_PERIOD_LSB          (* (reg32 *) Random_TimerUDB_sT32_timerdp_u0__32BIT_D0_REG )
            #define Random_PERIOD_LSB_PTR        ((reg32 *) Random_TimerUDB_sT32_timerdp_u0__32BIT_D0_REG )
            #define Random_COUNTER_LSB         (* (reg32 *) Random_TimerUDB_sT32_timerdp_u0__32BIT_A0_REG )
            #define Random_COUNTER_LSB_PTR       ((reg32 *) Random_TimerUDB_sT32_timerdp_u0__32BIT_A0_REG )
        #endif /* CY_PSOC3 || CY_PSOC5 */ 
    #endif

    #define Random_COUNTER_LSB_PTR_8BIT       ((reg8 *) Random_TimerUDB_sT32_timerdp_u0__A0_REG )
    
    #if (Random_UsingHWCaptureCounter)
        #define Random_CAP_COUNT              (*(reg8 *) Random_TimerUDB_sCapCount_counter__PERIOD_REG )
        #define Random_CAP_COUNT_PTR          ( (reg8 *) Random_TimerUDB_sCapCount_counter__PERIOD_REG )
        #define Random_CAPTURE_COUNT_CTRL     (*(reg8 *) Random_TimerUDB_sCapCount_counter__CONTROL_AUX_CTL_REG )
        #define Random_CAPTURE_COUNT_CTRL_PTR ( (reg8 *) Random_TimerUDB_sCapCount_counter__CONTROL_AUX_CTL_REG )
    #endif /* (Random_UsingHWCaptureCounter) */


    /***************************************
    *       Register Constants
    ***************************************/

    /* Control Register Bit Locations */
    #define Random_CTRL_INTCNT_SHIFT              0x00u       /* As defined by Verilog Implementation */
    #define Random_CTRL_TRIG_MODE_SHIFT           0x02u       /* As defined by Verilog Implementation */
    #define Random_CTRL_TRIG_EN_SHIFT             0x04u       /* As defined by Verilog Implementation */
    #define Random_CTRL_CAP_MODE_SHIFT            0x05u       /* As defined by Verilog Implementation */
    #define Random_CTRL_ENABLE_SHIFT              0x07u       /* As defined by Verilog Implementation */

    /* Control Register Bit Masks */
    #define Random_CTRL_INTCNT_MASK               ((uint8)((uint8)0x03u << Random_CTRL_INTCNT_SHIFT))
    #define Random_CTRL_TRIG_MODE_MASK            ((uint8)((uint8)0x03u << Random_CTRL_TRIG_MODE_SHIFT))
    #define Random_CTRL_TRIG_EN                   ((uint8)((uint8)0x01u << Random_CTRL_TRIG_EN_SHIFT))
    #define Random_CTRL_CAP_MODE_MASK             ((uint8)((uint8)0x03u << Random_CTRL_CAP_MODE_SHIFT))
    #define Random_CTRL_ENABLE                    ((uint8)((uint8)0x01u << Random_CTRL_ENABLE_SHIFT))

    /* Bit Counter (7-bit) Control Register Bit Definitions */
    /* As defined by the Register map for the AUX Control Register */
    #define Random_CNTR_ENABLE                    0x20u

    /* Status Register Bit Locations */
    #define Random_STATUS_TC_SHIFT                0x00u  /* As defined by Verilog Implementation */
    #define Random_STATUS_CAPTURE_SHIFT           0x01u  /* As defined by Verilog Implementation */
    #define Random_STATUS_TC_INT_MASK_SHIFT       Random_STATUS_TC_SHIFT
    #define Random_STATUS_CAPTURE_INT_MASK_SHIFT  Random_STATUS_CAPTURE_SHIFT
    #define Random_STATUS_FIFOFULL_SHIFT          0x02u  /* As defined by Verilog Implementation */
    #define Random_STATUS_FIFONEMP_SHIFT          0x03u  /* As defined by Verilog Implementation */
    #define Random_STATUS_FIFOFULL_INT_MASK_SHIFT Random_STATUS_FIFOFULL_SHIFT

    /* Status Register Bit Masks */
    /* Sticky TC Event Bit-Mask */
    #define Random_STATUS_TC                      ((uint8)((uint8)0x01u << Random_STATUS_TC_SHIFT))
    /* Sticky Capture Event Bit-Mask */
    #define Random_STATUS_CAPTURE                 ((uint8)((uint8)0x01u << Random_STATUS_CAPTURE_SHIFT))
    /* Interrupt Enable Bit-Mask */
    #define Random_STATUS_TC_INT_MASK             ((uint8)((uint8)0x01u << Random_STATUS_TC_SHIFT))
    /* Interrupt Enable Bit-Mask */
    #define Random_STATUS_CAPTURE_INT_MASK        ((uint8)((uint8)0x01u << Random_STATUS_CAPTURE_SHIFT))
    /* NOT-Sticky FIFO Full Bit-Mask */
    #define Random_STATUS_FIFOFULL                ((uint8)((uint8)0x01u << Random_STATUS_FIFOFULL_SHIFT))
    /* NOT-Sticky FIFO Not Empty Bit-Mask */
    #define Random_STATUS_FIFONEMP                ((uint8)((uint8)0x01u << Random_STATUS_FIFONEMP_SHIFT))
    /* Interrupt Enable Bit-Mask */
    #define Random_STATUS_FIFOFULL_INT_MASK       ((uint8)((uint8)0x01u << Random_STATUS_FIFOFULL_SHIFT))

    #define Random_STATUS_ACTL_INT_EN             0x10u   /* As defined for the ACTL Register */

    /* Datapath Auxillary Control Register definitions */
    #define Random_AUX_CTRL_FIFO0_CLR             0x01u   /* As defined by Register map */
    #define Random_AUX_CTRL_FIFO1_CLR             0x02u   /* As defined by Register map */
    #define Random_AUX_CTRL_FIFO0_LVL             0x04u   /* As defined by Register map */
    #define Random_AUX_CTRL_FIFO1_LVL             0x08u   /* As defined by Register map */
    #define Random_STATUS_ACTL_INT_EN_MASK        0x10u   /* As defined for the ACTL Register */

#endif /* Implementation Specific Registers and Register Constants */

#endif  /* CY_Timer_v2_30_Random_H */


/* [] END OF FILE */
