/*
 * Copyright (c) 我的有限公司
 * 文件名: struct_pointer.c
 * 描述: 结构体指针的介绍
 * 作者: Hyb
 * 完成日期: 2018年1月14日
 * 当期版本: 1.0
 */

#include <stdio.h>
#include <string.h>
#include "basic2.h"

int main(void)
{
	struct address addr1 = {"china", "shanghai", "beijing road"};
	struct student stu1 = {1, "zhangsan", "male", 20, &addr1};
	/* 定义结构体指针 */
	struct student *stup1 = &stu1;
	printf("name: %s\n", stup1->name);
	printf("gender: %s\n", (*stup1).gender);
	printf("city: %s\n", stup1->addr->city);

	return 0;
}
