################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phceT4T/src/phceT4T.c 

OBJS += \
./NxpNfcRdLib/comps/phceT4T/src/phceT4T.o 

C_DEPS += \
./NxpNfcRdLib/comps/phceT4T/src/phceT4T.d 


# Each subdirectory must supply rules for building sources it contributes
NxpNfcRdLib/comps/phceT4T/src/phceT4T.o: D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phceT4T/src/phceT4T.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@NxpNfcRdLib/comps/phceT4T/src/phceT4T.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


