################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phalMfc/src/Sw/phalMfc_Sw.c 

OBJS += \
./NxpNfcRdLib/comps/phalMfc/src/Sw/phalMfc_Sw.o 

C_DEPS += \
./NxpNfcRdLib/comps/phalMfc/src/Sw/phalMfc_Sw.d 


# Each subdirectory must supply rules for building sources it contributes
NxpNfcRdLib/comps/phalMfc/src/Sw/phalMfc_Sw.o: D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phalMfc/src/Sw/phalMfc_Sw.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@NxpNfcRdLib/comps/phalMfc/src/Sw/phalMfc_Sw.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


