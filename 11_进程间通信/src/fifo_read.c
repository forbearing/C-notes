/*
 * 文件名: read_fifo.c
 * 描述: 命名管道的创建和读取
 * 完成日期: 2018年2月24日 10:40
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define handle_error(msg)	\
	do { perror(msg); exit(EXIT_FAILURE); } while(0)

int main(int argc, char *argv[])
{
	if(argc < 2){
		fprintf(stderr, "Usage: %s fifo\n", argv[0]);
		exit(EXIT_FAILURE);;
	}

	printf("open fifo read...\n");
	int fd = open(argv[1], O_RDONLY);
	if(fd < 0)
		handle_error("open error");
	else
		printf("open file success: %d\n", fd);
	
	/* 从命名管道中读取数据 */
	char buf[512];
	memset(buf, 0, sizeof(buf));
	ssize_t size;
	while((size = read(fd, buf, sizeof(buf))) > 0){
		printf("%s\n", buf);
	}
	if(size < 0)
		handle_error("read error");
	/*
	 * 管道中的数据少时,下买你代码也可以
	 * while(read(fd, buf, sizeof(buf)) < 0)
	 *		perror("read error");
	 * printf("%s\n", buf)
	 * */

	close(fd);

	return 0;
}
