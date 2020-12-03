################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phpalI14443p4a/src/phpalI14443p4a.c 

OBJS += \
./NxpNfcRdLib/comps/phpalI14443p4a/src/phpalI14443p4a.o 

C_DEPS += \
./NxpNfcRdLib/comps/phpalI14443p4a/src/phpalI14443p4a.d 


# Each subdirectory must supply rules for building sources it contributes
NxpNfcRdLib/comps/phpalI14443p4a/src/phpalI14443p4a.o: D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phpalI14443p4a/src/phpalI14443p4a.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@NxpNfcRdLib/comps/phpalI14443p4a/src/phpalI14443p4a.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


