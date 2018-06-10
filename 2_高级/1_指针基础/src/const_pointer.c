/*
 * Copyright (c) 我的有限公司
 * 文件名: const_pointer.c
 * 描述: 指针常量的介绍和使用
 * 作者: hyb
 * 完成日期: 2018年1月2日
 * 当前版本: 1.0
 */

#include <stdio.h>

void out_salary(float const *p)
{
	//*p = 10000.0f;
	printf("salary: %f\n", *p);
}

int main(void)
{
	int a = 3;
	int b = 4;
	/* 常量指针
	 * 1:通过该指针不可以去修改它所指向的存储单元中的值
	 * 2:指针本身即地址可以被修改
	 */
	int const *pci = &a;
	pci = &b;
	//*pci = 5;
	printf("b:%d *pci: %d\n", b, *pci);
	int *p = &b;
	*p = 5;
	printf("b:%d *p: %d\n", b, *p);

	
	float salary = 5000.0f;
	out_salary(&salary);

	return 0;
}
