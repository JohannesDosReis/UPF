#include <iostream>
using namespace std;

int main()
{
    int a, golsGremio, golsInter, quantGrenais = 0, vitGremio = 0, vitInter = 0, emp = 0;
    do
    {
        cout << "Digite o  numero de gols marcados pelo Gremio\n";
        cin >> golsGremio;
        cout << "Digite o  numero de gols marcados pelo Inter\n";
        cin >> golsInter;

        quantGrenais++;

        if (golsGremio > golsInter)
        {
            vitGremio++;
        }
        else if (golsGremio < golsInter)
        {
            vitInter++;
        }
        else
        {
            emp++;
        }
        cout << "Novo grenal?\n" << "1 - sim\n" << "2 - nao\n";
        cin >> a;

    }
    while (a == 1);


    cout << quantGrenais << " fizeram parte da estatistica\n";
    cout << vitGremio << " vitorias do Gremio\n";
    cout << vitInter << " vitorias do Inter\n";
    cout << emp << " empates\n";

    if (vitGremio > vitInter)
    {
        cout << "Gremio foi o vencedor!\n";
    }
    else if (vitGremio < vitInter)
    {
        cout << "Inter foi o vencedor!\n";
    }
    else
    {
        cout << "Nao houve vencedor\n";
    }
    return 0;
}
