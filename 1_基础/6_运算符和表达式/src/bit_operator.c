/*
 * Copyright (c) 我的有限公司
 * 文件名: bit_operator.c
 * 描述: 位操作运算符的介绍和使用
 * 作者: hyb
 * 完成日期: 2017年12月22日
 * 当前版本: 1.0
 */

#include <stdio.h>

int main(void)
{
	printf("15&8: %d\n",15&8);		// 底三位置为0,其余位不变
	printf("8|2: %d\n",8|2);		// 次低位置为1,其余位不变
	printf("8^7: %d\n",8^7);		// 低三位置反,其余为不变
	printf("~8: %d\n",~8);

	/* 按位与,按位或和逻辑与,逻辑或的区别 */
	printf("7&&6: %d\n", 7&&6);
	printf("7&6: %d\n", 7&6);
	printf("8||2: %d\n",8||2);
	printf("8|2: %d\n", 8|2);

	return 0;
}
