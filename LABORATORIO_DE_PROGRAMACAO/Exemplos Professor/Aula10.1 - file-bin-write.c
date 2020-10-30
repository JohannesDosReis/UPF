#include <stdio.h>


int main(void)
{
    char V1 = 0x04;
    char V2 = 0xFF;
    char V3 = 0xA5;
    char V4 = 0x00;
    int V5  = 0xAABBCCDD;
    char V6[10];

    int i;
    for(i = 0; i < 10; i++) V6[i] = i;

    // tipo ARQUIVO para usar
    FILE *pFile;

    // Abre um arquivo: nome e modo de operação
    // arquivo variables.dat em modo de escrita (write)
    pFile = fopen("variables.dat", "wb");
    if(!pFile) // if(pFile == NULL)
    {
        printf("\nArquivo 'variables.dat' nao pode ser aberto para escrita!\n\n");
        exit(1);
    }

    fwrite(&V1, sizeof(char), 1, pFile);
    fwrite(&V2, sizeof(char), 1, pFile);
    fwrite(&V3, sizeof(char), 1, pFile);
    fwrite(&V4, sizeof(char), 1, pFile);
    fwrite(&V5, sizeof(int),  1, pFile);
    fwrite(V6, sizeof(char), 10, pFile);

    fclose(pFile);
    puts("Done!");
    getchar();

    return(0);
}


