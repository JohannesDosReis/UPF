#include "buffer.h"
#include "fifo.h"
#include "list.h"

#define v  179 // vertical
#define md 180 // meio direita
#define cd 191 // cima direita
#define be 192 // baixo esquerda
#define mb 193 // meio baixo
#define mc 194 // meio cima
#define me 195 // meio esquerda
#define h  196 // horizontal
#define m  197 // meio
#define bd 217 // baixo direita
#define ce 218 // cima esquerda


char Compare(void *pItem, void *pData);
void List(struct TList *pList, struct TBuffer *pBuff);
void Queue(struct TFifo *pFifo, struct TBuffer *pBuff);
void Show(struct TElement *pItem);
void ReadInfo(struct TData *pData);

void cleanBuffer(void)
{
	char c;
	while ((c = getchar()) != '\n' && c != EOF);
}

int main(void)
{
	int Size, Len, op;
	struct TBuffer MyBuffer;
	struct TList MyList;
	Lst(&MyList, &MyBuffer);
	struct TFifo MyQueue;
	Ffo(&MyQueue, &MyBuffer);
	printf("Digite quantos elementos o Buffer tera: ");
	scanf("%d", &Len);
	Size = sizeof(struct TElement);
	BufInitialize(&MyBuffer, Size, Len);
	do
	{
		system("cls");
		printf("Escolha uma opcao\n");
		printf("1: Lista\n");
		printf("2: Fila\n");
		printf("0: Sair\n");
		scanf("%d", &op);
		switch (op)
		{
		case 1:
			List(&MyList, &MyBuffer);
			break;
		case 2:
			Queue(&MyQueue, &MyBuffer);
			break;
		}
	} while (op);
	BufTerminate(&MyBuffer);
	return 0;
}

void List(struct TList *pList, struct TBuffer *pBuff)
{
	int op, Idx, i;
	char Flags = 0x00;
	char ret;
	struct TData p[127];
	do
	{
		system("cls");
		if (pList->pFirst)
		{
			printf("  Idx   Nome                                              Idade\n");
			Show(pList->pFirst);
			printf(" Quantidade de elementos na lista: %03d\n Quantidade de elementos disponiveis: %03d\n\n", LstSize(pList), pBuff->FreeAmount);
		}
		printf("Escolha uma opcao\n");
		printf("1: Adicionar um elemnto no inicio/final\n");
		printf("2: Adicionar um elemnto a partir de um Idx\n");
		printf("3: Remover um elemento\n");
		printf("4: Limpar lista\n");
		printf("5: Procurar nome\n");
		printf("0: Voltar\n");
		scanf("%d", &op);
		switch (op)
		{
		case 1:
		{
			do
			{
				printf("Digite 0 para inserir no inicio ou 1 para inserir no final: ");
				scanf("%d", &op);
			} while (op != 0 && op != 1);
			Flags = (op) ? 0x80 : 0x00;
			do
			{
				printf("Digite quantos elemento deseja inserir(entre 0 e 128): ");
				scanf("%d", &op);
			} while (op < 1 || op > 127);
			Flags |= op;
			for (i = 0; i < op; i++)
			{
				ReadInfo(&p[i]);
			}
			ret = LstAdd(pList, Flags, &p[0], &p[1], &p[2], &p[3], &p[4], &p[5], &p[6], &p[7], &p[8], &p[9], &p[10], &p[11], &p[12], &p[13], &p[14], &p[15], &p[16], &p[17], &p[18], &p[19], &p[20], &p[21], &p[22], &p[23], &p[24], &p[25], &p[26], &p[27], &p[28], &p[29], &p[30], &p[31], &p[32], &p[33], &p[34], &p[35], &p[36], &p[37], &p[38], &p[39], &p[40], &p[41], &p[42], &p[43], &p[44], &p[45], &p[46], &p[47], &p[48], &p[49], &p[50], &p[51], &p[52], &p[53], &p[54], &p[55], &p[56], &p[57], &p[58], &p[59], &p[60], &p[61], &p[62], &p[63], &p[64], &p[65], &p[66], &p[67], &p[68], &p[69], &p[70], &p[71], &p[72], &p[73], &p[74], &p[75], &p[76], &p[77], &p[78], &p[79], &p[80], &p[81], &p[82], &p[83], &p[84], &p[85], &p[86], &p[87], &p[88], &p[89], &p[90], &p[91], &p[92], &p[93], &p[94], &p[95], &p[96], &p[97], &p[98], &p[99], &p[100], &p[101], &p[102], &p[103], &p[104], &p[105], &p[106], &p[107], &p[108], &p[109], &p[110], &p[111], &p[112], &p[113], &p[114], &p[115], &p[116], &p[117], &p[118], &p[119], &p[120], &p[121], &p[122], &p[123], &p[124], &p[125], &p[126], &p[127]);
			if (ret != '1')
			{
				printf("Sem Espaco!\n");
				system("pause");
			}
			op = 1;
		}
		break;
		case 2:
		{
			do
			{
				printf("Digite 0 para inserir e incrementar ou 1 para inserir e decrementar: ");
				scanf("%d", &op);
			} while (op != 0 && op != 1);
			Flags = (op) ? 0x80 : 0x00;
			do
			{
				printf("Digite quantos elemento deseja inserir(entre 0 e 128): ");
				scanf("%d", &op);
			} while (op < 1 || op > 127);
			Flags |= op;
			for (i = 0; i < op; i++)
			{
				ReadInfo(&p[i]);
			}
			do
			{
				printf("Digite a parir que qual elemento deseja inserir: ");
				scanf("%d", &op);
			} while (op < 1 || op > pList->ListAmount);

			if (pList->pLast) pList->pLast->pNext = pBuff->pFirstFree;
			else Lst(pList, pBuff);
			ret = LstAddIdx(pList, op - 1, Flags, &p[0], &p[1], &p[2], &p[3], &p[4], &p[5], &p[6], &p[7], &p[8], &p[9], &p[10], &p[11], &p[12], &p[13], &p[14], &p[15], &p[16], &p[17], &p[18], &p[19], &p[20], &p[21], &p[22], &p[23], &p[24], &p[25], &p[26], &p[27], &p[28], &p[29], &p[30], &p[31], &p[32], &p[33], &p[34], &p[35], &p[36], &p[37], &p[38], &p[39], &p[40], &p[41], &p[42], &p[43], &p[44], &p[45], &p[46], &p[47], &p[48], &p[49], &p[50], &p[51], &p[52], &p[53], &p[54], &p[55], &p[56], &p[57], &p[58], &p[59], &p[60], &p[61], &p[62], &p[63], &p[64], &p[65], &p[66], &p[67], &p[68], &p[69], &p[70], &p[71], &p[72], &p[73], &p[74], &p[75], &p[76], &p[77], &p[78], &p[79], &p[80], &p[81], &p[82], &p[83], &p[84], &p[85], &p[86], &p[87], &p[88], &p[89], &p[90], &p[91], &p[92], &p[93], &p[94], &p[95], &p[96], &p[97], &p[98], &p[99], &p[100], &p[101], &p[102], &p[103], &p[104], &p[105], &p[106], &p[107], &p[108], &p[109], &p[110], &p[111], &p[112], &p[113], &p[114], &p[115], &p[116], &p[117], &p[118], &p[119], &p[120], &p[121], &p[122], &p[123], &p[124], &p[125], &p[126], &p[127]);
			if (ret != '1')
			{
				printf("Sem espaco!\n");
				system("pause");
			}
			op = 2;
		}
		break;
		case 3:
		{
			printf("Digite o Idx do elemento a ser removido: ");
			scanf("%d", &op);
			ret = LstDel(pList, op - 1);
			if (ret != '1')
			{
				printf("Elemento nao existe!\n");
				system("pause");
			}
			op = 3;
		}
		break;
		case 4: LstClear(pList);
		break;
		case 5:
		{
			char NameFind[50];
			printf("Digite o nome: ");
			cleanBuffer();
			gets(NameFind);
			strncat(NameFind, "                                                 ", 49 - strlen(NameFind));
			Idx = LstFind(pList, NameFind, Compare);
			if (Idx)
			{
				printf("Elemento encontrado\n");
				LstGet(pList, Idx - 1, &p[0]);
				printf("  Idx   Nome                                              Idade\n");
				printf("%c", ce);
				for (i = 0; i < 62; ++i)
				{
					if (i == 5 || i == 57)
					{
						printf("%c", mc);
						continue;
					}
					printf("%c", h);
				}
				printf("%c\n", cd);
				printf("%c %3d %c %s %c %2d %c\n", v, Idx, v, p[0].Name, v, p[0].Age, v);
				printf("%c", be);
				for (i = 0; i < 62; ++i)
				{
					if (i == 5 || i == 57)
					{
						printf("%c", mb);
						continue;
					}
					printf("%c", h);
				}
				printf("%c\n", bd);
			}
			else printf("Elemento nao encontrado!\n");
			system("pause");
		}
		break;
		}
	} while (op);
}

void Queue(struct TFifo *pFifo, struct TBuffer *pBuff)
{
	int op, i;
	char ret;
	struct TData p;
	do
	{
		system("cls");
		if (pFifo->pRemove)
		{
			printf("  Idx   Nome                                              Idade\n");
			Show(pFifo->pRemove);
			printf(" Quantidade de elementos na fila: %03d\n Quantidade de elementos disponiveis: %03d\n\n", pFifo->FifoAmount, pBuff->FreeAmount);
		}
		printf("Escolha uma opcao\n");
		printf("1: Adicionar um elemnto\n");
		printf("2: Remover um elemento\n");
		printf("3: Limpar Fila\n");
		printf("0: Voltar\n");
		scanf("%d", &op);
		switch (op)
		{
		case 1:
		{
			if (pFifo->pRemove) pFifo->pInsert->pNext = pBuff->pFirstFree;
			else Ffo(pFifo, pBuff);
			ReadInfo(&p);
			ret = FfoAdd(pFifo, &p);
			if (ret != '1')
			{
				printf("Sem Espaco!\n");
				system("pause");
			}
		}
		break;
		case 2:
		{
			ret = FfoGet(pFifo, &p);
			if (ret == '1')
			{
				printf("O Elemento removido foi\n", p.Name, p.Age);
				printf("  Idx   Nome                                              Idade\n");
				printf("%c", ce);
				for (i = 0; i < 62; ++i)
				{
					if (i == 5 || i == 57)
					{
						printf("%c", mc);
						continue;
					}
					printf("%c", h);
				}
				printf("%c\n", cd);
				printf("%c %3d %c %s %c %2d %c\n", v, 1, v, p.Name, v, p.Age, v);
				printf("%c", be);
				for (i = 0; i < 62; ++i)
				{
					if (i == 5 || i == 57)
					{
						printf("%c", mb);
						continue;
					}
					printf("%c", h);
				}
				printf("%c\n", bd);
			}
			else printf("Fila Vazia!\n");
			system("pause");
		}
		break;
		case 3: FfoClear(pFifo);
		break;
		}
	} while (op);
}

void Show(struct TElement *pItem)
{
	int i, j = 1;
	//First Line
	printf("%c", ce);
	for (i = 0; i < 62; ++i)
	{
		if (i == 5 || i == 57)
		{
			printf("%c", mc);
			continue;
		}
		printf("%c", h);
	}
	printf("%c\n", cd);

	while (pItem)
	{
		printf("%c %3d %c %s %c %2d %c\n", v, j++, v, pItem->Info.Name, v, pItem->Info.Age, v);
		pItem = pItem->pNext;
		if (pItem == NULL) continue;
		printf("%c", me);
		for (i = 0; i < 62; ++i)
		{
			if (i == 5 || i == 57)
			{
				printf("%c", m);
				continue;
			}
			printf("%c", h);
		}
		printf("%c\n", md);
	}
	//Last Line
	printf("%c", be);
	for (i = 0; i < 62; ++i)
	{
		if (i == 5 || i == 57)
		{
			printf("%c", mb);
			continue;
		}
		printf("%c", h);
	}
	printf("%c\n", bd);
}

void ReadInfo(struct TData *pData)
{
	printf("Digite o nome: ");
	cleanBuffer();
	gets(pData->Name);
	strncat(pData->Name, "                                                 ", 49 - strlen(pData->Name));
	printf("Digite a idade: ");
	scanf("%d", &pData->Age);
}

char Compare(void *pItem, void *pData)
{
	char *Name1 = pItem, *Name2 = pData;
	if (strcmp(Name1, Name2) == -1) return '<';
	else if (strcmp(Name1, Name2) == 1) return '>';
	else if (strcmp(Name1, Name2) == 0) return '=';
}
