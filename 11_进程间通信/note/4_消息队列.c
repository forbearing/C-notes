1:消息队列概念
	1:消息队列是内核中的一个链表
	2:用户进程简爱嗯数据传输到内核后,内核重新添加一些如用户ID,组ID,读写进程的ID
	  和优先级大呢该相关信息后并打包成一个数据包称为消息
	3:允许一个或多个进程往消息队列中写消息和读消息, 但一个消息只能被一个进程读取
	  读取完毕后就自动删除
	4:消息队列具有一定的FIFO 特性, 消息可以按照顺序发送到队列中,也可以几种不同的
	  方式从队列中读取. 每一个消息队列在内核中用一个唯一的IPC 标识ID 表示.
	5:消息队列的实现包括创建和打开队列,发送消息,读取消息和控制消息读列四种操作


2:消息队列属性
	struct msqid_ds{
		struct ipc_perm msg_perm;
		msgqnum_t	msg_qnum;		// 消息队列中消息的数量
		msglen_t	msg_qbytes;		// 消息队列中最大消息的字节数
		pid_t		msg_lspid;		// 最后发送消息的进程的 pid
		pid_t		msg_lrpid;		// 最后接受消息的进程的 pid
		time_t		msg_stime;		// 最后发送消息的时间
		time_t		msg_ctime;		// 最后消息改变的时间
		...
	}


3:打开或创建消息队列
	#include <sys/msg.h>
	int msgget(key_t key, int flag);
	1:返回: 成功返回内核中消息队列的标识ID, 出错返回-1
	2:参数:
		key: 用户指定的消息队列键值
		flag: IPC_CREAT, IPC_EXCL 等权限组合
	3:若创建消息队列, key 可指定键值, 也可将之设置为 IPC_PRIVATE(), 若打开进行
	  查询, 则key 不能为0, 必须是一个非零的值,否则是查询不到的
	4:key 的取值
		key_t key = atoi(argv[1]);
		key_t key = IPC_PRIVATE;
		key_t key = ftok(argv[1], 0);
			// 第一个参数如果是数字, key 就为-1
			// 第一个参数如果是文件路径, key 就为随机值


4:消息队列控制
	#include <sys/msg.h>
	int msgctl(int msgid, int cmd, struct msqid_ds *buf);
	1:返回: 成功返回0, 出错返回-1
	2:参数:
		msgid: 消息队列ID
		buf: 消息队列属性指针
		cmd:
			IPC_STAT: 获取消息队列的属性, 取此队列的msqid_ds 结构,并将其存放在
				buf 指向的结构体中
			IPC_SET: 设置属性, 按由buf 指向的结构体中的值, 设置与此队列相关的
				结构中的字段
			IPC_RMID: 删除队列, 从系统中删除该消息队列以及仍在该队列上的所欲数据


5:发送消息
	#include <sys/msg.h>
	int msgsnd(int msgqid, const void *ptr, size_t nbytes, int falg);
	1:返回: 成功返回0, 出错返回-1
	2:ptr
		struct mymesg{
			long mtype;				// 消息类型,只能大于0
			char mtext[512];		// 消息数据本身
		};
	3:nbytes 指定消息的大小, 不包括mtype 的大小
	4:mtype 指消息的类型, 它由一个整数来代表, 并且它只能是大于0的整数
	5:mtext 是消息数据本身
	6:在Linux 中, 消息的最大长度是4056个字节,其中包括mtype, 它占有4个字节
	7:结构体mymesg 用户可自定义, 但第一个成员必须是 mtype 
	8:flag:
		1:0 表示阻塞
		2:IPC_NOWAIT: 类似于文件I/O的非阻塞I/O标志
		3:若消息队列已满(或者是队列中的消息总数等于系统限制值,或队列中的字节总数
			等于系统限制值),则指定 IPC_NOWAIT 使得 msgsnd 立即出错返回 EAGAIN,
			如果指定0, 则进程
				1:阻塞直到有空间可以容纳要发送的消息
				2:或从系统中删除了此队列
				3:或捕捉到一个信号,并从信号处理程序返回


6:接受消息
	#include <sys/msg.h>
	ssize_t msgrcv(int msgqid, void* ptr, size_t nbytes, long type, ing flag);
	1:返回: 成功返回消息的数据部分长度, 出错返回-1
	2:参数
		msgqid: 消息队列ID
		ptr: 指向存放消息的缓存
		nbytes: 消息缓存的大小,不包括mtype 的大小. 计算方式如下:
			nbytes = sizeof(struct mymesg) - sizeof(long);
		type: 消息类型
			type == 0: 获得消息队列中第一个消息
			type > 0: 获得消息队列中类型为type 的第一个消息
			type < 0: 获得消息队列中小于或等于type 绝对值的消息(类型最小的)
		flag: 0或者IPC_NOWAIT


示例:
	msg_snd.c						// 消息队列--发送消息
	msg_rcv.c						// 消息队列--接受消息
