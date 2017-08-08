#ifndef	_APP_H_
#define	_APP_H_

//extern OS_EVENT *Usart_Rec_Event;		//定义串口接收信号量
//extern OS_EVENT *Key_Num_Event;  		//定义按键信号量
//extern OS_EVENT *Time_Run_Event;		//定义时间运行信号量，启动指示运行时间的函数
//extern OS_EVENT *Lcd_Display_Event;  	//定义液晶显示信号量
//extern OS_EVENT *Update_Time_Event;		//动态更新时间信号量
//extern OS_EVENT *Method_Other_Event;	//加水测试、方法显示信号量


/**************** 用户任务声明 *******************/
void TASK_Master(void *p_arg);
void TASK_LcdDisplay(void *p_arg);  
void TASK_KeyScan(void *p_arg);

#endif
