#include <iostream>
#include <locale>
using namespace std;

int main ()
{
    int cont = 0, a;
    setlocale(LC_ALL, "Portuguese");
    do
    {
        cout << "Digite um n�mero\n";
        cin >> a;
        if(a==0)
        {
            cout << "N�mero zero informado, digite outro valor\n";
        }
        else if (a<0)
        {
            cout << "O n�mero � positivo\n";
            cont++;
        }
        else
        {
            cout << "O n�mero � positivo\n";
            cont++;
        }
    }
    while (cont <=10);
}
