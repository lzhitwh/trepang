#include "includes.h"

static OS_STK TASK_Master_Stk[TASK_Master_Stk_Size];

int main(void)
{
	BSP_Init();
	OSInit();

	OSTaskCreate(TASK_Master,
		         (void *)0,
	              &TASK_Master_Stk[TASK_Master_Stk_Size-1],
				  TASK_Master_Prio);    	//功能运行线程,完成主体部分运行。

	OSStart();

	return 0;
}

