################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phhalHw/src/Ncx3330/phhalHw_Ncx3330.c \
D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phhalHw/src/Ncx3330/phhalHw_Ncx3330_Instr.c \
D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phhalHw/src/Ncx3330/phhalHw_Ncx3330_Int.c \
D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phhalHw/src/Ncx3330/phhalHw_Ncx3330_Wait.c 

OBJS += \
./NxpNfcRdLib/comps/phhalHw/src/Ncx3330/phhalHw_Ncx3330.o \
./NxpNfcRdLib/comps/phhalHw/src/Ncx3330/phhalHw_Ncx3330_Instr.o \
./NxpNfcRdLib/comps/phhalHw/src/Ncx3330/phhalHw_Ncx3330_Int.o \
./NxpNfcRdLib/comps/phhalHw/src/Ncx3330/phhalHw_Ncx3330_Wait.o 

C_DEPS += \
./NxpNfcRdLib/comps/phhalHw/src/Ncx3330/phhalHw_Ncx3330.d \
./NxpNfcRdLib/comps/phhalHw/src/Ncx3330/phhalHw_Ncx3330_Instr.d \
./NxpNfcRdLib/comps/phhalHw/src/Ncx3330/phhalHw_Ncx3330_Int.d \
./NxpNfcRdLib/comps/phhalHw/src/Ncx3330/phhalHw_Ncx3330_Wait.d 


# Each subdirectory must supply rules for building sources it contributes
NxpNfcRdLib/comps/phhalHw/src/Ncx3330/phhalHw_Ncx3330.o: D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phhalHw/src/Ncx3330/phhalHw_Ncx3330.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@NxpNfcRdLib/comps/phhalHw/src/Ncx3330/phhalHw_Ncx3330.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

NxpNfcRdLib/comps/phhalHw/src/Ncx3330/phhalHw_Ncx3330_Instr.o: D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phhalHw/src/Ncx3330/phhalHw_Ncx3330_Instr.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@NxpNfcRdLib/comps/phhalHw/src/Ncx3330/phhalHw_Ncx3330_Instr.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

NxpNfcRdLib/comps/phhalHw/src/Ncx3330/phhalHw_Ncx3330_Int.o: D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phhalHw/src/Ncx3330/phhalHw_Ncx3330_Int.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@NxpNfcRdLib/comps/phhalHw/src/Ncx3330/phhalHw_Ncx3330_Int.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

NxpNfcRdLib/comps/phhalHw/src/Ncx3330/phhalHw_Ncx3330_Wait.o: D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phhalHw/src/Ncx3330/phhalHw_Ncx3330_Wait.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@NxpNfcRdLib/comps/phhalHw/src/Ncx3330/phhalHw_Ncx3330_Wait.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


