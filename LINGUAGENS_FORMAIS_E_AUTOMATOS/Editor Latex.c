#include <stdio.h>
#include <string.h>

int Tcircle(char str[]);
int pstree(char str[]);

int main(void)
{
	char line[1001];
	int i;
	while (!feof(stdin) && gets(line))
	{
		i = Tcircle(line) + pstree(line);
		if (i && line[i] == '\0') printf("SIM\n");
		else printf("NAO\n");
	}
	return 0;
}

int Tcircle(char str[])
{
	int i = 0;
	if (strncmp(str, "\\Tcircle{", 9) != 0) return 0;
	i += 9;
	if (str[i] > 90 || str[i] < 65 ) return 0;
	i++;
	if (str[i++] != '}') return 0;
	return i;
}

int pstree(char str[])
{
	int i = 0, j;
	if (strncmp(str, "\\pstree{", 8) != 0) return 0;
	i += 8;
	j = Tcircle(&str[i]);
	if (j == 0) return 0;
	i += j;
	if (str[i++] != '}') return 0;
	if (str[i++] != '{') return 0;
	j = Tcircle(&str[i]) + pstree(&str[i]);
	i += j;
	j = Tcircle(&str[i]) + pstree(&str[i]);
	i += j;
	if (str[i++] != '}') return 0;
	return i;
}