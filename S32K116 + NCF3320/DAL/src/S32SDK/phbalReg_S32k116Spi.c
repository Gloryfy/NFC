/*
*         Copyright (c), NXP Semiconductors Bangalore / India
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
* Generic phDriver Component of Reader Library Framework.
* $Author$
* $Revision$
* $Date$
*
* History:
*  RS: Generated 24. Jan 2017
*
*/

#include "phDriver.h"
#include "BoardSelection.h"

#include "Cpu.h"
#include "clockMan1.h"
#include "pin_mux.h"
#include "dmaController1.h"
#if CPU_INIT_CONFIG
#include "Init_Config.h"
#endif

#define PHBAL_REG_S32K_SPI_ID               0x32U       /**< ID for S32K SPI BAL component */
#define TEMP_RX_BUF_SIZE                    256
#define TIMEOUT                             (200u)

static void phbalReg_SpiInit(void);

phStatus_t phbalReg_Init(
                         void * pDataParams,
                         uint16_t wSizeOfDataParams
                         )
{
    if ( (pDataParams == NULL) || (sizeof(phbalReg_Type_t) != wSizeOfDataParams))
    {
        return (PH_DRIVER_ERROR | PH_COMP_DRIVER);
    }

    ((phbalReg_Type_t *)pDataParams)->wId      = PH_COMP_DRIVER | PHBAL_REG_S32K_SPI_ID;
    ((phbalReg_Type_t *)pDataParams)->bBalType = PHBAL_REG_TYPE_SPI;

    phbalReg_SpiInit();

    /* Initialize LPSPI0 */
    LPSPI_DRV_MasterInit(LPSPICOM1, &lpspiCom1State, &lpspiCom1_MasterConfig0);

    /* Set delay for transmission */
    LPSPI_DRV_MasterSetDelay(LPSPICOM1, 100u, 100u, 100u);

    return PH_DRIVER_SUCCESS;
}

phStatus_t phbalReg_Exchange(
                             void * pDataParams,
                             uint16_t wOption,
                             uint8_t * pTxBuffer,
                             uint16_t wTxLength,
                             uint16_t wRxBufSize,
                             uint8_t * pRxBuffer,
                             uint16_t * pRxLength
                             )
{
    phStatus_t status = PH_DRIVER_SUCCESS;
    status_t lpspiStatus;
    uint32_t byteRemain = 0;
    uint8_t pTmpRxBuffer[TEMP_RX_BUF_SIZE];

    if(pRxBuffer != NULL)
    {
    	lpspiStatus = LPSPI_DRV_MasterTransfer(LPSPI_INSTANCE, pTxBuffer, pRxBuffer, wTxLength);
    	/* The blocking function can alternatively be used */
    	/*lpspiStatus = LPSPI_DRV_MasterTransferBlocking(LPSPICOM1, pTxBuffer, pRxBuffer, wTxLength, TIMEOUT);*/
    }
    else
    {
    	/* This case for workaround due to LPSPI issue: LPSPI RX buffer is overflowed when parameter receiveBuffer = NULL */
    	lpspiStatus = LPSPI_DRV_MasterTransfer(LPSPI_INSTANCE, pTxBuffer, pTmpRxBuffer, wTxLength);
    	/* The blocking function can alternatively be used */
    	/*lpspiStatus = LPSPI_DRV_MasterTransferBlocking(LPSPICOM1, pTxBuffer, pTmpRxBuffer, wTxLength, TIMEOUT);*/
    }

    while(STATUS_BUSY == LPSPI_DRV_MasterGetTransferStatus(LPSPI_INSTANCE, &byteRemain));

    if(lpspiStatus != STATUS_SUCCESS)
    {
        return (PH_DRIVER_FAILURE | PH_COMP_DRIVER);
    }

    if (pRxLength != NULL)
    {
        *pRxLength = wTxLength;
    }

    return status;
}


phStatus_t phbalReg_SetConfig(
                              void * pDataParams,
                              uint16_t wConfig,
                              uint16_t wValue
                              )
{
    return PH_DRIVER_SUCCESS;
}

phStatus_t phbalReg_GetConfig(
                              void * pDataParams,
                              uint16_t wConfig,
                              uint16_t * pValue
                              )
{
    return PH_DRIVER_SUCCESS;
}

static void phbalReg_SpiInit(void)
{
    /* Done by Processor expert */
}

