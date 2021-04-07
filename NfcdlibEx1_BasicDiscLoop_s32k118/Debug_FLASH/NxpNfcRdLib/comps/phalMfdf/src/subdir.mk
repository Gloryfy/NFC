################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../NxpNfcRdLib/comps/phalMfdf/src/phalMfdf.c \
../NxpNfcRdLib/comps/phalMfdf/src/phalMfdf_Int.c 

OBJS += \
./NxpNfcRdLib/comps/phalMfdf/src/phalMfdf.o \
./NxpNfcRdLib/comps/phalMfdf/src/phalMfdf_Int.o 

C_DEPS += \
./NxpNfcRdLib/comps/phalMfdf/src/phalMfdf.d \
./NxpNfcRdLib/comps/phalMfdf/src/phalMfdf_Int.d 


# Each subdirectory must supply rules for building sources it contributes
NxpNfcRdLib/comps/phalMfdf/src/%.o: ../NxpNfcRdLib/comps/phalMfdf/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@NxpNfcRdLib/comps/phalMfdf/src/phalMfdf.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


