################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../NxpNfcRdLib/comps/phpalI18092mT/src/Sw/phpalI18092mT_Sw.c \
../NxpNfcRdLib/comps/phpalI18092mT/src/Sw/phpalI18092mT_Sw_Int.c 

OBJS += \
./NxpNfcRdLib/comps/phpalI18092mT/src/Sw/phpalI18092mT_Sw.o \
./NxpNfcRdLib/comps/phpalI18092mT/src/Sw/phpalI18092mT_Sw_Int.o 

C_DEPS += \
./NxpNfcRdLib/comps/phpalI18092mT/src/Sw/phpalI18092mT_Sw.d \
./NxpNfcRdLib/comps/phpalI18092mT/src/Sw/phpalI18092mT_Sw_Int.d 


# Each subdirectory must supply rules for building sources it contributes
NxpNfcRdLib/comps/phpalI18092mT/src/Sw/%.o: ../NxpNfcRdLib/comps/phpalI18092mT/src/Sw/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@NxpNfcRdLib/comps/phpalI18092mT/src/Sw/phpalI18092mT_Sw.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


