#ifndef _FUNCTION_H_
#define _FUNCTION_H_

///****************************************************************************
//	���ܣ�����ȫ�ֱ����������������й��̡�
//	0����ʾ�������������幦�ܡ�
//	1����ʾ���ӹ��ܡ�
//	2����ʾ���еĽ׶Ρ�				
//	3����ʾ�����Ƿ��Ѿ���ϴ��0��û����ϴʱ�䡣1������ϴ��û��ϴ��2����ϴ��ɡ�
//	4����ʾˮ·�Ƿ�ͨ����0��ͨ����1����ͨ��
//	5����ʾ�������Ƿ�������������0���ܡ�1������
//	6����ʾ���Ƿ��ڸ��ա�0��������1������
//*****************************************************************************/
//unsigned char Lcd_DisplayStatus[8]={0,0,0,0,0,0,0,0};

/*
	���������ź�����������Ϣ���䡣
*/
typedef struct
{
	OS_EVENT *Usart_Rec_Event;  	//���崮�ڽ����ź���
	OS_EVENT *Key_Num_Event;  		//���尴���ź���
	OS_EVENT *Time_Run_Event;		//����ʱ�������ź���������ָʾ����ʱ��ĺ���
	OS_EVENT *Lcd_Display_Event;  	//����Һ����ʾ�ź���
	OS_EVENT *Update_Time_Event;	//��̬����ʱ���ź���
	OS_EVENT *Method_Other_Event;	//��ˮ�����ź���
}SemEventSets;
extern SemEventSets SemEventSet;


/****************************************************************************
	���ܣ�����ȫ�ֱ����������������й��̡�
	0����ʾ�������������幦�ܡ�
	1����ʾ���ӹ��ܡ�
	2����ʾ���еĽ׶Ρ�				
	3����ʾ�����Ƿ��Ѿ���ϴ��0��û����ϴʱ�䡣1������ϴ��û��ϴ��2����ϴ��ɡ�
	4����ʾˮ·�Ƿ�ͨ����0��ͨ����1����ͨ��
	5����ʾ�������Ƿ�������������0���ܡ�1������
	6����ʾ���Ƿ��ڸ��ա�0��������1������
*****************************************************************************/
typedef struct
{
	unsigned char funcKey;				//�������幦��,�����˿�����ʵ����һ�๦�ܡ�
	unsigned int funcKeyTime;			//���ܰ�������ʱ����
	unsigned int function;				//�������ܡ������˿���������ʵ����һ���ܡ�
	unsigned int stage;					//ÿһ���幦��ʵ�ֽ׶Ρ�
	unsigned int clearStatus;			//�����Ƿ���ϴ��
	unsigned char isWater;				//ˮ·�Ƿ�ͨ����  		1:����������0:ˮ·������
	unsigned char isHeater;				//�������Ƿ�����������
	unsigned char isDry;				//���Ƿ���ա�
	unsigned char currKey;				//��ǰ���°���ֵ��
	unsigned int currKeyTime;			//��ǰ��������ʱ����
}FunctionsStatus;
extern FunctionsStatus FuncStatus;


/*
	���ܣ�Һ����ʾ��ز���
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
	LCD_DisplayTypes LCD_DisplayType;	//Һ����ʾ���͡�
	LCD_DisplayStatus isPositive;  		//Һ����������ʾ��
	
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
