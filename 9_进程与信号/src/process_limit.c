/*
 * 文件名: process_limit.c
 * 描述: 进程资源限制, getrlimit 函数的使用
 * 完成日期: 2018年2月5日9:00
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/resource.h>

#define RLIMIT(name)	get_limit(#name, name)

void get_limit(char *name, int resource){
	struct rlimit limit;
	if(getrlimit(resource, &limit) < 0){
		perror("getrlimit error");
		return;
	}
	printf("%-15s", name);
	/* rlim_cur: 软资源限制 */
	if(limit.rlim_cur == RLIM_INFINITY){
		printf("	infinity");
	}else{
		printf("%10ld", limit.rlim_cur);
	}
	/* rlim_max: 硬资源限制 */
	if(limit.rlim_max == RLIM_INFINITY){
		printf("	infinity\n");
	}else{
		printf("%10ld\n", limit.rlim_max);
	}
}

int main(void)
{
	RLIMIT(RLIMIT_AS);
	RLIMIT(RLIMIT_CORE);
	RLIMIT(RLIMIT_CPU);
	RLIMIT(RLIMIT_DATA);
	RLIMIT(RLIMIT_FSIZE);
	RLIMIT(RLIMIT_LOCKS);
	RLIMIT(RLIMIT_MEMLOCK);
	RLIMIT(RLIMIT_NOFILE);
	RLIMIT(RLIMIT_NPROC);
	RLIMIT(RLIMIT_RSS);
	RLIMIT(RLIMIT_STACK);

	return 0;
}
