################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/ICU_DRIVER/subdir.mk
-include MCAL/GPIO_DRIVER/subdir.mk
-include MCAL/EXT_INTERRUPT_DRIVER/subdir.mk
-include MCAL/ADC_DRIVER/subdir.mk
-include ECUAL/SEVEN-SEGMENT_DRIVER/subdir.mk
-include ECUAL/LM35_DRIVER/subdir.mk
-include ECUAL/LED_DRIVER/subdir.mk
-include ECUAL/LCD_DRIVER/subdir.mk
-include ECUAL/KEYPAD_DRIVER/subdir.mk
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


BUILD_ARTIFACT_NAME := INT_EX1_HOSA
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
INT_EX1_HOSA.lss \

FLASH_IMAGE += \
INT_EX1_HOSA.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: main-build

# Main-build Target
main-build: INT_EX1_HOSA.elf secondary-outputs

# Tool invocations
INT_EX1_HOSA.elf: $(OBJS) $(USER_OBJS) makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,INT_EX1_HOSA.map -mmcu=atmega16 -o "INT_EX1_HOSA.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

INT_EX1_HOSA.lss: INT_EX1_HOSA.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S INT_EX1_HOSA.elf  >"INT_EX1_HOSA.lss"
	@echo 'Finished building: $@'
	@echo ' '

INT_EX1_HOSA.hex: INT_EX1_HOSA.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex INT_EX1_HOSA.elf  "INT_EX1_HOSA.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: INT_EX1_HOSA.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 INT_EX1_HOSA.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) INT_EX1_HOSA.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents main-build

-include ../makefile.targets
