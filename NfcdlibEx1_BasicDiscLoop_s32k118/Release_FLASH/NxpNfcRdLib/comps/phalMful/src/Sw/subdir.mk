################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../NxpNfcRdLib/comps/phalMful/src/Sw/phalMful_Sw.c 

OBJS += \
./NxpNfcRdLib/comps/phalMful/src/Sw/phalMful_Sw.o 

C_DEPS += \
./NxpNfcRdLib/comps/phalMful/src/Sw/phalMful_Sw.d 


# Each subdirectory must supply rules for building sources it contributes
NxpNfcRdLib/comps/phalMful/src/Sw/%.o: ../NxpNfcRdLib/comps/phalMful/src/Sw/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@NxpNfcRdLib/comps/phalMful/src/Sw/phalMful_Sw.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


