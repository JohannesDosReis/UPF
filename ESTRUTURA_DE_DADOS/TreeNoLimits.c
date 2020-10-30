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

No *CreateTree(No *pTree)
{

    char n;
    printf("Digite o nome da Subarvore: ");
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

int main(void)
{
    No *pTree = NULL;
    setlocale(LC_ALL,"Portuguese");
    int op;
    do
    {
        printf("\nEscolha uma opção\n 1: Construir Arvore\n 2: Mostrar Pré fixado\n 3: Mostrar Pós Fixado\n 4: Centro\n 5: Destruir Arvore\n 6: Sair\n");
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
