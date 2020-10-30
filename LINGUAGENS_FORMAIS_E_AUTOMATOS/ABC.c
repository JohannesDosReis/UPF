#include <stdio.h>
#include <string.h>

#define mod 1000000007

unsigned long long int power(unsigned long long base, unsigned long long n, unsigned long long M) 
{
    if (n == 0) return 1;
    if (n == 1) return base;
    unsigned long long int halfn = power(base, n / 2, M);
    if (n % 2 == 0) return ( halfn * halfn ) % M;
    else return ( ( ( halfn * halfn ) % M ) * base ) % M;
}

int main(void)
{
	char sentence[1001];
	int i, length;
	unsigned long long int sum;
	while (!feof(stdin) && scanf("%s", sentence) == 1)
	{
		length = strlen(sentence);
		sum = 0;
		for ( i = 0; i < length; ++i)
		{
			sum +=((sentence[i] - 65) * (power(26, length - 1 - i, mod)));
		}
		printf("%llu\n", sum%mod);
	}
	return 0;
}