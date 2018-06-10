1:wait, waitpid 函数
	#include <sys/types.h>
	#include <sys/wait.h>
	pid_t wait(int *status);
	1:返回: 成功返回子进程ID, 出错返回-1
	2:等待子进程退出并回收, 防止僵尸进程产生
	pid_t waitpid(pid_t pid, int *status, int options);
	1:返回: 成功返回子进程ID, 出错返回-1
	2:功能: wait 函数的非阻塞版本
	3:参数
		pid:
			pid == 0	等待任一子进程,功能与 wait 等效
			pid > 0		等待其进程 ID 与 pid 相等的子进程
			pid == 0	等待其组ID等于调用进程的组ID的任一进程
			pid < -1	等待其组ID等于 pid 的绝对值的任意子进程
		status: 为空时,代表任意状态结束的子进程,若不为空,则代表指定状态结束的
				子进程
		检查 wait 和 waitpid 函数返回终止状态的宏
			WIFEXITED/WEXITSTATUS(status)
				若为正常终止子进程返回的状态,则为真
			WIFSIGNALED/WTERMSIG(status)
				若为异常终止子进程返回的状态,则为真(接到一个不能捕捉的信号)
			WIFSTOPED/WSTOPSIG(status)
				若为当前暂停子进程的返回的状态,则为真
		options:
			WNOHANG: 若由 pid 指定的子进程没有退出立即返回, 则 waitpid 不阻塞
					 此时其返回值为0
			WUNTRACED: 若某实现支持作业控制,则由 pid 指定的任一子进程状态已暂停,
					   且其状态自暂停依赖还未报告过,则返回其状态
	wait 和 waitpid 函数的区别
		1:在一个子进程终止之前, wait 使其调用者阻塞
		2:waitpid 有一选择项, 可使调用这不阻塞
		3:waitpid 等待一个指定的子进程, 而 wait 等待所有的子进程,返回任一
		  终止子进程的状态


2:exec 函数介绍
	1:在用 fork 函数创建子进程后,子进程往往要调用一种 exec 函数以执行另一陈需
	2:当进程调用一种 exec 函数时,该进程完全由新程序代替,替换原有进程的正文,而
	  新程序则从其 main 函数开始执行,因为调用 exec 并不创建新进程,所以前后的进程
	  ID并未改变, exec 只是用另一新程序替换了当前进程的正文,数据,堆,栈段


3:exec 函数
	#include <unistd.h>
	int execl(const char *pathname, const char *arg0, .../*(char *)0*/);
	int execv(const char *pathname, char *const argv[]);
	int execle(const char *pathname, const char *arg0,...
			/*(char *)0, char *const envp[]*/);
	int execve(const char *pathname, char *const argv[], char *const envp[]);
	int execlp(const char *pathname, const char *arg0,.../*(char *)0*/);
	int execvp(const char *pathname, char *const argv[]);
	1:返回: 出错返回-1, 成功则不返回
	2:exec 系列函数的注意点
		1:execve 函数为系统调用,其余为库函数,执行 execve 函数后面的代码不执行
		2:execlp 和 execvp 函数中的pathname, 相对和绝对路径均可以,其他四个函数中
		  的 pathname 只能使用绝对路径. 相对路径一定要在进程环境表对应的 PATH 中
		3:argv 参数为新程序执行 main 函数中传递的 argv 参数,最后一个元素为 NULL
		4:envp 为进程的环境表
		5:执行成功后,不返回,不会执行 exec 函数后面的代码
	3:exec 后缀
		1:带有字母 "l" 的函数,表明后面的参数列表是要传递给程序的参数列表,参数
		  列表的第一个参数必须是要执行程序,最后一个参数必须是 NULL
		2:带有字母 "v" 的函数,表明程序的参数列表通过一个字符串数组来传递, 这个
		  数组和最后传递给程序的 main 函数的字符串数组 argv 完全一样, 第一个参数
		  必须是程序名,最后一个参数也必须是 NULL
		3:带有字母 "e" 的函数,用户可以自己设置程序接收一个设置环境变量的数组
		4:带有字母 "p" 的函数,第一个参数可以是相对路径或程序名,如果无法立即找到
		  要执行的程序,那么就在环境变量 PATH 指定的路径中搜索,其他函数的第一个
		  参数则必须是绝对路径


4:system 函数
	#include <stdlib.h>
	int system(const char *command);
	1:返回: 成功返回执行命令的状态,出错返回-1
	2:功能: 简化 exec 函数的使用
	3:system 函数内部构建爱呢一个子进程,由子进程调用 exec 函数
	4: 等用与 /bin/bash -c "cmd" 或者 exec("bash", "-c", "cmd");


示例
	process_wait.c						// wait, waitpid 函数的使用
	process_zombie_wait.c				// wait 函数防止僵尸进程的产生
	execl.c								// exec 系列函数的使用
	execvp.c
	system.c							// system 函数的使用
	mysystem.c							// 自己实现 system
