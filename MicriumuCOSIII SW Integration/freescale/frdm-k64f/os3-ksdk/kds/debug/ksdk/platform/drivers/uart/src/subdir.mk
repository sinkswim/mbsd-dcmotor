################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/Users/Robert/Dropbox/POLITO/Model-based\ SW\ Design/FRDM\ K64F/Micrium/Examples/Freescale/KSDK/platform/drivers/uart/src/fsl_uart_driver.c 

OBJS += \
./KSDK/platform/drivers/uart/src/fsl_uart_driver.o 

C_DEPS += \
./KSDK/platform/drivers/uart/src/fsl_uart_driver.d 


# Each subdirectory must supply rules for building sources it contributes
KSDK/platform/drivers/uart/src/fsl_uart_driver.o: /Users/Robert/Dropbox/POLITO/Model-based\ SW\ Design/FRDM\ K64F/Micrium/Examples/Freescale/KSDK/platform/drivers/uart/src/fsl_uart_driver.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g -DDEBUG -DCPU_MK64FN1M0VMD12 -DKDS -DFSL_RTOS_UCOSIII -I"/Users/Robert/Dropbox/POLITO/Model-based SW Design/FRDM K64F/Micrium/Examples/Freescale/FRDM-K64F/OS3-KSDK/KDS/.." -I"/Users/Robert/Dropbox/POLITO/Model-based SW Design/FRDM K64F/Micrium/Examples/Freescale/FRDM-K64F/OS3-KSDK/KDS/../../BSP" -I"/Users/Robert/Dropbox/POLITO/Model-based SW Design/FRDM K64F/Micrium/Examples/Freescale/FRDM-K64F/OS3-KSDK/KDS/../../BSP/KSDK" -I"/Users/Robert/Dropbox/POLITO/Model-based SW Design/FRDM K64F/Micrium/Examples/Freescale/FRDM-K64F/OS3-KSDK/KDS/../../../KSDK/rtos/uCOSIII/src/uCOS-III/Ports/ARM-Cortex-M4/Generic/GNU" -I"/Users/Robert/Dropbox/POLITO/Model-based SW Design/FRDM K64F/Micrium/Examples/Freescale/FRDM-K64F/OS3-KSDK/KDS/../../../KSDK/rtos/uCOSIII/src/uCOS-III/Source" -I"/Users/Robert/Dropbox/POLITO/Model-based SW Design/FRDM K64F/Micrium/Examples/Freescale/FRDM-K64F/OS3-KSDK/KDS/../../../KSDK/rtos/uCOSIII/src/uC-CPU/ARM-Cortex-M4/GNU" -I"/Users/Robert/Dropbox/POLITO/Model-based SW Design/FRDM K64F/Micrium/Examples/Freescale/FRDM-K64F/OS3-KSDK/KDS/../../../KSDK/rtos/uCOSIII/src/uC-CPU" -I"/Users/Robert/Dropbox/POLITO/Model-based SW Design/FRDM K64F/Micrium/Examples/Freescale/FRDM-K64F/OS3-KSDK/KDS/../../../KSDK/rtos/uCOSIII/src/uC-LIB" -I"/Users/Robert/Dropbox/POLITO/Model-based SW Design/FRDM K64F/Micrium/Examples/Freescale/FRDM-K64F/OS3-KSDK/KDS/../../../KSDK/platform/utilities" -I"/Users/Robert/Dropbox/POLITO/Model-based SW Design/FRDM K64F/Micrium/Examples/Freescale/FRDM-K64F/OS3-KSDK/KDS/../../../KSDK/platform/osa" -I"/Users/Robert/Dropbox/POLITO/Model-based SW Design/FRDM K64F/Micrium/Examples/Freescale/FRDM-K64F/OS3-KSDK/KDS/../../../KSDK/platform/CMSIS/Include" -I"/Users/Robert/Dropbox/POLITO/Model-based SW Design/FRDM K64F/Micrium/Examples/Freescale/FRDM-K64F/OS3-KSDK/KDS/../../../KSDK/platform/CMSIS/Include/device" -I"/Users/Robert/Dropbox/POLITO/Model-based SW Design/FRDM K64F/Micrium/Examples/Freescale/FRDM-K64F/OS3-KSDK/KDS/../../../KSDK/platform/startup/MK64F12" -I"/Users/Robert/Dropbox/POLITO/Model-based SW Design/FRDM K64F/Micrium/Examples/Freescale/FRDM-K64F/OS3-KSDK/KDS/../../../KSDK/platform/hal" -I"/Users/Robert/Dropbox/POLITO/Model-based SW Design/FRDM K64F/Micrium/Examples/Freescale/FRDM-K64F/OS3-KSDK/KDS/../../../KSDK/platform/hal/adc" -I"/Users/Robert/Dropbox/POLITO/Model-based SW Design/FRDM K64F/Micrium/Examples/Freescale/FRDM-K64F/OS3-KSDK/KDS/../../../KSDK/platform/hal/can" -I"/Users/Robert/Dropbox/POLITO/Model-based SW Design/FRDM K64F/Micrium/Examples/Freescale/FRDM-K64F/OS3-KSDK/KDS/../../../KSDK/platform/hal/dac" -I"/Users/Robert/Dropbox/POLITO/Model-based SW Design/FRDM K64F/Micrium/Examples/Freescale/FRDM-K64F/OS3-KSDK/KDS/../../../KSDK/platform/hal/dmamux" -I"/Users/Robert/Dropbox/POLITO/Model-based SW Design/FRDM K64F/Micrium/Examples/Freescale/FRDM-K64F/OS3-KSDK/KDS/../../../KSDK/platform/hal/dspi" -I"/Users/Robert/Dropbox/POLITO/Model-based SW Design/FRDM K64F/Micrium/Examples/Freescale/FRDM-K64F/OS3-KSDK/KDS/../../../KSDK/platform/hal/edma" -I"/Users/Robert/Dropbox/POLITO/Model-based SW Design/FRDM K64F/Micrium/Examples/Freescale/FRDM-K64F/OS3-KSDK/KDS/../../../KSDK/platform/hal/enet" -I"/Users/Robert/Dropbox/POLITO/Model-based SW Design/FRDM K64F/Micrium/Examples/Freescale/FRDM-K64F/OS3-KSDK/KDS/../../../KSDK/platform/hal/flextimer" -I"/Users/Robert/Dropbox/POLITO/Model-based SW Design/FRDM K64F/Micrium/Examples/Freescale/FRDM-K64F/OS3-KSDK/KDS/../../../KSDK/platform/hal/gpio" -I"/Users/Robert/Dropbox/POLITO/Model-based SW Design/FRDM K64F/Micrium/Examples/Freescale/FRDM-K64F/OS3-KSDK/KDS/../../../KSDK/platform/hal/i2c" -I"/Users/Robert/Dropbox/POLITO/Model-based SW Design/FRDM K64F/Micrium/Examples/Freescale/FRDM-K64F/OS3-KSDK/KDS/../../../KSDK/platform/hal/lptmr" -I"/Users/Robert/Dropbox/POLITO/Model-based SW Design/FRDM K64F/Micrium/Examples/Freescale/FRDM-K64F/OS3-KSDK/KDS/../../../KSDK/platform/hal/mcg" -I"/Users/Robert/Dropbox/POLITO/Model-based SW Design/FRDM K64F/Micrium/Examples/Freescale/FRDM-K64F/OS3-KSDK/KDS/../../../KSDK/platform/hal/osc" -I"/Users/Robert/Dropbox/POLITO/Model-based SW Design/FRDM K64F/Micrium/Examples/Freescale/FRDM-K64F/OS3-KSDK/KDS/../../../KSDK/platform/hal/pdb" -I"/Users/Robert/Dropbox/POLITO/Model-based SW Design/FRDM K64F/Micrium/Examples/Freescale/FRDM-K64F/OS3-KSDK/KDS/../../../KSDK/platform/hal/pit" -I"/Users/Robert/Dropbox/POLITO/Model-based SW Design/FRDM K64F/Micrium/Examples/Freescale/FRDM-K64F/OS3-KSDK/KDS/../../../KSDK/platform/hal/pmc" -I"/Users/Robert/Dropbox/POLITO/Model-based SW Design/FRDM K64F/Micrium/Examples/Freescale/FRDM-K64F/OS3-KSDK/KDS/../../../KSDK/platform/hal/port" -I"/Users/Robert/Dropbox/POLITO/Model-based SW Design/FRDM K64F/Micrium/Examples/Freescale/FRDM-K64F/OS3-KSDK/KDS/../../../KSDK/platform/hal/rtc" -I"/Users/Robert/Dropbox/POLITO/Model-based SW Design/FRDM K64F/Micrium/Examples/Freescale/FRDM-K64F/OS3-KSDK/KDS/../../../KSDK/platform/hal/sai" -I"/Users/Robert/Dropbox/POLITO/Model-based SW Design/FRDM K64F/Micrium/Examples/Freescale/FRDM-K64F/OS3-KSDK/KDS/../../../KSDK/platform/hal/sdhc" -I"/Users/Robert/Dropbox/POLITO/Model-based SW Design/FRDM K64F/Micrium/Examples/Freescale/FRDM-K64F/OS3-KSDK/KDS/../../../KSDK/platform/hal/sim" -I"/Users/Robert/Dropbox/POLITO/Model-based SW Design/FRDM K64F/Micrium/Examples/Freescale/FRDM-K64F/OS3-KSDK/KDS/../../../KSDK/platform/hal/smc" -I"/Users/Robert/Dropbox/POLITO/Model-based SW Design/FRDM K64F/Micrium/Examples/Freescale/FRDM-K64F/OS3-KSDK/KDS/../../../KSDK/platform/hal/uart" -I"/Users/Robert/Dropbox/POLITO/Model-based SW Design/FRDM K64F/Micrium/Examples/Freescale/FRDM-K64F/OS3-KSDK/KDS/../../../KSDK/platform/hal/wdog" -I"/Users/Robert/Dropbox/POLITO/Model-based SW Design/FRDM K64F/Micrium/Examples/Freescale/FRDM-K64F/OS3-KSDK/KDS/../../../KSDK/platform/drivers" -I"/Users/Robert/Dropbox/POLITO/Model-based SW Design/FRDM K64F/Micrium/Examples/Freescale/FRDM-K64F/OS3-KSDK/KDS/../../../KSDK/platform/drivers/adc" -I"/Users/Robert/Dropbox/POLITO/Model-based SW Design/FRDM K64F/Micrium/Examples/Freescale/FRDM-K64F/OS3-KSDK/KDS/../../../KSDK/platform/drivers/adc/common" -I"/Users/Robert/Dropbox/POLITO/Model-based SW Design/FRDM K64F/Micrium/Examples/Freescale/FRDM-K64F/OS3-KSDK/KDS/../../../KSDK/platform/drivers/can" -I"/Users/Robert/Dropbox/POLITO/Model-based SW Design/FRDM K64F/Micrium/Examples/Freescale/FRDM-K64F/OS3-KSDK/KDS/../../../KSDK/platform/drivers/can/common" -I"/Users/Robert/Dropbox/POLITO/Model-based SW Design/FRDM K64F/Micrium/Examples/Freescale/FRDM-K64F/OS3-KSDK/KDS/../../../KSDK/platform/drivers/edma" -I"/Users/Robert/Dropbox/POLITO/Model-based SW Design/FRDM K64F/Micrium/Examples/Freescale/FRDM-K64F/OS3-KSDK/KDS/../../../KSDK/platform/drivers/edma/common" -I"/Users/Robert/Dropbox/POLITO/Model-based SW Design/FRDM K64F/Micrium/Examples/Freescale/FRDM-K64F/OS3-KSDK/KDS/../../../KSDK/platform/drivers/dac" -I"/Users/Robert/Dropbox/POLITO/Model-based SW Design/FRDM K64F/Micrium/Examples/Freescale/FRDM-K64F/OS3-KSDK/KDS/../../../KSDK/platform/drivers/dac/common" -I"/Users/Robert/Dropbox/POLITO/Model-based SW Design/FRDM K64F/Micrium/Examples/Freescale/FRDM-K64F/OS3-KSDK/KDS/../../../KSDK/platform/drivers/dspi/dspi_master" -I"/Users/Robert/Dropbox/POLITO/Model-based SW Design/FRDM K64F/Micrium/Examples/Freescale/FRDM-K64F/OS3-KSDK/KDS/../../../KSDK/platform/drivers/dspi/dspi_slave" -I"/Users/Robert/Dropbox/POLITO/Model-based SW Design/FRDM K64F/Micrium/Examples/Freescale/FRDM-K64F/OS3-KSDK/KDS/../../../KSDK/platform/drivers/dspi/common" -I"/Users/Robert/Dropbox/POLITO/Model-based SW Design/FRDM K64F/Micrium/Examples/Freescale/FRDM-K64F/OS3-KSDK/KDS/../../../KSDK/platform/drivers/enet" -I"/Users/Robert/Dropbox/POLITO/Model-based SW Design/FRDM K64F/Micrium/Examples/Freescale/FRDM-K64F/OS3-KSDK/KDS/../../../KSDK/platform/drivers/enet/common" -I"/Users/Robert/Dropbox/POLITO/Model-based SW Design/FRDM K64F/Micrium/Examples/Freescale/FRDM-K64F/OS3-KSDK/KDS/../../../KSDK/platform/drivers/enet/src" -I"/Users/Robert/Dropbox/POLITO/Model-based SW Design/FRDM K64F/Micrium/Examples/Freescale/FRDM-K64F/OS3-KSDK/KDS/../../../KSDK/platform/drivers/flash" -I"/Users/Robert/Dropbox/POLITO/Model-based SW Design/FRDM K64F/Micrium/Examples/Freescale/FRDM-K64F/OS3-KSDK/KDS/../../../KSDK/platform/drivers/flextimer" -I"/Users/Robert/Dropbox/POLITO/Model-based SW Design/FRDM K64F/Micrium/Examples/Freescale/FRDM-K64F/OS3-KSDK/KDS/../../../KSDK/platform/drivers/flextimer/common" -I"/Users/Robert/Dropbox/POLITO/Model-based SW Design/FRDM K64F/Micrium/Examples/Freescale/FRDM-K64F/OS3-KSDK/KDS/../../../KSDK/platform/drivers/gpio" -I"/Users/Robert/Dropbox/POLITO/Model-based SW Design/FRDM K64F/Micrium/Examples/Freescale/FRDM-K64F/OS3-KSDK/KDS/../../../KSDK/platform/drivers/gpio/common" -I"/Users/Robert/Dropbox/POLITO/Model-based SW Design/FRDM K64F/Micrium/Examples/Freescale/FRDM-K64F/OS3-KSDK/KDS/../../../KSDK/platform/drivers/i2c/i2c_master" -I"/Users/Robert/Dropbox/POLITO/Model-based SW Design/FRDM K64F/Micrium/Examples/Freescale/FRDM-K64F/OS3-KSDK/KDS/../../../KSDK/platform/drivers/i2c/i2c_slave" -I"/Users/Robert/Dropbox/POLITO/Model-based SW Design/FRDM K64F/Micrium/Examples/Freescale/FRDM-K64F/OS3-KSDK/KDS/../../../KSDK/platform/drivers/i2c/common" -I"/Users/Robert/Dropbox/POLITO/Model-based SW Design/FRDM K64F/Micrium/Examples/Freescale/FRDM-K64F/OS3-KSDK/KDS/../../../KSDK/platform/drivers/lptmr" -I"/Users/Robert/Dropbox/POLITO/Model-based SW Design/FRDM K64F/Micrium/Examples/Freescale/FRDM-K64F/OS3-KSDK/KDS/../../../KSDK/platform/drivers/lptmr/common" -I"/Users/Robert/Dropbox/POLITO/Model-based SW Design/FRDM K64F/Micrium/Examples/Freescale/FRDM-K64F/OS3-KSDK/KDS/../../../KSDK/platform/drivers/mmcau" -I"/Users/Robert/Dropbox/POLITO/Model-based SW Design/FRDM K64F/Micrium/Examples/Freescale/FRDM-K64F/OS3-KSDK/KDS/../../../KSDK/platform/drivers/pdb" -I"/Users/Robert/Dropbox/POLITO/Model-based SW Design/FRDM K64F/Micrium/Examples/Freescale/FRDM-K64F/OS3-KSDK/KDS/../../../KSDK/platform/drivers/pdb/common" -I"/Users/Robert/Dropbox/POLITO/Model-based SW Design/FRDM K64F/Micrium/Examples/Freescale/FRDM-K64F/OS3-KSDK/KDS/../../../KSDK/platform/drivers/pit" -I"/Users/Robert/Dropbox/POLITO/Model-based SW Design/FRDM K64F/Micrium/Examples/Freescale/FRDM-K64F/OS3-KSDK/KDS/../../../KSDK/platform/drivers/pit/common" -I"/Users/Robert/Dropbox/POLITO/Model-based SW Design/FRDM K64F/Micrium/Examples/Freescale/FRDM-K64F/OS3-KSDK/KDS/../../../KSDK/platform/drivers/rtc" -I"/Users/Robert/Dropbox/POLITO/Model-based SW Design/FRDM K64F/Micrium/Examples/Freescale/FRDM-K64F/OS3-KSDK/KDS/../../../KSDK/platform/drivers/rtc/common" -I"/Users/Robert/Dropbox/POLITO/Model-based SW Design/FRDM K64F/Micrium/Examples/Freescale/FRDM-K64F/OS3-KSDK/KDS/../../../KSDK/platform/drivers/sai" -I"/Users/Robert/Dropbox/POLITO/Model-based SW Design/FRDM K64F/Micrium/Examples/Freescale/FRDM-K64F/OS3-KSDK/KDS/../../../KSDK/platform/drivers/sai/common" -I"/Users/Robert/Dropbox/POLITO/Model-based SW Design/FRDM K64F/Micrium/Examples/Freescale/FRDM-K64F/OS3-KSDK/KDS/../../../KSDK/platform/drivers/sdhc" -I"/Users/Robert/Dropbox/POLITO/Model-based SW Design/FRDM K64F/Micrium/Examples/Freescale/FRDM-K64F/OS3-KSDK/KDS/../../../KSDK/platform/drivers/sdhc/common" -I"/Users/Robert/Dropbox/POLITO/Model-based SW Design/FRDM K64F/Micrium/Examples/Freescale/FRDM-K64F/OS3-KSDK/KDS/../../../KSDK/platform/drivers/sdcard" -I"/Users/Robert/Dropbox/POLITO/Model-based SW Design/FRDM K64F/Micrium/Examples/Freescale/FRDM-K64F/OS3-KSDK/KDS/../../../KSDK/platform/drivers/soundcard" -I"/Users/Robert/Dropbox/POLITO/Model-based SW Design/FRDM K64F/Micrium/Examples/Freescale/FRDM-K64F/OS3-KSDK/KDS/../../../KSDK/platform/drivers/uart" -I"/Users/Robert/Dropbox/POLITO/Model-based SW Design/FRDM K64F/Micrium/Examples/Freescale/FRDM-K64F/OS3-KSDK/KDS/../../../KSDK/platform/drivers/uart/common" -I"/Users/Robert/Dropbox/POLITO/Model-based SW Design/FRDM K64F/Micrium/Examples/Freescale/FRDM-K64F/OS3-KSDK/KDS/../../../KSDK/platform/drivers/wdog" -I"/Users/Robert/Dropbox/POLITO/Model-based SW Design/FRDM K64F/Micrium/Examples/Freescale/FRDM-K64F/OS3-KSDK/KDS/../../../KSDK/platform/drivers/wdog/common" -I"/Users/Robert/Dropbox/POLITO/Model-based SW Design/FRDM K64F/Micrium/Examples/Freescale/FRDM-K64F/OS3-KSDK/KDS/../../../KSDK/platform/system/clock" -I"/Users/Robert/Dropbox/POLITO/Model-based SW Design/FRDM K64F/Micrium/Examples/Freescale/FRDM-K64F/OS3-KSDK/KDS/../../../KSDK/platform/system/hwtimer" -I"/Users/Robert/Dropbox/POLITO/Model-based SW Design/FRDM K64F/Micrium/Examples/Freescale/FRDM-K64F/OS3-KSDK/KDS/../../../KSDK/platform/system/interrupt" -I"/Users/Robert/Dropbox/POLITO/Model-based SW Design/FRDM K64F/Micrium/Examples/Freescale/FRDM-K64F/OS3-KSDK/KDS/../../../KSDK/platform/system/power" -I"/Users/Robert/Dropbox/POLITO/Model-based SW Design/FRDM K64F/Micrium/Examples/Freescale/FRDM-K64F/OS3-KSDK/KDS/../../../KSDK/boards/frdmk64f120m" -std=c99 -MMD -MP -MF"KSDK/platform/drivers/uart/src/fsl_uart_driver.d" -MT"KSDK/platform/drivers/uart/src/fsl_uart_driver.d" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


