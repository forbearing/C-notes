/*
 * 文件名: line_buffer.c
 * 描述: 行缓存示例
 * 完成日期: 2018年1月31日
 */

#include <stdio.h>
#include <unistd.h>

int main(void)
{
	printf("hello linux");
	//printf("hello linux\n");
	int i = 0;
	while(i < 5){
		i++;
		sleep(1);
	}

	return 0;
}
