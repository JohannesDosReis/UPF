#include <iostream>
using namespace std;

int main() {
	int total, c50, c20, c10, c5, c2;
	cout << "Digite o valor\n";
	cin >> total;
	c50 = 0;
	c20 = 0;
	c10 = 0;
	c5 = 0;
	c2 = 0;

	if (total >= 50) {
		c50 = total / 50;
		total = total % 50;
	}
	if (total >= 20) {
		c20 = total / 20;
		total = total % 20;
	}
	if (total >= 10) {
		c10 = total / 10;
		total = total % 10;
	}
	if (total >= 5) {
		c5 = total / 5;
		total = total % 5;
	}
	if (total >= 2) {
		c2 = total / 2;
	}
	cout << "Numero de cedulas de R$ 50,00: " << c50 << endl;
	cout << "Numero de cedulas de R$ 20,00: " << c20 << endl;
	cout << "Numero de cedulas de R$ 10,00: " << c10 << endl;
	cout << "Numero de cedulas de R$ 5,00: " << c5 << endl;
	cout << "Numero de cedulas de R$ 2,00: " << c2 << endl;
	return 0;
}