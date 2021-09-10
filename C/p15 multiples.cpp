//realizar un programa que solicita +-*/ raiz ^2 ^3 ^4

#include<stdio.h>
#include<conio.h>
#include<math.h>

int main()

{
float n1,n2,n3;
printf("Escribir primer valor: ");
scanf("%f",&n1);
printf("Escribir segundo valor: ");
scanf("%f",&n2);
printf("\n La suma de: %f+%f=%f",n1,n2,n1+n2);
printf("\n\n La resta de: %f-%f=%f",n1,n2,n1-n2);
printf("\n\n La multiplicacion de: %f*%f=%f",n1,n2,n1*n2);
printf("\n\n La division: de %f/%f=%f",n1,n2,n1/n2);
printf("\n\n La raiz de: %f=%f \n La raiz de: %f=%f",n1,sqrt(n1),n2,sqrt(n2));
printf("\n\n El cuadrado de: %f^2=%f, \n El cuadrado de: %f^2=%f ",n1,pow(n1,2),n2,pow(n2,2));
printf("\n\n La tercera de: %f^3=%f, \n La tercera de: %f^3=%f ",n1,pow(n1,3),n2,pow(n2,3));
printf("\n\n La cuarta de: %f^4=%f, \n La cuarta de: %f^4=%f ",n1,pow(n1,4),n2,pow(n2,4));

getche();
}
