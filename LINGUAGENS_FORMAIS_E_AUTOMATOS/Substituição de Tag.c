#include <stdio.h>
#include <string.h>


int main(int argc, char const *argv[])
{
	char tag[11], res[51], *pFind;
	int value, open, tam;
	while(!feof(stdin) && scanf("%s\n%d\n%[^\n]s\n", tag, &value, res) == 3)
	{
		pFind = res;
		open = 0;
		tam = strlen(tag);
		while(*pFind != '\0')
		{
			if(*pFind == '<') open = 1;
			if(*pFind == '>') open = 0;
			if (open == 1 && strncasecmp(tag, pFind, tam) ==  0)
			{
				printf("%d",value);
				pFind += tam;
				continue;
			}
			printf("%c", *pFind);
			pFind++;
		}
		printf("\n");
	}
	return 0;
}