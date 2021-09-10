//realizar programa que resuelva chicharronera y solicite los valores de a b y c

#include<stdio.h>
#include<conio.h>
#include<math.h>
int main()

{
float na, nb, nc, cuadrado, doble, cuatro;
printf("Escribir coeficiente de A: ");
scanf("%f",&na);
printf("Escribir coeficiente de B: ");
scanf("%f",&nb);
printf("Escribir coeficiente de C: ");
scanf("%f",&nc);

cuadrado=pow(nb,2);
doble=2*na;
cuatro=4*na*nc;

printf("\n El coeficiente de x usando raiz positiva: (-  %f  +  (%f  -  %f))/%f=%f",doble,cuatro,nb,cuadrado,(-nb+sqrt(cuadrado-cuatro))/doble);
printf("\n\nEl coeficiente de x usando raiz negativa: (-%f-(%f-%f))/%f=%f",doble,cuatro,nb,cuadrado,(-nb-sqrt(cuadrado-cuatro))/doble);


getche();
}
