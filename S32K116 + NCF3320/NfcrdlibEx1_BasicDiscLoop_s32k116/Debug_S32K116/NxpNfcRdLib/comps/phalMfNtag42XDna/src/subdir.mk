################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phalMfNtag42XDna/src/phalMfNtag42XDna.c \
D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phalMfNtag42XDna/src/phalMfNtag42XDna_Int.c 

OBJS += \
./NxpNfcRdLib/comps/phalMfNtag42XDna/src/phalMfNtag42XDna.o \
./NxpNfcRdLib/comps/phalMfNtag42XDna/src/phalMfNtag42XDna_Int.o 

C_DEPS += \
./NxpNfcRdLib/comps/phalMfNtag42XDna/src/phalMfNtag42XDna.d \
./NxpNfcRdLib/comps/phalMfNtag42XDna/src/phalMfNtag42XDna_Int.d 


# Each subdirectory must supply rules for building sources it contributes
NxpNfcRdLib/comps/phalMfNtag42XDna/src/phalMfNtag42XDna.o: D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phalMfNtag42XDna/src/phalMfNtag42XDna.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@NxpNfcRdLib/comps/phalMfNtag42XDna/src/phalMfNtag42XDna.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

NxpNfcRdLib/comps/phalMfNtag42XDna/src/phalMfNtag42XDna_Int.o: D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phalMfNtag42XDna/src/phalMfNtag42XDna_Int.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@NxpNfcRdLib/comps/phalMfNtag42XDna/src/phalMfNtag42XDna_Int.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


