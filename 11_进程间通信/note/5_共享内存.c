1:共享内存
	1:共享内存区域是被多个进程共享的一部分内存
	2:多个进程都可把共享内存映射到自己的虚拟内存空间. 所有用户空间的进程若要操作
	  共享内存,都要将其映射到自己虚拟内存空间中,通过映射的虚拟内存空间地址去操作
	  共享内存,从而达到进程间的数据通信
	3:共享内存是进程间共享数据的一种最快的方法,一个进程向共享内存区域写入数据,共
	  享这个内存区域的所有进程就可以立刻看到其中的内容
	4:本身不提供同步机制,可通过信号量进行同步
	5:提升数据处理效率,一种效率最高的IPC 机制.
	6:共享内存映射区
	7:共享内存使用步骤
		1:使用shmget 函数创建共享内存
		2:使用 shmat 函数映射共享内存,将这段创建的共享内存映射到具体的进程虚拟
		  内存空间中.


2:共享内存属性
	struct shmid_ds{
		struct ipc_perm shm_perm;
		size_t		shm_segsz;		// 共享内存大小
		pid_t		shm_lpid;		// 最后一次调用 shmop() 进程的 id
		pid_t		shm_cpid;		// 创建共享内存进程的 ID
		shmatt_t	shm_nattch;		// 与共享内存映射的进程数量
		time_t		shm_atime;		// 最后一次成功映射的时间
		time_t		shm_dtime;		// 最后一次解除映射的时间
		time_t		shm_ctime;		// 最后一次改变的时间
		...
	};


3:创建共享内存
	#include <sys/shm.h>
	int shmget(key_t key, size_t size, int shmflg);
	1:返回: 如果成功,返回内存中共享内存的标识ID, 如果失败,则返回-1
	2:参数
		key: 用户指定的共享内存键值
		size: 共享内存大小
		shmflg: IPC_CREAT, IPC_EXCL 等权限组合
	3:errno
		EINVAL(无效的内存段大小);
		EEXIST(内存段已经存在,无法创建);
		EIDRM(内存段已经被删除);
		ENOENT(内存段不存在);
		EACCES(权限不够);
		ENOMEM(没有足够的内存来创建内存段)


4:共享内存控制
	#include <sys/shm.h>
	int shmctl(int shmid, int cmd, struct shmid_ds *buf)
	1:返回: 成功返回0, 出错返回-1
	2:参数
		shmid: 共享内存ID
		buf: 共享内存属性指针
		cmd:
			IPC_STAT		获取共享内存
			IPC_SET			设置共享内存
			IPC_RMID		删除共享内存
			SHM_LOCK		锁定共享内存段页面(页面映射到物理内存不和外存
							进行换入换出操作)
			SHM_UNLOCK		解除共享存储段页面的锁定
	

5:共享内存映射和解除映射
	#include <sys/shm.h>
	void* shmat(int shmid, char *shmaddr, int shmflg);
	1:返回: 成功返回共享内存映射到进程虚拟内存空间的地址, 失败返回-1
	int shmdt(char *shmaddr);
	1:返回: 如果失败,则返回-1
	2:参数:
		shmid: 共享内存ID
		shmaddr: 映射到进程虚拟内存空间的地址,建议设置0,由操作系统分配
		shmflg: 若shmaddr 设置为0,则shmflg 也设置为0
			SHM_RND
			SHMLBA			地址为2的乘方
			SHM_RDONLY		只读方式链接
	3:errno
		EINVAL		无效的IPC ID值或无效的地址
		ENOMEM		没有足够的内存
		EACCES		存取权限不够
	4:子进程不继承父进程创建的共享内存, 大家是共享的,子进程继承父进程映射的地址



示例:
	tell.h	tell.c	cal_shm.c				// tell.h(利用管道同步)
	account.h	account.c	account_test.c	// 共享内存操作银行账户
