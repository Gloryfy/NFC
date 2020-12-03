/*
 * Copyright (c) 2015 - 2016 , Freescale Semiconductor, Inc.
 * Copyright 2016-2018 NXP
 * All rights reserved.
 *
 * THIS SOFTWARE IS PROVIDED BY NXP "AS IS" AND ANY EXPRESSED OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL NXP OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */
/* ###################################################################
**     Filename    : main.c
**     Project     : flexio_spi_s32k116
**     Processor   : S32K116_48
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2018-01-11, 18:55, # CodeGen: 0
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file main.c
** @version 01.00
** @brief
**         Main module.
**         This module contains user's application code.
*/
/*!
**  @addtogroup main_module main module documentation
**  @{
*/
/* MODULE main */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "clockMan1.h"
#include "pin_mux.h"
#include "dmaController1.h"
#include "flexio_spi1.h"
#include "flexio_spi2.h"
#if CPU_INIT_CONFIG
  #include "Init_Config.h"
#endif

volatile int exit_code = 0;
/* User includes (#include below this line is not maintained by Processor Expert) */

#include <stdint.h>
#include <stdbool.h>

#define LED_PORT  (PTD)
#define LED_RED   (16u)
#define LED_GREEN (15u)

/* Declare transfer size */
#define TRANSFER_SIZE 16u

/* Struct that defines RX and TX buffer arrays */
typedef struct
{
    uint8_t txBuffer[TRANSFER_SIZE];
    uint8_t rxBuffer[TRANSFER_SIZE];
} spi_buffer_t;

/*!
 * @brief Initialize the SPI buffer with different values for TX/RX
 *
 * @param spiBuffer Pointer to the buffer that will be initialized
 * @param master    True if the buffer is used with the master device,
 *                  False if not
 */
void InitSPIBuffer(spi_buffer_t * spiBuffer, bool master)
{
    uint8_t cnt;
    /* Fill the buffers */
    for(cnt = 0U; cnt < TRANSFER_SIZE; cnt++)
    {
        /* If the master flag is set, then the txBuffer will take the value of the counter,
         * else the value will be (TRANSFER_SIZE - Counter).
         * This approach is taken to make the data transfer more visible.
         */
        spiBuffer->txBuffer[cnt] = ((master == true) ? (cnt) : (TRANSFER_SIZE - cnt));
        spiBuffer->rxBuffer[cnt] = 0U;
    }
}

/*!
  \brief The main function for the project.
  \details The startup initialization sequence is the following:
 * - __start (startup asm routine)
 * - __init_hardware()
 * - main()
 *   - PE_low_level_init()
 *     - Common_Init()
 *     - Peripherals_Init()
*/
int main(void)
{

    /* Allocate the memory necessary for the FlexIO state structures */
    flexio_device_state_t flexIODeviceState;
    flexio_spi_master_state_t flexIOSPIState_Master, flexIOSPIState_Slave;
    /* Declare the master and slave buffers */
    spi_buffer_t masterBuffer, slaveBuffer;
    volatile bool isTransferOk = true;
    uint8_t cnt;

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  #ifdef PEX_RTOS_INIT
    PEX_RTOS_INIT();                 /* Initialization of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of Processor Expert internal initialization.                    ***/

    /* Initialize and configure clocks
     *  -   Setup system clocks, dividers
     *  -   Configure FlexIO clock, Port clocks
     *  -   see clock manager component for more details
     */
    CLOCK_SYS_Init(g_clockManConfigsArr, CLOCK_MANAGER_CONFIG_CNT,
                        g_clockManCallbacksArr, CLOCK_MANAGER_CALLBACK_CNT);
    CLOCK_SYS_UpdateConfiguration(0U, CLOCK_MANAGER_POLICY_AGREEMENT);

    /* Initialize pins
     *  -   Init FlexIO pins
     *  -   See PinSettings component for more info
     */
    PINS_DRV_Init(NUM_OF_CONFIGURED_PINS, g_pin_mux_InitConfigArr);

    /* Init FlexIO device */
    FLEXIO_DRV_InitDevice(INST_FLEXIO_SPI1, &flexIODeviceState);
    /* Call the init function for FlexIO SPI driver */
    FLEXIO_SPI_DRV_MasterInit(INST_FLEXIO_SPI1, &flexio_spi1_MasterConfig0, &flexIOSPIState_Master);
    /* Initialize Slave instance of the FlexIO SPI driver */
    FLEXIO_SPI_DRV_SlaveInit(INST_FLEXIO_SPI2, &flexio_spi2_SlaveConfig0, &flexIOSPIState_Slave);

    /* Red off */
    PINS_DRV_WritePin(LED_PORT, LED_RED, 0u);
    /* Green off */
    PINS_DRV_WritePin(LED_PORT, LED_GREEN, 0u);

    /* Initialize master and slave buffers */
    InitSPIBuffer(&masterBuffer, true);
    InitSPIBuffer(&slaveBuffer,  false);

    /* Signal to the Slave FlexIO SPI driver to start listening. Set the buffers and transfer size */
    FLEXIO_SPI_DRV_SlaveTransfer(&flexIOSPIState_Slave, slaveBuffer.txBuffer, slaveBuffer.rxBuffer, TRANSFER_SIZE);

    /* Start the transmission of data */
    FLEXIO_SPI_DRV_MasterTransferBlocking(&flexIOSPIState_Master,
                                          masterBuffer.txBuffer,
                                          masterBuffer.rxBuffer,
                                          TRANSFER_SIZE,
                                          1000UL);

    /* Check if transfer is completed with no errors */
    for (cnt = 0U; cnt < TRANSFER_SIZE; cnt++)
    {
        /* If the values are not equal, break the loop and set isTransferOk to false */
        if((masterBuffer.txBuffer[cnt] != slaveBuffer.rxBuffer[cnt]) || (masterBuffer.rxBuffer[cnt] != slaveBuffer.txBuffer[cnt]))
        {
            isTransferOk = false;
            break;
        }
    }

    /* Turn on Red or Green LED depending on the check result */
    PINS_DRV_WritePin(LED_PORT, LED_RED, (1u-(uint8_t)isTransferOk));
    PINS_DRV_WritePin(LED_PORT, LED_GREEN, (uint8_t)isTransferOk);

  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;) {
    if(exit_code != 0) {
      break;
    }
  }
  return exit_code;
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END main */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.1 [05.21]
**     for the Freescale S32K series of microcontrollers.
**
** ###################################################################
*/
