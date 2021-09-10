#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#define PROM 8.00
main ()
{
system("color f0");
char x;
    printf("  Paises con if anidado\n");
    printf("  Omar Yosafat Cisneros Ruiz\n");
	printf("\n\tIntroducir caracter a, b, c: ");
	scanf("%c",&x);
	if (x=='a')
	printf("\t  Argentina");
	else
	if(x=='b')
	printf("\t  Bolivia");
	else
	if(x=='c')
	printf("\t  chile");
	else
	printf("\t  sin patria");

getch();
      }
