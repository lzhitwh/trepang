#include "includes.h"

void Zero_Display(void)
{
	Lcd_DisplayStatus[0]=0;
	Lcd_DisplayStatus[1]=0;
	Lcd_DisplayStatus[2]=0;
	Lcd_DisplayStatus[3]=0;

	LCD_Clear();
	LCD_DisplayGB2312(1,1,"˫�ٺ����͹ذ�");
	LCD_DisplayGB2312(3,1,"Ӫ�����α�����");
	LCD_DisplayGB2312(5,1,"���˷�������");
	LCD_DisplayGB2312(7,1,"123456789");
}
