#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

void showwin()
{
	system("cls");
	printf("\n\n\n\n                   oooooo   oooo                       ");
    printf("\n                   `888.   .8'                        ");
    printf("\n                    `888. .8'    .ooooo.  oooo  oooo  ");
    printf("\n                     `888.8'    d88' `88b `888  `888  ");
    printf("\n                      `888'     888   888  888   888  ");
    printf("\n                       888      888   888  888   888  ");
    printf("\n                      o888o     `Y8bod8P'  `V88V\"V8P' ");
    printf("\n");
    printf("\n              oooooo   oooooo     oooo  o8o              ");
    printf("\n               `888.    `888.     .8'   `\"'              ");
    printf("\n                `888.   .8888.   .8'   oooo  ooo. .oo.   ");
    printf("\n                 `888  .8'`888. .8'    `888  `888P\"Y88b  ");
    printf("\n                  `888.8'  `888.8'      888   888   888  ");
    printf("\n                   `888'    `888'       888   888   888  ");
    printf("\n                    `8'      `8'       o888o o888o o888o");

}
void showlose()
{
	system("cls");
	printf("\n\n\n\n             .oooooo.                                          ");
    printf("\n           d8P'  `Y8b                                         ");
    printf("\n          888            .oooo.   ooo. .oo.  .oo.    .ooooo.  ");
    printf("\n          888           `P  )88b  `888P\"Y88bP\"Y88b  d88' `88b ");
    printf("\n          888     ooooo  .oP\"888   888   888   888  888ooo888 ");
    printf("\n          `88.    .88'  d8(  888   888   888   888  888    .o ");
    printf("\n           `Y8bood8P'   `Y888\"\"8o o888o o888o o888o `Y8bod8P' ");
    printf("\n");
    printf("\n                .oooooo.                                  ");
    printf("\n               d8P'  `Y8b                                 ");
    printf("\n              888      888 oooo    ooo  .ooooo.  oooo d8b ");
    printf("\n              888      888  `88.  .8'  d88' `88b `888""8P ");
    printf("\n              888      888   `88..8'   888ooo888  888     ");
    printf("\n              `88b    d88'    `888'    888    .o  888     ");
    printf("\n               `Y8bood8P'      `8'     `Y8bod8P' d888b    ");

}
int main(void)
{
	int op;
	do
	{
		system("cls");
		system("color 07");
		char *test;
		char l, win = 1, word[21], error[7] = { ' ', ' ', ' ', ' ', ' ', ' ' };
		int i, size, life = 6, count = 0, present;
		do
		{
			printf("Digite uma palavra entre 4 e 20 letras: ");
			gets(word);
			size = strlen(word);
		}
		while(size < 4 || size > 20);
		test = malloc ((size+1) * sizeof(char));
		strcpy(test, "_");
		for(i=0; i<size-1; ++i)
			strcat(test, "_");
		for (i = 0; i < size; ++i)
			word[i] = toupper(word[i]);
		do
		{
			system("cls");
			printf("====================================\nVidas: ");
			for (i = 0; i < life; ++i)
				printf("%c", 3);
			switch(life)
			{
				case 0:
				{
					printf("\n %c%c%c%c", 218,196,196,191);
					printf("\n %c  %c", 179, 1);
					printf("\n %c %c%c%c", 179,192, 197, 217);
					printf("      %s", test);
					printf("\n %c %c%c%c", 179,218, 193, 191);
					printf("     %c", '[');
					for (i = 0; i < count; ++i)
						printf("%c", error[i]);
					printf("%c", ']');
					printf("\n %c   ",193);
				}
				break;
				case 1:
				{
					printf("\n %c%c%c%c", 218,196,196,191);
					printf("\n %c  %c  ", 179, 1);
					printf("\n %c %c%c%c", 179,192, 197, 217);
					printf("  %s", test);
					printf("\n %c %c%c", 179,218, 217);
					printf("  %c", '[');
					for (i = 0; i < count; ++i)
						printf("%c", error[i]);
					printf("%c", ']');
					printf("\n %c   ",193);
				}
				break;
				case 2:
				{
					printf("\n %c%c%c%c", 218,196,196,191);
					printf("\n %c  %c  ", 179, 1);
					printf("\n %c %c%c%c", 179,192, 197, 217);
					printf("  %s", test);
					printf("\n %c", 179);
					printf("     %c", '[');
					for (i = 0; i < count; ++i)
						printf("%c", error[i]);
					printf("%c", ']');
					printf("\n %c   ",193);
				}
				break;
				case 3:
				{
					printf("\n %c%c%c%c", 218,196,196,191);
					printf("\n %c  %c  ", 179, 1);
					printf("\n %c %c%c", 179,192, 180);
					printf("   %s", test);
					printf("\n %c", 179);
					printf("     %c", '[');
					for (i = 0; i < count; ++i)
						printf("%c", error[i]);
					printf("%c", ']');
					printf("\n %c   ",193);
				}
				break;
				case 4:
				{
					printf("\n %c%c%c%c", 218,196,196,191);
					printf("\n %c  %c  ", 179, 1);
					printf("\n %c  %c", 179, 179);
					printf("   %s", test);
					printf("\n %c", 179);
					printf("     %c", '[');
					for (i = 0; i < count; ++i)
						printf("%c", error[i]);
					printf("%c", ']');
					printf("\n %c   ",193);
				}
				break;
				case 5:
				{
					printf("\n %c%c%c%c", 218,196,196,191);
					printf("\n %c  %c  ", 179, 1);
					printf("\n %c", 179);
					printf("      %s", test);
					printf("\n %c", 179);
					printf("     %c", '[');
					for (i = 0; i < count; ++i)
						printf("%c", error[i]);
					printf("%c", ']');
					printf("\n %c",193);
				}
				break;
				case 6:
				{
					printf("\n %c%c%c%c", 218,196,196,191);
					printf("\n %c", 179);
					printf("\n %c", 179);
					printf("      %s", test);
					printf("\n %c", 179);
					printf("     %c", '[');
					for (i = 0; i < count; ++i)
						printf("%c", error[i]);
					printf("%c", ']');
					printf("\n %c",193);
				}
			}
			printf("\n\n %c%c%c%c Chute uma letra: ",196,196,196,16);
			present = 0;
			win = 1;
			l = toupper(getch());
			for (i = 0; i < size; ++i)
			{
				if(l==word[i])
				{
					test[i] = l;
					present = 1;
				}
				if(l==error[i])
					present = 1;
			}
			if (present == 0)
			{
				life--;
				error[count] = l;
				count++;
			}
			for (i = 0; i < size; ++i)
			{
				if (test[i] != word[i])
					win = 0;
			}
		}
		while(life > 0 && win == 0);
		if (life == 0)
		{
			for(i = 0; i < 3; i++)
			{
				system("color c0");
				showlose();
				Sleep(1000);
				system("color 0c");
				Sleep(1000);
			}
		}
		else
		{
			for(i = 0; i < 3; i++)
			{
				system("color 70");
				showwin();
				Sleep(1000);
				system("color 0E");
				showwin();
				Sleep(1000);
			}
		}
		system("cls");
		unsigned char seta;
		system("color 07");
		printf("Mova com as seta direcionais e precione enter na opcao desejada\n\n %c%c%c Jogar Novamente\n     Sair",196,196,16);
		op = 1;
		do
		{
			seta = getch();
			if (seta == 0xE0)
			{
				seta = getch();
				if (seta == 'P') // down
				{
					system("cls");
					printf("Mova com as seta direcionais e precione enter na opcao desejada\n\n     Jogar Novamente\n %c%c%c Sair",196,196,16);
					op = 0;
				}
				if (seta == 'H') //up
				{
					system("cls");
					printf("Mova com as seta direcionais e precione enter na opcao desejada\n\n %c%c%c Jogar Novamente\n     Sair",196,196,16);
					op = 1;
				}
			}
		}while(seta != 0x0D);
		free(test);
	}
	while(op != 0);
	return 0;
}
