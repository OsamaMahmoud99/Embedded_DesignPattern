/*
 * REGS.h
 *
 *  Created on: Apr 12, 2025
 *      Author: Osama
 */

#ifndef REGS_H_
#define REGS_H_

#include <stdint.h>

#define PERIPH_BASE		0x40000000U
#define AHB1PERIPH_BASE (PERIPH_BASE + 0x00020000U)
#define RCC_BASE		(AHB1PERIPH_BASE + 0x3800U)

#define GPIOA_BASE		(AHB1PERIPH_BASE + 0x0000U)
#define GPIOB_BASE		(AHB1PERIPH_BASE + 0x0400U)
#define GPIOC_BASE		(AHB1PERIPH_BASE + 0x0800U)
#define GPIOD_BASE		(AHB1PERIPH_BASE + 0x0C00U)
#define GPIOE_BASE		(AHB1PERIPH_BASE + 0x1000U)
#define GPIOF_BASE		(AHB1PERIPH_BASE + 0x1400U)
#define GPIOG_BASE		(AHB1PERIPH_BASE + 0x1800U)
#define GPIOH_BASE		(AHB1PERIPH_BASE + 0x1C00U)

#define RCC_AHB1ENR		(*(volatile unsigned int*)(RCC_BASE + 0x30))

#define GPIOA_EN		(1<<0)
#define GPIOB_EN		(1<<1)
#define GPIOC_EN		(1<<2)
#define GPIOD_EN		(1<<3)
#define GPIOE_EN		(1<<4)
#define GPIOF_EN		(1<<5)
#define GPIOG_EN		(1<<6)
#define GPIOH_EN		(1<<7)

typedef struct
{
	volatile uint32_t MODER;
	volatile uint32_t OTYPER;
	volatile uint32_t OSPEEDR;
	volatile uint32_t PUPDR;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t LCKR;
	volatile uint32_t AFR[2]; //offset 0x20 - 0x24

}GPIO_TypeDef;

#define GPIOA		((GPIO_TypeDef *)GPIOA_BASE)
#define GPIOB		((GPIO_TypeDef *)GPIOB_BASE)
#define GPIOC		((GPIO_TypeDef *)GPIOC_BASE)
#define GPIOD		((GPIO_TypeDef *)GPIOD_BASE)
#define GPIOE		((GPIO_TypeDef *)GPIOE_BASE)
#define GPIOF		((GPIO_TypeDef *)GPIOF_BASE)
#define GPIOG		((GPIO_TypeDef *)GPIOG_BASE)
#define GPIOH		((GPIO_TypeDef *)GPIOH_BASE)

typedef uint32_t 	Pin_Type;

#endif /* REGS_H_ */
