#include <iostream>
using namespace std;

int main()
{
    int i;
    cout << "Informe sua idade: ";
    cin >> i;
    if(i<5)
    {
    }
    else if (i<=7)
{
    cout << endl << "Infantil A " << endl;
}
else if (i<=10)
{
    cout << endl << "Infantil B " << endl;
}
else if (i<=13)
{
    cout << endl << "Juvenil A " << endl;
}
else if (i<=17)
{
    cout << endl << "Juvenil B " << endl;
}
else
{
    cout << endl <<
    "Adulto " << endl;
}
return 0;
}
