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
			cout << n << " � um n�mero � positivo" << endl;
		}
		else
		{
			cout << n << " � um n�mero � negativo" << endl;
		}
		n++;
	}
	return 0;
}
