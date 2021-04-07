################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../NxpNfcRdLib/comps/phCryptoSym/src/Sw/phCryptoSym_Lrp.c \
../NxpNfcRdLib/comps/phCryptoSym/src/Sw/phCryptoSym_Sw.c \
../NxpNfcRdLib/comps/phCryptoSym/src/Sw/phCryptoSym_Sw_Aes.c \
../NxpNfcRdLib/comps/phCryptoSym/src/Sw/phCryptoSym_Sw_Des.c \
../NxpNfcRdLib/comps/phCryptoSym/src/Sw/phCryptoSym_Sw_Int.c 

OBJS += \
./NxpNfcRdLib/comps/phCryptoSym/src/Sw/phCryptoSym_Lrp.o \
./NxpNfcRdLib/comps/phCryptoSym/src/Sw/phCryptoSym_Sw.o \
./NxpNfcRdLib/comps/phCryptoSym/src/Sw/phCryptoSym_Sw_Aes.o \
./NxpNfcRdLib/comps/phCryptoSym/src/Sw/phCryptoSym_Sw_Des.o \
./NxpNfcRdLib/comps/phCryptoSym/src/Sw/phCryptoSym_Sw_Int.o 

C_DEPS += \
./NxpNfcRdLib/comps/phCryptoSym/src/Sw/phCryptoSym_Lrp.d \
./NxpNfcRdLib/comps/phCryptoSym/src/Sw/phCryptoSym_Sw.d \
./NxpNfcRdLib/comps/phCryptoSym/src/Sw/phCryptoSym_Sw_Aes.d \
./NxpNfcRdLib/comps/phCryptoSym/src/Sw/phCryptoSym_Sw_Des.d \
./NxpNfcRdLib/comps/phCryptoSym/src/Sw/phCryptoSym_Sw_Int.d 


# Each subdirectory must supply rules for building sources it contributes
NxpNfcRdLib/comps/phCryptoSym/src/Sw/%.o: ../NxpNfcRdLib/comps/phCryptoSym/src/Sw/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@NxpNfcRdLib/comps/phCryptoSym/src/Sw/phCryptoSym_Lrp.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


