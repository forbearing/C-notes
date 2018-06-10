/*
 * Copyright (c) 2018 我的有限公司
 * 文件名: byte.c
 * 描述: 字节对齐
 * 作者: Hyb
 * 完成日期: 2018年1月15日
 * 当期版本: 1.0
 */

#include <stdio.h>

int main(void)
{
	#pragma pack(2)
	typedef struct{
		int a;
		char b;
		short c;
	}A;
	#pragma pack()
	#pragma pack(1)
	typedef struct{
		char a;
		int b;
		short c;
	}B;
	#pragma pack()
	printf("A szie: %ld\n", sizeof(A));
	printf("B size: %ld\n", sizeof(B));

	struct E{
		char a;
		char reversed[3];
		int b;
	};
	printf("E size: %ld\n", sizeof(struct E));

	return 0;
}
