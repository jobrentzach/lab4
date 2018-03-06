/*******************************************************************************
* File Name: cyfitter.h
* 
* PSoC Creator  4.1 Update 1
*
* Description:
* 
* This file is automatically generated by PSoC Creator.
*
********************************************************************************
* Copyright (c) 2007-2017 Cypress Semiconductor.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#ifndef INCLUDED_CYFITTER_H
#define INCLUDED_CYFITTER_H
#include "cydevice.h"
#include "cydevice_trm.h"

/* Clock1 */
#define Clock1__CFG0 CYREG_CLKDIST_DCFG2_CFG0
#define Clock1__CFG1 CYREG_CLKDIST_DCFG2_CFG1
#define Clock1__CFG2 CYREG_CLKDIST_DCFG2_CFG2
#define Clock1__CFG2_SRC_SEL_MASK 0x07u
#define Clock1__INDEX 0x02u
#define Clock1__PM_ACT_CFG CYREG_PM_ACT_CFG2
#define Clock1__PM_ACT_MSK 0x04u
#define Clock1__PM_STBY_CFG CYREG_PM_STBY_CFG2
#define Clock1__PM_STBY_MSK 0x04u

/* Clock2 */
#define Clock2__CFG0 CYREG_CLKDIST_DCFG1_CFG0
#define Clock2__CFG1 CYREG_CLKDIST_DCFG1_CFG1
#define Clock2__CFG2 CYREG_CLKDIST_DCFG1_CFG2
#define Clock2__CFG2_SRC_SEL_MASK 0x07u
#define Clock2__INDEX 0x01u
#define Clock2__PM_ACT_CFG CYREG_PM_ACT_CFG2
#define Clock2__PM_ACT_MSK 0x02u
#define Clock2__PM_STBY_CFG CYREG_PM_STBY_CFG2
#define Clock2__PM_STBY_MSK 0x02u

/* ISR_user_btn */
#define ISR_user_btn__INTC_CLR_EN_REG CYREG_NVIC_CLRENA0
#define ISR_user_btn__INTC_CLR_PD_REG CYREG_NVIC_CLRPEND0
#define ISR_user_btn__INTC_MASK 0x20u
#define ISR_user_btn__INTC_NUMBER 5u
#define ISR_user_btn__INTC_PRIOR_NUM 7u
#define ISR_user_btn__INTC_PRIOR_REG CYREG_NVIC_PRI_5
#define ISR_user_btn__INTC_SET_EN_REG CYREG_NVIC_SETENA0
#define ISR_user_btn__INTC_SET_PD_REG CYREG_NVIC_SETPEND0

/* LED */
#define LED__0__INTTYPE CYREG_PICU6_INTTYPE7
#define LED__0__MASK 0x80u
#define LED__0__PC CYREG_PRT6_PC7
#define LED__0__PORT 6u
#define LED__0__SHIFT 7u
#define LED__AG CYREG_PRT6_AG
#define LED__AMUX CYREG_PRT6_AMUX
#define LED__BIE CYREG_PRT6_BIE
#define LED__BIT_MASK CYREG_PRT6_BIT_MASK
#define LED__BYP CYREG_PRT6_BYP
#define LED__CTL CYREG_PRT6_CTL
#define LED__DM0 CYREG_PRT6_DM0
#define LED__DM1 CYREG_PRT6_DM1
#define LED__DM2 CYREG_PRT6_DM2
#define LED__DR CYREG_PRT6_DR
#define LED__INP_DIS CYREG_PRT6_INP_DIS
#define LED__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU6_BASE
#define LED__LCD_COM_SEG CYREG_PRT6_LCD_COM_SEG
#define LED__LCD_EN CYREG_PRT6_LCD_EN
#define LED__MASK 0x80u
#define LED__PORT 6u
#define LED__PRT CYREG_PRT6_PRT
#define LED__PRTDSI__CAPS_SEL CYREG_PRT6_CAPS_SEL
#define LED__PRTDSI__DBL_SYNC_IN CYREG_PRT6_DBL_SYNC_IN
#define LED__PRTDSI__OE_SEL0 CYREG_PRT6_OE_SEL0
#define LED__PRTDSI__OE_SEL1 CYREG_PRT6_OE_SEL1
#define LED__PRTDSI__OUT_SEL0 CYREG_PRT6_OUT_SEL0
#define LED__PRTDSI__OUT_SEL1 CYREG_PRT6_OUT_SEL1
#define LED__PRTDSI__SYNC_OUT CYREG_PRT6_SYNC_OUT
#define LED__PS CYREG_PRT6_PS
#define LED__SHIFT 7u
#define LED__SLW CYREG_PRT6_SLW

/* Random */
#define Random_TimerUDB_rstSts_stsreg__0__MASK 0x01u
#define Random_TimerUDB_rstSts_stsreg__0__POS 0
#define Random_TimerUDB_rstSts_stsreg__16BIT_STATUS_AUX_CTL_REG CYREG_B1_UDB07_08_ACTL
#define Random_TimerUDB_rstSts_stsreg__16BIT_STATUS_REG CYREG_B1_UDB07_08_ST
#define Random_TimerUDB_rstSts_stsreg__2__MASK 0x04u
#define Random_TimerUDB_rstSts_stsreg__2__POS 2
#define Random_TimerUDB_rstSts_stsreg__3__MASK 0x08u
#define Random_TimerUDB_rstSts_stsreg__3__POS 3
#define Random_TimerUDB_rstSts_stsreg__MASK 0x0Du
#define Random_TimerUDB_rstSts_stsreg__MASK_REG CYREG_B1_UDB07_MSK
#define Random_TimerUDB_rstSts_stsreg__STATUS_AUX_CTL_REG CYREG_B1_UDB07_ACTL
#define Random_TimerUDB_rstSts_stsreg__STATUS_REG CYREG_B1_UDB07_ST
#define Random_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_CONTROL_AUX_CTL_REG CYREG_B1_UDB04_05_ACTL
#define Random_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_CONTROL_CONTROL_REG CYREG_B1_UDB04_05_CTL
#define Random_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_CONTROL_COUNT_REG CYREG_B1_UDB04_05_CTL
#define Random_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_COUNT_CONTROL_REG CYREG_B1_UDB04_05_CTL
#define Random_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_COUNT_COUNT_REG CYREG_B1_UDB04_05_CTL
#define Random_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_MASK_MASK_REG CYREG_B1_UDB04_05_MSK
#define Random_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_MASK_PERIOD_REG CYREG_B1_UDB04_05_MSK
#define Random_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_PERIOD_MASK_REG CYREG_B1_UDB04_05_MSK
#define Random_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_PERIOD_PERIOD_REG CYREG_B1_UDB04_05_MSK
#define Random_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__7__MASK 0x80u
#define Random_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__7__POS 7
#define Random_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_AUX_CTL_REG CYREG_B1_UDB04_ACTL
#define Random_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_REG CYREG_B1_UDB04_CTL
#define Random_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_ST_REG CYREG_B1_UDB04_ST_CTL
#define Random_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__COUNT_REG CYREG_B1_UDB04_CTL
#define Random_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__COUNT_ST_REG CYREG_B1_UDB04_ST_CTL
#define Random_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__MASK 0x80u
#define Random_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__MASK_CTL_AUX_CTL_REG CYREG_B1_UDB04_MSK_ACTL
#define Random_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__PER_CTL_AUX_CTL_REG CYREG_B1_UDB04_MSK_ACTL
#define Random_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__PERIOD_REG CYREG_B1_UDB04_MSK
#define Random_TimerUDB_sT32_timerdp_u0__16BIT_A0_REG CYREG_B1_UDB04_05_A0
#define Random_TimerUDB_sT32_timerdp_u0__16BIT_A1_REG CYREG_B1_UDB04_05_A1
#define Random_TimerUDB_sT32_timerdp_u0__16BIT_D0_REG CYREG_B1_UDB04_05_D0
#define Random_TimerUDB_sT32_timerdp_u0__16BIT_D1_REG CYREG_B1_UDB04_05_D1
#define Random_TimerUDB_sT32_timerdp_u0__16BIT_DP_AUX_CTL_REG CYREG_B1_UDB04_05_ACTL
#define Random_TimerUDB_sT32_timerdp_u0__16BIT_F0_REG CYREG_B1_UDB04_05_F0
#define Random_TimerUDB_sT32_timerdp_u0__16BIT_F1_REG CYREG_B1_UDB04_05_F1
#define Random_TimerUDB_sT32_timerdp_u0__A0_A1_REG CYREG_B1_UDB04_A0_A1
#define Random_TimerUDB_sT32_timerdp_u0__A0_REG CYREG_B1_UDB04_A0
#define Random_TimerUDB_sT32_timerdp_u0__A1_REG CYREG_B1_UDB04_A1
#define Random_TimerUDB_sT32_timerdp_u0__D0_D1_REG CYREG_B1_UDB04_D0_D1
#define Random_TimerUDB_sT32_timerdp_u0__D0_REG CYREG_B1_UDB04_D0
#define Random_TimerUDB_sT32_timerdp_u0__D1_REG CYREG_B1_UDB04_D1
#define Random_TimerUDB_sT32_timerdp_u0__DP_AUX_CTL_REG CYREG_B1_UDB04_ACTL
#define Random_TimerUDB_sT32_timerdp_u0__F0_F1_REG CYREG_B1_UDB04_F0_F1
#define Random_TimerUDB_sT32_timerdp_u0__F0_REG CYREG_B1_UDB04_F0
#define Random_TimerUDB_sT32_timerdp_u0__F1_REG CYREG_B1_UDB04_F1
#define Random_TimerUDB_sT32_timerdp_u0__MSK_DP_AUX_CTL_REG CYREG_B1_UDB04_MSK_ACTL
#define Random_TimerUDB_sT32_timerdp_u0__PER_DP_AUX_CTL_REG CYREG_B1_UDB04_MSK_ACTL
#define Random_TimerUDB_sT32_timerdp_u1__16BIT_A0_REG CYREG_B1_UDB05_06_A0
#define Random_TimerUDB_sT32_timerdp_u1__16BIT_A1_REG CYREG_B1_UDB05_06_A1
#define Random_TimerUDB_sT32_timerdp_u1__16BIT_D0_REG CYREG_B1_UDB05_06_D0
#define Random_TimerUDB_sT32_timerdp_u1__16BIT_D1_REG CYREG_B1_UDB05_06_D1
#define Random_TimerUDB_sT32_timerdp_u1__16BIT_DP_AUX_CTL_REG CYREG_B1_UDB05_06_ACTL
#define Random_TimerUDB_sT32_timerdp_u1__16BIT_F0_REG CYREG_B1_UDB05_06_F0
#define Random_TimerUDB_sT32_timerdp_u1__16BIT_F1_REG CYREG_B1_UDB05_06_F1
#define Random_TimerUDB_sT32_timerdp_u1__A0_A1_REG CYREG_B1_UDB05_A0_A1
#define Random_TimerUDB_sT32_timerdp_u1__A0_REG CYREG_B1_UDB05_A0
#define Random_TimerUDB_sT32_timerdp_u1__A1_REG CYREG_B1_UDB05_A1
#define Random_TimerUDB_sT32_timerdp_u1__D0_D1_REG CYREG_B1_UDB05_D0_D1
#define Random_TimerUDB_sT32_timerdp_u1__D0_REG CYREG_B1_UDB05_D0
#define Random_TimerUDB_sT32_timerdp_u1__D1_REG CYREG_B1_UDB05_D1
#define Random_TimerUDB_sT32_timerdp_u1__DP_AUX_CTL_REG CYREG_B1_UDB05_ACTL
#define Random_TimerUDB_sT32_timerdp_u1__F0_F1_REG CYREG_B1_UDB05_F0_F1
#define Random_TimerUDB_sT32_timerdp_u1__F0_REG CYREG_B1_UDB05_F0
#define Random_TimerUDB_sT32_timerdp_u1__F1_REG CYREG_B1_UDB05_F1
#define Random_TimerUDB_sT32_timerdp_u2__16BIT_A0_REG CYREG_B1_UDB06_07_A0
#define Random_TimerUDB_sT32_timerdp_u2__16BIT_A1_REG CYREG_B1_UDB06_07_A1
#define Random_TimerUDB_sT32_timerdp_u2__16BIT_D0_REG CYREG_B1_UDB06_07_D0
#define Random_TimerUDB_sT32_timerdp_u2__16BIT_D1_REG CYREG_B1_UDB06_07_D1
#define Random_TimerUDB_sT32_timerdp_u2__16BIT_DP_AUX_CTL_REG CYREG_B1_UDB06_07_ACTL
#define Random_TimerUDB_sT32_timerdp_u2__16BIT_F0_REG CYREG_B1_UDB06_07_F0
#define Random_TimerUDB_sT32_timerdp_u2__16BIT_F1_REG CYREG_B1_UDB06_07_F1
#define Random_TimerUDB_sT32_timerdp_u2__A0_A1_REG CYREG_B1_UDB06_A0_A1
#define Random_TimerUDB_sT32_timerdp_u2__A0_REG CYREG_B1_UDB06_A0
#define Random_TimerUDB_sT32_timerdp_u2__A1_REG CYREG_B1_UDB06_A1
#define Random_TimerUDB_sT32_timerdp_u2__D0_D1_REG CYREG_B1_UDB06_D0_D1
#define Random_TimerUDB_sT32_timerdp_u2__D0_REG CYREG_B1_UDB06_D0
#define Random_TimerUDB_sT32_timerdp_u2__D1_REG CYREG_B1_UDB06_D1
#define Random_TimerUDB_sT32_timerdp_u2__DP_AUX_CTL_REG CYREG_B1_UDB06_ACTL
#define Random_TimerUDB_sT32_timerdp_u2__F0_F1_REG CYREG_B1_UDB06_F0_F1
#define Random_TimerUDB_sT32_timerdp_u2__F0_REG CYREG_B1_UDB06_F0
#define Random_TimerUDB_sT32_timerdp_u2__F1_REG CYREG_B1_UDB06_F1
#define Random_TimerUDB_sT32_timerdp_u3__16BIT_A0_REG CYREG_B1_UDB07_08_A0
#define Random_TimerUDB_sT32_timerdp_u3__16BIT_A1_REG CYREG_B1_UDB07_08_A1
#define Random_TimerUDB_sT32_timerdp_u3__16BIT_D0_REG CYREG_B1_UDB07_08_D0
#define Random_TimerUDB_sT32_timerdp_u3__16BIT_D1_REG CYREG_B1_UDB07_08_D1
#define Random_TimerUDB_sT32_timerdp_u3__16BIT_DP_AUX_CTL_REG CYREG_B1_UDB07_08_ACTL
#define Random_TimerUDB_sT32_timerdp_u3__16BIT_F0_REG CYREG_B1_UDB07_08_F0
#define Random_TimerUDB_sT32_timerdp_u3__16BIT_F1_REG CYREG_B1_UDB07_08_F1
#define Random_TimerUDB_sT32_timerdp_u3__A0_A1_REG CYREG_B1_UDB07_A0_A1
#define Random_TimerUDB_sT32_timerdp_u3__A0_REG CYREG_B1_UDB07_A0
#define Random_TimerUDB_sT32_timerdp_u3__A1_REG CYREG_B1_UDB07_A1
#define Random_TimerUDB_sT32_timerdp_u3__D0_D1_REG CYREG_B1_UDB07_D0_D1
#define Random_TimerUDB_sT32_timerdp_u3__D0_REG CYREG_B1_UDB07_D0
#define Random_TimerUDB_sT32_timerdp_u3__D1_REG CYREG_B1_UDB07_D1
#define Random_TimerUDB_sT32_timerdp_u3__DP_AUX_CTL_REG CYREG_B1_UDB07_ACTL
#define Random_TimerUDB_sT32_timerdp_u3__F0_F1_REG CYREG_B1_UDB07_F0_F1
#define Random_TimerUDB_sT32_timerdp_u3__F0_REG CYREG_B1_UDB07_F0
#define Random_TimerUDB_sT32_timerdp_u3__F1_REG CYREG_B1_UDB07_F1

/* Rx_1 */
#define Rx_1__0__INTTYPE CYREG_PICU2_INTTYPE0
#define Rx_1__0__MASK 0x01u
#define Rx_1__0__PC CYREG_PRT2_PC0
#define Rx_1__0__PORT 2u
#define Rx_1__0__SHIFT 0u
#define Rx_1__AG CYREG_PRT2_AG
#define Rx_1__AMUX CYREG_PRT2_AMUX
#define Rx_1__BIE CYREG_PRT2_BIE
#define Rx_1__BIT_MASK CYREG_PRT2_BIT_MASK
#define Rx_1__BYP CYREG_PRT2_BYP
#define Rx_1__CTL CYREG_PRT2_CTL
#define Rx_1__DM0 CYREG_PRT2_DM0
#define Rx_1__DM1 CYREG_PRT2_DM1
#define Rx_1__DM2 CYREG_PRT2_DM2
#define Rx_1__DR CYREG_PRT2_DR
#define Rx_1__INP_DIS CYREG_PRT2_INP_DIS
#define Rx_1__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU2_BASE
#define Rx_1__LCD_COM_SEG CYREG_PRT2_LCD_COM_SEG
#define Rx_1__LCD_EN CYREG_PRT2_LCD_EN
#define Rx_1__MASK 0x01u
#define Rx_1__PORT 2u
#define Rx_1__PRT CYREG_PRT2_PRT
#define Rx_1__PRTDSI__CAPS_SEL CYREG_PRT2_CAPS_SEL
#define Rx_1__PRTDSI__DBL_SYNC_IN CYREG_PRT2_DBL_SYNC_IN
#define Rx_1__PRTDSI__OE_SEL0 CYREG_PRT2_OE_SEL0
#define Rx_1__PRTDSI__OE_SEL1 CYREG_PRT2_OE_SEL1
#define Rx_1__PRTDSI__OUT_SEL0 CYREG_PRT2_OUT_SEL0
#define Rx_1__PRTDSI__OUT_SEL1 CYREG_PRT2_OUT_SEL1
#define Rx_1__PRTDSI__SYNC_OUT CYREG_PRT2_SYNC_OUT
#define Rx_1__PS CYREG_PRT2_PS
#define Rx_1__SHIFT 0u
#define Rx_1__SLW CYREG_PRT2_SLW

/* Timer */
#define Timer_TimerUDB_rstSts_stsreg__0__MASK 0x01u
#define Timer_TimerUDB_rstSts_stsreg__0__POS 0
#define Timer_TimerUDB_rstSts_stsreg__16BIT_STATUS_AUX_CTL_REG CYREG_B0_UDB06_07_ACTL
#define Timer_TimerUDB_rstSts_stsreg__16BIT_STATUS_REG CYREG_B0_UDB06_07_ST
#define Timer_TimerUDB_rstSts_stsreg__2__MASK 0x04u
#define Timer_TimerUDB_rstSts_stsreg__2__POS 2
#define Timer_TimerUDB_rstSts_stsreg__3__MASK 0x08u
#define Timer_TimerUDB_rstSts_stsreg__3__POS 3
#define Timer_TimerUDB_rstSts_stsreg__MASK 0x0Du
#define Timer_TimerUDB_rstSts_stsreg__MASK_REG CYREG_B0_UDB06_MSK
#define Timer_TimerUDB_rstSts_stsreg__STATUS_AUX_CTL_REG CYREG_B0_UDB06_ACTL
#define Timer_TimerUDB_rstSts_stsreg__STATUS_REG CYREG_B0_UDB06_ST
#define Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_CONTROL_AUX_CTL_REG CYREG_B0_UDB04_05_ACTL
#define Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_CONTROL_CONTROL_REG CYREG_B0_UDB04_05_CTL
#define Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_CONTROL_COUNT_REG CYREG_B0_UDB04_05_CTL
#define Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_COUNT_CONTROL_REG CYREG_B0_UDB04_05_CTL
#define Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_COUNT_COUNT_REG CYREG_B0_UDB04_05_CTL
#define Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_MASK_MASK_REG CYREG_B0_UDB04_05_MSK
#define Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_MASK_PERIOD_REG CYREG_B0_UDB04_05_MSK
#define Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_PERIOD_MASK_REG CYREG_B0_UDB04_05_MSK
#define Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_PERIOD_PERIOD_REG CYREG_B0_UDB04_05_MSK
#define Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__7__MASK 0x80u
#define Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__7__POS 7
#define Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_AUX_CTL_REG CYREG_B0_UDB04_ACTL
#define Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_REG CYREG_B0_UDB04_CTL
#define Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_ST_REG CYREG_B0_UDB04_ST_CTL
#define Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__COUNT_REG CYREG_B0_UDB04_CTL
#define Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__COUNT_ST_REG CYREG_B0_UDB04_ST_CTL
#define Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__MASK 0x80u
#define Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__MASK_CTL_AUX_CTL_REG CYREG_B0_UDB04_MSK_ACTL
#define Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__PER_CTL_AUX_CTL_REG CYREG_B0_UDB04_MSK_ACTL
#define Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__PERIOD_REG CYREG_B0_UDB04_MSK
#define Timer_TimerUDB_sT24_timerdp_u0__16BIT_A0_REG CYREG_B0_UDB04_05_A0
#define Timer_TimerUDB_sT24_timerdp_u0__16BIT_A1_REG CYREG_B0_UDB04_05_A1
#define Timer_TimerUDB_sT24_timerdp_u0__16BIT_D0_REG CYREG_B0_UDB04_05_D0
#define Timer_TimerUDB_sT24_timerdp_u0__16BIT_D1_REG CYREG_B0_UDB04_05_D1
#define Timer_TimerUDB_sT24_timerdp_u0__16BIT_DP_AUX_CTL_REG CYREG_B0_UDB04_05_ACTL
#define Timer_TimerUDB_sT24_timerdp_u0__16BIT_F0_REG CYREG_B0_UDB04_05_F0
#define Timer_TimerUDB_sT24_timerdp_u0__16BIT_F1_REG CYREG_B0_UDB04_05_F1
#define Timer_TimerUDB_sT24_timerdp_u0__A0_A1_REG CYREG_B0_UDB04_A0_A1
#define Timer_TimerUDB_sT24_timerdp_u0__A0_REG CYREG_B0_UDB04_A0
#define Timer_TimerUDB_sT24_timerdp_u0__A1_REG CYREG_B0_UDB04_A1
#define Timer_TimerUDB_sT24_timerdp_u0__D0_D1_REG CYREG_B0_UDB04_D0_D1
#define Timer_TimerUDB_sT24_timerdp_u0__D0_REG CYREG_B0_UDB04_D0
#define Timer_TimerUDB_sT24_timerdp_u0__D1_REG CYREG_B0_UDB04_D1
#define Timer_TimerUDB_sT24_timerdp_u0__DP_AUX_CTL_REG CYREG_B0_UDB04_ACTL
#define Timer_TimerUDB_sT24_timerdp_u0__F0_F1_REG CYREG_B0_UDB04_F0_F1
#define Timer_TimerUDB_sT24_timerdp_u0__F0_REG CYREG_B0_UDB04_F0
#define Timer_TimerUDB_sT24_timerdp_u0__F1_REG CYREG_B0_UDB04_F1
#define Timer_TimerUDB_sT24_timerdp_u0__MSK_DP_AUX_CTL_REG CYREG_B0_UDB04_MSK_ACTL
#define Timer_TimerUDB_sT24_timerdp_u0__PER_DP_AUX_CTL_REG CYREG_B0_UDB04_MSK_ACTL
#define Timer_TimerUDB_sT24_timerdp_u1__16BIT_A0_REG CYREG_B0_UDB05_06_A0
#define Timer_TimerUDB_sT24_timerdp_u1__16BIT_A1_REG CYREG_B0_UDB05_06_A1
#define Timer_TimerUDB_sT24_timerdp_u1__16BIT_D0_REG CYREG_B0_UDB05_06_D0
#define Timer_TimerUDB_sT24_timerdp_u1__16BIT_D1_REG CYREG_B0_UDB05_06_D1
#define Timer_TimerUDB_sT24_timerdp_u1__16BIT_DP_AUX_CTL_REG CYREG_B0_UDB05_06_ACTL
#define Timer_TimerUDB_sT24_timerdp_u1__16BIT_F0_REG CYREG_B0_UDB05_06_F0
#define Timer_TimerUDB_sT24_timerdp_u1__16BIT_F1_REG CYREG_B0_UDB05_06_F1
#define Timer_TimerUDB_sT24_timerdp_u1__A0_A1_REG CYREG_B0_UDB05_A0_A1
#define Timer_TimerUDB_sT24_timerdp_u1__A0_REG CYREG_B0_UDB05_A0
#define Timer_TimerUDB_sT24_timerdp_u1__A1_REG CYREG_B0_UDB05_A1
#define Timer_TimerUDB_sT24_timerdp_u1__D0_D1_REG CYREG_B0_UDB05_D0_D1
#define Timer_TimerUDB_sT24_timerdp_u1__D0_REG CYREG_B0_UDB05_D0
#define Timer_TimerUDB_sT24_timerdp_u1__D1_REG CYREG_B0_UDB05_D1
#define Timer_TimerUDB_sT24_timerdp_u1__DP_AUX_CTL_REG CYREG_B0_UDB05_ACTL
#define Timer_TimerUDB_sT24_timerdp_u1__F0_F1_REG CYREG_B0_UDB05_F0_F1
#define Timer_TimerUDB_sT24_timerdp_u1__F0_REG CYREG_B0_UDB05_F0
#define Timer_TimerUDB_sT24_timerdp_u1__F1_REG CYREG_B0_UDB05_F1
#define Timer_TimerUDB_sT24_timerdp_u2__16BIT_A0_REG CYREG_B0_UDB06_07_A0
#define Timer_TimerUDB_sT24_timerdp_u2__16BIT_A1_REG CYREG_B0_UDB06_07_A1
#define Timer_TimerUDB_sT24_timerdp_u2__16BIT_D0_REG CYREG_B0_UDB06_07_D0
#define Timer_TimerUDB_sT24_timerdp_u2__16BIT_D1_REG CYREG_B0_UDB06_07_D1
#define Timer_TimerUDB_sT24_timerdp_u2__16BIT_DP_AUX_CTL_REG CYREG_B0_UDB06_07_ACTL
#define Timer_TimerUDB_sT24_timerdp_u2__16BIT_F0_REG CYREG_B0_UDB06_07_F0
#define Timer_TimerUDB_sT24_timerdp_u2__16BIT_F1_REG CYREG_B0_UDB06_07_F1
#define Timer_TimerUDB_sT24_timerdp_u2__A0_A1_REG CYREG_B0_UDB06_A0_A1
#define Timer_TimerUDB_sT24_timerdp_u2__A0_REG CYREG_B0_UDB06_A0
#define Timer_TimerUDB_sT24_timerdp_u2__A1_REG CYREG_B0_UDB06_A1
#define Timer_TimerUDB_sT24_timerdp_u2__D0_D1_REG CYREG_B0_UDB06_D0_D1
#define Timer_TimerUDB_sT24_timerdp_u2__D0_REG CYREG_B0_UDB06_D0
#define Timer_TimerUDB_sT24_timerdp_u2__D1_REG CYREG_B0_UDB06_D1
#define Timer_TimerUDB_sT24_timerdp_u2__DP_AUX_CTL_REG CYREG_B0_UDB06_ACTL
#define Timer_TimerUDB_sT24_timerdp_u2__F0_F1_REG CYREG_B0_UDB06_F0_F1
#define Timer_TimerUDB_sT24_timerdp_u2__F0_REG CYREG_B0_UDB06_F0
#define Timer_TimerUDB_sT24_timerdp_u2__F1_REG CYREG_B0_UDB06_F1

/* Tx_1 */
#define Tx_1__0__INTTYPE CYREG_PICU2_INTTYPE1
#define Tx_1__0__MASK 0x02u
#define Tx_1__0__PC CYREG_PRT2_PC1
#define Tx_1__0__PORT 2u
#define Tx_1__0__SHIFT 1u
#define Tx_1__AG CYREG_PRT2_AG
#define Tx_1__AMUX CYREG_PRT2_AMUX
#define Tx_1__BIE CYREG_PRT2_BIE
#define Tx_1__BIT_MASK CYREG_PRT2_BIT_MASK
#define Tx_1__BYP CYREG_PRT2_BYP
#define Tx_1__CTL CYREG_PRT2_CTL
#define Tx_1__DM0 CYREG_PRT2_DM0
#define Tx_1__DM1 CYREG_PRT2_DM1
#define Tx_1__DM2 CYREG_PRT2_DM2
#define Tx_1__DR CYREG_PRT2_DR
#define Tx_1__INP_DIS CYREG_PRT2_INP_DIS
#define Tx_1__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU2_BASE
#define Tx_1__LCD_COM_SEG CYREG_PRT2_LCD_COM_SEG
#define Tx_1__LCD_EN CYREG_PRT2_LCD_EN
#define Tx_1__MASK 0x02u
#define Tx_1__PORT 2u
#define Tx_1__PRT CYREG_PRT2_PRT
#define Tx_1__PRTDSI__CAPS_SEL CYREG_PRT2_CAPS_SEL
#define Tx_1__PRTDSI__DBL_SYNC_IN CYREG_PRT2_DBL_SYNC_IN
#define Tx_1__PRTDSI__OE_SEL0 CYREG_PRT2_OE_SEL0
#define Tx_1__PRTDSI__OE_SEL1 CYREG_PRT2_OE_SEL1
#define Tx_1__PRTDSI__OUT_SEL0 CYREG_PRT2_OUT_SEL0
#define Tx_1__PRTDSI__OUT_SEL1 CYREG_PRT2_OUT_SEL1
#define Tx_1__PRTDSI__SYNC_OUT CYREG_PRT2_SYNC_OUT
#define Tx_1__PS CYREG_PRT2_PS
#define Tx_1__SHIFT 1u
#define Tx_1__SLW CYREG_PRT2_SLW

/* UART_BUART */
#define UART_BUART_sRX_RxBitCounter__16BIT_CONTROL_AUX_CTL_REG CYREG_B0_UDB14_15_ACTL
#define UART_BUART_sRX_RxBitCounter__16BIT_CONTROL_CONTROL_REG CYREG_B0_UDB14_15_CTL
#define UART_BUART_sRX_RxBitCounter__16BIT_CONTROL_COUNT_REG CYREG_B0_UDB14_15_CTL
#define UART_BUART_sRX_RxBitCounter__16BIT_COUNT_CONTROL_REG CYREG_B0_UDB14_15_CTL
#define UART_BUART_sRX_RxBitCounter__16BIT_COUNT_COUNT_REG CYREG_B0_UDB14_15_CTL
#define UART_BUART_sRX_RxBitCounter__16BIT_MASK_MASK_REG CYREG_B0_UDB14_15_MSK
#define UART_BUART_sRX_RxBitCounter__16BIT_MASK_PERIOD_REG CYREG_B0_UDB14_15_MSK
#define UART_BUART_sRX_RxBitCounter__16BIT_PERIOD_MASK_REG CYREG_B0_UDB14_15_MSK
#define UART_BUART_sRX_RxBitCounter__16BIT_PERIOD_PERIOD_REG CYREG_B0_UDB14_15_MSK
#define UART_BUART_sRX_RxBitCounter__CONTROL_AUX_CTL_REG CYREG_B0_UDB14_ACTL
#define UART_BUART_sRX_RxBitCounter__CONTROL_REG CYREG_B0_UDB14_CTL
#define UART_BUART_sRX_RxBitCounter__CONTROL_ST_REG CYREG_B0_UDB14_ST_CTL
#define UART_BUART_sRX_RxBitCounter__COUNT_REG CYREG_B0_UDB14_CTL
#define UART_BUART_sRX_RxBitCounter__COUNT_ST_REG CYREG_B0_UDB14_ST_CTL
#define UART_BUART_sRX_RxBitCounter__MASK_CTL_AUX_CTL_REG CYREG_B0_UDB14_MSK_ACTL
#define UART_BUART_sRX_RxBitCounter__PER_CTL_AUX_CTL_REG CYREG_B0_UDB14_MSK_ACTL
#define UART_BUART_sRX_RxBitCounter__PERIOD_REG CYREG_B0_UDB14_MSK
#define UART_BUART_sRX_RxBitCounter_ST__16BIT_STATUS_AUX_CTL_REG CYREG_B0_UDB14_15_ACTL
#define UART_BUART_sRX_RxBitCounter_ST__16BIT_STATUS_REG CYREG_B0_UDB14_15_ST
#define UART_BUART_sRX_RxBitCounter_ST__MASK_REG CYREG_B0_UDB14_MSK
#define UART_BUART_sRX_RxBitCounter_ST__MASK_ST_AUX_CTL_REG CYREG_B0_UDB14_MSK_ACTL
#define UART_BUART_sRX_RxBitCounter_ST__PER_ST_AUX_CTL_REG CYREG_B0_UDB14_MSK_ACTL
#define UART_BUART_sRX_RxBitCounter_ST__STATUS_AUX_CTL_REG CYREG_B0_UDB14_ACTL
#define UART_BUART_sRX_RxBitCounter_ST__STATUS_CNT_REG CYREG_B0_UDB14_ST_CTL
#define UART_BUART_sRX_RxBitCounter_ST__STATUS_CONTROL_REG CYREG_B0_UDB14_ST_CTL
#define UART_BUART_sRX_RxBitCounter_ST__STATUS_REG CYREG_B0_UDB14_ST
#define UART_BUART_sRX_RxShifter_u0__16BIT_A0_REG CYREG_B0_UDB13_14_A0
#define UART_BUART_sRX_RxShifter_u0__16BIT_A1_REG CYREG_B0_UDB13_14_A1
#define UART_BUART_sRX_RxShifter_u0__16BIT_D0_REG CYREG_B0_UDB13_14_D0
#define UART_BUART_sRX_RxShifter_u0__16BIT_D1_REG CYREG_B0_UDB13_14_D1
#define UART_BUART_sRX_RxShifter_u0__16BIT_DP_AUX_CTL_REG CYREG_B0_UDB13_14_ACTL
#define UART_BUART_sRX_RxShifter_u0__16BIT_F0_REG CYREG_B0_UDB13_14_F0
#define UART_BUART_sRX_RxShifter_u0__16BIT_F1_REG CYREG_B0_UDB13_14_F1
#define UART_BUART_sRX_RxShifter_u0__A0_A1_REG CYREG_B0_UDB13_A0_A1
#define UART_BUART_sRX_RxShifter_u0__A0_REG CYREG_B0_UDB13_A0
#define UART_BUART_sRX_RxShifter_u0__A1_REG CYREG_B0_UDB13_A1
#define UART_BUART_sRX_RxShifter_u0__D0_D1_REG CYREG_B0_UDB13_D0_D1
#define UART_BUART_sRX_RxShifter_u0__D0_REG CYREG_B0_UDB13_D0
#define UART_BUART_sRX_RxShifter_u0__D1_REG CYREG_B0_UDB13_D1
#define UART_BUART_sRX_RxShifter_u0__DP_AUX_CTL_REG CYREG_B0_UDB13_ACTL
#define UART_BUART_sRX_RxShifter_u0__F0_F1_REG CYREG_B0_UDB13_F0_F1
#define UART_BUART_sRX_RxShifter_u0__F0_REG CYREG_B0_UDB13_F0
#define UART_BUART_sRX_RxShifter_u0__F1_REG CYREG_B0_UDB13_F1
#define UART_BUART_sRX_RxSts__16BIT_STATUS_AUX_CTL_REG CYREG_B0_UDB13_14_ACTL
#define UART_BUART_sRX_RxSts__16BIT_STATUS_REG CYREG_B0_UDB13_14_ST
#define UART_BUART_sRX_RxSts__3__MASK 0x08u
#define UART_BUART_sRX_RxSts__3__POS 3
#define UART_BUART_sRX_RxSts__4__MASK 0x10u
#define UART_BUART_sRX_RxSts__4__POS 4
#define UART_BUART_sRX_RxSts__5__MASK 0x20u
#define UART_BUART_sRX_RxSts__5__POS 5
#define UART_BUART_sRX_RxSts__MASK 0x38u
#define UART_BUART_sRX_RxSts__MASK_REG CYREG_B0_UDB13_MSK
#define UART_BUART_sRX_RxSts__STATUS_AUX_CTL_REG CYREG_B0_UDB13_ACTL
#define UART_BUART_sRX_RxSts__STATUS_REG CYREG_B0_UDB13_ST
#define UART_BUART_sTX_sCLOCK_TxBitClkGen__A0_A1_REG CYREG_B0_UDB15_A0_A1
#define UART_BUART_sTX_sCLOCK_TxBitClkGen__A0_REG CYREG_B0_UDB15_A0
#define UART_BUART_sTX_sCLOCK_TxBitClkGen__A1_REG CYREG_B0_UDB15_A1
#define UART_BUART_sTX_sCLOCK_TxBitClkGen__D0_D1_REG CYREG_B0_UDB15_D0_D1
#define UART_BUART_sTX_sCLOCK_TxBitClkGen__D0_REG CYREG_B0_UDB15_D0
#define UART_BUART_sTX_sCLOCK_TxBitClkGen__D1_REG CYREG_B0_UDB15_D1
#define UART_BUART_sTX_sCLOCK_TxBitClkGen__DP_AUX_CTL_REG CYREG_B0_UDB15_ACTL
#define UART_BUART_sTX_sCLOCK_TxBitClkGen__F0_F1_REG CYREG_B0_UDB15_F0_F1
#define UART_BUART_sTX_sCLOCK_TxBitClkGen__F0_REG CYREG_B0_UDB15_F0
#define UART_BUART_sTX_sCLOCK_TxBitClkGen__F1_REG CYREG_B0_UDB15_F1
#define UART_BUART_sTX_TxShifter_u0__16BIT_A0_REG CYREG_B0_UDB12_13_A0
#define UART_BUART_sTX_TxShifter_u0__16BIT_A1_REG CYREG_B0_UDB12_13_A1
#define UART_BUART_sTX_TxShifter_u0__16BIT_D0_REG CYREG_B0_UDB12_13_D0
#define UART_BUART_sTX_TxShifter_u0__16BIT_D1_REG CYREG_B0_UDB12_13_D1
#define UART_BUART_sTX_TxShifter_u0__16BIT_DP_AUX_CTL_REG CYREG_B0_UDB12_13_ACTL
#define UART_BUART_sTX_TxShifter_u0__16BIT_F0_REG CYREG_B0_UDB12_13_F0
#define UART_BUART_sTX_TxShifter_u0__16BIT_F1_REG CYREG_B0_UDB12_13_F1
#define UART_BUART_sTX_TxShifter_u0__A0_A1_REG CYREG_B0_UDB12_A0_A1
#define UART_BUART_sTX_TxShifter_u0__A0_REG CYREG_B0_UDB12_A0
#define UART_BUART_sTX_TxShifter_u0__A1_REG CYREG_B0_UDB12_A1
#define UART_BUART_sTX_TxShifter_u0__D0_D1_REG CYREG_B0_UDB12_D0_D1
#define UART_BUART_sTX_TxShifter_u0__D0_REG CYREG_B0_UDB12_D0
#define UART_BUART_sTX_TxShifter_u0__D1_REG CYREG_B0_UDB12_D1
#define UART_BUART_sTX_TxShifter_u0__DP_AUX_CTL_REG CYREG_B0_UDB12_ACTL
#define UART_BUART_sTX_TxShifter_u0__F0_F1_REG CYREG_B0_UDB12_F0_F1
#define UART_BUART_sTX_TxShifter_u0__F0_REG CYREG_B0_UDB12_F0
#define UART_BUART_sTX_TxShifter_u0__F1_REG CYREG_B0_UDB12_F1
#define UART_BUART_sTX_TxSts__0__MASK 0x01u
#define UART_BUART_sTX_TxSts__0__POS 0
#define UART_BUART_sTX_TxSts__1__MASK 0x02u
#define UART_BUART_sTX_TxSts__1__POS 1
#define UART_BUART_sTX_TxSts__16BIT_STATUS_AUX_CTL_REG CYREG_B0_UDB12_13_ACTL
#define UART_BUART_sTX_TxSts__16BIT_STATUS_REG CYREG_B0_UDB12_13_ST
#define UART_BUART_sTX_TxSts__2__MASK 0x04u
#define UART_BUART_sTX_TxSts__2__POS 2
#define UART_BUART_sTX_TxSts__3__MASK 0x08u
#define UART_BUART_sTX_TxSts__3__POS 3
#define UART_BUART_sTX_TxSts__MASK 0x0Fu
#define UART_BUART_sTX_TxSts__MASK_REG CYREG_B0_UDB12_MSK
#define UART_BUART_sTX_TxSts__STATUS_AUX_CTL_REG CYREG_B0_UDB12_ACTL
#define UART_BUART_sTX_TxSts__STATUS_REG CYREG_B0_UDB12_ST

/* UART_IntClock */
#define UART_IntClock__CFG0 CYREG_CLKDIST_DCFG0_CFG0
#define UART_IntClock__CFG1 CYREG_CLKDIST_DCFG0_CFG1
#define UART_IntClock__CFG2 CYREG_CLKDIST_DCFG0_CFG2
#define UART_IntClock__CFG2_SRC_SEL_MASK 0x07u
#define UART_IntClock__INDEX 0x00u
#define UART_IntClock__PM_ACT_CFG CYREG_PM_ACT_CFG2
#define UART_IntClock__PM_ACT_MSK 0x01u
#define UART_IntClock__PM_STBY_CFG CYREG_PM_STBY_CFG2
#define UART_IntClock__PM_STBY_MSK 0x01u

/* user_btn */
#define user_btn__0__INTTYPE CYREG_PICU1_INTTYPE2
#define user_btn__0__MASK 0x04u
#define user_btn__0__PC CYREG_PRT1_PC2
#define user_btn__0__PORT 1u
#define user_btn__0__SHIFT 2u
#define user_btn__AG CYREG_PRT1_AG
#define user_btn__AMUX CYREG_PRT1_AMUX
#define user_btn__BIE CYREG_PRT1_BIE
#define user_btn__BIT_MASK CYREG_PRT1_BIT_MASK
#define user_btn__BYP CYREG_PRT1_BYP
#define user_btn__CTL CYREG_PRT1_CTL
#define user_btn__DM0 CYREG_PRT1_DM0
#define user_btn__DM1 CYREG_PRT1_DM1
#define user_btn__DM2 CYREG_PRT1_DM2
#define user_btn__DR CYREG_PRT1_DR
#define user_btn__INP_DIS CYREG_PRT1_INP_DIS
#define user_btn__INTSTAT CYREG_PICU1_INTSTAT
#define user_btn__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU1_BASE
#define user_btn__LCD_COM_SEG CYREG_PRT1_LCD_COM_SEG
#define user_btn__LCD_EN CYREG_PRT1_LCD_EN
#define user_btn__MASK 0x04u
#define user_btn__PORT 1u
#define user_btn__PRT CYREG_PRT1_PRT
#define user_btn__PRTDSI__CAPS_SEL CYREG_PRT1_CAPS_SEL
#define user_btn__PRTDSI__DBL_SYNC_IN CYREG_PRT1_DBL_SYNC_IN
#define user_btn__PRTDSI__OE_SEL0 CYREG_PRT1_OE_SEL0
#define user_btn__PRTDSI__OE_SEL1 CYREG_PRT1_OE_SEL1
#define user_btn__PRTDSI__OUT_SEL0 CYREG_PRT1_OUT_SEL0
#define user_btn__PRTDSI__OUT_SEL1 CYREG_PRT1_OUT_SEL1
#define user_btn__PRTDSI__SYNC_OUT CYREG_PRT1_SYNC_OUT
#define user_btn__PS CYREG_PRT1_PS
#define user_btn__SHIFT 2u
#define user_btn__SLW CYREG_PRT1_SLW
#define user_btn__SNAP CYREG_PICU1_SNAP

/* Miscellaneous */
#define BCLK__BUS_CLK__HZ 24000000U
#define BCLK__BUS_CLK__KHZ 24000U
#define BCLK__BUS_CLK__MHZ 24U
#define CY_PROJECT_NAME "LaboMenu"
#define CY_VERSION "PSoC Creator  4.1 Update 1"
#define CYDEV_CHIP_DIE_LEOPARD 1u
#define CYDEV_CHIP_DIE_PSOC4A 16u
#define CYDEV_CHIP_DIE_PSOC5LP 2u
#define CYDEV_CHIP_DIE_PSOC5TM 3u
#define CYDEV_CHIP_DIE_TMA4 4u
#define CYDEV_CHIP_DIE_UNKNOWN 0u
#define CYDEV_CHIP_FAMILY_FM0P 5u
#define CYDEV_CHIP_FAMILY_FM3 6u
#define CYDEV_CHIP_FAMILY_FM4 7u
#define CYDEV_CHIP_FAMILY_PSOC3 1u
#define CYDEV_CHIP_FAMILY_PSOC4 2u
#define CYDEV_CHIP_FAMILY_PSOC5 3u
#define CYDEV_CHIP_FAMILY_PSOC6 4u
#define CYDEV_CHIP_FAMILY_UNKNOWN 0u
#define CYDEV_CHIP_FAMILY_USED CYDEV_CHIP_FAMILY_PSOC5
#define CYDEV_CHIP_JTAG_ID 0x2E123069u
#define CYDEV_CHIP_MEMBER_3A 1u
#define CYDEV_CHIP_MEMBER_4A 16u
#define CYDEV_CHIP_MEMBER_4D 12u
#define CYDEV_CHIP_MEMBER_4E 6u
#define CYDEV_CHIP_MEMBER_4F 17u
#define CYDEV_CHIP_MEMBER_4G 4u
#define CYDEV_CHIP_MEMBER_4H 15u
#define CYDEV_CHIP_MEMBER_4I 21u
#define CYDEV_CHIP_MEMBER_4J 13u
#define CYDEV_CHIP_MEMBER_4K 14u
#define CYDEV_CHIP_MEMBER_4L 20u
#define CYDEV_CHIP_MEMBER_4M 19u
#define CYDEV_CHIP_MEMBER_4N 9u
#define CYDEV_CHIP_MEMBER_4O 7u
#define CYDEV_CHIP_MEMBER_4P 18u
#define CYDEV_CHIP_MEMBER_4Q 11u
#define CYDEV_CHIP_MEMBER_4R 8u
#define CYDEV_CHIP_MEMBER_4S 10u
#define CYDEV_CHIP_MEMBER_4U 5u
#define CYDEV_CHIP_MEMBER_5A 3u
#define CYDEV_CHIP_MEMBER_5B 2u
#define CYDEV_CHIP_MEMBER_6A 22u
#define CYDEV_CHIP_MEMBER_FM3 26u
#define CYDEV_CHIP_MEMBER_FM4 27u
#define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE1 23u
#define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE2 24u
#define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE3 25u
#define CYDEV_CHIP_MEMBER_UNKNOWN 0u
#define CYDEV_CHIP_MEMBER_USED CYDEV_CHIP_MEMBER_5B
#define CYDEV_CHIP_DIE_EXPECT CYDEV_CHIP_MEMBER_USED
#define CYDEV_CHIP_DIE_ACTUAL CYDEV_CHIP_DIE_EXPECT
#define CYDEV_CHIP_REV_LEOPARD_ES1 0u
#define CYDEV_CHIP_REV_LEOPARD_ES2 1u
#define CYDEV_CHIP_REV_LEOPARD_ES3 3u
#define CYDEV_CHIP_REV_LEOPARD_PRODUCTION 3u
#define CYDEV_CHIP_REV_PSOC4A_ES0 17u
#define CYDEV_CHIP_REV_PSOC4A_PRODUCTION 17u
#define CYDEV_CHIP_REV_PSOC5LP_ES0 0u
#define CYDEV_CHIP_REV_PSOC5LP_PRODUCTION 0u
#define CYDEV_CHIP_REV_PSOC5TM_ES0 0u
#define CYDEV_CHIP_REV_PSOC5TM_ES1 1u
#define CYDEV_CHIP_REV_PSOC5TM_PRODUCTION 1u
#define CYDEV_CHIP_REV_TMA4_ES 17u
#define CYDEV_CHIP_REV_TMA4_ES2 33u
#define CYDEV_CHIP_REV_TMA4_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_3A_ES1 0u
#define CYDEV_CHIP_REVISION_3A_ES2 1u
#define CYDEV_CHIP_REVISION_3A_ES3 3u
#define CYDEV_CHIP_REVISION_3A_PRODUCTION 3u
#define CYDEV_CHIP_REVISION_4A_ES0 17u
#define CYDEV_CHIP_REVISION_4A_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_4D_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4E_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION_256K 0u
#define CYDEV_CHIP_REVISION_4G_ES 17u
#define CYDEV_CHIP_REVISION_4G_ES2 33u
#define CYDEV_CHIP_REVISION_4G_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_4H_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4I_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4J_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4K_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4L_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4M_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4N_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4O_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4P_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4Q_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4R_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4S_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4U_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_5A_ES0 0u
#define CYDEV_CHIP_REVISION_5A_ES1 1u
#define CYDEV_CHIP_REVISION_5A_PRODUCTION 1u
#define CYDEV_CHIP_REVISION_5B_ES0 0u
#define CYDEV_CHIP_REVISION_5B_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_6A_NO_UDB 0u
#define CYDEV_CHIP_REVISION_6A_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_FM3_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_FM4_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE1_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE2_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE3_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_USED CYDEV_CHIP_REVISION_5B_PRODUCTION
#define CYDEV_CHIP_REV_EXPECT CYDEV_CHIP_REVISION_USED
#define CYDEV_CONFIG_FASTBOOT_ENABLED 1
#define CYDEV_CONFIG_UNUSED_IO_AllowButWarn 0
#define CYDEV_CONFIG_UNUSED_IO CYDEV_CONFIG_UNUSED_IO_AllowButWarn
#define CYDEV_CONFIG_UNUSED_IO_AllowWithInfo 1
#define CYDEV_CONFIG_UNUSED_IO_Disallowed 2
#define CYDEV_CONFIGURATION_COMPRESSED 1
#define CYDEV_CONFIGURATION_DMA 0
#define CYDEV_CONFIGURATION_ECC 1
#define CYDEV_CONFIGURATION_IMOENABLED CYDEV_CONFIG_FASTBOOT_ENABLED
#define CYDEV_CONFIGURATION_MODE_COMPRESSED 0
#define CYDEV_CONFIGURATION_MODE CYDEV_CONFIGURATION_MODE_COMPRESSED
#define CYDEV_CONFIGURATION_MODE_DMA 2
#define CYDEV_CONFIGURATION_MODE_UNCOMPRESSED 1
#define CYDEV_DEBUG_ENABLE_MASK 0x20u
#define CYDEV_DEBUG_ENABLE_REGISTER CYREG_MLOGIC_DEBUG
#define CYDEV_DEBUGGING_DPS_Disable 3
#define CYDEV_DEBUGGING_DPS_JTAG_4 1
#define CYDEV_DEBUGGING_DPS_JTAG_5 0
#define CYDEV_DEBUGGING_DPS_SWD 2
#define CYDEV_DEBUGGING_DPS_SWD_SWV 6
#define CYDEV_DEBUGGING_DPS CYDEV_DEBUGGING_DPS_SWD_SWV
#define CYDEV_DEBUGGING_ENABLE 1
#define CYDEV_DEBUGGING_XRES 0
#define CYDEV_DMA_CHANNELS_AVAILABLE 24u
#define CYDEV_ECC_ENABLE 0
#define CYDEV_HEAP_SIZE 0x80
#define CYDEV_INSTRUCT_CACHE_ENABLED 1
#define CYDEV_INTR_RISING 0x00000000u
#define CYDEV_IS_EXPORTING_CODE 0
#define CYDEV_IS_IMPORTING_CODE 0
#define CYDEV_PROJ_TYPE 0
#define CYDEV_PROJ_TYPE_BOOTLOADER 1
#define CYDEV_PROJ_TYPE_LAUNCHER 5
#define CYDEV_PROJ_TYPE_LOADABLE 2
#define CYDEV_PROJ_TYPE_LOADABLEANDBOOTLOADER 4
#define CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER 3
#define CYDEV_PROJ_TYPE_STANDARD 0
#define CYDEV_PROTECTION_ENABLE 0
#define CYDEV_STACK_SIZE 0x0800
#define CYDEV_USE_BUNDLED_CMSIS 1
#define CYDEV_VARIABLE_VDDA 0
#define CYDEV_VDDA 5.0
#define CYDEV_VDDA_MV 5000
#define CYDEV_VDDD 5.0
#define CYDEV_VDDD_MV 5000
#define CYDEV_VDDIO0 5.0
#define CYDEV_VDDIO0_MV 5000
#define CYDEV_VDDIO1 5.0
#define CYDEV_VDDIO1_MV 5000
#define CYDEV_VDDIO2 5.0
#define CYDEV_VDDIO2_MV 5000
#define CYDEV_VDDIO3 5.0
#define CYDEV_VDDIO3_MV 5000
#define CYDEV_VIO0 5.0
#define CYDEV_VIO0_MV 5000
#define CYDEV_VIO1 5.0
#define CYDEV_VIO1_MV 5000
#define CYDEV_VIO2 5.0
#define CYDEV_VIO2_MV 5000
#define CYDEV_VIO3 5.0
#define CYDEV_VIO3_MV 5000
#define CYIPBLOCK_ARM_CM3_VERSION 0
#define CYIPBLOCK_P3_ANAIF_VERSION 0
#define CYIPBLOCK_P3_CAN_VERSION 0
#define CYIPBLOCK_P3_CAPSENSE_VERSION 0
#define CYIPBLOCK_P3_COMP_VERSION 0
#define CYIPBLOCK_P3_DECIMATOR_VERSION 0
#define CYIPBLOCK_P3_DFB_VERSION 0
#define CYIPBLOCK_P3_DMA_VERSION 0
#define CYIPBLOCK_P3_DRQ_VERSION 0
#define CYIPBLOCK_P3_DSM_VERSION 0
#define CYIPBLOCK_P3_EMIF_VERSION 0
#define CYIPBLOCK_P3_I2C_VERSION 0
#define CYIPBLOCK_P3_LCD_VERSION 0
#define CYIPBLOCK_P3_LPF_VERSION 0
#define CYIPBLOCK_P3_OPAMP_VERSION 0
#define CYIPBLOCK_P3_PM_VERSION 0
#define CYIPBLOCK_P3_SCCT_VERSION 0
#define CYIPBLOCK_P3_TIMER_VERSION 0
#define CYIPBLOCK_P3_USB_VERSION 0
#define CYIPBLOCK_P3_VIDAC_VERSION 0
#define CYIPBLOCK_P3_VREF_VERSION 0
#define CYIPBLOCK_S8_GPIO_VERSION 0
#define CYIPBLOCK_S8_IRQ_VERSION 0
#define CYIPBLOCK_S8_SAR_VERSION 0
#define CYIPBLOCK_S8_SIO_VERSION 0
#define CYIPBLOCK_S8_UDB_VERSION 0
#define DMA_CHANNELS_USED__MASK0 0x00000000u
#define CYDEV_BOOTLOADER_ENABLE 0

#endif /* INCLUDED_CYFITTER_H */
