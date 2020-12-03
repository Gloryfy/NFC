################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phpalI18000p3m3/src/phpalI18000p3m3.c 

OBJS += \
./NxpNfcRdLib/comps/phpalI18000p3m3/src/phpalI18000p3m3.o 

C_DEPS += \
./NxpNfcRdLib/comps/phpalI18000p3m3/src/phpalI18000p3m3.d 


# Each subdirectory must supply rules for building sources it contributes
NxpNfcRdLib/comps/phpalI18000p3m3/src/phpalI18000p3m3.o: D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phpalI18000p3m3/src/phpalI18000p3m3.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@NxpNfcRdLib/comps/phpalI18000p3m3/src/phpalI18000p3m3.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


