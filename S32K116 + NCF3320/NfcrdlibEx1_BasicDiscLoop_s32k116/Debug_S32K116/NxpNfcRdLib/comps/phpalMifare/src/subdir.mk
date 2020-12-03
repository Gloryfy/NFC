################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phpalMifare/src/phpalMifare.c 

OBJS += \
./NxpNfcRdLib/comps/phpalMifare/src/phpalMifare.o 

C_DEPS += \
./NxpNfcRdLib/comps/phpalMifare/src/phpalMifare.d 


# Each subdirectory must supply rules for building sources it contributes
NxpNfcRdLib/comps/phpalMifare/src/phpalMifare.o: D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phpalMifare/src/phpalMifare.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@NxpNfcRdLib/comps/phpalMifare/src/phpalMifare.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


