

#include"STD_Lib.h"
#include"BIT_MATH.h"
#include"avr/io.h"
#include"Timers.h"
#include"DIO.h"
#include"avr/interrupt.h"

void main (void){


	DIO_VidSetPinDirection( DIO_PORTD , DIO_PIN5 , DIO_Output );
	Timer_VidTimer1Init();
	while(1);
}







