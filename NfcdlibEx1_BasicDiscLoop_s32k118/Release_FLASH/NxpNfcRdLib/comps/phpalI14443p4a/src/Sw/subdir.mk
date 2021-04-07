################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../NxpNfcRdLib/comps/phpalI14443p4a/src/Sw/phpalI14443p4a_Sw.c 

OBJS += \
./NxpNfcRdLib/comps/phpalI14443p4a/src/Sw/phpalI14443p4a_Sw.o 

C_DEPS += \
./NxpNfcRdLib/comps/phpalI14443p4a/src/Sw/phpalI14443p4a_Sw.d 


# Each subdirectory must supply rules for building sources it contributes
NxpNfcRdLib/comps/phpalI14443p4a/src/Sw/%.o: ../NxpNfcRdLib/comps/phpalI14443p4a/src/Sw/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@NxpNfcRdLib/comps/phpalI14443p4a/src/Sw/phpalI14443p4a_Sw.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


