#include "includes.h"

unsigned char Other_Stage=0;		//���ڱ�ʶ��ˮ�Ĳ�ͬ�׶Σ���������ʾ���Ʒ����Ĳ�ͬС����
unsigned char No_DisplayStatus=0;

void Water_Into(void);
void Water_IntoTest(void);

/**
	��Ҫ��ɼ�ˮ����ˮ���Թ����Լ�����������ʾ��
*/

void Function_OtherRun(void)
{	
//	unsigned char err;
//	unsigned time=100;		//10s��ʱ������

//	Other_Stage=0;
//	OSSemPend(Method_Other_Event,0,&err);

//	while((time!=0)&&(No_DisplayStatus!=0))	//10����׼��ʱ��
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
//		case 1:	  	Water_Into();		break;		//��ˮ
//		case 2:		Water_IntoTest();	break;		//��ˮ����
//		case 5:		break;		//����Ϊ��ʾ����������
//		case 6:		break;
//		default:	break;
//	}
}

void Water_Into(void)
{
//	int WaterInTime=180; 			//��ˮʱ��3min
//	Other_Stage=1;					//�����ˮ��һ�׶�,��ˮ����
//	Water_On();		   				//�򿪼�ˮ���أ�
//	OSSemPost(Lcd_Display_Event);	//����Һ����ʾ
////	OSTimeDlyHMSM(0,3,0,0);			//��ˮ������
//	while(WaterInTime>0)
//	{
//		Time_Page = 5;
//		Time_Colum= 1;
//		Time_Num  =WaterInTime;
//		WaterInTime--;
//		OSSemPost(Update_Time_Event);
//	}
//	Other_Stage=2;					//�����ˮ�ڶ��׶Σ���ˮ���
//	OSSemPost(Lcd_Display_Event);
//	OSTimeDlyHMSM(0,0,1,0);
//	No_DisplayStatus=0;		//�ӳ�1s�󣬿��Խ���������ʾ����������������ʾ��
//	Other_Stage=0;
//	OSTimeDlyHMSM(1,0,0,0);	//��ʱ1h�������˻�������ʾ���棬Ҳ�ɲ����в���
//	OSSemPost(Lcd_Display_Event);
}

void Water_IntoTest(void)
{

}
