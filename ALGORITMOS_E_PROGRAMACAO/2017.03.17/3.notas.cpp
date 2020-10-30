#include <iostream>
using namespace std;

int main()
{
    double a, Nota1, Nota2, Nota3, ME, MA;
    cout << "Digite o numero de identificacao: ";
    cin >> a;
    cout << "Digite as 3 notas e a media dos exercicios " << endl;
    cin >> Nota1 >>  Nota2 >> Nota3 >> ME;
    MA = ((Nota1 + Nota2) * 2 + (Nota3 * 3) + ME )/7;
    cout << "Media = " << MA << endl;
    if(MA >= 9)
    {
        cout << "Conceito A" << endl;
    }
    else if(MA >= 7.5)
    {
        cout << "Conceito B" << endl;
    }
    else if(MA >= 6)
    {
        cout << "Conceito C" << endl;
    }
    else if(MA >= 4)
    {
        cout << "Conceito D" << endl;
    }
    else
    {
        cout << "Conceito E" << endl;
    }
    return 0;
}
