################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phalMfdfLight/src/Sw/phalMfdfLight_Sw.c \
D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phalMfdfLight/src/Sw/phalMfdfLight_Sw_Int.c 

OBJS += \
./NxpNfcRdLib/comps/phalMfdfLight/src/Sw/phalMfdfLight_Sw.o \
./NxpNfcRdLib/comps/phalMfdfLight/src/Sw/phalMfdfLight_Sw_Int.o 

C_DEPS += \
./NxpNfcRdLib/comps/phalMfdfLight/src/Sw/phalMfdfLight_Sw.d \
./NxpNfcRdLib/comps/phalMfdfLight/src/Sw/phalMfdfLight_Sw_Int.d 


# Each subdirectory must supply rules for building sources it contributes
NxpNfcRdLib/comps/phalMfdfLight/src/Sw/phalMfdfLight_Sw.o: D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phalMfdfLight/src/Sw/phalMfdfLight_Sw.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@NxpNfcRdLib/comps/phalMfdfLight/src/Sw/phalMfdfLight_Sw.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

NxpNfcRdLib/comps/phalMfdfLight/src/Sw/phalMfdfLight_Sw_Int.o: D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phalMfdfLight/src/Sw/phalMfdfLight_Sw_Int.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@NxpNfcRdLib/comps/phalMfdfLight/src/Sw/phalMfdfLight_Sw_Int.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


