/*
 * Copyright (c) hyb有限公司
 * 文件名: queue_test.c
 * 描述:
 * 作者: hyb
 * 完成日期: 2017年12月27日
 * 当前版本: 1.0
 */

#include <stdio.h>
#include "queue.h"

int main(void)
{
	enqueue(1);
	enqueue(2);
	enqueue(3);

	printf("dequeue(): %d\n", dequeue());
	printf("dequeue(): %d\n", dequeue());
	printf("dequeue(): %d\n", dequeue());
	printf("dequeue(): %d\n", dequeue());

	return 0;
}
