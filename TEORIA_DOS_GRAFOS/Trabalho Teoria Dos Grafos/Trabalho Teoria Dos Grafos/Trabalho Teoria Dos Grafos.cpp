#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include <iomanip>

#include <conio.h>
//#include <Windows.h>

using namespace std;

typedef struct vertex
{
	string str;
	list<struct adjacencies> AdjList;
} TVertex;

typedef struct adjacencies
{
	string dest;
	string str;
	int weight;
} TAdj;

typedef struct line
{
	string vertex;
	bool know;
	int cost;
	string path;
} TLine;

void ReadFile(list<TVertex> *pGraph);
void Show(list<TVertex> pGraph);
void Prim(list<TVertex> pGraph);
void Kruskal(list<TVertex> pGraph);
bool compare(TAdj i, TAdj j);
bool compareVertex(TVertex i, TVertex j);
bool compareEdge(TAdj i, TAdj j);

int main()
{
	char c;
	list<TVertex> Graph;
	do
	{
		system("cls");
		//TEM QUE COLOCAR O E-MAIL DE TODO MUNDO
		cout << "\n Johannes Dos Reis: johannes3712@gmail.com\n Sandro Motter: sandromotter@gmail.com \n Gabriel Silveira: gabrielsilveirapro@gmail.com \n L - LEITURA\n P - PRIM\n K - KRUSKAL\n F - FIM\n";
		//cin >> c;
		c = _getch();
		switch (toupper(c))
		{
		case 'L':
			ReadFile(&Graph);
			break;
		case 'P':
			if (!Graph.empty())
				Prim(Graph);
			else
			{
				cout << "\n Grafo Vazio!\n\n ";
				system("pause");
			}
			break;
		case 'K':
			if (!Graph.empty())
				Kruskal(Graph);
			else
			{
				cout << "\n Grafo Vazio!\n\n ";
				system("pause");
			}
			break;
		case 'S':
			Show(Graph);
			break;
		}
	} while (toupper(c) != 'F');
	return 0;
}

bool compareVertex(TVertex i, TVertex j) { return (i.str < j.str); }
bool compareEdge(TAdj i, TAdj j) { return (i.dest < j.dest); }

void ReadFile(list<TVertex> *pGraph)
{
	pGraph->erase(pGraph->begin(), pGraph->end());
	ifstream inFile;
	string org, dest;
	list<TVertex>::iterator itOrg, itDest;
	TAdj Eaux;
	TVertex Vaux;
	int length;
	inFile.open("INPUT_GRAPH.txt", ios::in);
	if (!inFile)
	{
		cout << "\n Arquivo INPUT_GRAPH.txt nao pode ser aberto" << endl;
		abort();
	}
	inFile >> length;
	itOrg = pGraph->begin();
	cout << "\n Lendo Vertices\n";
	//le todos os vertices do grafo
	for (int i = 0; i < length; i++)
	{
		inFile >> Vaux.str;
		itOrg = pGraph->begin();
		pGraph->push_back(Vaux);
		int j;
		cout << "\r " << setw(3) << right << 100 * i / length << "% [";
		for (j = 0; j < 50 * i / length; j++)
			cout << "/";
		while (j < 50)
		{
			j++;
			cout << " ";
		}
		cout << "]";
		//Sleep(100);
	}
	cout << "\r 100% [";
	for (int i = 0; i < 50; i++)
		cout << "/";
	cout << "]\n";
	cout << "\n Lendo Arestas\n";
	inFile >> length;
	//le todas as arestas do grafo
	for (int i = 0; i < length; i++)
	{
		inFile >> Eaux.str >> org >> dest >> Eaux.weight;
		itOrg = itDest = pGraph->begin();

		//encontra o vertice de origem
		while (itOrg->str != org)
			itOrg++;
		//encontra o vertice de destino
		while (itDest->str != dest)
			itDest++;

		Eaux.dest = dest;
		itOrg->AdjList.push_back(Eaux);
		Eaux.dest = org;
		itDest->AdjList.push_back(Eaux);

		//barra de progresso kkkkkkkkk
		int j;
		cout << "\r " << setw(3) << right << 100 * i / length << "% [";
		for (j = 0; j < 50 * i / length; j++)
			cout << "/";
		while (j < 50)
		{
			j++;
			cout << " ";
		}
		cout << "]";
		//Sleep(100);
	}
	inFile.close();

	pGraph->sort(compareVertex);

	itOrg = pGraph->begin();
	while (itOrg != pGraph->end())
	{
		itOrg->AdjList.sort(compareEdge);
		itOrg++;
	}


	cout << "\r 100% [";
	for (int i = 0; i < 50; i++)
		cout << "/";
	cout << "]\n";
	cout << "\n Sucesso\n ";
	system("pause");
}

// mostra o grafo
void Show(list<TVertex> pGraph)
{
	list<TVertex>::iterator itV = pGraph.begin();
	list<TAdj>::iterator itE;
	cout << endl;
	while (itV != pGraph.end())
	{
		cout << " " << itV->str << "  -  ";
		itE = itV->AdjList.begin();
		while (itE != itV->AdjList.end())
		{
			cout << " " << itE->dest << " " << itE->str << " (" << setw(3) << itE->weight << ")";
			itE++;
			if (itE != itV->AdjList.end())
				cout << " || ";
		}
		cout << endl;
		itV++;
	}
	cout << "\n\n ";
	system("pause");
}

void Prim(list<TVertex> pGraph)
{
	TLine aux = {"\0", false, INT_MAX, "\0"};
	vector<TLine> matrix;
	list<TVertex>::iterator it;
	list<TAdj>::iterator itE;
	string str;
	int i, j;
	int CustoTotal = 0;
	it = pGraph.begin();
	while (it != pGraph.end())
	{
		aux.vertex = it->str;
		//adiciona o nome do vetice na matrix
		matrix.push_back(aux);
		it++;
	}

	do
	{
		cout << "\n Digite o Vertice de Inicio: ";
		//cin >> str;
		getline(cin, str);
		it = pGraph.begin();
		i = 0;
		while (it != pGraph.end() && it->str != str)
		{
			it++;
			i++;
		} //encontra o indice do vetice na matrix
		if (it == pGraph.end())
			cout << "\n Vertice nao encontrado!\n";
	} while (it == pGraph.end()); //repete ate que um vertice valido seja encontrado

	matrix[i].cost = 0;

	while (!matrix[i].know) //enquanto todos nao foram visitados
	{
		matrix[i].know = true;
		it = pGraph.begin();
		while (it->str != matrix[i].vertex)
			it++;
		itE = it->AdjList.begin();
		while (itE != it->AdjList.end())
		{
			j = 0;
			while (matrix[j].vertex != itE->dest)
				j++;
			if (matrix[j].know == false && itE->weight < matrix[j].cost)
			{
				matrix[j].cost = itE->weight;
				matrix[j].path = matrix[i].vertex;
				//CustoTotal += itE->weight;
			}
			itE++;
		}
		it = pGraph.begin();
		//encontra o menor nao visitado
		for (j = 0; j < matrix.size(); j++)
		{
			if (matrix[j].know == false && it->AdjList.begin() != it->AdjList.end())
			{
				if (matrix[j].cost < matrix[i].cost || matrix[i].know == true)
					i = j;
			}
			it++;
		}
	}
	//mostra a tabela
	// cout << setw(20) << left << " Vertice" << setw(20) << left << " Visitado"
	// cout << " Vertice" << setw(20) << left << " Visitado" << setw(20) << left << " Custo" << setw(20) << left << " Pai" << endl;

	cout << " " << setw(20) << left << "Vertice" << " " << setw(20) << left << "Visitado" << " " << setw(20) << left << "Custo" << " " << "Pai" << endl;

	for (i = 0; i < matrix.size(); i++)
	{
		cout << " " << setw(20) << left << matrix[i].vertex << " "
			 << setw(20) << left << ((matrix[i].know) ? "true" : "false") << " "
			 << setw(20) << left << matrix[i].cost << " "
			 << setw(20) << left << matrix[i].path << endl;
			CustoTotal += matrix[i].cost;
			
	}
	cout << "\n\n ";
	cout << "CUSTO : " << CustoTotal;
	cout << "\n\n ";
	system("pause");
}

bool compare(TAdj i, TAdj j)
{
	if (i.weight != j.weight)
		return (i.weight < j.weight);
	else if (i.str != j.str)
		return (i.str < j.str);
	else
		return (i.dest < j.dest);
} //ordenar o vetor do Kruskal

void Kruskal(list<TVertex> pGraph)
{
	vector<int> matrix(pGraph.size(), -1);
	vector<TAdj> adjMat;
	list<TVertex>::iterator it = pGraph.begin();
	list<TAdj>::iterator itAdj;
	TAdj AdjAux;
	while (it != pGraph.end())
	{
		itAdj = it->AdjList.begin();
		AdjAux.str = it->str;
		while (itAdj != it->AdjList.end())
		{
			AdjAux.dest = itAdj->dest;
			AdjAux.weight = itAdj->weight;
			if (AdjAux.str < itAdj->dest)
				adjMat.push_back(AdjAux); //adiciona as arestas a lista
			itAdj++;
		}
		it++;
	}
	sort(adjMat.begin(), adjMat.end(), compare); //ordena a lista pelo peso
	int org, dest;
	for (int i = 0; i < adjMat.size(); i++)
	{
		org = dest = 0;
		it = pGraph.begin();
		//encontra o indice da origem
		while (adjMat[i].str != it->str)
		{
			org++;
			it++;
		}
		it = pGraph.begin();
		//encontra o indice do destino
		while (adjMat[i].dest != it->str)
		{
			dest++;
			it++;
		}

		// redireciona os indices se maior que -1
		while (matrix[org] > -1)
			org = matrix[org];
		while (matrix[dest] > -1)
			dest = matrix[dest];

		//testa se sao iguais
		if (org != dest)
		{
			if (matrix[org] > matrix[dest])
			{
				matrix[dest] += matrix[org];
				matrix[org] = dest;
			}
			else if (matrix[org] < matrix[dest])
			{
				matrix[org] += matrix[dest];
				matrix[dest] = org;
			}
			else
			{
				if (org < dest)
				{
					matrix[dest] += matrix[org];
					matrix[org] = dest;
				}
				else
				{
					matrix[org] += matrix[dest];
					matrix[dest] = org;
				}
			}
		}
	}
	it = pGraph.begin();
	list<TVertex>::iterator itAux;
	//mostra a tabela
	cout << endl;
	for (int i = 0; i < matrix.size(); i++)
	{
		cout << " " << it->str;
		if (matrix[i] < 0)
			cout << " " << matrix[i];
		else
		{
			itAux = pGraph.begin();
			for (int j = 0; j < matrix[i]; j++)
				itAux++; //encotra o nome do indice
			cout << " " << itAux->str;
		}
		cout << endl;
		it++;
		//Sleep(100);
	}
	cout << "\n\n ";
	system("pause");
}
