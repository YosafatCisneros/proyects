#include<stdio.h>
#include<conio.h>

int main()

{
float n1,n2;
printf("Insertar la cantidad de pesos a cambiar: \n");
scanf("%f",&n1);
printf("\n Insertar el precio de venta del dolar: \n");
scanf("%f",&n2);
printf("\n\n La cantidad de dolares con respecto a los pesos introducidos es: \n %f/%f=%f",n1,n2,n1/n2);
getche();
}
