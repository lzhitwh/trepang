#include "includes.h"

unsigned char Time_Page,Time_Colum,Time_Num; //全局变量。用于标记更新时间的位置，数值


static void OneOneStage(void);		//普通海参发制第一阶段
static void OneTwoStage(void);		//普通海参发制第二阶段
static void OneThreeStage(void);	//普通海参发制第三阶段

void Update_Time(void)
{
	unsigned char display_data[3];

	display_data[2]=Time_Num%10+'0';
	display_data[1]=(Time_Num%100)/10+'0';
	if(Time_Num<100)
	{
		LCD_DisplayGB2312(Time_Page,Time_Colum,&display_data[1]);
	}
	else
	{
		display_data[0]=Time_Num/100+'0';
		LCD_DisplayGB2312(Time_Page,Time_Colum,display_data);
	}		
}

/***********************************************************************
		功能：用于标记时间，对过程进行控制。
			  由Time_Run_Event事件唤醒。
***********************************************************************/
void Time_RunMuch(void)
{
	switch(Lcd_DisplayStatus[0])
	{
		case 1	:	//普通海参发制
			switch(Lcd_DisplayStatus[1])
			{
				case 1:		//中等海参发制
					OneOneStage();	
				break;
				case 2:		//大头海参发制
				break;
				case 3:		//小头海参发制
				break;
			}	
		break;
		case 2	:		OSTimeDlyHMSM(1,0,0,0);		break;
		case 3	:		OSTimeDlyHMSM(1,0,0,0);		break;
		case 4	:		OSTimeDlyHMSM(1,0,0,0);		break;
		case 5	:		OSTimeDlyHMSM(1,0,0,0);		break;
		case 6	:		OSTimeDlyHMSM(1,0,0,0);		break;
		case 7	:		OSTimeDlyHMSM(1,0,0,0);		break;
		case 8	:		OSTimeDlyHMSM(1,0,0,0);		break;
		case 9	:		OSTimeDlyHMSM(1,0,0,0);		break;
		case 10	:		OSTimeDlyHMSM(1,0,0,0);		break;
		case 11	:		OSTimeDlyHMSM(1,0,0,0);		break;
		case 12	:		OSTimeDlyHMSM(1,0,0,0);		break;
		case 13	:		OSTimeDlyHMSM(1,0,0,0);		break;
		case 14	:		OSTimeDlyHMSM(1,0,0,0);		break;
	}
}

//普通海参发制第一阶段
static void OneOneStage(void)
{
	OSTimeDlyHMSM(5,0,0,0);			//延时5h,换水

	Water_On();						//打开换水,第一次换水。
	OSTimeDlyHMSM(0,3,0,0);			//延时换水时间
	Water_Off();					//关闭换水

	OSTimeDlyHMSM(3,0,0,0);			//延时3h到达海参清洗时间。
	Lcd_DisplayStatus[3]=1;			//设置清洗标志位，标示海参需要清洗
	OSSemPost(Lcd_Display_Event);	//发出更新液晶屏信号量。

	OSTimeDlyHMSM(2,0,0,0);			//延时2h，换水
	Water_On();						//打开换水,第二次换水。
	OSTimeDlyHMSM(0,3,0,0);			//延时换水时间
	Water_Off();				    //关闭换水

	OSTimeDlyHMSM(5,0,0,0);			//延时5h，换水
	Water_On();						//打开换水,第三次换水。
	OSTimeDlyHMSM(0,3,0,0);			//延时换水时间
	Water_Off();				    //关闭换水

	OSTimeDlyHMSM(5,0,0,0);			//延时1h,进入第二阶段	
}
//普通海参发制第二阶段
static void OneTwoStage(void)
{
	Operation_TheAction = 1;		//开启第一次煮制。		
	OSTimeDlyHMSM(12,0,0,0);		//煮制两次，时间间隔12h
	Operation_TheAction = 2;		//开启第二次煮制。
	OSTimeDlyHMSM(12,0,0,0);	
}
//普通海参发制第三阶段
static void OneThreeStage(void)
{
	
}
