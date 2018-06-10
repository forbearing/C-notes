/*
 * copyrigh (c) 2018 我的有限公司
 * 文件名: sort.c
 * 描述: 排序算法的函数功能实现
 * 作者: Hyb
 * 完成日期: 2018年1月23日
 * 当前版本: 1.0
 */

#include "sort.h"
#include <stdio.h>
#include <stdlib.h>


/*
 * data: 排序的 teacher 数据
 * n: teacher 的数量
 * comp: 用来比较大小的函数指针
 */
void data(PElementType data, uint_t n, int (*comp)(PElementType, PElementType))
{
	if(data == NULL || comp == NULL){
		printf("data sort error\n");
		exit(1);
	}
	int i, j;
	for(i=0; i<n-1; i++){
		int position = i;
		for(j=i+1; j<n; j++){
			if(comp(data+j, data+position) < 0){
				position = j;
			}
		}
		if(position != i){
			ElementType temp;
			temp = *(data+position);
			*(data+position) = *(data+i);
			*(data+i) = temp;
		}
	}
	
}
