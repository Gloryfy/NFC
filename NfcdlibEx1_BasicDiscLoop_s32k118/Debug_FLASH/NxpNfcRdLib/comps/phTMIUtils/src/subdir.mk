################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../NxpNfcRdLib/comps/phTMIUtils/src/phTMIUtils.c 

OBJS += \
./NxpNfcRdLib/comps/phTMIUtils/src/phTMIUtils.o 

C_DEPS += \
./NxpNfcRdLib/comps/phTMIUtils/src/phTMIUtils.d 


# Each subdirectory must supply rules for building sources it contributes
NxpNfcRdLib/comps/phTMIUtils/src/%.o: ../NxpNfcRdLib/comps/phTMIUtils/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@NxpNfcRdLib/comps/phTMIUtils/src/phTMIUtils.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


