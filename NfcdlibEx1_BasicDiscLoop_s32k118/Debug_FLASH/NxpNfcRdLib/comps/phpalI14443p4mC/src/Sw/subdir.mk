################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../NxpNfcRdLib/comps/phpalI14443p4mC/src/Sw/phpalI14443p4mC_Sw.c \
../NxpNfcRdLib/comps/phpalI14443p4mC/src/Sw/phpalI14443p4mC_Sw_Int.c 

OBJS += \
./NxpNfcRdLib/comps/phpalI14443p4mC/src/Sw/phpalI14443p4mC_Sw.o \
./NxpNfcRdLib/comps/phpalI14443p4mC/src/Sw/phpalI14443p4mC_Sw_Int.o 

C_DEPS += \
./NxpNfcRdLib/comps/phpalI14443p4mC/src/Sw/phpalI14443p4mC_Sw.d \
./NxpNfcRdLib/comps/phpalI14443p4mC/src/Sw/phpalI14443p4mC_Sw_Int.d 


# Each subdirectory must supply rules for building sources it contributes
NxpNfcRdLib/comps/phpalI14443p4mC/src/Sw/%.o: ../NxpNfcRdLib/comps/phpalI14443p4mC/src/Sw/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@NxpNfcRdLib/comps/phpalI14443p4mC/src/Sw/phpalI14443p4mC_Sw.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


