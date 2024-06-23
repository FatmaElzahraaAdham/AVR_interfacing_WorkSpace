#include"DIO.h"
#include"I2C.h"
#include"STD_Lib.h"
#define F_CPU 8000000UL
#include "avr/delay.h"

void main(void){

	u8 x;
	TWI_VidSlaveInit('1');
	DIO_VidSetPinDirection(DIO_PORTA,DIO_PIN0,DIO_Output);



	while(1){
		_delay_ms(505);
		x=TWI_VidSlaveRecieveData();
		if(x=='f'){
			DIO_VidTogglePinValue(DIO_PORTA,DIO_PIN0);
		}

	}
}
