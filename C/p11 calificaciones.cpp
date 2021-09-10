//se desea calcular el promedio de un alumno que tiene 3 materias
#include<stdio.h>
#include<conio.h>

int main()

{
float n1,n2,n3,prom;
printf("escribe la primera calificacion: ");
scanf("%f",&n1);
printf("escribe la segunda calificacion: ");
scanf("%f",&n2);
printf("escribe la tercera calificacion: ");
scanf("%f",&n3);
prom=(n1+n2+n3)/3;
printf("su promedio es: %f",prom);

getche();
}
