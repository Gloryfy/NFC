################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../NxpNfcRdLib/comps/phalTop/src/Sw/phalTop_Sw.c \
../NxpNfcRdLib/comps/phalTop/src/Sw/phalTop_Sw_Int_MfcTop.c \
../NxpNfcRdLib/comps/phalTop/src/Sw/phalTop_Sw_Int_T1T.c \
../NxpNfcRdLib/comps/phalTop/src/Sw/phalTop_Sw_Int_T2T.c \
../NxpNfcRdLib/comps/phalTop/src/Sw/phalTop_Sw_Int_T3T.c \
../NxpNfcRdLib/comps/phalTop/src/Sw/phalTop_Sw_Int_T4T.c \
../NxpNfcRdLib/comps/phalTop/src/Sw/phalTop_Sw_Int_T5T.c 

OBJS += \
./NxpNfcRdLib/comps/phalTop/src/Sw/phalTop_Sw.o \
./NxpNfcRdLib/comps/phalTop/src/Sw/phalTop_Sw_Int_MfcTop.o \
./NxpNfcRdLib/comps/phalTop/src/Sw/phalTop_Sw_Int_T1T.o \
./NxpNfcRdLib/comps/phalTop/src/Sw/phalTop_Sw_Int_T2T.o \
./NxpNfcRdLib/comps/phalTop/src/Sw/phalTop_Sw_Int_T3T.o \
./NxpNfcRdLib/comps/phalTop/src/Sw/phalTop_Sw_Int_T4T.o \
./NxpNfcRdLib/comps/phalTop/src/Sw/phalTop_Sw_Int_T5T.o 

C_DEPS += \
./NxpNfcRdLib/comps/phalTop/src/Sw/phalTop_Sw.d \
./NxpNfcRdLib/comps/phalTop/src/Sw/phalTop_Sw_Int_MfcTop.d \
./NxpNfcRdLib/comps/phalTop/src/Sw/phalTop_Sw_Int_T1T.d \
./NxpNfcRdLib/comps/phalTop/src/Sw/phalTop_Sw_Int_T2T.d \
./NxpNfcRdLib/comps/phalTop/src/Sw/phalTop_Sw_Int_T3T.d \
./NxpNfcRdLib/comps/phalTop/src/Sw/phalTop_Sw_Int_T4T.d \
./NxpNfcRdLib/comps/phalTop/src/Sw/phalTop_Sw_Int_T5T.d 


# Each subdirectory must supply rules for building sources it contributes
NxpNfcRdLib/comps/phalTop/src/Sw/%.o: ../NxpNfcRdLib/comps/phalTop/src/Sw/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@NxpNfcRdLib/comps/phalTop/src/Sw/phalTop_Sw.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


