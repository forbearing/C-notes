#ifndef __MSTDIO_H__
#define __MSTDIO_H__
#include <sys/types.h>

#define MEOF -1
enum mode{READ, WRITE, APPEND};

typedef struct
{
	int		_fd;
	char	*_buffer;				// 指向缓冲区
	char	*_nextc;				// 指向下一个字符
	int		_mode;
	off_t	_left;
}MFILE;

extern MFILE* mfopen(const char * const pathname, const char* const mode);
extern int mfclose(MFILE *fp);
extern void mfflush(MFILE *fp);
extern MFILE* mfdopen(int fd, const char* const mode);

extern int mfgetc(MFILE *fp);
extern int mfputc(int character, MFILE *fp);
extern int mungetc(int character, MFILE *fp);
extern char * mfgets(char *buff, int size, MFILE *fp);
extern char * mfputs(char *buff, MFILE *fp);
extern size_t mfread(void *buff, size_t size, size_t counter, MFILE *fp);
extern size_t mfwrite(void *buff, size_t size, size_t counter, MFILE *fp);


#endif
