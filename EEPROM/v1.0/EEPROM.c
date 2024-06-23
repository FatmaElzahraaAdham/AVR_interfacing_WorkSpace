


#include "EEPROM.h"
#include"I2C.h"
#include"BIT_Math.h"
#include"STD_Lib.h"
#include"avr/io.h"
#include"avr/delay.h"


u8 EEPROM_VidReadData(u16 Copy_U16Address){
	u8 Data;
	//start condition
		TWI_VidStartCondition();
		//send address
		TWI_VidSendSlaveAddressToWrite(0x50 | (0 << 2) | (Copy_U16Address>>8));
		TWI_VidMasterSendData((u8)Copy_U16Address);
		//start condition
		TWI_VidStartCondition();
		TWI_VidSendSlaveAddressToREAD(0x50 | (0 << 2) | (Copy_U16Address>>8));
		//send data
		Data=TWI_VidMasterRecieveData();
		//stop condition
		TWI_VidStopCondition();

		return Data;
}

void EEPROM_VidWriteData(u16 Copy_U16Address, u8 Copy_U8Data){
	//start condition
	TWI_VidStartCondition();
	//send address
	TWI_VidSendSlaveAddressToWrite(0x50 | (0 << 2) | (Copy_U16Address>>8));
	TWI_VidMasterSendData((u8)Copy_U16Address);
	//send data
	TWI_VidMasterSendData(Copy_U8Data);
		//stop condition
		TWI_VidStopCondition();
		_delay_ms(10);

}
