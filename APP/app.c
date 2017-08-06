#include "includes.h"

void Run_NotMaster(void);		//非主线程启动函数

OS_STK TASK_KeyScan_Stk[TASK_KeyScan_Stk_Size];
OS_STK TASK_Time_Stk[TASK_Time_Stk_Size];
OS_STK TASK_LcdDisplay_Stk[TASK_LcdDisplay_Stk_Size];
OS_STK TASK_UpdateTime_Stk[TASK_UpdateTime_Stk_Size]; 
OS_STK TASK_WtAndDp_Stk[TASK_WtAndDp_Stk_Size];

OS_EVENT *Usart_Rec_Event;  	//定义串口接收信号量
OS_EVENT *Key_Num_Event;  		//定义按键信号量
OS_EVENT *Time_Run_Event;		//定义时间运行信号量，启动指示运行时间的函数
OS_EVENT *Lcd_Display_Event;  	//定义液晶显示信号量
OS_EVENT *Update_Time_Event;	//动态更新时间信号量
OS_EVENT *Method_Other_Event;	//加水测试信号量

void TASK_Master(void *p_arg)
{
	(void)p_arg;

	Run_NotMaster();	//启动其他线程，主要包括液晶显示线程与按键检测线程
	 	
	while(1)
	{
		Set_Function();
	}
}

void TASK_KeyScan(void *p_arg)
{
	(void)p_arg;	
	while(1)
	{
		Key_RunTime();
//		OSTimeDlyHMSM(1,0,0,0);
	}
}

void TASK_Time(void *p_arg)
{
	unsigned char err;
	(void)p_arg;
	while(1)
	{
		OSSemPend(Time_Run_Event,0,&err);
		Time_RunMuch();
//		OSTimeDlyHMSM(1,0,0,0);
	}
}

void TASK_LcdDisplay(void *p_arg)
{
	unsigned char err;
	(void)p_arg;
	while(1)
	{
		OSSemPend(Lcd_Display_Event,0,&err);
		HaiShen_Display();
//		OSTimeDlyHMSM(1,0,0,0);
	}
}

void TASK_UpdateTime(void *p_arg)
{
	unsigned char err;
	(void)p_arg;
	while(1)
	{
		OSSemPend(Update_Time_Event,0,&err);
		Update_Time();
//		OSTimeDlyHMSM(1,0,0,0);	
	}
}


/***********************************************
	功能：测试键与功能显示键任务
***********************************************/
void TASK_WtAndDp(void *p_arg)
{
	unsigned char err;
	(void)p_arg;
	for(;;)
	{
		OSSemPend(Method_Other_Event,0,&err);
		LCD_DisplayGB2312(5,1,"进入提示模式");
		Function_WaterAndDisplay();
	}
}


/*
	功能：运行前准备工作,包括启动其他其他线程。初始化相关变量。
*/
void Run_NotMaster(void)
{
	OSTaskCreate(TASK_KeyScan,
		         (void *)0,
	              &TASK_KeyScan_Stk[TASK_KeyScan_Stk_Size-1],
				  TASK_KeyScan_Prio);  		//按键功能线程
	OSTaskCreate(TASK_Time,
				 (void *)0,
				 &TASK_Time_Stk[TASK_Time_Stk_Size-1],
				  TASK_Time_Prio);
	OSTaskCreate(TASK_LcdDisplay,
		         (void *)0,
	              &TASK_LcdDisplay_Stk[TASK_LcdDisplay_Stk_Size-1],
				  TASK_LcdDisplay_Prio);  	//液晶显示线程
	OSTaskCreate(TASK_UpdateTime,		    
				 (void *)0,
				 &TASK_UpdateTime_Stk[TASK_UpdateTime_Stk_Size-1],
				  TASK_UpdateTime_Prio);	//更新时间线程
	
	OSTaskCreate(TASK_WtAndDp,		    
				 (void *)0,	
				 &TASK_WtAndDp_Stk[TASK_WtAndDp_Stk_Size-1],
				  TASK_WtAndDp_Prio);	//更新时间线程

    Key_Num_Event = OSSemCreate(0);  
	Time_Run_Event = OSSemCreate(0);	
	Lcd_Display_Event = OSSemCreate(1);
	Update_Time_Event = OSSemCreate(0);
	Method_Other_Event = OSSemCreate(0);	
}
