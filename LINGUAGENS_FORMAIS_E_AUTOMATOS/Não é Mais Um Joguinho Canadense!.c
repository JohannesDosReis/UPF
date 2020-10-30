#include <stdio.h>
#include <string.h>
#include <math.h>


int main (void)
{
	char word[61];
	unsigned long long int sum;
	int count = 0, i, tam;
	count = 1;
	while (!feof(stdin) && scanf("%s", word) == 1)
	{
	    sum = 0;
	    tam = strlen(word);
	    for (i = 0; i < tam; i++)
	    {
	    	if (word[i] == 'b')
	    		sum += (unsigned long long int)pow(2, tam  - i - 1);
	    }
	    printf("Palavra %d\n%llu\n\n", count++, sum);
	}

	return 0;
}