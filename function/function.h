#ifndef _FUNCTION_H_
#define _FUNCTION_H_

///****************************************************************************
//	功能：定义全局变量作用于整个运行过程。
//	0：标示按键，决定主体功能。
//	1：标示附加功能。
//	2：标示进行的阶段。				
//	3：标示海参是否已经清洗。0：没到清洗时间。1：该清洗但没清洗。2：清洗完成。
//	4：标示水路是否通畅。0：通畅。1：不通畅
//	5：标示电热盘是否能正常工作。0：能。1：不能
//	6：标示锅是否在干烧。0：正常。1：干烧
//*****************************************************************************/
//unsigned char Lcd_DisplayStatus[8]={0,0,0,0,0,0,0,0};

/*
	程序所需信号量，用于信息传输。
*/
typedef struct
{
	OS_EVENT *Usart_Rec_Event;  	//定义串口接收信号量
	OS_EVENT *Key_Num_Event;  		//定义按键信号量
	OS_EVENT *Time_Run_Event;		//定义时间运行信号量，启动指示运行时间的函数
	OS_EVENT *Lcd_Display_Event;  	//定义液晶显示信号量
	OS_EVENT *Update_Time_Event;	//动态更新时间信号量
	OS_EVENT *Method_Other_Event;	//加水测试信号量
}SemEventSets;
extern SemEventSets SemEventSet;


/****************************************************************************
	功能：定义全局变量作用于整个运行过程。
	0：标示按键，决定主体功能。
	1：标示附加功能。
	2：标示进行的阶段。				
	3：标示海参是否已经清洗。0：没到清洗时间。1：该清洗但没清洗。2：清洗完成。
	4：标示水路是否通畅。0：通畅。1：不通畅
	5：标示电热盘是否能正常工作。0：能。1：不能
	6：标示锅是否在干烧。0：正常。1：干烧
*****************************************************************************/
typedef struct
{
	unsigned char funcKey;				//程序主体功能,决定了控制器实现哪一类功能。
	unsigned int funcKeyTime;			//功能按键按下时长。
	unsigned int function;				//二级功能。决定了控制器具体实现哪一功能。
	unsigned int stage;					//每一具体功能实现阶段。
	unsigned int clearStatus;			//海参是否清洗。
	unsigned char isWater;				//水路是否通畅。  		1:正常工作，0:水路不畅。
	unsigned char isHeater;				//电热盘是否正常工作。
	unsigned char isDry;				//锅是否干烧。
	unsigned char currKey;				//当前按下按键值。
	unsigned int currKeyTime;			//当前按键按下时长。
}FunctionsStatus;
extern FunctionsStatus FuncStatus;


/*
	功能：液晶显示相关参数
*/
typedef enum
{
	LCD_char12864=1,
	LCD_charGB2312,
	LCD_char58,
	LCD_numInt,
	LCD_image12864
}LCD_DisplayTypes;
typedef enum
{
	false=0,
	true
	
}LCD_DisplayStatus;
typedef struct
{
	LCD_DisplayTypes LCD_DisplayType;	//液晶显示类型。
	LCD_DisplayStatus isPositive;  		//液晶正反向显示。
	
	union dataParam
	{
		struct char12864
		{
			unsigned char **data;
		}char12864;
		struct image12864
		{
			unsigned char *data;
		}image12864;
		struct charGB2312
		{
			unsigned char row;
			unsigned char col;
			unsigned char *data;
		}charGB2312,char58;
		struct numInt
		{
			unsigned char row;
			unsigned char col;
			unsigned int data;
		}numInt;
	}dataParam;
}LCD_DisplayParams;
extern LCD_DisplayParams LCD_DisplayParam;


extern unsigned char Operation_TheAction;
void Set_Function(void);
void Function_WaterAndDisplay(void);

#endif
