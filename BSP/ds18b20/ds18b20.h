#ifndef DS18B20_H_
#define DS18B20_H_

#define GPIO_DQ  			 GPIO_Pin_12
#define DS18B20_GPIO		 GPIOA

#include"includes.h"

#define DQ_SET GPIO_SetBits(DS18B20_GPIO,GPIO_DQ)
#define DQ_CLK GPIO_ResetBits(DS18B20_GPIO,GPIO_DQ)
#define DS18B20_Init()	DS18B20_GPIO_Init()	

//void DS18B20_Init(void);
int DS18B20_ReadTemper(void);
int DS18B20_GetTemper(void);

#endif
