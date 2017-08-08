/**********************************************************************************
 * �ļ���  ��led.c
 * ����    ��led Ӧ�ú�����         
 * ʵ��ƽ̨��NiRen_TwoHeartϵͳ��
 * Ӳ�����ӣ�  PA8 -> LED1       
 * ��汾  ��ST_v3.5
**********************************************************************************/

#include "includes.h"
	   
/*******************************************************************************
* ������  : LED_GPIO_Config
* ����    : LED IO����
* ����    : ��
* ���    : ��
* ����    : �� 
* ˵��    : LED(1~4)��IO�ڷֱ���:PB5,PB6,PB7,PB8
*******************************************************************************/
void LED_GPIO_Config(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;				//����һ��GPIO_InitTypeDef���͵�GPIO��ʼ���ṹ��
	
	RCC_APB2PeriphClockCmd(LED_RCC, ENABLE);			//ʹ��GPIOB������ʱ��	
	
	GPIO_InitStructure.GPIO_Pin = LED;				    //ѡ��Ҫ��ʼ����GPIOB����(PB5,PB6,PB7,PB8)
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;	//�������Ź���ģʽΪͨ��������� 		
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	//������������������Ϊ50MHz
	GPIO_Init(LED_PORT, &GPIO_InitStructure);			//���ÿ⺯���е�GPIO��ʼ����������ʼ��GPIOB�е�PB5,PB6,PB7,PB8����

	LED_ON();										//�ر�LED  					 
}

/*����LED.PA8*/
void LED_OFF(void) 
{
	GPIO_SetBits(LED_PORT,LED);
}

/*�ر�LED.PA8*/
void LED_ON(void)
{
	GPIO_ResetBits(LED_PORT,LED);
}

