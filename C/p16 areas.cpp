#include<stdio.h>
#include<conio.h>
#include<math.h>

int main()
{
int clave;
float na ,nb ,nc ,nh ,nr, pi;
pi=3.141592;
printf("Estos son los codigos que representan a cada figura: \n Cuadrado=0, Rectangulo=1, Triangulo=2, Circulo=3");
printf("\n\nNumero que representa a la figura deseada: ");
scanf("%d",&clave);
if(clave==0){
printf("\nEscribe la medida del lado del cuadrado: ");
scanf("%f",&na);
printf("\nEl area del cuadrado es de: %f^2=%f",na,pow(na,2));
printf("\nEl perimetro del cuadrado es de: %f*4=%f",na,na*4);}
else{
if(clave==1){
printf("\nEscribe la medida del lado mayor del rectangulo: ");
scanf("%f",&na);
printf("Escribe la medida del lado menor del rectangulo: ");
scanf("%f",&nb);
printf("\nEl area del rectangulo es de: %f*%f=%f",na,nb,na*nb);
printf("\nEl perimetro del rectangulo es de: (2*%f)+(2*%f)=%f",na,nb,(2*na)+(2*nb));}
else{
if(clave==2){
printf("\nEscribe la medida del lado 1 (base) del triangulo: ");
scanf("%f",&na);
printf("Escribe la medida del lado 2 del triangulo: ");
scanf("%f",&nb);
printf("Escribe la medida del lado 3 del triangulo: ");
scanf("%f",&nc);
printf("Escribe la medida de la altura del triangulo: ");
scanf("%f",&nh);
printf("\nEl area del triangulo es de: (%f*%f)/2=%f",na,nh,(na*nh)/2);
printf("\nEl perimetro del triangulo es de: %f+%f+%f=%f",na,nb,nc,na+nb+nc);}
else{ 
if(clave==3){
printf("\nEscribe la medida del radio del circulo: ");
scanf("%f",&nr);
printf("\nEl area del circulo es de: %f*%f^2=%f",pi,nr,pi*pow(nr,2));
printf("\nEl perimetro del circulo es de: %f*%f*2=%f",pi,nr,pi*nr*2);}
else{printf("\nActualmente no hay datos para este codigo");}}}}
getche();
}
