//1. Leer 2 números; si son iguales que los multiplique, si el primero es mayor que el segundo que los reste y si no que los sume.



#include<stdio.h>
#include<conio.h>

int main()
{
float n1,n2;
printf("Intruducir primer numero: ");
scanf("%f",&n1);
printf("Intruducir segundo numero: ");
scanf("%f",&n2);
if(n1==n2) printf("\n\n La multiplicacion de: %f*%f=%f",n1,n2,n1*n2);
else{
if (n1>n2) printf("\n\n La resta de: %f-%f=%f",n1,n2,n1-n2);
else printf("\n\n La suma de: %f+%f=%f",n1,n2,n1+n2);}
getche();
}
