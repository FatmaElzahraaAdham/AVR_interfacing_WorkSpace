#include "DIO.h"
#include "BIT_Math.h"
#include "STD_Lib.h"
#include"USART.h"
#include "avr/io.h"



void USART_VidInit(void){
	u8 Local_U8UCSRCValue=0b10000000;
		u16 Local_U16BaudValue=51;
		UBRRL=(u8)Local_U16BaudValue;
		UBRRH=(u8)Local_U16BaudValue>>8;
		/* normal speed */
		CLR_BIT(UCSRA,U2X);
		// TX,RX enables
		SET_BIT(UCSRB,TXEN);
		SET_BIT(UCSRB,RXEN);

		//
		CLR_BIT(Local_U8UCSRCValue,UPM0);
		CLR_BIT(Local_U8UCSRCValue,UPM1);


		SET_BIT(Local_U8UCSRCValue,USBS);

		SET_BIT(Local_U8UCSRCValue,UCSZ0);
		SET_BIT(Local_U8UCSRCValue,UCSZ1);
		CLR_BIT(UCSRB,UCSZ2);

		UCSRC=Local_U8UCSRCValue;
}


void USART_VidSendChar(u8 Copy_U8Char){
	while(GET_BIT(UCSRA,UDRE)==0);

	UDR=Copy_U8Char;

}


u8 USART_VidGetChar(void){
	u8 Local_U8CharValue;
	while(GET_BIT(UCSRA,RXC)==0);

	Local_U8CharValue=UDR;
	return Local_U8CharValue;
}
