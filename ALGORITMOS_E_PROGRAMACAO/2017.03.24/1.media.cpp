#include <iostream>
using namespace std;

int main() {
	int a, b, c, op;
	double media;
	cout << "Digite tres valores\n";
	cin >> a >> b >> c;
	cout << "Escolha a opcao\n";
	cout << "1 - media aritmetica\n";
	cout << "2 - media ponderada\n";
	cin >> op;

	switch (op)
	{
	case 1: media = (a + b + c) / 3;
		break;
	case 2: media = ((a * 3) + (b * 3) + (c * 4)) / (3 + 3 + 4);
		break;
	}
	cout << "Media: " << media << endl;
	return 0;
}
