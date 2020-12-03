################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/NXP/workspaceS32DS.ARM.2.2/S32SDK_S32K116_EAR_1.8.7/platform/devices/S32K116/startup/system_S32K116.c 

OBJS += \
./S32SDK_S32K116_EAR_1.8.7/platform/devices/S32K116/startup/system_S32K116.o 

C_DEPS += \
./S32SDK_S32K116_EAR_1.8.7/platform/devices/S32K116/startup/system_S32K116.d 


# Each subdirectory must supply rules for building sources it contributes
S32SDK_S32K116_EAR_1.8.7/platform/devices/S32K116/startup/system_S32K116.o: D:/NXP/workspaceS32DS.ARM.2.2/S32SDK_S32K116_EAR_1.8.7/platform/devices/S32K116/startup/system_S32K116.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@S32SDK_S32K116_EAR_1.8.7/platform/devices/S32K116/startup/system_S32K116.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


