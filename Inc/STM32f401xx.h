#ifndef STM32F401XX_H_
#define STM32F401XX_H_

#define GPIOA_BASEADDR  0x40020000
#define GPIOB_BASEADDR  0x40020400
#define GPIOC_BASEADDR  0x40020800
#define RCC_BASEADDR    0x40023800

#define GPIOA_MODER (*(volatile int *)(GPIOA_BASEADDR + 0x00))

typedef volatile unsigned long int vu32;

typedef struct {
    volatile int MODER;
    volatile int OTYPER;
    volatile int OSPEEDER;
    volatile int PUPDR;
    volatile int IDR;
    volatile int ODR;
    volatile int BSRR;
    volatile int LCKR;
    volatile int AFR[2];
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

#define GPIOA ((GPIO_RegDef_t*) GPIOA_BASEADDR)
#define GPIOB ((GPIO_RegDef_t*) GPIOB_BASEADDR)
#define GPIOC ((GPIO_RegDef_t*) GPIOC_BASEADDR)
#define RCC   ((RCC_TypeDef*) RCC_BASEADDR)

#endif /* STM32F401XX_H_ */
