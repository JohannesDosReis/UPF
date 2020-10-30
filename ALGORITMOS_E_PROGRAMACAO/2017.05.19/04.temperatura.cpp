#include <iostream>
#include <iomanip>
#include <tchar.h>
using namespace std;

double conversor(double f)
{
    double c;
    c = (f-32)*5/9;
    return c;
}

int main ()
{
    setlocale(LC_ALL, "Portuguese");
    double Fahrenheit, Celsius;
    cout << "Digite a temperatura em Fahrenheit: ";
    cin >> Fahrenheit;
    Celsius = conversor(Fahrenheit);
    cout << "Temperatura em graus Celsius: " << fixed << setprecision(2) << Celsius << "º" << endl;
    return 0;
}
