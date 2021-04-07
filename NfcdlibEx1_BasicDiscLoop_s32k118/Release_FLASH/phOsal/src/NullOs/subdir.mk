################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../phOsal/src/NullOs/phOsal_NullOs.c 

OBJS += \
./phOsal/src/NullOs/phOsal_NullOs.o 

C_DEPS += \
./phOsal/src/NullOs/phOsal_NullOs.d 


# Each subdirectory must supply rules for building sources it contributes
phOsal/src/NullOs/%.o: ../phOsal/src/NullOs/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@phOsal/src/NullOs/phOsal_NullOs.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


