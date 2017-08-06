#include "includes.h"

#define Delay_ms(ms)	OSTimeDlyHMSM(0,0,0,ms)		

void Delay_us(__IO u32 nTime)
{
	int i,j;
	for(i=0;i<nTime;i++)
	{
		j=3;   //j=2
		while(j--);
	}		
}

void DS18B20_GPIO_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStruecture;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);

	GPIO_InitStruecture.GPIO_Pin=GPIO_DQ;
	GPIO_InitStruecture.GPIO_Mode=GPIO_Mode_IN_FLOATING;
	GPIO_InitStruecture.GPIO_Speed=GPIO_Speed_50MHz;

	GPIO_Init(DS18B20_GPIO,&GPIO_InitStruecture);
}
//void DS18B20_Init(void)
//{
//	DS18B20_GPIO_Init();
//}

void DS18B20_DQ_Out(void)
{
	GPIO_InitTypeDef GPIO_InitStruecture;

	GPIO_InitStruecture.GPIO_Pin=GPIO_DQ;
	GPIO_InitStruecture.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStruecture.GPIO_Speed=GPIO_Speed_50MHz;

	GPIO_Init(DS18B20_GPIO,&GPIO_InitStruecture);
}

void DS18B20_DQ_In(void)
{
	GPIO_InitTypeDef GPIO_InitStruecture;

	GPIO_InitStruecture.GPIO_Pin=GPIO_DQ;
	GPIO_InitStruecture.GPIO_Mode=GPIO_Mode_IN_FLOATING;
	GPIO_InitStruecture.GPIO_Speed=GPIO_Speed_50MHz;

	GPIO_Init(DS18B20_GPIO,&GPIO_InitStruecture);
}

char DS18B20_ReadData(void)
{
 	u8 i;
	u8 dat=0;
	DS18B20_DQ_Out(); 		// 设置引脚为输出模式
	DQ_SET;			  				// 设置为高电平
	Delay_us(3);	  			// 延时3us
	for(i=0;i<8;i++)
	{
		dat>>=1;
		DS18B20_DQ_Out();
		DQ_CLK;
		Delay_us(2);
		DQ_SET;
		DS18B20_DQ_In();
		Delay_us(10);
		if(GPIO_ReadInputDataBit(DS18B20_GPIO,GPIO_DQ)==1)
		{
		    dat|=0x80;
		}
		Delay_us(50);
	}
	return dat;
}

void DS18B20_WriteData(u8 dat)
{
 	u8 i;
	u8 udat;
	DS18B20_DQ_Out();
	DQ_SET;
	Delay_us(2);
	for(i=0;i<8;i++)
	{
		udat=dat & 0x01;
		dat=dat>>1;
		if(udat)
		{
			DQ_CLK;
			Delay_us(2);
			DQ_SET;
			Delay_us(60);
		}
		else
		{
			DQ_CLK;
			Delay_us(60);
			DQ_SET;
			Delay_us(2);
		}
	}
}

u8 DS18B20_RST(void)
{
	u16 time=0;
	DS18B20_DQ_Out();
	DQ_SET;     
	Delay_us(3);
	DQ_CLK;
	Delay_us(750);
	DQ_SET;	          			//释放数据线
	DS18B20_DQ_In();  
	Delay_us(15);
	while(GPIO_ReadInputDataBit(DS18B20_GPIO,GPIO_DQ)&&time<500)
	{
		time++;
		Delay_us(1);
	}
	if(time>=500)
	{
		//初始化失败
		LCD_DisplayGB2312(5,1,"温度传感器错误");
		return 0;				//t=0;
	}
	time=0;
	while((!GPIO_ReadInputDataBit(DS18B20_GPIO,GPIO_DQ))&&time<10000)	//等待ds18b20释放总线
	{
		time++;
		Delay_us(1);
	}
	if(time>=10000)
	{
		LCD_DisplayGB2312(5,1,"温度传感器未释放");
		return 0;	//t=0;
	}
	return 1;		//return t; 		
}

int DS18B20_ReadTemper(void)
{
  	OS_CPU_SR cpu_sr;

	char rst=0;
	char time=0;
	char HTemper=0;
	char LTemper=0;
	int Temper;

	while((rst==0)&&(time<10)){
		time++;
OS_ENTER_CRITICAL();
		rst = DS18B20_RST();
	
		DS18B20_WriteData(0xcc);
		DS18B20_WriteData(0x44);
OS_EXIT_CRITICAL();
		Delay_ms(1000);
OS_ENTER_CRITICAL();
		rst = DS18B20_RST();
		DS18B20_WriteData(0xcc);
		DS18B20_WriteData(0xbe);
		LTemper=DS18B20_ReadData();
		HTemper=DS18B20_ReadData();
OS_EXIT_CRITICAL();
	}
	if(time>=10)
	{
		time=0;
//		printf("请检查温度传感器！\n");
		return	2000;
	}
	time=0;
	Temper=HTemper;
	Temper=(Temper<<8) | LTemper;
//	Temper=Temper*0.0625;
//	printf("\r\n温度高位为：%d \r\n",HTemper);
//	printf("\r\n温度低位为：%d \r\n",LTemper);
//	printf("\r\n当前温度为：%d \r\n",Temper);

	return Temper;
}

int DS18B20_GetTemper(void)
{
	int tem[5];
	int temper;
	unsigned char i,j;
	for(i=0;i<5;i++)
	{
	 	tem[i]=	DS18B20_ReadTemper();
//		LCD_DisplayNum(1,1+i*16,tem[i]%100);
	}
	for(i=0;i<4;i++)
	{
		for(j=0;j<4-i;j++)
		{
			if(tem[j+1]<tem[j])
			{
			  	temper=tem[j+1];
				tem[j+1]=tem[j];
				tem[j]=temper;
			}	
		}
	}
	temper=0;
	for(i=1;i<4;i++)
	{
		temper+=tem[i];
	}
	return (temper/3);
}

