################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ECUAL/LM35_DRIVER/LM35.c 

OBJS += \
./ECUAL/LM35_DRIVER/LM35.o 

C_DEPS += \
./ECUAL/LM35_DRIVER/LM35.d 


# Each subdirectory must supply rules for building sources it contributes
ECUAL/LM35_DRIVER/%.o: ../ECUAL/LM35_DRIVER/%.c ECUAL/LM35_DRIVER/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


