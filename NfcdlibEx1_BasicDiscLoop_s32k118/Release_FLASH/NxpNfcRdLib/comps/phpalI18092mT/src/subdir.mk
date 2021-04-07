################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../NxpNfcRdLib/comps/phpalI18092mT/src/phpalI18092mT.c 

OBJS += \
./NxpNfcRdLib/comps/phpalI18092mT/src/phpalI18092mT.o 

C_DEPS += \
./NxpNfcRdLib/comps/phpalI18092mT/src/phpalI18092mT.d 


# Each subdirectory must supply rules for building sources it contributes
NxpNfcRdLib/comps/phpalI18092mT/src/%.o: ../NxpNfcRdLib/comps/phpalI18092mT/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@NxpNfcRdLib/comps/phpalI18092mT/src/phpalI18092mT.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


