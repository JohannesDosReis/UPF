#include <iostream>
#include <string>
#include <locale>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Portuguese");
	cout << "  _____   ___    ___     _____     _      ___     _____    ___     ___                " << endl;
	cout << " |_   _| |_ _|  / __|   |_   _|   /_\\    / __|   |_   _|  / _ \\   / __|   ___|___|___ " << endl;
	cout << "   | |    | |  | (__      | |    / _ \\  | (__      | |   | (_) | | (__    ___|___|___ " << endl;
	cout << "   |_|   |___|  \\___|     |_|   /_/ \\_\\  \\___|     |_|    \\___/   \\___|      |   |    " << endl;
	cout << "\nDigite valores entre 1 e 3 para linha e coluna que deseja colucar o X ou O\n";
	char icone[2] = { 'X','O' }, escolha, aux, matriz[3][3] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ' ,' ' ,' ' };
	int cont = 0, linha, coluna;
	string jogador[2] = { "Jogador 1" ,"Jogador 2" };
	do
	{
		cout << jogador[0] << " Digite X ou O para escolher qual figura você quer: ";
		cin >> escolha;
		if (escolha != 'O' && escolha != 'X')
		{
			cout << "Opcção Invalida\n";
			cout << "Tente novamente\n";
		}
		else if (escolha == 'O')
		{
			aux = icone[0];
			icone[0] = icone[1];
			icone[1] = aux;
		}
	} while (escolha != 'X' && escolha != 'O');
	do
	{
		cout << endl << jogador[cont % 2] << "  digite a linha onde quer colocar o " << icone[cont % 2] << ": ";
		cin >> linha;
		cout << jogador[cont % 2] << "  digite a coluna onde quer colocar o " << icone[cont % 2] << ": ";
		cin >> coluna;
		if (linha > 4 || linha < 1 || coluna > 4 || linha < 1)
		{
			cout << "Lugar Invalido tente novamente\n";
			continue;
		}
		if (matriz[linha - 1][coluna - 1] != ' ')
		{
			cout << "\nLugar já prenchido tente outro\n";
			continue;
		}
		matriz[linha - 1][coluna - 1] = icone[cont % 2];
		bool dP = true, dS = true, Linha[3] = { true, true, true }, Coluna[3] = { true, true, true }, empate = true;
		for (int l = 0; l < 3; l++)
		{
			for (int i = 0; i < 3; i++)
			{
				if (matriz[l][i] == ' ')
				{
					empate = false;
				}
				if (matriz[i][l] != icone[cont % 2])
				{
					Linha[i] = false;
				}
				if (matriz[l][i] != icone[cont % 2])
				{
					Coluna[i] = false;
				}
				if (matriz[l][l] != icone[cont % 2])
				{
					dP = false;
				}
				if ((l + i == 2) && matriz[l][i] != icone[cont % 2])
				{
					dS = false;

				}
				cout << " " << matriz[l][i];
				if (i < 2)
				{
					cout << " | ";
				}
			}
			if (l < 2)
			{
				cout << "\n-------------\n";
			}
		}
		if (dP || dS || Linha[0] || Linha[1] || Linha[2] || Coluna[0] || Coluna[1] || Coluna[2])
		{
			cout << "\n\nO " << jogador[(cont - 1) % 2] << " foi o ganhador\n";
			system("pause");
			return 0;
		}
		else if (empate)
		{
			cout << "\n\nOcorreu um empate\n";
			system("pause");
			return 0;
		}
		cont++;
	} while (true);
}
