/*
 * Copyright (c) 我的有限公司
 * 文件名: linkattribute.c
 * 描述: 链接属性介绍
 * 作者: Hyb
 * 完成日期: 2018年1月2号
 * 当前版本: 1.0
 */

#include <stdio.h>

/* 变量来 x 的存储类型为 exetern,
 * 链接属性为 External, 可以在当前文件和其他文件使用 */ 
int x = 10;
/* 变量 y 的存储类型为 static,
 * 链接属性为 Internal, 仅限于当前文件使用 */
static int y = 1;
/* 函数 a 的链接属性为 External
 * 称为外部函数,可以在多个文件中使用, extern 可以省略 */
extern int a(){
	printf("a()...\n");
}
/* 函数 b 的链接属性为 Internal
 * 称为内部函数或者静态函数,使用仅限于当前文件 */
static int b(int i){
	printf("b()...\n");
	/* 变量k的存储类型为 auto, 链接属性为 None */
	int k = 1;
	/* 变量 m 的存储类型为 static,
	 * 链接属性为 Internal, 仅限于当前函数使用 */
	int static m = 2;
}
