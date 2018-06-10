1:UDP 编程模型
	1:服务器端
		socket() -> bind() -> readfrom() -> sendto() -> close()
	2:客户端
		socket() -> bind() -> sendto() -> readfrom() -> close()


2:发送数据
	#include <sys/socket.h>
	ssize_t send(int sockfd, const void *buf, size_t nbytes, int flag);
	返回: 成功返回发送的字节数, 出错返回-1
	ssize_t sendto(int sockfd, const void *buf, size_t nbytes, int flag,
			const struct sockaddr *destaddr, socklen_t destlen);
	返回: 成功返回发送的字节数, 出错返回-1
	ssize_t sendmsg(int sockfd, const struct msghdr *msg, int flag);
	返回: 成功返回发送的字节数, 出错返回-1
	struct msghdr{
		void *msg_name;				// optional address
		socklen_t msg_namelen;		// address size in bytes
		struct iovec *msg_iov;		// array of I/O buffers
		int msg_iovlen;				// number of elements in array
		void *msg_control;			// ancillary data
		socklen_t msg_controllen;	// number of ancillary bytes
		int msg_flags;				// flags for received message
	}


3:接收数据
	#include <sys/socket.h>
	ssize_t recv(int sockfd, void *buf, size_t nbytes, int flag);
	ssize_t recvfrom(int sockfd, void *restrict buf, size_t len, int flag,
			struct sockaddr *restrict addr, socklen_t *restrict addrlen);
	ssize_t recvmsg(int sockfd, struct msghdr *msg, int flag);
	返回: 成功返回消息的字节数, 无消息返回0, 出错返回-1


4:设置套接字选项
	int ret;
	int opt = 1;
	if((ret = setsockopt(sockfd, SOL_SOCKET, 
					SO_REUSEADDR, &opt, sizeof(opt))) < 0){
		perror("setsockopt error");
		exit(EXIT_FAILURE);
	}


总结
	1:在TCP 编程中,客户端调用connect 会经过三次握手, 在UDP 编程中,客户端即使调用
	  connect 也不会握手,只不过是在内核中记录了服务器端的地址信息(ip,port)
	2:udp 编程中, 客户端调用connect 之后, 客户端向服务器端发送信息可以不使用
	  sendto, 可以使用send 函数
	3:bind, connect, sendto: sockeln_t len
	4:accept, getpeername, getsockname, recvfrom: socklen_t *len
	5:发送数据报文函数(send, sendto)和接收数据报文函数(recv, recvfrom)都是阻塞
	  性读写函数
	6:udp编程中如果使用了setsockopt 的SO_REUSEADDR 选项, 就可以两个服务器端都
	  绑定同一个端口,但只有最后一个绑定端口的服务器端才可以接受数据


示例:
	udp_server_time.c
	udp_client_time.c
