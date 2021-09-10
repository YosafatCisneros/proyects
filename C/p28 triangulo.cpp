//realizar un programa que solisite y determine de que tipo de triangulo se trata
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
