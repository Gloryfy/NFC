################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../NxpNfcRdLib/comps/phCryptoRng/src/Sw/phCryptoRng_Sw.c 

OBJS += \
./NxpNfcRdLib/comps/phCryptoRng/src/Sw/phCryptoRng_Sw.o 

C_DEPS += \
./NxpNfcRdLib/comps/phCryptoRng/src/Sw/phCryptoRng_Sw.d 


# Each subdirectory must supply rules for building sources it contributes
NxpNfcRdLib/comps/phCryptoRng/src/Sw/%.o: ../NxpNfcRdLib/comps/phCryptoRng/src/Sw/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@NxpNfcRdLib/comps/phCryptoRng/src/Sw/phCryptoRng_Sw.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


