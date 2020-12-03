################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phlnLlcp/src/Sw/phlnLlcp_Sw.c \
D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phlnLlcp/src/Sw/phlnLlcp_Sw_Int.c \
D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phlnLlcp/src/Sw/phlnLlcp_Sw_Mac.c \
D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phlnLlcp/src/Sw/phlnLlcp_Sw_Transport.c \
D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phlnLlcp/src/Sw/phlnLlcp_Sw_Transport_Connection.c \
D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phlnLlcp/src/Sw/phlnLlcp_Sw_Transport_Connectionless.c \
D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phlnLlcp/src/Sw/phlnLlcp_Timers.c 

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
NxpNfcRdLib/comps/phlnLlcp/src/Sw/phlnLlcp_Sw.o: D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phlnLlcp/src/Sw/phlnLlcp_Sw.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@NxpNfcRdLib/comps/phlnLlcp/src/Sw/phlnLlcp_Sw.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

NxpNfcRdLib/comps/phlnLlcp/src/Sw/phlnLlcp_Sw_Int.o: D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phlnLlcp/src/Sw/phlnLlcp_Sw_Int.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@NxpNfcRdLib/comps/phlnLlcp/src/Sw/phlnLlcp_Sw_Int.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

NxpNfcRdLib/comps/phlnLlcp/src/Sw/phlnLlcp_Sw_Mac.o: D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phlnLlcp/src/Sw/phlnLlcp_Sw_Mac.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@NxpNfcRdLib/comps/phlnLlcp/src/Sw/phlnLlcp_Sw_Mac.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

NxpNfcRdLib/comps/phlnLlcp/src/Sw/phlnLlcp_Sw_Transport.o: D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phlnLlcp/src/Sw/phlnLlcp_Sw_Transport.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@NxpNfcRdLib/comps/phlnLlcp/src/Sw/phlnLlcp_Sw_Transport.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

NxpNfcRdLib/comps/phlnLlcp/src/Sw/phlnLlcp_Sw_Transport_Connection.o: D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phlnLlcp/src/Sw/phlnLlcp_Sw_Transport_Connection.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@NxpNfcRdLib/comps/phlnLlcp/src/Sw/phlnLlcp_Sw_Transport_Connection.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

NxpNfcRdLib/comps/phlnLlcp/src/Sw/phlnLlcp_Sw_Transport_Connectionless.o: D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phlnLlcp/src/Sw/phlnLlcp_Sw_Transport_Connectionless.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@NxpNfcRdLib/comps/phlnLlcp/src/Sw/phlnLlcp_Sw_Transport_Connectionless.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

NxpNfcRdLib/comps/phlnLlcp/src/Sw/phlnLlcp_Timers.o: D:/NXP/workspaceS32DS.ARM.2.2/NxpNfcRdLib/comps/phlnLlcp/src/Sw/phlnLlcp_Timers.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@NxpNfcRdLib/comps/phlnLlcp/src/Sw/phlnLlcp_Timers.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


