/*
 * copyright (c) 2018 我的有限公司
 * 文件名: sort_test.c
 * 描述: 排序的调用程序
 * 作者: Hyb
 * 完成日期: 2018年1月23日
 * 当前版本: 1.0
 */

#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

int compare(PElementType p1, PElementType p2)
{
	if(p1->salary > p2->salary) return 1;
	if(p1->salary < p2->salary) return -1;
	if(p1->salary == p2->salary) return 0;
}

/* 获得排序的数据 */
PElementType data()
{
	PElementType p = (PElementType)calloc(3, sizeof(ElementType));
	if(p == NULL){
		printf("get data error\n");
		exit(1);
	}
	p[0].id = 1;
	p[0].name = "zhang";
	p[0].age = 28;
	p[0].salary = 3000;
	p[1].id = 2;
	p[1].name = "li";
	p[1].age = 22;
	p[1].salary = 2000;
	p[2].id = 3;
	p[2].name = "wang";
	p[2].age = 24;
	p[2].salary = 5000;
	
	return p;
}

void out(PElementType p, uint_t n)
{
	if(p == NULL){
		printf("out data error\n");
		exit(1);
	}
	int i;
	for(i=0; i<n; i++){
		printf("%d %s %d %.2f\n", 
				(p+i)->id, (p+i)->name, (p+i)->age, (p+i)->salary);
	}
}

int main(void)
{
	PElementType p = data(); 
	out(p,3);
	printf("----------------- after sort ------------------\n");
	data_sort(p, 3, compare);
	out(p,3);

	return 0;
}
