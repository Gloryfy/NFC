################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phTools/src/phTools.c \
D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phTools/src/phTools_Q.c 

OBJS += \
./NxpNfcRdLib/comps/phTools/src/phTools.o \
./NxpNfcRdLib/comps/phTools/src/phTools_Q.o 

C_DEPS += \
./NxpNfcRdLib/comps/phTools/src/phTools.d \
./NxpNfcRdLib/comps/phTools/src/phTools_Q.d 


# Each subdirectory must supply rules for building sources it contributes
NxpNfcRdLib/comps/phTools/src/phTools.o: D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phTools/src/phTools.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@NxpNfcRdLib/comps/phTools/src/phTools.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

NxpNfcRdLib/comps/phTools/src/phTools_Q.o: D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phTools/src/phTools_Q.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@NxpNfcRdLib/comps/phTools/src/phTools_Q.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


