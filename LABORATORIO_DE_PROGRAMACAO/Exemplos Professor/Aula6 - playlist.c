#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * Estrutura de uma musica
 */
struct Song
{
    char Title[100];    // nome da musica
    char Artist[50];    // artista
    unsigned int Time;  // tempo da musica (segundos)
};

/*
 * Estrutura de um elemento da lista (nó ou node)
 */
struct Node
{
    struct Node *pProx;     // proximo da lista
    struct Song Item;       // valor armazenado na lista
};

/*
 * Estrutura de uma lista completa
 */
struct List
{
    struct Node *pFirst;    // primeiro elemento da lista
    unsigned int Size;      // total de musicas na lista
    unsigned int TotalTime; // tempo total de execução da lista
    char Name[30];          // nome da playlist
};

struct List *LstNew(char *Name);        // cria uma nova lista
void LstClear(struct List *pList);      // apaga todos os elementos
void LstDestroy(struct List *pList);    // destroi toda a lista
void LstDisplay(struct List *pList);    // esibe toda a lista na tela

void ReadSong(struct Song *pSong);      // obtem as informacoes de uma musica
void DisplaySong(struct Song *pSong);   // escreve na tela as informacoes de uma musica

void SongNew(struct List *pList);
void SongAdd(struct List *pList, struct Node *pNode);
void SongNewLiteral(struct List *pList, char *Title, char *Artist, int Time);
void SongRemove(struct List *pList, int Index);


/*
 * main
 */
int main(void)
{
    // global playlist
    struct List *MyList;

    // cria a lista
    MyList = LstNew("Best of MetallicA");

    // adiciona 3 musicas na lista
    //SongNew(MyList);
    //SongNew(MyList);
    //SongNew(MyList);
    SongNewLiteral(MyList, "The day that never comes", "Metallica", 6*50+33);
    SongNewLiteral(MyList, "One", "Metallica", 8*60+19);
    SongNewLiteral(MyList, "Despacito", "Modinhas", 3*60+10);
    SongNewLiteral(MyList, "Blackened", "Metallica", 6*60+52);

    // exibe os 3 elementos
    LstDisplay(MyList);

    // remove a 'despacito';
    SongRemove(MyList, 2);

    // adiciona mais um
    //SongNew(MyList);
    SongNewLiteral(MyList, "Fade to Black", "Metallica", 6*60+21);
    SongNewLiteral(MyList, "The outlaw torn", "Metallica", 11*60+29);

    // exibe
    LstDisplay(MyList);

    // limpa tudo
    LstClear(MyList);

    // exibe
    LstDisplay(MyList);

    return(0);
}

/*
 * Faz a leitura dos dados da estrutura
 */
void SongNew(struct List *pList)
{
    struct Node *New;

    // cria um elemento da lista
    New = malloc(sizeof(struct Node));

    // nao possui nenhum elemento como proximo
    New->pProx = NULL;

    // faz a leitura dos dados
    ReadSong(&New->Item);

    // adiciona este novo elemento na lista
    SongAdd(pList, New);
}

/*
 * Faz a leitura dos dados da estrutura
 */
void SongAdd(struct List *pList, struct Node *pNode)
{
    // armazena um elemento da lista
    struct Node *pSearch;

    // primeiro elemento da lista?
    if(pList->pFirst == NULL)
    {
        // o primeiro passa a ser este novo elemento
        pList->pFirst = pNode;

        // temos um unico elemento
        pList->Size         = 1;
        pList->TotalTime    = pNode->Item.Time;
    }
    else
    {
        // primeiro
        pSearch = pList->pFirst;

        // procura o ultimo
        while(pSearch->pProx != NULL)
        {
            // proximo
            pSearch = pSearch->pProx;
        }

        // o proximo depois do ultimo vira o ultimo
        pSearch->pProx = pNode;
        pNode->pProx   = NULL;

        // atualiza os demais parametros da lista
        pList->Size         = pList->Size + 1;
        pList->TotalTime    = pList->TotalTime + pNode->Item.Time;
    }

}

/*
 * Adiciona uma entrada na lista de forma literal
 */
void SongNewLiteral(struct List *pList, char *Title, char *Artist, int Time)
{
    struct Node *New;

    // cria um elemento da lista
    New = malloc(sizeof(struct Node));

    // nao possui nenhum elemento como proximo
    New->pProx = NULL;

    // faz a leitura dos dados
    //ReadSong(&New->Item);
    strcpy(New->Item.Artist, Artist);
    strcpy(New->Item.Title, Title);
    New->Item.Time = Time;

    // adiciona este novo elemento na lista
    SongAdd(pList, New);
}

/*
 * Remove um elemento da lista, de acordo com sua posicao
 */
void SongRemove(struct List *pList, int Index)
{
    struct Node *pDel;
    struct Node *pSearch;

    // inicialmente nao foi encontrado ninguem a remover
    pDel = NULL;

    // é o primeiro da lista?
    if(Index == 0)
    {
        // existe ao menos o primeiro?
        if(pList->pFirst != NULL)
        {
            // o item a deletar é o primeiro da lista
            pDel = pList->pFirst;

            // entao, existe um elemento.
            // O primeiro da lista passa a ser o proximo do que era o primeiro
            pList->pFirst = pList->pFirst->pProx;
        }
    }
    else
    {
        // desconsidera um elemento
        Index--;

        // primeiro elemento da lista
        pSearch = pList->pFirst;

        while(Index && pSearch->pProx != NULL)
        {
            // proximo
            pSearch = pSearch->pProx;

            // conta mais um que foi percorrido
            Index--;
        }

        // encontramos o alvo?
        if(pSearch->pProx != NULL)
        {
            // o item a ser removido é o proximo do que achamos
            pDel = pSearch->pProx;

            // isolamos o elemento que vamos remover
            pSearch->pProx = pSearch->pProx->pProx;
        }

    }

    // se existe ponteiro a ser excluido, entao apaga
    if(pDel)
    {
        // atualza as informacoes da lista
        pList->Size      = pList->Size - 1;
        pList->TotalTime = pList->TotalTime - pDel->Item.Time;

        // elimina o elemento a ser removido
        free(pDel);
    }
}

/*
 * Faz a leitura dos dados da estrutura
 */
void ReadSong(struct Song *pSong)
{
    int M, S;

    // digite o seu nome
    fflush(stdin);
    printf("Type song name: ");
    gets(pSong->Title);
    printf("Who sing it   : ");
    gets(pSong->Artist);
    printf("Song lenght   : ");
    scanf("%d:%d", &M, &S);


    // converte de Min/Seg para Seg
    pSong->Time = M*60 + S;
}

/*
 * Escreve na tela uma informação
 */
void DisplaySong(struct Song *pSong)
{
    int M, S;

    M = pSong->Time/60;
    S = pSong->Time%60;

    printf("Artist: %s\n", pSong->Artist);
    printf("Title : %s\n", pSong->Title);
    printf("Lenght: %02d:%02d\n\n", M, S);
}



/*
 * cria uma nova lista
 */
struct List *LstNew(char *Name)
{
    struct List *New;

    // cria uma estrutura em memoria do tamanho da estrutura lista
    New = malloc(sizeof(struct List));

    // copia o nome
    strcpy(New->Name, Name);

    // inicializa os demais valores sem nada
    New->pFirst     = NULL;
    New->Size       = 0;
    New->TotalTime  = 0;
}

/*
 * Fapaga todos os elementos
 */
void LstClear(struct List *pList)
{
    struct Node *pDel;

    // enquanto houver elementos...
    while(pList->pFirst != NULL)
    {
        // salva o item a remover
        pDel = pList->pFirst;

        // o proximo passa a ser o primeiro da lista
        pList->pFirst = pDel->pProx;

        // elimina o nodo
        free(pDel);
    }

    // zera o metadados
    pList->Size      = 0;
    pList->TotalTime = 0;

}

/*
 * destroi toda a lista
 */
void LstDestroy(struct List *pList)
{
    // aborta se nao existe nem o ponteiro da lista
    if(pList == NULL) return;

    // se ainda existe elementos, apaga tudo!
    if(pList->pFirst != NULL)
    {
        // apaga todos eles antes de destruir a lsita
        LstClear(pList);
    }

    // destroi a lista
    free(pList);
}

/*
 * Exibe toda a lista na tela
 */
void LstDisplay(struct List *pList)
{
    int n, M, S;
    struct Node *pNode;

    // primeiro elemento da lista
    pNode = pList->pFirst;

    // escreve uma linha tracejada na tela
    printf("\nCurrent list: %s\n", pList->Name);
    printf("========================================\n");

    // percorre até chegar no final da lista
    while(pNode != NULL)
    {
        DisplaySong(&pNode->Item);
        putchar('\n');

        // proximo
        pNode = pNode->pProx;
    }

    // escreve outra linha tracejada na tela
    printf("========================================\n");
    n = printf("Total %d songs", pList->Size);
    while(n < 34) { putchar(' '); n++; }
    M = pList->TotalTime / 60;
    S = pList->TotalTime % 60;
    printf("%3d:%02d\n", M, S);
}


