#include "includes.h"

void Screen_GPIO_Init(void){
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    GPIO_InitStructure.GPIO_Pin=LCD_SDA|LCD_SCK|LCD_RS| LCD_RST|LCD_CS;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
}

//дָ�LCDģ��
void SCREEN_WriteCommand(int data1)   
{
	char i;
	LCD_CS_L();		//LCDƬѡ��Ч
	LCD_RS_L();		//����ָ��
	for(i=0;i<8;i++)
    {
		LCD_SCK_L();//lcd_sclk=0; 
	
		if(data1&0x80) 
			LCD_SID_H();//lcd_sid=1;
		else LCD_SID_L();//lcd_sid=0;
		LCD_SCK_H();//lcd_sclk=1;
	
	 	data1=data1<<=1;
    }
	LCD_CS_H();//lcd_cs1=1;
}

//д���ݵ�LCDģ��
void SCREEN_WriteData(int data1,char status)
{
	char i;
	
	if(status==0)
	{
		data1=~data1;
	}
	
	LCD_CS_L();
	LCD_RS_H();
	for(i=0;i<8;i++)
	{
		LCD_SCK_L();
		if(data1&0x80) 
			LCD_SID_H();
		else 
			LCD_SID_L();
		LCD_SCK_H();
		data1=data1<<1;
	}
	LCD_CS_H();	
}

//LCDģ���ʼ��
void SCREEN_Init(void)
{
	Screen_GPIO_Init();
	LCD_RST_L();        	//�͵�ƽ��λ
	LCD_RST_H();	    	//��λ���   
	SCREEN_WriteCommand(0xe2);	 //��λ
	SCREEN_WriteCommand(0x2c);  //��ѹ����1
	SCREEN_WriteCommand(0x2e);  //��ѹ����2
	SCREEN_WriteCommand(0x2f);  //��ѹ����3
	SCREEN_WriteCommand(0x23);  //�ֵ��Աȶȣ������÷�Χ0x20��0x27
	SCREEN_WriteCommand(0x81);  //΢���Աȶ�
	SCREEN_WriteCommand(0x30);  //΢���Աȶȵ�ֵ�������÷�Χ0x00��0x3f
	SCREEN_WriteCommand(0xa2);  //1/9ƫѹ�ȣ�bias��
	SCREEN_WriteCommand(0xc8);  //��ɨ��˳�򣺴��ϵ���
	SCREEN_WriteCommand(0xa0);  //��ɨ��˳�򣺴�����
	SCREEN_WriteCommand(0x40);  //��ʼ�У���һ�п�ʼ
	SCREEN_WriteCommand(0xaf);  //����ʾ
}

void SCREEN_WriteAddr(uint page,uint column)
{
	column=column-0x01;
	SCREEN_WriteCommand(0xb0+page-1);   //����ҳ��ַ��ÿ8��Ϊһҳ��ȫ����64�У����ֳ�8ҳ
	SCREEN_WriteCommand(0x10+(column>>4&0x0f));	//�����е�ַ�ĸ�4λ
	SCREEN_WriteCommand(column&0x0f);	//�����е�ַ�ĵ�4λ	
}

//ȫ������
void SCREEN_Clear(void)
{
	unsigned char i,j;
	for(i=0;i<9;i++)
	{
		SCREEN_WriteCommand(0xb0+i);
		SCREEN_WriteCommand(0x10);
		SCREEN_WriteCommand(0x00);
		for(j=0;j<132;j++)
		{
		  	SCREEN_WriteData(0x00,1);
		}
	}
}

//��ʾ128x64����ͼ��
void SCREEN_Display12864(uchar *dp,uchar status)
{
	uint i,j;
	
	for(j=0;j<8;j++)
	{
		SCREEN_WriteAddr(j+1,1);
		for (i=0;i<128;i++)
		{	
			SCREEN_WriteData(*dp,status);					//д���ݵ�LCD,ÿд��һ��8λ�����ݺ��е�ַ�Զ���1
			dp++;
		}
	}
}

//��ʾ16x16����ͼ�񡢺��֡���Ƨ�ֻ�16x16���������ͼ��
void SCREEN_Display1616(uchar page,uchar column,uchar *dp,uchar status)
{
	uint i,j;
	for(j=0;j<2;j++)
	{
		SCREEN_WriteAddr(page+j,column);
		for (i=0;i<16;i++)
		{	
			SCREEN_WriteData(*dp,status);					//д���ݵ�LCD,ÿд��һ��8λ�����ݺ��е�ַ�Զ���1
			dp++;
		}
	}
}
//
//��ʾ8x16����ͼ��ASCII, ��8x16����������ַ�������ͼ��
void SCREEN_Display816(uchar page,uchar column,uchar *dp,uchar status)
{
	uint i,j;
	for(j=0;j<2;j++)
	{
		SCREEN_WriteAddr(page+j,column);
		for (i=0;i<8;i++)
		{	
			SCREEN_WriteData(*dp,status);					//д���ݵ�LCD,ÿд��һ��8λ�����ݺ��е�ַ�Զ���1
			dp++;
		}
	}
}
//��ʾ5X8����ͼ��ASCII, ��5x8����������ַ�������ͼ��
void SCREEN_Display58(uchar page,uchar column,uchar *dp,uchar status)
{
	uint i;
	SCREEN_WriteAddr(page,column);
	for (i=0;i<6;i++)
	{	
		SCREEN_WriteData(*dp,status);
		dp++;
	}
}
