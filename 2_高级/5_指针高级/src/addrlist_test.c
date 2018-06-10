/*
 * Copyright (c) 我的有限公司
 * 文件名: addrlist_test.c
 * 描述: 调用程序
 * 作者: Hyb
 * 完成日期: 2018年1月20日
 * 当期版本: 1.0
 */

#include <stdio.h>
#include "addrlist.h"

int main(void)
{
	char name[20] = {'\0'};
	printf("please input your name: ");
	scanf("%s", name);
	char const *phone = lookup_phone(name);
	char const *address = lookup_address(name);
	if(phone != NULL && address != NULL){
		printf("phone: %s\n", phone);
		printf("address: %s\n", address);
	}else{
		printf("Sorry, not find !\n");
	}

	return 0;
}
