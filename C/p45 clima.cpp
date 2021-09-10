//calcular el promedio de temperaturas al medio dia de un mes 30 dias
#include<stdio.h>
#include<conio.h>
int main()
{
float suma=0, prom;
int x, t;
for (x=1; x<=30; x++)
  {
    printf("temperatura del dia %d: " ,x);
    scanf("%d",&t);
    suma=suma+t;
  }
prom=suma/30;
printf("El promedio es: %f", prom);
getche();
}
