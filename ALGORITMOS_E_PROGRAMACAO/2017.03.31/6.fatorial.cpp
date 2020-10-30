#include <iostream>
using namespace std;

int main()
{
    int i, a, fat = 1;
    cout << "Digite um numero\n";
    cin >> a;
    cout << "Fatorial de " << a << endl;
    for (i = 1; i <= a; i++)
    {
        fat = fat * i;
    }
    cout << fat << endl;;
    return 0;
}
