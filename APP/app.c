#include "includes.h"

void Task_RunInit(void);		//任务初始化，包括其他任务以及相关参数初始化

OS_STK TASK_KeyScan_Stk[TASK_KeyScan_Stk_Size];
OS_STK TASK_Time_Stk[TASK_Time_Stk_Size];
OS_STK TASK_LcdDisplay_Stk[TASK_LcdDisplay_Stk_Size];
OS_STK TASK_UpdateTime_Stk[TASK_UpdateTime_Stk_Size]; 
OS_STK TASK_WtAndDp_Stk[TASK_WtAndDp_Stk_Size];

void TASK_Master(void *p_arg)
{
	(void)p_arg;

	Task_RunInit();				//任务初始化，包括启动其它相关任务，以及初始化相关参数。
	 	
	while(1)
	{
		Set_Function();
	}
	OS_NO_ERR;
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
		OSSemPend(SemEventSet.Time_Run_Event,0,&err);
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
		OSSemPend(SemEventSet.Lcd_Display_Event,0,&err);
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
		OSSemPend(SemEventSet.Update_Time_Event,0,&err);
		Update_Time();
//		OSTimeDlyHMSM(1,0,0,0);	
	}
}


///***********************************************
//	功能：测试键与功能显示键任务
//***********************************************/
//void TASK_WtAndDp(void *p_arg)
//{
//	unsigned char err;
//	(void)p_arg;
//	for(;;)
//	{
//		OSSemPend(Method_Other_Event,0,&err);
//		LCD_DisplayGB2312(5,1,"进入提示模式");
//		Function_WaterAndDisplay();
//	}
//}

/*
	功能：任务初始化,包括启动其他其他。初始化相关变量。
*/
void Task_RunInit(void)
{
	/*
			启动其他任务。
	*/
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
	
//	OSTaskCreate(TASK_WtAndDp,		    
//				 (void *)0,	
//				 &TASK_WtAndDp_Stk[TASK_WtAndDp_Stk_Size-1],
//				  TASK_WtAndDp_Prio);	    //更新时间线程

	/*
			信号量初始化
	*/				
    SemEventSet.Key_Num_Event = OSSemCreate(0);  
	SemEventSet.Time_Run_Event = OSSemCreate(0);	
	SemEventSet.Lcd_Display_Event = OSSemCreate(0); 	//液晶启动存在显示内容。
	SemEventSet.Update_Time_Event = OSSemCreate(0);
	SemEventSet.Method_Other_Event = OSSemCreate(0);

}


