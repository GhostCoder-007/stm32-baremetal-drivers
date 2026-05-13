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

#endif /* INC_STM32L476XX_H_ */
