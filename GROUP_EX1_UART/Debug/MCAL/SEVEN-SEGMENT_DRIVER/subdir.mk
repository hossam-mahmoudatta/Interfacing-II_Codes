################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/SEVEN-SEGMENT_DRIVER/SEGMENT.c 

OBJS += \
./MCAL/SEVEN-SEGMENT_DRIVER/SEGMENT.o 

C_DEPS += \
./MCAL/SEVEN-SEGMENT_DRIVER/SEGMENT.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/SEVEN-SEGMENT_DRIVER/%.o: ../MCAL/SEVEN-SEGMENT_DRIVER/%.c MCAL/SEVEN-SEGMENT_DRIVER/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


