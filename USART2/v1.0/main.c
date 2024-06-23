#include"USART.h"
#define F_CPU 8000000UL
#include"avr/delay.h"
#include "avr/io.h"
#include"DIO.h"
void main(void){
	u8 x;
	USART_VidInit();
	DIO_VidSetPinDirection(DIO_PORTA,DIO_PIN0,DIO_Output);

	while(1){
		_delay_ms(505);
		x=USART_VidGetChar();
		if(x =='f'){
			DIO_VidTogglePinValue(DIO_PORTA,DIO_PIN0);
		}
	}


}

