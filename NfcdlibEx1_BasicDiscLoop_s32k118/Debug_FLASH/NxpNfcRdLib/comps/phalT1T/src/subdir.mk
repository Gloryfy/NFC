################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../NxpNfcRdLib/comps/phalT1T/src/phalT1T.c 

OBJS += \
./NxpNfcRdLib/comps/phalT1T/src/phalT1T.o 

C_DEPS += \
./NxpNfcRdLib/comps/phalT1T/src/phalT1T.d 


# Each subdirectory must supply rules for building sources it contributes
NxpNfcRdLib/comps/phalT1T/src/%.o: ../NxpNfcRdLib/comps/phalT1T/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@NxpNfcRdLib/comps/phalT1T/src/phalT1T.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


