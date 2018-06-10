1:文件属性
	struct stat{
		mode_t st_mode;			// 文件的类型和权限
		ino_t st_ino;			// inode
		dev_t st_dev;			// device number(file system)
		dev_t st_rdev;			// device number for special files
		nlink_t st_nlink;		// 链接数量
		uid_t st_uid;			// 文件拥有者的 user ID
		gid_t st_gid;			// 文件拥有者的 group ID
		off_t st_size;			// 文件大小
		time_t st_atime;		// access time, 最后一次访问时间
		time_t st_mtime;		// modification time, 最后以此修改时间
		time_t st_ctime;		// change time, 文件状态最后改变的时间
		blksize st_blksize;		// best I/O block size
		blkcnt_t st_blocks		// number of disk blocks allocated
	};


2:文件属性操作函数
	#include <sys/types.h>
	#include <sys/stat.h>
	int stat(const char *pathname, struct stat *buf);
	int fstat(int fd, struct stat *buf);
	int lstat(const char *pathname, struct stat *buf);
	1:返回: 若成功返回0,若出错则为-1
	2:功能: 返回一个与 pathname 或 fd 指定的文件属性信息,存储在结构体 buf 中
	3:参数
		pathname: 文件路径名字
		buf: struct stat 结构体指针
	4:lstat 函数类似与 stat,但是当命名的文件是一个符号链接时, lstat 返回该符号
	  链接的有关信息,而不是由该符号链接引用的文件的信息


3:文件类型
	Linux 中的其中文件和七种宏
	1:普通文件(regular file)				S_ISREG()
	2:目录文件(directory file)				S_ISDIR()
	3:符号链接(symbolic link)				S_ISLNK()
	4:块特殊文件(block special file)		S_ISBLK()
	5:字符特殊文件(character special file)	S_ISCHR()
	6:FIFO(named pipe)						S_ISFIFO()
	7:套接字(socket)						S_ISSOCK()


4:文件权限
	1:9种文件访问权限
		用户权限
			S_IRUSR, S_IWUSR, S_IXUSR
		组权限
			S_IRGRp, S_IWGRP, S_IXGRP
		其他权限
			S_IROTH, S_IWOTH, S_IXOTH
	2:文件权限通过按位或方式构造



示例
	filetype.c								// 判断文件类型
	file_perm.c								// 判断文件权限
