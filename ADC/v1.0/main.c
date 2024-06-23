#include"STD_Lib.h"
#include"BIT_Math.h"
#define F_CPU 8000000UL
#include "avr/delay.h"

#include"ADC.h"
#include"LCD.h"

void main(void)
{
	ADC_VidInit();
	LCD_VidInit();

	u16 Local_U16DigitalResult , Local_U16AnalogResult ,Local_U16Temp ;


	while(1)
	{
		Local_U16DigitalResult = ADC_U16GetDigitalValue( ADC_CHANNEL_0 );
		// analog = digital * step
		Local_U16AnalogResult =(u16)((Local_U16DigitalResult * 2560UL) / (1024)) ;

		Local_U16Temp = Local_U16AnalogResult / 10 ;

		LCD_VidSendNumber(Local_U16Temp);

		_delay_ms(2000);

		LCD_VidSendCommand(0x01);

		_delay_ms(500);


	}

}
