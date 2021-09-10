#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#define PROM 8.00
main ()
{
system("color f0");
int x;
    printf("  Colegiatura\n");
    printf("  Omar Yosafat Cisneros Ruiz\n");
	printf("\n\tHora de la comida:");
	scanf("%d",&x);
	if((x>=7)&&(x<=10))
	printf("\t  Desayuno");
	else
	if((x>=14)&&(x<=17))
	printf("\t  comida");
	else
	if((x>=20)&&(x<=22))
	printf("\t  cena");
	else
	printf("\t  sin alimento");
	getch();

getch();
      }
