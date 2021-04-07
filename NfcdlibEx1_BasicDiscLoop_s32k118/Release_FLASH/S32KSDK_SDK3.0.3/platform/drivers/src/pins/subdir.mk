################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../S32KSDK_SDK3.0.3/platform/drivers/src/pins/pins_driver.c \
../S32KSDK_SDK3.0.3/platform/drivers/src/pins/pins_port_hw_access.c 

OBJS += \
./S32KSDK_SDK3.0.3/platform/drivers/src/pins/pins_driver.o \
./S32KSDK_SDK3.0.3/platform/drivers/src/pins/pins_port_hw_access.o 

C_DEPS += \
./S32KSDK_SDK3.0.3/platform/drivers/src/pins/pins_driver.d \
./S32KSDK_SDK3.0.3/platform/drivers/src/pins/pins_port_hw_access.d 


# Each subdirectory must supply rules for building sources it contributes
S32KSDK_SDK3.0.3/platform/drivers/src/pins/%.o: ../S32KSDK_SDK3.0.3/platform/drivers/src/pins/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@S32KSDK_SDK3.0.3/platform/drivers/src/pins/pins_driver.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


