/*
 * Copyright (c) 2018 我的有限公司
 * 文件名: char_pointer_array.c
 * 描述: 字符指针数组的介绍和使用
 * 作者: Hyb
 * 完成日期: 2018年1月20日
 * 当期版本: 1.0
 */

#include <stdio.h>
#include <string.h>

/* 输出字符指针数组 */
void out_name(char *name[], int n)
{
	int i;
	for(i=0; i<n ;i++){
		printf("%s  ",name[i]);
	}
	printf("\n");
}

/* 数组字符指针数组 */
void out_name2(char **pp, int n)
{
	int i;
	for(i=0; i<n; i++){
		printf("%s ", *(pp+i));
	}
	printf("\n");
}

/* 字符指针数组排序 */
void sort(char *names[], int n)
{
	int i,j;
	for(i=0; i<n-1; i++){
		int pos = i;
		for(j=i+1; j<n; j++){
			if(strcmp(names[j],names[pos]) < 0)
				pos = j;
		}
		if(pos != i){
			char *temp;
			temp = names[i];
			names[i] = names[pos];
			names[pos] = temp;
		}
	}
}

int main(void)
{
	char *names[] = {"Zhangsan", "Lisi", "Wangwu"};
	printf("names[0]:%s, names[0]:%p\n", names[0], names[0]);
	//*(names[0]) = 'z';			// 段错误,操作的是数据区的常量区
	out_name(names, 3);
	out_name2(names, 3);

	printf("***** after sort *****\n");
	sort(names, 3);
	out_name2(names, 3);

	return 0;
}
