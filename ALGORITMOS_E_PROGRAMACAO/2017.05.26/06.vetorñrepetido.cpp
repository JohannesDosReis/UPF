#include <iostream>
#include <locale>
using namespace std;

int main()
{
	int vetor[10];
	setlocale(LC_ALL, "Portuguese");
	for (int i = 0; i < 10; i++)
	{
		cout << "\nDigite o " << i + 1 << "º valor do vetor\n";
		cin >> vetor[i];
		for (int j = 0; j < i; j++)
		{
			if (vetor[i] == vetor[j])
			{
				cout << "\nNúmero Repetido, digite outro\n";
				i--;
			}
		}
	}
	return 0;
}