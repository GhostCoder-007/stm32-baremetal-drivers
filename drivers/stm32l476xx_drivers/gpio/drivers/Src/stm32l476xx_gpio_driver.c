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
/**********************************************************************************
 * @fn                - GPIO_Init
 * 
 * @brief             - Enables or disables the peripheral clock for the given GPIO port.
 * 
 * @param[in]         - pGPIOHandle.
 * @param[in]         - 
 * 
 * @return            - None
 */
void GPIO_Init(GPIO_HANDLE_t *pGPIOHandle)
{
    uint32_t temp = 0;
    // 1. Configure pinMode of Gpio pin
    if (pGPIOHandle->GPIOConfig.GPIO_PinMode <= GPIO_MODE_ANALOG )
    {
        // Non Interrupt Mode
        temp = (pGPIOHandle->GPIOConfig.GPIO_PinMode << (2*pGPIOHandle->GPIOConfig.GPIO_PinNumber)); // each pin has 2 bits in the MODER register, so we shift by 2*pinNumber
        pGPIOHandle->pGPIOx->MODER |= temp;
        temp = 0;
    }
    else
    {
        //Interupt Mode
    }

    // 2. Confifure the speed
    temp = 0;
    temp = (pGPIOHandle->GPIOConfig.GPIO_PinSpeed << (2*pGPIOHandle->GPIOConfig.GPIO_PinSpeed)); // each pin has 2 bits in the OSPEEDR register, so we shift by 2*pinNumber
    pGPIOHandle->pGPIOx->OSPEEDR |= temp;

    // 3. Configure the pull-up/pull-down settings
    temp = 0;
    temp = (pGPIOHandle->GPIOConfig.GPIO_PinPuPdControl << (2*pGPIOHandle->GPIOConfig.GPIO_PinPuPdControl)); // each pin has 2 bits in the PUPDR register, so we shift by 2*pinNumber
    pGPIOHandle->pGPIOx->PUPDR |= temp;

    // 4. Configure the output type
    temp = 0;
    temp = (pGPIOHandle->GPIOConfig.GPIO_PinOPType << (pGPIOHandle->GPIOConfig.GPIO_PinOPType)); // each pin has 1 bit in the OTYPER register, so we shift by pinNumber
    pGPIOHandle->pGPIOx->OTYPER |= temp;

    // 5. Configure the alternate function
    if (pGPIOHandle->GPIOConfig.GPIO_PinMode == GPIO_MODE_ALTFN)
    {
        uint32_t temp1, temp2;
        temp1=pGPIOHandle->GPIOConfig.GPIO_PinNumber / 8;
        temp2=pGPIOHandle->GPIOConfig.GPIO_PinNumber % 8;
        pGPIOHandle->pGPIOx->AFR
    }
}
