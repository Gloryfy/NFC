################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phpalSli15693/src/phpalSli15693.c 

OBJS += \
./NxpNfcRdLib/comps/phpalSli15693/src/phpalSli15693.o 

C_DEPS += \
./NxpNfcRdLib/comps/phpalSli15693/src/phpalSli15693.d 


# Each subdirectory must supply rules for building sources it contributes
NxpNfcRdLib/comps/phpalSli15693/src/phpalSli15693.o: D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phpalSli15693/src/phpalSli15693.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@NxpNfcRdLib/comps/phpalSli15693/src/phpalSli15693.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


