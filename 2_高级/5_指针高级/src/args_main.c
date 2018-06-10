/*
 * Copyright (c) 2018 我的有限公司
 * 文件名: args_main.c
 * 描述: 带参主函数
 * 作者: Hyb
 * 当期日期: 2018年1月20日
 * 当期版本: 1.0
 */

#include <stdio.h>

int main(int argc, char *argv[])
{
	printf("argc:%d\n", argc);
	int i;
	for(i=1; i<argc; i++){
		printf("%s ", argv[i]);
		//printf("%s ",*(argv+i));
	}
	printf("\n");

	return 0;
}
