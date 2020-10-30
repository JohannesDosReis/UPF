#include <iostream>;
#include <iomanip>
using namespace std;

int main() {
	int n[6] = { 10000,5000,2000,1000,500,200 }; //Valores para as notas em centavos
	int m[6] = { 100,50,25,10,5,1 };
	double rest;
	int cents;
	int i;

	cin >> rest;
	
	cents = rest * 100; // convertendo para centavos

	cout << "NOTAS:\n";
	for (i = 0; i < 6; i++) {
		cout << cents / n[i] << " nota(s) de R$ " << fixed << setprecision(2) << (float) n[i] / 100.00 << endl;
		cents = cents % n[i];
	}
	cout << "MOEDAS:\n";
	for (i = 0; i < 6; i++) {
		cout << cents / m[i] << " moeda(s) de R$ " << fixed << setprecision(2) << (float) m[i] / 100.00 << endl;
		cents = cents % m[i];
	}
	system("pause");
	return 0;
}