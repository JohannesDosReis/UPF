#include <iostream>
#include <locale>
using namespace std;

int main ()
{
    int cont = 0, a;
    setlocale(LC_ALL, "Portuguese");
    do
    {
        cout << "Digite um número\n";
        cin >> a;
        if(a==0)
        {
            cout << "Número zero informado, digite outro valor\n";
        }
        else if (a<0)
        {
            cout << "O número é positivo\n";
            cont++;
        }
        else
        {
            cout << "O número é positivo\n";
            cont++;
        }
    }
    while (cont <=10);
}
