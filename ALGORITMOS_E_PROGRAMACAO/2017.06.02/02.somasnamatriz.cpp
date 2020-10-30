#include <iostream>
using namespace std;

int main()
{
	int matriz[3][3], acm = 0;
	for (int lin = 0; lin < 3; lin++)
	{
		for (int col = 0; col < 3; col++)
		{
			cout << "Digite um valor para a linha " << lin + 1 << " e coluna " << col + 1 << " da matriz\n";
			cin >> matriz[lin][col];
		}
	}
	cout << "\n\nSoma dos elementos da primeira linha: ";
	for (int i = 0; i < 3; i++)
	{
		acm += matriz[0][i];
	}
	cout << acm << endl;
	acm = 0;
	cout << "\n\nSoma dos elementos da terceira coluna:";
	for (int i = 0; i < 3; i++)
	{
		acm += matriz[i][2];
	}
	cout << acm << endl;
	acm = 0;
	cout << "\nSoma dos elementos da diagonal principal: ";
	for (int i = 0; i < 3; i++)
	{
		acm += matriz[i][i];
	}
	cout << acm << endl;
	acm = 0;
	cout << "\n\nSoma de todos os elementos da matriz: ";
	for (int lin = 0; lin < 3; lin++)
	{
		for (int col = 0; col < 3; col++)
		{
			acm += matriz[lin][col];
		}
	}
	cout << acm << endl;
	return 0;
}