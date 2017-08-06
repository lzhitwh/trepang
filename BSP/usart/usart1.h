#ifndef __USART1_H
#define	__USART1_H

#include "stm32f10x.h"
#include <stdio.h>

#define Usart_Rec_BufSize		128
#define Usart_Send_BufSize		64

extern INT8U Rec_BufSit;
extern INT8U Usart_Rec_Buf[Usart_Rec_BufSize];
extern INT8U Usart_Send_Buf[Usart_Send_BufSize];

#define USART1_DR_Base  0x40013804

extern void USART1_Config(void);
extern int Usart_GetData(char argc[],int argv);
int fputc(int ch, FILE *f);
void USART1_printf(USART_TypeDef* USARTx, uint8_t *Data,...);
void DMA_Config(void);
static void NVIC_Config(void);

#endif /* __USART1_H */
