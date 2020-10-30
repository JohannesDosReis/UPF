#include <iostream>
using namespace std;

int main()
{
    int elef, cont = 1;
    cout << "Digite a quantidades de elefantes\n";
    cin >> elef;

    if (elef >= 1)
    {
        cout << cont << " elefantes incomada muita gente\n";
        cont++;
    }
    while (cont<= elef)
    {
        cout << cont << " elefantes ";
        for (int i = 0; i < cont; i++)
        {
            cout << "imcomodam, ";
        }
        cout << "muito mais\n";
        cont++;
        if (cont <= elef)
        {
            cout << cont << " elefantes incomadam muita gente\n";
            cont++;
        }
    }
    return 0;
}
