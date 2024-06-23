/*
 * USART.h
 *
 *  Created on: Aug 23, 2023
 *      Author: H P
 */

#ifndef USART_H_
#define USART_H_
#include"STD_Lib.h"
void USART_VidInit(void);
void USART_VidSendChar(u8 Copy_U8Char);
u8 USART_VidGetChar(void);
#endif /* USART_H_ */
