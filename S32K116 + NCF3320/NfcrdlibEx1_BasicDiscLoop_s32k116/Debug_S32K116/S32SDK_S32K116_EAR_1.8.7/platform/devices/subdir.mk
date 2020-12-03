################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/NXP/workspaceS32DS.ARM.2.2/S32SDK_S32K116_EAR_1.8.7/platform/devices/startup.c 

OBJS += \
./S32SDK_S32K116_EAR_1.8.7/platform/devices/startup.o 

C_DEPS += \
./S32SDK_S32K116_EAR_1.8.7/platform/devices/startup.d 


# Each subdirectory must supply rules for building sources it contributes
S32SDK_S32K116_EAR_1.8.7/platform/devices/startup.o: D:/NXP/workspaceS32DS.ARM.2.2/S32SDK_S32K116_EAR_1.8.7/platform/devices/startup.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@S32SDK_S32K116_EAR_1.8.7/platform/devices/startup.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


