#include "list.h"

void Lst(struct TList *pList, struct TBuffer *pBuff)
{
	pList->ListAmount = 0;
	pList->pFirst = pList->pLast = NULL;
	pList->pBuffer = pBuff;
}

char LstAdd(struct TList *pList, char Flags, ...)
{
	int i, length;
	struct TElement *pAux, *pFirstAux;
	if (pList->pLast == NULL) pList->pFirst = pList->pBuffer->pFirstFree;
	else pList->pLast->pNext = pList->pBuffer->pFirstFree;
	pAux = pList->pBuffer->pFirstFree;
	pFirstAux = pAux;
	va_list args;
	va_start(args, Flags);
	if (Flags & 0x80)
	{
		length = Flags &= ~0x80;
		for (i = 0; i < length; i++)
		{
			if (pAux == NULL)
			{
				va_end(args);
				pList->pLast->pNext = NULL;
				return '0';
			}
			pAux->Info = *(struct TData *)va_arg(args, void *);
			if (i != (length - 1)) pAux = pAux->pNext;
		}
		pList->pLast = pAux;
	}
	else
	{
		length = Flags;
		for (i = 0; i < length; i++)
		{
			if (pAux == NULL)
			{
				va_end(args);
				pList->pLast->pNext = NULL;
				return '0';
			}
			pAux->Info = *(struct TData *)va_arg(args, void *);
			if (i != (length - 1)) pAux = pAux->pNext;
		}
		if (pList->pLast == NULL) pList->pLast = pAux;
		else
		{
			pList->pLast->pNext = pAux->pNext;
			pAux->pNext = pList->pFirst;
			pList->pFirst->pPrevious = pAux;
			pList->pFirst = pFirstAux;
			pList->pFirst->pPrevious = NULL;
		}
	}
	va_end(args);
	pList->pBuffer->pFirstFree = pList->pLast->pNext;
	pList->pLast->pNext = NULL;
	pList->pBuffer->FreeAmount -= length;
	pList->ListAmount += length;
	return '1';
}

char LstAddIdx(struct TList *pList, int Idx, char Flags, ...)
{
	int i, length;
	struct TElement *pAux, *pSearch, *pFirstAux;
	if (pList->pLast == NULL) pList->pFirst = pList->pBuffer->pFirstFree;
	else pList->pLast->pNext = pList->pBuffer->pFirstFree;
	pAux = pList->pBuffer->pFirstFree;
	pFirstAux = pAux;
	pSearch = pList->pFirst;
	while (Idx)
	{
		pSearch = pSearch->pNext;
		Idx--;
	}
	va_list args;
	va_start(args, Flags);
	if (Flags & 0x80)
	{
		length = Flags &= ~0x80;
		for (i = 0; i < length; i++)
		{
			if (pAux == NULL)
			{
				va_end(args);
				return '0';
			}
			if (i != (length - 1)) pAux = pAux->pNext;
		}
		if (pList->pLast == NULL || pSearch == pList->pLast) pList->pLast = pAux;
		else
		{
			pList->pLast->pNext = pAux->pNext;
			pAux->pNext = pSearch->pNext;
			pSearch->pNext->pPrevious = pAux;
		}
		for (i = 0; i < length; i++)
		{
			if (pAux == NULL)
			{
				va_end(args);
				return '0';
			}
			pAux->Info = *(struct TData *)va_arg(args, void *);
			if (i != (length - 1)) pAux = pAux->pPrevious;
		}
		if (pSearch != pAux)
		{
			pSearch->pNext = pAux;
			pAux->pPrevious = pSearch;
		}
	}
	else
	{
		length = Flags;
		for (i = 0; i < length; i++)
		{
			if (pAux == NULL)
			{
				va_end(args);
				return '0';
			}
			pAux->Info = *(struct TData *)va_arg(args, void *);
			if (i != (length - 1)) pAux = pAux->pNext;
		}
		if (pSearch == pList->pLast) pList->pLast = pAux;
		pList->pLast->pNext = pAux->pNext;
		if (pList->pLast == NULL) pList->pLast = pAux;
		else
		{
			pList->pLast->pNext = pAux->pNext;
			pAux->pNext = pSearch->pNext;
			pSearch->pNext->pPrevious = pAux;
			pSearch->pNext = pFirstAux;
			pFirstAux->pPrevious = pSearch;
		}
	}
	va_end(args);
	pList->pBuffer->pFirstFree = pList->pLast->pNext;
	pList->pLast->pNext = NULL;
	pList->pBuffer->FreeAmount -= length;
	pList->ListAmount += length;
	return '1';
}

char LstGet(struct TList *pList, int Idx, void *pData)
{
	struct TElement *pSearch = pList->pFirst;
	struct TData *pAux = (struct TData *)pData;
	if (Idx < 0) return '0';
	if (pList->pLast == NULL) return '0';
	while (Idx)
	{
		pSearch = pSearch->pNext;
		if (pSearch == NULL) return '0';
		Idx--;
	}
	*pAux = pSearch->Info;
	return '1';
}

char LstDel(struct TList *pList, int Idx)
{
	struct TElement *pDel = pList->pFirst;
	if (pList->pLast == NULL) return '0';
	if (Idx < 0) return '0';
	while (Idx)
	{
		if (pDel == NULL) return '0';
		pDel = pDel->pNext;
		Idx--;
	}
	if (pDel == NULL) return '0';
	if (pDel == pList->pFirst && pList->pLast)
	{
		LstClear(pList);
		return '1';
	}
	else if (pDel == pList->pFirst)
	{
		pList->pBuffer->pFirstFree->pPrevious = pList->pFirst;
		pList->pBuffer->pFirstFree->pPrevious->pNext = pList->pBuffer->pFirstFree;
		pList->pBuffer = pList->pBuffer->pFirstFree->pPrevious;
		pList->pFirst = pList->pFirst->pNext;
		pList->pFirst->pPrevious = NULL;
	}
	else if (pDel == pList->pLast)
	{
		pList->pBuffer->pFirstFree->pPrevious = pList->pLast;
		pList->pLast->pNext = pList->pBuffer->pFirstFree;
		pList->pBuffer->pFirstFree = pList->pLast;
		pList->pLast = pList->pLast->pPrevious;
		pList->pLast->pNext = NULL;
		return '1';
	}
	else
	{
		pDel->pNext->pPrevious = pDel->pPrevious;
		pDel->pPrevious->pNext = pDel->pNext;
		pDel->pNext = pList->pBuffer->pFirstFree;
		pList->pBuffer->pFirstFree->pPrevious = pDel;
		pList->pBuffer->pFirstFree = pDel;
		pList->pBuffer->pFirstFree->pPrevious = NULL;
	}
	return '1';
}

void LstClear(struct TList *pList)
{
	if (pList->pLast)
	{
		pList->pLast->pNext = pList->pBuffer->pFirstFree;
		pList->pBuffer->pFirstFree->pPrevious = pList->pLast;
		pList->pBuffer->pFirstFree = pList->pFirst;
		pList->pBuffer->FreeAmount += pList->ListAmount;
		pList->pFirst = NULL;
		pList->pLast = NULL;
		pList->ListAmount = 0;
	}
}

int LstSize(struct TList *pList)
{
	int count = 0;
	struct TElement *pSearch = pList->pFirst;
	while (pSearch)
	{
		pSearch = pSearch->pNext;
		count++;
	}
	return count;
}

int LstFind(struct TList *pList, void *pData, pFunction fComp)
{
	int find = 0, i = 0;
	char ret, comp;
	struct TData Item;
	do
	{
		ret = LstGet(pList, i, &Item);
		if (ret == '0') break;
		comp = fComp(&Item.Name, pData);
		if (comp == '=')
		{
			find = i + 1;
			break;
		}
		i++;
	} while (ret == '1');
	return find;
}
