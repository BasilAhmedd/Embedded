//#include <stdint.h>
//#include "STM32f401xx.h"
//#include "STM32f401_gpio.h"
//void delay(uint32_t time){
//	for (uint32_t i = 0; i < time * 1000; i++);
//}
//
//int main(void)
//{
//	GPIO_EnableClock(GPIOA);
//	GPIO_EnableClock(GPIOB);
//
//	GPIO_Init(GPIOA,2,0x1,0x0,0x0,0x0);
////	GPIO_Init(GPIOB,2,0x1,0x0,0x0,0x0);
////	GPIO_Init(GPIOB,3,0x0,0x0,0x0,0x1);
//	GPIO_Init(GPIOB,3,0x0,0x0,0x0,0x2); //this for pull down
//
//	while(1) {
////		GPIO_TogglePin(GPIOA,2);
////		delay(125);
//		if(GPIO_ReadInputPin(GPIOB,3)==1){
//			GPIO_WriteOutputPin(GPIOA,2,1);
//		}else{
//			GPIO_WriteOutputPin(GPIOA,2,0);
//		}
//	}
//}
////	RCC->AHB1ENR |= (1<<0); //enable GPIOA clock
////
////	GPIOA->MODER &= ~(3 << (2 * 2)); //clear bits
////	GPIOA->MODER |= (1 << (2 * 2));
////
////
////	while(1){
////		if(!(GPIOA->IDR & (1 << 0))){
////			GPIOA->ODR |= (1<<2);
////		}else{
////			GPIOA->ODR &= ~(1<<2);
////		}
////
////
////	}
#include <stdint.h>
#include "STM32f401xx.h"
#include "STM32f401_gpio.h"

// Simple delay function
void delay(uint32_t time) {
    for (uint32_t i = 0; i < time * 1000; i++);
}

int main(void) {
    // Enable clock for GPIOA and GPIOB
    GPIO_EnableClock(GPIOA);
    GPIO_EnableClock(GPIOB);

    // Configure PA2 as output for LED
    GPIO_Init(GPIOA, 2, 0x1, 0x0, 0x0, 0x0);

    // Configure PB3 as input with pull-down resistor
    GPIO_Init(GPIOB, 3, 0x0, 0x0, 0x0, 0x2);

    while(1) {
        // Check if button (PB3) is pressed (reads HIGH)
        if(GPIO_ReadInputPin(GPIOB, 3) == 1) {
            GPIO_WriteOutputPin(GPIOA, 2, 1);  // Turn ON LED
        } else {
            GPIO_WriteOutputPin(GPIOA, 2, 0);  // Turn OFF LED
        }
    }
}


