/*
 * Copyright (c) 我的有限公司
 * 文件名: if_condition.c
 * 描述: if 条件语句的介绍和使用
 * 作者: hyb
 * 完成日期: 2017年12月18日
 * 当前版本: 1.0
 */

#include <stdio.h>

int main(void)
{
/*
	// if 结构
	int a,b,max;
	printf("please input two number: ");
	scanf("%d %d",&a,&b);

	max = a;
	if(max<b){
		max = b;
	}
	printf("max = %d\n",max);
*/

/*
	// if-else 结构
	int a, b;
	printf("please input two number: ");
	scanf("%d %d",&a, &b);
	if(a > b){
		printf("max = %d\n", a);
	}else{
		printf("max = %d\n", b);
	}
*/

/*
	// if-else-if 结构
	char c;
	printf("please input a character: ");
	c = getchar();

	if(c < 32){
		printf("This is a control character\n");
	}else if(c >= '0' && c <= '9'){
		printf("This is a digit\n");
	}else if(c >= 'A' && c <= 'Z'){
		printf("This is a capital letter\n");
	}else if(c >= 'a' && c <= 'z'){
		printf("This is a small letter\n");
	}else{
		printf("This is an other character\n");
	}
*/

/*
	// if语句嵌套
	int a,b;
	printf("please input a and b: ");
	scanf("%d %d",&a,&b);
	if(a != b){
		if(a > b){
			printf("a > b\n");
		}else{
			printf("a < b\n");
		}
	}else{
		printf("a == b\n");
	}
	// 等价于
	if(a == b){
		printf("a == b\n");
	}else{
		if(a > b){
			printf("a > b\n");
		}else{
			printf("a < b\n");
		}
	}
*/

	// if 和 else 的配对问题, 注意加上{}后的效果
	int x = 10;
	if(x == 0)
		if(x > 0)
			printf("x:%d\n",x);
	else
		printf("else\n");

	return 0;
}
