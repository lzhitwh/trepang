#include "includes.h"

static OS_STK TASK_Master_Stk[TASK_Master_Stk_Size];

int main(void)
{
	BSP_Init();
	OSInit();

	OSTaskCreate(TASK_Master,
		         (void *)0,
	              &TASK_Master_Stk[TASK_Master_Stk_Size-1],
				  TASK_Master_Prio);    	//���������߳�,������岿�����С�

	OSStart();

	return 0;
}

