################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/NXP/workspaceS32DS.ARM.2.2/DAL/src/S32SDK/phDriver_S32k116SDK.c \
D:/NXP/workspaceS32DS.ARM.2.2/DAL/src/S32SDK/phbalReg_S32k116Spi.c 

OBJS += \
./DAL/src/S32SDK/phDriver_S32k116SDK.o \
./DAL/src/S32SDK/phbalReg_S32k116Spi.o 

C_DEPS += \
./DAL/src/S32SDK/phDriver_S32k116SDK.d \
./DAL/src/S32SDK/phbalReg_S32k116Spi.d 


# Each subdirectory must supply rules for building sources it contributes
DAL/src/S32SDK/phDriver_S32k116SDK.o: D:/NXP/workspaceS32DS.ARM.2.2/DAL/src/S32SDK/phDriver_S32k116SDK.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@DAL/src/S32SDK/phDriver_S32k116SDK.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

DAL/src/S32SDK/phbalReg_S32k116Spi.o: D:/NXP/workspaceS32DS.ARM.2.2/DAL/src/S32SDK/phbalReg_S32k116Spi.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@DAL/src/S32SDK/phbalReg_S32k116Spi.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


