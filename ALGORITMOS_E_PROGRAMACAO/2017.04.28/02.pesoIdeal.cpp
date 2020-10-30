#include <iostream>
#include <locale>
#include <iomanip>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Portuguese");
	int sx;
	double ideal, alt;
	cout << "Informe sua altura: ";
	cin >> alt;
	cout << "Informe seu sexo:\n" << "1 - Masculino\n" << "2 - Feminino\n";
	cin >> sx;
	if (sx == 1)
	{
		ideal = (72.7 * alt) - 58;
	}
	else if (sx == 2)
	{
		ideal = (62.1 * alt) - 44.7;
	}
	cout << "Seu peso ideal é: " << fixed << setprecision(2) << ideal << " kg" << endl;
	system("pause");
	return 0;
}
