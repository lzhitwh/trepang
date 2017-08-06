#include "includes.h"

void DM13A_GPIO_Config(void)
{
	GPIO_InitTypeDef Dm13a_Structure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);			//使能GPIOB的外设时钟

	Dm13a_Structure.GPIO_Pin=GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_5|GPIO_Pin_6;
	Dm13a_Structure.GPIO_Speed=GPIO_Speed_50MHz;
	Dm13a_Structure.GPIO_Mode=GPIO_Mode_Out_PP; 
	GPIO_Init(GPIOB,&Dm13a_Structure);
	DM13A_DAI_H;
	DM13A_DCK_H;
	DM13A_LAT_H;
	DM13A_EN_L;	
	Led_OnTheNum(0);
}

void Relay_Init(void)
{
	GPIO_InitTypeDef Relay_Structure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);			//使能GPIOB的外设时钟

	Relay_Structure.GPIO_Pin=GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_10;
	Relay_Structure.GPIO_Speed=GPIO_Speed_50MHz;
	Relay_Structure.GPIO_Mode=GPIO_Mode_Out_PP; 
	GPIO_Init(GPIOC,&Relay_Structure);
	
	Water_Off();
	Cold_Off();
	Hot_Off();		
}


void Led_OnTheNum(unsigned char num)
{
	unsigned char i=0;
//	DM13A_LAT_H;
	DM13A_DAI_L;
	DM13A_DCK_L;
	DM13A_EN_H;

	if(num==0||num>16)
	{
		for(i=0;i<16;i++)
		{
			DM13A_DAI_L;
			DM13A_DCK_H;
			OSTimeDlyHMSM(0,0,0,10);
			DM13A_DCK_L;	
		}
	}
	else
	{
		for(i=0;i<16;i++)
		{
			if(i==(num-1))
				DM13A_DAI_H;
			else
				DM13A_DAI_L;
			DM13A_DCK_H;
			OSTimeDlyHMSM(0,0,0,10);
			DM13A_DCK_L;	
		}
	}

//	DM13A_LAT_L;
	DM13A_EN_L;
}
