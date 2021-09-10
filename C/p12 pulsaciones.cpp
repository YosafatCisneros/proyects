//calcular el numero de pulsaciones que una persona tiene durante su ejercicio aerobico, la formula es pulsa=(220-edad)/10

#include<stdio.h>
#include<conio.h>

int main()

{
float edad,pulsa;
printf("Introduce edad: ");
scanf("%f",&edad);
pulsa=(220-edad)/10;
printf("\n numero de pulsaciones=%f",pulsa);
getche();
}
