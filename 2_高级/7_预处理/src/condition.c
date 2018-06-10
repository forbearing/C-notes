/*
 * Copyright (C) 2018 我的有限公司
 * 文件名: condition.c
 * 描述: 条件编译
 * 作者: Hyb
 * 完成日期: 2018年1月26日
 * 当前版本: .10
 */

#include <stdio.h>

#define Condition1 0
#define Condition2 0
#define Condition3 1

#if (Condition1)
	#include "condition1.h"
#elif (Condition2)
	#include "condition2.h"
#elif (Condition3)
	#include "condition3.h"
#else
	#include "condition.h"
#endif

#define HELLO "hello Linux"
#ifndef HI
	#define HI "welcome!"
#endif

#ifdef HELLO
	int i = 10;
#endif



int main(void)
{
	printf("condition3: %s\n", CON3);
	printf("HI: %s\n", HI);
	printf("i:%d\n", i);

	return 0;
}
