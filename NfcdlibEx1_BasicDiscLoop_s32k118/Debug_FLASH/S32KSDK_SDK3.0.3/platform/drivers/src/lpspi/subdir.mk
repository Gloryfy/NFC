################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../S32KSDK_SDK3.0.3/platform/drivers/src/lpspi/lpspi_hw_access.c \
../S32KSDK_SDK3.0.3/platform/drivers/src/lpspi/lpspi_irq.c \
../S32KSDK_SDK3.0.3/platform/drivers/src/lpspi/lpspi_master_driver.c \
../S32KSDK_SDK3.0.3/platform/drivers/src/lpspi/lpspi_shared_function.c \
../S32KSDK_SDK3.0.3/platform/drivers/src/lpspi/lpspi_slave_driver.c 

OBJS += \
./S32KSDK_SDK3.0.3/platform/drivers/src/lpspi/lpspi_hw_access.o \
./S32KSDK_SDK3.0.3/platform/drivers/src/lpspi/lpspi_irq.o \
./S32KSDK_SDK3.0.3/platform/drivers/src/lpspi/lpspi_master_driver.o \
./S32KSDK_SDK3.0.3/platform/drivers/src/lpspi/lpspi_shared_function.o \
./S32KSDK_SDK3.0.3/platform/drivers/src/lpspi/lpspi_slave_driver.o 

C_DEPS += \
./S32KSDK_SDK3.0.3/platform/drivers/src/lpspi/lpspi_hw_access.d \
./S32KSDK_SDK3.0.3/platform/drivers/src/lpspi/lpspi_irq.d \
./S32KSDK_SDK3.0.3/platform/drivers/src/lpspi/lpspi_master_driver.d \
./S32KSDK_SDK3.0.3/platform/drivers/src/lpspi/lpspi_shared_function.d \
./S32KSDK_SDK3.0.3/platform/drivers/src/lpspi/lpspi_slave_driver.d 


# Each subdirectory must supply rules for building sources it contributes
S32KSDK_SDK3.0.3/platform/drivers/src/lpspi/%.o: ../S32KSDK_SDK3.0.3/platform/drivers/src/lpspi/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@S32KSDK_SDK3.0.3/platform/drivers/src/lpspi/lpspi_hw_access.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


