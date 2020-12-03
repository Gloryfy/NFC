################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/NXP/workspaceS32DS.ARM.2.2/S32SDK_S32K116_PE/Cpu.c \
D:/NXP/workspaceS32DS.ARM.2.2/S32SDK_S32K116_PE/clockMan1.c \
D:/NXP/workspaceS32DS.ARM.2.2/S32SDK_S32K116_PE/dmaController1.c \
D:/NXP/workspaceS32DS.ARM.2.2/S32SDK_S32K116_PE/lpit1.c \
D:/NXP/workspaceS32DS.ARM.2.2/S32SDK_S32K116_PE/lpspiCom1.c \
D:/NXP/workspaceS32DS.ARM.2.2/S32SDK_S32K116_PE/pin_mux.c 

OBJS += \
./S32SDK_S32K116_PE/Cpu.o \
./S32SDK_S32K116_PE/clockMan1.o \
./S32SDK_S32K116_PE/dmaController1.o \
./S32SDK_S32K116_PE/lpit1.o \
./S32SDK_S32K116_PE/lpspiCom1.o \
./S32SDK_S32K116_PE/pin_mux.o 

C_DEPS += \
./S32SDK_S32K116_PE/Cpu.d \
./S32SDK_S32K116_PE/clockMan1.d \
./S32SDK_S32K116_PE/dmaController1.d \
./S32SDK_S32K116_PE/lpit1.d \
./S32SDK_S32K116_PE/lpspiCom1.d \
./S32SDK_S32K116_PE/pin_mux.d 


# Each subdirectory must supply rules for building sources it contributes
S32SDK_S32K116_PE/Cpu.o: D:/NXP/workspaceS32DS.ARM.2.2/S32SDK_S32K116_PE/Cpu.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@S32SDK_S32K116_PE/Cpu.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

S32SDK_S32K116_PE/clockMan1.o: D:/NXP/workspaceS32DS.ARM.2.2/S32SDK_S32K116_PE/clockMan1.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@S32SDK_S32K116_PE/clockMan1.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

S32SDK_S32K116_PE/dmaController1.o: D:/NXP/workspaceS32DS.ARM.2.2/S32SDK_S32K116_PE/dmaController1.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@S32SDK_S32K116_PE/dmaController1.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

S32SDK_S32K116_PE/lpit1.o: D:/NXP/workspaceS32DS.ARM.2.2/S32SDK_S32K116_PE/lpit1.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@S32SDK_S32K116_PE/lpit1.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

S32SDK_S32K116_PE/lpspiCom1.o: D:/NXP/workspaceS32DS.ARM.2.2/S32SDK_S32K116_PE/lpspiCom1.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@S32SDK_S32K116_PE/lpspiCom1.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

S32SDK_S32K116_PE/pin_mux.o: D:/NXP/workspaceS32DS.ARM.2.2/S32SDK_S32K116_PE/pin_mux.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@S32SDK_S32K116_PE/pin_mux.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


