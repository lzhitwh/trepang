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

void Two_Display(void)
{
	switch(Lcd_DisplayStatus[1])
	{
		case 1	:	OneBranch_Display();	break;
		case 2	:	TwoBranch_Display();	break;
		case 3	:	ThreeBranch_Display();	break;
	}
}


static void OneBranch_Display(void)
{
	switch(Lcd_DisplayStatus[2])
	{
		case 1	:	OneOneStage_Display();		break;
		case 2	:	OneTwoStage_Display();		break;
		case 3	:	OneThreeStage_Display();	break;
		case 4	:	OneFourStage_Display();		break;
		case 5	:	OneFiveStage_Display();		break;
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
	LCD_DisplayGB2312(1,1,"普通海参发制30");
	LCD_DisplayGB2312(3,1,"一斤海参40至90只");
	LCD_DisplayGB2312(5,1,"其他头数海参发制");
	LCD_DisplayGB2312(7,1,"再按再选长按退出");
}

static void OneTwoStage_Display(void)
{
	LCD_Clear();
	LCD_DisplayGB2312(1,1,"大头海参发制30");
	LCD_DisplayGB2312(3,1,"一斤海参少于40只");
	LCD_DisplayGB2312(5,1,"其他头数海参发制");
	LCD_DisplayGB2312(7,1,"再按再选长按退出"); 
}
static void OneThreeStage_Display(void)
{
	LCD_Clear();
	LCD_DisplayGB2312(1,1,"");
	LCD_DisplayGB2312(3,1,"");
	LCD_DisplayGB2312(5,1,"");
	LCD_DisplayGB2312(7,1,"");
}
static void OneFourStage_Display(void)
{
	LCD_Clear();
	LCD_DisplayGB2312(1,1,"");
	LCD_DisplayGB2312(3,1,"");
	LCD_DisplayGB2312(5,1,"");
	LCD_DisplayGB2312(7,1,"");
}
static void OneFiveStage_Display(void)
{
	LCD_Clear();
	LCD_DisplayGB2312(1,1,"");
	LCD_DisplayGB2312(3,1,"");
	LCD_DisplayGB2312(5,1,"");
	LCD_DisplayGB2312(7,1,"");	
}


static void TwoOneStage_Display(void)
{
	LCD_Clear();
	LCD_DisplayGB2312(1,1,"大头海参发制30");
	LCD_DisplayGB2312(3,1,"一斤海参少于40只");
	LCD_DisplayGB2312(5,1,"其他头数海参发制");
	LCD_DisplayGB2312(7,1,"再按再选长按退出"); 
}
static void TwoTwoStage_Display(void)
{
	LCD_Clear();
	LCD_DisplayGB2312(1,1,"");
	LCD_DisplayGB2312(3,1,"");
	LCD_DisplayGB2312(5,1,"");
	LCD_DisplayGB2312(7,1,"");
}
static void TwoThreeStage_Display(void)
{
	LCD_Clear();
	LCD_DisplayGB2312(1,1,"");
	LCD_DisplayGB2312(3,1,"");
	LCD_DisplayGB2312(5,1,"");
	LCD_DisplayGB2312(7,1,"");
}
static void TwoFourStage_Display(void)
{
	LCD_Clear();
	LCD_DisplayGB2312(1,1,"");
	LCD_DisplayGB2312(3,1,"");
	LCD_DisplayGB2312(5,1,"");
	LCD_DisplayGB2312(7,1,"");
}
static void TwoFiveStage_Display(void)
{
	LCD_Clear();
	LCD_DisplayGB2312(1,1,"");
	LCD_DisplayGB2312(3,1,"");
	LCD_DisplayGB2312(5,1,"");
	LCD_DisplayGB2312(7,1,"");	
}


static void ThreeOneStage_Display(void)
{
	LCD_Clear();
	LCD_DisplayGB2312(1,1,"小头海参发制30");
	LCD_DisplayGB2312(3,1,"一斤海参多于90只");
	LCD_DisplayGB2312(5,1,"其他头数海参发制");
	LCD_DisplayGB2312(7,1,"再按再选长按退出");
}

static void ThreeTwoStage_Display(void)
{
	LCD_Clear();
	LCD_DisplayGB2312(1,1,"");
	LCD_DisplayGB2312(3,1,"");
	LCD_DisplayGB2312(5,1,"");
	LCD_DisplayGB2312(7,1,"");	
}

static void ThreeThreeStage_Display(void)
{
	LCD_Clear();
	LCD_DisplayGB2312(1,1,"");
	LCD_DisplayGB2312(3,1,"");
	LCD_DisplayGB2312(5,1,"");
	LCD_DisplayGB2312(7,1,"");
}
static void ThreeFourStage_Display(void)
{
	LCD_Clear();
	LCD_DisplayGB2312(1,1,"");
	LCD_DisplayGB2312(3,1,"");
	LCD_DisplayGB2312(5,1,"");
	LCD_DisplayGB2312(7,1,"");
}
static void ThreeFiveStage_Display(void)
{
	LCD_Clear();
	LCD_DisplayGB2312(1,1,"");
	LCD_DisplayGB2312(3,1,"");
	LCD_DisplayGB2312(5,1,"");
	LCD_DisplayGB2312(7,1,"");
}
