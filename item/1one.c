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
		case 1	:	OneBranch_Display();	break;  	//中头海参
		case 2	:	TwoBranch_Display();	break;		//大头海参
		case 3	:	ThreeBranch_Display();	break;		//小头海参
	}
}


static void OneBranch_Display(void)
{
	switch(Lcd_DisplayStatus[2])
	{
		case 1	:	OneOneStage_Display();		break;	 // 20/30等待阶段
		case 2	:	OneTwoStage_Display();		break;	 //海参发制第一阶段
		case 3	:	OneThreeStage_Display();	break;	 //海参发制第二阶段
		case 4	:	OneFourStage_Display();		break;	 //海参发制第三阶段
		case 5	:	OneFiveStage_Display();		break;	 //海参发制完冷藏阶段
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
	
	//加水，加热一切正常，没有干烧。
	if((Lcd_DisplayStatus[4]==0)&&(Lcd_DisplayStatus[5]==0)&&(Lcd_DisplayStatus[6]==0))
	{
		switch(Lcd_DisplayStatus[3])
		{
		 	case 0:  //海参法制第一阶段，不需要清洗，电热盘，加水工作正常。没有干烧。	
				LCD_DisplayGB2312(1,1,"普通海参开始发制");
				LCD_DisplayGB2312(3,1,"一斤海参40至90只");
				LCD_DisplayGB2312(5,1," 8小时后清洗海参");
				LCD_DisplayGB2312(7,1,"68小时后发制结束");
			break;

			case 1:	 //海参法制第一阶段，需要清洗但是没有清洗，电热盘，加水工作正常。没有干烧。
				LCD_DisplayGB2312(1,1,"请您现在清洗海参");
				LCD_DisplayGB2312(3,1,"按暂停键后端出锅");
				LCD_DisplayGB2312(5,1,"清洗后把参锅放回");
				LCD_DisplayGB2312(7,1,"按恢复键接着发制");
			break;

			case 2:	 //海参法制第一阶段，正在清洗海参，电热盘，加水工作正常。没有干烧。
				LCD_DisplayGB2312(1,1,"您按了暂停键");
				LCD_DisplayGB2312(3,1,"现在可以清洗海参");
				LCD_DisplayGB2312(5,1,"请1小时内放回");
				LCD_DisplayGB2312(7,1,"按恢复键接着发制");
			break;

			case 3:	 //海参法制第一阶段，海参清洗完成，电热盘，加水工作正常。没有干烧。
				LCD_DisplayGB2312(1,1,"海参已经清洗完毕");
				LCD_DisplayGB2312(3,1,"普通海参接着发制");
				LCD_DisplayGB2312(5,1,"一斤海参40至90只");
				LCD_DisplayGB2312(7,1,"60小时后发制完成");
			break;

			case 4:	//海参法制第一阶段，清洗过程超时，电热盘，加水工作正常。没有干烧。
				LCD_DisplayGB2312(1,1,"清洗海参超时");
				LCD_DisplayGB2312(3,1,"请您放回海参");
				LCD_DisplayGB2312(5,1,"按恢复键继续发制");
				LCD_DisplayGB2312(7,1,"12小时后关机");
			break;	
		}
		
	}
	//加水不正常，但加热正常，没有干烧
	if((Lcd_DisplayStatus[4]==1)&&(Lcd_DisplayStatus[5]==0)&&(Lcd_DisplayStatus[6]==0))
	{
	}
	//加热不正常，但加水正常，没有干烧
	if((Lcd_DisplayStatus[4]==0)&&(Lcd_DisplayStatus[5]==1)&&(Lcd_DisplayStatus[6]==0))
	{
	
	}
	//加水加热均正常。但干烧
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
	LCD_DisplayGB2312(1,1,"大头海参发制30");
	LCD_DisplayGB2312(3,1,"一斤海参少于40只");
	LCD_DisplayGB2312(5,1,"其他头数海参发制");
	LCD_DisplayGB2312(7,1,"再按再选长按退出"); 
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
	LCD_DisplayGB2312(1,1,"小头海参发制30");
	LCD_DisplayGB2312(3,1,"一斤海参多于90只");
	LCD_DisplayGB2312(5,1,"其他头数海参发制");
	LCD_DisplayGB2312(7,1,"再按再选长按退出");
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

	//前期进行器件检测
	Water_On();
	Lcd_DisplayStatus[7]=1;		//设置加水标志位，主要用于加水时，最好不进行加热，制冷操作。
	OSTimeDlyHMSM(0,0,50,0);	
	Water_Off();     			//加水完成
	Lcd_DisplayStatus[7]=0;		//清空加水标志位。

	temper_now = DS18B20_GetTemper();//LCD_DisplayNum(3,12,(temper_now/100));LCD_DisplayNum(3,36,temper_now%100);
	HotBig_On();
	OSTimeDlyHMSM(0,0,30,0);
	Hot_Off();		 				 		//电热盘加热完成。
	temper_before = temper_now;
	temper_now = DS18B20_GetTemper();
	temper_before = temper_now-temper_before; //通过计算温度检测电热盘是否工作正常

	if(temper_before<16)			//温度变化小于1度，电热盘工作不正常。
	{
		Lcd_DisplayStatus[5]=1;
	}
	if(temper_before>80)			//温度变化大于5度，电热盘干烧。
	{
		Lcd_DisplayStatus[6]=1;
	}							   
	if(Lcd_DisplayStatus[4]!=0||    //判断是否出现异常，无异常怎不需要更新界面。
		Lcd_DisplayStatus[5]!=0||Lcd_DisplayStatus[6]!=0)
	{
	 	OSSemPost(Lcd_Display_Event);
	}
}


void Function_OneRun(void)
{
    int temper_now,temper_before;
	Device_Test();
	do{	//器件检测完毕，正式进入发制
		switch(Lcd_DisplayStatus[2])
		{
		 	case 2:		//海参发制第一阶段
			case 3:	 	//海参发制第二阶段
			case 4:		//海参发制第三阶段
			case 5:		//海参发制冷藏阶段
				while(Lcd_DisplayStatus[2]==2)	//海参发制第一阶段
				{
					temper_now = DS18B20_GetTemper();
					if((temper_now<Haishen_OneStageTemLow)&&(Lcd_DisplayStatus[7]==0))	//温度低于40度,且不在加水
					{
						HotBig_On();
						OSTimeDlyHMSM(0,2,0,0); //加热2分钟后在检测温度。	
					}
					if(temper_now>Haishen_OneStageTemHight)
					{
						Hot_Off();
						OSTimeDlyHMSM(0,3,0,0);//停止加热后冷却3分钟后再检测
					} 
					OSTimeDlyHMSM(0,0,30,0);	//延时30s检测一次。
				}
				while(Lcd_DisplayStatus[2]==3) //海参发制第二阶段
				{
				
				}
				while(Lcd_DisplayStatus[2]==4) //海参发制第三阶段
				{
				
				}
				while(Lcd_DisplayStatus[2]==5) //海参发制冷藏阶段
				{
				
				}
			break;

			default:break;	//其他情况
		}
	}while(Lcd_DisplayStatus[0]==1);
	
}
