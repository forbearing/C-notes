/*
 * Copyright (c) 2018 我的有限公司
 * 文件名: addrlist.c
 * 描述: 实现根据名字查核早地址和电话的函数功能
 * 作者: Hyb
 * 完成日期: 2018年1月20日
 * 当期版本: 1.0
 */

#include <stdio.h>
#include <string.h>
#include "addrlist.h"

static char name[MAX_ADDRESSES][NAME_LENGTH] = {"jack", "tom", "marray"};
static char phone[MAX_ADDRESSES][PHONE_LENGTH] = 
{
	"13918115555",
	"13743453563",
	"24343543543"
};
static char address[MAX_ADDRESSES][ADDR_LENGTH] =
{"jiangshu", "shanghai", "beijing"};


/* 根据名字查找对应行的下标(前提是名字存在) */
static int find_index(char const *find_to_name)
{
	int index;
	for(index=0; index<MAX_ADDRESSES; index++){
		if(strcmp(find_to_name, *(name+index)) == 0)
			return index;
	}
	return -1;
}

char const *lookup_phone(char const *name)
{
	int index = find_index(name);
	if(index == -1)
		return NULL;
	else
		//return phone[index];
		return *(phone+index);
}

char const *lookup_address(char const *name)
{
	int index = find_index(name);
	if(index == -1)
		return NULL;
	else
		return *(address+index);
}
