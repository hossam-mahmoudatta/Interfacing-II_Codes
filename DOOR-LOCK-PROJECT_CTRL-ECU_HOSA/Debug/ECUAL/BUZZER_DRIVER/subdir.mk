################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ECUAL/BUZZER_DRIVER/BUZZER.c 

OBJS += \
./ECUAL/BUZZER_DRIVER/BUZZER.o 

C_DEPS += \
./ECUAL/BUZZER_DRIVER/BUZZER.d 


# Each subdirectory must supply rules for building sources it contributes
ECUAL/BUZZER_DRIVER/%.o: ../ECUAL/BUZZER_DRIVER/%.c ECUAL/BUZZER_DRIVER/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


