################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../NxpNfcRdLib/comps/phlnLlcp/src/phlnLlcp.c 

OBJS += \
./NxpNfcRdLib/comps/phlnLlcp/src/phlnLlcp.o 

C_DEPS += \
./NxpNfcRdLib/comps/phlnLlcp/src/phlnLlcp.d 


# Each subdirectory must supply rules for building sources it contributes
NxpNfcRdLib/comps/phlnLlcp/src/%.o: ../NxpNfcRdLib/comps/phlnLlcp/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@NxpNfcRdLib/comps/phlnLlcp/src/phlnLlcp.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


