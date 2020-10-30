#include <stdio.h>
#include <string.h>

// ESTRUTURAS
// utiliza 'struct <nome>' para definir uma estrutura
// dentro da estrutura sao colocados os campos que ela representa
// Os campos sao acessados via . quando variavel, e -> quando ponteiro
// Exemplo:
// struct TAviao Aviao;     Aviao.Spd = 415;
// struct TAviao *pAviao;   pAviao->Spd = 415;

// PONTEIROS
// Sao uma referencia para qualquer variavel.
// Mantem na memoria um indicativo de onde está a variavel original
//      (em vez de fazer uma copia)
// Sao declaradas com um * antes.
// int A;       // variavel inteira
// int *p;      // ponteiro para uma variavel inteira;
// p = &A;      // ponteiro 'p' armazena o local onde está a variavel 'A';
// *p = 15;     // modifica a variavel indicada por 'p', no caso, 'A';
// printf("%d", A) resulta no valor 15 na tela


/*
 * Estrutura de dados que define um aviao
 */
struct TAviao
{
    char Call[10];
    char Acft[10];
    int FL;
    int Spd;
};

/*
 * Escreve na tela um aviao
 */
void MostraAviao(char Call[], char Acft[], int FL, int Spd)
{
    printf("\\\n");
    printf(" | CALL: %s\n", Call);
    printf(" | ACFT: %s\n", Acft);
    printf(" | FL%3d %3dKT\n", FL, Spd);
}

/*
 * Escreve na tela um aviao, utilizando ponteiros
 */
void MostraAviaoPont(struct TAviao *pAviao)
{
    printf("\\\n");
    printf(" | CALL: %s\n", pAviao->Call);
    printf(" | ACFT: %s\n", pAviao->Acft);
    printf(" | FL%3d %3dKT\n", pAviao->FL, pAviao->Spd);
}

/*
 * main
 */
int main(void)
{
    // variavel 'Aviao' do tipo 'TAviao' que eh uma estrutura (struct)
    struct TAviao Aviao;

    // preenche uma estrutura
    strcpy(Aviao.Call, "AZU4200");
    strcpy(Aviao.Acft, "E195");
    Aviao.FL  = 350;
    Aviao.Spd = 415;

    // escreve na tela, item por item
    MostraAviao(Aviao.Call, Aviao.Acft, Aviao.FL, Aviao.Spd);
    printf("-----------------------\n");

    // escreve na tela, usando o ponteiro para a variavel Aviao
    MostraAviaoPont(&Aviao);

    return(0);
}
