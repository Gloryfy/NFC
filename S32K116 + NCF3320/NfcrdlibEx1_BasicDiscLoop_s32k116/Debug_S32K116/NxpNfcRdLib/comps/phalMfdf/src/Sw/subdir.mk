################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phalMfdf/src/Sw/phalMfdf_Sw.c \
D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phalMfdf/src/Sw/phalMfdf_Sw_Int.c 

OBJS += \
./NxpNfcRdLib/comps/phalMfdf/src/Sw/phalMfdf_Sw.o \
./NxpNfcRdLib/comps/phalMfdf/src/Sw/phalMfdf_Sw_Int.o 

C_DEPS += \
./NxpNfcRdLib/comps/phalMfdf/src/Sw/phalMfdf_Sw.d \
./NxpNfcRdLib/comps/phalMfdf/src/Sw/phalMfdf_Sw_Int.d 


# Each subdirectory must supply rules for building sources it contributes
NxpNfcRdLib/comps/phalMfdf/src/Sw/phalMfdf_Sw.o: D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phalMfdf/src/Sw/phalMfdf_Sw.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@NxpNfcRdLib/comps/phalMfdf/src/Sw/phalMfdf_Sw.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

NxpNfcRdLib/comps/phalMfdf/src/Sw/phalMfdf_Sw_Int.o: D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phalMfdf/src/Sw/phalMfdf_Sw_Int.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@NxpNfcRdLib/comps/phalMfdf/src/Sw/phalMfdf_Sw_Int.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


