/*En un arreglo unidimensional se almacenan las calificaciones obtenidas por un grupo de diez alumnos en un examen 
Cada calificación es un número enero entre 0 y 5. Escribe un programa que calcule, almacene e imprima la frecuencia de cada una de las calificaciones 
y que además obtenga e imprima la frecuencia más alta. Si hubiera calificaciones con la misma frecuencia debe obtener la primera ocurrencia.*/
#include <stdio.h>
#include <conio.h>
#define T 10
#define P 6
int main ()
{
  int x,a,y,cal[T],ar[P];
  for(x=0,a=1;x<10;x++,a++)
     {
     printf ("Calificacion #%d: ",a);
     scanf ("%d",&cal[a]);
     switch(cal[a])
        {
        case 0:
        ar[0]+=1;
        break;
        case 1:
        ar[1]+=1;
        break;
        case 2:
        ar[2]+=1;
        break;
        case 3:
        ar[3]+=1;
        break;
        case 4:
        ar[4]+=1;
        break;
        case 5:
        ar[5]+=1;
        break;
        }
     }
  do
  {
  
  }
  while(cal[x]!=5);
  printf ("");
  getch();
}

