#include "DIO.h"
#include"avr/interrupt.h"
#include"EX_INT.h"

void TOGGLE_LED1(){


		DIO_VidTogglePinValue(DIO_PORTA,DIO_PIN0);



}
void TOGGLE_LED2(){


		DIO_VidTogglePinValue(DIO_PORTA,DIO_PIN1);



}

void main(void){



	DIO_VidSetPinDirection(DIO_PORTA,DIO_PIN0,DIO_Output);
	DIO_VidSetPinValue(DIO_PORTA,DIO_PIN0,DIO_Low);

	DIO_VidSetPinDirection(DIO_PORTD,DIO_PIN2,DIO_Intput);
	DIO_VidSetPinValue(DIO_PORTD,DIO_PIN2,DIO_High);
	EX_INT0VidInit();
	EX_INT0VidSetCallBack(&TOGGLE_LED1);




	DIO_VidSetPinDirection(DIO_PORTA,DIO_PIN1,DIO_Output);
	DIO_VidSetPinValue(DIO_PORTA,DIO_PIN1,DIO_Low);

	DIO_VidSetPinDirection(DIO_PORTD,DIO_PIN3,DIO_Intput);
	DIO_VidSetPinValue(DIO_PORTD,DIO_PIN3,DIO_High);
	EX_INT1VidInit();
	EX_INT1VidSetCallBack(&TOGGLE_LED2);

	while(1);

}




