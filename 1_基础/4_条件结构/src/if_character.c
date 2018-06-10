/*
 * Copyright (c) 我的有限公司
 * 文件名: if_character.c
 * 描述: 从屏幕终端读取一个字符并判断其类型
 * 作者: hyb
 * 完成日期: 2017年12月19号
 * 当前版本: 1.0
 */

#include <stdio.h>
#include <ctype.h>

int main(void)
{
	char charIn;
	printf("Please input a character: ");
	scanf("%c", &charIn);

	if(isalpha(charIn)){				// 判断是否是字母
		printf("Your input a letter\n");
		if(islower(charIn)){			// 判断是否小写
			printf("You input a lowercase letter\n ");
			printf("toupper(%c): %c\n",charIn, toupper(charIn));
		}
		if(isupper(charIn)){			// 判断是否大写
			printf("You input a uppercase letter\n");
			printf("tolower(%c): %c\n",charIn, tolower(charIn));
		}
	}else if(isdigit(charIn)){			// 判断是否是数字
		printf("You input a digit\n");
	}else if(ispunct(charIn)){			// 判断是否是标点符号
		printf("You input a punctuation character\n");
	}else if(isspace(charIn)){			// 判断是否为空白字符
		printf("You input a whitespace character\n");
	}else{
		printf("You input a unknow character\n");
	}

	return 0;
}
