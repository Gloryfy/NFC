################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../S32KSDK_SDK3.0.3/platform/drivers/src/lpit/lpit_driver.c 

OBJS += \
./S32KSDK_SDK3.0.3/platform/drivers/src/lpit/lpit_driver.o 

C_DEPS += \
./S32KSDK_SDK3.0.3/platform/drivers/src/lpit/lpit_driver.d 


# Each subdirectory must supply rules for building sources it contributes
S32KSDK_SDK3.0.3/platform/drivers/src/lpit/%.o: ../S32KSDK_SDK3.0.3/platform/drivers/src/lpit/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@S32KSDK_SDK3.0.3/platform/drivers/src/lpit/lpit_driver.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


