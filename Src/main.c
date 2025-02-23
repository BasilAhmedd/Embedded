#include <stdint.h>
#include "STM32f401xx.h"
void delay(uint32_t time){
	for (uint32_t i = 0; i < time * 1000; i++);
}

int main(void)
{
	RCC->AHB1ENR |= (1<<0); //enable GPIOA clock

	GPIOA->MODER &= ~(3 << (2 * 2)); //clear bits
	GPIOA->MODER |= (1 << (2 * 2));
	GPIOA->ODR |= (1<<2);

	while(1){
	}
}
