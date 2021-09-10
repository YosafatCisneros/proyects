//realizar programa que imprima 2, 3 y 4 potencia de 3 numeros, lo incremente en uno 30 veces
#include<stdio.h>
#include<conio.h>
#include <stdlib.h> 
#include <math.h>
int main()
{
int a, b, c;

for (a=1; a<11; a++) 
 for (b=1; b<11; b++) 
  for (c=1; c<11; c++)
 {printf("Escribir coeficiente de A: ");
scanf("%d",&a);
printf("Escribir coeficiente de B: ");
scanf("%d",&b);
printf("Escribir coeficiente de C: ");
scanf("%d",&c);
printf("\tA^2\tB^3\tC^4:\t%d\t%d\t%d\n",a,b,c,pow(a,2),pow(b,3),pow(c,4));}
getche();
}
