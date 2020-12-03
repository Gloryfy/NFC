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

#include <device_registers.h>
#include <interrupt_manager.h>
#include <clock_manager.h>
#include <lpspi_master_driver.h>
#include <pins_driver.h>

#define PHBAL_REG_S32K_SPI_ID               0x32U       /**< ID for S32K SPI BAL component */
#define TEMP_RX_BUF_SIZE                    256

static void phbalReg_SpiInit(void);
static lpspi_state_t masterState;

phStatus_t phbalReg_Init(
                         void * pDataParams,
                         uint16_t wSizeOfDataParams
                         )
{
    uint32_t dwLpspiClockVal;

    /* Configure LPSPI using Interrupt mode */
    lpspi_master_config_t sMasterConfig =
    {
        .bitsPerSec = 100000U,
        .whichPcs = LPSPI_PCS0,
        .pcsPolarity = LPSPI_ACTIVE_HIGH,
        .isPcsContinuous = true,
        .bitcount = 8U,
        .lpspiSrcClk = 48000000U,
        .clkPhase = LPSPI_CLOCK_PHASE_1ST_EDGE,
        .clkPolarity = LPSPI_SCK_ACTIVE_HIGH,
        .lsbFirst = false,
        .transferType = LPSPI_USING_INTERRUPTS,
        .rxDMAChannel = 255,
        .txDMAChannel = 255,
        .callback = NULL,
        .callbackParam = NULL,
    };

    if ( (pDataParams == NULL) || (sizeof(phbalReg_Type_t) != wSizeOfDataParams))
    {
        return (PH_DRIVER_ERROR | PH_COMP_DRIVER);
    }

    ((phbalReg_Type_t *)pDataParams)->wId      = PH_COMP_DRIVER | PHBAL_REG_S32K_SPI_ID;
    ((phbalReg_Type_t *)pDataParams)->bBalType = PHBAL_REG_TYPE_SPI;

    /* Configure LPSPI module */
    sMasterConfig.pcsPolarity = LPSPI_PCS_POLARITY;
    sMasterConfig.bitsPerSec = LPSPI_BAUD_RATE;
    sMasterConfig.transferType = LPSPI_TRANSFER_TYPE;
    /* Get current clock source of LPSPI module */
    CLOCK_DRV_GetFreq(LPSPI_CLK_SRC, &dwLpspiClockVal);
    sMasterConfig.lpspiSrcClk = dwLpspiClockVal;

    phbalReg_SpiInit();

    /* Initialize LPSPI as Master */
    LPSPI_DRV_MasterInit(LPSPI_INSTANCE, &masterState, &sMasterConfig);

    LPSPI_DRV_MasterSetDelay(LPSPI_INSTANCE, 100, 100, 100);

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
    }
    else
    {
    	/* This case for workaround due to LPSPI issue: LPSPI RX buffer is overflowed when parameter receiveBuffer = NULL */
    	lpspiStatus = LPSPI_DRV_MasterTransfer(LPSPI_INSTANCE, pTxBuffer, pTmpRxBuffer, wTxLength);
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
    uint32_t pinCount = 1;
    pin_settings_config_t config[1];
	pin_settings_config_t sPinSpiConfig =
	    {
	        .base          = PORTB,
	        .pinPortIdx    = 0u,
	        .pullConfig    = PORT_INTERNAL_PULL_NOT_ENABLED,
	        .passiveFilter = false,
	        .driveSelect   = PORT_LOW_DRIVE_STRENGTH,
	        .mux           = PORT_PIN_DISABLED,
	        .pinLock       = false,
	        .intConfig     = PORT_DMA_INT_DISABLED,
	        .clearIntFlag  = false,
	        .gpioBase      = NULL,
	        .digitalFilter = false,
	    };

    config[0] = sPinSpiConfig;

    /* Set IRQ Priority for LPSPI interrupt */
    INT_SYS_SetPriority(PHDRIVER_S32K_LPSPI_IRQ, LPSPI_IRQ_PRIORITY);

    /* Configure SCK pin */
    sPinSpiConfig.base = PORT_LPSPI_SCK;
    sPinSpiConfig.pinPortIdx = PIN_NUM_SCK;
    sPinSpiConfig.mux = PIN_MUX_ALT_SCK;
    config[0] = sPinSpiConfig;
    PINS_DRV_Init(pinCount, config);

    /* Configure MISO pin */
    sPinSpiConfig.base = PORT_LPSPI_MISO;
    sPinSpiConfig.pinPortIdx = PIN_NUM_MISO;
    sPinSpiConfig.pullConfig = PORT_INTERNAL_PULL_DOWN_ENABLED;
    sPinSpiConfig.mux = PIN_MUX_ALT_MISO;
    config[0] = sPinSpiConfig;
    PINS_DRV_Init(pinCount, config);

    /* Configure MOSI pin */
    sPinSpiConfig.base = PORT_LPSPI_MOSI;
    sPinSpiConfig.pinPortIdx = PIN_NUM_MOSI;
    sPinSpiConfig.pullConfig = PORT_INTERNAL_PULL_DOWN_ENABLED;
    sPinSpiConfig.mux = PIN_MUX_ALT_MOSI;
    config[0] = sPinSpiConfig;
    PINS_DRV_Init(pinCount, config);

    /* Configure PCS pin */
    sPinSpiConfig.base = PORT_LPSPI_PCS;
    sPinSpiConfig.pinPortIdx = PIN_NUM_PCS;
    sPinSpiConfig.mux = PIN_MUX_ALT_PCS;
    config[0] = sPinSpiConfig;
    PINS_DRV_Init(pinCount, config);

}

