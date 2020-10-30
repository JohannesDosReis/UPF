#include <iostream>
using namespace std;

int main()
{
    int cod;
    double q, valor;
    cout << "Digite o codigo do produto desejado" << endl;
    cin >> cod;
    cout << "Digite a quantidade" << endl;
    cin >> q;

    if(cod == 10)
    {
        cout << "Valor= R$ " << q*3.5 << endl;
    }
    else if (cod == 11)
    {
        cout << "Valor= R$ " << q*7.5 << endl;
    }
    else if(cod == 12)
    {
        cout << "Valor= R$ " << q*8 << endl;
    }
    else if(cod ==13)
    {
        cout << "Valor= R$ " << q*3.5 << endl;
    }
    else if(cod == 14)
    {
        cout << "Valor= R$ " << q*7.5 << endl;
    }
    else if (cod == 15)
    {
        cout << "Valor= R$ " << q*3.5 << endl;
    }

    return 0;
}
