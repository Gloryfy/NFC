
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
*  RS: Generated 3. Apr 2018
*
*/


/* *****************************************************************************************************************
 * Includes
 * ***************************************************************************************************************** */
#include <phDriver.h>
#include <BoardSelection.h>
#include <device_registers.h>
#include <interrupt_manager.h>
#include <lpit_driver.h>
#include <clock_manager.h>
#include <phDriver_Gpio.h>
#include <pins_driver.h>
/* *****************************************************************************************************************
 * Internal Definitions
 * ***************************************************************************************************************** */
#define S32K_TIMER_MAX_32BIT      0xFFFFFFFFU

/* *****************************************************************************************************************
 * Type Definitions
 * ***************************************************************************************************************** */

/* *****************************************************************************************************************
 * Global and Static Variables
 * Total Size: NNNbytes
 * ***************************************************************************************************************** */

static pphDriver_TimerCallBck_t pPitTimerCallBack;
static volatile uint8_t dwTimerExp;

/* *****************************************************************************************************************
 * Private Functions Prototypes
 * ***************************************************************************************************************** */
static void phDriver_PitTimerIsrCallBack(void);

/* *****************************************************************************************************************
 * Public Functions
 * ***************************************************************************************************************** */
phStatus_t phDriver_TimerStart(phDriver_Timer_Unit_t eTimerUnit, uint32_t dwTimePeriod, pphDriver_TimerCallBck_t pTimerCallBack)
{
	uint64_t         qwTimerCnt;
	uint32_t         qwTimeInUs;
    uint32_t         dwTimerFreq;

    lpit_user_channel_config_t lpit1_ChnConfig0 =
    {
        .timerMode = LPIT_PERIODIC_COUNTER,
        .periodUnits = LPIT_PERIOD_UNITS_MICROSECONDS,
        .period = 0U,
        .triggerSource = LPIT_TRIGGER_SOURCE_EXTERNAL,
        .triggerSelect = 0U,
        .enableReloadOnTrigger = false,
        .enableStopOnInterrupt = false,
        .enableStartOnTrigger = false,
        .chainChannel = false,
        .isInterruptEnabled = true
    };

    CLOCK_SYS_GetFreq(PH_DRIVER_S32K_LPIT_CLK, &dwTimerFreq);
    /* Timer count = (delay * freq)/Units. */
    qwTimerCnt = ((uint64_t)dwTimePeriod * dwTimerFreq);
    qwTimerCnt = (qwTimerCnt / eTimerUnit) - 1U;

    /* 32-bit timers counter */
    if(qwTimerCnt > (uint64_t)S32K_TIMER_MAX_32BIT)
    {
        return PH_DRIVER_ERROR | PH_COMP_DRIVER;
    }

    /* Set period for counter in microSeconds */
    qwTimeInUs = ((dwTimePeriod * 1000000) / eTimerUnit);
    lpit1_ChnConfig0.period = qwTimeInUs;

    if(pTimerCallBack == NULL)
    {    /* Timer Start is blocking call. */
        dwTimerExp = 0;
        pPitTimerCallBack = phDriver_PitTimerIsrCallBack;
    }
    else
    {   /* Call the Timer callback. */
        pPitTimerCallBack = pTimerCallBack;
    }

    LPIT_DRV_ClearInterruptFlagTimerChannels(PH_DRIVER_S32K_LPIT_INSTANCE, (1 << PH_DRIVER_S32K_LPIT_CHANNEL));
    LPIT_DRV_InitChannel(PH_DRIVER_S32K_LPIT_INSTANCE, PH_DRIVER_S32K_LPIT_CHANNEL, &lpit1_ChnConfig0);
    /* Start LPIT0 channel 0 counter */
    LPIT_DRV_StartTimerChannels(PH_DRIVER_S32K_LPIT_INSTANCE, (1 << PH_DRIVER_S32K_LPIT_CHANNEL));

    if(pTimerCallBack == NULL)
        {
            /* Block until timer expires. */
            while(!dwTimerExp);
        }

    return PH_DRIVER_SUCCESS;
}


phStatus_t phDriver_TimerStop(void)
{
    /* LPIT0 channel 0 counter */
    LPIT_DRV_StopTimerChannels(PH_DRIVER_S32K_LPIT_INSTANCE, (1 << PH_DRIVER_S32K_LPIT_CHANNEL));

    /* Disable interrupt for LPIT0 channel 0 */
    LPIT_DRV_DisableTimerChannelInterrupt(PH_DRIVER_S32K_LPIT_INSTANCE, (1 << PH_DRIVER_S32K_LPIT_CHANNEL));
    /* Disable at the NVIC */
    INT_SYS_DisableIRQ(PH_DRIVER_S32K_LPIT_CHANNEL_NVIC);

    return PH_DRIVER_SUCCESS;
}


phStatus_t phDriver_PinConfig(uint32_t dwPinNumber, phDriver_Pin_Func_t ePinFunc, phDriver_Pin_Config_t *pPinConfig)
{
    uint8_t bPinNum;
    uint32_t dwPortBaseAddress;
    uint32_t dwGpioBaseAddress;
    uint32_t pinCount = 1;
    pin_settings_config_t config[1];
    pin_settings_config_t sPinConfig =
    {
        .base          = NULL,
        .pinPortIdx    = 0u,
        .pullConfig    = PORT_INTERNAL_PULL_NOT_ENABLED,
        .passiveFilter = false,
        .driveSelect   = PORT_LOW_DRIVE_STRENGTH,
        .mux           = PORT_MUX_AS_GPIO,
        .pinLock       = false,
        .intConfig     = PORT_DMA_INT_DISABLED,
        .clearIntFlag  = false,
        .gpioBase      = NULL,
        .direction     = GPIO_UNSPECIFIED_DIRECTION,
        .digitalFilter = false,
        .initValue     = 0u,
    };

    if((ePinFunc == PH_DRIVER_PINFUNC_BIDIR) || (pPinConfig == NULL))
    {
        return PH_DRIVER_ERROR | PH_COMP_DRIVER;
    }

    /* Extract the Pin, GPIO, Port details from dwPinNumber */
    bPinNum = (uint8_t)((dwPinNumber & 0xFF00000) >> 20);
    dwPortBaseAddress = ((dwPinNumber & 0x000FF000) | PORT_BASE_ADDR);
    dwGpioBaseAddress = ((dwPinNumber & 0x00000FFF) | GPIO_BASE_ADDR);

    sPinConfig.base = ((PORT_Type *) dwPortBaseAddress);
    sPinConfig.pinPortIdx = bPinNum;
    if(PHDRIVER_PIN_SSEL == dwPinNumber)
    {
    	sPinConfig.pullConfig = PORT_INTERNAL_PULL_NOT_ENABLED;
    }
    else
    {
    	sPinConfig.pullConfig = (pPinConfig->bPullSelect == PH_DRIVER_PULL_DOWN)? PORT_INTERNAL_PULL_DOWN_ENABLED : PORT_INTERNAL_PULL_UP_ENABLED;
    }
    sPinConfig.gpioBase = ((GPIO_Type *) dwGpioBaseAddress);
    sPinConfig.direction = (ePinFunc == PH_DRIVER_PINFUNC_OUTPUT)? GPIO_OUTPUT_DIRECTION : GPIO_INPUT_DIRECTION;
    sPinConfig.initValue = pPinConfig->bOutputLogic;

    /* Configure for interrupt pin */
    if(ePinFunc == PH_DRIVER_PINFUNC_INTERRUPT){
        /* Clear any pending interrupts before enabling interrupt */
        PINS_DRV_ClearPinIntFlagCmd(sPinConfig.base, bPinNum);
        /* Set interrupt enable depends on which type of triggering */
        switch(pPinConfig->eInterruptConfig){
        case PH_DRIVER_INTERRUPT_LEVELZERO:
            sPinConfig.intConfig = PORT_INT_LOGIC_ZERO;
            break;
        case PH_DRIVER_INTERRUPT_LEVELONE:
            sPinConfig.intConfig = PORT_INT_LOGIC_ONE;
            break;
        case PH_DRIVER_INTERRUPT_RISINGEDGE:
            sPinConfig.intConfig = PORT_INT_RISING_EDGE;
            break;
        case PH_DRIVER_INTERRUPT_FALLINGEDGE:
            sPinConfig.intConfig = PORT_INT_FALLING_EDGE;
            break;
        case PH_DRIVER_INTERRUPT_EITHEREDGE:
            sPinConfig.intConfig = PORT_INT_EITHER_EDGE;
            break;
        default:
            break;
        }
    }

    config[0] = sPinConfig;
    PINS_DRV_Init(pinCount, config);

    return PH_DRIVER_SUCCESS;
}


uint8_t phDriver_PinRead(uint32_t dwPinNumber, phDriver_Pin_Func_t ePinFunc)
{
    uint8_t bValue;
    uint8_t bPinNum;
    uint32_t dwPortBaseAddress;
    uint32_t dwGpioBaseAddress;
    /* Extract the Pin, Gpio details from dwPinNumber */
    bPinNum = (uint8_t)((dwPinNumber & 0xFF00000) >> 20);
    dwGpioBaseAddress = ((dwPinNumber & 0x00000FFF) | GPIO_BASE_ADDR);
    dwPortBaseAddress = ((dwPinNumber & 0x000FF000) | PORT_BASE_ADDR);
    if(ePinFunc == PH_DRIVER_PINFUNC_INTERRUPT){
        bValue = (uint8_t)((PINS_DRV_GetPortIntFlag((PORT_Type *) dwPortBaseAddress) >> bPinNum) & 0x01);
    }
    else{
        bValue = (uint8_t)((PINS_DRV_ReadPins((GPIO_Type *) dwGpioBaseAddress) >> bPinNum) & 0x01);
    }

    return bValue;
}


void phDriver_PinWrite(uint32_t dwPinNumber, uint8_t bValue)
{
    uint8_t bPinNum;
    uint32_t dwGpioBaseAddress;

    /* Extract the Pin, Gpio details from dwPinNumber */
    bPinNum = (uint8_t)((dwPinNumber & 0xFF00000) >> 20);
    dwGpioBaseAddress = ((dwPinNumber & 0x00000FFF) | GPIO_BASE_ADDR);

    PINS_DRV_WritePin((GPIO_Type *) dwGpioBaseAddress, (pins_channel_type_t) bPinNum, (pins_level_type_t) bValue);
}


void phDriver_PinClearIntStatus(uint32_t dwPinNumber)
{
    uint8_t bPinNum;
    uint32_t dwPortBaseAddress;

    /* Extract the Pin, Gpio details from dwPinNumber */
    bPinNum = (uint8_t)((dwPinNumber & 0xFF00000) >> 20);
    dwPortBaseAddress = ((dwPinNumber & 0x000FF000) | PORT_BASE_ADDR);

    PINS_DRV_ClearPinIntFlagCmd((PORT_Type *) dwPortBaseAddress, bPinNum);
}


void LPIT0_Ch0_IRQHandler(void)
{
    /* Clear interrupt flag.*/
    LPIT_DRV_ClearInterruptFlagTimerChannels(PH_DRIVER_S32K_LPIT_INSTANCE, (1 << PH_DRIVER_S32K_LPIT_CHANNEL));

    /* Single shot timer. Stop it. */
    /* LPIT0 channel 0 counter */
    LPIT_DRV_StopTimerChannels(PH_DRIVER_S32K_LPIT_INSTANCE, (1 << PH_DRIVER_S32K_LPIT_CHANNEL));
    /* Disable interrupt for LPIT0 channel 0 */
    LPIT_DRV_DisableTimerChannelInterrupt(PH_DRIVER_S32K_LPIT_INSTANCE, (1 << PH_DRIVER_S32K_LPIT_CHANNEL));

    pPitTimerCallBack();

}


static void phDriver_PitTimerIsrCallBack(void)
{
    dwTimerExp = 1;
}

