#include <iostream>
#include <locale>
#include <vector>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Portuguese");
	int n, soma = 0;
	cout << "Digite quantos números serão inseridos no vetor\n";
	cin >> n;
	vector <int> vetor(n);
	for (int i = 0; i < n; i++)
	{
		cout << "Digite o " << i + 1 << "º valor do vetor\n";
		cin >> vetor[i];
	}
	cout << "\n\nValores do vetor\n";
	for (int i = 0; i < n; i++)
	{
		cout << vetor[i] << endl;
		soma += vetor[i];
	}
	cout << "\nSoma = " << soma << endl;
	return 0;
}

