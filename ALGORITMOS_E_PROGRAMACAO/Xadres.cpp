#include <iostream>
using namespace std;

int main()
{
	int lin, col;
	cout << "Digite a posi��o da rainha:\n";
	cout << "Digite a linha da rainha: ";
	cin >> lin;
	cout << "\nDigite a coluna da rainha: ";
	cin >> col;
	if (col>lin)
	{
		int aux = col;
		col = lin;
		lin = aux;
	}
	if (col>3)
	{
		col -= 3;
	}
	cout << "N�mero de posi��es possiveis para pe�s: " << 64 - (22 + 2 * (col)) << endl;
	system("pause");
	return 0;
}