################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../NxpNfcRdLib/comps/phTools/src/phTools.c \
../NxpNfcRdLib/comps/phTools/src/phTools_Q.c 

OBJS += \
./NxpNfcRdLib/comps/phTools/src/phTools.o \
./NxpNfcRdLib/comps/phTools/src/phTools_Q.o 

C_DEPS += \
./NxpNfcRdLib/comps/phTools/src/phTools.d \
./NxpNfcRdLib/comps/phTools/src/phTools_Q.d 


# Each subdirectory must supply rules for building sources it contributes
NxpNfcRdLib/comps/phTools/src/%.o: ../NxpNfcRdLib/comps/phTools/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@NxpNfcRdLib/comps/phTools/src/phTools.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


