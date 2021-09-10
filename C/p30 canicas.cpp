//un centro comercial realiza su venta anual la cual consiste en un descuento sobre el total
//el descuento depende del color de la canica que el cliente obtenga
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
