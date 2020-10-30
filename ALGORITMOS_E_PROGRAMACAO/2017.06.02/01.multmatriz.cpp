#include <iostream>
#include <locale>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int n, matriz[2][3], cont = 0;
    for (int l = 0; l < 2; l++)
    {
        for (int c = 0; c < 3; c++)
        {
            cout << "Digite um valor para a linha " << l+1 << " e coluna " << c+1 << " da matriz\n";
            cin >> matriz[l][c];
        }
    }
    cout << "Digite o número de pelo qual a matriz será multiplicada\n";
    cin >> n;
    cout << "\nMatriz resultante\n";
    for (int l = 0; l < 2; l++)
    {
        for(int c = 0; c < 3; c++)
        {
            if (cont == 3)
            {
                cont = 0;
                cout << endl;
            }
            matriz[l][c] *= n;
            cout << matriz[l][c] << " ";
            cont++;
        }
    }
    return 0;
}
