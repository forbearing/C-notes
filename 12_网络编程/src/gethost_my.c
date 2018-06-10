/*
 * 文件名: gethost_my.c
 * 描述: 域名解析
 * 完成日期: 2018年3月1日 7:50
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

void out_addr(struct hostent *h){
	printf("host name: %s\n", h->h_name);
	printf("addrtype: %s\n", h->h_addrtype == AF_INET ? "IPv4" : "IPv6");
	int i = 0;
	while(h->h_aliases[i] != NULL){
		printf("alias: %s\n", h->h_aliases[i]);
		i++;
	}
	i = 0;
	char ip[16];
	memset(ip, 0, sizeof(ip));
	while(h->h_addr_list[i] != NULL){
		inet_ntop(h->h_addrtype, h->h_addr_list[i], ip, sizeof(ip));
		printf("ip address: %s\n", ip);
		i++;
	}
}

int main(int argc, char *argv[])
{
	if(argc < 2){
		fprintf(stderr, "Usage: %s host\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	
	struct hostent *h;
	if((h = gethostbyname(argv[1])) == NULL){
		perror("gethostbyname error");
		exit(EXIT_FAILURE);
	}else{
		out_addr(h)	;
	}

	return 0;
}
