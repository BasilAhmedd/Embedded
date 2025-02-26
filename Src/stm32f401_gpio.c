/*
 * stm32f401_gpio.c
 *
 *  Created on: Feb 26, 2025
 *      Author: basel.abdella
 */


#include "STM32f401xx.h"
#include "STM32f401_gpio.h"

void GPIO_EnableClock(GPIO_RegDef_t *pGPIOx){
	if(pGPIOx == GPIOA){
		RCC->AHB1ENR |=(1<<0);
	}else if(pGPIOx == GPIOB){
		RCC->AHB1ENR |=(1<<1);
	}else if(pGPIOx == GPIOC){
		RCC->AHB1ENR |=(1<<2);
	}
}

void GPIO_Init(GPIO_RegDef_t *pGPIOx , int pinNumber , int mode , int speed , int outputType , int pull){
	pGPIOx->MODER &= ~(0x3 << (pinNumber * 2));
	pGPIOx->MODER |= (mode << (pinNumber * 2));

	pGPIOx->OSPEEDER &= ~(0x3 << (pinNumber * 2));
	pGPIOx->OSPEEDER |= (speed << (pinNumber * 2));

	pGPIOx->OTYPER &= ~(0x1 << (pinNumber));
	pGPIOx->OTYPER |= (outputType << (pinNumber));

	pGPIOx->PUPDR &= ~(0x3 << (pinNumber * 2));
	pGPIOx->PUPDR |= (pull << (pinNumber * 2));
}

void GPIO_WriteOutputPin(GPIO_RegDef_t *pGPIOx , int pinNumber , int value ){
	if(value == 1){
		pGPIOx->ODR |= (1 << pinNumber);
	}else if (value == 0){
		pGPIOx->ODR &= ~(1 << pinNumber);  // ✅ Fixed issue
	}
}

void GPIO_TogglePin(GPIO_RegDef_t *pGPIOx, int pinNumber){
	pGPIOx->ODR ^= (1 << pinNumber);
}

int GPIO_ReadInputPin(GPIO_RegDef_t *pGPIOx, int pinNumber){
	return ((pGPIOx->IDR >> pinNumber) & 0x1);
}
