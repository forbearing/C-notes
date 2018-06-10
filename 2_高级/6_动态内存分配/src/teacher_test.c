/*
 * copyright (c) 2018 我的有限公司
 * 文件名: teacher_test.c
 * 描述: 教师操作的调用程序
 * 作者: Hyb
 * 完成日期: 2018年1月22日
 * 当前版本: 1.0
 */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "teacher.h"

int main(void)
{
	// 在栈上分配
	ElementType e1 = {1, 25, "tom", 3000};
	ElementType e2 = {2, 26, "marray", 4000};
	ElementType e3 = {3, 28, "kevin", 5000};
	
	// 在堆上分配
	PElementType p1 = (PElementType)calloc(1, sizeof(ElementType));
	p1->id = 1;
	p1->age = 25;
	p1->name = "tom";
	p1->salary = 3000;
	PElementType p2 = (PElementType)calloc(1, sizeof(ElementType));
	p2->id = 2;
	p2->age = 26;
	p2->name = "marray";
	p2->salary = 4000;
	PElementType p3 = (PElementType)calloc(1, sizeof(ElementType));
	p3->id = 3;
	p3->age = 27;
	p3->name = "kevin";
	p3->salary = 5000;
	create(3);
	add(p1);	// add(&e1);
	add(p2);	// add(&e2);
	add(p3);	// add(&e3);
	iterate();	
	printf("*********************************\n");

	PElementType p4 = (PElementType)calloc(1, sizeof(ElementType));
	p4->id = 4;
	p4->name = "tom4";
	p4->age = 28;
	p4->salary = 5500;
	insert(1,p4);

	PElementType p5 = (PElementType)calloc(1, sizeof(ElementType));
	p5->id = 5;
	p5->name = "tom5";
	p5->age = 35;
	p5->salary = 6500;
	add(p5);
	iterate();
	printf("*********************************\n");

	del(2);
	iterate();
	printf("*********************************\n");
	PElementType p = get(3);
	printf("name:%s\n", p->name);
	printf("teacher total: %d\n", size());

	destroy();
	free(p1);
	free(p2);
	free(p3);
	free(p4);
	free(p5);
	p1 = NULL;
	p2 = NULL;
	p3 = NULL;
	p4 = NULL;
	p5 = NULL;

	return 0;
}
