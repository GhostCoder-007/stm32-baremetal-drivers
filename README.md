# STM32 Bare-Metal Driver Development

This repository contains register-level drivers and example projects
for STM32 microcontrollers, developed without HAL.

## Targets
- STM32L4 series
- ARM Cortex-M4

## Drivers
- GPIO
- RCC
- TIM (PWM, Input Capture)
- UART
- I2C
- SPI
- CAN (planned)
- RS-485 (planned)
- RS-232 (planned)

## Toolchain
- arm-none-eabi-gcc
- OpenOCD
- CMake

## Philosophy
- No HAL
- Datasheet-first development
- Clear separation of drivers and applications
