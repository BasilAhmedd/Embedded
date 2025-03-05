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
//#include <stdint.h>
//#include "STM32f401xx.h"
//#include "STM32f401_gpio.h"
//
//// Simple delay function
//void delay(uint32_t time) {
//    for (uint32_t i = 0; i < time * 1000; i++);
//}
//
//int main(void) {
//    // Enable clock for GPIOA and GPIOB
//    GPIO_EnableClock(GPIOA);
//    GPIO_EnableClock(GPIOB);
//
//    // Configure PA2 as output for LED
//    GPIO_Init(GPIOA, 2, 0x1, 0x0, 0x0, 0x0);
//
//    // Configure PB3 as input with pull-down resistor
//    GPIO_Init(GPIOB, 3, 0x0, 0x0, 0x0, 0x2);
//
//    while(1) {
//        // Check if button (PB3) is pressed (reads HIGH)
//        if(GPIO_ReadInputPin(GPIOB, 3) == 1) {
//            GPIO_WriteOutputPin(GPIOA, 2, 1);  // Turn ON LED
//        } else {
//            GPIO_WriteOutputPin(GPIOA, 2, 0);  // Turn OFF LED
//        }
//    }
//}

//#include "STM32f401xx.h"
//#include "STM32f401_gpio.h"
//
//int main(void) {
//    GPIO_EnableClock(GPIOA);
//    GPIO_Init(GPIOA, 0, 0x0, 0x0, 0x0, 0x0);  // Configure PA0 as Analog Input
//
//    ADC_Init();  // Initialize ADC
//
//    while (1) {
//        uint16_t adcValue = ADC_Read();  // Read ADC value
//    }
//}

//#include "stm32f401xx.h"
//#include <stdint.h>
//
//#define GREEN_LED_PIN  (1 << 0)  // PA0
//#define YELLOW_LED_PIN (1 << 1)  // PA1
//#define RED_LED_PIN    (1 << 2)  // PA2
//#define FAN_PIN        (1 << 3)  // PA3
//#define BUZZER_PIN     (1 << 4)  // PA4
//#define BUTTON_PIN     (1 << 5)  // PA5
//
//volatile uint8_t unit_celsius = 1; // Default to Celsius
//volatile uint8_t button_pressed = 0;
//
//void GPIO_Init(void) {
//    RCC->AHB1ENR |= (1 << 0);  // Enable GPIOA clock
//
//    GPIOA->MODER |= (1 << (0 * 2)) | (1 << (1 * 2)) | (1 << (2 * 2)) | (1 << (3 * 2)) | (1 << (4 * 2));
//    GPIOA->MODER &= ~(3 << (5 * 2)); // Set PA5 as input (Button)
//    GPIOA->PUPDR |= (1 << (5 * 2));  // Enable pull-up resistor on PA5
//}
//
//void ADC_Init(void) {
//    RCC->APB2ENR |= (1 << 8);  // Enable ADC1 clock
//    ADC1->CR2 |= (1 << 0);     // Enable ADC
//    ADC1->SMPR2 |= (7 << (0 * 3));   // Sample time for channel 0
//    ADC1->SQR3 |= (0 << 0);    // Select channel 0 (PA0)
//}
//
//uint16_t Read_ADC(void) {
//    ADC1->CR2 |= (1 << 30);    // Start conversion
//    while (!(ADC1->SR & (1 << 1)));  // Wait for conversion
//    return ADC1->DR;
//}
//
//void Button_Handler(void) {
//    if (!(GPIOA->IDR & BUTTON_PIN)) {
//        for (volatile int i = 0; i < 100000; i++); // Debounce delay
//        if (!(GPIOA->IDR & BUTTON_PIN)) {
//            button_pressed = 1;
//        }
//    }
//}
//
//void Set_Temperature_Indications(float temp) {
//    GPIOA->BSRR = (GREEN_LED_PIN | YELLOW_LED_PIN | RED_LED_PIN | FAN_PIN | BUZZER_PIN) << 16;
//
//    if (temp < 25) {
//        GPIOA->BSRR = GREEN_LED_PIN;
//    } else if (temp <= 35) {
//        GPIOA->BSRR = YELLOW_LED_PIN | FAN_PIN;
//    } else if (temp <= 45) {
//        GPIOA->BSRR = RED_LED_PIN | FAN_PIN;
//    } else {
//        GPIOA->BSRR = RED_LED_PIN | BUZZER_PIN | FAN_PIN;
//    }
//}
//
//int main(void) {
//    GPIO_Init();
//    ADC_Init();
//
//    while (1) {
//        uint16_t adc_value = Read_ADC();
//        float temperature = (adc_value * 3.3 / 4095.0) * 100.0;
//
//        if (!unit_celsius) {
//            temperature = (temperature * 9.0 / 5.0) + 32.0;
//        }
//
//        Set_Temperature_Indications(temperature);
//
//        Button_Handler();
//        if (button_pressed) {
//            unit_celsius = !unit_celsius;
//            button_pressed = 0;
//        }
//
//        for (volatile int i = 0; i < 100000; i++);
//    }
//}


/**
 * @file adc_gpio_control.c
 * @brief ADC and GPIO control using STM32F401 microcontroller.
 *
 * This program configures the ADC to read an analog input from PA0 and controls an LED on PA1
 * based on the ADC value.
 */

#include "STM32F401xx.h"  // Device header
#include "stdint.h"
int main(void) {
    RCC->AHB1ENR |= (1 << 0);   // Enable GPIOA clock (PA0)
    RCC->APB2ENR |= (1 << 8);   // Enable ADC1 clock
    GPIOA->MODER |= (0b11 << 0);  // Set PA0 to analog mode
    GPIOA->MODER |= (0b1 << 2);  // Set PA1 to output mode
    ADC1->ADC_CR2 |= (1 << 0);      // Enable ADC (ADON bit)
    for (volatile int i = 0; i < 1000; i++); // Short delay
    ADC1->ADC_CR1 = 0;              // 12-bit resolution (default)
    ADC1->ADC_SQR3 = 0;             // Convert channel 0 (PA0) first
    while (1) {
        ADC1->ADC_CR2 |= (1 << 30);    // Start conversion (SWSTART bit)
        while (!(ADC1->ADC_SR & (1 << 1))); // Wait for EOC (End of Conversion)
        uint16_t adc_value = ADC1->ADC_DR; // Read ADC result
        float temp = ((adc_value * 3.3)/ 4096)/0.01;
//        GPIOA->ODR &= ~((1 << 1) | (1 << 3) | (1 << 4));
//        GPIOB->ODR &= ~((1 << 0) | (1 << 6));

        if (temp > 45) {
            GPIOA->ODR |= (1 << 1);  // Turn on PA1 (LED) - High temperature alert
            GPIOB->ODR |= (1 << 0);  // Turn on PB0 (LED) - High temperature alert
        } else if (temp > 35) {
            GPIOA->ODR |= (1 << 1);  // Turn on PA1 (LED) - Medium-high temperature
            GPIOB->ODR |= (1 << 6);  // Turn on PB6 (LED)
        } else if (temp >= 26 && temp <= 35) {
            GPIOA->ODR |= (1 << 3);  // Turn on PA3 (LED) - Normal range
            GPIOB->ODR |= (1 << 6);  // Turn on PB6 (LED)
        } else if (temp < 25) {
            GPIOA->ODR |= (1 << 4);  // Turn on PA4 (LED) - Slightly above normal
        }
    }

    return 0; // (Never reached)
}
