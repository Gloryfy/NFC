################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../NxpNfcRdLib/comps/phpalFelica/src/phpalFelica.c 

OBJS += \
./NxpNfcRdLib/comps/phpalFelica/src/phpalFelica.o 

C_DEPS += \
./NxpNfcRdLib/comps/phpalFelica/src/phpalFelica.d 


# Each subdirectory must supply rules for building sources it contributes
NxpNfcRdLib/comps/phpalFelica/src/%.o: ../NxpNfcRdLib/comps/phpalFelica/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@NxpNfcRdLib/comps/phpalFelica/src/phpalFelica.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


