/******************** (C) COPYRIGHT 2012 WildFire Team ***************************
 * 硬件连接：------------------------
 *          | PA9  - USART1(Tx)      |
 *          | PA10 - USART1(Rx)      |
 *           ------------------------
**********************************************************************************/
#include "includes.h"

INT8U Rec_BufSit=0;

INT8U Usart_Rec_Buf[Usart_Rec_BufSize];
INT8U Usart_Send_Buf[Usart_Send_BufSize];

/*
 * 函数名：USART1_Config
 * 描述  ：USART1 GPIO 配置,工作模式配置。115200 8-N-1
 * 输入  ：无
 * 输出  : 无
 * 调用  ：外部调用
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
 * 函数名：DMA_Config
 * 描述  ：DMA 串口的初始化配置
 * 输入  ：无
 * 输出  : 无
 * 调用  ：外部调用
 */
void DMA_Config(void)
{
    DMA_InitTypeDef DMA_InitStructure;

	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);	//开启DMA时钟
	NVIC_Config();	   									//配置DMA中断
 	/*设置DMA源：内存地址&串口数据寄存器地址*/
    DMA_InitStructure.DMA_PeripheralBaseAddr = USART1_DR_Base;	   
	/*内存地址(要传输的变量的指针)*/
    DMA_InitStructure.DMA_MemoryBaseAddr = (u32)Usart_Rec_Buf;
	/*方向：从外设到内存*/		
    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;	
	/*传输大小DMA_BufferSize=SENDBUFF_SIZE*/	
    DMA_InitStructure.DMA_BufferSize = Usart_Rec_BufSize;
	/*外设地址不增*/	    
    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable; 
	/*内存地址自增*/
    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;	
	/*外设数据单位*/	
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
	/*内存数据单位 8bit*/
    DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;	 
	/*DMA模式：一次传输，循环*/
    DMA_InitStructure.DMA_Mode = DMA_Mode_Circular ;	 
	/*优先级：中*/	
    DMA_InitStructure.DMA_Priority = DMA_Priority_Medium; 
	/*禁止内存到内存的传输	*/
    DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;
	   
	/*配置DMA1的5通道*/		   
    DMA_Init(DMA1_Channel5, &DMA_InitStructure); 	   
	
	DMA_Cmd (DMA1_Channel5,ENABLE);					//使能DMA
	USART_DMACmd(USART1, USART_DMAReq_Rx, ENABLE);	
}
/*
 * 函数名：NVIC_Config
 * 描述  ：DMA 中断配置
 * 输入  ：无
 * 输出  : 无
 * 调用  ：外部调用
 */
static void NVIC_Config(void)
{
  	NVIC_InitTypeDef NVIC_InitStructure;
  
  	/* Configure one bit for preemption priority */
  	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
  
  	/* 配置P[A|B|C|D|E]0为中断源 */
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


//重定义使得串口也可以使用printf
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
//自定义USART通过此函数实现串口与电脑的通信
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
