################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../NxpNfcRdLib/comps/phpalEpcUid/src/phpalEpcUid.c 

OBJS += \
./NxpNfcRdLib/comps/phpalEpcUid/src/phpalEpcUid.o 

C_DEPS += \
./NxpNfcRdLib/comps/phpalEpcUid/src/phpalEpcUid.d 


# Each subdirectory must supply rules for building sources it contributes
NxpNfcRdLib/comps/phpalEpcUid/src/%.o: ../NxpNfcRdLib/comps/phpalEpcUid/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@NxpNfcRdLib/comps/phpalEpcUid/src/phpalEpcUid.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


