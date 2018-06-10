/*
 * 文件名: io.h
 * 描述: 文件IO系统调用头文件
 * 完成日期: 2018年1月30日
 */
#ifndef __IO_H__
#define __IO_H__
#include <sys/types.h>

extern void copy(int fdin, int fdout);

extern void set_fl(int fd, int flag);				// 重新设置文件状态标志
extern void clr_fl(int fd, int flag);				// 清除文件状态标志

extern int lock_reg(int fd, int cmd,	\
		short type, off_t offset, short whence, off_t length);
#define READ_LOCKW(fd, offset, whence, length)	\
	lock_reg(fd, F_SETLKW, F_RDLCK, offset, whence, length)	// 共享读锁,阻塞
#define READ_LOCK(fd, offset, whence, length)	\
	lock_reg(fd, F_SETLK, F_RDLCK, offset, whence, length)	// 共享读锁,非阻塞
#define WRITE_LOCKW(fd, offset, whence, length)	\
	lock_reg(fd, F_SETLKW, F_WRLCK, offset, whence, length)	// 独占写锁,阻塞
#define WRITE_LOCK(fd, offset, whence, length)	\
	lock_reg(fd, F_SETLK, F_WRLCK, offset, whence, length)	// 独占写锁,非阻塞
#define UNLOCK(fd, offset, whence, length)	\
	lock_reg(fd, F_SETLK, F_UNLCK, offset, whence, length)	// 解锁


#endif
