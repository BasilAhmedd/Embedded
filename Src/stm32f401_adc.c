//#include "STM32f401xx.h"
//#include <stdint.h>  // Add this line
//
//void ADC_EnableClock(void) {
//    RCC->APB2ENR |= (1 << 8); // Enable ADC1 clock
//}
//
//void ADC_Init(void) {
//    ADC_EnableClock();
//
//    // Ensure ADC is disabled before configuration
//    ADC->ADC_CR2 &= ~(1 << 0);
//
//    // 12-bit resolution (default), single conversion mode
//    ADC->ADC_CR1 = 0x00000000;
//
//    // Enable ADC
//    ADC->ADC_CR2 |= (1 << 0);
//
//    // Select Channel 0 (PA0) for conversion
//    ADC->ADC_SQR3 = 0x00000000;
//
//    // Set sampling time to 56 cycles for Channel 0
//    ADC->ADC_SMPR2 |= (3 << 0);
//}
//
//uint16_t ADC_Read(void) {
//    ADC->ADC_CR2 |= (1 << 30);  // Start conversion
//
//    while (!(ADC->ADC_SR & (1 << 1)));  // Wait for conversion to complete
//
//    return (uint16_t) ADC->ADC_DR;  // Read ADC value
//}
