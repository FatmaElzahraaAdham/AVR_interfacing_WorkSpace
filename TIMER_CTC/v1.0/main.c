

#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"Timers.h"
#include"DIO.h"
#include"avr/interrupt.h"


void TOGGLE_LED(void);

void main(void)
{
	DIO_VidSetPinDirection( DIO_PORTA , DIO_PIN0 , DIO_Output );
	Timers_VidTimer0SetCallBack(&TOGGLE_LED);
	Timers_VidTimer0Init();


	while(1);
}


void TOGGLE_LED(void)
{
	DIO_VidTogglePinValue(DIO_PORTA, DIO_PIN0);
}











