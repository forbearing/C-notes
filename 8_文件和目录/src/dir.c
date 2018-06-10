/*
 * 文件名: dir.c
 * 描述: 目录的打开,读取,关闭
 * 完成日期: 2018年2月5日
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

#define handle_error(msg)	\
	do { perror(msg); exit(EXIT_FAILURE); } while(0);

int main(int argc, char *argv[])
{
	if(argc < 2){
		fprintf(stderr, "Usage: %s dir\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	/* 判断是否为目录 */
	struct stat buf;
	memset(&buf, 0, sizeof(buf));
	if(lstat(argv[1], &buf) < 0)
		handle_error("lstat error");
	if(!S_ISDIR(buf.st_mode)){
		printf("%s is not directory\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	/* 打开目录 */
	DIR *dir = opendir(argv[1]);
	if(dir == NULL)
		handle_error("opendir error");
	/* 读取目录 */
	struct dirent *ent;
	while((ent = readdir(dir)) != NULL)
		printf("%-10ld %-20s\n", ent->d_ino, ent->d_name);
	/* 关闭目录 */
	closedir(dir);

	return 0;
}
