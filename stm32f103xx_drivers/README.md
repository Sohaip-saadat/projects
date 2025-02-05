# STM32F103xx GPIO Driver

## Description
This project contains the drivers for STM32F103xx microcontroller's GPIO (General Purpose Input/Output) peripheral. The code includes functions for enabling and disabling GPIO clocks, configuring pins for input or output, reading/writing data to GPIO pins, and handling interrupts.

## File Structure
1. **stm32f103xx.h**  
   - Contains the base addresses of the STM32F103xx peripherals, including GPIO, timers, and other peripherals.
   
2. **stn32f103xx_drivers_gpio.h**  
   - Contains the GPIO pin configurations, API declarations for GPIO operations, and configuration settings.
   
3. **stm32f103xx_drivers_gpio.c**  
   - Contains the implementation of GPIO APIs, including functions for clock enabling, initialization, reading/writing data, and toggling pins.

## GPIO Driver Features
- **GPIO Pin Modes**: Input/Output, Alternate Functions, and Push-pull/Open-drain output types.
- **GPIO Speed Settings**: Low, Medium, and High-speed options for output pins.
- **Pull-up/Pull-down Configuration**: Allows configuring internal pull-up and pull-down resistors.
- **Clock Control**: Enable or disable clock to GPIO peripherals.
- **Read/Write**: Read input pins, write to output pins, and toggle output pins.

## Usage

### 1. GPIO Initialization

To initialize a GPIO pin, configure the GPIO pin number, mode, speed, and pull-up/pull-down configuration in the `GPIO_PinConfig_t` structure, then pass this structure to the `GPIO_Init` function.

```c
GPIO_Handle_t gpioHandle;
gpioHandle.pGPIOx = GPIOA;  // Example: GPIOA port
gpioHandle.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_0;
gpioHandle.GPIO_PinConfig.GPIO_PinMode = GPIO_Mode_OUT_PP;
gpioHandle.GPIO_PinConfig.GPIO_PinSpeed = GPIO_Speed_MED;
gpioHandle.GPIO_PinConfig.GPIO_PinPuPd = GPIO_PD;
GPIO_Init(&gpioHandle);
