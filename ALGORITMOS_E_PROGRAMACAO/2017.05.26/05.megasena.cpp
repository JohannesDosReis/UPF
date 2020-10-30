#include <iostream>
#include <locale>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int apos[6];
    int sorte[6];
    for (int i = 0; i < 6; i++)
    {
        cout << "Digite o " << i + 1 << "º número da aposta: ";
        cin >> apos[i];
        for (int j = 0; j < i; j++)
        {
            if (apos[i] == apos[j])
            {
                cout << "\nNúmero Repetido, digite outro\n";
                i--;
            }
        }
    }
    cout << "\n\nInforme as dezenas sorteadas\n";
    for (int i = 0; i < 6; i++)
    {
        cout << "Digite o " << i + 1 << "º número sorteado: ";
        cin >> sorte[i];
        for (int j = 0; j < i; j++)
        {
            if (sorte[i] == sorte[j])
            {
                cout << "\nNúmero Repetido, digite outro\n";
                i--;
            }
        }
    }
    int cont = 0;
    for (int i = 0; i < 6; i++)
    {
        for(int j = 0; i < 6; i++)
        {
            if (apos[i] == sorte[j])
            {
                cont++;
            }
        }
    }
    cout << "Números acertados: " << cont << endl;
    return cont;
}
