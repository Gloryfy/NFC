################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../NxpNfcRdLib/comps/phpalI18092mPI/src/Sw/phpalI18092mPI_Sw.c \
../NxpNfcRdLib/comps/phpalI18092mPI/src/Sw/phpalI18092mPI_Sw_Int.c 

OBJS += \
./NxpNfcRdLib/comps/phpalI18092mPI/src/Sw/phpalI18092mPI_Sw.o \
./NxpNfcRdLib/comps/phpalI18092mPI/src/Sw/phpalI18092mPI_Sw_Int.o 

C_DEPS += \
./NxpNfcRdLib/comps/phpalI18092mPI/src/Sw/phpalI18092mPI_Sw.d \
./NxpNfcRdLib/comps/phpalI18092mPI/src/Sw/phpalI18092mPI_Sw_Int.d 


# Each subdirectory must supply rules for building sources it contributes
NxpNfcRdLib/comps/phpalI18092mPI/src/Sw/%.o: ../NxpNfcRdLib/comps/phpalI18092mPI/src/Sw/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@NxpNfcRdLib/comps/phpalI18092mPI/src/Sw/phpalI18092mPI_Sw.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


