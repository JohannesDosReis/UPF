#include <iostream>
#include <locale>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int a, som = 0, cont = 0;
    do
    {
        cout << "Digite o n�mero\n";
        cin >> a;
        som += a;
        cont++;
        cout << "1 - Mais um n�mero" << endl << "2 - Ver a m�dia e fechar o programa" << endl;
        cin >> a;
        if (a == 2)
        {
            cout << "M�dia: "<< som/cont << endl;
            break;
        }
    }
    while (true);
    return 0;
    }
