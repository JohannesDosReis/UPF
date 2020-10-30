#include "list.h"



void push_front(TList *pList, void *pItem, size_t data_size)
{
    struct node *pNew = malloc(sizeof(struct node));
    pNew->pData = malloc(data_size);
    memcpy(pNew->pData, pItem, data_size);


    

}
void pop_front();
void push_back();
void pop_back();
void erase();
void clear();
