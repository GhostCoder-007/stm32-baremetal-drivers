/*
 * stm32l476xx.h
 *
 *  Created on: Feb 11, 2026
 *      Author: Brendon Nhachi
 */

#ifndef INC_STM32L476XX_H_
#define INC_STM32L476XX_H_

#define FLASH_BASEADDR                                 0x8000000U
#define SRAM1_BASEADDR                                 0x20000000U
#define SRAM2_BASEADDR                                 0x10000000U
#define ROM_BASEADDR                                   0x1FFF0000U // System memory


/*  AHBx & APBx Bus Peripheral base Addresses  */

#define PERIPH_BASE                                    0x40000000U
#define APB1PERIPH_BASE                                PERIPH_BASE
#define APB2PERIPH_BASE                                0x40010000U
#define AHB1PERIPH_BASE                                0x40020000U
#define AHB2PERIPH_BASE                                0x48000000U

/*
 * Base Addresses for AHB2 (GPIO) bus
 * Todo: Complete for peripherals on bus
 *  */

#define GPIOA_BASEADDR                                 (AHB2PERIPH_BASE + 0x0000)
#define GPIOB_BASEADDR                                 (AHB2PERIPH_BASE + 0x0400)
#define GPIOC_BASEADDR                                 (AHB2PERIPH_BASE + 0x0800)
#define GPIOD_BASEADDR                                 (AHB2PERIPH_BASE + 0x0C00)
#define GPIOE_BASEADDR                                 (AHB2PERIPH_BASE + 0x1000)
#define GPIOF_BASEADDR                                 (AHB2PERIPH_BASE + 0x1400)
#define GPIOG_BASEADDR                                 (AHB2PERIPH_BASE + 0x1800)
#define GPIOH_BASEADDR                                 (AHB2PERIPH_BASE + 0x1C00)

#endif /* INC_STM32L476XX_H_ */
