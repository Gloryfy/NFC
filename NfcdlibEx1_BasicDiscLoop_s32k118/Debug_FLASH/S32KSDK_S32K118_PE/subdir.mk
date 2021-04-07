################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../S32KSDK_S32K118_PE/Cpu.c \
../S32KSDK_S32K118_PE/canCom0.c \
../S32KSDK_S32K118_PE/clockMan1.c \
../S32KSDK_S32K118_PE/dmaController1.c \
../S32KSDK_S32K118_PE/lpit1.c \
../S32KSDK_S32K118_PE/lpspiCom1.c \
../S32KSDK_S32K118_PE/lpuart0.c \
../S32KSDK_S32K118_PE/pin_mux.c 

OBJS += \
./S32KSDK_S32K118_PE/Cpu.o \
./S32KSDK_S32K118_PE/canCom0.o \
./S32KSDK_S32K118_PE/clockMan1.o \
./S32KSDK_S32K118_PE/dmaController1.o \
./S32KSDK_S32K118_PE/lpit1.o \
./S32KSDK_S32K118_PE/lpspiCom1.o \
./S32KSDK_S32K118_PE/lpuart0.o \
./S32KSDK_S32K118_PE/pin_mux.o 

C_DEPS += \
./S32KSDK_S32K118_PE/Cpu.d \
./S32KSDK_S32K118_PE/canCom0.d \
./S32KSDK_S32K118_PE/clockMan1.d \
./S32KSDK_S32K118_PE/dmaController1.d \
./S32KSDK_S32K118_PE/lpit1.d \
./S32KSDK_S32K118_PE/lpspiCom1.d \
./S32KSDK_S32K118_PE/lpuart0.d \
./S32KSDK_S32K118_PE/pin_mux.d 


# Each subdirectory must supply rules for building sources it contributes
S32KSDK_S32K118_PE/%.o: ../S32KSDK_S32K118_PE/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@S32KSDK_S32K118_PE/Cpu.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


