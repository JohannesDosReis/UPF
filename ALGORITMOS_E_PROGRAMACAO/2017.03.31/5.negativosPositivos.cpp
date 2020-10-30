#include <iostream>
using namespace std;

int main()
{
	int neg = 0, pos = 0, a;
	cout << "Digite 10 numeros\n";
	for (int i = 0; i < 10; i++)
	{
		cin >> a;
		if (a > 0)
		{
			pos++;
		}
		if (a < 0)
		{
			neg++;
		}
	}
	cout << pos << " numeros positivos lidos\n";
	cout << neg << " numeros negativos lidos\n";
	return 0;
}
