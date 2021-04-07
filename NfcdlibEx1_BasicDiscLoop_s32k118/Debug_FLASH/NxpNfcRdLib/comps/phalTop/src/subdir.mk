################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../NxpNfcRdLib/comps/phalTop/src/phalTop.c 

OBJS += \
./NxpNfcRdLib/comps/phalTop/src/phalTop.o 

C_DEPS += \
./NxpNfcRdLib/comps/phalTop/src/phalTop.d 


# Each subdirectory must supply rules for building sources it contributes
NxpNfcRdLib/comps/phalTop/src/%.o: ../NxpNfcRdLib/comps/phalTop/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@NxpNfcRdLib/comps/phalTop/src/phalTop.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


