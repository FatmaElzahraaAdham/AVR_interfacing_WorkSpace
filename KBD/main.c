
#include"DIO.h"
#include"SEV_SEG.h"
#include"KBD.h"

#define F_CPU 8000000UL
#include"avr/delay.h"

void main(void)
{
	u8 Local_U8Key ;
	KBD_VidInit();
	SEV_SEG_VidInit();



	while(1)
	{
		Local_U8Key = KBD_U8GetPressedKey();
		if( Local_U8Key != 20 )
		{


			switch(Local_U8Key)
			{
				case '0' :
					SEV_SEG_VidSetNumber(SEV_SEG_ZERO);
					break;

				case '1' :
					SEV_SEG_VidSetNumber(SEV_SEG_ONE);
										break;
				default :
					SEV_SEG_VidSetNumber(SEV_SEG_FOUR);
			}

		}
	}
}


