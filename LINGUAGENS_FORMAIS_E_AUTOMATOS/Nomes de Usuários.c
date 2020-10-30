#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cleanBuffer();
int comp(const void *s1, const void *s2);

int main(void)
{
	int N, A, i, j, nsta;
	char **users, *pAux, word[101];
	while (!feof(stdin) && scanf("%d%d", &N, &A) == 2)
	{
		users = (char **)malloc(N * sizeof(*users));
		cleanBuffer();
		for (i = 0; i < N; ++i)
		{
			gets(word);
			j = 0;
			pAux = strtok (word, " ");
			while (pAux != NULL)
			{
				word[j++] = *pAux;
				pAux = strtok(NULL, " ");
			}
			word[j] = '\0';
			users[i] = (char *)malloc((strlen(word) + 5) * sizeof(**users));
			sprintf(users[i], "%s%d", word, A);
		}
		
		qsort(users, N, sizeof(users[0]), comp);
		nsta = 0;
		for (i = 0; i < N-1; ++i)
		{
			if (strcmp(users[i], users[i+1]) == 0) nsta++;
		}
		/*---------------------------Alternative---------------------------*/
		/*
		for (i = N - 1; i >= 0; --i)
		{
			pAux = bsearch(&users[i], users, N, sizeof(users[0]), comp);
			if (pAux != &users[i]) nsta++;
		}
		*/
		printf("%d\n", nsta);
		for (i = 0; i < N; ++i)
			free(users[i]);
		free(users);
	}
	return 0;
}

void cleanBuffer()
{
	char c;
	while ((c = getchar()) != '\n' && c != EOF);
}

int comp(const void *s1, const void *s2)
{
	return (strcmp(*(char **)s1, *(char **)s2));
}