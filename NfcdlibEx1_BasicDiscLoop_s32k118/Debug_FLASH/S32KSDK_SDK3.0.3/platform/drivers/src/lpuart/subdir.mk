################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../S32KSDK_SDK3.0.3/platform/drivers/src/lpuart/lpuart_driver.c \
../S32KSDK_SDK3.0.3/platform/drivers/src/lpuart/lpuart_hw_access.c \
../S32KSDK_SDK3.0.3/platform/drivers/src/lpuart/lpuart_irq.c 

OBJS += \
./S32KSDK_SDK3.0.3/platform/drivers/src/lpuart/lpuart_driver.o \
./S32KSDK_SDK3.0.3/platform/drivers/src/lpuart/lpuart_hw_access.o \
./S32KSDK_SDK3.0.3/platform/drivers/src/lpuart/lpuart_irq.o 

C_DEPS += \
./S32KSDK_SDK3.0.3/platform/drivers/src/lpuart/lpuart_driver.d \
./S32KSDK_SDK3.0.3/platform/drivers/src/lpuart/lpuart_hw_access.d \
./S32KSDK_SDK3.0.3/platform/drivers/src/lpuart/lpuart_irq.d 


# Each subdirectory must supply rules for building sources it contributes
S32KSDK_SDK3.0.3/platform/drivers/src/lpuart/%.o: ../S32KSDK_SDK3.0.3/platform/drivers/src/lpuart/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@S32KSDK_SDK3.0.3/platform/drivers/src/lpuart/lpuart_driver.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


