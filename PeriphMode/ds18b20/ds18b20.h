#ifndef DS18B20_H_
#define DS18B20_H_

#define GPIO_DQ  			 GPIO_Pin_12
#define DS18B20_GPIO		 GPIOA

#define DQ_SET GPIO_SetBits(DS18B20_GPIO,GPIO_DQ)
#define DQ_CLK GPIO_ResetBits(DS18B20_GPIO,GPIO_DQ)
//#define DS18B20_Init()	DS18B20_GPIO_Init()

void DS18B20_Init(void);
void DS18B20_GPIO_Init(void);
int DS18B20_ReadTemper(void);	//功能：读取温度值，读取一次。温度没有做/16处理，所以读取是数值是实际温度的16倍。	
int DS18B20_GetTemper(void);	//功能：读取温度值，读取5次，去除最大值最小值。取其平均值。

#endif
