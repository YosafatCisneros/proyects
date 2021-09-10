//imprimir en pantalla si el alumno aprueba o reprueba la calificacion debe ser igual o mayor a 8

#include<stdio.h>
#include<conio.h>

int main()
{
int cal;
printf("\n\nCalificacion del alumno: ");
scanf("%d",&cal);
if(cal>7) printf("\nAPROBADO");
else printf("\nREPROBADO");
getche();
}
