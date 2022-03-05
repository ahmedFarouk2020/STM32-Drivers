//#include "STD_TYPES.h"
//#include "GPIO_Interface.h"
//#include "timer_interface.h"
#include "stm32f401xc.h"


int data = 0;

int main()
{
//
//	GPIO_EnableClk(PORTA);
//	GPIO_Init(PORTA, PIN0, OUTPUT_PUSHPULL);
//
//	TIM_Init();
	//TIM_EnableEventTrig();

	NVIC->ISER[(((uint32_t)28) >> 5UL)] = (uint32_t)(1UL << (((uint32_t)28) & 0x1FUL));

	//NVIC_EnableIRQ(TIM2_IRQn);
	RCC -> APB1ENR |= RCC_APB1ENR_TIM2EN;
	//RCC -> APB2ENR |= RCC_APB2ENR_TIM1EN;
	RCC -> AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

	GPIOA->MODER = 1;
	GPIOA->ODR = 0;

	TIM2->DIER |= TIM_DIER_UIE;
	TIM2-> ARR = (int)0xff0;
	TIM2-> PSC = 100;
	TIM2->SR = 0;

	TIM2-> CR1 |= 1;



	while(1)
	{

//		if( TIM_Status() == 1) {
//			GPIO_WritePin(0, 0, 1);
//			TIM_ClrIntFlag();
//		}
//		if( (TIM2->SR & 1) == 1) {
//			data = (1^data);
//			GPIOA ->ODR = data & 1;
//
//			TIM2->SR &= ~(1<<0); // clear flag
//		}
		GPIOA ->ODR = data ;
	}

	return 0;
}


//void TIM2_IRQHandler(void)
//{
////	static uint8 data = 1;
////	data ^= 1;
////	GPIO_WritePin(PORTA, PIN0, (data & 1));
////	GPIOA ->ODR = 1;
//
//	data = (1^data);
//	GPIOA ->ODR = 1;//data & 1;
//	TIM2->SR &= ~(0b01000001<<0); // clear flag
//	TIM2->SR = ~TIM_SR_UIF;
//}

void TIM2_IRQHandler(void) {
    TIM2->SR = 0;
    data = (1 ^ data) & 1;
}
