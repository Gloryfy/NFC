################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../S32KSDK_SDK3.0.3/platform/devices/S32K118/startup/system_S32K118.c 

OBJS += \
./S32KSDK_SDK3.0.3/platform/devices/S32K118/startup/system_S32K118.o 

C_DEPS += \
./S32KSDK_SDK3.0.3/platform/devices/S32K118/startup/system_S32K118.d 


# Each subdirectory must supply rules for building sources it contributes
S32KSDK_SDK3.0.3/platform/devices/S32K118/startup/%.o: ../S32KSDK_SDK3.0.3/platform/devices/S32K118/startup/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@S32KSDK_SDK3.0.3/platform/devices/S32K118/startup/system_S32K118.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


