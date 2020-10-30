#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int *prime;
int size, i, j, root, primo, count;
void showPrimes()
{
    i=1;
    j=1;
    count = 1;
    do
    {
        for(i = i; (i <= size) && (i <= count*18); i++)
            printf("%03d ", i);
        printf("\n");
        for(j = j; (j <= size) && (j <= count*18); j++)
        {
            if(prime[j])
                printf("  %c ", 30);
            else
                printf("    ");
        }
        count++;
        printf("\n");
    }
    while(i < size);
}
int main()
{
    double ic,fc,in,fn;
    printf("Digite um numero maior que 30 para o limte de numeros primos: ");
    scanf("%d", &size);
    prime = malloc(size * sizeof(prime));
    for(i = 2; i < size; ++i)
        prime[i] = 1;
    root = sqrt(size);
    ic = clock();
    for(i = 2; i <= root; ++i)
    {
        if(prime[i])
        {
            for(j = i*i; j <= size; j = j+i)
                prime[j] = 0;
        }
    }
    prime[j] = '\0';
    fc = clock();
    printf("\nPor Crivo\n");
    showPrimes();
    in = clock();
    for(i = 2; i < size; ++i)
        prime[i] = 1;
    for(i = 2; i <= size; ++i)
    {
        primo = 1;
        for(j = 2; j < i; ++j)
        {
            if(i%j == 0)
                prime[i] = 0;
        }
    }
    fn = clock();
    printf("\n");
    printf("Metodo Normal\n");
    showPrimes();
    printf("\nPor Crivo: %02.6f\nMetodo Normal: %02.6f", fc-ic,fn-in);
    free(prime);
    return 0;
}
