################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../NxpNfcRdLib/comps/phpalI14443p4mC/src/phpalI14443p4mC.c 

OBJS += \
./NxpNfcRdLib/comps/phpalI14443p4mC/src/phpalI14443p4mC.o 

C_DEPS += \
./NxpNfcRdLib/comps/phpalI14443p4mC/src/phpalI14443p4mC.d 


# Each subdirectory must supply rules for building sources it contributes
NxpNfcRdLib/comps/phpalI14443p4mC/src/%.o: ../NxpNfcRdLib/comps/phpalI14443p4mC/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@NxpNfcRdLib/comps/phpalI14443p4mC/src/phpalI14443p4mC.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


