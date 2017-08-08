#include "includes.h"

void LCD_Init(void)
{  	
	SCREEN_Init();
	SPI_ZikuInit();
	LCD_Clear();
}

/**************************************************/
//从指定地址读出数据写到液晶屏指定（page,column)座标中
void LCD_DisplayChar1616(ulong fontaddr,uchar page,uchar column,uchar status)
{
	uchar data[32];
	SPI_ZikuReadChar(fontaddr,data,32);
	SCREEN_Display1616(page,column,data,status);
}

//从指定地址读出数据写到液晶屏指定（page,column)座标中
void LCD_DisplayChar816(ulong fontaddr,uchar page,uchar column,uchar status)
{
	uchar data[16];
	SPI_ZikuReadChar(fontaddr,data,16);
	SCREEN_Display816(page,column,data,status);
}

//从指定地址读出数据写到液晶屏指定（page,column)座标中
void LCD_DisplayChar58(ulong fontaddr,uchar page,uchar column,uchar status) 
{
	uchar data[5];
	SPI_ZikuReadChar(fontaddr,data,5);
	SCREEN_Display1616(page,column,data,status);
}

void LCD_DisplayGB2312(uchar page,uchar column,uchar *text,uchar status)
{
	uchar i= 0;
	ulong fontaddr;			
	while((text[i]>0x00))
	{
		if(((text[i]>=0xb0)&&(text[i]<=0xf7))&&(text[i+1]>=0xa1))
		{						
			//国标简体（GB2312）汉字在晶联讯字库IC中的地址由以下公式来计算：
			//Address = ((MSB - 0xB0) * 94 + (LSB - 0xA1)+ 846)*32+ BaseAdd;BaseAdd=0
			//由于担心8位单片机有乘法溢出问题，所以分三部取地址
			fontaddr = (text[i]- 0xb0)*94; 
			fontaddr += (text[i+1]-0xa1)+846;
			fontaddr = (ulong)(fontaddr*32);
			LCD_DisplayChar1616(fontaddr,page,column,status);	 //从指定地址读出数据写到液晶屏指定（page,column)座标中
			i+=2;
			column+=16;
		}
		else if(((text[i]>=0xa1) &&(text[i]<=0xa3))&&(text[i+1]>=0xa1))
		{						
			//国标简体（GB2312）15x16点的字符在字库IC中的地址由以下公式来计算：
			//Address = ((MSB - 0xa1) * 94 + (LSB - 0xA1))*32+ BaseAdd;BaseAdd=0
			//由于担心8位单片机有乘法溢出问题，所以分三部取地址
			fontaddr = (text[i]- 0xa1)*94; 
			fontaddr += (text[i+1]-0xa1);
			fontaddr = (ulong)(fontaddr*32);
	
			LCD_DisplayChar1616(fontaddr,page,column,status);	 //从指定地址读出数据写到液晶屏指定（page,column)座标中
			i+=2;
			column+=16;
		}
		else if((text[i]>=0x20) &&(text[i]<=0x7e))	
		{									
			fontaddr = (text[i]- 0x20);
			fontaddr = (unsigned long)(fontaddr*16);
			fontaddr = (unsigned long)(fontaddr+0x3cf80);			

			LCD_DisplayChar816(fontaddr,page,column,status);	 //从指定地址读出数据写到液晶屏指定（page,column)座标中
			i+=1;
			column+=8;
		}
		else
			i++;	
	}
}

void LCD_DisplayString58(uchar page,uchar column,uchar *text,uchar status)
{
	unsigned char i= 0;
	ulong fontaddr;	
	while((text[i]>0x00))
	{
		if((text[i]>=0x20) &&(text[i]<=0x7e))	
		{						
			fontaddr = (text[i]- 0x20);
			fontaddr = (unsigned long)(fontaddr*8);
			fontaddr = (unsigned long)(fontaddr+0x3bfc0);			

			LCD_DisplayChar58(fontaddr,page,column,status);	 //从指定地址读出数据写到液晶屏指定（page,column)座标中

			i+=1;
			column+=6;
		}
		else
		i++;	
	}
}
void LCD_DisplayNum(unsigned char page,unsigned char col,unsigned int num,uchar status)
{
	unsigned char *a=0;
	unsigned char i=0;
	
	if(num>100)
	{
		num=num%1000;
		a[i]=num/100+'0';
		i++;
	}
	if(num>10)
	{
		num=num%100;
		a[i]=num/10+'0';
		i++;
	}
	a[i]=num%10+'0';
	
	LCD_DisplayGB2312(page,col,a,status);
}

void LCD_Display(void)
{
	switch(LCD_DisplayParam.LCD_DisplayType)
	{
		case LCD_char12864 :
			for(int i=0;i<4;i++)
			{
				LCD_DisplayGB2312(i,0,
					LCD_DisplayParam.dataParam.char12864.data[i],LCD_DisplayParam.isPositive);
			}
		break;
		
		case LCD_charGB2312 :
			LCD_DisplayGB2312(LCD_DisplayParam.dataParam.charGB2312.row,LCD_DisplayParam.dataParam.charGB2312.col,
					LCD_DisplayParam.dataParam.charGB2312.data,LCD_DisplayParam.isPositive);
		break;
		
		case LCD_char58:
			LCD_DisplayString58(LCD_DisplayParam.dataParam.char58.row,LCD_DisplayParam.dataParam.char58.col,
					LCD_DisplayParam.dataParam.char58.data,LCD_DisplayParam.isPositive);
		break;
		
		case LCD_numInt:
			LCD_DisplayNum(LCD_DisplayParam.dataParam.numInt.row,LCD_DisplayParam.dataParam.numInt.col,
					LCD_DisplayParam.dataParam.numInt.data,LCD_DisplayParam.isPositive);
		break;
		
		case LCD_image12864:
			LCD_Display12864(LCD_DisplayParam.dataParam.image12864.data,LCD_DisplayParam.isPositive);
		break;
		
		default: ;
	}
}
