################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../NxpNfcRdLib/comps/phalVca/src/phalVca.c \
../NxpNfcRdLib/comps/phalVca/src/phalVca_Int.c 

OBJS += \
./NxpNfcRdLib/comps/phalVca/src/phalVca.o \
./NxpNfcRdLib/comps/phalVca/src/phalVca_Int.o 

C_DEPS += \
./NxpNfcRdLib/comps/phalVca/src/phalVca.d \
./NxpNfcRdLib/comps/phalVca/src/phalVca_Int.d 


# Each subdirectory must supply rules for building sources it contributes
NxpNfcRdLib/comps/phalVca/src/%.o: ../NxpNfcRdLib/comps/phalVca/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@NxpNfcRdLib/comps/phalVca/src/phalVca.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


