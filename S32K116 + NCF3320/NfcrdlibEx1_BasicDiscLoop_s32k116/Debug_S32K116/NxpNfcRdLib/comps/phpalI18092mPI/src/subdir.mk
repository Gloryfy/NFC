################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phpalI18092mPI/src/phpalI18092mPI.c 

OBJS += \
./NxpNfcRdLib/comps/phpalI18092mPI/src/phpalI18092mPI.o 

C_DEPS += \
./NxpNfcRdLib/comps/phpalI18092mPI/src/phpalI18092mPI.d 


# Each subdirectory must supply rules for building sources it contributes
NxpNfcRdLib/comps/phpalI18092mPI/src/phpalI18092mPI.o: D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phpalI18092mPI/src/phpalI18092mPI.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@NxpNfcRdLib/comps/phpalI18092mPI/src/phpalI18092mPI.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


