//Hacer un programa que calcule el total a pagar por la compra de camisas. 
//Si se compran tres camisas o mas se aplica un descuento del 20%  sobre el total 
//de la compra y si son menos de tres camisas un descuento del 10%.
 
#include<stdio.h>
#include<conio.h>

int main()
{
int c1;
float p1,tot;
printf("Intruducir cantidad de camisas a comprar: ");
scanf("%d",&c1);
printf("Intruducir precio de las camisas: ");
scanf("%f",&p1);
tot=c1*p1;
if(c1>=3) printf("\nEl total a pagar es de: %f*.8=%f",tot,tot*.8);
else printf("\nEl total a pagar es de: %f*.9=%f",tot,tot*.9);
getche();
}
