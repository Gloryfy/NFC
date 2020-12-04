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
* Example Source abstracting component data structure and code initialization and code specific to HW used in the examples
* This file shall be present in all examples. A customer does not need to touch/modify this file. This file
* purely depends on the phNxpBuild_Lpc.h or phNxpBuild_App.h
* The phAppInit.h externs the component data structures initialized here that is in turn included by the core examples.
* The core example shall not use any other variable defined here except the RdLib component data structures(as explained above)
* The RdLib component initialization requires some user defined data and function pointers.
* These are defined in the respective examples and externed here.
*
* Keystore and Crypto initialization needs to be handled by application.
*
* $Author: jenkins_ cm (nxp92197) $
* $Revision: 4184 $ (v05.22.00)
* $Date: 2016-01-22 18:04:59 +0530 (Fri, 22 Jan 2016) $
*
* History:
* BK: Generated 25. Sept 2014
*
*/

/* Status header */
#include <ph_Status.h>

#include "phApp_Init.h"

/* NFCLIB Header */
#include <phNfcLib.h>

/* LLCP header */
#include <phlnLlcp.h>

#include <phOsal.h>

#ifdef PH_PLATFORM_HAS_ICFRONTEND
#include "BoardSelection.h"
#endif

#ifdef PHDRIVER_LPC1769
#include "board.h"
#endif /* PHDRIVER_LPC1769 */

#ifdef NXPBUILD__PHHAL_HW_NCx3330
/* HAL specific headers */
#include <phhalHw_Ncx3330_Instr.h>
#endif

#ifdef PHDRIVER_KINETIS_K82
#include <fsl_port.h>
#include <fsl_pit.h>
#ifdef DEBUG
#include <fsl_clock.h>
#endif
#endif /* PHDRIVER_KINETIS_K82 */

#ifdef NXPBUILD__PHHAL_HW_PN7462AU
#include <phFlashBoot.h>
#include <phhalTimer.h>
#endif /* NXPBUILD__PHHAL_HW_PN7462AU */

#ifdef PHDRIVER_S32K14x
#include "device_registers.h"
#include "clock_manager.h"
#include "interrupt_manager.h"
#include "osif.h"
#include "lpspi_master_driver.h"
#include "lpspi_shared_function.h"
#include "lpit_driver.h"
#include "system_S32K144.h"
#endif

#ifdef PHDRIVER_S32K116
#include "Cpu.h"
#include "clockMan1.h"
#include "pin_mux.h"
#include "dmaController1.h"
#include "lpit1.h"
#if CPU_INIT_CONFIG
#include "Init_Config.h"
#endif
#endif

#ifdef PHDRIVER_KINETIS_K82
#ifdef DEBUG

#define KINETIS_K82_DEBUG_UART_CLK_FREQ         CLOCK_GetOsc0ErClkFreq()
#define KINETIS_K82_DEBUG_UART_BASEADDR         ((uint32_t)LPUART4)
#define KINETIS_K82_DEBUG_UART_BAUDRATE         115200
#define KINETIS_K82_DEBUG_UART_TYPE             DEBUG_CONSOLE_DEVICE_TYPE_LPUART

#endif

/*! @brief Clock configuration structure. */
typedef struct _clock_config
{
    mcg_config_t mcgConfig;       /*!< MCG configuration.      */
    sim_clock_config_t simConfig; /*!< SIM configuration.      */
    osc_config_t oscConfig;       /*!< OSC configuration.      */
    uint32_t coreClock;           /*!< core clock frequency.   */
} clock_config_t;
#endif /* PHDRIVER_KINETIS_K82 */

#ifdef PH_OSAL_LINUX
#    define PI_IRQ_POLLING_TASK_PRIO    0
#    define PI_IRQ_POLLING_TASK_STACK   0x20000
     phOsal_ThreadObj_t gphPiThreadObj;
#endif /* PH_OSAL_LINUX */

#if defined(PHDRIVER_LPC1769) && defined(__CC_ARM)
uint32_t SystemCoreClock;
#endif

#if defined(PHDRIVER_S32K14x)
lpit_user_config_t lpit1_InitConfig_0 =
{
    .enableRunInDebug = false,         /*!< true: LPIT run in debug mode; false: LPIT stop in debug mode */
    .enableRunInDoze = false           /*!< true: LPIT run in doze mode; false: LPIT stop in doze mode */
};
#endif
/*******************************************************************************
**   Function Declarations
*******************************************************************************/
#ifdef PHDRIVER_KINETIS_K82
static void phApp_K82_Init(void);
#endif /* PHDRIVER_KINETIS_K82 */

#ifdef PHDRIVER_S32K14x
static void phApp_S32K14x_Init(void);
#endif

#ifdef PHDRIVER_S32K116
static void phApp_S32K116_Init(void);
#endif

#ifdef PH_OSAL_LINUX
static void phExample_IrqPolling(void* param);
#endif


#ifdef PH_PLATFORM_HAS_ICFRONTEND
void CLIF_IRQHandler(void);
#endif

phStatus_t phApp_Configure_IRQ();
phStatus_t phApp_Configure_LED(uint8_t led, uint8_t state);

/*******************************************************************************
**   Clock configuration of K82 Platform
*******************************************************************************/

#ifdef PHDRIVER_KINETIS_K82
/* Configuration for enter RUN mode. Core clock = 50MHz. */
const clock_config_t g_defaultClockConfigRun = {
    .mcgConfig =
        {
            .mcgMode = kMCG_ModePEE,             /* Work in PEE mode. */
            .irclkEnableMode = kMCG_IrclkEnable, /* MCGIRCLK enable. */
            .ircs = kMCG_IrcSlow,                /* Select IRC32k. */
            .fcrdiv = 0U,                        /* FCRDIV is 0. */

            .frdiv = 4U,
            .drs = kMCG_DrsLow,         /* Low frequency range. */
            .dmx32 = kMCG_Dmx32Default, /* DCO has a default range of 25%. */
            .oscsel = kMCG_OscselOsc,   /* Select OSC. */

            .pll0Config =
                {
                    .enableMode = 0U, .prdiv = 0x01U, .vdiv = 0x01U,
                },
        },
    .simConfig =
        {
            .pllFllSel = 1U,        /* PLLFLLSEL select PLL. */
            .pllFllDiv = 0U,        /* PLLFLLSEL clock divider divisor. */
            .pllFllFrac = 0U,       /* PLLFLLSEL clock divider fraction. */
            .er32kSrc = 5U,         /* ERCLK32K selection, use RTC. */
            .clkdiv1 = 0x01140000U, /* SIM_CLKDIV1. */
        },
    .oscConfig = {.freq = CPU_XTAL_CLK_HZ,
                  .capLoad = 0,
                  .workMode = kOSC_ModeOscLowPower,
                  .oscerConfig =
                      {
                          .enableMode = kOSC_ErClkEnable,
#if (defined(FSL_FEATURE_OSC_HAS_EXT_REF_CLOCK_DIVIDER) && FSL_FEATURE_OSC_HAS_EXT_REF_CLOCK_DIVIDER)
                          .erclkDiv = 0U,
#endif
                      }},

};
#endif /* PHDRIVER_KINETIS_K82 */

/*******************************************************************************
**   Global Variable Declaration
*******************************************************************************/
#ifdef PH_PLATFORM_HAS_ICFRONTEND
phbalReg_Type_t                 sBalParams;
#endif /* PH_PLATFORM_HAS_ICFRONTEND */

#ifdef NXPBUILD__PHHAL_HW_NCx3330
phhalHw_Ncx3330_DataParams_t   * pHal;
#endif

#ifdef NXPBUILD__PHHAL_HW_NCx3320
phhalHw_Ncx3320_DataParams_t    * pHal;
#endif

#ifdef NXPBUILD__PHHAL_HW_PN7462AU
phhalHw_PN7462AU_DataParams_t * pHal;
#endif

#ifdef NXPBUILD__PHLN_LLCP_SW
phlnLlcp_Sw_DataParams_t           slnLlcp;            /* LLCP component */
#endif /* NXPBUILD__PHLN_LLCP_SW */

/* General information bytes to be sent with ATR Request */
#if defined(NXPBUILD__PHPAL_I18092MPI_SW) || defined(NXPBUILD__PHPAL_I18092MT_SW)
uint8_t aLLCPGeneralBytes[36] = { 0x46,0x66,0x6D,
                                  0x01,0x01,0x10,       /*VERSION*/
                                  0x03,0x02,0x00,0x01,  /*WKS*/
                                  0x04,0x01,0xF1        /*LTO*/
                                 };
uint8_t   bLLCPGBLength = 13;
#endif

/* ATR Response or ATS Response holder */
#if defined(NXPBUILD__PHPAL_I14443P4A_SW)     || \
    defined(NXPBUILD__PHPAL_I18092MPI_SW)
uint8_t    aResponseHolder[64];
#endif

#ifdef NXPBUILD__PHHAL_HW_TARGET
/* Parameters for L3 activation during Autocoll */
extern uint8_t  sens_res[2]    ;
extern uint8_t  nfc_id1[3]     ;
extern uint8_t  sel_res        ;
extern uint8_t  nfc_id3        ;
extern uint8_t  poll_res[18]   ;
#endif /* NXPBUILD__PHHAL_HW_TARGET */

/* prints if error is detected */
#define CHECK_SUCCESS(x)              \
    if ((x) != PH_ERR_SUCCESS)        \
{                                     \
    DEBUG_PRINTF("\nLine: %d   Error - (0x%04X) has occurred : 0xCCEE CC-Component ID, EE-Error code. Refer-ph_Status.h\n ", __LINE__, (x)); \
    return (x);                       \
}

/*******************************************************************************
**   Function Definitions
*******************************************************************************/
#ifdef PHDRIVER_KINETIS_K82
static void phApp_K82_Init(void)
{
#ifdef DEBUG
    uint32_t uartClkSrcFreq;
#endif /* DEBUG */

    pit_config_t pitConfig;         /* Structure of initialize PIT */

    CLOCK_SetSimSafeDivs();

    CLOCK_InitOsc0(&g_defaultClockConfigRun.oscConfig);
    CLOCK_SetXtal0Freq(CPU_XTAL_CLK_HZ);

    CLOCK_BootToPeeMode(g_defaultClockConfigRun.mcgConfig.oscsel, kMCG_PllClkSelPll0,
        &g_defaultClockConfigRun.mcgConfig.pll0Config);

    CLOCK_SetInternalRefClkConfig(g_defaultClockConfigRun.mcgConfig.irclkEnableMode,
        g_defaultClockConfigRun.mcgConfig.ircs, g_defaultClockConfigRun.mcgConfig.fcrdiv);

    CLOCK_SetSimConfig(&g_defaultClockConfigRun.simConfig);

    SystemCoreClockUpdate();

    /*
     * pitConfig.enableRunInDebug = false;
     */
    PIT_GetDefaultConfig(&pitConfig);

    /* Init pit module */
    PIT_Init(PIT, &pitConfig);

#ifdef DEBUG

    /* Initialize LPUART4 pins below used to Print */
    /* Ungate the port clock */
    CLOCK_EnableClock(kCLOCK_PortC);
    /* Affects PORTC_PCR14 register */
    PORT_SetPinMux(PORTC, 14U, kPORT_MuxAlt3);
    /* Affects PORTC_PCR15 register */
    PORT_SetPinMux(PORTC, 15U, kPORT_MuxAlt3);

    /* SIM_SOPT2[27:26]:
     *  00: Clock Disabled
     *  01: MCGFLLCLK, or MCGPLLCLK, or IRC48M
     *  10: OSCERCLK
     *  11: MCGIRCCLK
     */
    CLOCK_SetLpuartClock(2);

    uartClkSrcFreq = KINETIS_K82_DEBUG_UART_CLK_FREQ;

    DbgConsole_Init(KINETIS_K82_DEBUG_UART_BASEADDR, KINETIS_K82_DEBUG_UART_BAUDRATE, KINETIS_K82_DEBUG_UART_TYPE, uartClkSrcFreq);
#endif /* DEBUG */
}
#endif /* PHDRIVER_KINETIS_K82 */

/* Clock configuration */
#ifdef PHDRIVER_S32K14x

/*! @brief Count of user configuration structures */
#define CLOCK_MANAGER_CONFIG_CNT 1U
/*! @brief Count of peripheral clock user configurations */
#define NUM_OF_PERIPHERAL_CLOCKS_0 7U
/*! @brief Count of user Callbacks */
#define CLOCK_MANAGER_CALLBACK_CNT 0U

peripheral_clock_config_t peripheralClockConfig0[NUM_OF_PERIPHERAL_CLOCKS_0] = {
    {
        .clockName        = LPIT0_CLK,
        .clkGate          = true,
        .clkSrc           = CLK_SRC_FIRC_DIV2,
        .frac             = MULTIPLY_BY_ONE,
        .divider          = DIVIDE_BY_ONE,
    },
    {
        .clockName        = LPSPI0_CLK,
        .clkGate          = true,
        .clkSrc           = CLK_SRC_FIRC_DIV2,
        .frac             = MULTIPLY_BY_ONE,
        .divider          = DIVIDE_BY_ONE,
    },
    {
        .clockName        = PORTA_CLK,
        .clkGate          = true,
        .clkSrc           = CLK_SRC_OFF,
        .frac             = MULTIPLY_BY_ONE,
        .divider          = DIVIDE_BY_ONE,
    },
    {
        .clockName        = PORTB_CLK,
        .clkGate          = true,
        .clkSrc           = CLK_SRC_OFF,
        .frac             = MULTIPLY_BY_ONE,
        .divider          = DIVIDE_BY_ONE,
    },
    {
        .clockName        = PORTC_CLK,
        .clkGate          = true,
        .clkSrc           = CLK_SRC_OFF,
        .frac             = MULTIPLY_BY_ONE,
        .divider          = DIVIDE_BY_ONE,
    },
    {
        .clockName        = PORTD_CLK,
        .clkGate          = true,
        .clkSrc           = CLK_SRC_OFF,
        .frac             = MULTIPLY_BY_ONE,
        .divider          = DIVIDE_BY_ONE,
    },
    {
        .clockName        = PORTE_CLK,
        .clkGate          = true,
        .clkSrc           = CLK_SRC_OFF,
        .frac             = MULTIPLY_BY_ONE,
        .divider          = DIVIDE_BY_ONE,
    },
};

/*! @brief User Configuration structure clockMan1_InitConfig0 */
clock_manager_user_config_t clockMan1_InitConfig0 = {
    /*! @brief Configuration of SIRC */
    .scgConfig =
    {
        .sircConfig =
        {
            .initialize       = true,                                /*!< Initialize */
            /* SIRCCSR */
            .enableInStop     = false,                               /*!< SIRCSTEN  */
            .enableInLowPower = true,                                /*!< SIRCLPEN  */
            .locked           = false,                               /*!< LK        */
            /* SIRCCFG */
            .range            = SCG_SIRC_RANGE_HIGH,                 /*!< RANGE - High range (8 MHz) */
            /* SIRCDIV */
            .div1             = SCG_ASYNC_CLOCK_DIV_BY_1,            /*!< SIRCDIV1  */
            .div2             = SCG_ASYNC_CLOCK_DIV_BY_1,            /*!< SIRCDIV2  */
        },
        .fircConfig =
        {
            .initialize       = true,                                /*!< Initialize */
            /* FIRCCSR */
            .regulator        = true,                                /*!< FIRCREGOFF */
            .locked           = false,                               /*!< LK         */
            /* FIRCCFG */
            .range            = SCG_FIRC_RANGE_48M,                  /*!< RANGE      */
            /* FIRCDIV */
            .div1             = SCG_ASYNC_CLOCK_DIV_BY_1,            /*!< FIRCDIV1   */
            .div2             = SCG_ASYNC_CLOCK_DIV_BY_1,            /*!< FIRCDIV2   */
        },
        .rtcConfig =
        {
            .initialize       = true,                                /*!< Initialize  */
            .rtcClkInFreq     = 0U,                                  /*!< RTC_CLKIN   */
        },
        .soscConfig =
        {
            .initialize       = true,                                /*!< Initialize */
            .freq             = 8000000U,                            /*!< Frequency  */
            /* SOSCCSR */
            .monitorMode      = SCG_SOSC_MONITOR_DISABLE,            /*!< SOSCCM      */
            .locked           = false,                               /*!< LK          */
            /* SOSCCFG */
            .extRef           = SCG_SOSC_REF_OSC,                    /*!< EREFS       */
            .gain             = SCG_SOSC_GAIN_LOW,                   /*!< HGO         */
            .range            = SCG_SOSC_RANGE_MID,                  /*!< RANGE       */
            /* SOSCDIV */
            .div1             = SCG_ASYNC_CLOCK_DIV_BY_1,            /*!< SOSCDIV1    */
            .div2             = SCG_ASYNC_CLOCK_DIV_BY_1,            /*!< SOSCDIV2    */
        },
        .spllConfig =
        {
            .initialize       = true,                                /*!< Initialize */
            /* SPLLCSR */
            .monitorMode      = SCG_SPLL_MONITOR_DISABLE,            /*!< SPLLCM     */
            .locked           = false,                               /*!< LK         */
            /* SPLLCFG */
            .prediv           = SCG_SPLL_CLOCK_PREDIV_BY_1,          /*!< PREDIV     */
            .mult             = SCG_SPLL_CLOCK_MULTIPLY_BY_28,       /*!< MULT       */
            .src              = 0U,                                  /*!< SOURCE     */
            /* SPLLDIV */
            .div1             = SCG_ASYNC_CLOCK_DIV_BY_1,            /*!< SPLLDIV1   */
            .div2             = SCG_ASYNC_CLOCK_DIV_BY_1,            /*!< SPLLDIV2   */
        },
        .clockOutConfig =
        {
            .initialize       = true,                                /*!< Initialize    */
            .source           = SCG_CLOCKOUT_SRC_FIRC,               /*!< SCG CLKOUTSEL     */
        },
        .clockModeConfig =
        {
            .initialize       = true,                                /*!< Initialize */
            .rccrConfig =              /*!< RCCR - Run Clock Control Register          */
            {
                .src          = SCG_SYSTEM_CLOCK_SRC_FIRC,           /*!< SCS        */
                .divCore      = SCG_SYSTEM_CLOCK_DIV_BY_1,           /*!< DIVCORE    */
                .divBus       = SCG_SYSTEM_CLOCK_DIV_BY_2,           /*!< DIVBUS     */
                .divSlow      = SCG_SYSTEM_CLOCK_DIV_BY_2,           /*!< DIVSLOW    */
            },
            .vccrConfig =              /*!< VCCR - VLPR Clock Control Register         */
            {
                .src          = SCG_SYSTEM_CLOCK_SRC_SIRC,           /*!< SCS        */
                .divCore      = SCG_SYSTEM_CLOCK_DIV_BY_2,           /*!< DIVCORE    */
                .divBus       = SCG_SYSTEM_CLOCK_DIV_BY_1,           /*!< DIVBUS     */
                .divSlow      = SCG_SYSTEM_CLOCK_DIV_BY_4,           /*!< DIVSLOW    */
            },
            .hccrConfig =              /*!< HCCR - HSRUN Clock Control Register        */
            {
                .src          = SCG_SYSTEM_CLOCK_SRC_SYS_PLL,        /*!< SCS        */
                .divCore      = SCG_SYSTEM_CLOCK_DIV_BY_1,           /*!< DIVCORE    */
                .divBus       = SCG_SYSTEM_CLOCK_DIV_BY_2,           /*!< DIVBUS     */
                .divSlow      = SCG_SYSTEM_CLOCK_DIV_BY_4,           /*!< DIVSLOW    */
            },
        },
    },
    .pccConfig =
    {
        .peripheralClocks = peripheralClockConfig0,                  /*!< Peripheral clock control configurations  */
        .count = NUM_OF_PERIPHERAL_CLOCKS_0,                         /*!< Number of the peripheral clock control configurations  */
    },
    .simConfig =
    {
        .clockOutConfig =              /*!< Clock Out configuration.           */
        {
            .initialize       = true,                                /*!< Initialize    */
            .enable           = false,                               /*!< CLKOUTEN      */
            .source           = SIM_CLKOUT_SEL_SYSTEM_SCG_CLKOUT,    /*!< CLKOUTSEL     */
            .divider          = SIM_CLKOUT_DIV_BY_1,                 /*!< CLKOUTDIV     */
        },
        .lpoClockConfig =              /*!< Low Power Clock configuration.     */
        {
            .initialize       = true,                                /*!< Initialize    */
            .enableLpo1k      = true,                                /*!< LPO1KCLKEN    */
            .enableLpo32k     = true,                                /*!< LPO32KCLKEN   */
            .sourceLpoClk     = SIM_LPO_CLK_SEL_LPO_128K,            /*!< LPOCLKSEL     */
            .sourceRtcClk     = SIM_RTCCLK_SEL_SOSCDIV1_CLK,         /*!< RTCCLKSEL     */
        },
        .platGateConfig =              /*!< Platform Gate Clock configuration. */
        {
            .initialize       = true,                                /*!< Initialize    */
            .enableMscm       = true,                                /*!< CGCMSCM       */
            .enableMpu        = true,                                /*!< CGCMPU        */
            .enableDma        = true,                                /*!< CGCDMA        */
            .enableErm        = true,                                /*!< CGCERM        */
            .enableEim        = true,                                /*!< CGCEIM        */
        },

        .qspiRefClkGating =            /*!< Quad Spi Internal Reference Clock Gating. */
        {
            .enableQspiRefClk  = false,                              /*!< Qspi reference clock gating    */
        },
        .tclkConfig =                  /*!< TCLK CLOCK configuration. */
        {
            .initialize       = true,                                /*!< Initialize    */
            .tclkFreq[0]      = 0U,                                  /*!< TCLK0         */
            .tclkFreq[1]      = 0U,                                  /*!< TCLK1         */
            .tclkFreq[2]      = 0U,                                  /*!< TCLK2         */
        },
        .traceClockConfig =            /*!< Debug trace Clock Configuration. */
        {
            .initialize       = true,                                /*!< Initialize    */
            .divEnable        = true,                                /*!< TRACEDIVEN    */
            .source           = CLOCK_TRACE_SRC_CORE_CLK,            /*!< TRACECLK_SEL  */
            .divider          = 0U,                                  /*!< TRACEDIV      */
            .divFraction      = false,                               /*!< TRACEFRAC     */
        },
    },
    .pmcConfig =
    {
        .lpoClockConfig =              /*!< Low Power Clock configuration.     */
        {
            .initialize       = true,                                /*!< Initialize             */
            .enable           = true,                                /*!< Enable/disable LPO     */
            .trimValue        = 0,                                   /*!< Trimming value for LPO */
        },
    },
};

/*! @brief Array of pointers to User configuration structures */
clock_manager_user_config_t const * g_clockManConfigsArr[] = {
    &clockMan1_InitConfig0
};
/*! @brief Array of pointers to User defined Callbacks configuration structures */
clock_manager_callback_user_config_t * g_clockManCallbacksArr[] = {(void*)0};

#endif

#ifdef PHDRIVER_S32K14x
static void phApp_S32K14x_Init(void)
{
    phDriver_Pin_Config_t pinCfg;

    /* Initialize clock */
    CLOCK_SYS_Init(g_clockManConfigsArr, CLOCK_MANAGER_CONFIG_CNT,
                            g_clockManCallbacksArr, CLOCK_MANAGER_CALLBACK_CNT);
    CLOCK_SYS_UpdateConfiguration(0U, CLOCK_MANAGER_POLICY_AGREEMENT);

    /* Initialize timer */
    LPIT_DRV_Init(PH_DRIVER_S32K_LPIT_INSTANCE, &lpit1_InitConfig_0);

    /* Config Green LED pin as output and set the default voltage level. */
    pinCfg.bPullSelect = PHDRIVER_PIN_RESET_PULL_CFG;
    pinCfg.bOutputLogic = RESET_POWERUP_LEVEL;
    phDriver_PinConfig(PHDRIVER_PIN_LED_GREEN, PH_DRIVER_PINFUNC_OUTPUT, &pinCfg);

    /* Config Red LED pin as output and set the default voltage level. */
    pinCfg.bPullSelect = PHDRIVER_PIN_RESET_PULL_CFG;
    pinCfg.bOutputLogic = RESET_POWERUP_LEVEL;
    phDriver_PinConfig(PHDRIVER_PIN_LED_RED, PH_DRIVER_PINFUNC_OUTPUT, &pinCfg);
}
#endif

#ifdef PHDRIVER_S32K116
static void phApp_S32K116_Init(void)
{
    /* Initialize and configure clocks
     *     -   see clock manager component for details
     */
    CLOCK_SYS_Init(g_clockManConfigsArr, CLOCK_MANAGER_CONFIG_CNT, g_clockManCallbacksArr, CLOCK_MANAGER_CALLBACK_CNT);
    CLOCK_SYS_UpdateConfiguration(0U, CLOCK_MANAGER_POLICY_AGREEMENT);

    /* Initialize pins
     *    -   See PinSettings component for more info
     */
    PINS_DRV_Init(NUM_OF_CONFIGURED_PINS, g_pin_mux_InitConfigArr);

    /* Testing the LEDs */
    /*phDriver_PinWrite(PHDRIVER_PIN_LED_GREEN, PH_DRIVER_SET_HIGH);
    phDriver_PinWrite(PHDRIVER_PIN_LED_RED, PH_DRIVER_SET_HIGH);

    phDriver_PinWrite(PHDRIVER_PIN_LED_GREEN, PH_DRIVER_SET_LOW);
    phDriver_PinWrite(PHDRIVER_PIN_LED_RED, PH_DRIVER_SET_LOW);*/
}
#endif

/**
* This function will initialize Host Controller.
* Any initialization which is not generic across Platforms, should be done here.
*/
void phApp_CPU_Init(void)
{
#if defined PHDRIVER_KINETIS_K82
    phApp_K82_Init();
#elif defined NXPBUILD__PHHAL_HW_PN7462AU
    phFlashBoot_Main();

    phhalTimer_Init();
#elif defined(PHDRIVER_LPC1769) && defined(__CC_ARM)
    SystemCoreClock =  (( unsigned long ) 96000000);
#elif defined(PHDRIVER_S32K14x)
    phApp_S32K14x_Init();
#elif defined(PHDRIVER_S32K116)
    phApp_S32K116_Init();
#else
    /* In case of LPC series, startup file takes care of initializing clock and ports.
     * No initialization is required in Linux environment. */
#endif
}

/**
* This function will initialize Reader LIbrary Component
*/
phStatus_t phApp_Comp_Init(void * pDiscLoopParams)
{
    phStatus_t wStatus = PH_ERR_SUCCESS;
#if defined(NXPBUILD__PHPAL_I18092MPI_SW) || defined(NXPBUILD__PHPAL_I18092MT_SW) || \
    defined(NXPBUILD__PHAC_DISCLOOP_TYPEA_P2P_TAGS) || defined(NXPBUILD__PHAC_DISCLOOP_TYPEA_P2P_ACTIVE) || \
	defined(NXPBUILD__PHAC_DISCLOOP_TYPEA_I3P4_TAGS) || defined(NXPBUILD__PHAC_DISCLOOP_TYPEF_P2P_TAGS) || \
	defined(NXPBUILD__PHAC_DISCLOOP_TYPEF212_P2P_ACTIVE) || defined(NXPBUILD__PHAC_DISCLOOP_TYPEF424_P2P_ACTIVE)

    phacDiscLoop_Sw_DataParams_t * pDiscLoop = (phacDiscLoop_Sw_DataParams_t *)pDiscLoopParams;
#endif

/* Initialize the LLCP component */
#ifdef NXPBUILD__PHLN_LLCP_SW
    slnLlcp.sLocalLMParams.wMiu = 0x00; /* 128 bytes only */
    slnLlcp.sLocalLMParams.wWks = 0x11; /* SNEP & LLCP */
    slnLlcp.sLocalLMParams.bLto = 100; /* Maximum LTO */
    slnLlcp.sLocalLMParams.bOpt = 0x02;
    slnLlcp.sLocalLMParams.bAvailableTlv = PHLN_LLCP_TLV_MIUX_MASK | PHLN_LLCP_TLV_WKS_MASK |
        PHLN_LLCP_TLV_LTO_MASK | PHLN_LLCP_TLV_OPT_MASK;

    wStatus = phlnLlcp_Sw_Init(
        &slnLlcp,
        sizeof(phlnLlcp_Sw_DataParams_t),
        aLLCPGeneralBytes,
        &bLLCPGBLength);
#endif /* NXPBUILD__PHLN_LLCP_SW */

#ifdef NXPBUILD__PHAC_DISCLOOP_SW
#if defined(NXPBUILD__PHPAL_I18092MPI_SW) || defined(NXPBUILD__PHPAL_I18092MT_SW)
    /* Assign the GI for Type A */
    pDiscLoop->sTypeATargetInfo.sTypeA_P2P.pGi       = (uint8_t *)aLLCPGeneralBytes;
    pDiscLoop->sTypeATargetInfo.sTypeA_P2P.bGiLength = bLLCPGBLength;
    /* Assign the GI for Type F */
//    pDiscLoop->sTypeFTargetInfo.sTypeF_P2P.pGi       = (uint8_t *)aLLCPGeneralBytes;//alan 2020
//    pDiscLoop->sTypeFTargetInfo.sTypeF_P2P.bGiLength = bLLCPGBLength;//alan 2020
#endif

#if defined(NXPBUILD__PHAC_DISCLOOP_TYPEA_P2P_TAGS) || defined(NXPBUILD__PHAC_DISCLOOP_TYPEA_P2P_ACTIVE)
    /* Assign ATR response for Type A */
    pDiscLoop->sTypeATargetInfo.sTypeA_P2P.pAtrRes   = aResponseHolder;
#endif
#if defined(NXPBUILD__PHAC_DISCLOOP_TYPEF_P2P_TAGS) ||  defined(NXPBUILD__PHAC_DISCLOOP_TYPEF212_P2P_ACTIVE) || \
    defined(NXPBUILD__PHAC_DISCLOOP_TYPEF424_P2P_ACTIVE)
    /* Assign ATR response for Type F */
    pDiscLoop->sTypeFTargetInfo.sTypeF_P2P.pAtrRes   = aResponseHolder;
#endif
#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEA_I3P4_TAGS
    /* Assign ATS buffer for Type A */
    pDiscLoop->sTypeATargetInfo.sTypeA_I3P4.pAts     = aResponseHolder;
#endif /* NXPBUILD__PHAC_DISCLOOP_TYPEA_I3P4_TAGS */
#endif /* NXPBUILD__PHAC_DISCLOOP_SW */
    return wStatus;
}

/**
* This function will initialize Hal Target Config
*/
phStatus_t phApp_HALConfigAutoColl(void)
{
#ifdef NXPBUILD__PHHAL_HW_TARGET
    phStatus_t wStatus;
#endif /* NXPBUILD__PHHAL_HW_TARGET */

#if defined(NXPBUILD__PHHAL_HW_NCx3330) && defined(NXPBUILD__PHHAL_HW_TARGET)
    uint8_t aCmd[1] = {0x01};   /* Enable Random UID feature on Ncx3330 FW. */
#endif

#if defined(NXPBUILD__PHHAL_HW_PN7462AU) && defined(NXPBUILD__PHHAL_HW_TARGET)
    uint8_t bSystemCode[] = {0xFF, 0xFF};
#endif /* NXPBUILD__PHHAL_HW_PN7462AU && NXPBUILD__PHHAL_HW_TARGET */

#if defined(NXPBUILD__PHHAL_HW_NCx3330) && defined(NXPBUILD__PHHAL_HW_TARGET)
    /* Set Listen Parameters in HAL Buffer used during Autocoll */
    wStatus = phhalHw_Ncx3330_SetListenParameters(
        pHal,
        &sens_res[0],
        &nfc_id1[0],
        sel_res,
        &poll_res[0],
        nfc_id3);
    CHECK_SUCCESS(wStatus);

    if (pHal->wFirmwareVer < 0x308)
    {
        /* With Ncx3330 FW version < 3.8, static UID is supported by default. */
        aCmd[0] = 0x00;
    }
    /* Enabling the Random UID in 5180 EEPROM */
    wStatus = phhalHw_Ncx3330_Instr_WriteE2Prom(
        (phhalHw_Ncx3330_DataParams_t *) pHal,
        0x58,
        aCmd,
        0x01
        );

    CHECK_SUCCESS(wStatus);
#endif

#if defined(NXPBUILD__PHHAL_HW_PN7462AU) && defined(NXPBUILD__PHHAL_HW_TARGET)
    /* Set Listen Parameters in HAL Buffer used during Autocoll */
    wStatus = phhalHw_PN7462AU_SetListenParam(
       pHal,
       &sens_res[0],
       &nfc_id1[0],
       sel_res,
       (poll_res[0] == 0x02 ? PH_ON : PH_OFF),
       &poll_res[2],
       &poll_res[8],
       bSystemCode);
    CHECK_SUCCESS(wStatus);
#endif

    return PH_ERR_SUCCESS;
}

phStatus_t phApp_Configure_IRQ()
{
#ifdef PH_OSAL_LINUX
    phStatus_t  wStatus;
#endif /* PH_OSAL_LINUX */

#ifdef PH_PLATFORM_HAS_ICFRONTEND
    phDriver_Pin_Config_t pinCfg;

    pinCfg.bOutputLogic = PH_DRIVER_SET_LOW;
    pinCfg.bPullSelect = PHDRIVER_PIN_IRQ_PULL_CFG;

    pinCfg.eInterruptConfig = PIN_IRQ_TRIGGER_TYPE;
    phDriver_PinConfig(PHDRIVER_PIN_IRQ, PH_DRIVER_PINFUNC_INTERRUPT, &pinCfg);

#ifdef PHDRIVER_LPC1769
    NVIC_SetPriority(EINT_IRQn, EINT_PRIORITY);
    /* Enable interrupt in the NVIC */
    NVIC_ClearPendingIRQ(EINT_IRQn);
    NVIC_EnableIRQ(EINT_IRQn);
#endif /* PHDRIVER_LPC1769 */

#ifdef PH_OSAL_LINUX

    gphPiThreadObj.pTaskName = (uint8_t *) "IrqPolling";
    gphPiThreadObj.pStackBuffer = NULL;
    gphPiThreadObj.priority = PI_IRQ_POLLING_TASK_PRIO;
    gphPiThreadObj.stackSizeInNum = PI_IRQ_POLLING_TASK_STACK;
    PH_CHECK_SUCCESS_FCT(wStatus, phOsal_ThreadCreate(&gphPiThreadObj.ThreadHandle, &gphPiThreadObj,
        &phExample_IrqPolling, NULL));

#endif /* PH_OSAL_LINUX */

#ifdef PHDRIVER_KINETIS_K82
    NVIC_SetPriority(EINT_IRQn, EINT_PRIORITY);
    NVIC_ClearPendingIRQ(EINT_IRQn);
    EnableIRQ(EINT_IRQn);
#endif /* PHDRIVER_KINETIS_K82 */

#ifdef PHDRIVER_S32K14x
    INT_SYS_SetPriority(EINT_IRQn, EINT_PRIORITY);
    INT_SYS_ClearPending(EINT_IRQn);
    INT_SYS_EnableIRQ(EINT_IRQn);
#endif

#ifdef PHDRIVER_S32K116
    INT_SYS_SetPriority(EINT_IRQn, EINT_PRIORITY);
    INT_SYS_ClearPending(EINT_IRQn);
    INT_SYS_EnableIRQ(EINT_IRQn);

    /* Install EINT interrupt handler */
    INT_SYS_InstallHandler(EINT_IRQn, &CLIF_IRQHandler, (isr_t *)0);
#endif
#endif /* #ifdef PH_PLATFORM_HAS_ICFRONTEND */

    return PH_ERR_SUCCESS;
}

phStatus_t phApp_Configure_LED(uint8_t led, uint8_t state)
{
	uint32_t pin_number = 0;
	uint8_t pin_state   = 0;

	switch(led)
	{
	case 0:
		pin_number = PHDRIVER_PIN_LED_RED;
		break;
	case 1:
		pin_number = PHDRIVER_PIN_LED_GREEN;
		break;
	default:
		break;
	}

	if(state != 0)
	{
		pin_state = RESET_POWERUP_LEVEL;
	}
	else
	{
		pin_state = RESET_POWERDOWN_LEVEL;
	}

    phDriver_PinWrite(pin_number, pin_state);

    return PH_ERR_SUCCESS;
}


#ifdef PH_OSAL_LINUX
/*
 * \brief: The purpose of this Thread is to detect RF signal from an External Peer .
 */
static void phExample_IrqPolling(void* param)
{
    uint8_t bgpioVal = 0;
    uint8_t bhighOrLow = 0;

    if(PIN_IRQ_TRIGGER_TYPE ==  PH_DRIVER_INTERRUPT_RISINGEDGE)
    {
        bhighOrLow = 1;
    }

    while(PiGpio_read(PHDRIVER_PIN_IRQ, &bgpioVal) != PH_ERR_SUCCESS)
    {
        PiGpio_unexport(PHDRIVER_PIN_IRQ);
        PiGpio_export(PHDRIVER_PIN_IRQ);
        PiGpio_set_direction(PHDRIVER_PIN_IRQ, false);

        if(PIN_IRQ_TRIGGER_TYPE ==  PH_DRIVER_INTERRUPT_RISINGEDGE)
        {
            PiGpio_set_edge(PHDRIVER_PIN_IRQ, true, false);
        }
        else
        {
            PiGpio_set_edge(PHDRIVER_PIN_IRQ, false, true);
        }
    }

    /* Initial status: If pin is already Active, post an event. */
    if(bgpioVal == bhighOrLow)
    {
        CLIF_IRQHandler();
    }

    while(1)
    {
        /* Block forever for Raising Edge in PHDRIVER_PIN_IRQ. */
        if(PiGpio_poll(PHDRIVER_PIN_IRQ, bhighOrLow, -1) == PH_ERR_SUCCESS)
        {
            CLIF_IRQHandler();
        }
        else
        {
            PiGpio_unexport(PHDRIVER_PIN_IRQ);

            PiGpio_export(PHDRIVER_PIN_IRQ);

            PiGpio_set_direction(PHDRIVER_PIN_IRQ, false);

            if(PIN_IRQ_TRIGGER_TYPE ==  PH_DRIVER_INTERRUPT_RISINGEDGE)
            {
                PiGpio_set_edge(PHDRIVER_PIN_IRQ, true, false);
            }
            else
            {
                PiGpio_set_edge(PHDRIVER_PIN_IRQ, false, true);
            }
        }


    }
}
#endif /* PH_OSAL_LINUX */


#ifdef PH_PLATFORM_HAS_ICFRONTEND
void CLIF_IRQHandler(void)
{
    /* Read the interrupt status of external interrupt attached to the reader IC IRQ pin */
    if (phDriver_PinRead(PHDRIVER_PIN_IRQ, PH_DRIVER_PINFUNC_INTERRUPT))
    {
        /* Call application registered callback. */
        if (pHal->pRFISRCallback != NULL)
        {
            pHal->pRFISRCallback(pHal);
        }
    }
    phDriver_PinClearIntStatus(PHDRIVER_PIN_IRQ);
}
#endif /* PH_PLATFORM_HAS_ICFRONTEND */


#ifdef NXPBUILD__PHHAL_HW_NCx3320
/* Configure LPCD (for NCx3320) */
phStatus_t phApp_ConfigureLPCD(void)
{
    phStatus_t status;
    uint8_t bValueI;
    uint8_t bValueQ;

    /* Configure LPCD calibration standby time (T4) and RF ON time (T3). */
    status = phhalHw_Ncx3320_Cmd_Lpcd_SetConfig(
        pHal,
        PHHAL_HW_NCx3320_CMD_LPCD_MODE_DEFAULT,
        0,
        0,
        PH_NFCRDLIB_EXAMPLE_LPCD_GUARDTIME,
        PH_NFCRDLIB_EXAMPLE_LPCD_RFON_TIME);

    /* Perform LPCD calibration to get I and Q values. */
	do {
		status = phhalHw_Ncx3320_Cmd_Lpcd_GetConfig(pHal, &bValueI, &bValueQ);
	} while (status == PH_STATUS_INPROCESS);
	CHECK_SUCCESS(status);

	DEBUG_PRINTF("[User Log]bValueI: %d, bValueQ: %d\r\n",bValueI,bValueQ);

    /* Configure I and Q values for LPCD detection cycle. */
    status = phhalHw_Ncx3320_Cmd_Lpcd_SetConfig(
        pHal,
        PHHAL_HW_NCx3320_CMD_LPCD_MODE_POWERDOWN,
        bValueI,
        bValueQ,
        PH_NFCRDLIB_EXAMPLE_LPCD_GUARDTIME,
        PH_NFCRDLIB_EXAMPLE_LPCD_RFON_TIME);

    return status;
}
#endif

#ifdef NXPBUILD__PHHAL_HW_NCx3330
/* Configure LPCD (for NCx3330) */
phStatus_t phApp_ConfigureLPCD(void)
{
    /**
     * PHHAL_HW_CONFIG_SET_LPCD_WAKEUPTIME_MS  0x0070U     //< Used value for wakeup counter in msecs, i.e. after this amount of time IC will wakes up from standby.
     * PHHAL_HW_CONFIG_LPCD_MODE               0x0071U     //< Used to set options  PHHAL_HW_NCx3330_LPCD_MODE_DEFAULT or PHHAL_HW_NCx3330_LPCD_MODE_POWERDOWN_GUARDED
     * PHHAL_HW_CONFIG_LPCD_REF                0x0072U     //< Used to set or get LPCD Ref
     */
        phStatus_t status = PH_ERR_SUCCESS;
        uint16_t wConfig = PHHAL_HW_CONFIG_LPCD_REF;
        uint16_t wValue;
        uint8_t bLPCD_Threshold_EEPROMAddress = 0x37;
        uint8_t bLPCD_Threshold = 0x10;
        wValue = PHHAL_HW_NCx3330_LPCD_MODE_POWERDOWN;
        wConfig = PHHAL_HW_CONFIG_LPCD_MODE;

        //status = phhalHw_Ncx3330_Int_LPCD_GetConfig(pHal, wConfig, &wValue);
        status = phhalHw_Ncx3330_Instr_WriteE2Prom(pHal,bLPCD_Threshold_EEPROMAddress, &bLPCD_Threshold, 1 );
        CHECK_SUCCESS(status);
        status = phhalHw_Ncx3330_Int_LPCD_SetConfig(
            pHal,
            wConfig,
            wValue
            );

        return status;
}
#endif

#ifdef NXPBUILD__PHHAL_HW_PN7462AU
/* Configure LPCD (for PN7462AU) */
phStatus_t phApp_ConfigureLPCD(void)
{
    phStatus_t status;
    uint16_t wLpcdValue;

    wLpcdValue = 0;

    status = phhalHw_GetConfig(pHal, PHHAL_HW_CONFIG_PN7462AU_LPCD_NEW_VALUE, &wLpcdValue);
    CHECK_SUCCESS(status);

    if (wLpcdValue != 0x00)
    {
        status = phhalHw_SetConfig(pHal, PHHAL_HW_CONFIG_PN7462AU_LPCD_REF_VALUE, wLpcdValue);
        CHECK_SUCCESS(status);
    }

    return status;
}
#endif /* NXPBUILD__PHHAL_HW_PN7462AU */

/* Print technology being resolved */
void phApp_PrintTech(uint8_t TechType)
{
    switch(TechType)
    {
    case PHAC_DISCLOOP_POS_BIT_MASK_A:
        DEBUG_PRINTF ("\tResolving Type A... \n");
        break;

    case PHAC_DISCLOOP_POS_BIT_MASK_B:
        DEBUG_PRINTF ("\tResolving Type B... \n");
        break;

    case PHAC_DISCLOOP_POS_BIT_MASK_F212:
        DEBUG_PRINTF ("\tResolving Type F with baud rate 212... \n");
        break;

    case PHAC_DISCLOOP_POS_BIT_MASK_F424:
        DEBUG_PRINTF ("\tResolving Type F with baud rate 424... \n");
        break;

    case PHAC_DISCLOOP_POS_BIT_MASK_V:
        DEBUG_PRINTF ("\tResolving Type V... \n");
        break;

    default:
        break;
    }
}

/**
* This function will print buffer content
* \param   *pBuff   Buffer Reference
* \param   num      data size to be print
*/
void phApp_Print_Buff(uint8_t *pBuff, uint8_t num)
{
    uint32_t    i;

    for(i = 0; i < num; i++)
    {
        DEBUG_PRINTF(" %02X",pBuff[i]);
    }
}

/**
* This function will print Tag information
* \param   pDataParams      The discovery loop data parameters
* \param   wNumberOfTags    Total number of tags detected
* \param   wTagsDetected    Technology Detected
*/
void phApp_PrintTagInfo(phacDiscLoop_Sw_DataParams_t *pDataParams, uint16_t wNumberOfTags, uint16_t wTagsDetected)
{
#if defined(NXPBUILD__PHAC_DISCLOOP_TYPEA_TAGS) || \
    defined(NXPBUILD__PHAC_DISCLOOP_TYPEA_P2P_ACTIVE) || \
    defined(NXPBUILD__PHAC_DISCLOOP_TYPEB_TAGS) || \
    defined(NXPBUILD__PHAC_DISCLOOP_TYPEF_TAGS) || \
    defined(NXPBUILD__PHAC_DISCLOOP_TYPEV_TAGS) || \
    defined(NXPBUILD__PHAC_DISCLOOP_I18000P3M3_TAGS)
    uint8_t bIndex;
#endif
#if defined(NXPBUILD__PHAC_DISCLOOP_TYPEA_TAGS) || defined(NXPBUILD__PHAC_DISCLOOP_TYPEA_P2P_ACTIVE)
    uint8_t bTagType;
#endif

#if defined(NXPBUILD__PHAC_DISCLOOP_TYPEA_TAGS) || defined(NXPBUILD__PHAC_DISCLOOP_TYPEA_P2P_ACTIVE)
    if (PHAC_DISCLOOP_CHECK_ANDMASK(wTagsDetected, PHAC_DISCLOOP_POS_BIT_MASK_A))
    {
        if(pDataParams->sTypeATargetInfo.bT1TFlag)
        {
            DEBUG_PRINTF("\tTechnology  : Type A");
            DEBUG_PRINTF ("\n\t\tUID :");
            phApp_Print_Buff( pDataParams->sTypeATargetInfo.aTypeA_I3P3[0].aUid,
                        pDataParams->sTypeATargetInfo.aTypeA_I3P3[0].bUidSize);
            DEBUG_PRINTF ("\n\t\tSAK : 0x%02x",pDataParams->sTypeATargetInfo.aTypeA_I3P3[0].aSak);
            DEBUG_PRINTF ("\n\t\tType: Type 1 Tag\n");
        }
        else
        {
            DEBUG_PRINTF("\tTechnology  : Type A");
            for(bIndex = 0; bIndex < wNumberOfTags; bIndex++)
            {
                DEBUG_PRINTF ("\n\t\tCard: %d",bIndex + 1);
                DEBUG_PRINTF ("\n\t\tUID :");
                phApp_Print_Buff( pDataParams->sTypeATargetInfo.aTypeA_I3P3[bIndex].aUid,
                            pDataParams->sTypeATargetInfo.aTypeA_I3P3[bIndex].bUidSize);
                DEBUG_PRINTF ("\n\t\tSAK : 0x%02x",pDataParams->sTypeATargetInfo.aTypeA_I3P3[bIndex].aSak);

                if ((pDataParams->sTypeATargetInfo.aTypeA_I3P3[bIndex].aSak & (uint8_t) ~0xFB) == 0)
                {
                    /* Bit b3 is set to zero, [Digital] 4.8.2 */
                    /* Mask out all other bits except for b7 and b6 */
                    bTagType = (pDataParams->sTypeATargetInfo.aTypeA_I3P3[bIndex].aSak & 0x60);
                    bTagType = bTagType >> 5;

                    switch(bTagType)
                    {
                    case PHAC_DISCLOOP_TYPEA_TYPE2_TAG_CONFIG_MASK:
                        DEBUG_PRINTF ("\n\t\tType: Type 2 Tag\n");
                        break;
                    case PHAC_DISCLOOP_TYPEA_TYPE4A_TAG_CONFIG_MASK:
                        DEBUG_PRINTF ("\n\t\tType: Type 4A Tag\n");
                        break;
                    case PHAC_DISCLOOP_TYPEA_TYPE_NFC_DEP_TAG_CONFIG_MASK:
                        DEBUG_PRINTF ("\n\t\tType: P2P\n");
                        break;
                    case PHAC_DISCLOOP_TYPEA_TYPE_NFC_DEP_TYPE4A_TAG_CONFIG_MASK:
                        DEBUG_PRINTF ("\n\t\tType: Type NFC_DEP and  4A Tag\n");
                        break;
                    default:
                        break;
                    }
                }
            }
        }
    }
#endif

#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEB_TAGS
    if (PHAC_DISCLOOP_CHECK_ANDMASK(wTagsDetected, PHAC_DISCLOOP_POS_BIT_MASK_B))
    {
        DEBUG_PRINTF("\tTechnology  : Type B");
        /* Loop through all the Type B tags detected and print the Pupi */
        for (bIndex = 0; bIndex < wNumberOfTags; bIndex++)
        {
            DEBUG_PRINTF ("\n\t\tCard: %d",bIndex + 1);
            DEBUG_PRINTF ("\n\t\tUID :");
            /* PUPI Length is always 4 bytes */
            phApp_Print_Buff( pDataParams->sTypeBTargetInfo.aTypeB_I3P3[bIndex].aPupi, 0x04);
        }
        DEBUG_PRINTF("\n");
    }
#endif

#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEF_TAGS
    if( PHAC_DISCLOOP_CHECK_ANDMASK(wTagsDetected, PHAC_DISCLOOP_POS_BIT_MASK_F212) ||
        PHAC_DISCLOOP_CHECK_ANDMASK(wTagsDetected, PHAC_DISCLOOP_POS_BIT_MASK_F424))
    {
        DEBUG_PRINTF("\tTechnology  : Type F");

        /* Loop through all the type F tags and print the IDm */
        for (bIndex = 0; bIndex < wNumberOfTags; bIndex++)
        {
            DEBUG_PRINTF ("\n\t\tCard: %d",bIndex + 1);
            DEBUG_PRINTF ("\n\t\tUID :");
            phApp_Print_Buff( pDataParams->sTypeFTargetInfo.aTypeFTag[bIndex].aIDmPMm,
                        PHAC_DISCLOOP_FELICA_IDM_LENGTH );
            if ((pDataParams->sTypeFTargetInfo.aTypeFTag[bIndex].aIDmPMm[0] == 0x01) &&
                (pDataParams->sTypeFTargetInfo.aTypeFTag[bIndex].aIDmPMm[1] == 0xFE))
            {
                /* This is Type F tag with P2P capabilities */
                DEBUG_PRINTF ("\n\t\tType: P2P");
            }
            else
            {
                /* This is Type F T3T tag */
                DEBUG_PRINTF ("\n\t\tType: Type 3 Tag");
            }

            if(pDataParams->sTypeFTargetInfo.aTypeFTag[bIndex].bBaud != PHAC_DISCLOOP_CON_BITR_212)
            {
                DEBUG_PRINTF ("\n\t\tBit Rate: 424\n");
            }
            else
            {
                DEBUG_PRINTF ("\n\t\tBit Rate: 212\n");
            }
        }
    }
#endif

#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEV_TAGS
    if (PHAC_DISCLOOP_CHECK_ANDMASK(wTagsDetected, PHAC_DISCLOOP_POS_BIT_MASK_V))
    {
        DEBUG_PRINTF("\tTechnology  : Type V / ISO 15693 / T5T");
        /* Loop through all the Type V tags detected and print the UIDs */
        for (bIndex = 0; bIndex < wNumberOfTags; bIndex++)
        {
            DEBUG_PRINTF ("\n\t\tCard: %d",bIndex + 1);
            DEBUG_PRINTF ("\n\t\tUID :");
            phApp_Print_Buff( pDataParams->sTypeVTargetInfo.aTypeV[bIndex].aUid, 0x08);
        }
        DEBUG_PRINTF("\n");
    }
#endif

#ifdef NXPBUILD__PHAC_DISCLOOP_I18000P3M3_TAGS
    if (PHAC_DISCLOOP_CHECK_ANDMASK(wTagsDetected, PHAC_DISCLOOP_POS_BIT_MASK_18000P3M3))
    {
        DEBUG_PRINTF("\tTechnology  : ISO 18000p3m3 / EPC Gen2");
        /* Loop through all the 18000p3m3 tags detected and print the UII */
        for (bIndex = 0; bIndex < wNumberOfTags; bIndex++)
        {
            DEBUG_PRINTF("\n\t\tCard: %d",bIndex + 1);
            DEBUG_PRINTF("\n\t\tUII :");
            phApp_Print_Buff(
                pDataParams->sI18000p3m3TargetInfo.aI18000p3m3[bIndex].aUii,
                (pDataParams->sI18000p3m3TargetInfo.aI18000p3m3[bIndex].wUiiLength / 8));
        }
        DEBUG_PRINTF("\n");
    }
#endif
}

/**
* This function will print Error information received from Reader Lib
* \param   wStatus      Error status
*/
void PrintErrorInfo(phStatus_t wStatus)
{
    DEBUG_PRINTF("\n ErrorInfo Comp:");

    switch(wStatus & 0xFF00)
    {
    case PH_COMP_BAL:
        DEBUG_PRINTF("\t PH_COMP_BAL");
        break;
    case PH_COMP_HAL:
        DEBUG_PRINTF("\t PH_COMP_HAL");
        break;
    case PH_COMP_PAL_ISO14443P3A:
        DEBUG_PRINTF("\t PH_COMP_PAL_ISO14443P3A");
        break;
    case PH_COMP_PAL_ISO14443P3B:
        DEBUG_PRINTF("\t PH_COMP_PAL_ISO14443P3B");
        break;
    case PH_COMP_PAL_ISO14443P4A:
        DEBUG_PRINTF("\t PH_COMP_PAL_ISO14443P4A");
        break;
    case PH_COMP_PAL_ISO14443P4:
        DEBUG_PRINTF("\t PH_COMP_PAL_ISO14443P4");
        break;
    case PH_COMP_PAL_FELICA:
        DEBUG_PRINTF("\t PH_COMP_PAL_FELICA");
        break;
    case PH_COMP_PAL_EPCUID:
        DEBUG_PRINTF("\t PH_COMP_PAL_EPCUID");
        break;
    case PH_COMP_PAL_SLI15693:
        DEBUG_PRINTF("\t PH_COMP_PAL_SLI15693");
        break;
    case PH_COMP_PAL_I18000P3M3:
        DEBUG_PRINTF("\t PH_COMP_PAL_I18000P3M3");
        break;
    case PH_COMP_PAL_I18092MPI:
        DEBUG_PRINTF("\t PH_COMP_PAL_I18092MPI");
        break;
    case PH_COMP_PAL_I18092MT:
        DEBUG_PRINTF("\t PH_COMP_PAL_I18092MT");
        break;
    case PH_COMP_PAL_GENERALTARGET:
        DEBUG_PRINTF("\t PH_COMP_PAL_GENERALTARGET");
        break;
    case PH_COMP_PAL_I14443P4MC:
        DEBUG_PRINTF("\t PH_COMP_PAL_I14443P4MC");
        break;
    case PH_COMP_AC_DISCLOOP:
        DEBUG_PRINTF("\t PH_COMP_AC_DISCLOOP");
        break;
    case PH_COMP_OSAL:
        DEBUG_PRINTF("\t PH_COMP_OSAL");
        break;
    default:
        DEBUG_PRINTF("\t 0x%x",(wStatus & PH_COMPID_MASK));
        break;
    }

    DEBUG_PRINTF("\t type:");

    switch(wStatus & PH_ERR_MASK)
    {
    case PH_ERR_SUCCESS_INCOMPLETE_BYTE:
        DEBUG_PRINTF("\t PH_ERR_SUCCESS_INCOMPLETE_BYTE");
        break;
    case PH_ERR_IO_TIMEOUT:
        DEBUG_PRINTF("\t PH_ERR_IO_TIMEOUT");
        break;
    case PH_ERR_INTEGRITY_ERROR:
        DEBUG_PRINTF("\t PH_ERR_INTEGRITY_ERROR");
        break;
    case PH_ERR_COLLISION_ERROR:
        DEBUG_PRINTF("\t PH_ERR_COLLISION_ERROR");
        break;
    case PH_ERR_BUFFER_OVERFLOW:
        DEBUG_PRINTF("\t PH_ERR_BUFFER_OVERFLOW");
        break;
    case PH_ERR_FRAMING_ERROR:
        DEBUG_PRINTF("\t PH_ERR_FRAMING_ERROR");
        break;
    case PH_ERR_PROTOCOL_ERROR:
        DEBUG_PRINTF("\t PH_ERR_PROTOCOL_ERROR");
        break;
    case PH_ERR_RF_ERROR:
        DEBUG_PRINTF("\t PH_ERR_RF_ERROR");
        break;
    case PH_ERR_EXT_RF_ERROR:
        DEBUG_PRINTF("\t PH_ERR_EXT_RF_ERROR");
        break;
    case PH_ERR_NOISE_ERROR:
        DEBUG_PRINTF("\t PH_ERR_NOISE_ERROR");
        break;
    case PH_ERR_ABORTED:
        DEBUG_PRINTF("\t PH_ERR_ABORTED");
        break;
    case PH_ERR_INTERNAL_ERROR:
        DEBUG_PRINTF("\t PH_ERR_INTERNAL_ERROR");
        break;
    case PH_ERR_INVALID_DATA_PARAMS:
        DEBUG_PRINTF("\t PH_ERR_INVALID_DATA_PARAMS");
        break;
    case PH_ERR_INVALID_PARAMETER:
        DEBUG_PRINTF("\t PH_ERR_INVALID_PARAMETER");
        break;
    case PH_ERR_PARAMETER_OVERFLOW:
        DEBUG_PRINTF("\t PH_ERR_PARAMETER_OVERFLOW");
        break;
    case PH_ERR_UNSUPPORTED_PARAMETER:
        DEBUG_PRINTF("\t PH_ERR_UNSUPPORTED_PARAMETER");
        break;
    case PH_ERR_OSAL_ERROR:
        DEBUG_PRINTF("\t PH_ERR_OSAL_ERROR");
        break;
    case PHAC_DISCLOOP_LPCD_NO_TECH_DETECTED:
        DEBUG_PRINTF("\t PHAC_DISCLOOP_LPCD_NO_TECH_DETECTED");
        break;
    case PHAC_DISCLOOP_COLLISION_PENDING:
        DEBUG_PRINTF("\t PHAC_DISCLOOP_COLLISION_PENDING");
        break;
    default:
        DEBUG_PRINTF("\t 0x%x",(wStatus & PH_ERR_MASK));
        break;
    }
}


/******************************************************************************
**                            End Of File
******************************************************************************/
