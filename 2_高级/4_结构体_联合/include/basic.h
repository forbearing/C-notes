/* Copyright (c) 2018 我的有限公司
 * 文件名: basic.h
 * 描述: 声明结构体
 * 作者: Hyb
 * 完成日期: 2018年1月8日
 * 当前版本: 1.0
 */

struct address
{
	char country[30];
	char city[30];
	char street[30];
}

struct student
{
	/* 成员列表 */
	int xh;
	char name[30];
	char gender[20];
	int age;
	//char address[30];
	/* 结构体的嵌套 */
	struct address addr;
};
