1:域名解析函数
	struct hostent{
		char	*h_name;			// 正式主机名
		char	**h_aliases;		// 别名,字符串数组
		int		h_addrtype;			// 协议类型
		int		h_length;			// 网络地址大小
		char	**h_addr_list		// 指向网络地址的指针
	}
	#include <netdb.h>
	struct hostent *gethostent(void);
	struct hostent *gethostbyname(const char *hostname);
	void sethostent(int stayopen);
	void endhostent(void);

示例
	gethost.c
	gethost2.c
	udp_gethost.c
