#include"avr/io.h"
#include"RTOS.h"
#include "DIO.h"

void LED1(void){
	DIO_VidTogglePinValue(DIO_PORTA,DIO_PIN0);
}
void LED2(void){
	DIO_VidTogglePinValue(DIO_PORTB,DIO_PIN0);
}
void LED3(void){
	DIO_VidTogglePinValue(DIO_PORTC,DIO_PIN0);
}
void main(void){
	DIO_VidSetPinDirection(DIO_PORTA,DIO_PIN0,DIO_Output);
	DIO_VidSetPinValue(DIO_PORTA,DIO_PIN0,DIO_Low);
	DIO_VidSetPinDirection(DIO_PORTB,DIO_PIN0,DIO_Output);
	DIO_VidSetPinValue(DIO_PORTB,DIO_PIN0,DIO_Low);
	DIO_VidSetPinDirection(DIO_PORTD,DIO_PIN0,DIO_Output);
	DIO_VidSetPinValue(DIO_PORTD,DIO_PIN0,DIO_Low);

	RTOS_CreateTask(LED1,1000,0);
	RTOS_CreateTask(LED2,1000,0);
	RTOS_CreateTask(LED3,1000,0);
	RTOS_StartOS(Scheduler);
	while(1);

}
