#include <iostream>
using namespace std;

int main()
{
    double a, b, c, mont, escolar, esc;
    cout << "Digite o valor da passagem normal: ";
    cin >> a;
    cout << "Digite o numero de passagens a serem adquiridas ";
    cin >> b;

    esc = a*0.6;
         cout << "Valor da Passagem escolar = R$ " << esc << endl;

    if(b>50)
    {
        c = b-50;
        mont = (50*esc) + (c*a);
        cout << "Montante = R$: " << mont << endl;
    }
    else
    {
        mont = (b*esc);
               cout << "Montante = R$: " << mont << endl;
    }
    return 0;
}
