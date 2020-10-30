#include <stdio.h>
#include <string.h>


int main()
{
	char ass[1000001], pan[300001], *pFind;
	int count = 1;
	while (scanf("%s%s", ass, pan) == 2 && strcmp("0", ass) != 0)
	{
		if (count != 1) printf("\n");
		printf("Instancia %d\n", count++);
		pFind = strstr(pan, ass);
		if (pFind) printf("verdadeira\n");
		else printf("falsa\n");
	}
	return 0;
}



/*
1234
837384937292379450545045672392303485065402302373543504864694450034302
23034
837384937292379450545045672392303485065402302373543504864694450034302
0*/