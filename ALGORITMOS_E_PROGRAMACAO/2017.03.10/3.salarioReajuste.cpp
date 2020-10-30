#include <iostream>
using namespace std;

int main(){
    float sal, salreaj;
    cout << "Informe seu salario atual: ";
    cin >> sal;

    if(sal<3000){
        salreaj = sal*1.5;
        cout << salreaj;
    }else if(sal>= 3000 && sal<= 10000){
        salreaj = sal*1.2;
        cout << salreaj;
        }else{
            salreaj = sal*1.15;
            cout << salreaj;
        }
return 0;
}
