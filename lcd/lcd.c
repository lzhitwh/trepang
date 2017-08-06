#include "includes.h"

void LCD_Init(void)
{  	
	SCREEN_Init();
	SPI_ZikuInit();
	LCD_Clear();
}

/**************************************************/
//��ָ����ַ��������д��Һ����ָ����page,column)������
void LCD_DisplayChar1616(ulong fontaddr,uchar page,uchar column)
{
	uchar data[32];
	SPI_ZikuReadChar(fontaddr,data,32);
	SCREEN_Display1616(page,column,data);
}

//��ָ����ַ��������д��Һ����ָ����page,column)������
void LCD_DisplayChar816(ulong fontaddr,uchar page,uchar column)
{
	uchar data[16];
	SPI_ZikuReadChar(fontaddr,data,16);
	SCREEN_Display816(page,column,data);
}

//��ָ����ַ��������д��Һ����ָ����page,column)������
void LCD_DisplayChar58(ulong fontaddr,uchar page,uchar column) 
{
	uchar data[5];
	SPI_ZikuReadChar(fontaddr,data,5);
	SCREEN_Display1616( page,column,data);
}

void LCD_DisplayGB2312(uchar page,uchar column,uchar *text)
{
	uchar i= 0;
	ulong fontaddr;			
	while((text[i]>0x00))
	{
		if(((text[i]>=0xb0)&&(text[i]<=0xf7))&&(text[i+1]>=0xa1))
		{						
			//������壨GB2312�������ھ���Ѷ�ֿ�IC�еĵ�ַ�����¹�ʽ�����㣺
			//Address = ((MSB - 0xB0) * 94 + (LSB - 0xA1)+ 846)*32+ BaseAdd;BaseAdd=0
			//���ڵ���8λ��Ƭ���г˷�������⣬���Է�����ȡ��ַ
			fontaddr = (text[i]- 0xb0)*94; 
			fontaddr += (text[i+1]-0xa1)+846;
			fontaddr = (ulong)(fontaddr*32);
			LCD_DisplayChar1616(fontaddr,page,column);	 //��ָ����ַ��������д��Һ����ָ����page,column)������
			i+=2;
			column+=16;
		}
		else if(((text[i]>=0xa1) &&(text[i]<=0xa3))&&(text[i+1]>=0xa1))
		{						
			//������壨GB2312��15x16����ַ����ֿ�IC�еĵ�ַ�����¹�ʽ�����㣺
			//Address = ((MSB - 0xa1) * 94 + (LSB - 0xA1))*32+ BaseAdd;BaseAdd=0
			//���ڵ���8λ��Ƭ���г˷�������⣬���Է�����ȡ��ַ
			fontaddr = (text[i]- 0xa1)*94; 
			fontaddr += (text[i+1]-0xa1);
			fontaddr = (ulong)(fontaddr*32);
	
			LCD_DisplayChar1616(fontaddr,page,column);	 //��ָ����ַ��������д��Һ����ָ����page,column)������
			i+=2;
			column+=16;
		}
		else if((text[i]>=0x20) &&(text[i]<=0x7e))	
		{									
			fontaddr = (text[i]- 0x20);
			fontaddr = (unsigned long)(fontaddr*16);
			fontaddr = (unsigned long)(fontaddr+0x3cf80);			

			LCD_DisplayChar816(fontaddr,page,column);	 //��ָ����ַ��������д��Һ����ָ����page,column)������
			i+=1;
			column+=8;
		}
		else
			i++;	
	}
}

void LCD_DisplayString58(uchar page,uchar column,uchar *text)
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

			LCD_DisplayChar58(fontaddr,page,column);	 //��ָ����ַ��������д��Һ����ָ����page,column)������

			i+=1;
			column+=6;
		}
		else
		i++;	
	}
}
void LCD_DisplayNum(unsigned char page,unsigned char col,unsigned int num)
{
	unsigned char a[3];
	a[0]=num/100+'0';
	a[1]=(num%100)/10+'0';
	a[2]=num%10+'0';
	LCD_DisplayGB2312(page,col,a);
}
