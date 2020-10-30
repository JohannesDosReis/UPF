#include <iostream>
#include <locale>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Portuguese");
	int n = 0;
	cout << "Digite 10 numeros diferentes de 0\n";
	while (n <= 10)
	{
		cin >> n;
		if (n == 0)
		{
			cout << "Zero informado\n";
			n = -1;
		}
		else if (n > 0)
		{
			cout << n << " é um número é positivo" << endl;
		}
		else
		{
			cout << n << " é um número é negativo" << endl;
		}
		n++;
	}
	return 0;
}
