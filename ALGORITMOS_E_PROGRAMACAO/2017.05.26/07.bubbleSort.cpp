#include <iostream>
#include <locale>
using namespace std;

void bubble_sort(int vet[], int max)
{
	int flag, i, aux;
	do {
		flag = 0;
		for (i = 0; i < (max - 1); i++) {
			if (vet[i] > vet[i + 1]) {
				aux = vet[i];
				vet[i] = vet[i + 1];
				vet[i + 1] = aux;
				flag = 1;
			}
		}
	} while (flag == 1);
}
int main()
{
    setlocale(LC_ALL, "Portuguese");
	int vet[20];
	for (int i = 0; i < 20; i++)
	{
		cout << "Digite o " << i + 1 << "º valor do vetor\n";
		cin >> vet[i];
	}
	bubble_sort(vet, 20);
	cout << "Vetor em ordem crescente";
	for (int i = 0; i < 20; i++)
	{
		cout << vet[i] << '\n';
	}
	return 0;
}
