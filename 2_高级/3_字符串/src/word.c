/*
 * Copyright (c) 我的有限公司
 * 文件名: word.c
 * 描述: 计算输入语句中单词的平均长度
 * 作者: hyb
 * 完成日期: 2018男1月7号
 * 当前版本: 1.0
 */

#include <stdio.h>
#include <string.h>

int main(void)
{
	int letter = 0, word_count = 0, flag = 0;
	char array[30] = {'\0'};

	printf("Please input a sentence: ");
	fgets(array, sizeof(array), stdin);
	int n = strlen(array);
	int i;
	for(i=0; i<n; i++){
		char ch = array[i];
		if(ch == '\n')	break;
		/* 碰到空白字符(空格和水平制表符) */
		if(ch == ' ' || ch =='\t'){
			flag = 0;
		/* 碰到单词的第一个字母 */
		}else if(!flag && ch != ' ' && ch != '\t'){
			word_count++;
			flag = 1;
		}
		/* 对非空白字符进行累加计数 */
		if(ch != ' ' && ch != '\t')
			letter ++;
	}
	printf("Average word length: %.1f\n", (float)letter/word_count);

	return 0;
}
