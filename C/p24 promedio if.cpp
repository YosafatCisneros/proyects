//Determinar si un alumno aprueba a reprueba un curso, sabiendo que aprobara si 
//su promedio de tres calificaciones es mayor o igual a 70; reprueba en caso contrario. 
#include<stdio.h>
#include<conio.h>

int main()
{
float c1,c2,c3,prom;

printf("Intruducir primera calificacion: ");
scanf("%f",&c1);
printf("Intruducir segunda calificacion: ");
scanf("%f",&c2);
printf("Intruducir tercera calificacion: ");
scanf("%f",&c3);
prom=(c1+c2+c3)/3;
if(prom>=70) printf("\nAlumno aprobado");
else printf("\nAlumno reprobado");
getche();
}
