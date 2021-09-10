#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
float c1;
int c;
printf("Intruducir monto de la compra: ");
scanf("%f",&c1);
 
 
srand(time(NULL));
c=rand()%100;
printf("Numero al azar: %d",c);
getche();
clrscr();
if(c>=74) printf("El precio total es de: %f*%f=%f",c1,c1*.8);
else printf("El precio total es de: %f*.85=%f",c1,c1*.85);
getche();
}
