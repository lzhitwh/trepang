#include "includes.h"

//unsigned char Key_Num=0;
//unsigned int Key_Time=0;

#define Delay_ms(x)    OSTimeDlyHMSM(0,0,0,x)

void KEY_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_10|GPIO_Pin_11;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP; 	//设置为推挽输出
	GPIO_InitStructure.GPIO_Speed= GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStructure);
				  
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU; 	//设置为推挽输出
	GPIO_InitStructure.GPIO_Speed= GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStructure);
	GPIO_ResetBits(GPIOB,GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_10|GPIO_Pin_11);		   
}

void KEY_RowColChange(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_10|GPIO_Pin_11;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP; 	//设置为推挽输出
	GPIO_InitStructure.GPIO_Speed= GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU; 	//设置为推挽输出
	GPIO_InitStructure.GPIO_Speed= GPIO_Speed_10MHz;
	GPIO_Init(GPIOB,&GPIO_InitStructure);
	GPIO_ResetBits(GPIOB,GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_10|GPIO_Pin_11);
}

void KEY_ColRowChange(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_10|GPIO_Pin_11;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU; 	//设置为推挽输出
	GPIO_InitStructure.GPIO_Speed= GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP; 	//设置为推挽输出
	GPIO_InitStructure.GPIO_Speed= GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStructure);
	GPIO_ResetBits(GPIOB,GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15);
}

													  
void KEY_Scan(unsigned char *key_num,unsigned int *key_time)
{
	unsigned int row=0,col=0;
	*key_num=0;
	*key_time=0;

	row = GPIO_ReadInputData(GPIOB)&0xf000;
	if(row != 0xf000)
	{
		KEY_ColRowChange();
		Delay_ms(10);
		col = GPIO_ReadInputData(GPIOB)&0x0f00;
		if(col != 0x0f00)
		{
		     switch((row|col)>>8)
			 {
			 	case  0xee:	 *key_num = 15;
				break;
				case  0xed:	 *key_num = 16;
				break;
				case  0xeb:	 *key_num = 13;
				break;
				case  0xe7:	 *key_num = 14;
				break;

				case  0xde:	 *key_num = 9;
				break;
				case  0xdd:	 *key_num = 10;
				break;
				case  0xdb:	 *key_num = 11;
				break;
				case  0xd7:	 *key_num = 12;
				break;

				case  0xbe:	 *key_num = 5;
				break;
				case  0xbd:	 *key_num = 6;
				break;
				case  0xbb:	 *key_num = 7;
				break;
				case  0xb7:	 *key_num = 8;
				break;

				case  0x7e:	 *key_num = 1;
				break;
				case  0x7d:	 *key_num = 2;
				break;
				case  0x7b:	 *key_num = 3;
				break;
				case  0x77:	 *key_num = 4;
				break;

				default :  	 *key_num = 0;
				break;
			 }
			 while((GPIO_ReadInputData(GPIOB)&0x0f00) != 0x0f00)
			 {	
			 	Delay_ms(10);
				(*key_time)++;
			 }
		}
	}
	KEY_RowColChange();
}
