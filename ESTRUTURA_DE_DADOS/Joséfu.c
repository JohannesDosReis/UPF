#include <stdio.h>
#include <conio.h>
#include <locale.h>

typedef struct Soldado
{
	int pos;
	struct Soldado  *pNext;
}Soldado;

int main(void)
{
	setlocale(LC_ALL, "Portuguese");
	Soldado *pCircle = NULL, *pNew = NULL, *pSearh = NULL, *pDel = NULL;
	int i, length, dead;
	printf("\nDigite quantos soldados est�o na roda: ");
	scanf("%d", &length);
	for (i = 0; i < length; i++)
	{
		pSearh = pCircle;
		pNew   = (Soldado*)malloc(sizeof(pNew));
		if (pNew == NULL)
		{
			printf("\nSem mem�ria!");
			exit(1);
		}
		pNew->pos = i + 1;
		pNew->pNext = NULL;
		if (pCircle == NULL)
		{
			pCircle = pNew;
		}
		else
		{
			while (pSearh->pNext != NULL)
			{
				pSearh = pSearh->pNext;
			}
			pSearh->pNext = pNew;
		}
	}
	pSearh = pNew;
	pSearh->pNext = pCircle;
	printf("\nDigite de quantos em quantos os soldados morrem: ");
	scanf("%d", &dead);
	while (pSearh->pNext != pSearh)
	{
		for (i = 1; i < dead; i++)
		{
			pSearh = pSearh->pNext;
		}
		pDel          = pSearh->pNext;
		pSearh->pNext = pSearh->pNext->pNext;
		free(pDel);
	}
	printf("\n A posi��o a salvo �: %d\n", pSearh->pos);
	free(pSearh);
	return 0;
}
