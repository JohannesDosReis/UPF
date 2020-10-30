#include <iostream>
using namespace std;

int main(){
    float a,b,media;

    cout << "Informe os km rodados: ";
    cin >> a;

    cout << "Informe os litros gastos: ";
    cin >> b;

    media = (a/b);
    cout << "Media de litros gastos por km: " << media <<"km/l" << endl;
}
