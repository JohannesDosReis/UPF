#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

char *GPS(int x, ...);

int main(void)
{
	double LA, LO, SP;
	int AL, HD;
	char *pGPS;
	printf("Latitude: ");
	scanf("%lf", &LA);
	printf("Longitude: ");
	scanf("%lf", &LO);
	printf("Altitude: ");
	scanf("%d", &AL);
	printf("Velocidade: ");
	scanf("%lf", &SP);
	printf("Direcao: ");
	scanf("%d", &HD);
	pGPS = GPS(5, LA, LO, AL, SP, HD);
	printf("%s\n", pGPS);
	free(pGPS);
	return 0;
}

char *GPS(int x,...)
{
	char *gps;
	char temp[100];
	va_list ap;
	double la, lo, sp;
	int al, hd;
	va_start(ap,x);
	la = va_arg(ap, double);
	lo = va_arg(ap, double);
	al = va_arg(ap, int);
	sp = va_arg(ap, double);
	hd = va_arg(ap, int);
	va_end(ap);
	if (la <= -30.0 || la >= -20.0)
	{
		printf("Parametro invalido1");
		exit(1);
	}
	if (lo <= -60.0 || lo >= -40.0)
	{
		printf("Parametro invalido2");
		exit(1);
	}
	if (al <= 0 || al >= 2500)
	{
		printf("Parametro invalido3");
		exit(1);
	}
	if (sp <= 0.0 || sp >= 250.0)
	{
		printf("Parametro invalido4");
		exit(1);
	} if (hd <= 0 || hd >= 359)
	{
		printf("Parametro invalido6");
		exit(1);
	}
	sprintf(temp, "GPS:%7.4f,%7.4f,%04d,%3.0fKT,%03dM\n     ^LA      ^LO     ^AL  ^SP   ^HD", la, lo, al, sp, hd);
	int size;
	size = strlen(temp);
	gps = malloc(size*sizeof(*gps)+1);
	strcpy(gps,temp);
	return gps;
}



/*
Exercicio 15:

Faça uma função que recebe parametros variaveis de acordo com uma string:
LA = latitude (double entre -20 e -30)
LO = longitude (double entre -40 e -60)
AL = altitude (inteiro entre 0 e 2500)
SP = velocidade (double entre 0 e 250)
HD = direção (inteiro entre 0 e 359)

Caso os parametros estejam validos, retorna um ponteiro alocado em memoria com a seguinte string:
"GPS:-21.2324,-44.9962,960,120KT,227M"
      ^LA      ^LO     ^AL ^SP   ^HD*/
