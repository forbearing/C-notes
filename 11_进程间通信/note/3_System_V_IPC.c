1:System V IPC 概述
	1:Unix 系统存在信号,管道和命名管道等基本进程间通讯机制
	2:System V 引入了三种高级进程间通信机制
		消息队列, 共享内存, 信号量
	3:IPC 对象(消息队列,共享内存,信号量)存在内核中而不是文件系统中,由用户控制
	  释放(用户管理ipc 对象的生命周期),不像管道的释放由内核控制
	4:IPC 对象通过其标识符来引用和访问, 所有IPC 对象在内核空间中由唯一性标识ID,
	  在用户空间中中的唯一性标识称为 key
	5:Linux IPC 继承自System V IPC


2:System V IPC 对象的访问
	1:IPC 对象是全局对象
		可用 ipcs, ipcrm 等命令查看或删除
	2:每个IPC 对象都由get 函数创建
		描述msgget, shmget, semget
		调用get 函数时必须指定关键字 key
	4:ipcs 的使用
		-q, --queues		消息队列
		-m, --shmems		共享内存
		-s, --semaphores	信号量
	5:ipcrm 的使用
		-q ID				删除消息队列
		-Q key				同上
		-m ID				删除共享内存
		-M key				同上
		-s ID				删除信号量
		-S key				同上


3:IPC 对象的权限和所有者结构体
	struct ipc_perm{
		uid_t uid;		// owner's effective user id
		gid_t gid;		// owner's effective group id
		uid_t cuid;		// creator's effective user id
		gid_t cgid;		// creator's effective group id
		mode_t mode;	// access mode
		...
	}
