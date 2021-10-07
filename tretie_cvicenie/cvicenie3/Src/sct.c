/*
 * sct.c
 *
 *  Created on: Oct 7, 2021
 *      Author: student
 */

#include "sct.h"
#include "stm32f0xx.h"

#define sct_nla(x) do { if (x) GPIOB->BSRR = (1 << 5); else GPIOB->BRR = (1 << 5); } while (0)
#define sct_nla(x) do { if (x) GPIOB->BSRR = (1 << 4); else GPIOB->BRR = (1 << 4); } while (0)
#define sct_nla(x) do { if (x) GPIOB->BSRR = (1 << 3); else GPIOB->BRR = (1 << 3); } while (0)
#define sct_nla(x) do { if (x) GPIOB->BSRR = (1 << 10); else GPIOB->BRR = (1 << 10); } while (0)


void sct_led(uint32_t value)
{
	for (uint8_t j=0; j<32; j++)
	{
		sct_sdi(value & 1);
		value>>=1;
		sct_clk(1);
		sct_clk(0);
	}
	sct_nla(1);
	sct_nla(0);
}
void sct_init(void)
{
	RCC_AHBENR_GPIOB |= RCC_AHBENR_GPIOBEN;
	GPIO->MODER |= (1 << 5) | (1 << 4) | (1 << 3) |(1 << 10 );
}

void sct_init(void)
{

}


