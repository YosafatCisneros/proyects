//2. Leer tres números diferentes e imprimir el numero mayor de los tres.



#include<stdio.h>
#include<conio.h>

int main()
{
float n1,n2,n3,ma;
printf("Intruducir primer numero: ");
scanf("%f",&n1);
printf("Intruducir segundo numero: ");
scanf("%f",&n2);
printf("Intruducir tercer numero: ");
scanf("%f",&n3);
if((n1>n2)&&(n1>n3)) ma=n1;
else{
if((n2>n1)&&(n2>n3))ma=n2;
else ma=n3;}
printf("\n El numero mayor es: %f",ma,ma);
getche();
}
