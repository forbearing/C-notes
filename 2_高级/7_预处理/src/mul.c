/*
 * Copyright (c) 2018 我的有限公司
 * 文件名: mul.c
 * 描述: 重复包含
 * 作者: Hyb
 * 完成日期: 2018年1月26日
 * 当前版本: .10
 */

#include <stdio.h>
#include "a.h"
#include "b.h"
#include "a.h"
#include "b.h"

int main(void)
{
	printf("HELLO: %s\n", HELLO);

	return 0;
}
