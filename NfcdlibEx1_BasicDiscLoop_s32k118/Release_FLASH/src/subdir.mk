################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/NfcrdlibEx1_BasicDiscoveryLoop.c \
../src/phApp_Init.c 

OBJS += \
./src/NfcrdlibEx1_BasicDiscoveryLoop.o \
./src/phApp_Init.o 

C_DEPS += \
./src/NfcrdlibEx1_BasicDiscoveryLoop.d \
./src/phApp_Init.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/NfcrdlibEx1_BasicDiscoveryLoop.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


