/*
 * Copyright (c) 我的有限公司
 * 文件名: relation_logic.c
 * 描述:关系运算符,逻辑运算符的介绍和使用
 * 作者: hyb
 * 完成日期: 2017年12月20日
 * 当前版本: 1.0
 */

#include <stdio.h>

int main(void)
{
	printf("1&&2: %d\n",1&&2);
	printf("1||2: %d\n",1||2);
	printf("!3: %d\n",!3);
	printf("!0: %d\n",!0);

	int flag = 0;
	if(flag)
		printf("true\n");
	if(flag == 1)
		printf("true\n");
	if(!flag)
		printf("false\n");

	printf("---------------------------------------\n");
	// 短路,不会计算 || 右侧
	if(1 || (3 > 0 && 1 < 0))
		printf("true\n");
	// 短路
	if (8 && (1 || 1))
		printf("true \n");
	else
		printf("false\n");
	// 短路应用
	int i = 1, j = 2;
	if(i++ > 0 || ++j < 0){
		printf("i: %d j:%d\n",i,j);		// j 还是为2, 因为短路
	}else{
		printf("i:%d j:%d\n",i,j);
	}

	return 0;
}
