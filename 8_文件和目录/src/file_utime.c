/*
 * 文件名: file_utime.c
 * 描述: utime 函数的介绍和使用
 * 完成日期: 2018年2月5日12:10
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <utime.h>

#define handle_error(msg)	\
	do{ perror(msg); exit(EXIT_FAILURE); } while(0)

struct stat get_stat(char *file, struct stat buf){
	memset(&buf, 0, sizeof(buf));
	if(lstat(file, &buf) < 0)
		handle_error("lstat error");
	return buf;
}

void out(struct stat buf){
	printf("atime: %s", ctime(&buf.st_atime));
	printf("mtime: %s", ctime(&buf.st_mtime));
	printf("ctime: %s", ctime(&buf.st_ctime));
}

int main(int argc, char *argv[])
{
	if(argc < 2){
		fprintf(stderr, "Usage: %s file\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	struct stat buf;
	buf = get_stat(argv[1], buf);
	/* 备份原先时间 */
	struct stat back = buf;
	out(buf);
	printf("-------------------------------\n");

	/* 设置文件的时间为当前系统时间 */
	utime(argv[1], NULL);
	buf = get_stat(argv[1], buf);
	out(buf);
	printf("-------------------------------\n");

	/* 恢复文件的原先时间 */
	struct utimbuf timebuf;
	timebuf.actime = back.st_atime;
	timebuf.modtime = back.st_mtime;
	utime(argv[1], &timebuf);
	buf = get_stat(argv[1], buf);
	out(buf);


	return 0;
}
