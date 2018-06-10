1:mkdir 和 rmdir 函数
	#include <sys/types.h>
	#include <sys/stat.h>
	int mkdir(const char *pathname, mode_t mode);
	1:返回: 成功返回0, 出错返回-1
	2:功能: 创建目录
	int rmdir(const char *pathname)
	1:返回: 成功返回0, 出错返回-1
	2:功能: 删除目录
	创建目录:
		1:创建一个新的空目录, . 和 .. 目录是自动创建的
		2:创建目录时,至少指定一个执行权限位
	目录删除条件
		1:该目录的链接计数为2(只包含.和..), 只删除空目录
		2:无其他进程打开此目录


2:opendir, readdir, rewinddir 和 closedir 函数
	#include <sys/types.h>
	#include <dirent.h>
	DIR *opendir(const char *pathname);
	1:返回: 成功返回目录指针, 出错返回 NULL
	2:功能: 打开目录
	struct dirent *readdir(DIR *dp);
	1:返回: 成功返回指针,若在目录结尾或者出错返回 NULL
	2:功能: 读取目录
	void rewinddir(dir(DIR *dp));
	1:返回: 成功返回0, 出错返回-1
	2:功能: 重新定位从头开始读取
	int closedir(DIR *dp);
	1:返回: 成功返回0, 出错返回-1
	2:功能: 关闭目录
	struct dirent{
		ino_t d_ino;					// 目录的 i-node 编号
		char d_name[NAME_MAX + 1];		// 目录的名字
	}


3:chdir, fchdir 和 getcwd 函数
	#include <unistd.h>
	int chdir(const char *pathname);
	int fchdir(int fd);
	1:返回: 成功返回0, 出错返回-1
	2:功能: 分别用 pathname 或 fd 来指定新的当前工作目录
	char *getcwd(char *buf, size_t size);
	1:返回: 成功返回 buf, 出错返回 NULL
	2:功能: 获取当前工作目录的绝对路径
	** 当前工作目录是一个进程的属性,所以它只影响调用 chdir 的进程本身,而不影响
	其他进程.(改变了路径不会影响 shell 的当前路径)


示例
	dir_read.c
	dir.c
	chdir.c
