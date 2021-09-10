//relog digital e imprimir la ultima hora minuto y seg e imprimir el total de seg que tiene un dia
#include<stdio.h>
#include<conio.h>
int main()
{
int h, m, s, suma=0;
for (h=0; h<23; h++)
for (m=0; m<59; m++)
for (s=0; s<59; s++)
{printf("%d:%d:%d ",h,m,s);
suma=suma+1;}
printf("\n%d:%d:%d ",h,m,s);
printf("Total de seg:%d ",suma);
getche();
}
