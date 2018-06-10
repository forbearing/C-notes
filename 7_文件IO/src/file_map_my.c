/*
 * 文件名: file_map_my.c
 * 描述: 共享内存映射区的使用
 * 完成日期: 2018年2月3日16:50
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

int main(int argc, char* argv[])
{
	if(argc < 2){
		fprintf(stderr, "Usage: %s file\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	int fd = open(argv[1], O_RDWR | O_CREAT | O_TRUNC, 0777);
	if(fd < 0){
		perror("open error");
		exit(EXIT_FAILURE);
	}

	// 跳过 20 个字节,并在最后做一个标志 "end"
	lseek(fd, 20L, SEEK_END);
	write(fd, "end", strlen("end"));

	// 创建共享内存映射区
	char *addr = mmap(0, 20, PROT_WRITE, MAP_SHARED, fd, 0);
	if(addr < 0){
		perror("mmap error");
		exit(EXIT_FAILURE);
	}

	// 读写共享内存映射区
	int i;
	for(i=0; i<20; i++){
		*(addr+i) = 'A'+i;
	}
	printf("write finished\n");

	// 解除映射
	munmap(addr, 0);
	close(fd);


	return 0;
}
