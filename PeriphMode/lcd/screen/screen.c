#include "includes.h"

void Screen_GPIO_Init(void){
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    GPIO_InitStructure.GPIO_Pin=LCD_SDA|LCD_SCK|LCD_RS| LCD_RST|LCD_CS;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
}

//写指令到LCD模块
void SCREEN_WriteCommand(int data1)   
{
	char i;
	LCD_CS_L();		//LCD片选有效
	LCD_RS_L();		//传输指令
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

//写数据到LCD模块
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

//LCD模块初始化
void SCREEN_Init(void)
{
	Screen_GPIO_Init();
	LCD_RST_L();        	//低电平复位
	LCD_RST_H();	    	//复位完毕   
	SCREEN_WriteCommand(0xe2);	 //软复位
	SCREEN_WriteCommand(0x2c);  //升压步聚1
	SCREEN_WriteCommand(0x2e);  //升压步聚2
	SCREEN_WriteCommand(0x2f);  //升压步聚3
	SCREEN_WriteCommand(0x23);  //粗调对比度，可设置范围0x20～0x27
	SCREEN_WriteCommand(0x81);  //微调对比度
	SCREEN_WriteCommand(0x30);  //微调对比度的值，可设置范围0x00～0x3f
	SCREEN_WriteCommand(0xa2);  //1/9偏压比（bias）
	SCREEN_WriteCommand(0xc8);  //行扫描顺序：从上到下
	SCREEN_WriteCommand(0xa0);  //列扫描顺序：从左到右
	SCREEN_WriteCommand(0x40);  //起始行：第一行开始
	SCREEN_WriteCommand(0xaf);  //开显示
}

void SCREEN_WriteAddr(uint page,uint column)
{
	column=column-0x01;
	SCREEN_WriteCommand(0xb0+page-1);   //设置页地址，每8行为一页，全屏共64行，被分成8页
	SCREEN_WriteCommand(0x10+(column>>4&0x0f));	//设置列地址的高4位
	SCREEN_WriteCommand(column&0x0f);	//设置列地址的低4位	
}

//全屏清屏
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

//显示128x64点阵图像
void SCREEN_Display12864(uchar *dp,uchar status)
{
	uint i,j;
	
	for(j=0;j<8;j++)
	{
		SCREEN_WriteAddr(j+1,1);
		for (i=0;i<128;i++)
		{	
			SCREEN_WriteData(*dp,status);					//写数据到LCD,每写完一个8位的数据后列地址自动加1
			dp++;
		}
	}
}

//显示16x16点阵图像、汉字、生僻字或16x16点阵的其他图标
void SCREEN_Display1616(uchar page,uchar column,uchar *dp,uchar status)
{
	uint i,j;
	for(j=0;j<2;j++)
	{
		SCREEN_WriteAddr(page+j,column);
		for (i=0;i<16;i++)
		{	
			SCREEN_WriteData(*dp,status);					//写数据到LCD,每写完一个8位的数据后列地址自动加1
			dp++;
		}
	}
}
//
//显示8x16点阵图像、ASCII, 或8x16点阵的自造字符、其他图标
void SCREEN_Display816(uchar page,uchar column,uchar *dp,uchar status)
{
	uint i,j;
	for(j=0;j<2;j++)
	{
		SCREEN_WriteAddr(page+j,column);
		for (i=0;i<8;i++)
		{	
			SCREEN_WriteData(*dp,status);					//写数据到LCD,每写完一个8位的数据后列地址自动加1
			dp++;
		}
	}
}
//显示5X8点阵图像、ASCII, 或5x8点阵的自造字符、其他图标
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
