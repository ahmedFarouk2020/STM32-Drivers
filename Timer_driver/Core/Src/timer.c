/*
 * timer.c
 *
 *  Created on: Mar 4, 2022
 *      Author: Farouk
 */

#include "STD_TYPES.h"

#include "timer_interface.h"
#include "timer_private.h"
#include "timer_config.h"


#define TIM2_INTERRPT_ID 28


void TIM_Init(void)
{
	RCC_APB1ENR |= 1; // enable timer2 clk

	TIM_EnableNVICInterrupt(TIM2_INTERRPT_ID,0);

	// set prescaler
	TIM2_PSC = PRESCALER;

//	TIM2_CNT = (uint32)0xfff;

	// timer mode (edge-aligned count-up mode)
	TIM2_CR1 = 1;//(TIM_MODE | TIM_START | EVENT_SRC);

}


uint8 TIM_Status(void)
{
	return (TIM2_SR & 1);
}

void TIM_ClrIntFlag(void)
{
	TIM2_SR &= ~(1<<0);
}

void TIM_EnableEventTrig(void)
{
	// enable event trigger sources
	TIM2_CR1 &= ~0x02;

}


void TIM_disableEventTrig(void)
{
	// disable event trigger sources
	TIM2_CR1 |= 0x02;
}



/**************************************************/
/*************   PRIVATE FUNCTIONS   **************/
/**************************************************/




/******* Enable global interrupt key from NVIC with interrupt ID
 * args:
 * 		interrupt_id(uint8): interrupt id in datasheet
 *
 * 		set_id(uint8): index of register contains this interrupt (NVIC_ISER0 -> 0)
 *
 * return: void
 */

void TIM_EnableNVICInterrupt(unsigned char interrupt_id, unsigned char set_id)
{
	switch(set_id)
	{
		case 0:
			NVIC_ISER0 |= (1<< (interrupt_id-32*set_id));
			break;
		case 1:
			NVIC_ISER1 |= (1<< (interrupt_id-32*set_id));
			break;
		case 2:
			NVIC_ISER2 |= (1<< (interrupt_id-32*set_id));
			break;
	}

}

void TIM_DisableNVICInterrupt(unsigned char interrupt_id, unsigned char set_id)
{
	switch(set_id)
	{
		case 0:
			NVIC_ICER0 |= (1<< (interrupt_id-32*set_id));
			break;
		case 1:
			NVIC_ICER1 |= (1<< (interrupt_id-32*set_id));
			break;
		case 2:
			NVIC_ICER2 |= (1<< (interrupt_id-32*set_id));
			break;
	}
}

