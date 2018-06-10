1:进程资源限制函数
	#include <sys/resource.h>
	int getrlimit(int resource, struct rlimit( rlptr));
	1:返回: 成功返回0, 出错返回非0
	2:功能: 获得资源限制,存放在 rlptr 指向的结构体中
	int setrlimit(int resource, const struct rlimit *rlptr);
	1:返回: 成功返回0, 出错返回-1
	2:功能: 通过 rlptr 指向的结构体中求修改 resource 指定的资源限制
	3:struct rlimit{
		rlim_t rlim_cur;			// soft limit: current limit
		rlim_t rlim_max;			// hard limit: maximum value for rlim_cur
	};
	4:resouce 取值
		RLIMIT_AS			进程可用存储区大小
		RLIMIT_CORE			core 文件最大字节数
		RLIMIT_CPU			CPU 时间最大值
		RLIMIT_DATA			数据段最大长度
		RLIMIT_FSIZE		可创建文件的最大长度
		RLIMIT_LOCKS		文件锁的最大数
		RLIMIT_MEMLOCK		使用 mlock 能否在存储器中锁定的最长字节数
		RLIMIT_NOFILE		能打开的最大文件数
		RLIMIT_NPROC		每个用户 ID 可拥有的最大子进程数
		RLIMIT_RSS			最大驻内存集的字节长度
		RLIMIT_STACK		栈的最大长度
	5: rlim_cur == RLIM_INFINITY


2:进程资源限制的配置文件
	/etc/security/limits.conf
	Linux 中进程资源的初始化由0号进程建立, 并被后续进程继承


3:资源限制的修改规则
	1:硬资源的限制必须大于等于软资源限制
	2:任何一进程可以降低或者提升其软资源限制,但必须小于等于其硬资源限制
	3:任何一进程可以降低其硬资源限制,但必须大于其软资源限制,普通用户不可逆此操作
	4:只有超级用户可以提高硬资源限制
	


示例:
	process_limit.c
	limit_nofile.c
