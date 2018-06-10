/*
 * 文件名: one_write.c
 * 描述: 将字符串每次只向文件中写入一个字符
 * 完成日期: 2018年2月3日11:40
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
		fprintf(stderr, "Usage: %s file\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	char buf[20] = "hello linux";
	ssize_t size = strlen(buf);

	int fd = open(argv[1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if(fd < 0){
		perror("open error");
		exit(1);
	}

	char *p = buf;
	int i;
	for(i=0; i<size; i++){
		if(write(fd, (p+i), 1) != 1){
			perror("write error");
			exit(1);
		}
		printf("write a character: %c\n", *(p+i));
		sleep(1);
	}
	printf("write finish!\n");

	close(fd);

	return 0;
}
