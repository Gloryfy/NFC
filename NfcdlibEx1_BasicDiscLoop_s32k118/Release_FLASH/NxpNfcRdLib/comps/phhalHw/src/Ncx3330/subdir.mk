################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../NxpNfcRdLib/comps/phhalHw/src/Ncx3330/phhalHw_Ncx3330.c \
../NxpNfcRdLib/comps/phhalHw/src/Ncx3330/phhalHw_Ncx3330_Instr.c \
../NxpNfcRdLib/comps/phhalHw/src/Ncx3330/phhalHw_Ncx3330_Int.c \
../NxpNfcRdLib/comps/phhalHw/src/Ncx3330/phhalHw_Ncx3330_Wait.c 

OBJS += \
./NxpNfcRdLib/comps/phhalHw/src/Ncx3330/phhalHw_Ncx3330.o \
./NxpNfcRdLib/comps/phhalHw/src/Ncx3330/phhalHw_Ncx3330_Instr.o \
./NxpNfcRdLib/comps/phhalHw/src/Ncx3330/phhalHw_Ncx3330_Int.o \
./NxpNfcRdLib/comps/phhalHw/src/Ncx3330/phhalHw_Ncx3330_Wait.o 

C_DEPS += \
./NxpNfcRdLib/comps/phhalHw/src/Ncx3330/phhalHw_Ncx3330.d \
./NxpNfcRdLib/comps/phhalHw/src/Ncx3330/phhalHw_Ncx3330_Instr.d \
./NxpNfcRdLib/comps/phhalHw/src/Ncx3330/phhalHw_Ncx3330_Int.d \
./NxpNfcRdLib/comps/phhalHw/src/Ncx3330/phhalHw_Ncx3330_Wait.d 


# Each subdirectory must supply rules for building sources it contributes
NxpNfcRdLib/comps/phhalHw/src/Ncx3330/%.o: ../NxpNfcRdLib/comps/phhalHw/src/Ncx3330/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@NxpNfcRdLib/comps/phhalHw/src/Ncx3330/phhalHw_Ncx3330.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


