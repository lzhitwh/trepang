#include "includes.h"

void Run_NotMaster(void);		//�����߳���������

OS_STK TASK_KeyScan_Stk[TASK_KeyScan_Stk_Size];
OS_STK TASK_Time_Stk[TASK_Time_Stk_Size];
OS_STK TASK_LcdDisplay_Stk[TASK_LcdDisplay_Stk_Size];
OS_STK TASK_UpdateTime_Stk[TASK_UpdateTime_Stk_Size]; 
OS_STK TASK_WtAndDp_Stk[TASK_WtAndDp_Stk_Size];

OS_EVENT *Usart_Rec_Event;  	//���崮�ڽ����ź���
OS_EVENT *Key_Num_Event;  		//���尴���ź���
OS_EVENT *Time_Run_Event;		//����ʱ�������ź���������ָʾ����ʱ��ĺ���
OS_EVENT *Lcd_Display_Event;  	//����Һ����ʾ�ź���
OS_EVENT *Update_Time_Event;	//��̬����ʱ���ź���
OS_EVENT *Method_Other_Event;	//��ˮ�����ź���

void TASK_Master(void *p_arg)
{
	(void)p_arg;

	Run_NotMaster();	//���������̣߳���Ҫ����Һ����ʾ�߳��밴������߳�
	 	
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
	���ܣ����Լ��빦����ʾ������
***********************************************/
void TASK_WtAndDp(void *p_arg)
{
	unsigned char err;
	(void)p_arg;
	for(;;)
	{
		OSSemPend(Method_Other_Event,0,&err);
		LCD_DisplayGB2312(5,1,"������ʾģʽ");
		Function_WaterAndDisplay();
	}
}


/*
	���ܣ�����ǰ׼������,�����������������̡߳���ʼ����ر�����
*/
void Run_NotMaster(void)
{
	OSTaskCreate(TASK_KeyScan,
		         (void *)0,
	              &TASK_KeyScan_Stk[TASK_KeyScan_Stk_Size-1],
				  TASK_KeyScan_Prio);  		//���������߳�
	OSTaskCreate(TASK_Time,
				 (void *)0,
				 &TASK_Time_Stk[TASK_Time_Stk_Size-1],
				  TASK_Time_Prio);
	OSTaskCreate(TASK_LcdDisplay,
		         (void *)0,
	              &TASK_LcdDisplay_Stk[TASK_LcdDisplay_Stk_Size-1],
				  TASK_LcdDisplay_Prio);  	//Һ����ʾ�߳�
	OSTaskCreate(TASK_UpdateTime,		    
				 (void *)0,
				 &TASK_UpdateTime_Stk[TASK_UpdateTime_Stk_Size-1],
				  TASK_UpdateTime_Prio);	//����ʱ���߳�
	
	OSTaskCreate(TASK_WtAndDp,		    
				 (void *)0,	
				 &TASK_WtAndDp_Stk[TASK_WtAndDp_Stk_Size-1],
				  TASK_WtAndDp_Prio);	//����ʱ���߳�

    Key_Num_Event = OSSemCreate(0);  
	Time_Run_Event = OSSemCreate(0);	
	Lcd_Display_Event = OSSemCreate(1);
	Update_Time_Event = OSSemCreate(0);
	Method_Other_Event = OSSemCreate(0);	
}
