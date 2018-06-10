/*
 * Copyright (c) 我的有限公司
 * 文件名: enum.c
 * 描述: 枚举类型的介绍和使用
 * 作者: hyb
 * 完成日期: 2017年12月17日
 * 当前版本: 1.0
 */

#include <stdio.h>

int main(void)
{
	/* 枚举类型定义方法1 */
	// 声明枚举类型
	enum Car_Type{BENZ,BMW,FORD,AUDI,JEEP};
	// 定义枚举变量
	enum Car_Type my_car = BENZ, your_car;
	printf("Car_Type my_car:%d BMW:%d your_car:%d\n",my_car, BMW, your_car);

	/* 枚举变量定义方法2 */
	enum Car_Type2{BENZ2,BMW2,FORD2,AUDI2,JEEP2} my_car2 = BENZ2, your_car2;
	printf("Car_Type2 my_car2:%d BMW2:%d your_car2:%d\n",
													my_car2,BMW2,your_car2);

	/* 枚举变量定义方法3 */
	enum {BENZ3,BMW3,FORD3,AUDI3,JEEP3} my_car3 = BENZ3, your_car3;
	printf("Car_Type3 my_car:%d BMW3:%d your_car3:%d\n",my_car3,BMW3,your_car3);

	/* 声明枚举类型的同时对枚举值初始化 */
	enum Car_Type4{BENZ4=2,BMW4,FORD4=8,AUDI4,JEEP4};
	enum Car_Type4 my_car4 = BENZ4, your_car4=JEEP4, other_car4=9;
	// BMW4 = 0;			//不能对枚举值(符号常量)进行赋值
	printf("Car_Type4 my_car4:%d BMW4:%d your_car4:%d other_car4:%d\n",
										my_car4, BMW4, your_car4, other_car4);

	return 0;
}
