#include "buffer.h"

void BufInitialize(struct TBuffer *pBuff, int Size, int Len)
{
	int i;
	pBuff->pFirstFree = malloc(Size * Len);
	if (pBuff->pFirstFree == NULL)
	{
		printf("Sem Espaço Suficiente!\n");
		exit(1);
	}
	pBuff->pDestroy = pBuff->pFirstFree;
	pBuff->FreeAmount = Len;
	for (i = 0; i < Len; i++)
	{
		pBuff->pFirstFree[i].pNext = &pBuff->pFirstFree[i + 1];
		pBuff->pFirstFree[i].pPrevious = &pBuff->pFirstFree[i - 1];
	}
	pBuff->pFirstFree[0].pPrevious = NULL;
	pBuff->pFirstFree[Len - 1].pNext = NULL;
}

void BufTerminate(struct TBuffer *pBuff)
{
	free(pBuff->pDestroy);
	pBuff->pFirstFree = NULL;
	pBuff->FreeAmount = 0;
}
