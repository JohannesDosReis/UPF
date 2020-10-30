#include <iostream>
using namespace std;

int main() {
	int a;
	cout << "Digite um valor\n";
	cin >> a;
	if (a % 2 == 0) {
		cout << "Valor par\n";
	}
	else {
		cout << "Valor impar\n";
	}
	return 0;
}