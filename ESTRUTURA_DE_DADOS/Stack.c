#include <stdio.h>
#include <stdlib.h>

#define NoMemory 1

struct Dados
{
	char name[30];
	int age;
};

typedef struct Noh
{
	struct Dados data;
	struct Noh *pNext;
}Noh;

void cleanBuffer(void)
{
	char c;
	while((c = getchar()) != '\n' && c != EOF);
}
void ReadInfo(Noh *pNew)
{
	printf("\nDigite o nome: ");
	cleanBuffer();
	gets(pNew->data.name);
	printf("Digite a idade: ");
	scanf("%d", &pNew->data.age);
	pNew->pNext = NULL;
}

Noh *StackUp(Noh *pStack)
{
	Noh *pNew = NULL;
	pNew = malloc(sizeof(*pNew));
	if(pNew == NULL)
		exit(NoMemory);
	ReadInfo(pNew);
	if(pStack == NULL)
		return pNew;
	Noh *pSearch = pStack;
	while(pSearch->pNext != NULL)
		pSearch = pSearch->pNext;
	pSearch->pNext = pNew;
	return pStack;
}

Noh *UnPack(Noh *pStack)
{
	if(pStack == NULL)
		return NULL;
	if(pStack->pNext == NULL)
	{
		free(pStack);
		return NULL;
	}
	Noh *pSearch = pStack;
	while(pSearch->pNext->pNext != NULL)
		pSearch = pSearch->pNext;
	free(pSearch->pNext);
	pSearch->pNext = NULL;
	return pStack;
}

void ShowStack(Noh *pStack)
{
	if(pStack != NULL)
	{
		ShowStack(pStack->pNext);
		printf("%30s %2d\n", pStack->data.name, pStack->data.age);
	}
}

int main(void)
{
	Noh *pStack = NULL;
	int op;
	do
	{
		printf("\n Escolha uma opcao\n 1: Empilhar\n 2: Desempilhar\n 3: Limpar Pilha\n 4: Mostrar Pilha\n 5: Sair\n");
		scanf("%d", &op);
		switch (op)
		{
			case 1: pStack = StackUp(pStack);
			break;
			case 2: pStack = UnPack(pStack);
			break;
			case 3: while(pStack != NULL) pStack = UnPack(pStack);
			break;
			case 4: if(pStack == NULL) printf("\nLista Vazia\n"); else ShowStack(pStack);
			break;
		}
	} while (op != 5);
	if (pStack != NULL) while(pStack != NULL) pStack = UnPack(pStack);
	return 0;

}