//Calcular el total que una persona debe pagar en un llantera, si el precio de 
//cada llanta es de $900 si se compran menos de 4 llantas y de $700 si se compran 4 o mas.
                
#include<stdio.h>
#include<conio.h>

int main()
{
int l1;

printf("Intruducir cantidad de llantas a comprar: ");
scanf("%d",&l1);
if(l1>=4) printf("\nEl total a pagar es de: %d*700=%d",l1,l1*700);
else printf("\nEl total a pagar es de: %d*900=%d",l1,l1*900);
getche();
}
