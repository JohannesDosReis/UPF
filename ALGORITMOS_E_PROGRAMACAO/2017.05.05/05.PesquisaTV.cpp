#include <iostream>
#include <tchar.h>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int canal,numpes4, numpes5, numpes7, numpes12, por4 = 0, por5 = 0, por7 = 0, por12 = 0;
    do
    {
        cout << "Digite o número do canal\n";
        cin >> canal;
        switch (canal)
        {
    case 4:
        cout << "Digite o número de pessoas assintindo a esta canal\n";
        cin >> numpes4;
        por4 = por4 + numpes4;
        break;
    case 5:
        cout << "Digite o número de pessoas assintindo ao canal\n";
        cin >> numpes5;
        por5 = por5 + numpes5;
        break;
    case 7:
        cout << "Digite o número de pessoas assintindo ao canal\n";
        cin >> numpes7;
        por7 = por7 + numpes7;
        break;
    case 12:
        cout << "Digite o número de pessoas assintindo ao canal\n";
        cin >> numpes12;
        por12 = por12 + numpes12;
        break;
        }
    }
    while(canal!=0);
    cout << "audiência do canal 4" << (por4 / (por4 + por5 + por7 + por12)) * 100 << "%" << endl;
    cout << "audiência do canal 5" << (por5 / (por4 + por5 + por7 + por12)) * 100 << "%" << endl;
    cout << "audiência do canal 7" << (por7 / (por4 + por5 + por7 + por12)) * 100 << "%" << endl;
    cout << "audiência do canal 12" << (por12 / (por4 + por5 + por7 + por12)) * 100 << "%" << endl;
    return 0;
}
