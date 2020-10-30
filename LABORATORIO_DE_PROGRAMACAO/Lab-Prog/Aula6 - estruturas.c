#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * Estrutura de uma pessoa
 */
struct Dados
{
    int Idade;
    char Nome[100];
    long long RG;
};

/*
 * Estrutura de um elemento da lista
 */
struct Elemento
{
    struct Elemento *pProx;     // proximo da lista
    struct Elemento *pAnt;      // anterior da lista
    struct Dados Valor;         // valor armazenado na lista
};

void ShowData(struct Dados *pPessoa);
void ReadData(struct Dados *pPessoa);

/*
 * main
 */
int main(void)
{
    struct Dados Pessoa;

    // faz a leitura dos dados
    ReadData(&Pessoa);

    // exibe os dados na tela
    ShowData(&Pessoa);



    return(0);
}

/*
 * Faz a leitura dos dados da estrutura
 */
void ReadData(struct Dados *pPessoa)
{
    // digite o seu nome
    printf("Digite o nome da pessoa: ");
    gets(pPessoa->Nome);
    printf("Digite a idade: ");
    scanf("%d", &pPessoa->Idade);
    printf("Digite o RG ou CPF: ");
    scanf("%lld", &pPessoa->RG);

    // Para acessar os campos via ponteiro usa a ->
    // Como variavel normal, utiliza-se o .
    // Pessoa.Idade
    // pPessoa->Idade
}



/*
 * Faz a leitura da quantidade
 */
void ShowData(struct Dados *pPessoa)
{
    printf("\n======================================\n");
    printf("Nome: %s\n", pPessoa->Nome);
    printf("Idade: %3d RG: %15lld\n", pPessoa->Idade, pPessoa->RG);
    printf("======================================\n\n");

}
