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


#ifndef BOARD_FRDM_K82FNCx3330_H_
#define BOARD_FRDM_K82FNCx3330_H_

#define GPIO_PORT_A         0    /* Same macro for GPIOA/PORTA */
#define GPIO_PORT_B         1    /* Same macro for GPIOB/PORTB */
#define GPIO_PORT_C         2    /* Same macro for GPIOC/PORTC */
#define GPIO_PORT_D         3    /* Same macro for GPIOD/PORTD */
#define GPIO_PORT_E         4    /* Same macro for GPIOE/PORTE */

/******************************************************************
 * Board Pin/Gpio configurations
 ******************************************************************/
/* Pin configuration format : Its a 32 bit format where every byte represents a field as shown below.
 * | Byte3 | Byte2 | Byte1      | Byte0 |
 * |  --   |  --   | GPIO/PORT  | PIN   |
 * */
#define PHDRIVER_PIN_RESET  ((GPIO_PORT_A << 8) | 13)  /**< Reset pin, Pin13, GPIOA, PORTA */
#define PHDRIVER_PIN_IRQ    ((GPIO_PORT_C << 8) | 7)   /**< IRQ pin, Pin7, GPIOC, PORTC */
#define PHDRIVER_PIN_BUSY   ((GPIO_PORT_A << 8) | 5)   /**< Busy pin, Pin5, GPIOA, PORTA */
#define PHDRIVER_PIN_DWL    ((GPIO_PORT_A << 8) | 12)  /**< Download pin, Pin12, GPIOA, PORTA */

/******************************************************************
 * PIN Pull-Up/Pull-Down configurations.
 ******************************************************************/
#define PHDRIVER_PIN_RESET_PULL_CFG    PH_DRIVER_PULL_UP
#define PHDRIVER_PIN_IRQ_PULL_CFG      PH_DRIVER_PULL_UP
#define PHDRIVER_PIN_BUSY_PULL_CFG     PH_DRIVER_PULL_UP
#define PHDRIVER_PIN_DWL_PULL_CFG      PH_DRIVER_PULL_UP
#define PHDRIVER_PIN_NSS_PULL_CFG      PH_DRIVER_PULL_UP

/******************************************************************
 * IRQ PIN NVIC settings
 ******************************************************************/
#define EINT_IRQn                 PORTC_IRQn
#define EINT_PRIORITY             8
#define CLIF_IRQHandler           PORTC_IRQHandler
#define PIN_IRQ_TRIGGER_TYPE      PH_DRIVER_INTERRUPT_RISINGEDGE


/*****************************************************************
 * Front End Reset logic level settings
 ****************************************************************/
#define PH_DRIVER_SET_HIGH            1          /**< Logic High. */
#define PH_DRIVER_SET_LOW             0          /**< Logic Low. */
#define RESET_POWERDOWN_LEVEL PH_DRIVER_SET_LOW
#define RESET_POWERUP_LEVEL   PH_DRIVER_SET_HIGH

/*****************************************************************
 * SPI Configuration
 ****************************************************************/

#define PHDRIVER_KSDK_SPI_POLLING          /* Enable to perform SPI transfer using polling method. */
#define PHDRIVER_KSDK_SPI_MASTER           DSPI0
#define PHDRIVER_KSDK_SPI_DATA_RATE        5000000U
#define PHDRIVER_KSDK_SPI_CLK_SRC          DSPI0_CLK_SRC
#define PHDRIVER_KSDK_SPI_IRQ              SPI0_IRQn


#define DSPI_IRQ_PRIORITY     7


#define ENABLE_PORT_SSP_1     kCLOCK_PortA
#define PORT_SSP_1            PORTA
#define FIRST_PINNUM_SSP      15

#define ENABLE_PORT_SSP_2     kCLOCK_PortA
#define PORT_SSP_2            PORTA
#define SECOND_PINNUM_SSP     16

#define ENABLE_PORT_SSP_3     kCLOCK_PortA
#define PORT_SSP_3            PORTA
#define THIRD_PINNUM_SSP      17

#define PHDRIVER_PIN_SSEL     ((GPIO_PORT_A << 8) | 14)  /**< Reset pin, Pin14, GPIOA, PORTA */

/*****************************************************************
 * Timer Configuration
 ****************************************************************/
#define PH_DRIVER_KSDK_PIT_TIMER          PIT
#define PH_DRIVER_KSDK_PIT_CLK            kCLOCK_BusClk
#define PH_DRIVER_KSDK_TIMER_CHANNEL      kPIT_Chnl_0    /**< PIT channel number 0 */
#define PH_DRIVER_KSDK_TIMER_NVIC         PIT0CH0_IRQn

#endif /* BOARD_FRDM_K82FNCx3330_H_ */
