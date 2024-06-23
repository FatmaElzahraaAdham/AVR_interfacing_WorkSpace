/*
 * I2C.h
 *
 *  Created on: Aug 26, 2023
 *      Author: H P
 */

#ifndef I2C_H_
#define I2C_H_

#include"STD_Lib.h"

void TWI_VidMasterInit(void);
void TWI_VidStartCondition(void);
void TWI_VidSendSlaveAddressToWrite(u8 Copy_U8SlaveAddress);
void TWI_VidSendSlaveAddressToREAD(u8 Copy_U8SlaveAddress);
void TWI_VidMasterSendData(u8 Copy_U8Data);
u8 TWI_VidMasterRecieveData(void);
void TWI_VidStopCondition(void);

void TWI_VidSlaveInit(u8 Copy_U8SlaveAddress);
void TWI_VidSlaveSendData(u8 Copy_U8Data);
u8 TWI_VidSlaveRecieveData(void);
#endif /* I2C_H_ */
