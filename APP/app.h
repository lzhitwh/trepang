#ifndef	_APP_H_
#define	_APP_H_

//extern OS_EVENT *Usart_Rec_Event;		//���崮�ڽ����ź���
//extern OS_EVENT *Key_Num_Event;  		//���尴���ź���
//extern OS_EVENT *Time_Run_Event;		//����ʱ�������ź���������ָʾ����ʱ��ĺ���
//extern OS_EVENT *Lcd_Display_Event;  	//����Һ����ʾ�ź���
//extern OS_EVENT *Update_Time_Event;		//��̬����ʱ���ź���
//extern OS_EVENT *Method_Other_Event;	//��ˮ���ԡ�������ʾ�ź���


/**************** �û��������� *******************/
void TASK_Master(void *p_arg);
void TASK_LcdDisplay(void *p_arg);  
void TASK_KeyScan(void *p_arg);

#endif
