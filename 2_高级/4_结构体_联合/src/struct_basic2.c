/* Copyright (c) 2018 我的有限公司
 * 文件名: struct_basic.c
 * 描述: 结构体变量,结构图数组的介绍和使用
 * 作者: Hyb
 * 完成日期: 2018年1月8日
 * 当前版本: 1.0
 */

#include <stdio.h>
#include <string.h>
#include "basic.h"

void out_student(struct student stu);

int main(void)
{
	/* 定义结构体变量并初始化 */
	struct student stu1 = {1, "zhangsan", "male", 20, "shanghai"};
	struct student stu2 = {2, "lisi", "male", 21, "Beijing"};
	/* 结构体变量的赋值 */
	stu2 = stu1;
	out_student(stu1);
	printf("-------------------------\n");
	out_student(stu2);
	
	return 0;
}

void out_student(struct student stu)
{
	printf("xh:%d\n",  stu.xh);
	printf("name:%s\n", stu.name);
	printf("gender:%s\n", stu.gender);
	printf("age:%d\n", stu.age);
}
