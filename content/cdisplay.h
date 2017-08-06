#ifndef _CDISPLAY_H_
#define _CDISPLAY_H_

/*
	功能：表示液晶显示字幕
	0：按键值，1：小功能，2：阶段，3：是否清洗海参，4：加水是否正常
	5：加热是否正常，		6：是否在干烧，	7：是否加水
*/
extern unsigned char Lcd_DisplayStatus[8];	

/*
	功能：液晶屏内容显示函数。		
*/
void HaiShen_Display(void);			


#endif
