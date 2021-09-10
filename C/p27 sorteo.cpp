//En un supermercado se hace una promoción, mediante la cual el cliente obtiene un descuento
//dependiendo de un numero que se escoge al azar. Si el numero escogido es menor que 74 el descuento es del 15% 
//sobre el total de la compra, si es mayor o igual a 74 el descuento es del 20%. Obtener cuanto dinero se le descuenta. 
#include<stdio.h>
#include<conio.h>

int main()
{
float c1, s1;

printf("Intruducir monto de la compra: ");
scanf("%f",&c1);
printf("Intruducir numero del sorteo: ");
scanf("%f",&s1);
if(s1>=74) printf("\nEl precio total es de: %f*.8=%f",c1,c1*.8);
else printf("\nEl precio total es de: %f*.85=%f",c1,c1*.85);
getche();
}
