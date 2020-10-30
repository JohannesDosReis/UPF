#include <iostream>

using namespace std;

extern "C" {
    long long int maior(long long int, long long int);
}

int main(void) {
    long long int a, b, m;
    cout << "Informe um numero: ";
    cin >> a;
    cout << "Informe outro numero: ";
    cin >> b;
    m = maior(a, b);

    cout << "Maior: " << m << endl;
    return 0;
}