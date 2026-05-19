/*
 * stm32l476xx.h
 *
 *  Created on: Feb 11, 2026
 *      Author: Brendon Nhachi
 */

#ifndef INC_STM32L476XX_H_
#define INC_STM32L476XX_H_

#include <stdint.h> // standard header for integer types (e.g., uint32_t)

#define FLASH_BASEADDR                                 0x8000000U
#define SRAM1_BASEADDR                                 0x20000000U
#define SRAM2_BASEADDR                                 0x10000000U
#define ROM_BASEADDR                                   0x1FFF0000U // System memory

#define __vo volatile

/*  AHBx & APBx Bus Peripheral base Addresses  */
#define PERIPH_BASE                                    0x40000000U
#define APB1PERIPH_BASE                                PERIPH_BASE
#define APB2PERIPH_BASE                                0x40010000U
#define AHB1PERIPH_BASE                                0x40020000U
#define AHB2PERIPH_BASE                                0x48000000U

/*
 * Base Addresses for AHB1 bus
 * 
 *  */

/*
 * Base Addresses for AHB2 (GPIO) bus
 * Todo: Complete for peripherals on bus
 *  */
#define GPIOH_BASEADDR                                 (AHB2PERIPH_BASE + 0x1C00) //GPIOH
#define GPIOG_BASEADDR                                 (AHB2PERIPH_BASE + 0x1800) //GPIOG
#define GPIOF_BASEADDR                                 (AHB2PERIPH_BASE + 0x1400) //GPIOF
#define GPIOE_BASEADDR                                 (AHB2PERIPH_BASE + 0x1000) //GPIOE
#define GPIOD_BASEADDR                                 (AHB2PERIPH_BASE + 0x0C00) //GPIOD
#define GPIOC_BASEADDR                                 (AHB2PERIPH_BASE + 0x0800) //GPIOC
#define GPIOB_BASEADDR                                 (AHB2PERIPH_BASE + 0x0400) //GPIOB
#define GPIOA_BASEADDR                                 (AHB2PERIPH_BASE + 0x0000) //GPIOA

/*
 * Base Addresses for APB1 (I2c, UUART, USART, CAN1, SPI) bus
 * Todo: Complete for peripherals on bus
 *  */
#define CAN1_BASEADDR                                  (APB1PERIPH_BASE + 0x6400) //CAN1
#define I2C3_BASEADDR                                  (APB1PERIPH_BASE + 0x5C00) //I2C3
#define I2C2_BASEADDR                                  (APB1PERIPH_BASE + 0x5800) //I2C2
#define I2C1_BASEADDR                                  (APB1PERIPH_BASE + 0x5400) //I2C1
#define UART5_BASEADDR                                 (APB1PERIPH_BASE + 0x5000) //UART5
#define UART4_BASEADDR                                 (APB1PERIPH_BASE + 0x4C00) //UART4
#define USART3_BASEADDR                                (APB1PERIPH_BASE + 0x4800) //USART3
#define USART2_BASEADDR                                (APB1PERIPH_BASE + 0x4400) //USART2
#define SPI3_BASEADDR                                  (APB1PERIPH_BASE + 0x3C00) //SPI3
#define SPI2_BASEADDR                                  (APB1PERIPH_BASE + 0x3800) //SPI2

/*
 * Base Addresses for APB2 (EXTI, SYSCFG) bus
 * Todo: Complete for peripherals on bus
 *  */
 #define EXTI_BASEADDR                                 (APB2PERIPH_BASE + 0x0400) //EXTI
 #define SYSCFG_BASEADDR                               (APB2PERIPH_BASE + 0x0000) //SYSCFG

 /*
 * Register peripheral structure for GPIOx peripheral
 * Used as a placeholder for the GPIO peripheral register definitions, 
 * and to create a pointer to the GPIO peripheral base address for easy access to the registers.
 */
 typedef struct 
 {

    __vo uint32_t MODER;    /*|< GPIO port mode register,                             Address offset: 0x00 */
    __vo uint32_t OTYPER;   /*|< GPIO port output type register,                      Address offset: 0x04 */
    __vo uint32_t OSPEEDR;  /*|< GPIO port output speed register,                     Address offset: 0x08 */
    __vo uint32_t PUPDR;    /*|< GPIO port pull-up/pull-down register,                Address offset: 0x0C */
    __vo uint32_t IDR;      /*|< GPIO port input data register,                       Address offset: 0x10 */
    __vo uint32_t ODR;      /*|< GPIO port output data register,                      Address offset: 0x14 */
    __vo uint32_t BSRR;     /*|< GPIO port bit set/reset register,                    Address offset: 0x18 */
    __vo uint32_t LCKR;     /*|< GPIO port configuration lock register,               Address offset: 0x1C */
    __vo uint32_t AFR[2];   /*|< GPIO alternate function low (0) / high (1) register, Address offset: 0x20-0x24 */
    __vo uint32_t BRR;      /*|< GPIO port bit reset register,                        Address offset: 0x28 */
    __vo uint32_t ASCR;     /*|< GPIO port analog switch control register,            Address offset: 0x2C */

 } GPIO_regDef_t;

 //GPIO_regDef_t *pGPIOA = (GPIO_regDef_t *) GPIOA_BASEADDR;   pointer to struct fot GPIOA peripheral base address, used to access the registers of GPIOA peripheral
 //GPIO_regDef_t *pGPIOB = (GPIO_regDef_t *) GPIOB_BASEADDR;

#endif /* INC_STM32L476XX_H_ */
