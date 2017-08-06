#include "includes.h"

/****************************************************************************
	���ܣ�����ȫ�ֱ����������������й��̡�
	0����ʾ�������������幦�ܡ�
	1����ʾ���ӹ��ܡ�
	2����ʾ���еĽ׶Ρ�				
	3����ʾ�����Ƿ��Ѿ���ϴ��0��û����ϴʱ�䡣1������ϴ��û��ϴ��2����ϴ��ɡ�
	4����ʾˮ·�Ƿ�ͨ����0��ͨ����1����ͨ��
	5����ʾ�������Ƿ�������������0���ܡ�1������
	6����ʾ���Ƿ��ڸ��ա�0��������1������
*****************************************************************************/
unsigned char Lcd_DisplayStatus[8]={0,0,0,0,0,0,0,0};

void HaiShen_Display(void)
{
	if(No_DisplayStatus==0)		//��ʾ���ǽ��м�ˮ����ˮ���ԺͲ鿴��������������
	{
		switch(Lcd_DisplayStatus[0])
		{
			case 0	:	Zero_Display();		break;
			case 1	: 	One_Display();		break;
			case 2	: 	Two_Display();		break;
			case 3	: 	Three_Display();	break;
			case 4	: 	Four_Display();		break;
			case 5	: 	Five_Display();		break;
			case 6	: 	Six_Display();		break;
			case 7	: 	Seven_Display();	break;
			case 8	: 	Eight_Display();	break;
			case 9	: 	Nine_Display();		break;
			case 10	: 	Ten_Display();		break;
			case 11	: 	Eleven_Display();	break;
			case 12	: 	Twelve_Display();	break;
			case 13	: 	Thirteen_Display();	break;
			case 14	: 	Fourteen_Display();	break;
			default :						break;
		}
	}
	else   		//��ʾ���м�ˮ���ˮ���Ի�鿴��������������
	{
		switch(No_DisplayStatus)
		{
			case 1	: 	
			case 2	: 	Fifteen_Display();	break;	//��ˮ����ˮ����
			case 3	:	break;

			case 5	:
			case 6	:
			case 7	:	Sixteen_Display();	break;

			default	:						break;
		}
	}		
}
