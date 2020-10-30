#include <iostream>
using namespace std;

int main()
{
    int a, maior, menor, cont = 1;
    cout << "Digite dez numeros\n";
    cin >> a;
    int antmenor = a;
    int antmaior = a;
    int soma = a;

    for (int i = 0; i < 9; i++)
    {
        cin >> a;
        if (a >= antmaior)
        {
            maior = a;
            antmaior= a;
        }
        if (a <= antmenor)
        {
            menor = a;
            antmenor = a;
        }
        soma = soma + a;
        cont++;
    }
    cout << "Maior: " << maior << endl;
    cout << "Menor: " << menor << endl;
    cout << "Media: " << (double) soma / cont << endl;
    return 0;
}
