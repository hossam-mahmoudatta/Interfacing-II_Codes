################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/USART_DRIVER/subdir.mk
-include MCAL/TIMER_DRIVER/subdir.mk
-include MCAL/SPI_DRIVER/subdir.mk
-include MCAL/ICU_DRIVER/subdir.mk
-include MCAL/I2C_DRIVER/subdir.mk
-include MCAL/GPIO_DRIVER/subdir.mk
-include MCAL/EXT_INTERRUPT_DRIVER/subdir.mk
-include MCAL/ADC_DRIVER/subdir.mk
-include ECUAL/SEVEN-SEGMENT_DRIVER/subdir.mk
-include ECUAL/MOTOR_DRIVER/subdir.mk
-include ECUAL/LM35_DRIVER/subdir.mk
-include ECUAL/LED_DRIVER/subdir.mk
-include ECUAL/LCD_DRIVER/subdir.mk
-include ECUAL/KEYPAD_DRIVER/subdir.mk
-include ECUAL/EEPROM_DRIVER/subdir.mk
-include ECUAL/BUZZER_DRIVER/subdir.mk
-include ECUAL/BUTTON_DRIVER/subdir.mk
-include APP/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := DOOR-LOCK-PROJECT_CTRL-ECU_HOSA
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
DOOR-LOCK-PROJECT_CTRL-ECU_HOSA.lss \

SIZEDUMMY += \
sizedummy \


# All Target
all: main-build

# Main-build Target
main-build: DOOR-LOCK-PROJECT_CTRL-ECU_HOSA.elf secondary-outputs

# Tool invocations
DOOR-LOCK-PROJECT_CTRL-ECU_HOSA.elf: $(OBJS) $(USER_OBJS) makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,DOOR-LOCK-PROJECT_CTRL-ECU_HOSA.map -mmcu=atmega32 -o "DOOR-LOCK-PROJECT_CTRL-ECU_HOSA.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

DOOR-LOCK-PROJECT_CTRL-ECU_HOSA.lss: DOOR-LOCK-PROJECT_CTRL-ECU_HOSA.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S DOOR-LOCK-PROJECT_CTRL-ECU_HOSA.elf  >"DOOR-LOCK-PROJECT_CTRL-ECU_HOSA.lss"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: DOOR-LOCK-PROJECT_CTRL-ECU_HOSA.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 DOOR-LOCK-PROJECT_CTRL-ECU_HOSA.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) DOOR-LOCK-PROJECT_CTRL-ECU_HOSA.elf
	-@echo ' '

secondary-outputs: $(LSS) $(SIZEDUMMY)

.PHONY: all clean dependents main-build

-include ../makefile.targets
