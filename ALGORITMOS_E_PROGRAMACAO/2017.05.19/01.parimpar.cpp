#include <iostream>
#include <tchar.h>
using namespace std;

int ler(int n)
{
    int a, contpar = 0, contimpar = 0;
    for (int i = 0; i < n; i++)
    {
        cout << "Digite um número\n";
        cin >> a;
        if (a%2==0)
        {
            contpar++;
        }
        else
        {
            contimpar++;
        }

    }
    if (contpar == 0)
    {
        return 1;
    }
    else if (contimpar == 0)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int n, r;
    cout << "Digite quantos números serão digitados\n";
    cin >> n;
    r = ler(n);
    cout << endl << r << endl;
    return 0;
}
