#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <Windows.h>

struct Dados
{
    char Name[30];
    int Age;
};

typedef struct Elem
{
    struct Dados data;
    struct Elem *pNext;
} Elem;

Elem *Create(Elem *pQueue);
Elem *Remove(Elem *pQueue);
void Show(Elem *pQueue);
void cleanBuffer();

int main(void)
{
    setlocale(LC_ALL, "Portuguese"); //para nomes com acento
    Elem *pQueue = NULL;
    int op;
    printf("Digite uma opção\n");
    do
    {
        system("cls");
        printf("\n 1: Inserir um Novo Elemento na Fila\n");
        printf(" 2: Remover um Elemento na Fila\n");
        printf(" 3: Mostrar Fila\n");
        printf(" 0: Sair\n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            pQueue = Create(pQueue);
            break;
        case 2:
            pQueue = Remove(pQueue);
            break;
        case 3:
            Show(pQueue);
            break;
        }
    }
    while (op);
    while (pQueue)
    {
        pQueue = Remove(pQueue);
    }
    return 0;
}

Elem *Create(Elem *pQueue)
{
    //criar elemento
    Elem *pNew = NULL;
    Elem *pSearch = pQueue;
    int i;
    pNew = malloc(sizeof(*pNew));
    if (pNew == NULL)
    {
        printf("Sem Memória\n");
        exit(1);
    }
    printf("Digite o nome: ");
    cleanBuffer();
    gets(pNew->data.Name);
    printf("Digite a idade: ");
    scanf("%d", &pNew->data.Age);
    pNew->pNext = NULL;
    //achar ultimo
    if (pSearch == NULL) //fila vazia
    {
        pQueue = pNew;
    }
    else
    {
        while (pSearch->pNext != NULL)
        {
            pSearch = pSearch->pNext;
        }
        pSearch->pNext = pNew;
    }
    return pQueue;
}

Elem *Remove(Elem *pQueue)
{
    Elem *pDel;
    //elimina o primeiro
    if (pQueue == NULL) return;
    if (pQueue->pNext == NULL) //fila com 1 elem
    {
        free(pQueue);
        pQueue = NULL;
    }
    else
    {
        pDel = pQueue;
        pQueue = pQueue->pNext;
        //desaloca a memoria
        free(pDel);
    }
    return pQueue;
}
void Show(Elem *pQueue)
{
    int i = 0;
    CONSOLE_SCREEN_BUFFER_INFO pos;
    Elem *pSearch = pQueue;
    if (pSearch == NULL)
        printf(" Fila Vazia!\n");
    else
    {
        while (pSearch != NULL)
        {
            printf(" %d: Nome: %s", i + 1, pSearch->data.Name);
            GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &pos);
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), (COORD)
            {
                50, pos.dwCursorPosition.Y
            });
            printf(" Idade: %02d\n", pSearch->data.Age);
            pSearch = pSearch->pNext;
            i++;
        }
    }
    getch();
}

void cleanBuffer(void)
{
    char c;
    while((c = getchar()) != '\n' && c != EOF);
}
