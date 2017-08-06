#ifndef _DM13A_H_
#define _DM13A_H_

#define DM13A_DAI_H	 	GPIO_SetBits(GPIOB,GPIO_Pin_0)
#define DM13A_DAI_L		GPIO_ResetBits(GPIOB,GPIO_Pin_0)	
#define DM13A_DCK_H		GPIO_SetBits(GPIOB,GPIO_Pin_1)
#define DM13A_DCK_L		GPIO_ResetBits(GPIOB,GPIO_Pin_1)
#define DM13A_LAT_H		GPIO_SetBits(GPIOB,GPIO_Pin_5)
#define DM13A_LAT_L		GPIO_ResetBits(GPIOB,GPIO_Pin_5)
#define DM13A_EN_H		GPIO_SetBits(GPIOB,GPIO_Pin_6)
#define DM13A_EN_L		GPIO_ResetBits(GPIOB,GPIO_Pin_6)

#define Water_On()		GPIO_ResetBits(GPIOC,GPIO_Pin_7)
#define Water_Off()		GPIO_SetBits(GPIOC,GPIO_Pin_7)

#define Cold_On()		GPIO_ResetBits(GPIOC,GPIO_Pin_8)
#define Cold_Off()		GPIO_SetBits(GPIOC,GPIO_Pin_8)

#define HotBig_On()		GPIO_ResetBits(GPIOC,GPIO_Pin_1|GPIO_Pin_2)
#define HotSmall_Off()	GPIO_SetBits(GPIOC,GPIO_Pin_1);GPIO_ResetBits(GPIOC,GPIO_Pin_2)
#define Hot_Off()		GPIO_SetBits(GPIOC,GPIO_Pin_1|GPIO_Pin_2)

void DM13A_GPIO_Config(void);
void Led_OnTheNum(unsigned char num);
void Relay_Init(void);

#endif
