#include<stdio.h>
#include<conio.h>
#include<math.h>

//x=(-b+- raiz de b^2-4ac)/2a

int main()

{
float na, nb, nc, y;
printf("Escribir coeficiente de A: ");
scanf("%f",&na);
printf("Escribir coeficiente de B: ");
scanf("%f",&nb);
printf("Escribir coeficiente de C: ");
scanf("%f",&nc);

y=sqrt((nb*nb)-4*(na*nc));

printf("\n El coeficiente de x1: (%f+%f)/%f=%f",y,nb,na,(-nb+y)/2*na);
printf("\n El coeficiente de x2: (%f+%f)/%f=%f",y,nb,na,(-nb-y)/2*na);


getche();
}
