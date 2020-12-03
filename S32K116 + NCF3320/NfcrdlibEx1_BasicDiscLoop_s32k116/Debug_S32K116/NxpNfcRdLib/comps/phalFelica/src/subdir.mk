################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phalFelica/src/phalFelica.c 

OBJS += \
./NxpNfcRdLib/comps/phalFelica/src/phalFelica.o 

C_DEPS += \
./NxpNfcRdLib/comps/phalFelica/src/phalFelica.d 


# Each subdirectory must supply rules for building sources it contributes
NxpNfcRdLib/comps/phalFelica/src/phalFelica.o: D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phalFelica/src/phalFelica.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@NxpNfcRdLib/comps/phalFelica/src/phalFelica.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


