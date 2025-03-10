/*
 * stm32f401xx.h
 *
 *  Created on: Mar 10, 2025
 *      Author: ser
 */

#ifndef STM32F401XX_H_
#define STM32F401XX_H_

#define GPIOA_BASEADDR 0x40020000
#define GPIOB_BASEADDR 0x40020400
#define GPIOC_BASEADDR 0x40020800
#define RCC_BASEADDR 0x40023800
#define ADC1_BASEADDR 0x40012000

typedef struct {
	volatile int MODER;
	volatile int OTYPER;
	volatile int OSPEEDR;
	volatile int PUPDR;
	volatile int IDR ;
	volatile int ODR ;
	volatile int BSRR;
    volatile int LCKR;
    volatile int AFR[2];
} GPIO_REGDEF;

typedef struct {
	volatile int CR;
	volatile int PLLCFGR;
	volatile int CFGR;
	volatile int CIR;
	volatile int AHB1RSTR;
	volatile int AHB2RSTR;
	volatile int Reserved0[2];
	volatile int APB1RSTR;
	volatile int APB2RSTR;
	volatile int Reserved1[2];
	volatile int AHB1ENR;
	volatile int AHB2ENR;
	volatile int Reserved2[2];
	volatile int APB1ENR;
	volatile int APB2ENR;
	volatile int Reserved3[2];
}RCC_REGDEF;

typedef struct {
	volatile int SR;
	volatile int CR1;
	volatile int CR2;
	volatile int SMPR1;
	volatile int SMPR2;
	volatile int JOFR1;
	volatile int JOFR2;
	volatile int JOFR3;
	volatile int JOFR4;
	volatile int HTR;
	volatile int LTR;
	volatile int SQR1;
	volatile int SQR2;
	volatile int SQR3;
	volatile int JSQR;
	volatile int JDR1;
	volatile int JDR2;
	volatile int JDR3;
	volatile int JDR4;
	volatile int DR;
	volatile int CCR;
} ADC1_REGDEF;


#define GPIOA ((GPIO_REGDEF*) GPIOA_BASEADDR)
#define GPIOB ((GPIO_REGDEF*) GPIOB_BASEADDR)
#define GPIOC ((GPIO_REGDEF*) GPIOC_BASEADDR)
#define RCC ((RCC_REGDEF*) RCC_BASEADDR)
#define ADC1 ((ADC1_REGDEF*) ADC1_BASEADDR)
#endif /* STM32F401XX_H_ */
