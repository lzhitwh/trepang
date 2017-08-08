#ifndef DS18B20_H_
#define DS18B20_H_

#define GPIO_DQ  			 GPIO_Pin_12
#define DS18B20_GPIO		 GPIOA

#define DQ_SET GPIO_SetBits(DS18B20_GPIO,GPIO_DQ)
#define DQ_CLK GPIO_ResetBits(DS18B20_GPIO,GPIO_DQ)
//#define DS18B20_Init()	DS18B20_GPIO_Init()

void DS18B20_Init(void);
void DS18B20_GPIO_Init(void);
int DS18B20_ReadTemper(void);	//���ܣ���ȡ�¶�ֵ����ȡһ�Ρ��¶�û����/16�������Զ�ȡ����ֵ��ʵ���¶ȵ�16����	
int DS18B20_GetTemper(void);	//���ܣ���ȡ�¶�ֵ����ȡ5�Σ�ȥ�����ֵ��Сֵ��ȡ��ƽ��ֵ��

#endif
