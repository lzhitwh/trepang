#include "includes.h"

char ESP8266_Init(void)
{
//	char err;
//	USART1_printf(USART1,"AT\n");   //启动无线模块
//	OSSemPend(Usart_Rec_Event,0,&err);
//	USART1_printf(USART2,Usart_Rec_Buf);
////	OSTimeDlyHMSM(0,0,1,0);
//	USART1_printf(USART1,"AT+CWMODE=3\r\n"); //设置AP兼Station模式
//	OSTimeDlyHMSM(0,0,1,0);
//	USART1_printf(USART1,"AT+RST\r\n");	 //重启无线模块
//	OSTimeDlyHMSM(0,0,1,0);
//	USART1_printf(USART1,"AT+CIPMUX=0\r\n"); //启动单链接
//	OSTimeDlyHMSM(0,0,1,0);
//	USART1_printf(USART1,"AT+CIPMODE=1\r\n");
//	OSTimeDlyHMSM(0,0,1,0);
//	USART1_printf(USART1,"AT+CIPSTART=\"UDP\",\"192.168.1.100\",54321\r\n");
//	OSTimeDlyHMSM(0,0,1,0);
	return 1;
}

void ESP8266_Send(char num,char *date)
{
//	char sendStart[10]={'A','T','+','S','E','N','D','=',num,\r,\n};
	USART1_printf(USART1,"AT+CIPSEND=4\r\n");
	OSTimeDlyHMSM(0,0,1,0);
	USART1_printf(USART1,"num1\r\n");
}

/*******************************************************
		功能：判断初始化成功与否
		返回值： 1	表示初始化成功
				-1	表示初始化失败			
*******************************************************/
char Esp8266_OkError(char argc[])  
{
//	char buf[21];
//	unsigned char i=0;
//   	unsigned char j=0;
//	for(i=0;i<128&&argc[i]!='\n';)
//	{
//	  	for(j=0;(argc[i]!='\n')&&(argc[i]!=' ')&&(j<20);i++,j++)
//		{
//		     buf[j]=argc[i];
//			 buf[j+1]='\n';
//		}
//		if(j==20)
//		{
//			for(;(argc[i]!='\n')&&(argc[i]!=' ');i++);
//		}
//		if((buf[0]=='O')&&(buf[0]=='K'))
//		{
//			return 1;
//		}
//		if((buf[0]=='E')&&(buf[0]=='R')&&(buf[0]=='R')
//			&&(buf[0]=='O')&&(buf[0]=='R')&&(buf[0]=='\n'))
//		{
//			return -1;
//		}
//	}
	return 0;
}
