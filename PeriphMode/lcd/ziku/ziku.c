#include "includes.h"

void SPI_ZikuInit(void)
{
  SPI_InitTypeDef  SPI_InitStructure;
  GPIO_InitTypeDef GPIO_InitStructure;
  
  /* Enable SPI1 and GPIO clocks */
  /*!< SPI_FLASH_SPI_CS_GPIO, SPI_FLASH_SPI_MOSI_GPIO, 
       SPI_FLASH_SPI_MISO_GPIO, SPI_FLASH_SPI_DETECT_GPIO 
       and SPI_FLASH_SPI_SCK_GPIO Periph clock enable */
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOD, ENABLE);

  /*!< SPI_FLASH_SPI Periph clock enable */
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1, ENABLE);
 
  
  /*!< Configure SPI_FLASH_SPI pins: SCK */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_Init(GPIOA, &GPIO_InitStructure);

  /*!< Configure SPI_FLASH_SPI pins: MISO */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
  GPIO_Init(GPIOA, &GPIO_InitStructure);

  /*!< Configure SPI_FLASH_SPI pins: MOSI */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;
  GPIO_Init(GPIOA, &GPIO_InitStructure);

  /*!< Configure SPI_FLASH_SPI_CS_PIN pin: SPI_FLASH Card CS pin */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_Init(GPIOA, &GPIO_InitStructure);

  /* Deselect the FLASH: Chip Select high */
  SPI_FLASH_CS_HIGH();

  /* SPI1 configuration */
  // W25X16: data input on the DIO pin is sampled on the rising edge of the CLK. 
  // Data on the DO and DIO pins are clocked out on the falling edge of CLK.
  SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
  SPI_InitStructure.SPI_Mode = SPI_Mode_Master;
  SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;
  SPI_InitStructure.SPI_CPOL = SPI_CPOL_High;
  SPI_InitStructure.SPI_CPHA = SPI_CPHA_2Edge;
  SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;
  SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_4;
  SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;
  SPI_InitStructure.SPI_CRCPolynomial = 7;
  SPI_Init(SPI1, &SPI_InitStructure);

  /* Enable SPI1  */
  SPI_Cmd(SPI1, ENABLE);
}

/************************************************/
// 集通字库处理
/***********************************************/
unsigned char SPI_TransChar(unsigned char datu)
{
  	/* Loop while DR register in not emplty */
  	while (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_TXE) == RESET);

  	/* Send byte through the SPI1 peripheral */
  	SPI_I2S_SendData(SPI1, datu);

  	/* Wait to receive a byte */
  	while (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_RXNE) == RESET);

  	/* Return the byte read from the SPI bus */
  	return SPI_I2S_ReceiveData(SPI1);
}

void SPI_ZikuWriteAddr(ulong fontaddr)
{
	SPI_ZikuWrite(0x03);
	SPI_ZikuWrite((fontaddr&0xff0000)>>16);	 	 //地址的高8位,共24位
	SPI_ZikuWrite((fontaddr&0xff00)>>8);		 //地址的中8位,共24位
	SPI_ZikuWrite(fontaddr&0xff);
}

void SPI_ZikuReadChar(ulong fontaddr,uchar *data,uchar size)
{
	int i=0;
	SPI_FLASH_CS_LOW();//	Rom_CS = 0;
	SPI_ZikuWriteAddr(fontaddr);
	for(i=0;i<size;i++)
	{
		data[i]=SPI_ZikuRead();
	}
	SPI_FLASH_CS_HIGH();//	Rom_CS=1;
}
