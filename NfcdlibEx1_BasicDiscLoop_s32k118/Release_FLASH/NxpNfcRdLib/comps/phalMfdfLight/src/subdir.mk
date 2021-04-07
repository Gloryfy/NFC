################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../NxpNfcRdLib/comps/phalMfdfLight/src/phalMfdfLight.c \
../NxpNfcRdLib/comps/phalMfdfLight/src/phalMfdfLight_Int.c 

OBJS += \
./NxpNfcRdLib/comps/phalMfdfLight/src/phalMfdfLight.o \
./NxpNfcRdLib/comps/phalMfdfLight/src/phalMfdfLight_Int.o 

C_DEPS += \
./NxpNfcRdLib/comps/phalMfdfLight/src/phalMfdfLight.d \
./NxpNfcRdLib/comps/phalMfdfLight/src/phalMfdfLight_Int.d 


# Each subdirectory must supply rules for building sources it contributes
NxpNfcRdLib/comps/phalMfdfLight/src/%.o: ../NxpNfcRdLib/comps/phalMfdfLight/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@NxpNfcRdLib/comps/phalMfdfLight/src/phalMfdfLight.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


