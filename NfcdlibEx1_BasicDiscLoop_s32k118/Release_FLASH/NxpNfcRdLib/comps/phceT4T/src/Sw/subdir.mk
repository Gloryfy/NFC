################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../NxpNfcRdLib/comps/phceT4T/src/Sw/phceT4T_Sw.c \
../NxpNfcRdLib/comps/phceT4T/src/Sw/phceT4T_Sw_Int.c 

OBJS += \
./NxpNfcRdLib/comps/phceT4T/src/Sw/phceT4T_Sw.o \
./NxpNfcRdLib/comps/phceT4T/src/Sw/phceT4T_Sw_Int.o 

C_DEPS += \
./NxpNfcRdLib/comps/phceT4T/src/Sw/phceT4T_Sw.d \
./NxpNfcRdLib/comps/phceT4T/src/Sw/phceT4T_Sw_Int.d 


# Each subdirectory must supply rules for building sources it contributes
NxpNfcRdLib/comps/phceT4T/src/Sw/%.o: ../NxpNfcRdLib/comps/phceT4T/src/Sw/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@NxpNfcRdLib/comps/phceT4T/src/Sw/phceT4T_Sw.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


