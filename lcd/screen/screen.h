#ifndef SCREEN_H_
#define SCREEN_H_

#define uchar unsigned char 
#define uint unsigned int
#define ulong unsigned long

#define LCD_SDA			GPIO_Pin_0
#define LCD_SCK			GPIO_Pin_1
#define LCD_RS			GPIO_Pin_2
#define LCD_RST			GPIO_Pin_3
#define LCD_CS			GPIO_Pin_11
	

#define LCD_SID_L()  GPIO_ResetBits(GPIOA, LCD_SDA)
#define LCD_SID_H()  GPIO_SetBits(GPIOA, LCD_SDA)

#define LCD_SCK_L()  GPIO_ResetBits(GPIOA, LCD_SCK)
#define LCD_SCK_H()  GPIO_SetBits(GPIOA, LCD_SCK)

#define LCD_RS_L()  GPIO_ResetBits(GPIOA, LCD_RS)
#define LCD_RS_H()  GPIO_SetBits(GPIOA, LCD_RS)

#define LCD_RST_L()  GPIO_ResetBits(GPIOA, LCD_RST)
#define LCD_RST_H()  GPIO_SetBits(GPIOA, LCD_RST)

#define LCD_CS_L()  GPIO_ResetBits(GPIOA, LCD_CS)
#define LCD_CS_H()  GPIO_SetBits(GPIOA, LCD_CS)

void SCREEN_Init(void);
void SCREEN_Clear(void);
void SCREEN_Display12864(uchar *dp);
void SCREEN_Display1616(uchar page,uchar column,uchar *dp);
void SCREEN_Display816(uchar page,uchar column,uchar *dp);
void SCREEN_Display58(uchar page,uchar column,uchar *dp);

#endif
