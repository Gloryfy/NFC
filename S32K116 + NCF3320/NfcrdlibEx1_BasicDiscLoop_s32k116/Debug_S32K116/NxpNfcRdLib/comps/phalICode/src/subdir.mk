################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phalICode/src/phalICode.c \
D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phalICode/src/phalICode_Int.c 

OBJS += \
./NxpNfcRdLib/comps/phalICode/src/phalICode.o \
./NxpNfcRdLib/comps/phalICode/src/phalICode_Int.o 

C_DEPS += \
./NxpNfcRdLib/comps/phalICode/src/phalICode.d \
./NxpNfcRdLib/comps/phalICode/src/phalICode_Int.d 


# Each subdirectory must supply rules for building sources it contributes
NxpNfcRdLib/comps/phalICode/src/phalICode.o: D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phalICode/src/phalICode.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@NxpNfcRdLib/comps/phalICode/src/phalICode.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

NxpNfcRdLib/comps/phalICode/src/phalICode_Int.o: D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phalICode/src/phalICode_Int.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@NxpNfcRdLib/comps/phalICode/src/phalICode_Int.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


