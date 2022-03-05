/*
 * timer_config.h
 *
 *  Created on: Mar 4, 2022
 *      Author: Farouk
 */

#ifndef INC_TIMER_CONFIG_H_
#define INC_TIMER_CONFIG_H_

/*
 * center-aligned count-up = 0
 */
#define TIM_MODE 	0

#define PRESCALER   1000UL
/*
 * OVER_UNDER_FLOW , ALL_SRCS
 */
#define OVER_UNDER_FLOW  0x04
#define ALL_SRCS		 0x00
#define EVENT_SRC	OVER_UNDER_FLOW

#endif /* INC_TIMER_CONFIG_H_ */
