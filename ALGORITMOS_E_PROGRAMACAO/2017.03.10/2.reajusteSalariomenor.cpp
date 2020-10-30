#include <iostream>
using namespace std;

int main(){
    float salario, salreajustado;

    cout << "Digite seu salario atual: ";
    cin >> salario;

    if(salario<5000){
        salreajustado = salario*1.30;
        cout << "Seu salario reajustado R$: " << salreajustado;
    }else{
        cout << "Seu salario nao sofreu reajuste.";
    }
    return 0;
    }
