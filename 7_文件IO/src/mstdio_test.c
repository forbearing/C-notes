/*
 * 文件名: mstdio_test.c
 * 描述: 构建标志IO库函数的测试文件
 * 完成日期; 2018年2月3日 19:30
 */

#include "mstdio.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(void)
{
	MFILE *fp1 = mfopen("/etc/services", "r");
	assert(fp1 != NULL);
	MFILE *fp2 = mfopen("services", "w");
	assert(fp2 != NULL);

	char c;
	while((c = mfgetc(fp1)) != MEOF)
		mfputc(c, fp2);

	mfclose(fp1);
	mfclose(fp2);

	return 0;
}
