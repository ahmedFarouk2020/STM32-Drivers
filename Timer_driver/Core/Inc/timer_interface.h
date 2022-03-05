/*
 * timer_interface.h
 *
 *  Created on: Mar 4, 2022
 *      Author: Farouk
 */

#ifndef INC_TIMER_INTERFACE_H_
#define INC_TIMER_INTERFACE_H_





void TIM_Init(void);

uint8 TIM_Status(void);

void TIM_ClrIntFlag(void);

void TIM_EnableEventTrig(void);

void TIM_DisableEventTrig(void);


#endif /* INC_TIMER_INTERFACE_H_ */
