#ifndef STM32F401XX_H_
#define STM32F401XX_H_

#define GPIOA_BASEADDR  0x40020000
#define GPIOB_BASEADDR  0x40020400
#define GPIOC_BASEADDR  0x40020800
#define RCC_BASEADDR    0x40023800
#define ADC_BASEADDR    0x40012000

#define GPIOA_MODER (*(volatile int *)(GPIOA_BASEADDR + 0x00))

typedef volatile unsigned long int vu32;

typedef struct {
    vu32 MODER;
    vu32 OTYPER;
    vu32 OSPEEDER;
    vu32 PUPDR;
    vu32 IDR;
    vu32 ODR;
    vu32 BSRR;
    vu32 LCKR;
    vu32 AFR[2];
} GPIO_RegDef_t;

typedef struct {
    vu32 CR;
    vu32 PLLCFGR;
    vu32 CFGR;
    vu32 CIR;
    vu32 AHB1RSTR;
    vu32 AHB2RSTR;
    vu32 RESERVED0[2];
    vu32 APB1RSTR;
    vu32 APB2RSTR;
    vu32 RESERVED1[2];
    vu32 AHB1ENR;
    vu32 AHB2ENR;
    vu32 RESERVED2[2];
    vu32 APB1ENR;
    vu32 APB2ENR;
    vu32 RESERVED3[2];  // ✅ Ensure correct alignment
} RCC_TypeDef;

typedef struct {
  vu32 ADC_SR;
  vu32 ADC_CR1;
  vu32 ADC_CR2;
  vu32 ADC_SMPR1;
  vu32 ADC_SMPR2;
  vu32 ADC_JOFR1;
  vu32 ADC_JOFR2;
  vu32 ADC_JOFR3;
  vu32 ADC_JOFR4;
  vu32 ADC_HTR;
  vu32 ADC_LTR;
  vu32 ADC_SQR1;
  vu32 ADC_SQR2 ;
  vu32 ADC_SQR3 ;
  vu32 ADC_JSQR ;
  vu32 ADC_JDR1;
  vu32 ADC_JDR2;
  vu32 ADC_JDR3;
  vu32 ADC_JDR4;
  vu32 ADC_DR;
  vu32 ADC_CCR;
} ADC_TypeDef;

#define GPIOA ((GPIO_RegDef_t*) GPIOA_BASEADDR)
#define GPIOB ((GPIO_RegDef_t*) GPIOB_BASEADDR)
#define GPIOC ((GPIO_RegDef_t*) GPIOC_BASEADDR)
#define RCC   ((RCC_TypeDef*) RCC_BASEADDR)
#define ADC1  ((ADC_TypeDef*) ADC_BASEADDR)
#endif /* STM32F401XX_H_ */
