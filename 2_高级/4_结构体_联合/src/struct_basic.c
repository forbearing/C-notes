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
	/* 定义结构体变量 */
	struct student stu1, stu2;
	stu1.xh = 1;
	//stu1.name = "zhangsan";
	//stu1.gender = "male";
	strcpy(stu1.name, "zhangsan");
	strcpy(stu1.gender, "male");
	stu1.age = 20;
	/* 结构体变量的赋值 */
	stu2 = stu1;
	//scanf("%d %s %s %d\n", &stu2.xh, stu2.name, stu2.gender, &stu2.age);
	out_student(stu1);
	printf("-------------------------\n");
	out_student(stu2);

	/* 定义结构体数组并初始化 */
	struct student stus1[] = {stu1, stu2}
	struct student stus2[] = {
		{3,"Tom", "male", 23, addr},
		{4, "mary", "female", 22,
			{"China", "nanjing", "zhongsan road"}}
	}
	
	return 0;
}

void out_student(struct student stu)
{
	printf("xh:%d\n",  stu.xh);
	printf("name:%s\n", stu.name);
	printf("gender:%s\n", stu.gender);
	printf("age:%d\n", stu.age);
}
