/*
*         Copyright (c), NXP Semiconductors Gratkorn / Austria
*
*                     (C)NXP Semiconductors
*       All rights are reserved. Reproduction in whole or in part is
*      prohibited without the written consent of the copyright owner.
*  NXP reserves the right to make changes without notice at any time.
* NXP makes no warranty, expressed, implied or statutory, including but
* not limited to any implied warranty of merchantability or fitness for any
*particular purpose, or that the use will not infringe any third party patent,
* copyright or trademark. NXP must not be liable for any loss or damage
*                          arising from its use.
*/

/** \file
* Command functions for Ncx3320 specific HAL-Component of Reader Library Framework.
* $Author: Purnank G (ing05193) $
* $Revision: 5076 $ (v05.22.00)
* $Date: 2016-06-13 17:29:09 +0530 (Mon, 13 Jun 2016) $
*
* History:
*  CHu: Generated 19. March 2010
*
*/
#include <phhalHw.h>
#include <phDriver.h>
#include <ph_RefDefs.h>
#include <phNxpNfcRdLib_Config.h>

#ifdef NXPBUILD__PHHAL_HW_NCx3320
#include <BoardSelection.h>

#include "phhalHw_Ncx3320.h"
#include "phhalHw_Ncx3320_Int.h"
#include "phhalHw_Ncx3320_Config.h"
#include <phhalHw_Ncx3320_Reg.h>
#include <phhalHw_Ncx3320_Cmd.h>

#ifdef   LPCD_DEBUG
#include <stdio.h>
#define  DEBUG_PRINTF(...) printf(__VA_ARGS__)
#else
#define  DEBUG_PRINTF(...)
#endif

/*******************************************************************************
**   Function Declarations
*******************************************************************************/
static phStatus_t phhalHw_Ncx3320_Int_LoadTimer(
    phhalHw_Ncx3320_DataParams_t * pDataParams,
    uint32_t dwReload,
    uint8_t  bTimerAdd
    );


static phStatus_t phhalHw_Ncx3320_Int_LoadTimer(
    phhalHw_Ncx3320_DataParams_t * pDataParams,
    uint32_t dwReload,
    uint8_t  bTimerAdd
    )
{
    phStatus_t  PH_MEMLOC_REM statusTmp;

    if (dwReload > PHHAL_HW_NCx3320_TIMER_RELOAD_MAX)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_HAL);
    }

    /* Write Timer reload value to High and Low registers. */
    PH_CHECK_SUCCESS_FCT(statusTmp, phhalHw_Ncx3320_WriteRegister(pDataParams, bTimerAdd, (uint8_t)(dwReload >> 8U)));
    return phhalHw_Ncx3320_WriteRegister(pDataParams, (bTimerAdd + 1U), (uint8_t)(dwReload));
}

static phStatus_t phhalHw_Ncx3320_Cmd_LpcdAdjustiLoad(phhalHw_Ncx3320_DataParams_t * pDataParams,
		uint8_t bLpcdMatrix[15][3], uint8_t * iLoadSetting);

static phStatus_t phhalHw_Ncx3320_Cmd_LpcdAdjustiLoad(phhalHw_Ncx3320_DataParams_t * pDataParams,
		uint8_t bLpcdMatrix[15][3], uint8_t * iLoadSetting)
{
	uint8_t higher_border = 0U, lower_border = 1U, lower_border_temp = 1U;
	uint8_t index = 0U;
	uint8_t stable_window = 1U;
	uint8_t stable_window_temp = 1U;
	uint8_t pos_q_direction = 0U;
	uint8_t neg_q_direction = 0U;
	uint8_t bChannel0 = pDataParams->bTxiChannel, bChannel1;
	/*------------------------------------------*/
	/* Look for the longest stable region in I. */
	/*------------------------------------------*/
	if (bChannel0 > 1U)
	{
		return PH_ERR_PARAMETER_OVERFLOW;
	}
	bChannel1 = bChannel0 ^ 1U;
	/* We start with index 1 which means we compare tx iLoad setting 2 to setting 1.
	 * Be careful: setting zero is by default excluded from this input table. */
	for (index = 1; index < PHHAL_HW_NCx3320_VALUE_TXILOAD_15; index++)
	{
		/* Is the I value still the same? */
		if ((bLpcdMatrix[index][bChannel0]) == (bLpcdMatrix[index - 1U][bChannel0]))
		{
			stable_window_temp++;

			/* We need to evaluate this in case the longer window is at the end of the Matrix. */
			if (index == 14U)
			{
				/* Is the last window bigger or equal?
				 * We favour higher windows even if they have the same width */
				if (stable_window_temp >= stable_window)
				{
					/* Save the length of the window */
					stable_window = stable_window_temp;

					/* Set the higher border at the first point outside the Matrix.
					 * This keeps the calculation method consistent. */
					lower_border = lower_border_temp;
					higher_border = 15;
				}
			}
		}
		else
		{
			/* Is the new window bigger or equal?
			 * We favour higher windows even if they have the same width */
			if (stable_window_temp >= stable_window)
			{
				/* Save the length of the window */
				stable_window = stable_window_temp;

				/* Save the transition point */
				higher_border = index;
				lower_border = lower_border_temp;
			}
			/* Look for next stable window */
			stable_window_temp = 1U;
			lower_border_temp = index + 1U;
		}
	}

	/* Make decision if possible */
	if (stable_window < 3U)
	{
		/* The system is very unstable */
		/* We cannot calculate the middle point. Take absolute middle */
		*iLoadSetting = PHHAL_HW_NCx3320_VALUE_TXILOAD_08;

		/* Increase the delta for the I/Q */
		if (bChannel0 == 0U)
		{
			pDataParams->bIDelta = 1U;
			/*DEBUG_PRINTF("Delta of I increased\r\n");*/
		}
		else
		{
			pDataParams->bQDelta = 1U;
			/*DEBUG_PRINTF("Delta of Q increased\r\n");*/
		}
	}
	else
	{
		if (pDataParams->bTxiDirection == 0U)
		{
			/* If there is only one transition, use it as a reference */
			if((lower_border != PHHAL_HW_NCx3320_VALUE_TXILOAD_01) && (higher_border == PHHAL_HW_NCx3320_VALUE_TXILOAD_15))
			{
				/* Protect against big TxiDelta values */
				if((lower_border - 1U) > pDataParams->bTxiDelta)
				{
					*iLoadSetting = lower_border - 1U - (pDataParams->bTxiDelta);
				}
				else
				{
					*iLoadSetting = higher_border - (uint8_t)(pDataParams->bTxiDelta - (lower_border - 1U));
				}
			}
			else
			{
				/* Decision is the higher border point minus bTxiDelta */
				*iLoadSetting = higher_border - pDataParams->bTxiDelta;
			}
		}
		else
		{
			/* If there is only one transition, use it as a reference */
			if((lower_border == PHHAL_HW_NCx3320_VALUE_TXILOAD_01) && (higher_border != PHHAL_HW_NCx3320_VALUE_TXILOAD_15))
			{
				/* Protect against big TxiDelta values */
				if((higher_border + 1U + pDataParams->bTxiDelta) <= PHHAL_HW_NCx3320_VALUE_TXILOAD_15)
				{
					*iLoadSetting = higher_border + 1U + (pDataParams->bTxiDelta);
				}
				else
				{
					*iLoadSetting = lower_border + (uint8_t)(higher_border + pDataParams->bTxiDelta - PHHAL_HW_NCx3320_VALUE_TXILOAD_15);
				}
			}
			else
			{
				/* Decision is the lower border point plus bTxiDelta */
				*iLoadSetting = lower_border + pDataParams->bTxiDelta;
			}
		}
		if (*iLoadSetting > 15U)
		{
			*iLoadSetting = 15U;
		}

		/* If stable window is smaller than 5, increase I delta anyway. */
		/* The decision is kept as the middle point. */
		if (stable_window < 5U)
		{
			/* Increase the delta for the I/Q */
			if (bChannel0 == 0U)
			{
				pDataParams->bIDelta = 1U;
				/*DEBUG_PRINTF("Delta of I increased\r\n");*/
			}
			else
			{
				pDataParams->bQDelta = 1U;
				/*DEBUG_PRINTF("Delta of Q increased\r\n");*/
			}
		}

		/* Decision point falls next to change in the other channel */
		if (((bLpcdMatrix[(*iLoadSetting) - 1U][bChannel1]) != (bLpcdMatrix[(*iLoadSetting) - 2U][bChannel1]))
				|| ((bLpcdMatrix[(*iLoadSetting) - 1U][bChannel1]) != (bLpcdMatrix[(*iLoadSetting)][bChannel1])))
		{
			/* Increase the delta of the other channel */
			if (bChannel1 == 0U)
			{
				pDataParams->bIDelta = 1U;
				/*DEBUG_PRINTF("Delta of I increased\r\n");*/
			}
			else
			{
				pDataParams->bQDelta = 1U;
				/*DEBUG_PRINTF("Delta of Q increased\r\n");*/
			}
		}
	}

	/*-----------------------------------------------------------------*/
	/* Now we analyse the behaviour of the other channel if necessary. */
	/*-----------------------------------------------------------------*/

	/* If the channel's delta wasn't already increased, check it for instability */
	if ((pDataParams->bQDelta == 0U && bChannel0 == 0U) || (pDataParams->bIDelta == 0U && bChannel0 == 1U) )
	{
		for (index = 1U; index < 15U; index++)
		{
			/* Is the value bigger than the previous one? */
			if ((bLpcdMatrix[index][bChannel1]) > (bLpcdMatrix[index - 1U][bChannel1]))
			{
				pos_q_direction++;
			}
			else
			{
				if ((bLpcdMatrix[index][bChannel1]) < (bLpcdMatrix[index - 1U][bChannel1]))
				{
					neg_q_direction++;
				}
				else
				{
					;/* No change *//*MISRA Rule 15.7*/
				}
			}
			/* If it moves in both directions, increase channel delta to 1 */
			if ((pos_q_direction != 0U) && (neg_q_direction != 0U))
			{
				/* Increase the delta for the Q/I */
				if (bChannel0 == 0U)
				{
					pDataParams->bQDelta = 1U;
					/*DEBUG_PRINTF("Delta of Q increased\r\n");*/
				}
				else
				{
					pDataParams->bIDelta = 1U;
					/*DEBUG_PRINTF("Delta of I increased\r\n");*/
				}
				/* Instability detected, no need to check further */
				break;
			}
			else
			{
				/* Do nothing */
			}
		}
	}

	return PH_ERR_SUCCESS;
}

phStatus_t phhalHw_Ncx3320_Cmd_Lpcd_GetConfig(phhalHw_Ncx3320_DataParams_t * pDataParams,
		uint8_t * pI, uint8_t * pQ)
{
//alan 2020.12.03
	phStatus_t PH_MEMLOC_REM status = PH_ERR_SUCCESS;
	uint8_t PH_MEMLOC_REM bRegister = 0;
	uint8_t PH_MEMLOC_REM bValue = 0;
	uint32_t PH_MEMLOC_REM dwReload = 0;
	float32_t PH_MEMLOC_REM fReload = 0;

	uint8_t PH_MEMLOC_REM I_Value = 0;
	uint8_t PH_MEMLOC_REM Q_Value = 0;

	phhal_LPCD_Handle_t *pLpcdHandle = &pDataParams->bSmLpcdParams;

	switch (pLpcdHandle->bCalib_State)
	{
		case LPCD_CALIB_START:

			pLpcdHandle->bT4Config = 0;
			pLpcdHandle->bLpcdIndex = 0;
			pLpcdHandle->bLpcdIload = PHHAL_HW_NCx3320_VALUE_TXILOAD_01;
			pDataParams->bIDelta = 0;
			pDataParams->bQDelta = 0;

			pDataParams->bMode |= PHHAL_HW_NCx3320_CMD_LPCD_MODE_OPTION_TRIMM_LPO;
			/* Set Qmin register */
			(void) phhalHw_Ncx3320_WriteRegister(pDataParams, PHHAL_HW_NCx3320_REG_LPCD_QMIN,
					PHHAL_HW_NCx3320_LPCD_CALIBRATE_QMIN_REG);

			/* Set Qmax register */
			(void) phhalHw_Ncx3320_WriteRegister(pDataParams, PHHAL_HW_NCx3320_REG_LPCD_QMAX,
					PHHAL_HW_NCx3320_LPCD_CALIBRATE_QMAX_REG);

			/* Set Imin register */
			(void) phhalHw_Ncx3320_WriteRegister(pDataParams, PHHAL_HW_NCx3320_REG_LPCD_IMIN,
					PHHAL_HW_NCx3320_LPCD_CALIBRATE_IMIN_REG);

			/* Configure Charge Pump and Filter set by the Application. */
			(void) phhalHw_Ncx3320_WriteRegister(pDataParams, PHHAL_HW_NCx3320_REG_LPCD_OPTIONS,
					(pDataParams->bLpcdOption
							& (PHHAL_HW_NCx3320_BIT_LPCD_CHARGEPUMP
									| PHHAL_HW_NCx3320_BIT_LPCD_FILTER)));

			/* Set Mix2Adc bit for LPCD mode */
			(void) phhalHw_Ncx3320_ReadRegister(pDataParams, PHHAL_HW_NCx3320_REG_RCV, &bRegister);
			bRegister |= PHHAL_HW_NCx3320_BIT_RX_SHORT_MIX2ADC;
			(void) phhalHw_Ncx3320_WriteRegister(pDataParams, PHHAL_HW_NCx3320_REG_RCV, bRegister);

			/* Calculate timer 3 (Detection Time) reload value */
			fReload =  (float32_t)pDataParams->wDetectionTimeUs * PHHAL_HW_NCx3320_TIMER0_FREQ;
			dwReload = (uint32_t)fReload;
			(void) phhalHw_Ncx3320_Int_LoadTimer(pDataParams, dwReload,
					PHHAL_HW_NCx3320_REG_T3RELOADHI);
			/*MISRA C-2012 Rule 2.2
			 dwReload = (uint32_t)((uint32_t)pDataParams->wPowerDownTimeMs * 16U);*/
			/* Set timer 4 (wPowerDownTimeMs) to minimum with LFO (16khz) clock used as last two bits of T4Control = 00b */
			(void) phhalHw_Ncx3320_Int_LoadTimer(pDataParams, 80u, PHHAL_HW_NCx3320_REG_T4RELOADHI);

			/* Set AutoTrimm bit if requested */
			if (0U != (pDataParams->bMode & PHHAL_HW_NCx3320_CMD_LPCD_MODE_OPTION_TRIMM_LPO)) /*MISRA Rule 14.4*/
			{
				pLpcdHandle->bT4Config |= PHHAL_HW_NCx3320_BIT_T4AUTOTRIMM;
			}

			/* Configure T4 for AutoLPCD and AutoRestart / Autowakeup */
			pLpcdHandle->bT4Config |= PHHAL_HW_NCx3320_BIT_T4AUTOLPCD
					| PHHAL_HW_NCx3320_BIT_T4AUTORESTARTED | PHHAL_HW_NCx3320_BIT_T4AUTOWAKEUP;
			/* Use 16Khz LFO */
			pLpcdHandle->bT4Config |= PHHAL_HW_NCx3320_VALUE_TCLK_LFO_16_KHZ;
			/* Start T4 */
			pLpcdHandle->bT4Config |= PHHAL_HW_NCx3320_BIT_T4STARTSTOPNOW
					| PHHAL_HW_NCx3320_BIT_T4RUNNING;

			pLpcdHandle->bCalib_State = LPCD_CALIB_CMD_REQ;
			break;
		case LPCD_CALIB_CMD_REQ:

			/* Update TxiLoad setting for the next calibration point */
			status = phhalHw_Ncx3320_ReadRegister(pDataParams, PHHAL_HW_NCx3320_REG_TXI,
					&bRegister);
			if ((status & PH_ERR_MASK) != PH_ERR_SUCCESS)
			{
				pLpcdHandle->bCalib_State = LPCD_CALIB_START;
				/* Expected error */
				return PH_ADD_COMPCODE(status, PH_COMP_HAL);
			}
			bValue = ((bRegister & (uint8_t) PHHAL_HW_NCx3320_MASK_TXILOAD))
					| pLpcdHandle->bLpcdIload;
			/* Only perform the operation, if the new value is different */
			if (bValue != bRegister)
			{
				(void) phhalHw_Ncx3320_WriteRegister(pDataParams, PHHAL_HW_NCx3320_REG_TXI, bValue);
			}

			/* If the filter is activated read I/Q unstable bit. */
			if (0U != (pDataParams->bLpcdOption & PHHAL_HW_NCx3320_BIT_LPCD_FILTER))
			{
				/* Clear LPCD result :  this is commented to avoid more than one pulse during the calibration */
				(void) phhalHw_Ncx3320_WriteRegister(pDataParams,
						PHHAL_HW_NCx3320_REG_LPCD_RESULT_Q, PHHAL_HW_NCx3320_BIT_LPCDIRQ_CLR);
			}

			/* Write T4Control register */
			(void) phhalHw_Ncx3320_WriteRegister(pDataParams, PHHAL_HW_NCx3320_REG_T4CONTROL,
					pLpcdHandle->bT4Config);
			/* Wait until T4 is started*/
			do
			{
				(void) phhalHw_Ncx3320_ReadRegister(pDataParams, PHHAL_HW_NCx3320_REG_T4CONTROL,
						&bRegister);
			} while (0U == (bRegister & PHHAL_HW_NCx3320_BIT_T4RUNNING));

			/* start the command */
			(void) phhalHw_Ncx3320_WriteRegister(pDataParams, PHHAL_HW_NCx3320_REG_COMMAND,
					PHHAL_HW_NCx3320_CMD_LPCD | PHHAL_HW_NCx3320_BIT_STANDBY);

			pLpcdHandle->bCalib_State = LPCD_CALIB_CMD_WAITRSP;
			break;
		case LPCD_CALIB_CMD_WAITRSP:
			/* Wait until power up mode */
			/* Read command register */
			(void) phhalHw_Ncx3320_ReadRegister(pDataParams, PHHAL_HW_NCx3320_REG_COMMAND,
					&bRegister);
			if (bRegister != PHHAL_HW_NCx3320_CMD_IDLE)
			{
				/* Continuous to check status  */
				/* Return PH_STATUS_INPROCESS */
				break;

			}
			/* Power up occurred, go to next process */

			/* Stop Timer4 if started */
			(void) phhalHw_Ncx3320_ReadRegister(pDataParams, PHHAL_HW_NCx3320_REG_T4CONTROL, &bRegister);
			bRegister |= PHHAL_HW_NCx3320_BIT_T4STARTSTOPNOW;
			bRegister &= (uint8_t) ~(uint8_t) PHHAL_HW_NCx3320_BIT_T4RUNNING;
			(void) phhalHw_Ncx3320_WriteRegister(pDataParams, PHHAL_HW_NCx3320_REG_T4CONTROL, bRegister);
			do
			{
				(void) phhalHw_Ncx3320_ReadRegister(pDataParams, PHHAL_HW_NCx3320_REG_T4CONTROL,
						&bRegister);
			} while (0U != (bRegister & PHHAL_HW_NCx3320_BIT_T4RUNNING));

			/* Retrieve I and Q results */
			(void) phhalHw_Ncx3320_ReadRegister(pDataParams, PHHAL_HW_NCx3320_REG_LPCD_RESULT_I, &I_Value);
			(void) phhalHw_Ncx3320_ReadRegister(pDataParams, PHHAL_HW_NCx3320_REG_LPCD_RESULT_Q, &Q_Value);

			/* If the filter is activated read I/Q unstable bit. */
			if (0U != (pDataParams->bLpcdOption & PHHAL_HW_NCx3320_BIT_LPCD_FILTER))
			{
				(void) phhalHw_Ncx3320_ReadRegister(pDataParams, PHHAL_HW_NCx3320_REG_LPCD_OPTIONS,	&bRegister);
				pDataParams->bLpcdOption |= bRegister & (PHHAL_HW_NCx3320_BIT_LPCD_Q_UNSTABLE | PHHAL_HW_NCx3320_BIT_LPCD_I_UNSTABLE);
			}
			else
			{
				bRegister = 0x00;
			}

			if (pLpcdHandle->bLpcdIndex < PHHAL_HW_NCx3320_VALUE_TXILOAD_15)
			{
				/* Mask out irrelevant bits and store calibration values */
				pLpcdHandle->bLpcdMatrix[pLpcdHandle->bLpcdIndex][0] = I_Value & 0x3FU;
				pLpcdHandle->bLpcdMatrix[pLpcdHandle->bLpcdIndex][1] = Q_Value & 0x3FU;
				pLpcdHandle->bLpcdMatrix[pLpcdHandle->bLpcdIndex][2] = bRegister;
			}

			/* Only for debug */
			DEBUG_PRINTF("LPCD:CALIB %02X, I= 0x%02X, Q= 0x%02X\r\n", pLpcdHandle->bLpcdIndex + 1U,
					(I_Value & 0x3FU), (Q_Value & 0x3FU));

			if (pLpcdHandle->bLpcdIload == PHHAL_HW_NCx3320_VALUE_TXILOAD_15)
			{
				pLpcdHandle->bCalib_State = LPCD_CALIB_FINISH;
			}
			else
			{
				/* Calibrate with next iLoad settings */
				pLpcdHandle->bLpcdIload++;
				pLpcdHandle->bLpcdIndex++;
				pLpcdHandle->bCalib_State = LPCD_CALIB_CMD_REQ;
			}
			break;
		case LPCD_CALIB_FINISH:

			pLpcdHandle->bCalib_State = LPCD_CALIB_START;
			/* Adjust iLoad settings */
			(void) phhalHw_Ncx3320_Cmd_LpcdAdjustiLoad(pDataParams, pLpcdHandle->bLpcdMatrix,
					&pLpcdHandle->bLpcdIload);

			/* Clear Mix2Adc bit */
			status = phhalHw_Ncx3320_ReadRegister(pDataParams, PHHAL_HW_NCx3320_REG_RCV, &bRegister);
			if ((status & PH_ERR_MASK) != PH_ERR_SUCCESS)
			{
				/* error returning */
				return PH_ADD_COMPCODE(status, PH_COMP_HAL);
			}

			bRegister &= (uint8_t) ~(uint8_t) PHHAL_HW_NCx3320_BIT_RX_SHORT_MIX2ADC;
			(void) phhalHw_Ncx3320_WriteRegister(pDataParams, PHHAL_HW_NCx3320_REG_RCV, bRegister);

			DEBUG_PRINTF("LPCD:ILOAD: %02X\r\n", pLpcdHandle->bLpcdIload);

			/* Update TxiLoad setting after adjustment */
			(void) phhalHw_Ncx3320_ReadRegister(pDataParams, PHHAL_HW_NCx3320_REG_TXI, &bRegister);
			bValue = ((bRegister & (uint8_t) PHHAL_HW_NCx3320_MASK_TXILOAD)) | pLpcdHandle->bLpcdIload;

			/* Only perform the operation, if the new value is different */
			if (bValue != bRegister)
			{
				(void) phhalHw_Ncx3320_WriteRegister(pDataParams, PHHAL_HW_NCx3320_REG_TXI, bValue);
			}

			/* Store Tx-iLoad for LPCD calibration */
			pDataParams->bTxiLoad = (uint8_t) pLpcdHandle->bLpcdIload;

			/* Retrieve I and Q results */
			if ((pI != NULL) && (pQ != NULL))
			{
				*pI = pLpcdHandle->bLpcdMatrix[pLpcdHandle->bLpcdIload - 1U][0];
				*pQ = pLpcdHandle->bLpcdMatrix[pLpcdHandle->bLpcdIload - 1U][1];
			}

		    /* consume all the event generated in Hal */
		    (void) phhalHw_EventConsume(pDataParams);

			/* Return result */
			return PH_ERR_SUCCESS;
			/*break;*//*Rule 2.1*/
		default:
			pLpcdHandle->bCalib_State = LPCD_CALIB_START;
			/* unexpected error*/
			return PH_ADD_COMPCODE(PH_ERR_EVENT_FAILURE, PH_COMP_HAL);
			/*break;*//*Rule 2.1*/
	}

	return PH_STATUS_INPROCESS;
}

phStatus_t phhalHw_Ncx3320_Cmd_Lpcd(
                                  phhalHw_Ncx3320_DataParams_t * pDataParams
                                  )
{
    phStatus_t  PH_MEMLOC_REM status;
    phStatus_t  PH_MEMLOC_REM statusTmp;
	uint8_t PH_MEMLOC_REM aCmd = 0u;
	uint16_t PH_MEMLOC_REM wOption = 0u;
	uint8_t PH_MEMLOC_REM bIrq0WaitFor = 0u;
	uint8_t PH_MEMLOC_REM bIrq1WaitFor = 0u;
	uint32_t PH_MEMLOC_REM dwReload = 0u;
    float32_t   PH_MEMLOC_REM fReload;
    uint8_t     PH_MEMLOC_REM bRxAnaBackup;
	uint8_t PH_MEMLOC_REM bQMin = 0u;
	uint8_t PH_MEMLOC_REM bQMax = 0u;
	uint8_t PH_MEMLOC_REM bIMin = 0u;
	uint8_t PH_MEMLOC_REM bIMax = 0u;
	uint8_t PH_MEMLOC_REM bRegister = 0u;

    /* Configure T4 for AutoLPCD and Autowakeup and to use 16KHz LFO. */
    bRegister = PHHAL_HW_NCx3320_BIT_T4AUTOLPCD | PHHAL_HW_NCx3320_BIT_T4AUTOWAKEUP |
        PHHAL_HW_NCx3320_VALUE_TCLK_LFO_16_KHZ;

    /* Parameter check */
    switch (pDataParams->bMode & (uint8_t)~(uint8_t)PHHAL_HW_NCx3320_CMD_LPCD_MODE_OPTION_MASK)
    {
    case PHHAL_HW_NCx3320_CMD_LPCD_MODE_DEFAULT:
        break;

    case PHHAL_HW_NCx3320_CMD_LPCD_MODE_POWERDOWN_GUARDED:
    case PHHAL_HW_NCx3320_CMD_LPCD_MODE_POWERDOWN:

        /* Configure T4 additionally with AutoRestart to start T4 after every RFON during LPCD
         * to continue standby + rfon cycle continuously to detect antenna de-tuning. */
        bRegister |= PHHAL_HW_NCx3320_BIT_T4AUTORESTARTED;
        break;

    default:
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_HAL);
    }

    /* Calculate timer 3 reload value */
    fReload = (float32_t)pDataParams->wDetectionTimeUs * PHHAL_HW_NCx3320_TIMER0_FREQ;
    dwReload = (uint32_t)fReload;

    PH_CHECK_SUCCESS_FCT(statusTmp, phhalHw_Ncx3320_Int_LoadTimer(
        pDataParams,
        dwReload,
        PHHAL_HW_NCx3320_REG_T3RELOADHI));

    /* Calculate timer 4 reload value with LFO (16khz) clock used as last two bits of T4Control = 00b */
    dwReload = (uint32_t)((uint32_t)pDataParams->wPowerDownTimeMs * 16U);

    PH_CHECK_SUCCESS_FCT(statusTmp, phhalHw_Ncx3320_Int_LoadTimer(
        pDataParams,
        dwReload,
        PHHAL_HW_NCx3320_REG_T4RELOADHI));

    /* Set AutoTrimm bit if requested */
    if (0U != (pDataParams->bMode & PHHAL_HW_NCx3320_CMD_LPCD_MODE_OPTION_TRIMM_LPO))
    {
        bRegister |= PHHAL_HW_NCx3320_BIT_T4AUTOTRIMM;
    }

    /* Write T4Control register */
    PH_CHECK_SUCCESS_FCT(statusTmp, phhalHw_Ncx3320_WriteRegister(pDataParams, PHHAL_HW_NCx3320_REG_T4CONTROL, bRegister));
    //alan 2020.12.03
	/* Clear LPCD result */
	PH_CHECK_SUCCESS_FCT(statusTmp,
				phhalHw_Ncx3320_WriteRegister(pDataParams, PHHAL_HW_NCx3320_REG_LPCD_RESULT_Q, PHHAL_HW_NCx3320_BIT_LPCDIRQ_CLR));

    /* Set I & Q values */
    if ((0U == ((pDataParams->bMode & PHHAL_HW_NCx3320_CMD_LPCD_MODE_OPTION_IGNORE_IQ))))
    {
    //alan 2020.12.03
		if (pDataParams->bQ >= pDataParams->bQDelta)
		{
			bQMin = pDataParams->bQ - pDataParams->bQDelta;
		}
		else
		{
			bQMin = 0U;
		}
		if (pDataParams->bI > pDataParams->bIDelta)
		{
			bIMin = pDataParams->bI - pDataParams->bIDelta;
		}
		else
		{
			bIMin = 0U;
		}
		bQMax = pDataParams->bQ + pDataParams->bQDelta;
		bIMax = pDataParams->bI + pDataParams->bIDelta;
		if (bQMax > 0x3Fu)
		{
			bQMax = 0x3Fu;
		}
		if (bIMax > 0x3Fu)
		{
			bIMax = 0x3Fu;
		}

        /* Set Qmin register */
        bRegister = bQMin | (uint8_t)((bIMax & 0x30U) << 2U);
        PH_CHECK_SUCCESS_FCT(statusTmp, phhalHw_Ncx3320_WriteRegister(pDataParams, PHHAL_HW_NCx3320_REG_LPCD_QMIN, bRegister));

        /* Set Qmax register */
        bRegister = bQMax | (uint8_t)((bIMax & 0x0CU) << 4U);
        PH_CHECK_SUCCESS_FCT(statusTmp, phhalHw_Ncx3320_WriteRegister(pDataParams, PHHAL_HW_NCx3320_REG_LPCD_QMAX, bRegister));

        /* Set Imin register */
        bRegister = bIMin | (uint8_t)((bIMax & 0x03U) << 6U);
        PH_CHECK_SUCCESS_FCT(statusTmp, phhalHw_Ncx3320_WriteRegister(pDataParams, PHHAL_HW_NCx3320_REG_LPCD_IMIN, bRegister));
    }

    /* Set Mix2Adc bit */
    PH_CHECK_SUCCESS_FCT(statusTmp, phhalHw_Ncx3320_ReadRegister(pDataParams, PHHAL_HW_NCx3320_REG_RCV, &bRegister));
    bRegister |= PHHAL_HW_NCx3320_BIT_RX_SHORT_MIX2ADC;
    PH_CHECK_SUCCESS_FCT(statusTmp, phhalHw_Ncx3320_WriteRegister(pDataParams, PHHAL_HW_NCx3320_REG_RCV, bRegister));

    /* Backup current RxAna setting */
    PH_CHECK_SUCCESS_FCT(statusTmp, phhalHw_Ncx3320_ReadRegister(pDataParams, PHHAL_HW_NCx3320_REG_RXANA, &bRxAnaBackup));
    /* Raise receiver gain to maximum */
    PH_CHECK_SUCCESS_FCT(statusTmp, phhalHw_Ncx3320_WriteRegister(pDataParams, PHHAL_HW_NCx3320_REG_RXANA, PHHAL_HW_NCx3320_LPCD_RECEIVER_GAIN));

	/* Prepare command and option */
	aCmd = PHHAL_HW_NCx3320_CMD_LPCD;
	wOption = PH_EXCHANGE_DEFAULT;

	/* Prepare wait IRQs */
	bIrq0WaitFor = 0x00;
	bIrq1WaitFor = PHHAL_HW_NCx3320_BIT_LPCDIRQ;

	/* Set standby bit */
	aCmd |= PHHAL_HW_NCx3320_BIT_STANDBY;
	switch (pDataParams->bMode & (uint8_t) ~(uint8_t) PHHAL_HW_NCx3320_CMD_LPCD_MODE_OPTION_MASK)
	{
		case PHHAL_HW_NCx3320_CMD_LPCD_MODE_DEFAULT:
			bIrq1WaitFor |= PHHAL_HW_NCx3320_BIT_TIMER3IRQ;
			break;

		case PHHAL_HW_NCx3320_CMD_LPCD_MODE_POWERDOWN_GUARDED:
			/* start and wait for timer */
			/* This option is used as fall through mechanism to exit LPCD loop after certain LPCD cycles. */
			wOption |= PHHAL_HW_NCx3320_RXTX_TIMER_START;
			bIrq1WaitFor |= PHHAL_HW_NCx3320_BIT_TIMER1IRQ;
			break;
	}
    status = phhalHw_Ncx3320_Command_Int(
        pDataParams,
        aCmd,
        wOption,
        bIrq0WaitFor,
        bIrq1WaitFor,
        NULL,
        0,
        0,
        NULL,
        NULL);
    //alan 2020.12.03
	/* After doing _Command_int, restore Antenna cfg */
    /* Restore RxAna register */
    PH_CHECK_SUCCESS_FCT(statusTmp, phhalHw_Ncx3320_WriteRegister(pDataParams, PHHAL_HW_NCx3320_REG_RXANA, bRxAnaBackup));

    /* Clear Mix2Adc bit */
    PH_CHECK_SUCCESS_FCT(statusTmp, phhalHw_Ncx3320_ReadRegister(pDataParams, PHHAL_HW_NCx3320_REG_RCV, &bRegister));
    bRegister &= (uint8_t)~(uint8_t)PHHAL_HW_NCx3320_BIT_RX_SHORT_MIX2ADC;
    PH_CHECK_SUCCESS_FCT(statusTmp, phhalHw_Ncx3320_WriteRegister(pDataParams, PHHAL_HW_NCx3320_REG_RCV, bRegister));

    /* Stop Timer4 if started */
    PH_CHECK_SUCCESS_FCT(statusTmp, phhalHw_Ncx3320_ReadRegister(pDataParams, PHHAL_HW_NCx3320_REG_T4CONTROL, &bRegister));
    bRegister |= PHHAL_HW_NCx3320_BIT_T4STARTSTOPNOW;
    bRegister &= (uint8_t)~(uint8_t)PHHAL_HW_NCx3320_BIT_T4RUNNING;
    PH_CHECK_SUCCESS_FCT(statusTmp, phhalHw_Ncx3320_WriteRegister(pDataParams, PHHAL_HW_NCx3320_REG_T4CONTROL, bRegister));

    /* Stop the LPCD command */
    PH_CHECK_SUCCESS_FCT(statusTmp, phhalHw_Ncx3320_WriteRegister(
        pDataParams,
        PHHAL_HW_NCx3320_REG_COMMAND,
        PHHAL_HW_NCx3320_CMD_IDLE));

    /* Command error check (ignore timeout since interface could have been too slow) */
    if ((status & PH_ERR_MASK) != PH_ERR_IO_TIMEOUT)
    {
        PH_CHECK_SUCCESS(status);
    }

    /* Check if LPCD-IRQ is set */
    PH_CHECK_SUCCESS_FCT(statusTmp, phhalHw_Ncx3320_ReadRegister(pDataParams, PHHAL_HW_NCx3320_REG_IRQ1, &bRegister));

    /* Clear LPCD interrupt source to avoid any spurious LPCD_IRQ to be triggered. */
    PH_CHECK_SUCCESS_FCT(statusTmp, phhalHw_Ncx3320_WriteRegister(pDataParams, PHHAL_HW_NCx3320_REG_LPCD_RESULT_Q, PHHAL_HW_NCx3320_BIT_LPCDIRQ_CLR));

    if (0U == (bRegister & PHHAL_HW_NCx3320_BIT_LPCDIRQ))
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_IO_TIMEOUT, PH_COMP_HAL);
    }

    return PH_ERR_SUCCESS;
}


phStatus_t phhalHw_Ncx3320_Cmd_LoadKey(
                                     phhalHw_Ncx3320_DataParams_t * pDataParams,
                                     uint8_t * pKey
                                     )
{
    uint8_t PH_MEMLOC_REM bIrq0WaitFor;
    uint8_t PH_MEMLOC_REM bIrq1WaitFor;

    /* Set wait IRQs */
    bIrq0WaitFor = 0x00;
    bIrq1WaitFor = 0x00;

    /* Perform command */
    return phhalHw_Ncx3320_Command_Int(
        pDataParams,
        PHHAL_HW_NCx3320_CMD_LOADKEY,
        PH_EXCHANGE_DEFAULT,
        bIrq0WaitFor,
        bIrq1WaitFor,
        pKey,
        PHHAL_HW_NCx3320_MFC_KEY_LENGTH,
        0,
        NULL,
        NULL);
}

phStatus_t phhalHw_Ncx3320_Cmd_WriteE2(
                                     phhalHw_Ncx3320_DataParams_t * pDataParams,
                                     uint16_t wAddress,
                                     uint8_t bData
                                     )
{
    uint8_t PH_MEMLOC_REM aCmd[3];
    uint8_t PH_MEMLOC_REM bIrq0WaitFor;
    uint8_t PH_MEMLOC_REM bIrq1WaitFor;

    /* Check Address range */
    if (wAddress >= PHHAL_HW_NCx3320_EEPROM_SIZE)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_HAL);
    }

    /* Set wait IRQs */
    bIrq0WaitFor = 0x00;
    bIrq1WaitFor = 0x00;

    /* Prepare command */
    aCmd[0] = (uint8_t)(wAddress >> 8U);
    aCmd[1] = (uint8_t)(wAddress);
    aCmd[2] = bData;

    /* Perform command */
    return phhalHw_Ncx3320_Command_Int(
        pDataParams,
        PHHAL_HW_NCx3320_CMD_WRITEE2,
        PH_EXCHANGE_DEFAULT,
        bIrq0WaitFor,
        bIrq1WaitFor,
        aCmd,
        3,
        0,
        NULL,
        NULL);
}

phStatus_t phhalHw_Ncx3320_Cmd_WriteE2Page(
    phhalHw_Ncx3320_DataParams_t * pDataParams,
    uint16_t wAddress,
    uint8_t * pData,
    uint8_t bDataLen
    )
{
    phStatus_t  PH_MEMLOC_REM statusTmp;
    uint8_t     PH_MEMLOC_REM aCmd[2];
    uint8_t     PH_MEMLOC_REM bIrq0WaitFor;
    uint8_t     PH_MEMLOC_REM bIrq1WaitFor;
    uint16_t    PH_MEMLOC_REM wFifoBytes;

    /* Check Address range and data length */
    if ((wAddress >= PHHAL_HW_NCx3320_EEPROM_NUM_PAGES) || (bDataLen == 0U) || (bDataLen > PHHAL_HW_NCx3320_EEPROM_PAGE_SIZE))
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_HAL);
    }

    /* Set wait IRQs */
    bIrq0WaitFor = 0x00;
    bIrq1WaitFor = 0x00;

    /* Flush FiFo */
    PH_CHECK_SUCCESS_FCT(statusTmp, phhalHw_Ncx3320_FlushFifo(pDataParams));

    /* Write Address into FIFO */
    aCmd[1] = (uint8_t)(wAddress);
    PH_CHECK_SUCCESS_FCT(statusTmp, phhalHw_Ncx3320_WriteFifo(pDataParams, &aCmd[1], 1, &wFifoBytes));

    /* Perform command */
    return phhalHw_Ncx3320_Command_Int(
        pDataParams,
        PHHAL_HW_NCx3320_CMD_WRITEE2PAGE,
        PHHAL_HW_NCx3320_OPTION_FIFO_NOCLEAR,
        bIrq0WaitFor,
        bIrq1WaitFor,
        pData,
        (uint16_t)bDataLen,
        0,
        NULL,
        NULL);
}

phStatus_t phhalHw_Ncx3320_Cmd_ReadE2(
                                    phhalHw_Ncx3320_DataParams_t * pDataParams,
                                    uint16_t wAddress,
                                    uint16_t wNumBytes,
                                    uint8_t * pData
                                    )
{
    phStatus_t  PH_MEMLOC_REM statusTmp;
    uint8_t     PH_MEMLOC_REM aCmd[3];
    uint8_t     PH_MEMLOC_REM bIrq0WaitFor;
    uint8_t     PH_MEMLOC_REM bIrq1WaitFor;
    uint16_t    PH_MEMLOC_REM wDataLenTmp;

    /* Parameter check */
    if (wNumBytes > 0x100U)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_HAL);
    }

    /* 0 means 256, do this for the check below */
    if (wNumBytes == 0U)
    {
        wNumBytes = 0x100;
    }

    /* Limit number of bytes to read to FiFo-Size */
    if (pDataParams->bFifoSize == PH_NXPNFCRDLIB_CONFIG_NCx3320_VALUE_FIFOSIZE_255)
    {
        if (wNumBytes > 0xFFU)
        {
            return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_HAL);
        }
    }

    /* Check Address range */
    if ((wAddress + wNumBytes) > PHHAL_HW_NCx3320_EEPROM_SIZE)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_HAL);
    }

    /* Set wait IRQs */
    bIrq0WaitFor = PHHAL_HW_NCx3320_BIT_HIALERTIRQ;
    bIrq1WaitFor = 0x00;

    /* Prepare command */
    aCmd[0] = (uint8_t)(wAddress >> 8U);
    aCmd[1] = (uint8_t)(wAddress);
    aCmd[2] = (uint8_t)wNumBytes;

    /* Perform command */
    PH_CHECK_SUCCESS_FCT(statusTmp, phhalHw_Ncx3320_Command_Int(
        pDataParams,
        PHHAL_HW_NCx3320_CMD_READE2,
        PH_EXCHANGE_DEFAULT,
        bIrq0WaitFor,
        bIrq1WaitFor,
        aCmd,
        3,
        wNumBytes,
        pData,
        &wDataLenTmp));

    /* Check received data */
    if (wDataLenTmp != wNumBytes)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INTERNAL_ERROR, PH_COMP_HAL);
    }

    return PH_ERR_SUCCESS;
}

phStatus_t phhalHw_Ncx3320_Cmd_LoadReg(
                                     phhalHw_Ncx3320_DataParams_t * pDataParams,
                                     uint16_t wEEAddress,
                                     uint8_t bRegAddress,
                                     uint8_t bNumBytes
                                     )
{
    uint8_t PH_MEMLOC_REM aCmd[4];
    uint8_t PH_MEMLOC_REM bIrq0WaitFor;
    uint8_t PH_MEMLOC_REM bIrq1WaitFor;

    /* Parameter check */
    if (bNumBytes == 0U)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_HAL);
    }

    /* EEPROM address check */
    if ((wEEAddress < PHHAL_HW_NCx3320_EEPROM_SECTION2_BEGIN) || ((wEEAddress + bNumBytes) > (PHHAL_HW_NCx3320_EEPROM_SECTION2_END + 1U)))
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_HAL);
    }

    /* Register address check */
    if ((bRegAddress + bNumBytes) > PHHAL_HW_NCx3320_MAX_NUM_REGS)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_HAL);
    }

    /* Set wait IRQs */
    bIrq0WaitFor = 0x00;
    bIrq1WaitFor = 0x00;

    /* Prepare command */
    aCmd[0] = (uint8_t)(wEEAddress >> 8U);
    aCmd[1] = (uint8_t)(wEEAddress);
    aCmd[2] = bRegAddress;
    aCmd[3] = bNumBytes;

    /* Perform command */
    return phhalHw_Ncx3320_Command_Int(
        pDataParams,
        PHHAL_HW_NCx3320_CMD_LOADREG,
        PH_EXCHANGE_DEFAULT,
        bIrq0WaitFor,
        bIrq1WaitFor,
        aCmd,
        4,
        0,
        NULL,
        NULL);
}

phStatus_t phhalHw_Ncx3320_Cmd_LoadProtocol(
    phhalHw_Ncx3320_DataParams_t * pDataParams,
    uint8_t bTxProtocol,
    uint8_t bRxProtocol
    )
{
    uint8_t PH_MEMLOC_REM aCmd[2];
    uint8_t PH_MEMLOC_REM bIrq0WaitFor;
    uint8_t PH_MEMLOC_REM bIrq1WaitFor;

    /* Parameter check */
    if ((bTxProtocol > PHHAL_HW_NCx3320_MAX_TX_SETTINGS) || (bRxProtocol > PHHAL_HW_NCx3320_MAX_RX_SETTINGS))
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_HAL);
    }

    /* Set wait IRQs this bit needs to be set for interrupt mode  */
    bIrq0WaitFor = 0x00;

    bIrq1WaitFor = 0x00;

    /* Prepare command */
    aCmd[0] = bRxProtocol;
    aCmd[1] = bTxProtocol;

    /* Perform command */
    return phhalHw_Ncx3320_Command_Int(
        pDataParams,
        PHHAL_HW_NCx3320_CMD_LOADPROTOCOL,
        PH_EXCHANGE_DEFAULT,
        bIrq0WaitFor,
        bIrq1WaitFor,
        aCmd,
        2,
        0,
        NULL,
        NULL);
}

phStatus_t phhalHw_Ncx3320_Cmd_LoadKeyE2(
                                       phhalHw_Ncx3320_DataParams_t * pDataParams,
                                       uint8_t  bKeyNo
                                       )
{
    uint8_t PH_MEMLOC_REM aCmd[1];
    uint8_t PH_MEMLOC_REM bIrq0WaitFor;
    uint8_t PH_MEMLOC_REM bIrq1WaitFor;

    /* Set wait IRQs */
    bIrq0WaitFor = 0x00;
    bIrq1WaitFor = 0x00;

    /* Prepare command */
    aCmd[0] = bKeyNo;

    /* Perform command */
    return phhalHw_Ncx3320_Command_Int(
        pDataParams,
        PHHAL_HW_NCx3320_CMD_LOADKEYE2,
        PH_EXCHANGE_DEFAULT,
        bIrq0WaitFor,
        bIrq1WaitFor,
        aCmd,
        1,
        0,
        NULL,
        NULL);
}

phStatus_t phhalHw_Ncx3320_Cmd_StoreKeyE2(
                                        phhalHw_Ncx3320_DataParams_t * pDataParams,
                                        uint8_t  bKeyNo,
                                        uint8_t * pKeys,
                                        uint8_t bNumberOfKeys
                                        )
{
    phStatus_t  PH_MEMLOC_REM statusTmp;
    uint8_t     PH_MEMLOC_REM aCmd[2];
    uint8_t     PH_MEMLOC_REM bIrq0WaitFor;
    uint8_t     PH_MEMLOC_REM bIrq1WaitFor;
    uint16_t    PH_MEMLOC_REM wDataLen = 0;
    uint16_t    PH_MEMLOC_REM wFifoBytes;

    /* Parameter check */
    if (bNumberOfKeys == 0U)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_HAL);
    }

    /* Parameter check */
    if ((uint16_t)((uint16_t)bKeyNo + (uint16_t)bNumberOfKeys) > PHHAL_HW_NCx3320_MAX_NUM_KEYS)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_HAL);
    }

    /* Calculate overal data length */
    wDataLen = (uint16_t)((uint16_t)bNumberOfKeys * PHHAL_HW_NCx3320_MFC_KEY_LENGTH);

    /* Limit number of bytes to write to FiFo-Size */
    if (pDataParams->bFifoSize == PH_NXPNFCRDLIB_CONFIG_NCx3320_VALUE_FIFOSIZE_255)
    {
        if (wDataLen > 0xFFU)
        {
            return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_HAL);
        }
    }
    else
    {
        if (wDataLen > 0x200U)
        {
            return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_HAL);
        }
    }

    /* Set wait IRQs */
    bIrq0WaitFor = 0x00;
    bIrq1WaitFor = 0x00;

    /* Flush FiFo */
    PH_CHECK_SUCCESS_FCT(statusTmp, phhalHw_Ncx3320_FlushFifo(pDataParams));

    /* Write Keynumber into FIFO */
    aCmd[1] = bKeyNo;
    PH_CHECK_SUCCESS_FCT(statusTmp, phhalHw_Ncx3320_WriteFifo(pDataParams, &aCmd[1], 1, &wFifoBytes));

    /* Perform command */
    return phhalHw_Ncx3320_Command_Int(
        pDataParams,
        PHHAL_HW_NCx3320_CMD_STOREKEYE2,
        PHHAL_HW_NCx3320_OPTION_FIFO_NOCLEAR,
        bIrq0WaitFor,
        bIrq1WaitFor,
        pKeys,
        wDataLen,
        0,
        NULL,
        NULL);
}

phStatus_t phhalHw_Ncx3320_Cmd_SoftReset(
                                       phhalHw_Ncx3320_DataParams_t * pDataParams
                                       )
{

    return phhalHw_Ncx3320_WriteRegister(pDataParams, PHHAL_HW_NCx3320_REG_COMMAND, PHHAL_HW_NCx3320_CMD_SOFTRESET);
}

phStatus_t phhalHw_Ncx3320_Cmd_AckReq(
                                    phhalHw_Ncx3320_DataParams_t * pDataParams,
                                    uint8_t * pCmdBuffer,
                                    uint16_t wLen,
                                    uint8_t * pRxBuffer,
                                    uint16_t * pwRxBufferLen
                                    )
{
    phStatus_t PH_MEMLOC_REM statusTmp;
    uint16_t   PH_MEMLOC_REM wBytesWritten;
    uint8_t    PH_MEMLOC_REM bError;
    uint8_t    PH_MEMLOC_REM bRegister;
    uint8_t    PH_MEMLOC_REM bIrq0WaitFor;
    uint8_t    PH_MEMLOC_REM bIrq1WaitFor;
    uint8_t    PH_MEMLOC_REM bIrq0Reg = 0x00;
    uint8_t    PH_MEMLOC_REM bIrq1Reg = 0x00;

    PH_CHECK_SUCCESS_FCT(statusTmp, phhalHw_Ncx3320_WriteRegister(pDataParams, PHHAL_HW_NCx3320_REG_RXCORR, 0x88));
    PH_CHECK_SUCCESS_FCT(statusTmp, phhalHw_Ncx3320_WriteRegister(pDataParams, PHHAL_HW_NCx3320_REG_RXCTRL, 0x07));
    PH_CHECK_SUCCESS_FCT(statusTmp, phhalHw_Ncx3320_WriteRegister(pDataParams, PHHAL_HW_NCx3320_REG_RXWAIT, 0x3D));
    PH_CHECK_SUCCESS_FCT(statusTmp, phhalHw_Ncx3320_WriteRegister(pDataParams, PHHAL_HW_NCx3320_REG_TXWAITLO, 0x80));

    /* Set Preamble */
    PH_CHECK_SUCCESS_FCT(statusTmp, phhalHw_Ncx3320_WriteRegister(pDataParams, PHHAL_HW_NCx3320_REG_FRAMECON, 0x01));
    PH_CHECK_SUCCESS_FCT(statusTmp, phhalHw_Ncx3320_WriteRegister(pDataParams, PHHAL_HW_NCx3320_REG_TXDATAMOD, 0x00U));

    PH_CHECK_SUCCESS_FCT(statusTmp, phhalHw_Ncx3320_WriteRegister(pDataParams, PHHAL_HW_NCx3320_REG_TXSYM0H, 0x68));
    PH_CHECK_SUCCESS_FCT(statusTmp, phhalHw_Ncx3320_WriteRegister(pDataParams, PHHAL_HW_NCx3320_REG_TXSYM0L, 0x41));
    PH_CHECK_SUCCESS_FCT(statusTmp, phhalHw_Ncx3320_WriteRegister(pDataParams, PHHAL_HW_NCx3320_REG_TXSYM10LEN, 0x8E));
    PH_CHECK_SUCCESS_FCT(statusTmp, phhalHw_Ncx3320_WriteRegister(pDataParams, PHHAL_HW_NCx3320_REG_TXSYM10BURSTLEN, 0x00U));
    PH_CHECK_SUCCESS_FCT(statusTmp, phhalHw_Ncx3320_WriteRegister(pDataParams, PHHAL_HW_NCx3320_REG_TXSYM10BURSTCTRL, 0x00U));
    PH_CHECK_SUCCESS_FCT(statusTmp, phhalHw_Ncx3320_WriteRegister(pDataParams, PHHAL_HW_NCx3320_REG_TXSYM10MOD, 0x00U));
    PH_CHECK_SUCCESS_FCT(statusTmp, phhalHw_Ncx3320_WriteRegister(pDataParams, PHHAL_HW_NCx3320_REG_TXSYMFREQ, 0x05));
    /* Set preamble done */

    /* Load IDLE command (to terminate a possibly running command) */
    PH_CHECK_SUCCESS_FCT(statusTmp, phhalHw_Ncx3320_WriteRegister(
        pDataParams,
        PHHAL_HW_NCx3320_REG_COMMAND,
        PHHAL_HW_NCx3320_CMD_IDLE));

    /* Flush FiFo */
    PH_CHECK_SUCCESS_FCT(statusTmp, phhalHw_Ncx3320_FlushFifo(pDataParams));

    /* Clear all IRQ0 flags */
    PH_CHECK_SUCCESS_FCT(statusTmp, phhalHw_Ncx3320_WriteRegister(
        pDataParams,
        PHHAL_HW_NCx3320_REG_IRQ0,
        (uint8_t)~(uint8_t)PHHAL_HW_NCx3320_BIT_SET));

    /* Clear all IRQ1 flags */
    PH_CHECK_SUCCESS_FCT(statusTmp, phhalHw_Ncx3320_WriteRegister(
        pDataParams,
        PHHAL_HW_NCx3320_REG_IRQ1,
        (uint8_t)~(uint8_t)PHHAL_HW_NCx3320_BIT_SET));

    /* Write exchange command to FiFo */
    PH_CHECK_SUCCESS_FCT(statusTmp, phhalHw_Ncx3320_WriteFifo(
        pDataParams,
        &pCmdBuffer[0],
        wLen,
        &wBytesWritten));

    /* Start the command */
    PH_CHECK_SUCCESS_FCT(statusTmp, phhalHw_Ncx3320_WriteRegister(
        pDataParams,
        PHHAL_HW_NCx3320_REG_COMMAND,
        PHHAL_HW_NCx3320_CMD_ACKREQ));

    /* Set wait IRQs */
    bIrq0WaitFor = PHHAL_HW_NCx3320_BIT_IDLEIRQ;
    bIrq1WaitFor = PHHAL_HW_NCx3320_BIT_TIMER1IRQ;

    /* Wait for enabled IRQs */
    PH_CHECK_SUCCESS_FCT(statusTmp, phhalHw_Ncx3320_WaitIrq(
        pDataParams,
        PH_ON,
        PH_OFF,
        bIrq0WaitFor,
        bIrq1WaitFor,
        &bIrq0Reg,
        &bIrq1Reg));

    /* Timeout handling */
    if (0U != (bIrq1Reg & PHHAL_HW_NCx3320_BIT_TIMER1IRQ))
    {
        /* Stop the command */
        PH_CHECK_SUCCESS_FCT(statusTmp, phhalHw_Ncx3320_WriteRegister(
            pDataParams,
            PHHAL_HW_NCx3320_REG_COMMAND,
            PHHAL_HW_NCx3320_CMD_IDLE));

        /* Flush FiFo */
        PH_CHECK_SUCCESS_FCT(statusTmp, phhalHw_Ncx3320_FlushFifo(pDataParams));

        /* Retrieve content of Timer Control Register */
        PH_CHECK_SUCCESS_FCT(statusTmp, phhalHw_Ncx3320_ReadRegister(
            pDataParams,
            PHHAL_HW_NCx3320_REG_TCONTROL,
            &bRegister));

        /* Manually stop timers */
        bRegister |= PHHAL_HW_NCx3320_BIT_T0STARTSTOPNOW | PHHAL_HW_NCx3320_BIT_T1STARTSTOPNOW;
        bRegister &= (uint8_t)~(uint8_t)(PHHAL_HW_NCx3320_BIT_T0RUNNING | PHHAL_HW_NCx3320_BIT_T1RUNNING);
        PH_CHECK_SUCCESS_FCT(statusTmp, phhalHw_Ncx3320_WriteRegister(
            pDataParams,
            PHHAL_HW_NCx3320_REG_TCONTROL,
            bRegister));

        /* Return timeout */
        return PH_ADD_COMPCODE_FIXED(PH_ERR_IO_TIMEOUT, PH_COMP_HAL);
    }

    /* Read received data from FiFo (Max possible response length is 70) */
    PH_CHECK_SUCCESS_FCT(statusTmp, phhalHw_Ncx3320_ReadFifo(
        pDataParams,
        70,
        pRxBuffer,
        pwRxBufferLen));

    /* No bytes received -> timeout */
    if(pwRxBufferLen == NULL)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_IO_TIMEOUT, PH_COMP_HAL);
    }

    /* Check if any error occurred */
    PH_CHECK_SUCCESS_FCT(statusTmp, phhalHw_Ncx3320_ReadRegister(
        pDataParams,
        PHHAL_HW_NCx3320_REG_ERROR,
        &bError));

    /* Buffer overflow */
    if (0U != (bError & PHHAL_HW_NCx3320_BIT_FIFOOVL))
    {
        statusTmp = PH_ERR_BUFFER_OVERFLOW;
    }
    /* FiFo write error */
    else if (0U != (bError & PHHAL_HW_NCx3320_BIT_FIFOWRERR))
    {
        statusTmp = PH_ERR_READ_WRITE_ERROR;
    }
    /* EEPROM error */
    else if (0U != (bError & PHHAL_HW_NCx3320_BIT_EE_ERR))
    {
        statusTmp = PH_ERR_READ_WRITE_ERROR;
    }
    /* Framing error */
    else if (0U != (bError & PHHAL_HW_NCx3320_BIT_MINFRAMEERR))
    {
        statusTmp = PH_ERR_FRAMING_ERROR;
    }
    /* Collision */
    else if (0U != (bError & PHHAL_HW_NCx3320_BIT_COLLDET))
    {
        statusTmp = PH_ERR_COLLISION_ERROR;
    }
    /* Protocol error */
    else if (0U != (bError & PHHAL_HW_NCx3320_BIT_PROTERR))
    {
        statusTmp = PH_ERR_PROTOCOL_ERROR;
    }
    /* CRC / parity error */
    else if (0U != (bError & PHHAL_HW_NCx3320_BIT_INTEGERR))
    {
        statusTmp = PH_ERR_INTEGRITY_ERROR;
    }
    /* No error */
    else
    {
        statusTmp = PH_ERR_SUCCESS;
    }

    return PH_ADD_COMPCODE(statusTmp, PH_COMP_HAL);
}

phStatus_t phhalHw_Ncx3320_Cmd_Lpcd_SetConfig(phhalHw_Ncx3320_DataParams_t * pDataParams,
		uint8_t bMode, uint8_t bI, uint8_t bQ, uint16_t wPowerDownTimeMs, uint16_t wDetectionTimeUs)
{
	phStatus_t PH_MEMLOC_REM status = PH_ERR_SUCCESS;
	/* Check for valid I/Q values only in Default Mode and with Option to not ignore I and Q. */
	if (((bMode & PHHAL_HW_NCx3320_CMD_LPCD_MODE_MASK) != PHHAL_HW_NCx3320_CMD_LPCD_MODE_DEFAULT)
			&& (0U == (bMode & PHHAL_HW_NCx3320_CMD_LPCD_MODE_OPTION_IGNORE_IQ)))
	{
		if ((bI > 0x3FU) || (bQ > 0x3FU))
		{
			return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_HAL);
		}
	}

	pDataParams->bMode = bMode;
	pDataParams->bI = bI;
	pDataParams->bQ = bQ;
	pDataParams->wPowerDownTimeMs = wPowerDownTimeMs;
	pDataParams->wDetectionTimeUs = wDetectionTimeUs;

	/* Enable charge pump */
	PH_CHECK_SUCCESS_FCT(status, phhalHw_SetConfig(pDataParams, PHHAL_HW_NCx3320_CONFIG_LPCD_CHARGEPUMP,
			PH_ON));
	/* Disable filter */
	PH_CHECK_SUCCESS_FCT(status, phhalHw_SetConfig(pDataParams, PHHAL_HW_NCx3320_CONFIG_LPCD_FILTER, PH_OFF));
	/* Configure transmitter amplitude */
	PH_CHECK_SUCCESS_FCT(status, phhalHw_SetConfig(pDataParams, PHHAL_HW_NCx3320_CONFIG_LPCD_CWAMP,
	PH_NFCRDLIB_EXAMPLE_LPCD_CWAMP_SETTING));
	/* Disable maximum amplitude of continuous wave carrier */
	PH_CHECK_SUCCESS_FCT(status, phhalHw_SetConfig(pDataParams, PHHAL_HW_NCx3320_CONFIG_LPCD_CWMAX, PH_OFF));

	return status;
}

phStatus_t phhalHw_Ncx3320_Cmd_Advanced_Lpcd_SetConfig(phhalHw_Ncx3320_DataParams_t * pDataParams,
	uint8_t bTxiDelta,
	uint8_t bTxiDirection,
	uint8_t bTxiChannel
)
{
	if ((bTxiDelta > 4U) || (bTxiDirection > 1U) || (bTxiChannel > 1U))
	{
		return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_HAL);
	}

	pDataParams->bTxiDelta = bTxiDelta;
	pDataParams->bTxiDirection = bTxiDirection;
	pDataParams->bTxiChannel = bTxiChannel;

	return PH_ERR_SUCCESS;
}

phStatus_t phhalHw_Ncx3320_WriteRegister(
                                       phhalHw_Ncx3320_DataParams_t * pDataParams,
                                       uint8_t bAddress,
                                       uint8_t bValue
                                       )
{
    phStatus_t  PH_MEMLOC_REM statusTmp;
    uint8_t     PH_MEMLOC_REM bDataBuffer[2];
    uint16_t    PH_MEMLOC_REM wBytesRead;
    uint8_t     PH_MEMLOC_REM bNumExpBytes;

    /* RS232 protocol */
    if (pDataParams->bBalConnectionType == PHHAL_HW_BAL_CONNECTION_RS232)
    {
        /* clear RD/NWR bit to indicate write operation */
        bAddress &= 0x7FU;
        bNumExpBytes = 1;
    }
    /* SPI protocol */
    else if (pDataParams->bBalConnectionType == PHHAL_HW_BAL_CONNECTION_SPI)
    {
        /* shift address and clear RD/NWR bit to indicate write operation */
        bAddress = (uint8_t)(bAddress << 1U);
        bNumExpBytes = 2;

        /* Enable chip select connected to reader IC by pulling NSS low. */
        phhalHw_Ncx3320_WriteSSEL(pDataParams->pBalDataParams, PH_DRIVER_SET_LOW);
    }
    /* I2C protocol */
    else if (pDataParams->bBalConnectionType == PHHAL_HW_BAL_CONNECTION_I2C)
    {
        bNumExpBytes = 0;
    }
    else
    {
        /* Insert Code for other protocols here */
        bNumExpBytes = 0;
    }

    /* Write the address and data */
    bDataBuffer[0] = bAddress;
    bDataBuffer[1] = bValue;
    PH_CHECK_SUCCESS_FCT(statusTmp, phbalReg_Exchange(
        pDataParams->pBalDataParams,
        PH_EXCHANGE_DEFAULT,
        bDataBuffer,
        2,
        bNumExpBytes,
        bDataBuffer,
        &wBytesRead));

    /* Check number of received bytes */
    if (wBytesRead != bNumExpBytes)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INTERFACE_ERROR, PH_COMP_HAL);
    }

    /* RS232 protocol */
    if (pDataParams->bBalConnectionType == PHHAL_HW_BAL_CONNECTION_RS232)
    {
        /* Returned address should match */
        if (bDataBuffer[0] != bAddress)
        {
            return PH_ADD_COMPCODE_FIXED(PH_ERR_INTERFACE_ERROR, PH_COMP_HAL);
        }
    }
    /* SPI protocol */
    else if (pDataParams->bBalConnectionType == PHHAL_HW_BAL_CONNECTION_SPI)
    {
        /* Disable chip select connected to reader IC by pulling NSS high. */
        phhalHw_Ncx3320_WriteSSEL(pDataParams->pBalDataParams, PH_DRIVER_SET_HIGH);
    }
    /* I2C protocol */
    else if (pDataParams->bBalConnectionType == PHHAL_HW_BAL_CONNECTION_I2C)
    {
        /* nothing to be done */
    }
    else
    {
        /* Insert Code for other protocols here */
    }

    return PH_ERR_SUCCESS;
}

phStatus_t phhalHw_Ncx3320_ReadRegister(
                                      phhalHw_Ncx3320_DataParams_t * pDataParams,
                                      uint8_t bAddress,
                                      uint8_t * pValue
                                      )
{
    phStatus_t  PH_MEMLOC_REM statusTmp;
    uint8_t     PH_MEMLOC_REM bTxBuffer[2];
    uint16_t    PH_MEMLOC_REM wTxLength = 0;
    uint16_t    PH_MEMLOC_REM wBytesRead;
    uint8_t     PH_MEMLOC_REM bNumExpBytes;

    /* RS232 protocol */
    if (pDataParams->bBalConnectionType == PHHAL_HW_BAL_CONNECTION_RS232)
    {
        /* set RD/NWR bit to indicate read operation */
        bTxBuffer[0] = bAddress | 0x80U;
        wTxLength = 1;
        bNumExpBytes = 1;
    }
    /* SPI protocol */
    else if (pDataParams->bBalConnectionType == PHHAL_HW_BAL_CONNECTION_SPI)
    {
        /* set RD/NWR bit to indicate read operation */
        bTxBuffer[0] = (uint8_t)(bAddress << 1U) | 0x01U;
        bTxBuffer[1] = 0x00;
        wTxLength = 2;
        bNumExpBytes = 2;

        /* Enable chip select connected to reader IC by pulling NSS low. */
        phhalHw_Ncx3320_WriteSSEL(pDataParams->pBalDataParams, PH_DRIVER_SET_LOW);
    }
    /* I2C protocol */
    else if (pDataParams->bBalConnectionType == PHHAL_HW_BAL_CONNECTION_I2C)
    {
        /* nothing to be modified */
        bTxBuffer[0] = bAddress;
        wTxLength = 1;
        bNumExpBytes = 1;
    }
    else
    {
        /* Insert Code for other protocols here */
        wTxLength = 0;
        bNumExpBytes = 0;
    }

    /* Write the address and retrieve the register content */
    PH_CHECK_SUCCESS_FCT(statusTmp, phbalReg_Exchange(
        pDataParams->pBalDataParams,
        PH_EXCHANGE_DEFAULT,
        bTxBuffer,
        wTxLength,
        bNumExpBytes,
        bTxBuffer,
        &wBytesRead));

    /* Check number of received bytes */
    if (wBytesRead != bNumExpBytes)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INTERFACE_ERROR, PH_COMP_HAL);
    }

    /* in case of SPI 2 bytes are received from a read */
    if (pDataParams->bBalConnectionType == PHHAL_HW_BAL_CONNECTION_SPI)
    {
        /* Disable chip select connected to reader IC by pulling NSS high. */
        phhalHw_Ncx3320_WriteSSEL(pDataParams->pBalDataParams, PH_DRIVER_SET_HIGH);

        *pValue = bTxBuffer[1];
    }
    else
    {
        *pValue = bTxBuffer[0];
    }

    return PH_ERR_SUCCESS;
}

phStatus_t phhalHw_Ncx3320_Cmd_PRBS(
                                  phhalHw_Ncx3320_DataParams_t * pDataParams,
                                  uint8_t * pBufferStartPos,
                                  uint16_t wBuffLength
                                  )
{
    phStatus_t  PH_MEMLOC_REM status = PH_ERR_SUCCESS;
    phStatus_t  PH_MEMLOC_REM statusTmp;
    uint16_t    PH_MEMLOC_REM wFifoBytes;
    uint16_t    PH_MEMLOC_REM wTxLength;
    uint16_t    PH_MEMLOC_REM wTmpBufferLen = 0x00;
    uint16_t    PH_MEMLOC_REM wNumPrecachedBytes = 0x00;
    uint8_t *   PH_MEMLOC_REM pTxBuffer;
    uint8_t     PH_MEMLOC_REM bIrq0WaitFor = 0x00;
    uint8_t     PH_MEMLOC_REM bIrq1WaitFor = 0x00;
    uint8_t     PH_MEMLOC_REM bIrq0Reg = 0x00;
    uint8_t     PH_MEMLOC_REM bIrq1Reg = 0x00;

    if ((wBuffLength == 0x00U) || (pBufferStartPos == NULL))
    {
        return PH_ADD_COMPCODE(PH_ERR_INVALID_PARAMETER, PH_COMP_HAL);
    }

    /* Initializing Variable used. */
    pTxBuffer = pBufferStartPos;
    wTxLength = wBuffLength;

    /* Clear internal Tx buffer. */
    pDataParams->wTxBufLen = 0;

    /* Turn off Parity irrespective of protocol configured */
    PH_CHECK_SUCCESS_FCT(statusTmp, phhalHw_Ncx3320_SetConfig(pDataParams, PHHAL_HW_CONFIG_PARITY, PH_OFF));

    /* Terminate a possibly running command */
    PH_CHECK_SUCCESS_FCT(statusTmp, phhalHw_Ncx3320_WriteRegister(pDataParams, PHHAL_HW_NCx3320_REG_COMMAND, PHHAL_HW_NCx3320_CMD_IDLE));

    /* Flush FiFo */
    PH_CHECK_SUCCESS_FCT(statusTmp, phhalHw_Ncx3320_FlushFifo(pDataParams));

    /* clear all IRQ0 flags */
    PH_CHECK_SUCCESS_FCT(statusTmp, phhalHw_Ncx3320_WriteRegister(
        pDataParams,
        PHHAL_HW_NCx3320_REG_IRQ0,
        (uint8_t)~(uint8_t)PHHAL_HW_NCx3320_BIT_SET));

    /* clear all IRQ1 flags */
    PH_CHECK_SUCCESS_FCT(statusTmp, phhalHw_Ncx3320_WriteRegister(
        pDataParams,
        PHHAL_HW_NCx3320_REG_IRQ1,
        (uint8_t)~(uint8_t)PHHAL_HW_NCx3320_BIT_SET));

    /* Set Water level count based on number of bytes that are been provided as input. */
    do
    {
        /* Precache given buffer contents into FIFO */
        wNumPrecachedBytes = (wTxLength > pDataParams->wMaxPrecachedBytes) ? pDataParams->wMaxPrecachedBytes : wTxLength;

        /* Perform actual write to FIFO */
        status = phhalHw_Ncx3320_WriteFifo(pDataParams, pTxBuffer, wNumPrecachedBytes, &wFifoBytes);

        /* Ignore FiFo overflow warning */
        if ((status & PH_ERR_MASK) != PH_ERR_BUFFER_OVERFLOW)
        {
            statusTmp = status;
            PH_BREAK_ON_FAILURE(status);
        }

        /* Update buffer pointer and length */
        wTxLength = wTxLength - wFifoBytes;
        if (wTxLength == 0x00U)
        {
            pTxBuffer = pBufferStartPos;
            wTxLength = wBuffLength;
        }
        else
        {
            pTxBuffer += wFifoBytes;
        }
        wTmpBufferLen += wFifoBytes;
    }
    while (wTmpBufferLen != pDataParams->wMaxPrecachedBytes);

    /* start the command */
    PH_CHECK_SUCCESS_FCT(statusTmp, phhalHw_Ncx3320_WriteRegister(pDataParams, PHHAL_HW_NCx3320_REG_COMMAND, PHHAL_HW_NCx3320_CMD_TRANSMIT));

    /* Set wait IRQs */
    bIrq0WaitFor = PHHAL_HW_NCx3320_BIT_TXIRQ | PHHAL_HW_NCx3320_BIT_IDLEIRQ | PHHAL_HW_NCx3320_BIT_LOALERTIRQ;
    bIrq1WaitFor = 0U;

    do{
#ifndef NXPBUILD__PH_PLATFORM_DELEGATE
        /* wait until the transmission is finished */
        statusTmp = phhalHw_Ncx3320_WaitIrq(
            pDataParams,
            PH_ON,
            PH_OFF,
            bIrq0WaitFor,
            bIrq1WaitFor,
            &bIrq0Reg,
            &bIrq1Reg);
        if ((statusTmp & PH_ERR_MASK) == PH_ERR_ABORTED)
        {
            status = PH_ERR_SUCCESS;
            break;
        }
        else
        {
            PH_CHECK_SUCCESS(statusTmp);
        }

#endif /* NXPBUILD__PH_PLATFORM_DELEGATE*/

        /* Write the remaining data into the Fifo */
        /* (Only possible if interface to RC is fast enough!) */
        if (0U != (bIrq0WaitFor & PHHAL_HW_NCx3320_BIT_LOALERTIRQ))
        {
            /* Check for FIFO underflow */
#ifdef PHHAL_HW_NCx3320_FEATURE_FIFO_UNDERFLOW_CHECK
            /* read interrupt status */
            PH_CHECK_SUCCESS_FCT(statusTmp, phhalHw_Ncx3320_ReadRegister(pDataParams, PHHAL_HW_NCx3320_REG_IRQ0, &bIrq0Reg));

            /* If we got data to transmit but the Tx-command aborted, we were too slow! */
            if ((0U != (bIrq0Reg & PHHAL_HW_NCx3320_BIT_IDLEIRQ)) ||
                (0U != (bIrq0Reg & PHHAL_HW_NCx3320_BIT_TXIRQ)))
            {
                /* stop the command */
                PH_CHECK_SUCCESS_FCT(statusTmp, phhalHw_Ncx3320_WriteRegister(
                    pDataParams,
                    PHHAL_HW_NCx3320_REG_COMMAND,
                    PHHAL_HW_NCx3320_CMD_IDLE));

                /* Flush FiFo */
                PH_CHECK_SUCCESS_FCT(statusTmp, phhalHw_Ncx3320_FlushFifo(pDataParams));

                return PH_ADD_COMPCODE_FIXED(PH_ERR_INTERFACE_ERROR, PH_COMP_HAL);
            }
#endif
            /* write remaining data to transmit into FiFo buffer */
            status = phhalHw_Ncx3320_WriteFifo(pDataParams, pTxBuffer, wTxLength, &wFifoBytes);
            /* Ignore FiFo overflow warning */
            if ((status & PH_ERR_MASK) != PH_ERR_BUFFER_OVERFLOW)
            {
                PH_CHECK_SUCCESS(status);
            }

            /* Update buffer pointer and length */
            wTxLength = wTxLength - wFifoBytes;
            if (wTxLength == 0x00U)
            {
                pTxBuffer = pBufferStartPos;
                wTxLength = wBuffLength;
            }
            else
            {
                pTxBuffer += wFifoBytes;
            }

            /* Mask the LOW ALERT IRQ. */
            bIrq0Reg &= (uint8_t)~PHHAL_HW_NCx3320_BIT_LOALERTIRQ;

            /* Clear the LOW ALERT IRQ. */
            PH_CHECK_SUCCESS_FCT(statusTmp, phhalHw_Ncx3320_WriteRegister(
                pDataParams,
                PHHAL_HW_NCx3320_REG_IRQ0,
                (uint8_t)PHHAL_HW_NCx3320_BIT_LOALERTIRQ));
        }
    } while(1);

    return PH_ADD_COMPCODE(status, PH_COMP_HAL);
}

#endif /* NXPBUILD__PHHAL_HW_NCx3320 */
