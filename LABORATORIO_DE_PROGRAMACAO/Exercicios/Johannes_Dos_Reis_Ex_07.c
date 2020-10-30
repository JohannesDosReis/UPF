#include <stdio.h>
#include <string.h>

int main()
{
	int size;
	char vector[71], l, i;
	do
	{
		printf("Digite uma palavra entre 30 e 70 letras: ");
		gets(vector);
		size = strlen(vector);
	}while(size < 30 || size > 70);
	for (i = 0; i < size; ++i)
		vector[i] = toupper(vector[i]);
	printf("Digite a letra a encontrar:");
	l = toupper(getch());
	printf("\n%s\n", vector);
	for (i = 0; i < size; ++i)
	{
		if(vector[i] == l)
			printf("%c", 30);
		else
			printf(" ");
	}
	return 0;
}