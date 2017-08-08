#ifndef _ZIKU_H_
#define _ZIKU_H_

#include"includes.h"

#define  uchar unsigned char
#define  uint unsigned int
#define  ulong unsigned long

#define SPI_FLASH_CS_LOW()       GPIO_ResetBits(GPIOA, GPIO_Pin_4)
#define SPI_FLASH_CS_HIGH()      GPIO_SetBits(GPIOA, GPIO_Pin_4)

void SPI_ZikuInit(void);
#define SPI_ZikuRead( ) 	SPI_TransChar(0xff)
#define SPI_ZikuWrite(data)	SPI_TransChar(data)
void SPI_ZikuWriteAddr(unsigned long fontaddr);
void SPI_ZikuReadChar(ulong fontaddr,uchar *data,uchar size);

#endif
