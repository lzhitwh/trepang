/******************** (C) COPYRIGHT 2012 WildFire Team ***************************
 * Ӳ�����ӣ�------------------------
 *          | PA9  - USART1(Tx)      |
 *          | PA10 - USART1(Rx)      |
 *           ------------------------
**********************************************************************************/
#include "includes.h"

INT8U Rec_BufSit=0;

INT8U Usart_Rec_Buf[Usart_Rec_BufSize];
INT8U Usart_Send_Buf[Usart_Send_BufSize];

/*
 * ��������USART1_Config
 * ����  ��USART1 GPIO ����,����ģʽ���á�115200 8-N-1
 * ����  ����
 * ���  : ��
 * ����  ���ⲿ����
 */
void USART1_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	
	/* config USART1 clock */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1 | RCC_APB2Periph_GPIOA, ENABLE);
	
	/* USART1 GPIO config */
	/* Configure USART1 Tx (PA.09) as alternate function push-pull */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);    
	/* Configure USART1 Rx (PA.10) as input floating */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	  
	/* USART1 mode config */
	USART_InitStructure.USART_BaudRate =9600; //115200;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No ;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	USART_Init(USART1, &USART_InitStructure); 
	USART_ITConfig(USART1, USART_IT_IDLE, ENABLE);
	USART_Cmd(USART1, ENABLE); 
}
/*
 * ��������DMA_Config
 * ����  ��DMA ���ڵĳ�ʼ������
 * ����  ����
 * ���  : ��
 * ����  ���ⲿ����
 */
void DMA_Config(void)
{
    DMA_InitTypeDef DMA_InitStructure;

	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);	//����DMAʱ��
	NVIC_Config();	   									//����DMA�ж�
 	/*����DMAԴ���ڴ��ַ&�������ݼĴ�����ַ*/
    DMA_InitStructure.DMA_PeripheralBaseAddr = USART1_DR_Base;	   
	/*�ڴ��ַ(Ҫ����ı�����ָ��)*/
    DMA_InitStructure.DMA_MemoryBaseAddr = (u32)Usart_Rec_Buf;
	/*���򣺴����赽�ڴ�*/		
    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;	
	/*�����СDMA_BufferSize=SENDBUFF_SIZE*/	
    DMA_InitStructure.DMA_BufferSize = Usart_Rec_BufSize;
	/*�����ַ����*/	    
    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable; 
	/*�ڴ��ַ����*/
    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;	
	/*�������ݵ�λ*/	
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
	/*�ڴ����ݵ�λ 8bit*/
    DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;	 
	/*DMAģʽ��һ�δ��䣬ѭ��*/
    DMA_InitStructure.DMA_Mode = DMA_Mode_Circular ;	 
	/*���ȼ�����*/	
    DMA_InitStructure.DMA_Priority = DMA_Priority_Medium; 
	/*��ֹ�ڴ浽�ڴ�Ĵ���	*/
    DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;
	   
	/*����DMA1��5ͨ��*/		   
    DMA_Init(DMA1_Channel5, &DMA_InitStructure); 	   
	
	DMA_Cmd (DMA1_Channel5,ENABLE);					//ʹ��DMA
	USART_DMACmd(USART1, USART_DMAReq_Rx, ENABLE);	
}
/*
 * ��������NVIC_Config
 * ����  ��DMA �ж�����
 * ����  ����
 * ���  : ��
 * ����  ���ⲿ����
 */
static void NVIC_Config(void)
{
  	NVIC_InitTypeDef NVIC_InitStructure;
  
  	/* Configure one bit for preemption priority */
  	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
  
  	/* ����P[A|B|C|D|E]0Ϊ�ж�Դ */
  	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  	NVIC_Init(&NVIC_InitStructure);
}


//int Usart_GetData(char argc[],int argv){
//	int i=0;
//	while((Usart_Rec_Buf[Rec_BufSit]!='\n')&&(i!=argv))
//	{
//		argc[i++] = Usart_Rec_Buf[Rec_BufSit++];
//		if(Rec_BufSit == Usart_Rec_BufSize)
//		{
//			 Rec_BufSit=0;
//		}
//	}
//	if((i!=argv)&&(i!=0))
//	{
//		Rec_BufSit++;
//		if(Rec_BufSit == Usart_Rec_BufSize)
//		{
//			 Rec_BufSit=0;
//		}
//		if(argc[i-1]=='\r')
//		{
//			return (--i);
//		}	
//	}
//	if(i==argv)
//	{
//	  	return -1;
//	}
//	if(i==0)
//	{
//	 	return 0;
//	}
//}


//�ض���ʹ�ô���Ҳ����ʹ��printf
int fputc(int ch, FILE *f)
{
	USART_SendData(USART1, (unsigned char) ch);
	while(USART_GetFlagStatus(USART1,USART_FLAG_TC)!=SET);
	return (ch);
}

static char	*itoa(int value, char *string, int radix)
{
	int i,d;
	int flag=0;
	char *ptr=string;
	if(radix!=10)
	{
		*ptr=0;
		return string;
	}
	if(!value)
	{
		*ptr++=0x30;
		*ptr=0;
		return string;
	}
	if(value<0)
	{
		*ptr++='-';
		value*=-1;
	}
	for(i=10000;i>0;i/=10)
	{
		d=value/i;
		if(d||flag)
	    {
			*ptr++=(char)(d+0x30);
			value-=(d*i);
			flag=1;
	 	}
	}
	*ptr=0;
	return string;
}
//�Զ���USARTͨ���˺���ʵ�ִ�������Ե�ͨ��
void USART1_printf(USART_TypeDef* USARTx,uint8_t *Data,...)
{
	const char *s;
	int d;
	char buf[16];
	va_list ap;
	va_start(ap, Data);
	while(*Data!=0)
	{
	 	if(*Data==0x5c)
		{
			switch(*++Data)
			{
				case 'r':
					USART_SendData(USARTx,0x0d);
					Data++;
					break;
				case 'n':
					USART_SendData(USARTx,0x0a);
					Data++;
					break;
				default:
					Data++;
					break;
			}
		}
		else if(*Data=='%')
		{
			switch(*++Data)
			{
				case 's':
					s=va_arg(ap,const char*);
					for(;*s;s++)
					{
						USART_SendData(USARTx,*s);
						while(USART_GetFlagStatus(USARTx,USART_FLAG_TC)==RESET);
					}
					Data++;
					break;

			     case 'd':
				 	  d=va_arg(ap,int);
					  itoa(d,buf,10);
					  for(s=buf;*s;s++)
					  {
					   	  USART_SendData(USARTx,*s);
						  while(USART_GetFlagStatus(USARTx,USART_FLAG_TC)==RESET);
					  }
					  Data++;
					  break;
				  default:
				  	   Data++;
					   break;
			}
		}
		else USART_SendData(USARTx, *Data++);
		while(USART_GetFlagStatus(USARTx,USART_FLAG_TC)==RESET);
	}
}
