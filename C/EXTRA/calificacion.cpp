#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#define C 3
main ()
{
system("color f0");
float c1,c2,c3,p;
    printf("  Calificacion alumnos\n");
    printf("  Omar Yosafat Cisneros Ruiz\n");
	printf("\n\tIntroducir calificacion 1: ");
	scanf("%f",&c1);
	printf("\n\tIntroducir calificacion 2: ");
	scanf("%f",&c2);
	printf("\n\tIntroducir calificacion 3: ");
	scanf("%f",&c3);
	if((c1>=0&&c1<=10)&&(c2>=0&&c2<=10)&&(c3>=0&&c3<=10))
	{
	p=(c1+c2+c3)/C;
	printf("\n\t  Promedio= %f",p);
	if(p>=8)
	printf("\n\t  Exento");
	else
	if(p>=6)
	printf("\n\t  Aprobado\n");
	else
	printf("\n\t  Repetir curso");
    }
    else
    printf("Error en las calificaciones");
getch();
}
