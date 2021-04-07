################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../NxpNfcRdLib/comps/phacDiscLoop/src/Sw/phacDiscLoop_Sw.c \
../NxpNfcRdLib/comps/phacDiscLoop/src/Sw/phacDiscLoop_Sw_Int.c \
../NxpNfcRdLib/comps/phacDiscLoop/src/Sw/phacDiscLoop_Sw_Int_A.c \
../NxpNfcRdLib/comps/phacDiscLoop/src/Sw/phacDiscLoop_Sw_Int_B.c \
../NxpNfcRdLib/comps/phacDiscLoop/src/Sw/phacDiscLoop_Sw_Int_F.c \
../NxpNfcRdLib/comps/phacDiscLoop/src/Sw/phacDiscLoop_Sw_Int_I18000p3m3.c \
../NxpNfcRdLib/comps/phacDiscLoop/src/Sw/phacDiscLoop_Sw_Int_V.c 

OBJS += \
./NxpNfcRdLib/comps/phacDiscLoop/src/Sw/phacDiscLoop_Sw.o \
./NxpNfcRdLib/comps/phacDiscLoop/src/Sw/phacDiscLoop_Sw_Int.o \
./NxpNfcRdLib/comps/phacDiscLoop/src/Sw/phacDiscLoop_Sw_Int_A.o \
./NxpNfcRdLib/comps/phacDiscLoop/src/Sw/phacDiscLoop_Sw_Int_B.o \
./NxpNfcRdLib/comps/phacDiscLoop/src/Sw/phacDiscLoop_Sw_Int_F.o \
./NxpNfcRdLib/comps/phacDiscLoop/src/Sw/phacDiscLoop_Sw_Int_I18000p3m3.o \
./NxpNfcRdLib/comps/phacDiscLoop/src/Sw/phacDiscLoop_Sw_Int_V.o 

C_DEPS += \
./NxpNfcRdLib/comps/phacDiscLoop/src/Sw/phacDiscLoop_Sw.d \
./NxpNfcRdLib/comps/phacDiscLoop/src/Sw/phacDiscLoop_Sw_Int.d \
./NxpNfcRdLib/comps/phacDiscLoop/src/Sw/phacDiscLoop_Sw_Int_A.d \
./NxpNfcRdLib/comps/phacDiscLoop/src/Sw/phacDiscLoop_Sw_Int_B.d \
./NxpNfcRdLib/comps/phacDiscLoop/src/Sw/phacDiscLoop_Sw_Int_F.d \
./NxpNfcRdLib/comps/phacDiscLoop/src/Sw/phacDiscLoop_Sw_Int_I18000p3m3.d \
./NxpNfcRdLib/comps/phacDiscLoop/src/Sw/phacDiscLoop_Sw_Int_V.d 


# Each subdirectory must supply rules for building sources it contributes
NxpNfcRdLib/comps/phacDiscLoop/src/Sw/%.o: ../NxpNfcRdLib/comps/phacDiscLoop/src/Sw/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@NxpNfcRdLib/comps/phacDiscLoop/src/Sw/phacDiscLoop_Sw.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


