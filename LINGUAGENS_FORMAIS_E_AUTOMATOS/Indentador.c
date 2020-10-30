#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ident(int n) {	while(n--) 	printf("....");}

int main(void)
{
	int i, bracket = 0, inF = 0;
	char line[2001];
	while (!feof(stdin) && gets(line))
	{
		if (line[0] == '#') 
		{
			printf("%s\n", line);
			continue;
		}
		for (i = 0; i < strlen(line); ++i)
		{
			if (line[i] == ';' && !inF)
			{
				printf("%c\n", line[i]);
				if(line[i+1] != '}') ident(bracket);
				continue;
			}
			if (line[i] == '{')
			{
				printf("\n");
				ident(bracket);
				printf("%c\n", line[i]);
				bracket++;
				if(line[i+1] != '}') ident(bracket);
				continue;
			}
			if (line[i] == '}')
			{
				bracket--;
				ident(bracket);
				printf("%c\n", line[i]);
				if(line[i+1] != '}') ident(bracket);
				continue;
			}

			if (line[i] == '(') inF = 1;
			else if (line[i] == ')') inF = 0;
			putchar(line[i]);
		}
	}
	return 0;
}