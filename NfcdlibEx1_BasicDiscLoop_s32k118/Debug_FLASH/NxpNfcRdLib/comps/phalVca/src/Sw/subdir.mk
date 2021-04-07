################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../NxpNfcRdLib/comps/phalVca/src/Sw/phalVca_Sw.c 

OBJS += \
./NxpNfcRdLib/comps/phalVca/src/Sw/phalVca_Sw.o 

C_DEPS += \
./NxpNfcRdLib/comps/phalVca/src/Sw/phalVca_Sw.d 


# Each subdirectory must supply rules for building sources it contributes
NxpNfcRdLib/comps/phalVca/src/Sw/%.o: ../NxpNfcRdLib/comps/phalVca/src/Sw/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@NxpNfcRdLib/comps/phalVca/src/Sw/phalVca_Sw.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


