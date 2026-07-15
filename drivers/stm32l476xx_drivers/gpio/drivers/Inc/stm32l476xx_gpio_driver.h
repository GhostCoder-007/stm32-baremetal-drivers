/*
 * stm32l476xx_gpio_driver.h
 *
 *  Created on: Jun 8, 2026
 *      Author: BrendonN
 */

#ifndef INC_STM32L476XX_GPIO_DRIVER_H_
#define INC_STM32L476XX_GPIO_DRIVER_H_

#include "stm32l476xx.h"

typedef struct
{
    uint8_t GPIO_PinNumber; /*!< possible values from @GPIO_PIN_NUMBERS */
    uint8_t GPIO_PinMode; /*!< possible values from @GPIO_PIN_MODES */
    uint8_t GPIO_PinSpeed; /*!< possible values from @GPIO_PIN_SPEED */
    uint8_t GPIO_PinPuPdControl; /*!< possible values from @GPIO_PIN_PUPD */
    uint8_t GPIO_PinOPType; /*!< possible values from @GPIO_OP_TYPE */
    uint8_t GPIO_PinAltFunMode; /*!< possible values from @GPIO_ALT_FUNC_MODES */
}GPIO_PinConfig_t;

typedef struct
{
    GPIO_regDef_t*pGPIOx; /*!< This holds the base address of the GPIO port to which the pin belongs */
    GPIO_PinConfig_t*pGPIOConfig; /*!< This holds the GPIO pin configuration settings */

}GPIO_HANDLE_t;

/********************************************************************************
*                      APIs supported by this driver
*       For more information about the APIs, check the function definitions
********************************************************************************/
// Prototyping the GPIO API's

void GPIO_PeriClock_Control(void);

/*

*/

void GPIO_Init(void);
void GPIO_DeInit(void);

/*
GPIO Read and Write
*/

void GPIO_ReadFromInputPin(void);
void GPIO_ReadFromInputPort(void);
void GPIO_WriteToOutputPin(void);
void GPIO_WriteToOutputPort(void);    
void GPIO_ToggleOutputPin(void);

/*
ISR ORQ
*/
void GPIO_IRQConfig(void); //irq number for configuring
void GPIO_ISRHandling(void); 

#endif /* INC_STM32L476XX_GPIO_DRIVER_H_ */
