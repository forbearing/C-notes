/*
 * Copyright (c) 2018 我的有限公司
 * 文件名: getchar_putchar.c
 * 描述: getchar 和 putchar函数的使用
 * 作者: Hyb
 * 完成日期: 2018年1月28日
 * 当前版本: 1.0
 */

#include <stdio.h>

int main(void)
{
	/* getchar 和 putchar 函数的使用 */
	int ch;
	while((ch = getchar()) != '\n'){
		putchar(ch);
	}
	putchar('\n');

	/* fgetc 和 fputc 函数的使用 */
	while((ch = fgetc(stdin)) != '\n'){
		fputc(ch, stdout);
	}
	fputc('\n', stdout);

	/* getc 和 putc 函数的使用 */
	while((ch = getc(stdin)) != '\n'){
		putc(ch, stdout);
	}
	putc('\n', stdout);

	return 0;
}
