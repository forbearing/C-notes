/*
 * 文件名: msg.h
 * 描述: 自定义协议
 * 完成日期: 2018年2月28日 10:15
 */
#ifndef __MSG_H__
#define __MSG_H__

typedef struct{
	char head[10];		// 协议头部
	char checknum;		// 校验码
	char buf[512];		// 数据
}Msg;

/* 发送一个基于自定义协议的message, 发送的数据存放在buf 中 */
extern int write_msg(int sockfd, char *buf, size_t len);

/* 接受一个基于自定义协议的message, 接受的数据存放在buf 中 */
extern int read_msg(int sockfd, char *buf, size_t len);

#endif
