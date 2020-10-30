#ifndef LIST_H
#define LIST_H

#include "buffer.h"

typedef char *pFunction(void *, void *);


struct TList
{
	int ListAmount;
	struct TElement *pFirst;
	struct TElement *pLast;
	struct TBuffer *pBuffer;
};

void Lst(struct TList *pList, struct TBuffer *pBuff);
char LstAdd(struct TList *pList, char Flags, ...);
char LstAddIdx(struct TList *pList, int Idx, char Flags, ...);
char LstGet(struct TList *pList, int Idx, void *pData);
char LstDel(struct TList *pList, int Idx);
void LstClear(struct TList *pList);
int LstSize(struct TList *pList);
int LstFind(struct TList *pList, void *pData, pFunction fComp);

#endif // LIST_H
