//realizar un programa que simule un reloj digital
//sin salto de renglon
//pintar de color verde(matrix)
#include<stdio.h>
#include<conio.h>
#include <stdlib.h> 
int main()
{
int h, m, s;
system("color 02");
for (h=0; h<24; h++)
for (m=0; m<60; m++)
for (s=0; s<60; s++)
printf("%d:%d:%d ",h,m,s);
getche();
}

