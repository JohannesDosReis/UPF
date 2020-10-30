#include <stdio.h>
#include <string.h>

char *readstring(void);

int main(void)
{
    int i, size, j, count;
    char l, temp[50];
    char *strings[6];
    for (i = 0; i < 5; i++)
        strings[i] = readstring();
    printf("\n\nDigite uma letra: ");
    l = getchar();
    for (i = 0; i < 5; ++i)
    {
        size = strlen(strings[i]);
        count = 0;
        for (j = 0; j < size; j++)
        {
            if (*(*(strings+i)+j) == l)
            {
                temp[j] = '^';
                count++;
            }
            else
                temp[j] = ' ';
        }
        temp[j] = '\0';
        printf("[%02d/%02d] >> %s\n",count,size, strings[i]);
        printf("           %s\n", temp);
    }
    for(i  = 0; i < 5; i++)
        free(strings[i]);
    return 0;
}

char* readstring(void)
{
    int size, i, j;
    char *String;
    char temp[50];
    printf("Digite uma frase com no maximo 50 caracteres\n");
    gets(temp);
    size = strlen(temp);
    j = 0;
    for ( i = 0; i < size; ++i)
    {
        if (isalnum(temp[i]) || temp[i] == ' ')
        {
            temp[j++] = temp[i];
        }
    }
    temp[j] = '\0';
    size =  strlen(temp);
    String = malloc((size+1) * sizeof(*String));
    strcpy(String, temp);
    return(String);
}
