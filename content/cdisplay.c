#include "includes.h"

/****************************************************************************
	功能：定义全局变量作用于整个运行过程。
	0：标示按键，决定主体功能。
	1：标示附加功能。
	2：标示进行的阶段。				
	3：标示海参是否已经清洗。0：没到清洗时间。1：该清洗但没清洗。2：清洗完成。
	4：标示水路是否通畅。0：通畅。1：不通畅
	5：标示电热盘是否能正常工作。0：能。1：不能
	6：标示锅是否在干烧。0：正常。1：干烧
*****************************************************************************/
unsigned char Lcd_DisplayStatus[8]={0,0,0,0,0,0,0,0};

void HaiShen_Display(void)
{
	if(No_DisplayStatus==0)		//表示不是进行加水，加水测试和查看制作方法操作。
	{
		switch(Lcd_DisplayStatus[0])
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
	}
	else   		//表示进行加水或加水测试或查看制作方法操作。
	{
		switch(No_DisplayStatus)
		{
			case 1	: 	
			case 2	: 	Fifteen_Display();	break;	//加水，加水测试
			case 3	:	break;

			case 5	:
			case 6	:
			case 7	:	Sixteen_Display();	break;

			default	:						break;
		}
	}		
}
