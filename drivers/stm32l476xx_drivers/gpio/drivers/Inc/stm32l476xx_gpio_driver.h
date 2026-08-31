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
    uint8_t GPIO_PinNumber;       /*!< possible values from @GPIO_PIN_NUMBERS */
    uint8_t GPIO_PinMode;         /*!< possible values from @GPIO_PIN_MODES */
    uint8_t GPIO_PinSpeed;        /*!< possible values from @GPIO_PIN_SPEED */
    uint8_t GPIO_PinPuPdControl;  /*!< possible values from @GPIO_PIN_PUPD */
    uint8_t GPIO_PinOPType;       /*!< possible values from @GPIO_OP_TYPE */
    uint8_t GPIO_PinAltFunMode;   /*!< possible values from @GPIO_ALT_FUNC_MODES */
}GPIO_PinConfig_t;

typedef struct
{
    GPIO_regDef_t*pGPIOx;          /*!< This holds the base address of the GPIO port to which the pin belongs */
    GPIO_PinConfig_t GPIOConfig;  /*!< This holds the GPIO pin configuration settings */

}GPIO_HANDLE_t;


/*
* @GPIO_PIN_NUMBERS
* GPIO Possible Pin numbers
*/
#define GPIO_PIN_NO_0 0
#define GPIO_PIN_NO_1 1
#define GPIO_PIN_NO_2 2
#define GPIO_PIN_NO_3 3
#define GPIO_PIN_NO_4 4
#define GPIO_PIN_NO_5 5
#define GPIO_PIN_NO_6 6
#define GPIO_PIN_NO_7 7
#define GPIO_PIN_NO_8 8
#define GPIO_PIN_NO_9 9
#define GPIO_PIN_NO_10 10
#define GPIO_PIN_NO_11 11
#define GPIO_PIN_NO_12 12
#define GPIO_PIN_NO_13 13
#define GPIO_PIN_NO_14 14
#define GPIO_PIN_NO_15 15

/*
* @GPIO_PIN_MODES
* GPIO Possible Modes
*/

#define GPIO_MODE_INPUT  0 // value for GPIO port mode register (GPIOx_MODER)
#define GPIO_MODE_OUTPUT 1
#define GPIO_MODE_ALTFN  2
#define GPIO_MODE_ANALOG 3
#define GPIO_MODE_IT_FT  4
#define GPIO_MODE_IT_RT  5
#define GPIO_MODE_IT_RFT 6

/*
* @GPIO_OP_TYPE
* GPIO possible output types
*/

#define GPIO_OP_TYPE_PP 0
#define GPIO_OP_TYPE_OD 1

/*
* @GPIO_PIN_SPEED
* GPIO possible Speed types
*/
#define GPIO_SPEED_LOW 0
#define GPIO_SPEED_MEDIUM 1
#define GPIO_SPEED_HIGH 2
#define GPIO_SPEED_VERY_HIGH 3

/*
* @GPIO_PIN_PUPD
* GPIO possible Pull-up pull-down settings
*/
#define GPIO_NO_PUPD 0
#define GPIO_PIN_PU 1
#define GPIO_PIN_PD 2

#define GPIO_PIN_SET 1


/********************************************************************************
*                      APIs supported by this driver
*       For more information about the APIs, check the function definitions
********************************************************************************/
// Prototyping the GPIO API's
void GPIO_PeriClock_Control(GPIO_regDef_t *pGPIOx, uint8_t EnorDi);
void GPIO_Init(GPIO_HANDLE_t *pGPIOHandle);
void GPIO_DeInit(GPIO_regDef_t *pGPIOx);

/*
GPIO Read and Write
*/

uint8_t GPIO_ReadFromInputPin(GPIO_regDef_t *pGPIOx, uint8_t PinNumber);
uint16_t GPIO_ReadFromInputPort(GPIO_regDef_t *pGPIOx);
void GPIO_WriteToOutputPin(GPIO_regDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value);
void GPIO_WriteToOutputPort(GPIO_regDef_t *pGPIOx, uint8_t Value);    
void GPIO_ToggleOutputPin(GPIO_regDef_t *pGPIOx, uint8_t PinNumber);

/*
ISR ORQ
*/
void GPIO_IRQConfig(void); //irq number for configuring
void GPIO_ISRHandling(void); 

#endif /* INC_STM32L476XX_GPIO_DRIVER_H_ */
