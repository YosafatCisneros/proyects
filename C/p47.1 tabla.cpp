#include<stdio.h>
#include<conio.h>
int main()
{
int t, y, p;
printf("Escribir numero del que se desea tabla: ");
scanf("%d",&p);

for (y=1; y<11; y++)
printf("%dx%d=%d \n",p,y,p*y);
getche();
}
