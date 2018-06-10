1:介绍
	1:一个或多个进程的集合
	2:可以接受同一个终端的各种信号,同一个信号发送进程组等于发送给组中的所有进程
	3:每个进程组由唯一的进程组ID
	4:进程组的消亡要等到组中的进程结束
	5:kill 发送信号给进程组 kill -9 -进程组号


2:函数
	#include <unistd.h>
	pid_t getpgrp(void);
	返回: 调用进程的进程组ID
	pid_t getpgid(pid_t pid)
	返回: 进程所在进程组的ID, 出错返回-1


3:组长进程
	1:每个进程可以有个组长进程,组长进程的ID就是进程组的ID
	2:组长进程可以创建进程组以及该组中的进程
	3:进程组的创建从第一个进程(组长进程)加入开始
	4:进程组的组号取第一个加入组的进程(组长进程)编号
	#include <unistd.h>
	int setpgid(pid_t pid, pid_t pgid);
	返回: 成功返回0, 出错返回-1
	功能: 将进程加入到指定的进程组中, pid 为进程号, pgid 为组号


4:前台进程组
	1:自动接受终端信号的组称为前台进程组
	2:在终端通过 Ctrl-C 等动作产生的信号首先被前台进程组接受
	3:在 shell 启动的若干个进程组默认是父进程所在的组为前台进程组
	4:除非是默认,否则都要通过调度才能称为前台进程组
	#include <unistd.h>
	pid_t gcgetpgrp(int fd)
	1:返回: 若成功返回前台进程组的ID, 出错返回-1
	2:功能: 获得前台进程组ID
	int tcsetpgrp(int filedes, pid_t pgrpid);
	1:返回值: 成功返回0, 出错返回-1
	2:功能: 使用 pgrpid 设置前台进程组 ID
	3:fd 必须引用该会话的控制终端,0代表当前正在使用的终端


示例
	process_group.c
	process_group2.c
	process_group3.c
	front_group.c							// 前台进程组
