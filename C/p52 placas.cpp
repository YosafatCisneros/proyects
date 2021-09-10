//realizar un programa que haga el total de convinaciones de placas de autos particulares del gob del df y el numero (variable doble)
#include<stdio.h>
#include<conio.h>
#include <stdlib.h> 
int main()
{
int h, m, s, suma=0; 
char a, b, c;
for (h=0; h<10; h++)
for (m=0; m<10; m++)
for (s=0; s<10; s++)
for (a='A'; a<='Y'; a++)
for (b='A'; b<='Y'; b++)
for (c='A'; c<='Y'; c++)
{printf("%d%d%d-%c%c%c ",h,m,s,a,b,c);
suma=suma+1;}
printf("%d%d%d-%c%c%c ",h,m,s,a,b,c);
printf("\nTotal de placas:%d ",suma);
getche();
}
