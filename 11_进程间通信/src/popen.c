/*
 * 文件名: popen.c
 * 描述: 标准库函数 popen 的使用
 * 完成日期: 2018年2月24日 10:10
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
	FILE *fp;
	/* 命令执行的结果放置在 fp 指向的结构体缓存中 */
	fp = popen("cat /etc/shells", "r");

	char buf[512];
	memset(buf, 0, sizeof(buf));
	while(fgets(buf, sizeof(buf), fp) != NULL)
		printf("%s", buf);
	
	pclose(fp);


	printf("-----------------------------------\n");
	

	fp = popen("wc -l", "w");
	fprintf(fp, "1\n2\n3\n");
	pclose(fp);

	return 0;
}
