################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phNfcLib/src/phNfcLib.c \
D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phNfcLib/src/phNfcLib_15693.c \
D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phNfcLib/src/phNfcLib_18000p3m3.c \
D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phNfcLib/src/phNfcLib_Initialization.c \
D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phNfcLib/src/phNfcLib_MFC.c \
D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phNfcLib/src/phNfcLib_MFDF.c \
D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phNfcLib/src/phNfcLib_MFUL.c \
D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phNfcLib/src/phNfcLib_Utility.c 

OBJS += \
./NxpNfcRdLib/comps/phNfcLib/src/phNfcLib.o \
./NxpNfcRdLib/comps/phNfcLib/src/phNfcLib_15693.o \
./NxpNfcRdLib/comps/phNfcLib/src/phNfcLib_18000p3m3.o \
./NxpNfcRdLib/comps/phNfcLib/src/phNfcLib_Initialization.o \
./NxpNfcRdLib/comps/phNfcLib/src/phNfcLib_MFC.o \
./NxpNfcRdLib/comps/phNfcLib/src/phNfcLib_MFDF.o \
./NxpNfcRdLib/comps/phNfcLib/src/phNfcLib_MFUL.o \
./NxpNfcRdLib/comps/phNfcLib/src/phNfcLib_Utility.o 

C_DEPS += \
./NxpNfcRdLib/comps/phNfcLib/src/phNfcLib.d \
./NxpNfcRdLib/comps/phNfcLib/src/phNfcLib_15693.d \
./NxpNfcRdLib/comps/phNfcLib/src/phNfcLib_18000p3m3.d \
./NxpNfcRdLib/comps/phNfcLib/src/phNfcLib_Initialization.d \
./NxpNfcRdLib/comps/phNfcLib/src/phNfcLib_MFC.d \
./NxpNfcRdLib/comps/phNfcLib/src/phNfcLib_MFDF.d \
./NxpNfcRdLib/comps/phNfcLib/src/phNfcLib_MFUL.d \
./NxpNfcRdLib/comps/phNfcLib/src/phNfcLib_Utility.d 


# Each subdirectory must supply rules for building sources it contributes
NxpNfcRdLib/comps/phNfcLib/src/phNfcLib.o: D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phNfcLib/src/phNfcLib.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@NxpNfcRdLib/comps/phNfcLib/src/phNfcLib.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

NxpNfcRdLib/comps/phNfcLib/src/phNfcLib_15693.o: D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phNfcLib/src/phNfcLib_15693.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@NxpNfcRdLib/comps/phNfcLib/src/phNfcLib_15693.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

NxpNfcRdLib/comps/phNfcLib/src/phNfcLib_18000p3m3.o: D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phNfcLib/src/phNfcLib_18000p3m3.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@NxpNfcRdLib/comps/phNfcLib/src/phNfcLib_18000p3m3.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

NxpNfcRdLib/comps/phNfcLib/src/phNfcLib_Initialization.o: D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phNfcLib/src/phNfcLib_Initialization.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@NxpNfcRdLib/comps/phNfcLib/src/phNfcLib_Initialization.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

NxpNfcRdLib/comps/phNfcLib/src/phNfcLib_MFC.o: D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phNfcLib/src/phNfcLib_MFC.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@NxpNfcRdLib/comps/phNfcLib/src/phNfcLib_MFC.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

NxpNfcRdLib/comps/phNfcLib/src/phNfcLib_MFDF.o: D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phNfcLib/src/phNfcLib_MFDF.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@NxpNfcRdLib/comps/phNfcLib/src/phNfcLib_MFDF.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

NxpNfcRdLib/comps/phNfcLib/src/phNfcLib_MFUL.o: D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phNfcLib/src/phNfcLib_MFUL.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@NxpNfcRdLib/comps/phNfcLib/src/phNfcLib_MFUL.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

NxpNfcRdLib/comps/phNfcLib/src/phNfcLib_Utility.o: D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phNfcLib/src/phNfcLib_Utility.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@NxpNfcRdLib/comps/phNfcLib/src/phNfcLib_Utility.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


