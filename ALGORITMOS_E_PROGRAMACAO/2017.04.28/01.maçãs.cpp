#include <iostream>
#include <locale>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Portuguese");
	int a;
	cout << "Digite o numero de maçãs a serem compradas\n";
	cin >> a;
	if (a < 12)
	{
		cout << "Valor total da compra R$: " << 0.5*a << endl;
	}
	else
	{
		cout << "Valor total da compra R$: " << 0.35*a << endl;
	}
	return 0;
}
