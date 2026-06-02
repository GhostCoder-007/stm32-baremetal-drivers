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
 * Base Addresses for AHB1 bus (RCC)
 * 
 *  */
#define RCC_BASEADDR                                    (AHB1PERIPH_BASE + 0x1000) 

/*
 * Base Addresses for AHB2 (GPIO) bus
 * Todo: Complete for peripherals on bus
 *  */
#define GPIOI_BASEADDR                                 (AHB2PERIPH_BASE + 0x2000) //GPIOI
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

 typedef struct 
 {
    __vo uint32_t CR;          /*|< RCC clock control register,                           Address offset: 0x00 */
    __vo uint32_t ICSCR;       /*|< RCC internal clock sources calibration register,      Address offset: 0x04 */
    __vo uint32_t CFGR;        /*|< RCC clock configuration register,                     Address offset: 0x08 */
    __vo uint32_t PLLCFGR;     /*|< RCC PLL configuration register,                       Address offset: 0x0C */
    __vo uint32_t PLLSAI1CFGR; /*|< RCC PLLSAI1 configuration register,                   Address offset: 0x10 */
    __vo uint32_t PLLSAI2CFGR; /*|< RCC PLLSAI2 configuration register,                   Address offset: 0x14 */
    __vo uint32_t CIER;        /*|< RCC clock interrupt enable register,                  Address offset: 0x18 */
    __vo uint32_t CIFR;        /*|< RCC clock interrupt flag register,                    Address offset: 0x1C */
    __vo uint32_t CICR;        /*|< RCC clock interrupt clear register,                   Address offset: 0x20 */
    uint32_t RESERVED0;        /*|< Reserved, 0x24 */
    __vo uint32_t AHB1RSTR;    /*|< RCC AHB1 peripheral reset register,                   Address offset: 0x28 */
    __vo uint32_t AHB2RSTR;    /*|< RCC AHB2 peripheral reset register,                   Address offset: 0x2C */
    __vo uint32_t AHB3RSTR;    /*|< RCC AHB3 peripheral reset register,                   Address offset: 0x30 */
    uint32_t RESERVED1;        /*|< Reserved, 0x34 */
    __vo uint32_t APB1RSTR1;   /*|< RCC APB1 peripheral reset register 1,                 Address offset: 0x38 */
    __vo uint32_t APB1RSTR2;   /*|< RCC APB1 peripheral reset register 2,                 Address offset: 0x3C */
    __vo uint32_t APB2RSTR;    /*|< RCC APB2 peripheral reset register,                   Address offset: 0x40 */
    uint32_t RESERVED2;        /*|< Reserved, 0x44 */
    __vo uint32_t AHB1ENR;     /*|< RCC AHB1 peripheral clock enable register,            Address offset: 0x48 */
    __vo uint32_t AHB2ENR;     /*|< RCC AHB2 peripheral clock enable register,            Address offset: 0x4C */
    __vo uint32_t AHB3ENR;     /*|< RCC AHB3 peripheral clock enable register,            Address offset: 0x50 */
    uint32_t RESERVED3;        /*|< Reserved, 0x54 */
    __vo uint32_t APB1ENR1;    /*|< RCC APB1 peripheral clock enable register 1,          Address offset: 0x58 */
    __vo uint32_t APB1ENR2;    /*|< RCC APB1 peripheral clock enable register 2,          Address offset: 0x5C */
    __vo uint32_t APB2ENR;     /*|< RCC APB2 peripheral clock enable register,            Address offset: 0x60 */

 } RCC_RegDef_t;
 
/*
* Creating Periphral definitions for GPIO
* Base address is typecast to GPIO_regDef_t
*/

#define GPIOA (GPIO_regDef_t *) GPIOA_BASEADDR 
#define GPIOB (GPIO_regDef_t *) GPIOB_BASEADDR 
#define GPIOC (GPIO_regDef_t *) GPIOC_BASEADDR 
#define GPIOD (GPIO_regDef_t *) GPIOD_BASEADDR 
#define GPIOE (GPIO_regDef_t *) GPIOE_BASEADDR 
#define GPIOF (GPIO_regDef_t *) GPIOF_BASEADDR 
#define GPIOG (GPIO_regDef_t *) GPIOG_BASEADDR 
#define GPIOH (GPIO_regDef_t *) GPIOH_BASEADDR 
#define GPIOI (GPIO_regDef_t *) GPIOI_BASEADDR 
#define RCC   (RCC_RegDef_t *)  RCC_BASEADDR

//GPIO_regDef_t *pGPIOA = (GPIO_regDef_t *) GPIOA_BASEADDR;   pointer to struct fot GPIOA peripheral base address, used to access the registers of GPIOA peripheral
//GPIO_regDef_t *pGPIOB = (GPIO_regDef_t *) GPIOB_BASEADDR;

 /* clock enable macros for GPIOx peripherals */
#define GPIOA_PCLK_EN()      RCC->AHB2ENR |= (1 << 0)
#define GPIOB_PCLK_EN()      RCC->AHB2ENR |= (1 << 1)
#define GPIOC_PCLK_EN()      RCC->AHB2ENR |= (1 << 2)
#define GPIOD_PCLK_EN()      RCC->AHB2ENR |= (1 << 3)
#define GPIOE_PCLK_EN()      RCC->AHB2ENR |= (1 << 4)
#define GPIOF_PCLK_EN()      RCC->AHB2ENR |= (1 << 5)
#define GPIOG_PCLK_EN()      RCC->AHB2ENR |= (1 << 6)
#define GPIOH_PCLK_EN()      RCC->AHB2ENR |= (1 << 7)
#define GPIOI_PCLK_EN()      RCC->AHB2ENR |= (1 << 8)

 /* clock disable macros for GPIOx peripherals */
#define GPIOA_PCLK_DISABLE()      RCC->AHB2ENR &= ~(1 << 0)
#define GPIOB_PCLK_DISABLE()      RCC->AHB2ENR &= ~(1 << 1)
#define GPIOC_PCLK_DISABLE()      RCC->AHB2ENR &= ~(1 << 2)
#define GPIOD_PCLK_DISABLE()      RCC->AHB2ENR &= ~(1 << 3)
#define GPIOE_PCLK_DISABLE()      RCC->AHB2ENR &= ~(1 << 4)
#define GPIOF_PCLK_DISABLE()      RCC->AHB2ENR &= ~(1 << 5)
#define GPIOG_PCLK_DISABLE()      RCC->AHB2ENR &= ~(1 << 6)
#define GPIOH_PCLK_DISABLE()      RCC->AHB2ENR &= ~(1 << 7)
#define GPIOI_PCLK_DISABLE()      RCC->AHB2ENR &= ~(1 << 8)

/* clock enable macro for spi peripheral */
#define SPI2_PCLK_EN()       RCC->APB1ENR1 |= (1 << 14)
#define SPI3_PCLK_EN()       RCC->APB1ENR1 |= (1 << 15)

/* clock disable macro for spi peripheral */
#define SPI2_PCLK_DISABLE()       RCC->APB1ENR1 &= ~(1 << 14)
#define SPI3_PCLK_DISABLE()       RCC->APB1ENR1 &= ~(1 << 15)

/* clock enable macro for USART* peripheral */
#define USART2_PCLK_EN()     RCC->APB1ENR1 |= (1 << 17)
#define USART3_PCLK_EN()     RCC->APB1ENR1 |= (1 << 18)
#define UART4_PCLK_EN()      RCC->APB1ENR1 |= (1 << 19)
#define UART5_PCLK_EN()      RCC->APB1ENR1 |= (1 << 20)

/* clock disable macro for USART* peripheral */
#define USART2_PCLK_DISABLE()     RCC->APB1ENR1 &= ~(1 << 17)
#define USART3_PCLK_DISABLE()     RCC->APB1ENR1 &= ~(1 << 18)
#define UART4_PCLK_DISABLE()      RCC->APB1ENR1 &= ~(1 << 19)
#define UART5_PCLK_DISABLE()      RCC->APB1ENR1 &= ~(1 << 20)

/* clock enable macro for SYSCFG  peripheral*/
#define SYSCFG_PCLK_EN()     RCC->APB2ENR |= (1 << 0)

/* clock disable macro for SYSCFG  peripheral*/
#define SYSCFG_PCLK_DISABLE()     RCC->APB2ENR &= ~(1 << 0)

/* clock enable macro for I2Cx peripherals*/
#define I2C1_PCLK_EN()      RCC->APB1ENR1 |= (1 << 21)
#define I2C2_PCLK_EN()      RCC->APB1ENR1 |= (1 << 22)
#define I2C3_PCLK_EN()      RCC->APB1ENR1 |= (1 << 23)

/* clock disable macro for I2Cx peripherals*/
#define I2C1_PCLK_DISABLE()      RCC->APB1ENR1 &= ~(1 << 21)
#define I2C2_PCLK_DISABLE()      RCC->APB1ENR1 &= ~(1 << 22)
#define I2C3_PCLK_DISABLE()      RCC->APB1ENR1 &= ~(1 << 23)

#endif /* INC_STM32L476XX_H_ */
