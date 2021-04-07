################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../NxpNfcRdLib/comps/phlnLlcp/src/Sw/phlnLlcp_Sw.c \
../NxpNfcRdLib/comps/phlnLlcp/src/Sw/phlnLlcp_Sw_Int.c \
../NxpNfcRdLib/comps/phlnLlcp/src/Sw/phlnLlcp_Sw_Mac.c \
../NxpNfcRdLib/comps/phlnLlcp/src/Sw/phlnLlcp_Sw_Transport.c \
../NxpNfcRdLib/comps/phlnLlcp/src/Sw/phlnLlcp_Sw_Transport_Connection.c \
../NxpNfcRdLib/comps/phlnLlcp/src/Sw/phlnLlcp_Sw_Transport_Connectionless.c \
../NxpNfcRdLib/comps/phlnLlcp/src/Sw/phlnLlcp_Timers.c 

OBJS += \
./NxpNfcRdLib/comps/phlnLlcp/src/Sw/phlnLlcp_Sw.o \
./NxpNfcRdLib/comps/phlnLlcp/src/Sw/phlnLlcp_Sw_Int.o \
./NxpNfcRdLib/comps/phlnLlcp/src/Sw/phlnLlcp_Sw_Mac.o \
./NxpNfcRdLib/comps/phlnLlcp/src/Sw/phlnLlcp_Sw_Transport.o \
./NxpNfcRdLib/comps/phlnLlcp/src/Sw/phlnLlcp_Sw_Transport_Connection.o \
./NxpNfcRdLib/comps/phlnLlcp/src/Sw/phlnLlcp_Sw_Transport_Connectionless.o \
./NxpNfcRdLib/comps/phlnLlcp/src/Sw/phlnLlcp_Timers.o 

C_DEPS += \
./NxpNfcRdLib/comps/phlnLlcp/src/Sw/phlnLlcp_Sw.d \
./NxpNfcRdLib/comps/phlnLlcp/src/Sw/phlnLlcp_Sw_Int.d \
./NxpNfcRdLib/comps/phlnLlcp/src/Sw/phlnLlcp_Sw_Mac.d \
./NxpNfcRdLib/comps/phlnLlcp/src/Sw/phlnLlcp_Sw_Transport.d \
./NxpNfcRdLib/comps/phlnLlcp/src/Sw/phlnLlcp_Sw_Transport_Connection.d \
./NxpNfcRdLib/comps/phlnLlcp/src/Sw/phlnLlcp_Sw_Transport_Connectionless.d \
./NxpNfcRdLib/comps/phlnLlcp/src/Sw/phlnLlcp_Timers.d 


# Each subdirectory must supply rules for building sources it contributes
NxpNfcRdLib/comps/phlnLlcp/src/Sw/%.o: ../NxpNfcRdLib/comps/phlnLlcp/src/Sw/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@NxpNfcRdLib/comps/phlnLlcp/src/Sw/phlnLlcp_Sw.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


