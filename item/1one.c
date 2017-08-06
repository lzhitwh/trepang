#include "includes.h"

static void OneBranch_Display(void);
static void TwoBranch_Display(void);
static void ThreeBranch_Display(void);


static void OneOneStage_Display(void);
static void OneTwoStage_Display(void);
static void OneThreeStage_Display(void);
static void OneFourStage_Display(void);
static void OneFiveStage_Display(void);

static void TwoOneStage_Display(void);
static void TwoTwoStage_Display(void);
static void TwoThreeStage_Display(void);
static void TwoFourStage_Display(void);
static void TwoFiveStage_Display(void);

static void ThreeOneStage_Display(void);
static void ThreeTwoStage_Display(void);
static void ThreeThreeStage_Display(void);
static void ThreeFourStage_Display(void);
static void ThreeFiveStage_Display(void);

void One_Display(void)
{
	switch(Lcd_DisplayStatus[1])
	{
		case 1	:	OneBranch_Display();	break;  	//��ͷ����
		case 2	:	TwoBranch_Display();	break;		//��ͷ����
		case 3	:	ThreeBranch_Display();	break;		//Сͷ����
	}
}


static void OneBranch_Display(void)
{
	switch(Lcd_DisplayStatus[2])
	{
		case 1	:	OneOneStage_Display();		break;	 // 20/30�ȴ��׶�
		case 2	:	OneTwoStage_Display();		break;	 //���η��Ƶ�һ�׶�
		case 3	:	OneThreeStage_Display();	break;	 //���η��Ƶڶ��׶�
		case 4	:	OneFourStage_Display();		break;	 //���η��Ƶ����׶�
		case 5	:	OneFiveStage_Display();		break;	 //���η�������ؽ׶�
	}
}
static void TwoBranch_Display(void)
{
	switch(Lcd_DisplayStatus[2])
	{
		case 1	:	TwoOneStage_Display();		break;
		case 2	:	TwoTwoStage_Display();		break;
		case 3	:	TwoThreeStage_Display();	break;
		case 4	:	TwoFourStage_Display();		break;
		case 5	:	TwoFiveStage_Display();		break;
	}
}

static void ThreeBranch_Display(void)
{
	switch(Lcd_DisplayStatus[2])
	{
		case 1	:	ThreeOneStage_Display();	break;
		case 2	:	ThreeTwoStage_Display();	break;
		case 3	:	ThreeThreeStage_Display();	break;
		case 4	:	ThreeFourStage_Display();	break;
		case 5	:	ThreeFiveStage_Display();	break;
	}
}

static void OneOneStage_Display(void)
{
	LCD_Clear();
	LCD_DisplayGB2312(1,1,"��ͨ���η���30");
	LCD_DisplayGB2312(3,1,"һ�ﺣ��40��90ֻ");
	LCD_DisplayGB2312(5,1,"����ͷ�����η���");
	LCD_DisplayGB2312(7,1,"�ٰ���ѡ�����˳�");
}

static void OneTwoStage_Display(void)
{
	LCD_Clear();
	
	//��ˮ������һ��������û�и��ա�
	if((Lcd_DisplayStatus[4]==0)&&(Lcd_DisplayStatus[5]==0)&&(Lcd_DisplayStatus[6]==0))
	{
		switch(Lcd_DisplayStatus[3])
		{
		 	case 0:  //���η��Ƶ�һ�׶Σ�����Ҫ��ϴ�������̣���ˮ����������û�и��ա�	
				LCD_DisplayGB2312(1,1,"��ͨ���ο�ʼ����");
				LCD_DisplayGB2312(3,1,"һ�ﺣ��40��90ֻ");
				LCD_DisplayGB2312(5,1," 8Сʱ����ϴ����");
				LCD_DisplayGB2312(7,1,"68Сʱ���ƽ���");
			break;

			case 1:	 //���η��Ƶ�һ�׶Σ���Ҫ��ϴ����û����ϴ�������̣���ˮ����������û�и��ա�
				LCD_DisplayGB2312(1,1,"����������ϴ����");
				LCD_DisplayGB2312(3,1,"����ͣ����˳���");
				LCD_DisplayGB2312(5,1,"��ϴ��Ѳι��Ż�");
				LCD_DisplayGB2312(7,1,"���ָ������ŷ���");
			break;

			case 2:	 //���η��Ƶ�һ�׶Σ�������ϴ���Σ������̣���ˮ����������û�и��ա�
				LCD_DisplayGB2312(1,1,"��������ͣ��");
				LCD_DisplayGB2312(3,1,"���ڿ�����ϴ����");
				LCD_DisplayGB2312(5,1,"��1Сʱ�ڷŻ�");
				LCD_DisplayGB2312(7,1,"���ָ������ŷ���");
			break;

			case 3:	 //���η��Ƶ�һ�׶Σ�������ϴ��ɣ������̣���ˮ����������û�и��ա�
				LCD_DisplayGB2312(1,1,"�����Ѿ���ϴ���");
				LCD_DisplayGB2312(3,1,"��ͨ���ν��ŷ���");
				LCD_DisplayGB2312(5,1,"һ�ﺣ��40��90ֻ");
				LCD_DisplayGB2312(7,1,"60Сʱ�������");
			break;

			case 4:	//���η��Ƶ�һ�׶Σ���ϴ���̳�ʱ�������̣���ˮ����������û�и��ա�
				LCD_DisplayGB2312(1,1,"��ϴ���γ�ʱ");
				LCD_DisplayGB2312(3,1,"�����Żغ���");
				LCD_DisplayGB2312(5,1,"���ָ�����������");
				LCD_DisplayGB2312(7,1,"12Сʱ��ػ�");
			break;	
		}
		
	}
	//��ˮ��������������������û�и���
	if((Lcd_DisplayStatus[4]==1)&&(Lcd_DisplayStatus[5]==0)&&(Lcd_DisplayStatus[6]==0))
	{
	}
	//���Ȳ�����������ˮ������û�и���
	if((Lcd_DisplayStatus[4]==0)&&(Lcd_DisplayStatus[5]==1)&&(Lcd_DisplayStatus[6]==0))
	{
	
	}
	//��ˮ���Ⱦ�������������
	 if((Lcd_DisplayStatus[4]==0)&&(Lcd_DisplayStatus[5]==0)&&(Lcd_DisplayStatus[6]==1))
	 {
	 
	 }
}
static void OneThreeStage_Display(void)
{

}
static void OneFourStage_Display(void)
{

}
static void OneFiveStage_Display(void)
{
	
}


static void TwoOneStage_Display(void)
{
	LCD_Clear();
	LCD_DisplayGB2312(1,1,"��ͷ���η���30");
	LCD_DisplayGB2312(3,1,"һ�ﺣ������40ֻ");
	LCD_DisplayGB2312(5,1,"����ͷ�����η���");
	LCD_DisplayGB2312(7,1,"�ٰ���ѡ�����˳�"); 
}
static void TwoTwoStage_Display(void)
{

}
static void TwoThreeStage_Display(void)
{

}
static void TwoFourStage_Display(void)
{

}
static void TwoFiveStage_Display(void)
{
	
}


static void ThreeOneStage_Display(void)
{
	LCD_Clear();
	LCD_DisplayGB2312(1,1,"Сͷ���η���30");
	LCD_DisplayGB2312(3,1,"һ�ﺣ�ζ���90ֻ");
	LCD_DisplayGB2312(5,1,"����ͷ�����η���");
	LCD_DisplayGB2312(7,1,"�ٰ���ѡ�����˳�");
}
static void ThreeTwoStage_Display(void)
{
	
}
static void ThreeThreeStage_Display(void)
{

}
static void ThreeFourStage_Display(void)
{

}
static void ThreeFiveStage_Display(void)
{

}



void Device_Test(void)
{
	int temper_now,temper_before;	

	//ǰ�ڽ����������
	Water_On();
	Lcd_DisplayStatus[7]=1;		//���ü�ˮ��־λ����Ҫ���ڼ�ˮʱ����ò����м��ȣ����������
	OSTimeDlyHMSM(0,0,50,0);	
	Water_Off();     			//��ˮ���
	Lcd_DisplayStatus[7]=0;		//��ռ�ˮ��־λ��

	temper_now = DS18B20_GetTemper();//LCD_DisplayNum(3,12,(temper_now/100));LCD_DisplayNum(3,36,temper_now%100);
	HotBig_On();
	OSTimeDlyHMSM(0,0,30,0);
	Hot_Off();		 				 		//�����̼�����ɡ�
	temper_before = temper_now;
	temper_now = DS18B20_GetTemper();
	temper_before = temper_now-temper_before; //ͨ�������¶ȼ��������Ƿ�������

	if(temper_before<16)			//�¶ȱ仯С��1�ȣ������̹�����������
	{
		Lcd_DisplayStatus[5]=1;
	}
	if(temper_before>80)			//�¶ȱ仯����5�ȣ������̸��ա�
	{
		Lcd_DisplayStatus[6]=1;
	}							   
	if(Lcd_DisplayStatus[4]!=0||    //�ж��Ƿ�����쳣�����쳣������Ҫ���½��档
		Lcd_DisplayStatus[5]!=0||Lcd_DisplayStatus[6]!=0)
	{
	 	OSSemPost(Lcd_Display_Event);
	}
}


void Function_OneRun(void)
{
    int temper_now,temper_before;
	Device_Test();
	do{	//���������ϣ���ʽ���뷢��
		switch(Lcd_DisplayStatus[2])
		{
		 	case 2:		//���η��Ƶ�һ�׶�
			case 3:	 	//���η��Ƶڶ��׶�
			case 4:		//���η��Ƶ����׶�
			case 5:		//���η�����ؽ׶�
				while(Lcd_DisplayStatus[2]==2)	//���η��Ƶ�һ�׶�
				{
					temper_now = DS18B20_GetTemper();
					if((temper_now<Haishen_OneStageTemLow)&&(Lcd_DisplayStatus[7]==0))	//�¶ȵ���40��,�Ҳ��ڼ�ˮ
					{
						HotBig_On();
						OSTimeDlyHMSM(0,2,0,0); //����2���Ӻ��ڼ���¶ȡ�	
					}
					if(temper_now>Haishen_OneStageTemHight)
					{
						Hot_Off();
						OSTimeDlyHMSM(0,3,0,0);//ֹͣ���Ⱥ���ȴ3���Ӻ��ټ��
					} 
					OSTimeDlyHMSM(0,0,30,0);	//��ʱ30s���һ�Ρ�
				}
				while(Lcd_DisplayStatus[2]==3) //���η��Ƶڶ��׶�
				{
				
				}
				while(Lcd_DisplayStatus[2]==4) //���η��Ƶ����׶�
				{
				
				}
				while(Lcd_DisplayStatus[2]==5) //���η�����ؽ׶�
				{
				
				}
			break;

			default:break;	//�������
		}
	}while(Lcd_DisplayStatus[0]==1);
	
}
