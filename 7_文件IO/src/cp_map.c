/*
 * 文件名: cp_map.c
 * 描述: 利用存储映射实现文件之间的拷贝
 * 完成日期: 2018年2月3日17:20
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

#define handle_error(msg)	\
	do{ perror(msg); exit(EXIT_FAILURE); } while(0)

int main(int argc, char *argv[])
{
	if(argc < 3 || argc > 4){
		fprintf(stderr, "Usage: %s srcfile desfile\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	int sfd = open(argv[1], O_RDONLY);
	if(sfd < 0)
		handle_error("open srcfile error");
	int dfd = open(argv[2], O_RDWR | O_CREAT | O_TRUNC, 0777);
	if(dfd < 0)
		handle_error("open desfile error");

	off_t len = lseek(sfd, 0, SEEK_END);			// 获取源文件的长度
	printf("src file length: %ld\n", len);
	lseek(dfd, len-1, SEEK_SET);					// 目标文件生成空洞
	write(dfd, "0", 1);

	// 创建共享内存映射区
	char *a1 = mmap(0, len, PROT_READ, MAP_SHARED, sfd, 0);
	if(a1 == MAP_FAILED)
		handle_error("mmap src file error");
	char *a2 = mmap(0, len, PROT_WRITE, MAP_SHARED, dfd, 0);
	if(a2 == MAP_FAILED)
		handle_error("mmap dest file error");

	// 存储映射区间的复制并同步到文件中
	memcpy(a2, a1, len);

	// 解除映射
	munmap(a1, 0);
	munmap(a2, 0);

	close(sfd);
	close(dfd);

	return 0;
}
