/*
 * 文件名: lock_my.c
 * 描述: 文件锁的介绍和使用
 * 完成日期: 2018年2月3日11:10
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

int  lock_reg(int fd, int cmd,	\
		short type, off_t offset, short whence, off_t length);
#define RD_LK(fd, offset, whence, length)	\
	lock_reg(fd, F_SETLK, F_RDLCK, offset, whence, length)
#define WR_LK(fd, offset, whence, length)	\
	lock_reg(fd, F_SETLK, F_WRLCK, offset, whence, length)
#define UNLOCK(fd, offset, whence, length)	\
	lock_reg(fd, F_SETLK, F_UNLCK, offset, whence, length)

int main(int argc, char *argv[])
{
	if(argc < 3){
		fprintf(stderr, "Usage: %s file [lock|unlock]\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	char buf[20] = "hello linux";
	ssize_t size = strlen(buf);

	int fd = open(argv[1], O_RDWR | O_TRUNC |O_CREAT, 0777);
	if(fd < 0){
		perror("read file error");
		exit(EXIT_FAILURE);
	}

	// 加锁或解锁
	if(!strcmp("lock", argv[2])){
		WR_LK(fd, 0, SEEK_SET, 0);
		printf("lock success\n");
		printf("lock process pid is: %d\n", getpid());
	}else if(!strcmp("unlock", argv[2])){
		UNLOCK(fd, 0, SEEK_SET, 0);
		printf("unlock success\n");
		printf("unlock process pid is: %d\n", getpid());
	}else{
		fprintf(stderr, "Usage: %s file [lock|unlock]\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	// 每次值写入一个字符
	char *p = buf;
	int i;
	for(i=0; i< size; i++){
		if(write(fd, (p+i), 1) != 1){
			perror("write error");
			exit(EXIT_FAILURE);
		}
		printf("write a character: %c\n", *(p+i));
		sleep(1);
	}
	printf("write finished\n");

	close(fd);

	return 0;
}

int  lock_reg(int fd, int cmd,	\
		short type, off_t offset, short whence, off_t length){
	struct flock *lock;
	lock->l_type = type;
	lock->l_start = offset;
	lock->l_whence = whence;
	lock->l_len = length;
	lock->l_pid = getpid();
	if(fcntl(fd, cmd, lock) < 0){
		perror("fcntl error");
		return -1;
	}
	return 0;
}
