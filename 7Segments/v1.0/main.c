#include"DIO.h"
#include "sev_seg.h"
int main()
{
	SEV_SEG_VidInit();
	SEV_SEG_VidSetNumber (SEV_SEG_ONE);
	while(1);
}
