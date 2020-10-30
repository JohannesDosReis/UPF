#include <iostream>
using namespace std;

int main(){
    float a, litrosConsumidos;

    cout << "Informe a quantidade de caixas consumidas: ";
    cin >> a;

    litrosConsumidos = (14.4 * a);
    cout << "Litros Consumidos: " << litrosConsumidos << " litros" << endl;
}
