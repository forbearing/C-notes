#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <assert.h>

#define handle_error(msg) \
	do{ perror(msg); exit(EXIT_FAILURE); } while(0)

int main(int argc, char *argv[])
{
	if(argc < 3){
		fprintf(stderr, "Usage: %s srcfile desfile\n", argv[0]);
		exit(1);
	}

	int fd1 = open(argv[1], O_RDWR);
	assert(fd1 > 0);
	int fd2 = open(argv[2], O_RDWR | O_CREAT | O_TRUNC, 0777);
	if(fd2 < 0)
		handle_error("open desfile error");

	return 0;
}
