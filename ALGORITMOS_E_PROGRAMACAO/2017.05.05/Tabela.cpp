# include <iostream>
#include <locale>
using namespace std;

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    for (char i = -127; i <= 126; i++)
    {
        cout << i << " = " << (int) i << " ";
    }

    return 0;
}
