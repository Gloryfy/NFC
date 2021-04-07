################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../NxpNfcRdLib/comps/phalI18000p3m3/src/Sw/phalI18000p3m3_Sw.c \
../NxpNfcRdLib/comps/phalI18000p3m3/src/Sw/phalI18000p3m3_Sw_Int.c 

OBJS += \
./NxpNfcRdLib/comps/phalI18000p3m3/src/Sw/phalI18000p3m3_Sw.o \
./NxpNfcRdLib/comps/phalI18000p3m3/src/Sw/phalI18000p3m3_Sw_Int.o 

C_DEPS += \
./NxpNfcRdLib/comps/phalI18000p3m3/src/Sw/phalI18000p3m3_Sw.d \
./NxpNfcRdLib/comps/phalI18000p3m3/src/Sw/phalI18000p3m3_Sw_Int.d 


# Each subdirectory must supply rules for building sources it contributes
NxpNfcRdLib/comps/phalI18000p3m3/src/Sw/%.o: ../NxpNfcRdLib/comps/phalI18000p3m3/src/Sw/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@NxpNfcRdLib/comps/phalI18000p3m3/src/Sw/phalI18000p3m3_Sw.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


