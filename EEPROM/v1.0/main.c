#include"DIO.h"
#include "EEPROM.h"
#include"I2C.h"
#include"BIT_Math.h"
#include"STD_Lib.h"
#include"avr/io.h"
#include"avr/delay.h"

void main(void){
    u8 x;

	DIO_VidSetPinDirection(DIO_PORTA,DIO_PIN0,DIO_Output);
	TWI_VidMasterInit();
	_delay_ms(100);
	EEPROM_VidWriteData('5','a' );
	_delay_ms(100);
	x=EEPROM_VidReadData('5');
	_delay_ms(100);
	if(x== 'a'){
		//DIO_VidTogglePinValue(DIO_PORTA,DIO_PIN0);
		DIO_VidSetPinValue(DIO_PORTA,DIO_PIN0,DIO_High);
	}

	while(1);
}
