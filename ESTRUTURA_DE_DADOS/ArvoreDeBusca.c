#include <stdio.h>
#include <stdlib.h>

struct Info
{
    char Name;
};

typedef struct Noh
{
    struct Info Data;
    struct Noh *pLeft;
    struct Noh *pRight;
}Noh;

void cleanBuffer(void)
{
    char c;
    while((c = getchar()) != '\n' && c != EOF);
}

Noh *NewNoh(Noh *pTree, char n)
{
    if(pTree != NULL)
    {
        if(n < pTree->Data.Name)
            pTree->pLeft = NewNoh(pTree->pLeft, n);
        else
            pTree->pRight = NewNoh(pTree->pRight, n);
    }
    else
    {
        pTree = malloc(sizeof(*pTree));
        pTree->Data.Name = n;
        pTree->pLeft = NULL;
        pTree->pRight = NULL;
        return pTree; 
    }
}

Noh *RemoveTree(Noh *pTree)
{
    if(pTree != NULL)
    {
        RemoveTree(pTree->pLeft);
        RemoveTree(pTree->pRight);
        free(pTree);
    }
    pTree = NULL;
    return pTree;
}
Noh *RemoveNoh(Noh *pTree, char n)
{
    if(pTree != NULL)
    {
        if(pTree->Data.Name != n)
        {
            if(n < pTree->Data.Name)
                pTree->pLeft = NewNoh(pTree->pLeft, n);
            else
                pTree->pRight = NewNoh(pTree->pRight, n);
        }
        else
        {
            pTree->pLeft = RemoveTree(pTree->pLeft);
            pTree->pLeft = RemoveTree(pTree->pRight);
            free(pTree);
        }
    }
    return pTree;
}



void Show(Noh *pTree)
{
    if(pTree != NULL)
    {
        printf("\n%c",pTree->Data.Name);
        Show(pTree->pLeft);
        Show(pTree->pRight);
    }
}

void Check(Noh *pTree, char n)
{
    if(pTree != NULL)
    {
        if(pTree->Data.Name != n)
        {
            if(n < pTree->Data.Name)
                pTree->pLeft = NewNoh(pTree->pLeft, n);
            else
                pTree->pRight = NewNoh(pTree->pRight, n);
        }
        else
        {
            printf("O elemento esta na arvore\n");
            return;
        }
    }
}

int main(void)
{
    Noh *pTree = NULL;
    int op;
    char temp;
    do
    {
        printf("\n\nEscolha uma opcao\n");
        printf(" 1: Nova Folha\n");
        printf(" 2: Remover Folha\n");
        printf(" 3: Destruir Arvore\n");
        printf(" 4: Mostar Arvore\n");
        printf(" 5: verificar se um elemento esta na arvore\n");
        printf(" 0: Sair\n");
        scanf("%d",&op);
        system("cls");
        switch (op)
        {
            case 1:
            {
                printf("Digite o nome da Subarvore\n");
                cleanBuffer();
                scanf("%c",&temp);
                pTree = NewNoh(pTree, temp);
            } 

            break;
            case 2: 
            {
                printf("Digite qual Elemento deseja remover: ");
                cleanBuffer();
                scanf("%c", &temp);
                pTree = RemoveNoh(pTree, temp);
            }break;
            case 3: pTree = RemoveTree(pTree);
            break;
            case 4: Show(pTree);
            break;
            case 5:
            {
                printf("Digite qual Elemento deseja Verificar: ");
                cleanBuffer();
                scanf("%c", &temp);
                Check(pTree, temp);
            }
            default: 10;
            break;
        }
    } while (op);
    if (pTree)
    {
        pTree = RemoveTree(pTree);
    }
    return 0;
}