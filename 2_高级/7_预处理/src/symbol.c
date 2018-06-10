/*
 * Copyright (c) 2018 我的有限公司
 * 文件名: symbol.c
 * 描述: 预处理操作,预定义宏和其他指令
 * 作者: Hyb
 * 完成日期: 2018年1月26日
 * 当前版本: .10
 */

#include <stdio.h>

/*
#define TRUE 1
#if defined (TRUE) && !defined (FALSE)
	#error You need to define FALSE too
#elif defined (FALSE) && !defined(TRUE)
	#error You need to define TRUE too
#endif
*/

#line 100 "symbol.c"

#pragma message("hello linux")

#define PRINT(FORMAT,VALUE) \
	printf("the value of" #VALUE "is: " FORMAT "\n", VALUE)
#define ADD_TO_SUM(sum_number,value) \
	sum##sum_number += value

int main(void)
{
	printf("Just a test!\n");
	
	int x = 10;
	PRINT("%d", x+2);

	int sum5 = 0;
	ADD_TO_SUM(5, 25);
	printf("sum5: %d\n", sum5);

	printf("file name: %s\n", __FILE__);
	printf("current line: %d\n", __LINE__);
	printf("compile data: %s\n", __DATE__);
	printf("compile time: %s\n", __TIME__);
	printf("current func: %s\n", __func__);

	return 0;
}
