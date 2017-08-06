#include "includes.h"

unsigned char Operation_TheAction=0;
void Function_InBefore(void);
void Function_InRun(void);

void Set_Function(void)
{
	Function_InBefore();
//	if(Lcd_DisplayStatus[2]!=0)
//	{
//		Function_InRun();
//	}
	OSTimeDlyHMSM(0,0,0,200);
}


void Function_InBefore(void)
{
	unsigned char rkey,rfunc;  //记录当前按键和小功能。
	unsigned char rtime;
	unsigned char err;

	OSSemPend(Key_Num_Event,0,&err);
	OSSemPost(Lcd_Display_Event);
	if(Lcd_DisplayStatus[2]==1)
	{	
//		OSSemPend(Key_Num_Event,0,&err);
//		OSSemPost(Lcd_Display_Event);
		rkey = Lcd_DisplayStatus[0];
		rfunc = Lcd_DisplayStatus[1];
		rtime=150;

//		LCD_DisplayNum(3,1,rtime);

		do{
			OSTimeDlyHMSM(0,0,0,200);

			if(rtime%5==0)
			{
				Time_Page=1;
				Time_Colum=97;
				Time_Num=rtime/5;
				if(Lcd_DisplayStatus[2] !=1)
					break;
				OSSemPost(Update_Time_Event);
			}
			rtime--;		
		}while((rkey == Lcd_DisplayStatus[0])&&(rfunc == Lcd_DisplayStatus[1])&&(rtime>0));
		if(rtime == 0)
		{
			Lcd_DisplayStatus[2]++;
			OSSemPost(Time_Run_Event);
			OSSemPost(Lcd_Display_Event);

			Function_InRun();	
		}
	}
}

void Function_InRun(void)
{
	switch(Lcd_DisplayStatus[0])
	{
		case 1	:	Function_OneRun();		break;
		case 2	:	break;
		case 3	:	break;
		case 4	:	break;
		case 5	:	break;
		case 6	:	break;
		case 7	:	break;
		case 8	:	break;
		case 9	:	break;
		case 10	:	break;
		case 11	:	break;
		case 12	:	break;
		case 13	:	break;
		case 14	:	break;
		default	:	break;
	}
}

void Function_WaterAndDisplay(void)
{
	switch(No_DisplayStatus)
	{
		case 1 :	LCD_DisplayGB2312(1,1,"加水测试");	break;
		case 2 :	LCD_DisplayGB2312(1,1,"进水阶段");  break;
		case 3 :	break;
		default:	break;	
	}
}
