#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char Flag = 0x80;
	int i;
	if(Flag & 0x80)
	{
		i = (Flag &= ~0x80);
		printf("0x%X\n", i);
		printf("%d\n", i);
	}
	system("pause");
	return 0;
}