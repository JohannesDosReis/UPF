#include <iostream>
#include <locale>
using namespace std;

int main()
{
	int acm = 0, cont = 0;
	setlocale(LC_ALL, "Portuguese");
	int vetor[10];
	for (int i = 0; i < 10; i++)
	{
		cout << "Digite o valor do " << i+1 << "º valor do vetor\n";
		cin >> vetor[i];
		acm += vetor[i];
		cont++;
	}
	cout << "\n\nValores do vetor";
	for (int i = 0; i < 10; i++)
	{
		cout << vetor[i] << endl;
	}
	cout << "\nMédia = " << (float) acm / cont << endl;
	return 0;
}
