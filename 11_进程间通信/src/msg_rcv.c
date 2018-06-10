/*
 * 文件名: msg_rcv.c
 * 描述: 消息队列--接受消息
 * 完成日期: 2018年2月24日 22:50
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/msg.h>

#define handle_error(msg)	\
	do { perror(msg); exit(EXIT_FAILURE); } while(0)

typedef struct{
	long	type;
	int		start;
	int		end;
}MSG;

int main(int argc, char *argv[])
{
	if(argc < 2){
		fprintf(stderr, "Usage: %s key type\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	key_t key = atoi(argv[1]);
	long type = atoi(argv[2]);

	
	/* 获得指定的消息队列 */
	int msqid;
	if((msqid = msgget(key, 0777)) < 0)
		handle_error("msgget error");
	
	/* 获得消息 */
	MSG m;
	if(msgrcv(msqid, &m, sizeof(MSG)-sizeof(long), type, IPC_NOWAIT) < 0)
		handle_error("msgrcv error");
	else
		printf("type: %ld, start: %d, end: %d\n", m.type, m.start, m.end);

	/* 销毁消息队列 */
	//if(msgctl(msqid, IPC_RMID, NULL) < 0)
	//	handle_error("msgctl error");

	return 0;
}
