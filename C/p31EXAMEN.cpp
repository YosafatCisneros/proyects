#include<stdio.h>
#include<conio.h>
int main()
{
int r1;
float suma=0;
printf("PREGUNTA NUMERO UNO: \nLa suma de 2+2=");
printf("\n\nRespuesta 1: 3");
printf("\nRespuesta 2: 1");
printf("\nRespuesta 3: 4");
printf("\nRespuesta 4: 100");
printf("\n\nIntruducir numero de la respuesta: ");
scanf("%d",&r1);
if(r1==3)
{printf("\ncorrecto");   
suma=suma+2.5;}
else printf("\nincorrecto");
getche();
clrscr();
printf("PREGUNTA NUMERO DOS: \nAño que se transmitio el primer capitulo de pokemon: ");
printf("\n\nRespuesta 1: 1996");
printf("\nRespuesta 2: 2004");
printf("\nRespuesta 3: 200");
printf("\nRespuesta 4: 2014");
printf("\n\nIntruducir numero de la respuesta: ");
scanf("%d",&r1);
if(r1==1)
{printf("\ncorrecto");   
suma=suma+2.5;}
else printf("\nincorrecto");
getche();
clrscr();
printf("PREGUNTA NUMERO TRES: \nAño que se creo jarabe de palo:");
printf("\n\nRespuesta 1: 1890");
printf("\nRespuesta 2: 1996");
printf("\nRespuesta 3: 2000");
printf("\nRespuesta 4: 1999");
printf("\n\nIntruducir numero de la respuesta: ");
scanf("%d",&r1);
if(r1==2)
{printf("\ncorrecto");   
suma=suma+2.5;}
else printf("\nincorrecto");
getche();
clrscr();
printf("PREGUNTA NUMERO CUATRO: \n¿A los cuantos años de casarnos tuvimos un sirenito?");
printf("\n\nRespuesta 1: justo al año de casarnos");
printf("\nRespuesta 2: no se");
printf("\nRespuesta 3: ¿a el mes?");
printf("\nRespuesta 4: me doy");
printf("\n\nIntruducir numero de la respuesta: ");
scanf("%d",&r1);
if(r1==1)
{printf("\ncorrecto");   
suma=suma+2.5;}
else printf("\nincorrecto");
getche();
clrscr();
printf("la calificacion es de: %f",suma);
getche();
}
