#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	char *s = "hello linux";
	ssize_t size = strlen(s) * sizeof(char);
	FILE *fp = fopen("fp", "w");
	if(fp == NULL){
		perror("fopen error");
		exit(EXIT_FAILURE);
	}
	
	fprintf(fp, "s:%s, pid:%d\n", s, getpid());

	fclose(fp);

	return 0;
}
