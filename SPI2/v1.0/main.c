///////////////////////master
#include"SPI.h"
#define F_CPU 8000000UL
#include"avr/delay.h"
#include "avr/io.h"
#include"STD_Lib.h"
#include"BIT_Math.h"
#include"DIO.h"
void main(void){
	u8 x;
	// pins
	DIO_VidSetPinDirection(DIO_PORTB,DIO_PIN7,DIO_Intput);
	DIO_VidSetPinDirection(DIO_PORTB,DIO_PIN6,DIO_Output);
	DIO_VidSetPinDirection(DIO_PORTB,DIO_PIN5,DIO_Intput);
	DIO_VidSetPinDirection(DIO_PORTB,DIO_PIN4,DIO_Intput);

	DIO_VidSetPinDirection(DIO_PORTA,DIO_PIN0,DIO_Output);

	SPI_VidSlaveInit();
	while(1){
		_delay_ms(505);
		x=SPI_U8Recieve();
		if(x=='f'){
			//DIO_VidSetPinValue(DIO_PORTA,DIO_PIN0,DIO_High);
			DIO_VidTogglePinValue(DIO_PORTA,DIO_PIN0);
		}
	}

}

