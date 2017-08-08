#include "includes.h"

#define SystemFrequency  72000000

void BSP_Init(void)
{
	SystemInit();
	Systick_Init();
	DS18B20_Init();
	USART1_Config();
//	USART2_Config();
	DMA_Config();
	LCD_Init();
	KEY_GPIO_Config();
	DM13A_GPIO_Config();
	Relay_Init();
}

void Systick_Init(void)
{
	SysTick_Config(SystemFrequency/OS_TICKS_PER_SEC);
}
