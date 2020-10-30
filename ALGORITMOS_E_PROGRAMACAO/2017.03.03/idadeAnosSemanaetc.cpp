#include <iostream>
using namespace std;

int main(){
    int i;

    cout << "Digite sua idade: ";
    cin >> i;

    cout << "Voce tem " << i*12 << " meses" << endl;
    cout << i*52.1429 << " semanas" << endl;
    cout << i*365.25 << " dias" << endl;
    return 0;
}
