################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phhalHw/src/PN7462AU/phhalHw_PN7462AU.c \
D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phhalHw/src/PN7462AU/phhalHw_PN7462AU_Int.c 

OBJS += \
./NxpNfcRdLib/comps/phhalHw/src/PN7462AU/phhalHw_PN7462AU.o \
./NxpNfcRdLib/comps/phhalHw/src/PN7462AU/phhalHw_PN7462AU_Int.o 

C_DEPS += \
./NxpNfcRdLib/comps/phhalHw/src/PN7462AU/phhalHw_PN7462AU.d \
./NxpNfcRdLib/comps/phhalHw/src/PN7462AU/phhalHw_PN7462AU_Int.d 


# Each subdirectory must supply rules for building sources it contributes
NxpNfcRdLib/comps/phhalHw/src/PN7462AU/phhalHw_PN7462AU.o: D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phhalHw/src/PN7462AU/phhalHw_PN7462AU.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@NxpNfcRdLib/comps/phhalHw/src/PN7462AU/phhalHw_PN7462AU.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

NxpNfcRdLib/comps/phhalHw/src/PN7462AU/phhalHw_PN7462AU_Int.o: D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phhalHw/src/PN7462AU/phhalHw_PN7462AU_Int.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@NxpNfcRdLib/comps/phhalHw/src/PN7462AU/phhalHw_PN7462AU_Int.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


