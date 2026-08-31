/*
 * 002led_button.c
 *
 *  Created on: Jul 20, 2026
 *      Author: BrendonN
 */


#include <stm32l476xx.h>
#define HIGH 1
#define BTN_PRESSED HIGH
void delay(void);
int main(void)
{
	GPIO_HANDLE_t GpioLed, GPIObtn;
    GpioLed.pGPIOx = GPIOA;
    GpioLed.GPIOConfig.GPIO_PinNumber       = GPIO_PIN_NO_5;
    GpioLed.GPIOConfig.GPIO_PinMode         = GPIO_MODE_OUTPUT;
    GpioLed.GPIOConfig.GPIO_PinSpeed        = GPIO_SPEED_HIGH;
    GpioLed.GPIOConfig.GPIO_PinOPType       = GPIO_OP_TYPE_PP;
    GpioLed.GPIOConfig.GPIO_PinPuPdControl  = GPIO_NO_PUPD;

    GPIO_PeriClock_Control(GPIOA,ENABLE);
    GPIO_Init(&GpioLed); // pointer input

    GPIObtn.pGPIOx = GPIOA;
    GPIObtn.GPIOConfig.GPIO_PinNumber       = GPIO_PIN_NO_0;
    GPIObtn.GPIOConfig.GPIO_PinMode         = GPIO_MODE_INPUT;
    GPIObtn.GPIOConfig.GPIO_PinSpeed        = GPIO_SPEED_HIGH;
    GPIObtn.GPIOConfig.GPIO_PinPuPdControl  = GPIO_NO_PUPD;

    GPIO_PeriClock_Control(GPIOA,ENABLE);
    GPIO_Init(&GPIObtn); // pointer input

    while (1)
    {
        if (GPIO_ReadFromInputPin(GPIOA, GPIO_PIN_NO_0) == BTN_PRESSED)
        {
            delay();
            GPIO_ToggleOutputPin(GPIOA, GPIO_PIN_NO_5);
        }
    }
    return 0;
}

void delay(void)
{
    for(uint32_t i = 0; i < 500000/2; i++)
        {
        }
}
