#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>

struct node
{
    void *pData;
    struct node *pNext;
    struct node *pPrevious;
};

typedef struct list
{
    struct node *pFirst;
    struct node *pLast;
    int size;
} TList;

void push_front();
void pop_front();
void push_back();
void pop_back();
void erase();
void clear();

#endif // LIST_H
