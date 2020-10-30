#include <iostream>
using namespace std;

int main(){
    int a,b,c;
    cout <<"Digite tres numeros inteiros e diferentes: " << endl << "Digite o primeiro valor: ";
    cin >> a;
    cout << "Digite o segundo valor: ";
    cin >> b;
    cout << "Digite o terceiro valor: ";
    cin >> c;

    if(a==b || a==c || b==c){
        cout << endl << "Erro, numeros iguais digitados! " << endl;
    }else if(a>b && b>c){
        cout << endl << "Maior numero: " << a;
        cout << endl <<"Numero do meio: " << b;
        cout << endl << "Menor numero: " << c << endl;

    }else if(a>c && c>b){
        cout << endl << "Maior numero: " << a;
        cout << endl <<"Numero do meio: " << c;
        cout << endl << "Menor numero: " << b << endl;

    }else if(b>a && a>c){
        cout << endl << "Maior numero: " << b;
        cout << endl <<"Numero do meio: " << a;
        cout << endl << "Menor numero: " << c << endl;

    }else if(b>c && c>a){
        cout << endl << "Maior numero: " << b;
        cout << endl <<"Numero do meio: " << c;
        cout << endl << "Menor numero: " << a << endl;

    }else if(c>a && a>b){
        cout << endl << "Maior numero: " << c;
        cout << endl <<"Numero do meio: " << a;
        cout << endl << "Menor numero: " << b << endl;
    }else if(c>b && b>a){
        cout << endl << "Maior numero: " << c;
        cout << endl <<"Numero do meio: " << b;
        cout << endl << "Menor numero: " << a << endl;
    }
return 0;
}
