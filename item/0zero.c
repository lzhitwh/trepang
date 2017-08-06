#include "includes.h"

void Zero_Display(void)
{
	Lcd_DisplayStatus[0]=0;
	Lcd_DisplayStatus[1]=0;
	Lcd_DisplayStatus[2]=0;
	Lcd_DisplayStatus[3]=0;

	LCD_Clear();
	LCD_DisplayGB2312(1,1,"双举海参送关爱");
	LCD_DisplayGB2312(3,1,"营养海参保健康");
	LCD_DisplayGB2312(5,1,"家人服务热线");
	LCD_DisplayGB2312(7,1,"123456789");
}
