#include <stdio.h>
#include <stdlib.h>

struct  Dados
{
    char Name;
};

typedef struct Noh
{
    struct Dados Data;
    struct Noh *pLeft;
    struct Noh *pRight;
} Noh;

void cleanBuffer(void)
{
    char c;
    while((c = getchar()) != '\n' && c != EOF);
}

Noh *CreateTree(Noh *pTree)
{

    char n;
    printf("Digite o nohme da Subarvore: ");
    cleanBuffer();
    scanf("%c", &n);
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

void PreFixado(Noh *pTree)
{
    if(pTree != NULL)
    {
        printf("\n%c",pTree->Data.Name);
        PreFixado(pTree->pLeft);
        PreFixado(pTree->pRight);
    }
}

void PosFixado(Noh *pTree)
{
    if(pTree != NULL)
    {
        PosFixado(pTree->pLeft);
        PosFixado(pTree->pRight);
        printf("\n%c",pTree->Data.Name);
    }
}

void Central(Noh *pTree)
{
    if(pTree != NULL)
    {
        Central(pTree->pLeft);
        printf("\n%c",pTree->Data.Name);
        Central(pTree->pRight);
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

int main(void)
{
    Noh *pTree = NULL;
    int op;
    do
    {
        printf("\nEscolha uma opcao\n 1: Construir Arvore\n 2: Mostrar Pre fixado\n 3: Mostrar Pos Fixado\n 4: Centro\n 5: Destruir Arvore\n 6: Sair\n");
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
        }
    }
    while(op != 6);
    pTree =  RemoveTree(pTree);
;    return 0;
}
