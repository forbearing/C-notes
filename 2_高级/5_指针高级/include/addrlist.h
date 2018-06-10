/*
 * Copyright (c) 2018 我的有限公司
 * 文件名: addrlist.h
 * 描述: 声明两个根据名字查找地址和电话的函数原型
 * 作者: Hyb
 * 完成日期: 2018年1月20日
 * 当期版本: 1.0
 */

#define NAME_LENGTH 30
#define ADDR_LENGTH 100
#define PHONE_LENGTH 12
#define MAX_ADDRESSES 1000

extern char const * lookup_address(char const *name);
extern char const * lookup_phone(char const *name);
