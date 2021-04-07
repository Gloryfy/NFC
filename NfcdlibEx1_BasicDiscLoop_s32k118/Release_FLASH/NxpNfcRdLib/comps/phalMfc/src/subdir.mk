################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../NxpNfcRdLib/comps/phalMfc/src/phalMfc.c \
../NxpNfcRdLib/comps/phalMfc/src/phalMfc_Int.c 

OBJS += \
./NxpNfcRdLib/comps/phalMfc/src/phalMfc.o \
./NxpNfcRdLib/comps/phalMfc/src/phalMfc_Int.o 

C_DEPS += \
./NxpNfcRdLib/comps/phalMfc/src/phalMfc.d \
./NxpNfcRdLib/comps/phalMfc/src/phalMfc_Int.d 


# Each subdirectory must supply rules for building sources it contributes
NxpNfcRdLib/comps/phalMfc/src/%.o: ../NxpNfcRdLib/comps/phalMfc/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@NxpNfcRdLib/comps/phalMfc/src/phalMfc.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


