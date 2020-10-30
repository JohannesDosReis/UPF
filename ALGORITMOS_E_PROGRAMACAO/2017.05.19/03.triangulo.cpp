#include <iostream>
#include <string>
#include <tchar.h>
using namespace std;

string triangulo(int a, int b, int c)
{
	string t1("ERRO!"), t2("Equilátero"), t3("Isósceles"), t4("Escaleno");
	if (a + b < c || a + c < b || b + c < a)
	{
		return t1;
	}
	else if (a == b && a == c)
	{
		return t2;
	}
	else if (a == b || a == c || b == c)
	{
		return t3;
	}
	else
	{
		return t4;
	}
}

int main ()
{
    setlocale(LC_ALL, "Portuguese");
    int lado[3];
    string l[3]{"Primeiro lado ", "Segundo Lado ", "Terceiro Lado "};
    for (int i = 0; i < 3; i++)
    {
        cout << "Digite a dimensão do " << l[i] << endl;
        cin >> lado[i];
    }
    cout << "Triangulo " << triangulo(lado[0], lado[1], lado[2]) << endl;
    return 0;
}
