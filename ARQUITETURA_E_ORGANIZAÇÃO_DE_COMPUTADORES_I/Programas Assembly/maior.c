#include <stdio.h>

long long int maior(long long int, long long int);

int main(void) {
    long long int a, b, m;
    printf("Informe um numero: ");
    scanf("%lld", &a);
    printf("Informe outro numero: ");
    scanf("%lld", &b);
    m = maior(a, b);
    printf("Maior: %lld\n", m);
    return 0;
}