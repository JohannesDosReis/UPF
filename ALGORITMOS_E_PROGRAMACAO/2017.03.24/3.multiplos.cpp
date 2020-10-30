#include <iostream>
using namespace std;

int main() {
	int a, b;
	cout << "Digite dois valores\n";
	cin >> a >> b;
	if (a > b && a%b == 0) {
		cout << "Os valores sao multiplos\n";
	}
	else if (b > a && b%a == 0) {
		cout << "Os valores sao multiplos\n";
	}
	else {
		cout << "Os valores nao sao multiplos\n";
	}
	return 0;
}