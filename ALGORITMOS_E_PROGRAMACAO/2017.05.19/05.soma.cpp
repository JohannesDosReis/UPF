#include <iostream>
#include <tchar.h>
using namespace std;

int soma(int N)
{
    int soma = 0;
    for (int i = 1; i <= N; i++)
    {
        soma += i;
    }
    return soma;
}

int main ()
{
    int n;
    setlocale(LC_ALL, "Portuguese");
    cout << "Digite um número inteiro e positivo: ";
    cin >> n;
    cout << "Soma dos números inteiros entre 1 e " << n << " é: " << soma(n) << endl;
    return 0;
}
