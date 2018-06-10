/*
 * 文件名: co_process.c
 * 描述: 协同进程
 *		父进程从管道a 中传入x 和y, 子进程从管道a 中获取x 和y 并计算之和
 *		子进程从管道b 中传入x h y, 父进程从管道b 中获取x+y 的结果并输出
 * 完成日期: 2018年13:20
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define handle_error(msg)	\
	do { perror(msg); exit(EXIT_FAILURE); } while(0)

int main(void)
{
	int fda[2], fdb[2];
	if((pipe(fda) < 0) || (pipe(fdb) < 0))
		handle_error("pipe error");


	pid_t pid = fork();
	if(pid < 0){
		handle_error("fork error");

	}else if(pid == 0){

		close(fda[1]);
		close(fdb[0]);
		if(dup2(fda[0], STDIN_FILENO) != STDIN_FILENO)
			handle_error("dup2 error");
		if(dup2(fdb[1], STDOUT_FILENO) != STDOUT_FILENO)
			handle_error("dup2 error");
		if(execlp("bin/add", "bin/add", NULL) < 0)
			handle_error("execlp error");
		/*
		 * 如果不使用 execlp, 代码如下
		 *	int x, y;
		 *	int result = 0;
		 *	if(read(fda[0], &x, sizeof(int)) < 0)
		 *		handle_error("read error");
		 *	if(read(fda[0], &y, sizoef(int)) < 0)
		 *		handle_error("readerror");
		 *	result = x + y;
		 *	if(write(fdb[1], &result, sizeof(int)) != sizeof(int))
		 *		handle_error("write error");
		 * */
		close(fda[0]);
		close(fdb[1]);

	}else{

		close(fda[0]);
		close(fdb[1]);
		int x, y;
		printf("please input x and y: ");
		scanf("%d %d", &x, &y);
		if(write(fda[1], &x, sizeof(int)) != sizeof(int))
			handle_error("write error");
		if(write(fda[1], &y, sizeof(int)) != sizeof(int))
			handle_error("write error");
		int result = 0;
		if(read(fdb[0], &result, sizeof(int)) < 0)
			handle_error("read error");
		else
			printf("add result is %d\n", result);
		close(fda[1]);
		close(fdb[0]);
		wait(NULL);

	}

	return 0;
}
