/*
 * 文件名: lock_write.c
 * 描述: 两个进程对同一个加锁的文件进行读写
 * 完成日期: 2018年2月3日10:40
 */

#include "io.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
	if(argc < 4){
		printf("Usage: %s content file locktype\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	ssize_t size = strlen(argv[1]) * sizeof(char);
	int fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if(fd < 0){
		perror("open error");
		exit(EXIT_FAILURE);
	}

	sleep(5);

	// 加锁
	if(!strcmp("lock", argv[3]))
		WRITE_LOCKW(fd, 0, SEEK_SET, 0);
	printf("lock success\n");
	printf("lock pid: %d\n", getpid());

	char *p = argv[1];
	int i;
	for(i=0; i<size; i++){
		if(write(fd, (p+i), 1) != 1){
			perror("write error");
			exit(1);
		}
		printf("%d success write one character\n", getpid());
		sleep(1);
	}

	// 解锁
	if(!strcmp("unlock", argv[3])){
		UNLOCK(fd, 0, SEEK_SET, 0);
		printf("unlock success\n");
		printf("unlock pid: %d\n", getpid());
	}
	close(fd);

	return 0;
}
