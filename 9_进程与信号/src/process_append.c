/*
 * 文件名: process_append.c
 * 描述: 案例:父进程调节文件偏移量,资金追加内容.
 *		子进程继承父进程的文件描述符表,但不继承文件表项和i-node(共享)
 * 完成日期: 2018年2月8日 15:30
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define handle_error(msg)	\
	do { perror(msg); exit(EXIT_FAILURE); } while(0)

int main(int argc, char *argv[])
{
	if(argc < 2){
		fprintf(stderr, "Usage: %s file\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	int fd = open(argv[1], O_WRONLY);
	if(fd < 0)
		handle_error("open error");

	pid_t pid = fork();
	if(pid < 0){
		handle_error("fork error");
	}else if(pid > 0){
		/* 父进程将文件偏移量调整到文件尾部 */
		if(lseek(fd, 0L, SEEK_END) < 0)
			handle_error("lseek error");
	}else{
		/* 子进程从文件尾部追加内容 */
		char *str = "hello linux";
		ssize_t size = strlen(str) * sizeof(char);
		sleep(1);							// 此处的fd 是从父进程中复制过来的
		if(write(fd, str, size) != size)	// 但是和父进程中的fd都是指向同一个
			handle_error("write error");	// 文件
	}
	
	printf("pid: %d finish\n", getpid());

	/* 父子进程分别关闭各自的文件描述符 */
	close(fd);

	return 0;
}
