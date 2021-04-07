################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../NxpNfcRdLib/comps/phLog/src/phLog.c 

OBJS += \
./NxpNfcRdLib/comps/phLog/src/phLog.o 

C_DEPS += \
./NxpNfcRdLib/comps/phLog/src/phLog.d 


# Each subdirectory must supply rules for building sources it contributes
NxpNfcRdLib/comps/phLog/src/%.o: ../NxpNfcRdLib/comps/phLog/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@NxpNfcRdLib/comps/phLog/src/phLog.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


