#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#define PROM 8.00
main ()
{
system("color f0");
char x;
    printf("  Paises con switch\n");
    printf("  Omar Yosafat Cisneros Ruiz\n");
	printf("\n\tIntroducir caracter a, b, c: ");
	scanf("%c",&x);
	switch (x)
	{
		case 'a':
		printf("\t  Argentina");
		break;
		case 'b':
		printf("\t  Bolivia");
		break;
		case 'c': 
		printf("\t  chile");
		break;
		default:
		printf("\t  sin patria");
		
	}

getch();
      }
