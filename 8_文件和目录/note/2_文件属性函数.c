1:access 函数
	#include <unistd.h>
	int access(const char *pathname, int mode);
	1:返回: 成功执行返回0, 出错返回-1
	2:功能: 检查是否可以对指定文件进行某种操作
	3:参数:
		pathname: 文件路径
		mode: 文件访问的权限
			R_OK	判断文件是否有读取权限
			W_OK	判断文件是否由写权限
			X_OK	判断文件是否由可执行权限
			F_OK	判断文件是否存在


2:umask 函数
	#include <sys/types.h>
	#include <sys/stat.h>
	mode_t umask(mode_t mode);
	1:返回: 以前的文件模式创建屏蔽字
	2:功能: 为进程设置文件方式创建屏蔽字, 并返回以前的值
	3:参数:
		mode 文件权限常量(例如: S_IRGRp, S_IWGRP 等)
	4:被 umask 设置过的权限不能再使用在创建文件的权限上

	
3:chmod 和 fchmod 函数
	#include <sys/stat.h>
	int chmod(const char *pathname, mode_t mode);
	int fchmod(int fd, mode_t mode);
	1:返回: 成功返回0, 出错返回-1
	2:功能: 更改现存文件的权限, chmod 函数在指定的文件上进行操作, 而 fchmod
			函数则对已打开的文件进行操作
	3:参数:
		pathname: 文件路径名字
		mode: 文件权限(按位或操作)
			S_ISUID, S_ISGID, S_ISVTX
			S_IRWXU, S_IRUSR, S_IWUSR, S_IXUSR
			S_IRWXG, S_IRGRP, S_IWGRP, S_IXGRP
			S_IRWXO, S_IROTH, S_IWOTH, S_IXOTH
	4:想要改变一个文件的权限位,需满足条件:
		进程的有效用户 ID 必须等于文件的所有者 ID
		进程具有超级用户权限


4:truncate 和 ftruncate 函数
	#include <sys/types.h>
	#include <unistd.h>
	int truncate(const char *pathname, off_t length);
	int ftruncate(int fd, off_t length);
	1:返回: 成功返回0,出错返回-1
	2:功能: 文件截短
	3:参数:
		pathname: 文件路径名字
		length: 文件截短后的长度
	4:在文件尾端处截去一些数据以缩短文件
	5:将一个文件的长度截短为0是一个特例,用 O_TRUNC 标志可以做到这一点
	6:如果该文件以前的长度大于 length, 则超过 length 以外的数据就不能存取,
	  如果以前的长度短于 length, 则其后果与系统有关


5:link 和 unlink 函数
	#include <unistd.h>
	int link(const char *existingpath, const char *newpath);
	1:返回: 成功返回0, 出错返回-1
	2:功能: 创建一个指向现存文件链接(硬链接)
	int unlink(const char *pathname);
	1:返回: 成功返回0, 出错返回-1
	2:功能: 删除 pathname 指向的硬链接,并将由 pathname 所引用的文件链接计数减1
	硬链接创建条件
		1:针对文件创建链接
		2:必须是同一个分区
		3:只有超级用户才能对目录建立链接
	文件删除条件
		链接计数为0
		无其他进程打开该文件


6:remove 和 rename 函数
	#include <unistd.h>
	int remove(const char *pathname);
	1:返回: 成功返回0, 出错返回-1
	2:功能: 解除对一个文件或目录的链接
	int rename( const char *oldname, const char *newname);
	1:返回: 成功返回0, 出错返回-1
	2:功能: 文件或目录更名
	对于文件: remove 的功能与 unlink相同
	对于目录, remove 的功能与 rmdir 相同


7:symlink 和 readlink 函数
	#include <unistd.h>
	int symlink(const char *actualpath, const char *sympath);
	1:返回: 成功返回0, 出错返回-1
	2:功能: 创建一个符号连接(软链接)
	int readlink(const char *restrict pathname, 
			char *restrict buf, size_t bufsize);
	1:返回: 成功返回读到的字节数, 出错返回-1
	2:功能: 打开该链接本身,并读该链接中的名字
	符号连接的创建
		创建符号链接并不要求 actualpath 存在
		可以跨文件系统建立符号链接


8:文件时间和 utime 函数
	#include <sys/types.h>
	#include <utime.h>
	int utime(const char *pathname, const struct utimbuf *times);
	1:返回: 成功返回0, 出错返回-1
	2:功能: 更改文件的存取和修改时间
	3:参数 times
		1:空指针: 取当前时间
			进程的有效用户 ID 必须等于该文件的所有者 ID
			或者进程对该文件具有写权限
		2:非空: 取 times 结构体中的时间
			进程的有效用户 ID 必须等于该文件的所有者 ID
			或者进程是超级用户进程
	4:utime 操作会自动更新 st_time 值
	5:struct utimbuf{
		time_t actime;		// access time
		time_t modtime;		// modification time;
	}
	struct stat 结构体成员
		st_atime	文件数据最后访问时间		read			ls -u
		st_mtime	文件数据最后修改时间		write			默认
		st_ctime	i节点最后更改时间			chmod,chown		ls -c




示例:
	file_access.c
	file_umask.c
	file_chmod.c
	file_truncate.c
	file_hardlink.c
	file_softlink.c
	softlink.c
	file_utime.c
