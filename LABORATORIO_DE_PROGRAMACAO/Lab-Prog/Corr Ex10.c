#include <stdio.h>

void CreateOutputFileName(char *RdName, char *WrName)
{
    // copy until there is a dot or string is over
    while(*RdName && *RdName != '.')
    {
        // copy file name
        *WrName = *RdName;

        WrName++;
        RdName++;
    }

    // append '-split' to file name
    strcpy(WrName, "-split");
    WrName += 6;

    while(*RdName)
    {
        // copy file name
        *WrName = *RdName;

        WrName++;
        RdName++;
    }

    // finish string
    *WrName = 0;
}

int main(int ArgC, char *ArgV[])
{
    char FileName[100];
    char OutputName[100];
    char NewLine = 0;
    char c;

    // tipo ARQUIVO para usar
    FILE *pFileRd;
    FILE *pFileWr;

    // escolha do nome
    printf("Escolha o nome do arquivo: ");
    scanf("%s", FileName);

    // open file
    pFileRd = fopen(FileName, "r");
    if(!pFileRd)
    {
        printf("\nArquivo '%s' nao pode ser aberto para leitura!\n\n", FileName);
        exit(1);
    }

    // create output file name
    CreateOutputFileName(FileName, OutputName);
    printf("Arquivo '%s' sera utilizado como saida!\n\n", OutputName);

    // open file
    pFileWr = fopen(OutputName, "w");
    if(!pFileWr)
    {
        fclose(pFileRd);
        printf("\nArquivo '%s' nao pode ser aberto para escrita!\n\n", OutputName);
        exit(2);
    }

    // read a single char
    c = fgetc(pFileRd);
    while(!feof(pFileRd))
    {
        if(isalnum(c))
        {
            // copy
            fputc(c, pFileWr);
            NewLine = 1;
        }
        else
        {
            // not alphanumeric, next line...
            if(NewLine)
            {
                // next
                fputc('\n', pFileWr);

                // no multiple new lines
                NewLine = 0;
            }
        }

        // read next
        c = fgetc(pFileRd);
    }

    fclose(pFileRd);
    fclose(pFileWr);
    getchar();

    return(0);
}


