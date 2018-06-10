1:Socket(套接字)
	1:Socket(套接字)是一种通讯机制,它包含一整套的调用接口和数据结构的定义,它给
	  应用程序提供了使用如TCP/UDP 等网络协议进行网路通讯的手段
	2:Linux 中的网络编程通过Socket 接口实现,Socket 既是一种特殊的IO,提供对应的
	  文件描述符. 一个完整的Socket 都有一个相关描述{协议,本地地址,本地端口,
	  远程地址,远程端口};每一个Socket 有一个本地地唯一Socket, 由操作系统分配


2:创建Socket
	#include <sys/socket.h>
	int socket(int domain, int type, int protocol);
	1:返回: 成功返回描述符, 出错返回-1
	2:Socket 创建在内核中,若创建成功返回内存文件描述符表中的socket 描述符
	3:参数
		domain:
			AF_INET		IPv4因特网域
			AF_INET6	IPv6因特网域
			AF_UNIX		unix域
			AF_UNSPEC	未指定
		protocol:
			通常为0, 表示按给定的域和套接字类型选择默认协议
		type:
			SOCK_STREAM
				流式的套接字可以提供可靠的,面向连接的通讯流,它使用了TCP 协议.
				TCP保证了数据传输的正确性和顺序性
			SOCK_DGRAM
				数据报套接字定义了一种无连接的服务,数据通过相互独立的报文进行
				传输,是无序的,并且不保证可靠,无差错,使用数据报协议UDP 协议
			SOCK_RAM
				原始套接字允许对底层协议如IP 或ICMP 直接访问,主要用于新的网络
				协议实现的测试等
			SOCK_SEQPACKET
				长度固定,有序,可靠的面向链接报文传递


3:字节序
	1:不同体系结构的主机使用不同的字节序存储器中保存多字节整数. 字节存储顺序不同
	  有的系统是高位在前,低位在后,而有的系统是低位在前,高位在后
	2:字节序分为大端和小端字节序
	3:网络协议使用网络字节序(大端字节序)


4:字节序转换函数
	1:网络传输的数据大家是一定要统一顺序的. 所以对与内部字节表示顺序和网络字节
	  顺序不同的机器,就一定要对数据进行转换
		uint32_t htonl(uint32_t hostlong);
			将一个32位整数由主机字节序转换成网络字节序
		uint16_t htons(uint16_t hostshort);
			将一个16位整数由主机字节序转换成网络字节序
		uint32_t ntohl(uint32_t netlong);
			将一个32位整数由网络字节序转换成主机字节序
		uint16_t ntohs(uint16_t netshort);
			将一个16位整数由网络字节序转换成主机字节序


5:通用地址结构
	#include <sys/socket.h>
	struct sockaddr{
		unsigned short sa_family;			// Internet 地址族,AF_XXX
		char sa_data[14];					// 14 bytes 的协议地址
	}
	1:sa_data 包含了一些远程电脑的地址,端口和套接字的数目,它里面的数据是杂溶
	  在一起的
	2:sa_family 一般来说,IPV4 使用AF_INET
	3:在传递给需要地址结构的函数时,把指向结构的指针转换成(struct sockaddr*)
	  传递进去


6:因特网地址结构
	struct in_addr{
		in_addr_t s_addr;				// IPv4 地址
	}
	struct sockaddr_in{
		short int sin_family;		// Internet 地址族,如AF_INET(主机字节序)
		unsigned short sin_port;	// 端口号,16位值(网络字节序)
		struct in_addr sin_addr;	// Internet 地址,32位IPv4地址(网络字节序)
		unsigned char sin_zero[8];	// 添0(为了格式对齐的填充位)
	};
	1:struct sockaddr 和 struct sockaddr_in, 这两个数据类型是等效的,可以相互转换
	  通常使用 sockaddr_in 更为方便


7:IPv4 地址族和字符地址间的转换
	#include <arp/inet.h>
	const char *inet_ntop(int domain, const void *restrict addr,
			char *restrict str, socklen_t size);
	1:返回: 成功返回地址字符串指针,出错返回NULL
	2:功能: 网路噢字节序转换成点分十进制
	int inet_pton(int domain, const char *restrict str, void *restrict addr);
	1:返回: 成功返回1, 无效格式返回0, 出错返回-1
	2:功能点分十进制转换成网络字节序
	3:参数:
		domain: Inetnet地址族,如AF_INET
		addr: Inetnet地址, 32为IPv4地址(网络字节序)
		str: 地址字符串(点分十进制)指针
		size: 地址字符串大小


8:TCP 客户端服务器编程模型
	1:客户端调用序列
		1;调用socket 函数创建套接字
		2:调用connect 连接服务器端
		3:调用I/O 函数(read/write)与服务器端通讯
		4:调用close 关闭套接字
	2:服务器端调用序列
		1:调用scoket 函数创建套接字
		2:调用bind 绑定本地地址和端口
		3:调用listen 启动监听
		4:条用accept 从已经连接队列中提取客户端连接
		5:调用I/O函数(read/write)与客户端通讯
		6:调用close 关闭套接字


9:套接字与地址绑定
	1:绑定地址
		#include <sys/socket.h>
		int bind(int sockfd, const struct sockaddr *addr, socklen_t len);
		返回: 成功返回0, 出错返回-1
	2:查找绑定到套接字的地址
		#include <sys/socket.h>
		int getsockname(int sockfd, struct sockaddr *restrict addr, 
				socklen_t *restrict alenp);
		返回: 成功返回0, 出错返回-1
	3:获取对方地址
		#include <sys/socket.h>
		int getpeername(int sockfd, struct sockaddr *restrict addr,
				socklen_t *restrict alenp);
		返回: 成功返回0, 出错返回-1
	4:特殊bind 地址
		1:一台主机可以由多个网络接口和多个IP 地址,如果我们只关心某个地址的连接
		  请求,我们可以指定一个具体的本地IP 地址,如果要响应所有接口上的连接请求
		  就要使用agiel特殊的地址: INADDR_ANY
		2:#define INADDR_ANY (uint32_t)0x00000000
		3:监听所有服务器上ip 得到的连接请求
			struct sockaddr_in serveraddr;
			memset(&serveraddr, 0, sizeof(serveraddr));
			serveraddr.sin_addr.s_addr = INADDR_ANY
	
10:建立连接
	1:服务器段
		#include <sys/socket.h>
		int listen(int sockfd, int backlog);
		返回: 成功返回0, 出错返回-1. backlog 指定进行客户端连接排队的队列长度
		int accept(int sockfd, struct sockaddr *restrict addr,
				socklen_t *restrict len);
		返回: 成功返回客户端socket(对应客户端的socket, 这个socket用来和客户端
				socket进行通信,类似于管道), 失败返回-1
			服务器端socket, 客户端socket, 获得的socket, 三种不同的socket
		参数
			sockfd: 服务器段socket
			sockaddr: 获取的客户端地址结构体指针
			len: 指针,sizeof(addr);
	2:客户端
		#include <sys/socket.h>
		int connect(int sockfd, const struct sockaddr *addr, socklen_t len);
		返回: 成功返回0, 出错返回-1


11:服务器并发性处理
	1:多进程模型
	2:多线程模型
	3:IO多路转换(select)


示例:
	tcp_server_time.c			// 客户端连接服务器端,服务器段返回一个系统时间
	tcp_client_time.c
	msg.h	msg.c				// 自定义协议
	tcp_server_echo.c			// 基于自定义协议的多进程模型的服务器编程
	tcp_client_echo.c
