#include "includes.h"

unsigned char Key_num=0;   //全局变量，键盘值。
unsigned int Key_time=0;   //全局变量，键盘按下时间。


void Get_Function(void)
{
//	unsigned char err;
//	do{
//		OSSemPend(Key_Num_Event,3000,&err);	
//		OSSemPost(Time_Run_Event);
//		OSSemPost(Lcd_Display_Event);
//	 }while(err == OS_ERR_NONE);
}


/*
 	功能：按键线程函数，用于检测按键按下情况。
*/
void Key_RunTime(void)
{
//	unsigned char keynum=0;
//	unsigned int keytime=0;
////	unsigned char i=0;
//	
//	while(1)
//	{
//		KEY_Scan(&keynum,&keytime);
//		if(keynum!=0)
//		{
//			FuncStatus.currKey=keynum;
//			FuncStatus.currKeyTime=keytime;
//			OSSemPost(Key_Num_Event);
//		}
//		keynum=0;		//清零
//		keytime=0;
//		if(FuncStatus.currKeyTime>300)
//		{
//			Led_OnTheNum(0);			//关闭LED指示灯。
//			for(i=0;i<8;i++)
//			{
//				Lcd_DisplayStatus[i] = 0;
//			}
//			No_DisplayStatus=0;			//清空相关标志位。
////			Led_OnTheNum(0);
//			OSSemPost(Key_Num_Event);	//发送按键事件
//		}
//		else
//		{
//			switch(key_num)
//			{
//			  	case 1	:	
//				case 2	:
//				case 3	:	
//				case 4	:
//				case 5	:
//				case 6	:	
//				case 7	:	
//				case 8	:
//				case 9	:	
//				case 10	:
//				case 11	:	
//				case 12	:
//				case 13	:	
//				case 14	:
//					Led_OnTheNum(key_num);		
//					if(key_num != Lcd_DisplayStatus[0])
//					{
//						Lcd_DisplayStatus[0]=key_num;
//						Lcd_DisplayStatus[1]=1;
//						Lcd_DisplayStatus[2]=1;
//						Lcd_DisplayStatus[3]=0;
//					}
//					else
//					{
//						Lcd_DisplayStatus[1]++;
//						if(Lcd_DisplayStatus[1] == 4)
//						{
//							Lcd_DisplayStatus[1]=1;	
//						}			
//					}
//					OSSemPost(Key_Num_Event);		
//				break;
//	
//				case 15	:		//设置为加水测试键
//					if(key_time>300)
//					{
//						No_DisplayStatus=0;
//						OSSemPost(Lcd_Display_Event);
//					}
//					else
//					{
//						No_DisplayStatus++;
//						if(No_DisplayStatus>=3)
//						{
//							No_DisplayStatus=1;
//						}
//						LCD_DisplayNum(7,1,key_num);
//						LCD_DisplayNum(7,80,No_DisplayStatus);
//						OSSemPost(Method_Other_Event);	
//					}
//				break;
//										
//				case 16	:		//设置为暂停/恢复/阅读键
//					if(key_time>300)
//					{
//						No_DisplayStatus=0;
//						OSSemPost(Lcd_Display_Event);
//					}
//					else
//					{
//						if(No_DisplayStatus==0)		//第一次按下按键时。
//						{
//							No_DisplayStatus=2;
//						}	
//						No_DisplayStatus++;
//						if(No_DisplayStatus>=10)	//到达最大值时，循环显示
//						{
//							No_DisplayStatus=3;
//						}
//						LCD_DisplayNum(7,1,key_num);
//						LCD_DisplayNum(7,80,No_DisplayStatus);
//						OSSemPost(Method_Other_Event);	
//					}
//				break;			
//				default	:	break;
//			}
//		}				   
//		OSTimeDlyHMSM(0,0,0,50);
//	}
}
