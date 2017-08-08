#include "includes.h"

unsigned char Other_Stage=0;		//用于标识加水的不同阶段，或者是显示发制方法的不同小屏。
unsigned char No_DisplayStatus=0;

void Water_Into(void);
void Water_IntoTest(void);

/**
	主要完成加水，加水测试功能以及制作方法显示。
*/

void Function_OtherRun(void)
{	
//	unsigned char err;
//	unsigned time=100;		//10s延时函数。

//	Other_Stage=0;
//	OSSemPend(Method_Other_Event,0,&err);

//	while((time!=0)&&(No_DisplayStatus!=0))	//10秒钟准备时间
//	{
//		if(time%10==0)
//		{
//			Time_Page=3;
//			Time_Colum=1;
//			Time_Num=time/10;
//			OSSemPost(Update_Time_Event);
//		}
//		time--;
//		OSTimeDlyHMSM(0,0,0,100);
//			
//	}

//	switch(No_DisplayStatus)
//	{
//		case 1:	  	Water_Into();		break;		//加水
//		case 2:		Water_IntoTest();	break;		//加水测试
//		case 5:		break;		//以下为显示制作方法。
//		case 6:		break;
//		default:	break;
//	}
}

void Water_Into(void)
{
//	int WaterInTime=180; 			//加水时间3min
//	Other_Stage=1;					//进入加水第一阶段,加水操作
//	Water_On();		   				//打开加水开关，
//	OSSemPost(Lcd_Display_Event);	//更新液晶提示
////	OSTimeDlyHMSM(0,3,0,0);			//加水三分钟
//	while(WaterInTime>0)
//	{
//		Time_Page = 5;
//		Time_Colum= 1;
//		Time_Num  =WaterInTime;
//		WaterInTime--;
//		OSSemPost(Update_Time_Event);
//	}
//	Other_Stage=2;					//进入加水第二阶段，加水完成
//	OSSemPost(Lcd_Display_Event);
//	OSTimeDlyHMSM(0,0,1,0);
//	No_DisplayStatus=0;		//延迟1s后，可以进行正常显示。但不主动更换显示。
//	Other_Stage=0;
//	OSTimeDlyHMSM(1,0,0,0);	//延时1h后主动退回正常显示界面，也可不进行操作
//	OSSemPost(Lcd_Display_Event);
}

void Water_IntoTest(void)
{

}
