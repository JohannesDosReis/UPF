#include <stdio.h>

typedef struct pCabron
{
    char Nome[32];
    int Mat;
    struct pCabron *pNext;
}StCabron;

typedef struct
{
    StCabron *pInicio;
    StCabron *pFim;
    int Total;
}StLista;

/****************************************************/
void Read(StCabron *pCab)
{
    printf("Digite o nome: ");
    scanf("%s", pCab->Nome);
    printf("Digite a matricula: ");
    scanf("%d", &pCab->Mat);
}

/****************************************************/
void Display(StCabron *pCab)
{
    printf("%06d %s\n", pCab->Mat, pCab->Nome);
}

/****************************************************/
void ExibeLista(StCabron *pPrimeiro)
{
    while(pPrimeiro != NULL)
    {
        // escreve o conteudo na tela
        Display(pPrimeiro);

        // proximo item!
        pPrimeiro = pPrimeiro->pNext;
    }
}

/****************************************************/
void DestroiLista(StCabron *pPrimeiro)
{
    StCabron *pTemp;
    while(pPrimeiro != NULL)
    {
        // salva variavel temporaria
        pTemp = pPrimeiro;

        // proximo item!
        pPrimeiro = pPrimeiro->pNext;

        // excluir o temporario
        free(pTemp);
    }
}

/****************************************************/
StCabron* InserePrimeiro(StCabron *pLista)
{
    StCabron *pNovo;

    // cria o novo objeto
    pNovo = malloc(sizeof(StCabron));

    // o proximo é o primeiro da lista (propria lista)
    pNovo->pNext = pLista;

    // obtem os dados do item
    Read(pNovo);

    // a lista agora aponta para o novo primeiro item
    return(pNovo);
}

/****************************************************/
StCabron* InsereFinal(StCabron *pLista)
{
    StCabron *pFinal;

    // se a lista ta vazia
    if(pLista == NULL)
    {
        // cria o primeiro item
        pLista = malloc(sizeof(StCabron));
        pFinal = pLista;
    }
    else
    {
        // aponta para o primeiro item da lista
        pFinal = pLista;
        while(pFinal->pNext != NULL)
        {
            pFinal = pFinal->pNext;
        }

        // cria o ultimo item
        pFinal->pNext = malloc(sizeof(StCabron));
        pFinal = pFinal->pNext;
    }

    // preenche o ultimo
    Read(pFinal);

    // e nao existe o proximo depois do ultimo
    pFinal->pNext = NULL;

    // retorna o ponteiro inicial da lista
    return(pLista);
}


/****************************************************/
int main(void)
{
    char c;
    StCabron *pTurma; // lista Turma!

    // inicializa a lista vazia
    pTurma = NULL;

    printf("Deseja inserir um aluno? [Y/N]: ");
    scanf("\n%c", &c);
    while(c != 'N' && c != 'n')
    {
        // insere o primeiro item
        pTurma = InserePrimeiro(pTurma);

        printf("Deseja inserir mais um aluno? [Y/N]: ");
        scanf("\n%c", &c);
    }

    // listar os alunos na tela
    ExibeLista(pTurma);



    // destroi a lista criada
    DestroiLista(pTurma);
    pTurma = NULL;
}



