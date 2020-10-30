#include <iostream>
using namespace std;

int main()
{
    int i, a = 0, b = 1, x;
    cout << "Sequencia de Fibonacci\n";
    for (i = 1; i <= 20; i++)
    {
        x = a + b;
        a = b;
        b = x;
        cout << x << endl;
    }
    return 0;
}
