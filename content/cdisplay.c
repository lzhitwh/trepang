#include "includes.h"

void HaiShen_Display(void)
{
	switch(FuncStatus.funcKey)
	{
		case 0	:	Zero_Display();		break;
		case 1	: 	One_Display();		break;
		case 2	: 	Two_Display();		break;
		case 3	: 	Three_Display();	break;
		case 4	: 	Four_Display();		break;
		case 5	: 	Five_Display();		break;
		case 6	: 	Six_Display();		break;
		case 7	: 	Seven_Display();	break;
		case 8	: 	Eight_Display();	break;
		case 9	: 	Nine_Display();		break;
		case 10	: 	Ten_Display();		break;
		case 11	: 	Eleven_Display();	break;
		case 12	: 	Twelve_Display();	break;
		case 13	: 	Thirteen_Display();	break;
		case 14	: 	Fourteen_Display();	break;
		default :						break;
	}
	LCD_Display();
}
