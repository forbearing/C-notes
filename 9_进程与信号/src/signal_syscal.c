/*
 * 文件名: signal_syscal.c
 * 描述: 中断的系统调用
 * 完成日期: 2018年2月12日: 21:40
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void sig_handler(int signo){
	if(signo == SIGTSTP){
		printf("SIGTSTP occured\n");
	}
}

int main(void)
{
	char buf[512];
	ssize_t size;
	
	if(signal(SIGTSTP, sig_handler) == SIG_ERR){
		perror("signal error");
	}

	printf("### begin running and waiting for signal ###\n");
	size = read(STDIN_FILENO, buf, 512);
	if(size < 0){
		perror("read error");
	}
	printf("### reading finished ###\n");
	if(write(STDOUT_FILENO, buf, size) != size){
		perror("write error");
	}
	printf("### end running ###\n");

	return 0;
}
