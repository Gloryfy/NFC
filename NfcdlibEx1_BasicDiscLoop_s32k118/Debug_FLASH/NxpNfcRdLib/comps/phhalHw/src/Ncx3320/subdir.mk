################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../NxpNfcRdLib/comps/phhalHw/src/Ncx3320/phhalHw_Ncx3320.c \
../NxpNfcRdLib/comps/phhalHw/src/Ncx3320/phhalHw_Ncx3320_Cmd.c \
../NxpNfcRdLib/comps/phhalHw/src/Ncx3320/phhalHw_Ncx3320_Int.c \
../NxpNfcRdLib/comps/phhalHw/src/Ncx3320/phhalHw_Ncx3320_Wait.c 

OBJS += \
./NxpNfcRdLib/comps/phhalHw/src/Ncx3320/phhalHw_Ncx3320.o \
./NxpNfcRdLib/comps/phhalHw/src/Ncx3320/phhalHw_Ncx3320_Cmd.o \
./NxpNfcRdLib/comps/phhalHw/src/Ncx3320/phhalHw_Ncx3320_Int.o \
./NxpNfcRdLib/comps/phhalHw/src/Ncx3320/phhalHw_Ncx3320_Wait.o 

C_DEPS += \
./NxpNfcRdLib/comps/phhalHw/src/Ncx3320/phhalHw_Ncx3320.d \
./NxpNfcRdLib/comps/phhalHw/src/Ncx3320/phhalHw_Ncx3320_Cmd.d \
./NxpNfcRdLib/comps/phhalHw/src/Ncx3320/phhalHw_Ncx3320_Int.d \
./NxpNfcRdLib/comps/phhalHw/src/Ncx3320/phhalHw_Ncx3320_Wait.d 


# Each subdirectory must supply rules for building sources it contributes
NxpNfcRdLib/comps/phhalHw/src/Ncx3320/%.o: ../NxpNfcRdLib/comps/phhalHw/src/Ncx3320/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@NxpNfcRdLib/comps/phhalHw/src/Ncx3320/phhalHw_Ncx3320.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


