################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../NxpNfcRdLib/comps/phalMful/src/phalMful.c \
../NxpNfcRdLib/comps/phalMful/src/phalMful_Int.c 

OBJS += \
./NxpNfcRdLib/comps/phalMful/src/phalMful.o \
./NxpNfcRdLib/comps/phalMful/src/phalMful_Int.o 

C_DEPS += \
./NxpNfcRdLib/comps/phalMful/src/phalMful.d \
./NxpNfcRdLib/comps/phalMful/src/phalMful_Int.d 


# Each subdirectory must supply rules for building sources it contributes
NxpNfcRdLib/comps/phalMful/src/%.o: ../NxpNfcRdLib/comps/phalMful/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@NxpNfcRdLib/comps/phalMful/src/phalMful.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


