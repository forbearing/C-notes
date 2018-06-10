1:信号量
	1:本质上就是共享资源的数目,用来控制对共享资源的访问
	2:用于进程间的互斥和同步
	3:每种共享资源对应一个信号量,为了便于大量共享资源的操作引入了信号量集,可对
	  所有信号量一次性操作. 对信号量集中所有操作可以要求全部成功,也可以部分成功
	4:二元信号量(信号灯)值为0和1
	5:对信号量做PV 操作


2:信号量集属性
	#include <sys/sem.h>
	struct semid_ds{
		struct ipc_perm		sem_perm;
		unsigned short		sem_nsems;		// 信号灯的数量
		time_t				sem_otime;		// 最后一次对信号量集操作的时间
		time_t				sem_ctime;		// 对信号量集最后一次改变的时间
		...
	}

3:创建信号量集
	#include <sys/sem.h>
	int semget(key_t key, int nsems, int flag);
	1:返回: 成功返回信号量集ID, 出错返回-1
	2:参数:
		key: 用户指定的信号量集键值
		nsems: 信号量集中信号量个数
		flag: IPC_CREAT, IPC_EXCL 等权限的组合


4:信号量集控制
	#include <sys/sem.h>
	int semctl(int semid, int semnum, int cmd,.../* union semnu arg */);
	union semnu{
		int val;
		struct semid_ds *buf;
		unsigned short *array;
	}
	1:参数
		semid: 信号量集ID
		semnum: 0表示对所有信号量操作,信号量编号从0开始
		val: 放置获取或设置信号量集中某个信号量的值
		buf: 信号里量属性指针
		array: 放置获取或设置信号量集中所有信号量的值
	2:通过cmd 参数设定对信号量集要执行的操作
		IPC_STAT	获取信号量集的属性			buf
		IPC_SET		设置信号量集的属性			buf
		IPC_RMID	删除信号量集				buf
		GETVAL		返回信号量的值				val
		SETVAL		设置semnum 信号量的值		val
		GETALL		获取所有信号量的值			array
		SETALL		设置所有信号量的值			array


5:信号量集操作
	#include <sys/sem.h>
	int semop(int semid, struct sembuf *sops, size_t nsops);
	1:返回: 成功返回0, 出错返回-1
	struct sembuf{
		unsigned short sem_num;		// member # in set
		short			sem_op;		// operation(negtive, 0, positive)
		short			sem_flg;	// IPC_NOWAIT, SEM_UNDO
	}
	2:参数
		1:semid: 信号量集ID
		2:sops: sembuf 结构体数组指针
		3:nsops: 第二个参数中结构体数组的长度(一次操作信号量的个数)
		4:sem_num: 信号量集中信号量的编号
		5:sem_op: 正数为V操作,负数为P操作,0可用于对共享资源是否已完成的测试
		6:sem_flag: SEM_UNDO 标志表示在进程结束时,相应的操作将被取消. 如果设置了
		  该标志,那么在进程没有释放共享资源就退出时,内核将代为释放
	3:用于信号量集中信号量的加和减操作(PV操作)
	4:用于进程间的互斥和同步


课后练习
	1:由一个父进程fork 出两个子进程(进程扇)进行数据传递
	2:通过管道完成如下命令:
		cat /etc/passwd } awk -F: '{print $7} | grep sh | wc -l'
	3:两个进程通过文件实现数据传输, 要求实现同步(双向), 一个进程往文件中写入数据
	  后,另外一个进程再去从文件中读取该数据,做成循环方式的读写


示例:
	pv.h	pv.c						// 信号量集进行PV 操作
	reader_writer.c			// 读者写者问题, 信号量集进行PV 操作实现进程间同步
