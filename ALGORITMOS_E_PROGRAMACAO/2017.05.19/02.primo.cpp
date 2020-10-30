#include <iostream>
#include <tchar.h>
using namespace std;

int primo(int m)
{
    bool primo = 1;
    for(int i = 2; i < m; i++)
    {
        if (m%i == 0)
        {
            primo = 0;
            return 0;
        }
    }
    return 1;
}

int main ()
{
    int a, b;
    cout << "Digite um valor\n";
    cin >> a;
    b = primo(a);
    cout << b << endl;
    return 0;
}
