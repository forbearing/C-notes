/*
 * Copyright (c) 2018 我的有限公司
 * 文件名: bit_struct.c
 * 描述: 位段的介绍和使用
 * 作者: Hyb
 * 完成日期: 2018年1月15日
 * 当前版本: 1.0
 */

#include <stdio.h>

struct controller
{
	unsigned int	adr :16;
	unsigned int	err	:8;
	unsigned int	ope	:8;
};

void out(struct controller *d)
{
	printf("ope:%u, err:%u, adr:%u\n", d->ope, d->err, d->adr);
}

int main(void)
{
	struct controller disk;
	disk.adr = 65535;
	disk.err = 255;
	disk.ope = 255;

	struct controller *p;
	p = &disk;
	out(p);

	return 0;
}
