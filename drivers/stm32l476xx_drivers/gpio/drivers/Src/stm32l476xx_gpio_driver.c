/*
 * stm32l476xx_gpio_driver.c
 *
 *  Created on: Jun 8, 2026
 *      Author: BrendonN
 */


#include <stm32l476xx_gpio_driver.h>

/**********************************************************************************
 * @fn                - GPIO_PeriClock_Control
 * 
 * @brief             - Enables or disables the peripheral clock for the given GPIO port.
 * 
 * @param[in]         - pGPIOx: Pointer to the GPIO port base address.
 * @param[in]         - EnorDi: Enable or disable macro (1 to enable, 0 to disable).
 * 
 * @return            - None
 */
void GPIO_PeriClock_Control(GPIO_regDef_t *pGPIOx, uint8_t EnorDi)
{
    if (EnorDi == ENABLE)
    {
             if (pGPIOx == GPIOA){ GPIOA_PCLK_EN();}
        else if (pGPIOx == GPIOB) {GPIOB_PCLK_EN();}
        else if (pGPIOx == GPIOC) {GPIOC_PCLK_EN();}
        else if (pGPIOx == GPIOD) {GPIOD_PCLK_EN();}
        else if (pGPIOx == GPIOE) {GPIOE_PCLK_EN();}
        else if (pGPIOx == GPIOF) {GPIOF_PCLK_EN();}
        else if (pGPIOx == GPIOG) {GPIOG_PCLK_EN();}
        else if (pGPIOx == GPIOH) {GPIOH_PCLK_EN();}
    }
    else 
    {
             if (pGPIOx == GPIOA){ GPIOA_PCLK_DISABLE();}
        else if (pGPIOx == GPIOB) {GPIOB_PCLK_DISABLE();}
        else if (pGPIOx == GPIOC) {GPIOC_PCLK_DISABLE();}
        else if (pGPIOx == GPIOD) {GPIOD_PCLK_DISABLE();}
        else if (pGPIOx == GPIOE) {GPIOE_PCLK_DISABLE();}
        else if (pGPIOx == GPIOF) {GPIOF_PCLK_DISABLE();}
        else if (pGPIOx == GPIOG) {GPIOG_PCLK_DISABLE();}
        else if (pGPIOx == GPIOH) {GPIOH_PCLK_DISABLE();}
    }
}
