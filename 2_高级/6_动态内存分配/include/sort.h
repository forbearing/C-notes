/*
 * Copyright (c) 2018 我的有限公司
 * 文件名: sort.h
 * 描述: 什么排序的函数原型
 * 作者: Hyb
 * 完成日期: 2018年1月23日
 * 当前版本: 1.0
 */

#include "element.h"

typedef unsigned int uint_t;

/*
 * data: 排序的 teacher 数据
 * n: teacher 的数量
 * comp: 用来比较大小的函数指针
 */
void data_sort(PElementType data, uint_t n, 
		int(*comp)(PElementType, PElementType));
