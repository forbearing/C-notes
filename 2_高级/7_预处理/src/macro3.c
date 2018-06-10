/*
 * copyright (c) 2018 我的有限公司
 * 文件名: macro3.c
 * 描述: 宏定义
 * 作者: Hyb
 * 完成日期: 2018年1月23日
 * 当前版本: 1.0
 */

#include <stdio.h>

#define PRINT(FORMAT,VALUE)  printf("The value is: " FORMAT "\n", VALUE);
#define HELLO "hello world"
#define PRINT2(INFO)  printf("Welcom %s and %s\n", INFO, HELLO);

int main(void)
{
	int x = 1;
	PRINT("%d", x +3);
	PRINT2("hyb");

	return 0;
}
