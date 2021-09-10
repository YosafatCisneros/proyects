//programa que solicite 2 numeros y los imprima en forma asendente
#include<stdio.h>
#include<conio.h>

int main()
{
int n1,n2;
printf("\n\nNumero 1: ");
scanf("%d",&n1);
printf("\n\nNumero 2: ");
scanf("%d",&n2);
if(n1<n2) printf("\n%d menor %d",n1,n2);
else printf("\n%d mayor %d", n1,n2);
getche();
}
