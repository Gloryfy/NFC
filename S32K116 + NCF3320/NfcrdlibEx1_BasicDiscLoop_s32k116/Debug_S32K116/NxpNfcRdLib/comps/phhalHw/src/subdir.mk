################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phhalHw/src/phhalHw.c 

OBJS += \
./NxpNfcRdLib/comps/phhalHw/src/phhalHw.o 

C_DEPS += \
./NxpNfcRdLib/comps/phhalHw/src/phhalHw.d 


# Each subdirectory must supply rules for building sources it contributes
NxpNfcRdLib/comps/phhalHw/src/phhalHw.o: D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phhalHw/src/phhalHw.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@NxpNfcRdLib/comps/phhalHw/src/phhalHw.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


