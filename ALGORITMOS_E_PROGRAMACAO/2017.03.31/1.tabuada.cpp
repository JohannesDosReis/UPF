#include <iostream>
using namespace std;

int main()
{
    int a, i;
    cout << "Digite qual tabuada\n";
    cin >> a;
    cout << "Tabuada do " << a << endl;
    for(i = 1; i <= 10; i++)
    {
        cout << a << " * " << i << " = " << a * i << endl;
    }
    return 0;
}
