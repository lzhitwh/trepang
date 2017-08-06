#ifndef KEY_H_
#define KEY_H_

//extern unsigned char Key_Num;
//extern unsigned int Key_Time;

/*
	功能：按键初始化函数
*/
void KEY_GPIO_Config(void);
	
/*
	功能：矩阵键盘检测函数
	参数：1：按键值 2：按键按下多少个10ms
*/  
void KEY_Scan(unsigned char *key_num,unsigned int *key_time);

#endif
