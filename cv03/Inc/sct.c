/*
 * sct.c
 *
 *  Created on: Oct 12, 2022
 *      Author: xsedla1m
 */

#include <stdint.h>
#include "stm32f0xx.h"
#include "sct.h"

#define sct_sdi(x) do { if (x) GPIOB->BSRR = (1 << 4); else GPIOB->BRR = (1 << 4); } while (0)
#define sct_clk(x) do { if (x) GPIOB->BSRR = (1 << 3); else GPIOB->BRR = (1 << 3); } while (0)
#define sct_nla(x) do { if (x) GPIOB->BSRR = (1 << 5); else GPIOB->BRR = (1 << 5); } while (0)
#define sct_noe(x) do { if (x) GPIOB->BSRR = (1 << 10); else GPIOB->BRR = (1 << 10); } while (0)

void sct_led(uint32_t value){
	for(uint32_t i = 0; (i < sizeof(value)*8); i++){
		sct_sdi(value&1);
		sct_clk(1);
		sct_clk(0);
		value>>=1;
	}
	sct_nla(1);
	sct_nla(0);
}

void sct_init(void){
	RCC->AHBENR |= RCC_AHBENR_GPIOBEN; // enable
	GPIOB->MODER |= GPIO_MODER_MODER4_0; // SDI = PB4, output
	GPIOB->MODER |= GPIO_MODER_MODER3_0; // CLK = PB3, output
	GPIOB->MODER |= GPIO_MODER_MODER5_0; // NLA = PB5, output
	GPIOB->MODER |= GPIO_MODER_MODER10_0; // NOE = PB10, output
	sct_led(0);
	sct_noe(0);
}
