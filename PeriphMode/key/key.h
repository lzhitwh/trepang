#ifndef KEY_H_
#define KEY_H_

//extern unsigned char Key_Num;
//extern unsigned int Key_Time;

/*
	���ܣ�������ʼ������
*/
void KEY_GPIO_Config(void);
	
/*
	���ܣ�������̼�⺯��
	������1������ֵ 2���������¶��ٸ�10ms
*/  
void KEY_Scan(unsigned char *key_num,unsigned int *key_time);

#endif
