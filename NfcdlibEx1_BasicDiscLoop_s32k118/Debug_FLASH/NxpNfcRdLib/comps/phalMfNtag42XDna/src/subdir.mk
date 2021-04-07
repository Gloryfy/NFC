################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../NxpNfcRdLib/comps/phalMfNtag42XDna/src/phalMfNtag42XDna.c \
../NxpNfcRdLib/comps/phalMfNtag42XDna/src/phalMfNtag42XDna_Int.c 

OBJS += \
./NxpNfcRdLib/comps/phalMfNtag42XDna/src/phalMfNtag42XDna.o \
./NxpNfcRdLib/comps/phalMfNtag42XDna/src/phalMfNtag42XDna_Int.o 

C_DEPS += \
./NxpNfcRdLib/comps/phalMfNtag42XDna/src/phalMfNtag42XDna.d \
./NxpNfcRdLib/comps/phalMfNtag42XDna/src/phalMfNtag42XDna_Int.d 


# Each subdirectory must supply rules for building sources it contributes
NxpNfcRdLib/comps/phalMfNtag42XDna/src/%.o: ../NxpNfcRdLib/comps/phalMfNtag42XDna/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@NxpNfcRdLib/comps/phalMfNtag42XDna/src/phalMfNtag42XDna.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


