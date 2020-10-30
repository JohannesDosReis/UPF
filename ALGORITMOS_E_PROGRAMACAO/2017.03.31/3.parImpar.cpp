#include <iostream>
using namespace std;

int main()
{
    int a, b, aux, par, impar;
    cout << "Digite dois numeros\n";
    cin >> a >> b;
    if (a > b)
    {
        aux = a;
        a = b;
        b = aux;
    }
    if (a % 2 == 0)
    {
        par = a + 2;
        impar = a + 1;
    }
    if (a % 2 == 1)
    {
        par = a + 1;
        impar = a + 2;
    }
    cout << "Numeros pares entre " << a << " e " << b << endl;
    if (par < b || impar < b)
    {
        while (par < b)
        {
            cout << par << endl;
            par = par + 2;
        }
        cout << "Numeros impares entre " << a << " e " << b << endl;
        while (impar < b)
        {
            cout << impar << endl;
            impar = impar + 2;
        }
    }
    else
    {
        cout << "Nao existem valores entre " << a << " e " << b << endl;
    }
    return 0;
}
