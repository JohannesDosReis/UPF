#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TData
{
	int num;
};

typedef struct Noh
{
	struct TData Info;
	struct Noh * pEsq;
	struct Noh * pDir;
}Noh;

Noh *RemoveTree(Noh *pTree)
{
	if (pTree != NULL)
	{
		RemoveTree(pTree->pEsq);
		RemoveTree(pTree->pDir);
		free(pTree);
	}
	pTree = NULL;
	return pTree;
}

Noh *NewNoh(Noh *pTree, int data)
{
	if (pTree != NULL)
	{
		if (pTree->Info.num > data)
			pTree->pEsq = NewNoh(pTree->pEsq, data);
		else
			pTree->pDir = NewNoh(pTree->pDir, data);
	}
	else
	{
		pTree = malloc(sizeof(*pTree));
		pTree->Info.num = data;
		pTree->pDir = NULL;
		pTree->pEsq = NULL;
	}
	return pTree;
}

Noh* RemoveNoh(Noh* pTree, int v)
{
	if (pTree == NULL)
		return NULL;
	else if (pTree->Info.num > v)
		pTree->pEsq = RemoveNoh(pTree->pEsq, v);
	else if (pTree->Info.num < v)
		pTree->pDir = RemoveNoh(pTree->pDir, v);
	else
	{
		if (pTree->pEsq == NULL && pTree->pDir == NULL)
		{
			free(pTree);
			pTree = NULL;
		}
		else if (pTree->pEsq == NULL)
		{
			Noh* pAux = pTree;
			pTree = pTree->pDir;
			free(pAux);
		}
		else if (pTree->pDir == NULL)
		{
			Noh* pAux = pTree;
			pTree = pTree->pEsq;
			free(pAux);
		}
		else 
		{
			Noh* pAux = pTree->pEsq;
			while (pAux->pDir != NULL)
			{
				pAux = pAux->pDir;
			}
			pTree->Info.num = pAux->Info.num;
			pAux->Info.num = v;
			pTree->pEsq = RemoveNoh(pTree->pEsq, v);
		}
	}
	return pTree;
}

Noh *Search(Noh *pTree, int v)
{
	if (pTree == NULL || pTree->Info.num == v)
		return pTree;
	if (pTree->Info.num > v)
		return Search(pTree->pEsq, v);
	else
		return Search(pTree->pDir, v);
}

void Show(Noh *pTree)
{
	if (pTree != NULL)
	{
		printf("%d\n", pTree->Info.num);
		Show(pTree->pEsq);
		Show(pTree->pDir);
	}
	else
		printf("*\n");
}

int main(void)
{
	int op, num;
	Noh *ret;
	Noh *pTree = NULL;
	do
	{
		printf("Escolha uma opcao\n");
		printf("1: Inserir Nodo\n");
		printf("2: Remover Nodo\n");
		printf("3: Pesquisar Nodo\n");
		printf("4: Destruir Arvore\n");
		printf("5: Mostrar Arvore\n");
		printf("0: Sair\n");
		scanf("%d", &op);
		switch (op)
		{
		case 1:
		{
			printf("Digite um Numero: ");
			scanf("%d", &num);
			pTree = NewNoh(pTree, num);
		}
		break;
		case 2:
		{
			printf("Digite qual Numero deseja remover: ");
			scanf("%d", &num);
			pTree = RemoveNoh(pTree, num);
		}
		break;
		case 3:
		{
			printf("Digite qual numero deseja pesquiar: ");
			scanf("%d", &num);
			ret = Search(pTree, num);
			if (ret)
				printf("\nO elemento esta na lista\n\n");
			else
				printf("\nO elemento nao esta na lista\n");
		}
			break;
		case 4: pTree = RemoveTree(pTree);
			break;
		case 5:
		{
			printf("\n");
			Show(pTree);
			printf("\n");
		}break;
		}
	} while (op);
	RemoveTree(pTree);
	return 0;
}