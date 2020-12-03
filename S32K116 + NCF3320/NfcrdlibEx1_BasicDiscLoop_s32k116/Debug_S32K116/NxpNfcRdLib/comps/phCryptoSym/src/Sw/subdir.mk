################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phCryptoSym/src/Sw/phCryptoSym_Lrp.c \
D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phCryptoSym/src/Sw/phCryptoSym_Sw.c \
D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phCryptoSym/src/Sw/phCryptoSym_Sw_Aes.c \
D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phCryptoSym/src/Sw/phCryptoSym_Sw_Des.c \
D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phCryptoSym/src/Sw/phCryptoSym_Sw_Int.c 

OBJS += \
./NxpNfcRdLib/comps/phCryptoSym/src/Sw/phCryptoSym_Lrp.o \
./NxpNfcRdLib/comps/phCryptoSym/src/Sw/phCryptoSym_Sw.o \
./NxpNfcRdLib/comps/phCryptoSym/src/Sw/phCryptoSym_Sw_Aes.o \
./NxpNfcRdLib/comps/phCryptoSym/src/Sw/phCryptoSym_Sw_Des.o \
./NxpNfcRdLib/comps/phCryptoSym/src/Sw/phCryptoSym_Sw_Int.o 

C_DEPS += \
./NxpNfcRdLib/comps/phCryptoSym/src/Sw/phCryptoSym_Lrp.d \
./NxpNfcRdLib/comps/phCryptoSym/src/Sw/phCryptoSym_Sw.d \
./NxpNfcRdLib/comps/phCryptoSym/src/Sw/phCryptoSym_Sw_Aes.d \
./NxpNfcRdLib/comps/phCryptoSym/src/Sw/phCryptoSym_Sw_Des.d \
./NxpNfcRdLib/comps/phCryptoSym/src/Sw/phCryptoSym_Sw_Int.d 


# Each subdirectory must supply rules for building sources it contributes
NxpNfcRdLib/comps/phCryptoSym/src/Sw/phCryptoSym_Lrp.o: D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phCryptoSym/src/Sw/phCryptoSym_Lrp.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@NxpNfcRdLib/comps/phCryptoSym/src/Sw/phCryptoSym_Lrp.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

NxpNfcRdLib/comps/phCryptoSym/src/Sw/phCryptoSym_Sw.o: D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phCryptoSym/src/Sw/phCryptoSym_Sw.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@NxpNfcRdLib/comps/phCryptoSym/src/Sw/phCryptoSym_Sw.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

NxpNfcRdLib/comps/phCryptoSym/src/Sw/phCryptoSym_Sw_Aes.o: D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phCryptoSym/src/Sw/phCryptoSym_Sw_Aes.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@NxpNfcRdLib/comps/phCryptoSym/src/Sw/phCryptoSym_Sw_Aes.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

NxpNfcRdLib/comps/phCryptoSym/src/Sw/phCryptoSym_Sw_Des.o: D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phCryptoSym/src/Sw/phCryptoSym_Sw_Des.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@NxpNfcRdLib/comps/phCryptoSym/src/Sw/phCryptoSym_Sw_Des.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

NxpNfcRdLib/comps/phCryptoSym/src/Sw/phCryptoSym_Sw_Int.o: D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phCryptoSym/src/Sw/phCryptoSym_Sw_Int.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@NxpNfcRdLib/comps/phCryptoSym/src/Sw/phCryptoSym_Sw_Int.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


