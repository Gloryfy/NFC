################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phCryptoRng/src/phCryptoRng.c 

OBJS += \
./NxpNfcRdLib/comps/phCryptoRng/src/phCryptoRng.o 

C_DEPS += \
./NxpNfcRdLib/comps/phCryptoRng/src/phCryptoRng.d 


# Each subdirectory must supply rules for building sources it contributes
NxpNfcRdLib/comps/phCryptoRng/src/phCryptoRng.o: D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phCryptoRng/src/phCryptoRng.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@NxpNfcRdLib/comps/phCryptoRng/src/phCryptoRng.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


