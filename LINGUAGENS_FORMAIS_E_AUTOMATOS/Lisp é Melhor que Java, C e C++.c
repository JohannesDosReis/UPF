#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct dic
{
	void *num;
	void *string;
}TDic;

int compToOrdem(const void *s1, const void *s2)
{
	TDic *str1 = (TDic *)s1, *str2 = (TDic *)s2;
	if (*(char *)str1->num < *(char *)str2->num) return -1;
	else if (*(char *)str1->num > *(char *)str2->num) return 1;
	else return strcmp(str1->string, str2->string);
}


int compNum(const void *s1, const void *s2)
{
	TDic *str2 = (TDic *)s2;
	if (**(char **)s1 < *(char *)str2->num) return -1;
	else if (**(char **)s1 > *(char *)str2->num) return 1;
	else return 0;
}

void cleanBuffer()
{
	char c;
	while ((c = getchar()) != '\n' && c != EOF);
}

void StrToNum(char *str)
{
	char *pAux = str;
	while (*str != '\0')
	{
		switch (tolower(*(str++)))
		{
		case 'e': *(pAux++) = '0'; break;
		case 'j':
		case 'n':
		case 'q': *(pAux++) = '1'; break;
		case 'r':
		case 'w':
		case 'x': *(pAux++) = '2'; break;
		case 'd':
		case 's':
		case 'y': *(pAux++) = '3'; break;
		case 'f':
		case 't': *(pAux++) = '4'; break;
		case 'a':
		case 'm': *(pAux++) = '5'; break;
		case 'c':
		case 'v':
		case 'i': *(pAux++) = '6'; break;
		case 'b':
		case 'k':
		case 'u': *(pAux++) = '7'; break;
		case 'l':
		case 'o':
		case 'p': *(pAux++) = '8'; break;
		case 'g':
		case 'h':
		case 'z': *(pAux++) = '9'; break;
		}
	}
	*pAux = '\0';
}

void NumToNum(char *str)
{
	char *pAux = str;
	while (*str != '\0')
	{
		if (isdigit(*str)) *(pAux++) = *str;
		str++;
	}
	*pAux = '\0';
}

void findCod(char ToShow[], char num[], TDic *dic, int n)
{
	int i, j, k = strlen(ToShow), find = 0;
	TDic *pFind;
	pFind = (TDic *)bsearch(&num, dic, n, sizeof(dic[0]), compNum);
	if (pFind)
	{
		while (*(char *)pFind->num == num[0] && pFind != dic) pFind--;
		if (pFind != dic && pFind != &dic[n - 1]) pFind++;
		while (*(char *)pFind->num == num[0])
		{
			if (strncmp(num, pFind->num, j = strlen(pFind->num)) == 0)
			{
				find = 1;
				sprintf(&ToShow[k], " %s", pFind->string);

				if (num[j] != '\0') findCod(ToShow, &num[j], dic, n);
				else printf("%s\n", ToShow);
			}
			if (pFind == &dic[n - 1]) break;
			pFind++;
		}
	}
	if (!find)
	{
		if (isdigit(ToShow[k - 1])) return;
		sprintf(&ToShow[k], " %c", num[0]);
		if (num[1] != '\0') findCod(ToShow, &num[1], dic, n);
		else printf("%s\n", ToShow);
	}
}

int main(void)
{
	TDic *dic;
	int i, n, t, j = 0, k;
	char aux[1000], aux2[1000];
	while (scanf("%d", &n) == 1 && n != 0)
	{
		if (j) putchar('\n');
		cleanBuffer();
		printf("Instancia %d\n", ++j);
		dic = (TDic *)malloc(n * sizeof(*dic));
		for (i = 0; i < n; ++i)
		{
			gets(aux);
			dic[i].string = (char *)malloc(sizeof(char) * strlen(aux) + 1);
			strcpy(dic[i].string, aux);
			StrToNum(aux);
			dic[i].num = (char *)malloc(sizeof(char) * strlen(aux) + 1);
			strcpy(dic[i].num, aux);
		}
		qsort(dic, n, sizeof(dic[0]), compToOrdem);
		scanf("%d", &t);
		cleanBuffer();
		for (i = 0; i < t; ++i)
		{
			gets(aux);
			strcpy(aux2, aux);
			NumToNum(aux2);
			strcat(aux, ":");
			//sprintf(aux, "%s:", aux);
			findCod(aux, aux2, dic, n);
		}
		for (i = 0; i < n; ++i)
		{
			free(dic[i].num);
			free(dic[i].string);
		}
		free(dic);
	}
	return 0;
}