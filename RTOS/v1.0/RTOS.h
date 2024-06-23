/*
 * RTOS.h
 *
 *  Created on: Aug 31, 2023
 *      Author: H P
 */

#ifndef RTOS_H_
#define RTOS_H_
#include"STD_Lib.h"
void RTOS_Start0S(void (*Timer0_Ptr)(void));
void RTOS_CreateTask(void (*Timer0_Ptr)(void), u16 A_Periodicity,u8 A_priority);
void Scheduler(void);


#endif /* RTOS_H_ */
