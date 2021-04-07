################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../phOsal/src/NullOs/portable/phOsal_Port_CM0plus.c 

OBJS += \
./phOsal/src/NullOs/portable/phOsal_Port_CM0plus.o 

C_DEPS += \
./phOsal/src/NullOs/portable/phOsal_Port_CM0plus.d 


# Each subdirectory must supply rules for building sources it contributes
phOsal/src/NullOs/portable/%.o: ../phOsal/src/NullOs/portable/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@phOsal/src/NullOs/portable/phOsal_Port_CM0plus.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


