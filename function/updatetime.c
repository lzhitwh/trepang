#include "includes.h"

unsigned char Time_Page,Time_Colum,Time_Num; //ȫ�ֱ��������ڱ�Ǹ���ʱ���λ�ã���ֵ


static void OneOneStage(void);		//��ͨ���η��Ƶ�һ�׶�
static void OneTwoStage(void);		//��ͨ���η��Ƶڶ��׶�
static void OneThreeStage(void);	//��ͨ���η��Ƶ����׶�

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
		���ܣ����ڱ��ʱ�䣬�Թ��̽��п��ơ�
			  ��Time_Run_Event�¼����ѡ�
***********************************************************************/
void Time_RunMuch(void)
{
	switch(Lcd_DisplayStatus[0])
	{
		case 1	:	//��ͨ���η���
			switch(Lcd_DisplayStatus[1])
			{
				case 1:		//�еȺ��η���
					OneOneStage();	
				break;
				case 2:		//��ͷ���η���
				break;
				case 3:		//Сͷ���η���
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

//��ͨ���η��Ƶ�һ�׶�
static void OneOneStage(void)
{
	OSTimeDlyHMSM(5,0,0,0);			//��ʱ5h,��ˮ

	Water_On();						//�򿪻�ˮ,��һ�λ�ˮ��
	OSTimeDlyHMSM(0,3,0,0);			//��ʱ��ˮʱ��
	Water_Off();					//�رջ�ˮ

	OSTimeDlyHMSM(3,0,0,0);			//��ʱ3h���ﺣ����ϴʱ�䡣
	Lcd_DisplayStatus[3]=1;			//������ϴ��־λ����ʾ������Ҫ��ϴ
	OSSemPost(Lcd_Display_Event);	//��������Һ�����ź�����

	OSTimeDlyHMSM(2,0,0,0);			//��ʱ2h����ˮ
	Water_On();						//�򿪻�ˮ,�ڶ��λ�ˮ��
	OSTimeDlyHMSM(0,3,0,0);			//��ʱ��ˮʱ��
	Water_Off();				    //�رջ�ˮ

	OSTimeDlyHMSM(5,0,0,0);			//��ʱ5h����ˮ
	Water_On();						//�򿪻�ˮ,�����λ�ˮ��
	OSTimeDlyHMSM(0,3,0,0);			//��ʱ��ˮʱ��
	Water_Off();				    //�رջ�ˮ

	OSTimeDlyHMSM(5,0,0,0);			//��ʱ1h,����ڶ��׶�	
}
//��ͨ���η��Ƶڶ��׶�
static void OneTwoStage(void)
{
	Operation_TheAction = 1;		//������һ�����ơ�		
	OSTimeDlyHMSM(12,0,0,0);		//�������Σ�ʱ����12h
	Operation_TheAction = 2;		//�����ڶ������ơ�
	OSTimeDlyHMSM(12,0,0,0);	
}
//��ͨ���η��Ƶ����׶�
static void OneThreeStage(void)
{
	
}
