################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/GPIO_DRIVER/subdir.mk
-include MCAL/ADC_DRIVER/subdir.mk
-include ECUAL/SEVEN-SEGMENT_DRIVER/subdir.mk
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


BUILD_ARTIFACT_NAME := KEYLCD_EX2_HOSA
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
KEYLCD_EX2_HOSA.lss \

FLASH_IMAGE += \
KEYLCD_EX2_HOSA.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: main-build

# Main-build Target
main-build: KEYLCD_EX2_HOSA.elf secondary-outputs

# Tool invocations
KEYLCD_EX2_HOSA.elf: $(OBJS) $(USER_OBJS) makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,KEYLCD_EX2_HOSA.map -mmcu=atmega16 -o "KEYLCD_EX2_HOSA.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

KEYLCD_EX2_HOSA.lss: KEYLCD_EX2_HOSA.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S KEYLCD_EX2_HOSA.elf  >"KEYLCD_EX2_HOSA.lss"
	@echo 'Finished building: $@'
	@echo ' '

KEYLCD_EX2_HOSA.hex: KEYLCD_EX2_HOSA.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex KEYLCD_EX2_HOSA.elf  "KEYLCD_EX2_HOSA.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: KEYLCD_EX2_HOSA.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 KEYLCD_EX2_HOSA.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) KEYLCD_EX2_HOSA.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents main-build

-include ../makefile.targets
