################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../NxpNfcRdLib/comps/phalICode/src/phalICode.c \
../NxpNfcRdLib/comps/phalICode/src/phalICode_Int.c 

OBJS += \
./NxpNfcRdLib/comps/phalICode/src/phalICode.o \
./NxpNfcRdLib/comps/phalICode/src/phalICode_Int.o 

C_DEPS += \
./NxpNfcRdLib/comps/phalICode/src/phalICode.d \
./NxpNfcRdLib/comps/phalICode/src/phalICode_Int.d 


# Each subdirectory must supply rules for building sources it contributes
NxpNfcRdLib/comps/phalICode/src/%.o: ../NxpNfcRdLib/comps/phalICode/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@NxpNfcRdLib/comps/phalICode/src/phalICode.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


