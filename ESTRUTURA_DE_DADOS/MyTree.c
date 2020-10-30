#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct  Dados
{
    char Name;
};

typedef struct No
{
    struct Dados Data;
    struct No *pLeft;
    struct No *pRight;
} No;

void cleanBuffer(void)
{
    char c;
    while((c = getchar()) != '\n' && c != EOF);
}

char ReadInfo()
{
    char N;
    printf("\nDigite o nome da Subarvore: ");
    cleanBuffer();
    scanf("%c", &N);
    return N;
}

No *CreateTree(No *pTree)
{

    char n;
    n = ReadInfo();
    if(n == '*')
        pTree = NULL;
    else
    {
        pTree = malloc(sizeof(*pTree));
        if(pTree == NULL)
            exit(1);
        pTree->Data.Name = n;
        pTree->pLeft = CreateTree(pTree);
        pTree->pRight = CreateTree(pTree);
    }
    return pTree;
}

void PreFixado(No *pTree)
{
    if(pTree != NULL)
    {
        printf("\n%c",pTree->Data.Name);
        PreFixado(pTree->pLeft);
        PreFixado(pTree->pRight);
    }
}

void PosFixado(No *pTree)
{
    if(pTree != NULL)
    {
        PosFixado(pTree->pLeft);
        PosFixado(pTree->pRight);
        printf("\n%c",pTree->Data.Name);
    }
}

void Central(No *pTree)
{
    if(pTree != NULL)
    {
        PosFixado(pTree->pLeft);
        printf("\n%c",pTree->Data.Name);
        PosFixado(pTree->pRight);
    }
}

No *RemoveTree(No *pTree)
{
    if(pTree != NULL)
    {
        PosFixado(pTree->pLeft);
        PosFixado(pTree->pRight);
        free(pTree);
    }
    pTree = NULL;
    return pTree;
}
/************************************************************************************/
void NewSubTree(No *pTree, char Dad, char pos)
{
    if (pTree != NULL)
    {
        if(pTree->Data.Name == Dad)
        {
            if (pos == 'L' && pTree->pLeft == NULL)
                pTree->pLeft = CreateTree(pTree->pLeft);
            if (pos == 'R' && pTree->pRight == NULL)
                pTree->pRight = CreateTree(pTree->pRight);
        }
        NewSubTree(pTree->pLeft, Dad, pos);
        NewSubTree(pTree->pRight, Dad, pos);
    }
}




void RemoveSubTree(No *pTree, char Rem)
{
    if (pTree != NULL)
    {
        if(pTree->Data.Name == Rem)
            RemoveTree(pTree);
        RemoveSubTree(pTree->pLeft, Rem);
        RemoveSubTree(pTree->pRight, Rem);
    }
}


No *NewLeaf(No *pTree, char Dad, char pos)
{
    if(pTree != NULL)
    {
        if(pTree->Data.Name == Dad)
        {
            if (pos == 'L' && pTree->pLeft == NULL)
            {
                pTree->pRight = malloc(sizeof(*pTree));
                if (pTree->pLeft == NULL)
                    exit(1);
                pTree->pLeft->Data.Name = ReadInfo();
                pTree->pLeft->pLeft = NULL;
                pTree->pLeft->pRight = NULL;
            }

            if (pos == 'R' && pTree->pRight == NULL)
            {
                pTree->pRight = malloc(sizeof(*pTree));
                if (pTree->pRight == NULL)
                    exit(1);
                pTree->pRight->Data.Name = ReadInfo();
                pTree->pRight->pLeft = NULL;
                pTree->pRight->pRight = NULL;
            }
        }
        pTree->pLeft = NewLeaf(pTree->pLeft, Dad, pos);
        pTree->pRight = NewLeaf(pTree->pRight, Dad, pos);
    }
    return pTree;
}


int main(void)
{
    No *pTree = NULL;
    char pos, Dad;
    setlocale(LC_ALL, "Portuguese");
    int op;
    do
    {
        printf("\nEscolha uma opção\n 1: Criar Arvore\n 2: Mostrar Pré fixado\n 3: Mostrar Pós Fixado\n 4: Centro\n 5: Destruir Arvore\n 6: Nova Subarvore\n 7: Remover Subarvoren 8: Sair\n");
        scanf("%d", &op);
        switch (op)
        {
            case 1:
            pTree = CreateTree(pTree);
            break;
            case 2:
            PreFixado(pTree);
            break;
            case 3:
            PosFixado(pTree);
            break;
            case 4:
            Central(pTree);
            break;
            case 5:
            pTree = RemoveTree(pTree);
            break;
            case 6: 
            {
                printf("\n Digite a Subarvore Pai: ");
                cleanBuffer();
                scanf("%c", &Dad);
                printf(" Digite a posição na Subarvore: ");
                cleanBuffer();
                scanf("%c", &pos);
                NewSubTree(pTree, Dad, pos);
            }break;
            case 7:
            {

            }break;
        }
    }
    while(op != 8);
    pTree =  RemoveTree(pTree);
    ;    return 0;
}
