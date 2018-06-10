#include <stdio.h>
#include <stdlib.h>

void sort(char content[], int n);

int main(int argc, char *argv[])
{
	if(argc != 4){
		printf("Usage: %s file_A file_B file_C", argv[0]);
		exit(EXIT_FAILURE);
	}

	FILE *fp1 = fopen(argv[1], "r");
	if(fp1 == NULL){
		printf("open file error\n");
		exit(EXIT_FAILURE);
	}
	FILE *fp2 = fopen(argv[2], "r");
	if(fp2 = NULL){
		printf("open file error\n");
		exit(EXIT_FAILURE);
	}
	FILE *fp3 = fopen(argv[3], "r");
	if(fp3 == NULL){
		printf("open file error\n");
		exit(EXIT_FAILURE);
	}

	char content[100];
	int ch;
	int i = 0;
	while((ch = fgetc(fp1)) != EOF){
		putchar(ch);
		if(ch == '\t' || ch == ' ' || ch =='\t')
			continue;
		content[i++] = ch;
	}
	fclose(fp1);
	while((ch = fgetc(fp2)) != EOF){
		putchar(ch);
		if(ch == '\t' || ch == ' ' || ch =='\t')
			continue;
		content[i++] = ch;
	}
	fclose(fp2);

	int n = i;
	sort(content, n);
	
	for(i=0; i<n; i++){
		putchar(content[i]);
		fputc(content[i], fp3);
	}
	putchar('\n');
	fputc('\n', fp3);
	fclose(fp3);

	return 0;
}

void sort(char content[], int n)
{
	int i,j;
	for(i=0; i<n-1; i++){
		int pos = i;
		for(j=i+1; j<n; j++){
			if(content[j] < content[pos])
				pos = j;
		}
		if(pos != i){
			int ch;
			ch = content[pos];
			content[pos] = content[i];
			content[i] = ch;
		}
	}
}
