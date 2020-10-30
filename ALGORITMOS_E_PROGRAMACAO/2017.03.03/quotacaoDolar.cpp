#include <iostream>
using namespace std;

int main(){
    float quotacao, dolar, reais;

    cout << "Informe a cotacao atual do dolar: ";
    cin >> quotacao;

    cout << "Informe quantos reais: ";
    cin >> reais;

    dolar = (quotacao * reais);
    cout << "$: " << dolar << endl;

}
