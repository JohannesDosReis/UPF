#include <iostream>
using namespace std;
int main()
{
    int a, b, i;
    b = 0;
    cout << "Digite 5 numeros\n";
    for(i = 0; i < 5; i++)
    {
        cin >> a;
        b = b + a;
    }
    cout << "Soma: " << b << endl;
    return 0;
}
