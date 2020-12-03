################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phKeyStore/src/Ncx3320/phKeyStore_Ncx3320.c 

OBJS += \
./NxpNfcRdLib/comps/phKeyStore/src/Ncx3320/phKeyStore_Ncx3320.o 

C_DEPS += \
./NxpNfcRdLib/comps/phKeyStore/src/Ncx3320/phKeyStore_Ncx3320.d 


# Each subdirectory must supply rules for building sources it contributes
NxpNfcRdLib/comps/phKeyStore/src/Ncx3320/phKeyStore_Ncx3320.o: D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phKeyStore/src/Ncx3320/phKeyStore_Ncx3320.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@NxpNfcRdLib/comps/phKeyStore/src/Ncx3320/phKeyStore_Ncx3320.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


