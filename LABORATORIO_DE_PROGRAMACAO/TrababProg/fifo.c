#include "fifo.h"

void Ffo(struct TFifo *pFifo, struct TBuffer *pBuff)
{
	pFifo->pBuffer = pBuff;
	pFifo->pRemove = pFifo->pInsert = NULL;
	pFifo->FifoAmount = 0;
}

char FfoAdd(struct TFifo *pFifo, void *pData)
{
	struct TElement *pAux;
	if (pFifo->pRemove == NULL) pFifo->pInsert = pFifo->pRemove = pFifo->pBuffer->pFirstFree;
	else pFifo->pInsert->pNext = pFifo->pBuffer->pFirstFree;
	pAux = pFifo->pBuffer->pFirstFree;
	if (pAux) pAux->Info = *(struct TData *)pData;
	else return '0';
	if (pFifo->pRemove == NULL)	pFifo->pRemove = pAux;
	pAux->pPrevious = pFifo->pInsert;
	pFifo->pInsert = pAux;
	pFifo->FifoAmount++;
	pFifo->pBuffer->pFirstFree = pFifo->pInsert->pNext;
	pFifo->pInsert->pNext = NULL;
	pFifo->pBuffer->FreeAmount--;
	return '1';
}

char FfoGet(struct TFifo *pFifo, void *pData)
{
	if (pFifo->pRemove)
	{
		struct TElement *pAux = pFifo->pBuffer->pFirstFree;
		pFifo->pBuffer->pFirstFree = pFifo->pRemove;
		pFifo->pRemove = pFifo->pRemove->pNext;
		pFifo->pBuffer->pFirstFree->pNext = pAux;
		pAux->pPrevious = pFifo->pBuffer->pFirstFree;
		if (pFifo->pRemove) pFifo->pRemove->pPrevious = NULL;
		pFifo->pBuffer->FreeAmount++;
		pFifo->FifoAmount--;
	}
	else return '0';
	return '1';
}

void FfoClear(struct TFifo *pFifo)
{
	if (pFifo->pRemove)
	{
		pFifo->pInsert->pNext = pFifo->pBuffer->pFirstFree;
		pFifo->pBuffer->pFirstFree->pPrevious = pFifo->pInsert;
		pFifo->pBuffer->pFirstFree = pFifo->pRemove;
		pFifo->pBuffer->FreeAmount += pFifo->FifoAmount;
		pFifo->FifoAmount = 0;
		pFifo->pInsert = NULL;
		pFifo->pRemove = NULL;
	}
}