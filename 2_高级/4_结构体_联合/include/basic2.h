/* Copyright (c) 2018 我的有限公司
 * 文件名: basic2.h
 * 描述: 声明结构体
 * 作者: Hyb
 * 完成日期: 2018年1月13日
 * 当前版本: 1.0
 */

struct address
{
	char *country;
	char *city;
	char *street;
};

struct student
{
	/* 成员列表 */
	int xh;
	char *name;
	char *gender;
	int age;
	/* 结构体的嵌套 */
	struct address *addr;
};
