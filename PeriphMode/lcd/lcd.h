#ifndef LCD_H_
#define LCD_H_

void LCD_Init(void);
#define LCD_Clear()				SCREEN_Clear()
#define LCD_Display12864(dat,status)   SCREEN_Display12864(dat,status)
//void LCD_DisplayChar1616(ulong fontaddr,uchar page,uchar column);
//void LCD_DisplayChar816(ulong fontaddr,uchar page,uchar column);
//void LCD_DisplayChar58(ulong fontaddr,uchar page,uchar column); 
void LCD_DisplayGB2312(uchar page,uchar column,uchar *text,uchar status);
void LCD_DisplayString58(uchar page,uchar column,uchar *text,uchar status);
void LCD_DisplayNum(unsigned char page,unsigned char col,unsigned int num,uchar status);

void LCD_Display(void);

#endif
