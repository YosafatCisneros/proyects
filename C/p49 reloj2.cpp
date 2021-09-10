//reloj digital con pausa para que se ejecute segundo a segundo... system pausa, limpiar pantalla... GO TO XY
#include<stdio.h>
#include<conio.h>
#include <stdlib.h> 
#include <windows.h>
int main()
{
int h, m, s;
system("color 02");

for (h=0; h<24; h++)
for (m=0; m<60; m++)
for (s=0; s<60; s++)
{printf("\n\n\n\n\n\n\n\n\n\n                                   | %d:%d:%d | ",h,m,s);
Sleep(1000);
clrscr();}
getche();
}
