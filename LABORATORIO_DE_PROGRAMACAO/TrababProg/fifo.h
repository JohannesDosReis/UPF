#ifndef FIFO_H
#define FIFO_H

#include "buffer.h"

struct TFifo
{

	int FifoAmount;
	struct TElement *pInsert;
	struct TElement *pRemove;
	struct TBuffer *pBuffer;
};

void Ffo(struct TFifo *pFifo, struct TBuffer *pBuff);
char FfoAdd(struct TFifo *pFifo, void *pData);
char FfoGet(struct TFifo *pFifo, void *pData);
void FfoClear(struct TFifo *pFifo);

#endif // FIFO_H
