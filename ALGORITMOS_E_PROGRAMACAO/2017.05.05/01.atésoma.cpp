#include <iostream>
#include <locale>
using namespace std;

int main ()
{
    setlocale(LC_ALL, "Portuguese");
    int a, som = 0, cont = 0;
    do
    {
        cout << "Digite um números\n";
        cin >> a;
        som += a;
        cont++;

    }
    while (som <= 100);
    cout << endl << cont << " números digitados" << endl;
    return 0;
}
