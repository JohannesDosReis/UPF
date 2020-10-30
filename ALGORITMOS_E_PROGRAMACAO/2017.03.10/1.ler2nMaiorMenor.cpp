#include <iostream>
using namespace std;

int main(){
    int n1,n2;

    cout << "Digite um valor: ";
    cin >> n1;
    cout << "Digite outro valor: ";
    cin >> n2;
    if(n1==n2){
            cout << "Os valores são iguais";
        }else if(n1>n2){
        cout << "Maior: " << n1 << endl;
        cout << "Menor: " << n2 << endl;
    }else{
        cout << "Maior: " << n2 << endl;
        cout << "Menor: " << n1 << endl;
    }
    return 0;
}
