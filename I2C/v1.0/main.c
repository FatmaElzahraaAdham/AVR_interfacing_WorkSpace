#include"DIO.h"
#include"I2C.h"
#include"STD_Lib.h"
#define F_CPU 8000000UL
#include "avr/delay.h"

void main(void){

	TWI_VidMasterInit();




	while(1){
		_delay_ms(500);
		TWI_VidStartCondition();
		TWI_VidSendSlaveAddressToWrite('1');
		TWI_VidMasterSendData('f');
		TWI_VidStopCondition();
	}
}
