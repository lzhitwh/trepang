#ifndef FUNCTIONOTHER_H_
#define FUNCTIONOTHER_H_

extern unsigned char Other_Stage;

/*用于标识是否在加水测试或功能查看。
	0:表示：既不在加水测试也不在功能查看状态。
	1:表示：第一种加水测试
	2:表示：第二种加水测试
	3,4,5保留。
	7:表示功能查看，第一组。以此类推。
*/
extern unsigned char No_DisplayStatus;

extern void Function_OtherRun(void);


#endif
