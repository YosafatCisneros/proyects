//reloj digital con salto de renglon
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
printf("\n%d:%d:%d ",h,m,s);
getche();
}
