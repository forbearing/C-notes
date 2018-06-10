/*
 * 文件名: length
 * 描述: 利用 lseek 来测量文件changdu
 * 完成日期: 2018年1月31日凌晨00:50
 */
#include <stdio.h>
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

	int fd = open(argv[1], O_RDONLY);
	ssize_t size = lseek(fd, 0L, SEEK_END);
	if(size < 0){
		perror("seek error");
		exit(EXIT_FAILURE);
	}else{
		printf("%s length: %ld\n", argv[1], size);
	}

	return 0;
}
