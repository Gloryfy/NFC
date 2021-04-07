################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../NxpNfcRdLib/comps/phCryptoSym/src/phCryptoSym.c 

OBJS += \
./NxpNfcRdLib/comps/phCryptoSym/src/phCryptoSym.o 

C_DEPS += \
./NxpNfcRdLib/comps/phCryptoSym/src/phCryptoSym.d 


# Each subdirectory must supply rules for building sources it contributes
NxpNfcRdLib/comps/phCryptoSym/src/%.o: ../NxpNfcRdLib/comps/phCryptoSym/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@NxpNfcRdLib/comps/phCryptoSym/src/phCryptoSym.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


