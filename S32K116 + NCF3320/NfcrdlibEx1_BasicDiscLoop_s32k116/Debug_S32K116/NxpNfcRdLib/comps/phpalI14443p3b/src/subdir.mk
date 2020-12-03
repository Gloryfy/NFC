################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phpalI14443p3b/src/phpalI14443p3b.c 

OBJS += \
./NxpNfcRdLib/comps/phpalI14443p3b/src/phpalI14443p3b.o 

C_DEPS += \
./NxpNfcRdLib/comps/phpalI14443p3b/src/phpalI14443p3b.d 


# Each subdirectory must supply rules for building sources it contributes
NxpNfcRdLib/comps/phpalI14443p3b/src/phpalI14443p3b.o: D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phpalI14443p3b/src/phpalI14443p3b.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@NxpNfcRdLib/comps/phpalI14443p3b/src/phpalI14443p3b.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


