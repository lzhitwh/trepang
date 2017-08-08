#include "includes.h"

void Zero_Display(void)
{
	LCD_DisplayParam.dataParam.char12864.data[0]="悦达海参送关爱";
	LCD_DisplayParam.dataParam.char12864.data[1]="常吃海参保健康";
	LCD_DisplayParam.dataParam.char12864.data[2]="家人服务热线";
	LCD_DisplayParam.dataParam.char12864.data[3]="123456789";
}
