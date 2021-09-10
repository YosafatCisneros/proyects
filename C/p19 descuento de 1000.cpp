//un centro comercial realiza su venta anual otorgando 40% de descuento si la compra es mayor a 1000

#include<stdio.h>
#include<conio.h>

int main()
{
float m;
printf("Monto de la compra: ");
scanf("%f",&m);
if(m>1000) printf("\ntotal a pagar %f",m*.6);
else printf("\ntotal a pagar %f",m );
getche();
}
