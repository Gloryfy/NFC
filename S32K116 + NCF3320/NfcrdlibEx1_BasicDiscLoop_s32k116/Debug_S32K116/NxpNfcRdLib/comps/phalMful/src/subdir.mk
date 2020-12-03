################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phalMful/src/phalMful.c \
D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phalMful/src/phalMful_Int.c 

OBJS += \
./NxpNfcRdLib/comps/phalMful/src/phalMful.o \
./NxpNfcRdLib/comps/phalMful/src/phalMful_Int.o 

C_DEPS += \
./NxpNfcRdLib/comps/phalMful/src/phalMful.d \
./NxpNfcRdLib/comps/phalMful/src/phalMful_Int.d 


# Each subdirectory must supply rules for building sources it contributes
NxpNfcRdLib/comps/phalMful/src/phalMful.o: D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phalMful/src/phalMful.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@NxpNfcRdLib/comps/phalMful/src/phalMful.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

NxpNfcRdLib/comps/phalMful/src/phalMful_Int.o: D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phalMful/src/phalMful_Int.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@NxpNfcRdLib/comps/phalMful/src/phalMful_Int.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


