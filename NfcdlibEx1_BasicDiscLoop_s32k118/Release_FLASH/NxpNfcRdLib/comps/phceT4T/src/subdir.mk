################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../NxpNfcRdLib/comps/phceT4T/src/phceT4T.c 

OBJS += \
./NxpNfcRdLib/comps/phceT4T/src/phceT4T.o 

C_DEPS += \
./NxpNfcRdLib/comps/phceT4T/src/phceT4T.d 


# Each subdirectory must supply rules for building sources it contributes
NxpNfcRdLib/comps/phceT4T/src/%.o: ../NxpNfcRdLib/comps/phceT4T/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@NxpNfcRdLib/comps/phceT4T/src/phceT4T.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


