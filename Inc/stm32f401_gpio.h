/*
 * stm32f401_gpio.h
 *
 * Created on: Feb 26, 2025
 * Author: basel.abdella
 */

#ifndef STM32F401_GPIO_H_
#define STM32F401_GPIO_H_

#include "STM32f401xx.h"  // ✅ Removed incorrect semicolon

/* Function Prototypes */
void GPIO_EnableClock(GPIO_RegDef_t *pGPIOx);
void GPIO_Init(GPIO_RegDef_t *pGPIOx, int pinNumber, int mode, int speed, int outputType, int pull);
void GPIO_WriteOutputPin(GPIO_RegDef_t *pGPIOx, int pinNumber, int value);
void GPIO_TogglePin(GPIO_RegDef_t *pGPIOx, int pinNumber);
int GPIO_ReadInputPin(GPIO_RegDef_t *pGPIOx, int pinNumber);

#endif /* STM32F401_GPIO_H_ */
