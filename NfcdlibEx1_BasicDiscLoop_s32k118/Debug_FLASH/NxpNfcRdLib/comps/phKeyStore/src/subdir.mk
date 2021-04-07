################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../NxpNfcRdLib/comps/phKeyStore/src/phKeyStore.c 

OBJS += \
./NxpNfcRdLib/comps/phKeyStore/src/phKeyStore.o 

C_DEPS += \
./NxpNfcRdLib/comps/phKeyStore/src/phKeyStore.d 


# Each subdirectory must supply rules for building sources it contributes
NxpNfcRdLib/comps/phKeyStore/src/%.o: ../NxpNfcRdLib/comps/phKeyStore/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@NxpNfcRdLib/comps/phKeyStore/src/phKeyStore.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


