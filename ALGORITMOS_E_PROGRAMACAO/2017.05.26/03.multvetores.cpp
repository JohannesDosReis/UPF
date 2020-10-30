#include <iostream>
#include <locale>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int vet1[10], vet2[10], mult[10];
    for(int i = 0; i < 10; i++)
    {
        cout << "Digite o " << i+1 << "º valor do primeiro vetor\n";
        cin >> vet1[i];
    }
    for(int i = 0; i < 10; i++)
    {
        cout << "Digite o " << i+1 << "º valor do segundo vetor\n";
        cin >> vet2[i];
    }
    for(int i = 0; i < 10; i++)
    {
        mult[i] = vet1[i] * vet2[i];
    }
    for(int i = 0; i < 10; i++)
    {
        cout << mult[i] << endl;
    }
    return 0;
}
