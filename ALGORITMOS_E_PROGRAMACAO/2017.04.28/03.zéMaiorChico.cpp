#include <iostream>
#include <locale>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Portuguese");
	int anos = 0, c = 150, z = 110; // metros em cm
	do
	{
		c = c + 2;
		z = z + 3;
		anos++;
	} while (z <= c);
	cout << "Zé será maior que Chico em: " << anos << " anos" << endl;
	return 0;
}
