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
        else if (pGPIOx == GPIOI) {GPIOI_PCLK_EN();}
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
        else if (pGPIOx == GPIOI) {GPIOI_PCLK_DISABLE();}
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
        pGPIOHandle->pGPIOx->MODER &= ~(0x03 << pGPIOHandle->GPIOConfig.GPIO_PinNumber); // clearing bit
        pGPIOHandle->pGPIOx->MODER |= temp; // setting bit
        temp = 0;
    }
    else
    {
        //Interupt Mode
    }

    // 2. Confifure the speed
    temp = 0;
    temp = (pGPIOHandle->GPIOConfig.GPIO_PinSpeed << (2*pGPIOHandle->GPIOConfig.GPIO_PinSpeed)); // each pin has 2 bits in the OSPEEDR register, so we shift by 2*pinNumber
    pGPIOHandle->pGPIOx->OSPEEDR &= ~(0x03 << pGPIOHandle->GPIOConfig.GPIO_PinNumber);// clearing bit
    pGPIOHandle->pGPIOx->OSPEEDR |= temp;

    // 3. Configure the pull-up/pull-down settings
    temp = 0;
    temp = (pGPIOHandle->GPIOConfig.GPIO_PinPuPdControl << (2*pGPIOHandle->GPIOConfig.GPIO_PinPuPdControl)); // each pin has 2 bits in the PUPDR register, so we shift by 2*pinNumber
    pGPIOHandle->pGPIOx->PUPDR &= ~(0x03 << pGPIOHandle->GPIOConfig.GPIO_PinNumber);// clearing bit
    pGPIOHandle->pGPIOx->PUPDR |= temp;

    // 4. Configure the output type
    temp = 0;
    temp = (pGPIOHandle->GPIOConfig.GPIO_PinOPType << (pGPIOHandle->GPIOConfig.GPIO_PinOPType)); // each pin has 1 bit in the OTYPER register, so we shift by pinNumber
    pGPIOHandle->pGPIOx->OTYPER &= ~(0x01 << pGPIOHandle->GPIOConfig.GPIO_PinNumber);// clearing bit
    pGPIOHandle->pGPIOx->OTYPER |= temp;

    // 5. Configure the alternate function
    if (pGPIOHandle->GPIOConfig.GPIO_PinMode == GPIO_MODE_ALTFN)
    {
        uint8_t temp1, temp2;
        temp1=pGPIOHandle->GPIOConfig.GPIO_PinNumber / 8; // there are two tables of registers (low and high) getting / 8 -> if 1 its high
        temp2=pGPIOHandle->GPIOConfig.GPIO_PinNumber % 8; // getting mod gives the bit position
        pGPIOHandle->pGPIOx->AFR[temp1] |= ~(0xF << (4 * temp2)); // clear bits
        pGPIOHandle->pGPIOx->AFR[temp1] |= (pGPIOHandle->GPIOConfig.GPIO_PinAltFunMode << (4 * temp2)); //
    }
}

/**********************************************************************************
 * @fn                - GPIO_DeInit
 * 
 * @brief             - Reinitializs GPIO peripheral. - make 1 and then 0 again so its not always reset
 * 
 * @param[in]         - pGPIOx.
 * @param[in]         - 
 * 
 * @return            - None
 */

void GPIO_DeInit(GPIO_regDef_t *pGPIOx)
    { 
             if (pGPIOx == GPIOA){ GPIOA_REG_RESET();}
        else if (pGPIOx == GPIOB) {GPIOB_REG_RESET();}
        else if (pGPIOx == GPIOC) {GPIOC_REG_RESET();}
        else if (pGPIOx == GPIOD) {GPIOD_REG_RESET();}
        else if (pGPIOx == GPIOE) {GPIOE_REG_RESET();}
        else if (pGPIOx == GPIOF) {GPIOF_REG_RESET();}
        else if (pGPIOx == GPIOG) {GPIOG_REG_RESET();}
        else if (pGPIOx == GPIOH) {GPIOH_REG_RESET();}
        else if (pGPIOx == GPIOI) {GPIOI_REG_RESET();}
    }

/**********************************************************************************
 * @fn                - GPIO_ReadFromInputPin
 * 
 * @brief             - Read values from input pin
 * 
 * @param[in]         - pGPIOx.
 * @param[in]         - PinNumber
 * 
 *
 * */

 uint8_t GPIO_ReadFromInputPin(GPIO_regDef_t *pGPIOx, uint8_t PinNumber)
 {
    uint8_t value;
    value = (uint8_t)((pGPIOx->IDR >> PinNumber) && 0x0000001);
    return value;
 }

 /**********************************************************************************
 * @fn                - GPIO_ReadFromInputPort
 * 
 * @brief             - Read values from input port
 * 
 * @param[in]         - pGPIOx.
 * @param[in]         -
 * 
 *
 * */

 uint16_t GPIO_ReadFromInputPort(GPIO_regDef_t *pGPIOx)
 {
    uint16_t value;
    value = (uint16_t)(pGPIOx->IDR);
    return value;
 }

  /**********************************************************************************
 * @fn                - GPIO_WriteToOutputPin
 * 
 * @brief             - Write to output pin
 * 
 * @param[in]         - pGPIOx.
 * @param[in]         - PinNumber
 * @param[in]         - Value
 * 
 *
 * */

 void GPIO_WriteToOutputPin(GPIO_regDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value)
 {
    if (Value == GPIO_PIN_SET)
    {
        pGPIOx->ODR |= (1 << PinNumber); // Set pin in port
    }
    else
    {
        pGPIOx->ODR &= ~(1<< PinNumber); // Reset pin in port
    }
 }

 /**********************************************************************************
 * @fn                - GPIO_WriteToOutputPort
 * 
 * @brief             - Write to output port
 * 
 * @param[in]         - pGPIOx.
 * @param[in]         - Value
 * 
 *
 * */

 void GPIO_WriteToOutputPort(GPIO_regDef_t *pGPIOx, uint8_t Value)
 {
    pGPIOx->ODR = Value; 
 }

 /**********************************************************************************
 * @fn                - GPIO_ToggleOutputPin
 * 
 * @brief             - Toggle output pin
 * 
 * @param[in]         - pGPIOx.
 * @param[in]         - PinNumber
 * 
 *
 * */

 void GPIO_ToggleOutputPin(GPIO_regDef_t *pGPIOx, uint8_t PinNumber)
 {
    pGPIOx->ODR ^= (1 << PinNumber); 
 }