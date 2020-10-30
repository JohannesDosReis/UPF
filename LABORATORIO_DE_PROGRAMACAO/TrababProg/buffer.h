#ifndef BUFFER_H
#define BUFFER_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

struct TData
{
	char Name[50];
	int Age;
};

struct TElement
{
	struct TData Info;
	struct TElement *pNext;
	struct TElement *pPrevious;
};

struct TBuffer
{
	struct TElement *pDestroy;
	struct TElement *pFirstFree;
	int FreeAmount;
};


void BufInitialize(struct TBuffer *pBuff, int Size, int Len);
void BufTerminate(struct TBuffer *pBuff);
#endif // BUFFER_H
