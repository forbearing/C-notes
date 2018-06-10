/*
 * Copyright (c) 我的有限公司
 * 文件名: char_array.c
 * 描述: 字符数组的定义和初始化
 * 作者: hyb
 * 完成日期: 2018年1月6号
 * 当前版本: 1.0
 */

#include <stdio.h>
#include <string.h>

char global_array[5];

int main(void)
{
	char local_array[5];
	/* 定义字符数组并初始化 */
	//char array1[] = {'h','e','l','l','o','\0'};
	//char array1[] = {'h','e','l','\0','l','o','\0'};
	char array1[] = {'h','e','l','l','o'};
	char array2[] = "hello";
	char array3[] = {"hello"};
	char array4[4] = {"hello"};
	char array5[5] = {"hello"};
	char array6[6] = {"hello"};

	printf("global_array:%s size:%d length:%d\n",
			global_array, sizeof(global_array), strlen(global_array));
	printf("local_array:%s size:%d length:%d\n",
			local_array, sizeof(local_array), strlen(local_array));
	printf("array1:%s size:%d length:%d\n",
			array1, sizeof(array1), strlen(array1));
	printf("array2:%s size:%d length:%d\n",
			array2, sizeof(array2), strlen(array2));
	printf("array3:%s size:%d length:%d\n",
			array3, sizeof(array3), strlen(array3));
	printf("array4:%s size:%d length:%d\n",
			array4, sizeof(array4), strlen(array4));
	printf("array5:%s size:%d length:%d\n",
			array5, sizeof(array5), strlen(array5));
	printf("array6:%s size:%d length:%d\n",
			array6, sizeof(array6), strlen(array6));

	/* 字符数组的输入和输出 */
	//char array7[10] = {'\0'};				// 初始化
	char array7[10];
	memset(array7, 0, sizeof(array7));		// 另一种初始化
	printf("please input one string: ");
	//scanf("%s", array7);					// 有空格不行
	fgets(array7, sizeof(array7), stdin);
	//printf("array: %s\n", array7);
	fputs(array7, stdout);

	/* 指向字符串的指针 */
	char *p = "hello";
	printf("%s\n", p);
	 //*(p+1) = 'E				// 不允许, 数据段的常量区
	p = array7;					// 可以将数组名赋值给指针
	printf("%s\n", p)

	return 0;
}
