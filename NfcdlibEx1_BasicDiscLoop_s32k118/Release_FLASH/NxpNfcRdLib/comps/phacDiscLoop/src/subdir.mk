################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../NxpNfcRdLib/comps/phacDiscLoop/src/phacDiscLoop.c 

OBJS += \
./NxpNfcRdLib/comps/phacDiscLoop/src/phacDiscLoop.o 

C_DEPS += \
./NxpNfcRdLib/comps/phacDiscLoop/src/phacDiscLoop.d 


# Each subdirectory must supply rules for building sources it contributes
NxpNfcRdLib/comps/phacDiscLoop/src/%.o: ../NxpNfcRdLib/comps/phacDiscLoop/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@NxpNfcRdLib/comps/phacDiscLoop/src/phacDiscLoop.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


