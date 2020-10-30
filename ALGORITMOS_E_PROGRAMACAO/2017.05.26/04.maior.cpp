#include <iostream>
#include <locale>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int maior, pos, vet[8];
    for (int i = 0; i < 8; i++)
    {
        cout << "Digite o valor do " << i+1 << "º valor\n";
        cin >> vet[i];
        if (i == 0)
        {
            maior = vet[i];
            pos = i;
        }
        if(vet[i]> maior)
        {
            maior = vet [i];
            pos = i;
        }
    }
    cout << "Maior = " << maior << endl;
    return 0;
}
