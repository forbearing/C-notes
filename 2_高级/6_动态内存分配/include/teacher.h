/*
 * Copyright (c) 2018 我的有限公司
 * 文件名: teacher.h
 * 描述: 声明对教师操作的函数原型
 * 作者: Hyb
 * 完成日期: 2018年1月20日
 * 当前版本: 1.0
 */

#include "element.h"
typedef unsigned int uint_t;

/* 创建指定大小的动态数组 */
extern void create(uint_t size);

/* 销毁动态数组 */
extern void destroy();

/* 往动态数组中加入 teacher */
extern void add(PElementType p);

/* 在动态数组的指定位置插入 teacher */
extern void insert(uint_t index, PElementType p);

/* 删除指定的 teacher */
extern void del(uint_t index);

/* 获得指定的 teacher */
extern PElementType get(uint_t index);

/* 获得 teacher 的数量 */
extern uint_t size();

/* 遍历动态数组中的 teacher */
extern void iterate();
