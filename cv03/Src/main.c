/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include "stm32f0xx.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

volatile uint32_t Tick;

//Symbol defs
#define LED_TIME_BLINK 300
#define LED_TIME_SHORT 100
#define LED_TIME_LONG 1000
#define DEBOUNCE_CHECK 5

void EXTI0_1_IRQHandler(void);
void SysTick_Handler(void);
void blikac(void);
void tlacitka(void);

int main(void) {
	RCC->AHBENR |= RCC_AHBENR_GPIOAEN | RCC_AHBENR_GPIOBEN | RCC_AHBENR_GPIOCEN; // enable
	GPIOA->MODER |= GPIO_MODER_MODER4_0; // LED1 = PA4, output
	GPIOB->MODER |= GPIO_MODER_MODER0_0; // LED2 = PB0, output
	GPIOC->PUPDR |= GPIO_PUPDR_PUPDR0_0; // S2 = PC0, pullup
	GPIOC->PUPDR |= GPIO_PUPDR_PUPDR1_0; // S1 = PC1, pullup

	RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN; //hodziny
	SYSCFG->EXTICR[0] |= SYSCFG_EXTICR1_EXTI0_PC; // select PC0 for EXTI0
	EXTI->IMR |= EXTI_IMR_MR0; // mask
	EXTI->FTSR |= EXTI_FTSR_TR0; // trigger on falling edge
	//NVIC_EnableIRQ(EXTI0_1_IRQn); // enable EXTI0_1

	SysTick_Config(8000); // timer 1ms

	/* Loop forever */
	for (;;) {
		tlacitka();
		blikac();
	}
}

void EXTI0_1_IRQHandler(void) {
	if (EXTI->PR & EXTI_PR_PR0) { // check line 0 has triggered the IT
		EXTI->PR |= EXTI_PR_PR0; // clear the pending bit
		GPIOB->ODR ^= (1 << 0);
	}
}

void SysTick_Handler(void) {
	Tick++;
}

void blikac(void) {
	static uint32_t delay;
	if (Tick > delay + LED_TIME_BLINK) {
		GPIOA->ODR ^= (1 << 4);
		delay = Tick;
	}
}

void tlacitka(void) {
	//static uint32_t old_s2;
	static uint32_t old_s1;
	static uint32_t off_time;
	static uint16_t debounce = 0xFFFF;
	static uint32_t debounce_delay;
	uint32_t new_s2 = GPIOC->IDR & (1 << 0);
	uint32_t new_s1 = GPIOC->IDR & (1 << 1);

	/*
	 // roznout LED2
	 if (old_s2 && !new_s2) { // falling edge
	 off_time_s2 = Tick + LED_TIME_SHORT;
	 GPIOB->BSRR = (1<<0);
	 }
	 old_s2 = new_s2;
	 */

	// roznout LED1
	if (old_s1 && !new_s1) { // falling edge
		off_time = Tick + LED_TIME_LONG;
		GPIOB->BSRR = (1 << 0);
	}
	old_s1 = new_s1;

	/*
	 // zhasnout LED2
	 if (Tick > off_time_s2) {
	 GPIOB->BRR = (1<<0);
	 }
	 */

	if (Tick > debounce_delay + 5) {
		debounce <<= 1;
		if (new_s2)
			debounce |= 0x0001;
		if (debounce == 0x7FFF) {
			off_time = Tick + LED_TIME_SHORT;
			GPIOB->BSRR = (1 << 0);
		}
		debounce_delay = Tick;
	}
	// zhasnout LED2
	if (Tick > off_time) {
		GPIOB->BRR = (1 << 0);
	}

}

