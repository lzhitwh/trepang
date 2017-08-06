#ifndef UPDATETIME_H_
#define UPDATETIME_H_

extern unsigned char Time_Page,Time_Colum,Time_Num; //全局变量。用于标记更新时间的位置，数值。
void Update_Time(void);
void Time_RunMuch(void);

#endif
