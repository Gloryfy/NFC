################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DAL/src/S32SDK/NFC_config.c \
../DAL/src/S32SDK/phDriver_S32k116SDK.c \
../DAL/src/S32SDK/phbalReg_S32k116Spi.c \
../DAL/src/S32SDK/printf.c 

OBJS += \
./DAL/src/S32SDK/NFC_config.o \
./DAL/src/S32SDK/phDriver_S32k116SDK.o \
./DAL/src/S32SDK/phbalReg_S32k116Spi.o \
./DAL/src/S32SDK/printf.o 

C_DEPS += \
./DAL/src/S32SDK/NFC_config.d \
./DAL/src/S32SDK/phDriver_S32k116SDK.d \
./DAL/src/S32SDK/phbalReg_S32k116Spi.d \
./DAL/src/S32SDK/printf.d 


# Each subdirectory must supply rules for building sources it contributes
DAL/src/S32SDK/%.o: ../DAL/src/S32SDK/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@DAL/src/S32SDK/NFC_config.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


