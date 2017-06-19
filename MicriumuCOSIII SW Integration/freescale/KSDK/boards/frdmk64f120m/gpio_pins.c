/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : gpio_pins.c
**     Project     : frdmk64f120m-pin
**     Processor   : MK64FN1M0VMD12
**     Component   : fsl_gpio
**     Version     : Component 01.106, Driver 01.00, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2014-06-09, 10:08, # CodeGen: 1
**
**     Copyright : 1997 - 2014 Freescale Semiconductor, Inc. 
**     All Rights Reserved.
**     
**     Redistribution and use in source and binary forms, with or without modification,
**     are permitted provided that the following conditions are met:
**     
**     o Redistributions of source code must retain the above copyright notice, this list
**       of conditions and the following disclaimer.
**     
**     o Redistributions in binary form must reproduce the above copyright notice, this
**       list of conditions and the following disclaimer in the documentation and/or
**       other materials provided with the distribution.
**     
**     o Neither the name of Freescale Semiconductor, Inc. nor the names of its
**       contributors may be used to endorse or promote products derived from this
**       software without specific prior written permission.
**     
**     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**     ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**     ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**     
**     http: www.freescale.com
**     mail: support@freescale.com
** ###################################################################*/
/*!
** @file gpio_pins.c
** @version 01.00
*/         
/*!
**  @addtogroup gpio_pins_module gpio_pins module documentation
**  @{
*/         

/* MODULE gpio_pins. */

#include "gpio_pins.h"
#include <stdbool.h>

gpio_input_pin_user_config_t switchPins[] = {
  {
    .pinName = kGpioSW1,
    .config.isPullEnable = true,
    .config.pullSelect = kPortPullUp,
    .config.isPassiveFilterEnabled = false,
	.config.interrupt = kPortIntFallingEdge,
  },
  {
    .pinName = kGpioSW2,
    .config.isPullEnable = true,
    .config.pullSelect = kPortPullUp,
    .config.isPassiveFilterEnabled = false,
    .config.interrupt = kPortIntDisabled
  },
	{															// Define properties of the new input
	      .pinName = kGpioIn,
	      .config.isPullEnable = false,
	      .config.pullSelect = kPortPullDown,
	      .config.isPassiveFilterEnabled = false,
	      .config.interrupt = kPortIntDisabled
	    },
  {
    .pinName = GPIO_PINS_OUT_OF_RANGE,
  }
};
      
const gpio_input_pin_user_config_t accelIntPins[] = {
  {
    .pinName = kGpioAccelINT1,
    .config.isPullEnable = false,
    .config.pullSelect = kPortPullUp,
    .config.isPassiveFilterEnabled = false,
    .config.interrupt = kPortIntDisabled
  },
  {
    .pinName = kGpioAccelINT2,
    .config.isPullEnable = false,
    .config.pullSelect = kPortPullUp,
    .config.isPassiveFilterEnabled = false,
    .config.interrupt = kPortIntDisabled
  },
  {
    .pinName = GPIO_PINS_OUT_OF_RANGE,
  }
};
      
const gpio_input_pin_user_config_t gpioUartDemoRxPin[] = {
  {
    .pinName = kGpioUartDemoRX,
    .config.isPullEnable = false,
    .config.pullSelect = kPortPullUp,
    .config.isPassiveFilterEnabled = false,
    .config.interrupt = kPortIntFallingEdge,
  },
  {
    .pinName = GPIO_PINS_OUT_OF_RANGE,
  }
};

const gpio_input_pin_user_config_t sdhcCdPin[] = {
  {
    .pinName = kGpioSdhc0Cd,
    .config.isPullEnable = true,
    .config.pullSelect = kPortPullDown,
    .config.isPassiveFilterEnabled = false,
    .config.interrupt = kPortIntEitherEdge
  },
  {
    .pinName = GPIO_PINS_OUT_OF_RANGE,
  }
};
      
const gpio_output_pin_user_config_t ledPins[] = {
  {
    .pinName = kGpioLED1,
    .config.outputLogic = 1,
    .config.slewRate = kPortSlowSlewRate,
    .config.isOpenDrainEnabled = false,
    .config.driveStrength = kPortLowDriveStrength,
  },
  {
    .pinName = kGpioLED2,
    .config.outputLogic = 1,
    .config.slewRate = kPortSlowSlewRate,
    .config.isOpenDrainEnabled = false,
    .config.driveStrength = kPortLowDriveStrength,
  },
  {
    .pinName = kGpioLED3,
    .config.outputLogic = 1,
    .config.slewRate = kPortSlowSlewRate,
    .config.isOpenDrainEnabled = false,
    .config.driveStrength = kPortLowDriveStrength,
  },
  {
      .pinName = kGpioOut,
      .config.outputLogic = 1,
      .config.slewRate = kPortSlowSlewRate,
      .config.isOpenDrainEnabled = false,
      .config.driveStrength = kPortLowDriveStrength,
    },
  {
    .pinName = GPIO_PINS_OUT_OF_RANGE,
  }
};
      
const gpio_output_pin_user_config_t spiCsPin[] = {
  {
    .pinName = kGpioSpi0Cs0,
    .config.outputLogic = 1,
    .config.slewRate = kPortSlowSlewRate,
    .config.driveStrength = kPortLowDriveStrength,
  },
  {
    .pinName = kGpioSpi0Cs1,
    .config.outputLogic = 1,
    .config.slewRate = kPortSlowSlewRate,
    .config.driveStrength = kPortLowDriveStrength,
  },
  {
    .pinName = GPIO_PINS_OUT_OF_RANGE,
  }
};

/* END gpio_pins. */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.4 [05.10]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
