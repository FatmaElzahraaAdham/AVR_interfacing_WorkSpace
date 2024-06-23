///////////////////////master
#include"SPI.h"
#define F_CPU 8000000UL
#include"avr/delay.h"
#include "avr/io.h"
#include"STD_Lib.h"
#include"BIT_Math.h"
#include"DIO.h"
void main(void){
	// pins
	DIO_VidSetPinDirection(DIO_PORTB,DIO_PIN7,DIO_Output);
	DIO_VidSetPinDirection(DIO_PORTB,DIO_PIN6,DIO_Intput);
	DIO_VidSetPinDirection(DIO_PORTB,DIO_PIN5,DIO_Output);
	DIO_VidSetPinDirection(DIO_PORTB,DIO_PIN4,DIO_Output);

	SPI_VidMasterInit();
	while(1){
		_delay_ms(500);
		SPI_U8Transmit('f');
	}

}

