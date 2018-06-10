/*
 * 文件名: file_perm.c
 * 描述: 文件权限判断
 * 完成日期: 2018年2月4日
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
	if(argc < 2){
		fprintf(stderr, "Usage: %s file\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	struct stat buf;
	int i;
	for(i=1; i<argc; i++){
		memset(&buf, 0, sizeof(buf));
		if(lstat(argv[i], &buf) < 0){
			perror("lstat error");
			continue;
		}
		/* 获得文件权限信息 */
		mode_t mode = buf.st_mode;
		printf("%-20s", argv[i]);
		
		/* user permission */
		if(S_IRUSR & mode)
			printf("r");
		else
			printf("-");
		if(S_IWUSR & mode)
			printf("w");
		else
			printf("-");
		if(S_IXUSR & mode)
			printf("x");
		else
			printf("-");

		/* group permission */
		if(S_IRGRP & mode)
			printf("r");
		else
			printf("-");
		if(S_IWGRP & mode)
			printf("w");
		else
			printf("-");
		if(S_IXGRP & mode)
			printf("x");
		else
			printf("-");

		/* others permission */
		if(S_IROTH & mode)
			printf("r");
		else
			printf("-");
		if(S_IWOTH & mode)
			printf("w");
		else
			printf("-");
		if(S_IXOTH & mode)
			printf("x");
		else
			printf("-");
		printf("\n");
	}

	return 0;
}
