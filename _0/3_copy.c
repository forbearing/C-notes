/*
 * 文件名: copy.c
 * 描述: 文件拷贝模板
 * 完成日期: 2018年2月5日12:10
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

#define handle_error(msg)	\
	do{ perror(msg); exit(EXIT_FAILURE); } while(0)
#define BUFFER_LEN 4096

int main(int argc, char *argv[])
{
	if(argc < 3){
		fprintf(stderr, "Usage: %s srcfile desfile\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	int fd1, fd2;
	if((fd1 = open(argv[1], O_RDONLY)) < 0)
		handle_error("open srcfile error");
	if((fd2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644)) < 0)
		handle_error("open desfile error");

	char buffer[BUFFER_LEN];
	ssize_t size;
	memset(buffer, 0, sizeof(buffer));
	while((size = read(fd1, buffer, sizeof(buffer))) > 0){
		if(write(fd2, buffer, size) != size)
			handle_error("write error");
	}
	if(size == 0)
		printf("***** read complete! *****\n");
	else if(size < 0)
		handle_error("open error");

	close(fd1);
	close(fd2);

	return 0;
}
