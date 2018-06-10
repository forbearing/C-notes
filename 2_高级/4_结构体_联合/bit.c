#include <stdio.h>

struct controller{
	unsigned int adr:16;
	unsigned int err:8;
	unsigned int ope:8;

};

void out(struct controller *p){
	printf("adr:%u err:%u ope:%u\n", p->adr, p->err, p->ope);
}

int main(void)
{
	struct controller disk = {65535, 255, 255};
	struct controller *p_disk = &disk;
	out(p_disk);

	return 0;
}
