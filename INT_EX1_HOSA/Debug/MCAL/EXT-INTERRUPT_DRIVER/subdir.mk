################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/EXT-INTERRUPT_DRIVER/EXT-INTERRUPT.c 

OBJS += \
./MCAL/EXT-INTERRUPT_DRIVER/EXT-INTERRUPT.o 

C_DEPS += \
./MCAL/EXT-INTERRUPT_DRIVER/EXT-INTERRUPT.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/EXT-INTERRUPT_DRIVER/%.o: ../MCAL/EXT-INTERRUPT_DRIVER/%.c MCAL/EXT-INTERRUPT_DRIVER/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


