################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include uCOS-III/Source/subdir.mk
-include uCOS-III/Ports/ARM-Cortex-M4/Generic/GNU/subdir.mk
-include uC-LIB/subdir.mk
-include uC-CPU/ARM-Cortex-M4/GNU/subdir.mk
-include uC-CPU/subdir.mk
-include KSDK/platform/system/interrupt/src/subdir.mk
-include KSDK/platform/system/clock/MK64F12/subdir.mk
-include KSDK/platform/system/clock/subdir.mk
-include KSDK/platform/startup/MK64F12/subdir.mk
-include KSDK/platform/osa/src/subdir.mk
-include KSDK/platform/hal/uart/subdir.mk
-include KSDK/platform/hal/sim/MK64F12/subdir.mk
-include KSDK/platform/hal/sim/subdir.mk
-include KSDK/platform/hal/port/subdir.mk
-include KSDK/platform/hal/mcg/subdir.mk
-include KSDK/platform/hal/gpio/subdir.mk
-include KSDK/platform/drivers/uart/src/subdir.mk
-include KSDK/platform/drivers/uart/common/subdir.mk
-include KSDK/platform/drivers/gpio/src/subdir.mk
-include KSDK/platform/drivers/gpio/common/subdir.mk
-include KSDK/boards/frdmk64f120m/subdir.mk
-include BSP/KSDK/KDS/subdir.mk
-include BSP/KSDK/subdir.mk
-include BSP/subdir.mk
-include APP/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: OS3-KSDK.elf secondary-outputs

# Tool invocations
OS3-KSDK.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Cross ARM C Linker'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g -T "/Users/Robert/Dropbox/POLITO/Model-based SW Design/FRDM K64F/Micrium/Examples/Freescale/FRDM-K64F/OS3-KSDK/KDS/../../BSP/KSDK/KDS/K64FN1Mxxx12_flash.ld" -Xlinker --gc-sections -Wl,-Map,"OS3-KSDK.map" -specs=nano.specs -specs=nosys.specs -o "OS3-KSDK.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(ASM_DEPS)$(S_UPPER_DEPS) OS3-KSDK.elf
	-@echo ' '

secondary-outputs:

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
