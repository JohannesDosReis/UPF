#include <iostream>
#include <tchar.h>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int senhavalida = 2011, senha, cont = 0;
    do
    {
        cont++;
        cout << endl << "Digite a Senha\n";
        cin >> senha;
        if(senha == senhavalida)
        {
            cout << "ACESSO PERMITIDO\n";
            cout << "Número de tentativas: " << cont << '\n';
            break;
        }
        cout << "SENHA INVALIDA\n";
    }
    while (true);
    return 0;
}
