################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phhalHw/src/Ncx3320/phhalHw_Ncx3320.c \
D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phhalHw/src/Ncx3320/phhalHw_Ncx3320_Cmd.c \
D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phhalHw/src/Ncx3320/phhalHw_Ncx3320_Int.c \
D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phhalHw/src/Ncx3320/phhalHw_Ncx3320_Wait.c 

OBJS += \
./NxpNfcRdLib/comps/phhalHw/src/Ncx3320/phhalHw_Ncx3320.o \
./NxpNfcRdLib/comps/phhalHw/src/Ncx3320/phhalHw_Ncx3320_Cmd.o \
./NxpNfcRdLib/comps/phhalHw/src/Ncx3320/phhalHw_Ncx3320_Int.o \
./NxpNfcRdLib/comps/phhalHw/src/Ncx3320/phhalHw_Ncx3320_Wait.o 

C_DEPS += \
./NxpNfcRdLib/comps/phhalHw/src/Ncx3320/phhalHw_Ncx3320.d \
./NxpNfcRdLib/comps/phhalHw/src/Ncx3320/phhalHw_Ncx3320_Cmd.d \
./NxpNfcRdLib/comps/phhalHw/src/Ncx3320/phhalHw_Ncx3320_Int.d \
./NxpNfcRdLib/comps/phhalHw/src/Ncx3320/phhalHw_Ncx3320_Wait.d 


# Each subdirectory must supply rules for building sources it contributes
NxpNfcRdLib/comps/phhalHw/src/Ncx3320/phhalHw_Ncx3320.o: D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phhalHw/src/Ncx3320/phhalHw_Ncx3320.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@NxpNfcRdLib/comps/phhalHw/src/Ncx3320/phhalHw_Ncx3320.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

NxpNfcRdLib/comps/phhalHw/src/Ncx3320/phhalHw_Ncx3320_Cmd.o: D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phhalHw/src/Ncx3320/phhalHw_Ncx3320_Cmd.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@NxpNfcRdLib/comps/phhalHw/src/Ncx3320/phhalHw_Ncx3320_Cmd.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

NxpNfcRdLib/comps/phhalHw/src/Ncx3320/phhalHw_Ncx3320_Int.o: D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phhalHw/src/Ncx3320/phhalHw_Ncx3320_Int.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@NxpNfcRdLib/comps/phhalHw/src/Ncx3320/phhalHw_Ncx3320_Int.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

NxpNfcRdLib/comps/phhalHw/src/Ncx3320/phhalHw_Ncx3320_Wait.o: D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phhalHw/src/Ncx3320/phhalHw_Ncx3320_Wait.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@NxpNfcRdLib/comps/phhalHw/src/Ncx3320/phhalHw_Ncx3320_Wait.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


