/*
 * EEPROM.h
 *
 *  Created on: Aug 26, 2023
 *      Author: H P
 */

#ifndef EEPROM_H_
#define EEPROM_H_

#include "EEPROM.h"
#include"I2C.h"
#include"BIT_Math.h"
#include"STD_Lib.h"

void EEPROM_VidWriteData(u16 Copy_U16Address, u8 Copy_U8Data);
u8 EEPROM_VidReadData(u16 Copy_U16Address);

#endif /* EEPROM_H_ */
