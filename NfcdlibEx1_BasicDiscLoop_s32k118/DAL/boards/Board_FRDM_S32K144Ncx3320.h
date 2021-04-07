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

#ifndef BOARD_FRDM_S32K144NCx3320_H_
#define BOARD_FRDM_S32K144NCx3320_H_
#include <device_registers.h>

#define PORT_A_BASE        PORTA_BASE  /* PORTA base address */
#define PORT_B_BASE        PORTB_BASE  /* PORTB base address */
#define PORT_C_BASE        PORTC_BASE  /* PORTC base address */
#define PORT_D_BASE        PORTD_BASE  /* PORTD base address */
#define PORT_E_BASE        PORTE_BASE  /* PORTE base address */

#define GPIO_A_BASE        PTA_BASE  /* GPIOA base address */
#define GPIO_B_BASE        PTB_BASE  /* GPIOB base address */
#define GPIO_C_BASE        PTC_BASE  /* GPIOC base address */
#define GPIO_D_BASE        PTD_BASE  /* GPIOD base address */
#define GPIO_E_BASE        PTE_BASE  /* GPIOE base address */

#define PORT_BASE_ADDR        0x40000000u
#define GPIO_BASE_ADDR        0x400FF000u

/******************************************************************
 * Board Pin/Gpio configurations
 ******************************************************************/

#define PHDRIVER_PIN_RESET  (((PORT_B_BASE & 0x000FFFFFu) | (GPIO_B_BASE & 0x00000FFFu)) | (1 << 20))  /**< Reset pin, Pin1, GPIOB, PORTB */
#define PHDRIVER_PIN_IRQ    (((PORT_E_BASE & 0x000FFFFFu) | (GPIO_E_BASE & 0x00000FFFu)) | (9 << 20))   /**< IRQ pin, Pin9, GPIOE, PORTE */
#define PHDRIVER_PIN_LED_GREEN    (((PORT_D_BASE & 0x000FFFFFu) | (GPIO_D_BASE & 0x00000FFFu)) | (16 << 20))   /**< IRQ pin, Pin16, GPIOD, PORTD */
#define PHDRIVER_PIN_LED_RED      (((PORT_D_BASE & 0x000FFFFFu) | (GPIO_D_BASE & 0x00000FFFu)) | (15 << 20))   /**< IRQ pin, Pin15, GPIOD, PORTD */

/******************************************************************
 * PIN Pull-Up/Pull-Down configurations.
 ******************************************************************/
#define PHDRIVER_PIN_RESET_PULL_CFG    PH_DRIVER_PULL_DOWN
#define PHDRIVER_PIN_IRQ_PULL_CFG      PH_DRIVER_PULL_UP
#define PHDRIVER_PIN_NSS_PULL_CFG      PH_DRIVER_PULL_UP

/******************************************************************
 * IRQ PIN NVIC settings
 ******************************************************************/
#define EINT_IRQn                 PORTE_IRQn
#define EINT_PRIORITY             8
#define CLIF_IRQHandler           PORTE_IRQHandler           /* PORTE IRQHandler */
#define PIN_IRQ_TRIGGER_TYPE      PH_DRIVER_INTERRUPT_FALLINGEDGE

/*****************************************************************
 * Front End Reset logic level settings
 ****************************************************************/
#define PH_DRIVER_SET_HIGH            1          /**< Logic High. */
#define PH_DRIVER_SET_LOW             0          /**< Logic Low. */
#define RESET_POWERDOWN_LEVEL         PH_DRIVER_SET_HIGH
#define RESET_POWERUP_LEVEL           PH_DRIVER_SET_LOW


/*****************************************************************
 * SPI Configuration
 ****************************************************************/
#define PHDRIVER_S32K_LPSPI_IRQ       LPSPI0_IRQn
#define LPSPI_IRQ_PRIORITY            7

#define LPSPI_INSTANCE                (0u)
#define LPSPI_BAUD_RATE               5000000U
#define LPSPI_TRANSFER_TYPE           LPSPI_USING_INTERRUPTS
#define LPSPI_PCS_POLARITY            LPSPI_ACTIVE_LOW
#define LPSPI_CLK_SRC                 LPSPI0_CLK

/* LPSPI SCK pin, Pin 0, PORTE,  Mux as ALT2 */
#define PORT_LPSPI_SCK        PORTE
#define PIN_NUM_SCK           0
#define PIN_MUX_ALT_SCK       PORT_MUX_ALT2
/* LPSPI MISO pin, Pin 1, PORTE,  Mux as ALT2 */
#define PORT_LPSPI_MISO       PORTE
#define PIN_NUM_MISO          1
#define PIN_MUX_ALT_MISO      PORT_MUX_ALT2
/* LPSPI MOSI pin, Pin 2, PORTE,  Mux as ALT2 */
#define PORT_LPSPI_MOSI       PORTE
#define PIN_NUM_MOSI          2
#define PIN_MUX_ALT_MOSI      PORT_MUX_ALT2
/* LPSPI PCS pin, Pin 5, PORTB,  Mux as ALT4 */
#define PORT_LPSPI_PCS        PORTB
#define PIN_NUM_PCS           5
#define PIN_MUX_ALT_PCS       PORT_MUX_ALT4

#define PHDRIVER_PIN_SSEL     (((PORT_B_BASE & 0x000FFFFFu) | (GPIO_B_BASE & 0x00000FFFu)) | (5 << 20))  /**< Slave Select pin, Pin 5, GPIOB, PORTB */

/*****************************************************************
 * Timer Configuration
 ****************************************************************/
#define PH_DRIVER_S32K_LPIT_INSTANCE       (0u)    /* LPIT module instance number */
#define PH_DRIVER_S32K_LPIT_CLK            LPIT0_CLK    /* LPIT0 clock source */
#define PH_DRIVER_S32K_LPIT_CHANNEL        (0UL)    /* LPIT channel number 0 */
#define PH_DRIVER_S32K_LPIT_CHANNEL_NVIC   LPIT0_Ch0_IRQn

#endif /* BOARD_FRDM_S32K144NCx3320_H_ */
