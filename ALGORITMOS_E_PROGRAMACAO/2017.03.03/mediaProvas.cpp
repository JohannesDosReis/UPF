#include <iostream>
using namespace std;

int main(){
    float p1,p2,t,mediap;

    cout << "Informe a nota da prova 1: ";
    cin >> p1;

    cout << "Informe a nota da prova 2: ";
    cin >> p2;

    cout << "Informe a nota do trabalho: ";
    cin >> t;

    mediap = ((p1*3)+(p2*5)+(t*2))/10;
    cout << "Media do aluno: " << mediap << endl;
    return 0;
}
