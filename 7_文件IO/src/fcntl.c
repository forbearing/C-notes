/*
 * 文件名: fcntl.c
 * 描述: 写入三个字符串(分别是: "start","mdist", end), 先写入mdist 再写入 end
 *		最后写入 start. 最后文件中结果是 "startmidest,end";
 * 完成日期: 2018年2月1日19:00
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
	if(argc < 2){
		fprintf(stderr, "Usage: %s [file]\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	char buffer[100] = {'\0'};
	char str1[5] = "start";
	char str2[5] = "midst";
	char str3[3] = "end";
	int fd;
	FILE *fp;
	ssize_t size;
	int flag;

	/* 第一次写入 midst */
	if((fd = open(argv[1], O_RDWR | O_CREAT | O_TRUNC, 0777)) < 0){
		perror("open file 1 error");
		exit(EXIT_FAILURE);
	}
	lseek(fd, 5L, SEEK_END);				// 跳过5个字节(预留给 start)
	size = strlen(str2);
	if(write(fd, str3, size) != size){		// 写入 midst
		perror("write 1 error");
		exit(EXIT_FAILURE);
	}
	fp = fdopen(fd, "rw");
	fscanf(fp, "%s", buffer);
	printf("%s\n", buffer);
	close(fd);

	/* 第二次写入 end */
	if((fd = open(argv[1], O_RDWR)) < 0){
		perror("open file 2 error");
		exit(EXIT_FAILURE);
	}
	flag = fcntl(fd, F_GETFL);
	flag |= O_APPEND;						// 设置 O_APPEND 标志
	if(fcntl(fd, F_SETFL, flag) < 0){
		perror("fcntl error");
		exit(EXIT_FAILURE);
	}
	size = strlen(str3);
	if(write(fd, str3, size) != size){		// 写入 end
		perror("write 2 error");
		exit(EXIT_FAILURE);
	}
	fp = fdopen(fd, "rw");
	fscanf(fp, "%s", buffer);
	printf("%s\n", buffer);
	close(fd);

	/* 第三次写入 start */
	if((fd = open(argv[1], O_RDWR|O_APPEND)) < 0){
		perror("open file 3 error");
		exit(EXIT_FAILURE);
	}
	flag = fcntl(fd, F_GETFL);
	flag &= ~O_APPEND;						// 清除 O_APPEND 标志
	if(fcntl(fd, F_SETFL, flag) < 0){
		perror("fcntl error");
		exit(EXIT_FAILURE);
	}
	size = strlen(str1);
	if(write(fd, str1, size) != size){		// 写入 start
		perror("write 3 error");
		exit(EXIT_FAILURE);
	}
	fp = fdopen(fd, "rw");
	fscanf(fp, "%s", buffer);
	printf("%s\n", buffer);
	close(fd);


	return 0;
}
