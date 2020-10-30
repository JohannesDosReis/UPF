#include <iostream>
using namespace std;

int main(){
    float l1,l2,l3;
    cout << "Digite o comprimento do primeiro lado do triangulo: ";
    cin >>l1;
    cout << "Digite o comprimento do segundo lado do triangulo: ";
    cin >>l2;
    cout << "Digite o comprimento do terceiro lado do segundo: ";
    cin >>l3;
    if((l1+l2)<l3 || (l2+l3)<l1 || (l1+l3)<l2){
            cout << endl << "Triangulo nao pode ser construido com esses valores!";
    }else if(l1==l2 && l2==l3){
        cout << endl <<  "O triangulo Equilatero";
        }else if(l1==l2 || l1==l3 || l2==l3){
            cout << endl << "Triangulo Isosceles";
            }else{
                cout << endl << "Triangulo Escaleno";
    }
}
