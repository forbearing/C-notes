/*
 * Copyright (c) 2018 我的有限公司
 * 文件名: demo_test.c
 * 描述: 重复包含
 * 作者: Hyb
 * 完成日期: 2018年1月26日
 * 当前版本: 1.0
 */

#include <stdio.h>
#include "demo.h"
#include "demo.h"

int main(void)
{
	printf("a:%d\n", a);

	return 0;
}
