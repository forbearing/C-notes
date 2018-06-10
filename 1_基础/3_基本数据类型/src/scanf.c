/*
 * Copyright (c) 我的有限公司
 * 文件名: scanf.c
 * 描述: scanf 函数的介绍和使用
 * 日期: 2017年12月16日
 * 版本: 1.0
 */

#include <stdio.h>

int main(void)
{
	/* scanf 函数使用1 */
	int height, width;
	printf("please input height and width: ");
	scanf ("%d%d",&height, &width);
	printf("height:%d  width:%d\n",height,width);
	
	/* scanf 函数使用2 */
	char s[20];
	printf("plesase input a sentence: ");
	scanf("%s",s);		// 读取的字符串不能带有空格(弊端),可循环 %c 读取
	//fgets(s,sizeof(s)-1,stdin);
	printf("s: %s\n",s);

	/* scanf 函数以使用3 */
	printf("please input a number: ");
	int num;
	scanf("%d", &num);
	printf("please input a character: ");
	int c = getchar();
	char ch;
	scanf("%c",&ch);
	printf("ch: %c\n", ch);

	/* scanf 函数使用4 */
	printf("please input two character: ");
	char ch1, ch2;
	scanf("%c%c", &ch1,&ch2);		// 多个 %c 之间是否有空格有细微差别, %d没有 
	printf("ch1:%c ch2:%c\n", ch1, ch2);

	/* scanf 函数使用5 */
	int a,b;
	printf("please input two number: ");
	scanf("%d,%d", &a, &b);
	printf("a:%d b:%d\n", a, b);

	/* "*"的用法 */
	int width,precision;
	float salary = 5555.343f;
	scanf("%d%d",&width,&precision);
	printf("salary:%*.*f\n",width, precision,salary);

	int n;
	scanf("%*d %*d %d", &n);		// 读取第三个字符, %*d 指跳过一个字符
	printf("n: %d\n", n);

	return 0;
}
