//realizar un programa que realice en pantalla las 6 funciones trigonometricas en columnas con 4 decimales y en grados
#include<stdio.h>
#include<conio.h>
#include <math.h> 
int main()
{

double int f,s,c,t,ct,sc,cs;
for(f=0;f<361;f++)
{s=sin(f);
c=cos(f);
t=tan(f);
ct=1/t;
sc=1/c;
cs=1/s;
}

getche();
}

printf("seno%d=%0.4f",f,sin(f));
printf("\tcoseno%d=%0.4f",f,cos(f));
printf("\ttangente%d=%0.4f\n",f,tan(f));
