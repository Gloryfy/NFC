################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../S32KSDK_SDK3.0.3/rtos/osif/osif_baremetal.c 

OBJS += \
./S32KSDK_SDK3.0.3/rtos/osif/osif_baremetal.o 

C_DEPS += \
./S32KSDK_SDK3.0.3/rtos/osif/osif_baremetal.d 


# Each subdirectory must supply rules for building sources it contributes
S32KSDK_SDK3.0.3/rtos/osif/%.o: ../S32KSDK_SDK3.0.3/rtos/osif/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@S32KSDK_SDK3.0.3/rtos/osif/osif_baremetal.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


