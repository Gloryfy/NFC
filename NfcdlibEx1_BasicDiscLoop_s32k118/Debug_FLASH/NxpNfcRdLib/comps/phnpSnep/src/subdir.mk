################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../NxpNfcRdLib/comps/phnpSnep/src/phnpSnep.c 

OBJS += \
./NxpNfcRdLib/comps/phnpSnep/src/phnpSnep.o 

C_DEPS += \
./NxpNfcRdLib/comps/phnpSnep/src/phnpSnep.d 


# Each subdirectory must supply rules for building sources it contributes
NxpNfcRdLib/comps/phnpSnep/src/%.o: ../NxpNfcRdLib/comps/phnpSnep/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@NxpNfcRdLib/comps/phnpSnep/src/phnpSnep.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


