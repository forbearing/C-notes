/*
 * 文件名: file_map.c
 * 描述: 共享内存映射区的介绍和使用
 * 完成日期: 2018年2月3日16:30
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/mman.h>

int main(int argc, char *argv[])
{
	if(argc < 2){
		fprintf(stderr, "Usage: %s file\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	int fd = open(argv[1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if(fd < 0){
		perror("open error");
		exit(EXIT_FAILURE);
	}

	// 跳过 20 个字节
	lseek(fd, 19L, SEEK_END);
	write(fd, "0", 1);

	char *addr;
	// 进行存储映射
	addr = mmap(0, 20, PROT_WRITE, MAP_SHARED, fd, 0);
	if(addr < 0){
		perror("mmap error");
		exit(EXIT_FAILURE);
	}

	// 修改存储映射区内容会同步到文件
	int i;
	for(i=0; i<20; i++){
		*(addr+i) = 'A'+i;
	}
	printf("write success\n");

	// 解除映射
	munmap(addr, 0);
	close(fd);
	

	return 0;
}
