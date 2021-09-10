//un corredor desea calcular su promedio en 5 dias de 5 kilometros

#include<stdio.h>
#include<conio.h>

int main()

{
float n1,n2,n3,n4,n5,prom;
printf("Introducir tiempo del dia 1: ");
scanf("%f",&n1);
printf("Introducir tiempo del dia 2: ");
scanf("%f",&n2);
printf("Introducir tiempo del dia 3: ");
scanf("%f",&n3);
printf("Introducir tiempo del dia 4: ");
scanf("%f",&n4);
printf("Introducir tiempo del dia 5: ");
scanf("%f",&n5);
prom=(n1+n2+n3+n4+n5)/5;
printf("\n promedio=%f",prom);
getche();
}
