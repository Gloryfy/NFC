################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../NxpNfcRdLib/comps/phpalI14443p3b/src/Sw/phpalI14443p3b_Sw.c 

OBJS += \
./NxpNfcRdLib/comps/phpalI14443p3b/src/Sw/phpalI14443p3b_Sw.o 

C_DEPS += \
./NxpNfcRdLib/comps/phpalI14443p3b/src/Sw/phpalI14443p3b_Sw.d 


# Each subdirectory must supply rules for building sources it contributes
NxpNfcRdLib/comps/phpalI14443p3b/src/Sw/%.o: ../NxpNfcRdLib/comps/phpalI14443p3b/src/Sw/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@NxpNfcRdLib/comps/phpalI14443p3b/src/Sw/phpalI14443p3b_Sw.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


