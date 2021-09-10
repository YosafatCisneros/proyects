/*Realizar un programa que haga un examen de 20 preguntas
1)cada pregunta 4 posibles respuestas
2)limpiar la pantalla en cada pregunta
3)imprimir calificacion al final
4)color al fondo
5)imprimir preguntas con color diferente al fondo
6)cultura general
7)no se aceptan que la respuesta sea la misma */
#include <stdlib.h> 
#include<stdio.h>
#include<conio.h>
int main()
{
int r1;
char continuar;
float suma=0; 
do{
system("color 80");
printf("PREGUNTA 1: \n¿Qué es Excel? ");
printf("\n\nRespuesta 1:Renacimiento");
printf("\nRespuesta 2:Gotico");
printf("\nRespuesta 3:Romantico");
printf("\nRespuesta 4:barroco");
printf("\n\nIntruducir numero de la respuesta: ");
scanf("%d",&r1);
if(r1==1)
{printf("\ncorrecto");   
suma=suma+.5;}
else printf("\nincorrecto");
getche();
clrscr();
system("color 80");
printf("PREGUNTA 2: \nCual de los siguientes autores no pertenece al Siglo de Oro?");
printf("\n\nRespuesta 1:Moratin ");
printf("\nRespuesta 2:Gongora ");
printf("\nRespuesta 3:Quevedo ");
printf("\nRespuesta 4:Lope de Vega ");
printf("\n\nIntruducir numero de la respuesta: ");
scanf("%d",&r1);
if(r1==1)
{printf("\ncorrecto");   
suma=suma+.5;}
else printf("\nincorrecto");
getche();
clrscr();
system("color 80");
printf("PREGUNTA 3: \nEl gentilicio de la provincia de Tarragona:");
printf("\n\nRespuesta 1:Tarragoniano ");
printf("\nRespuesta 2:Tarragonano ");
printf("\nRespuesta 3:Tarraconense ");
printf("\nRespuesta 4:Tarragonino ");
printf("\n\nIntruducir numero de la respuesta: ");
scanf("%d",&r1);
if(r1==3)
{printf("\ncorrecto");   
suma=suma+.5;}
else printf("\nincorrecto");
getche();
clrscr();
system("color 80");
printf("PREGUNTA 4: \nCuando se instauro la dinastia Borbon en España?");
printf("\n\nRespuesta 1:Tras la muerte de Felipe V ");
printf("\nRespuesta 2:Tras la muerte de Fernando VII");
printf("\nRespuesta 3:Tras la muerte de Carlos II de Austria ");
printf("\nRespuesta 4:Tras la muerte de Carlos V");
printf("\n\nIntruducir numero de la respuesta: ");
scanf("%d",&r1);
if(r1==3)
{printf("\ncorrecto");   
suma=suma+.5;}
else printf("\nincorrecto");
getche();
clrscr();
system("color 80");
printf("PREGUNTA 5: \nCuantos dias tiene un año bisiesto?");
printf("\n\nRespuesta 1:365 ");
printf("\nRespuesta 2:364");
printf("\nRespuesta 3:367");
printf("\nRespuesta 4:366");
printf("\n\nIntruducir numero de la respuesta: ");
scanf("%d",&r1);
if(r1==4)
{printf("\ncorrecto");   
suma=suma+.5;}
else printf("\nincorrecto");
getche();
clrscr();
system("color 80");
printf("PREGUNTA 6: \nDonde se encuentra el Templo de Zeus?");
printf("\n\nRespuesta 1:Grecia ");
printf("\nRespuesta 2:Francia ");
printf("\nRespuesta 3:Belgica ");
printf("\nRespuesta 4:Italia ");
printf("\n\nIntruducir numero de la respuesta: ");
scanf("%d",&r1);
if(r1==1)
{printf("\ncorrecto");   
suma=suma+.5;}
else printf("\nincorrecto");
getche();
clrscr();
system("color 80");
printf("PREGUNTA 7: \nQuien escribio Blancanieves y los siete enanos?");
printf("\n\nRespuesta 1:Los hermanos Rincon ");
printf("\nRespuesta 2:Los hermanos Wright");
printf("\nRespuesta 3:Los hermanos Grimm ");
printf("\nRespuesta 4:Los hermanos Mario");
printf("\n\nIntruducir numero de la respuesta: ");
scanf("%d",&r1);
if(r1==3)
{printf("\ncorrecto");   
suma=suma+.5;}
else printf("\nincorrecto");
getche();
clrscr();
system("color 80");
printf("PREGUNTA 8: \nEl rio mas largo de la Peninsula Iberica es:");
printf("\n\nRespuesta 1:Guadalquivir");
printf("\nRespuesta 2:Guadina ");
printf("\nRespuesta 3:Duero ");
printf("\nRespuesta 4:Tajo ");
printf("\n\nIntruducir numero de la respuesta: ");
scanf("%d",&r1);
if(r1==4)
{printf("\ncorrecto");   
suma=suma+.5;}
else printf("\nincorrecto");
getche();
clrscr();
system("color 80");
printf("PREGUNTA 9: \nLa capital de Ecuador es:");
printf("\n\nRespuesta 1:Guatemala ");
printf("\nRespuesta 2:Quito ");
printf("\nRespuesta 3:Santiago ");
printf("\nRespuesta 4:Bogota ");
printf("\n\nIntruducir numero de la respuesta: ");
scanf("%d",&r1);
if(r1==2)
{printf("\ncorrecto");   
suma=suma+.5;}
else printf("\nincorrecto");
getche();
clrscr();
system("color 80");
printf("PREGUNTA 10: \nComo se denomina a los objetos que dejan pasar la luz pero que no se puede ver a traves de ellos?");
printf("\n\nRespuesta 1:Traslucido ");
printf("\nRespuesta 2:Transparente ");
printf("\nRespuesta 3:Refractante ");
printf("\nRespuesta 4:Opaco ");
printf("\n\nIntruducir numero de la respuesta: ");
scanf("%d",&r1);
if(r1==1)
{printf("\ncorrecto");   
suma=suma+.5;}
else printf("\nincorrecto");
getche();
clrscr();
system("color 80");
printf("PREGUNTA 11: \nCuantos grados tiene un angulo llano?");
printf("\n\nRespuesta 1:45 ");
printf("\nRespuesta 2:120 ");
printf("\nRespuesta 3:90 ");
printf("\nRespuesta 4:180 ");
printf("\n\nIntruducir numero de la respuesta: ");
scanf("%d",&r1);
if(r1==4)
{printf("\ncorrecto");   
suma=suma+.5;}
else printf("\nincorrecto");
getche();
clrscr();
system("color 80");
printf("PREGUNTA 12: \nCual de las siguientes palabras es compuesta?");
printf("\n\nRespuesta 1:Ventanal ");
printf("\nRespuesta 2:Monedero ");
printf("\nRespuesta 3:Cochera ");
printf("\nRespuesta 4:Abrecartas ");
printf("\n\nIntruducir numero de la respuesta: ");
scanf("%d",&r1);
if(r1==4)
{printf("\ncorrecto");   
suma=suma+.5;}
else printf("\nincorrecto");
getche();
clrscr();
system("color 80");
printf("PREGUNTA 13: \nComo se llama la forma de gobierno cuyo Jefe de Estado es un Rey?");
printf("\n\nRespuesta 1:Monarquia ");
printf("\nRespuesta 2:Republica ");
printf("\nRespuesta 3:Dictadura ");
printf("\nRespuesta 4:No existe ");
printf("\n\nIntruducir numero de la respuesta: ");
scanf("%d",&r1);
if(r1==1)
{printf("\ncorrecto");   
suma=suma+.5;}
else printf("\nincorrecto");
getche();
clrscr();
system("color 80");
printf("PREGUNTA 14: \nEn que etapa de la historia se situa el Feudalismo?");
printf("\n\nRespuesta 1:Edad moderna");
printf("\nRespuesta 2:Edad antigua");
printf("\nRespuesta 3:Edad media");
printf("\nRespuesta 4:Edad contemporanea");
printf("\n\nIntruducir numero de la respuesta: ");
scanf("%d",&r1);
if(r1==3)
{printf("\ncorrecto");   
suma=suma+.5;}
else printf("\nincorrecto");
getche();
clrscr();
system("color 80");
printf("PREGUNTA 15: \nQue sustancia se encuentra en el interior de un termometro?");
printf("\n\nRespuesta 1:Agua con gas ");
printf("\nRespuesta 2:Mercurio");
printf("\nRespuesta 3:Agua ");
printf("\nRespuesta 4:Anticongelante ");
printf("\n\nIntruducir numero de la respuesta: ");
scanf("%d",&r1);
if(r1==2)
{printf("\ncorrecto");   
suma=suma+.5;}
else printf("\nincorrecto");
getche();
clrscr();
system("color 80");
printf("PREGUNTA 16: \nEl planeta Tierra se sitúa entre:");
printf("\n\nRespuesta 1:Marte y Mercurio ");
printf("\nRespuesta 2:Mercurio y Venus ");
printf("\nRespuesta 3:Marte y Jupiter ");
printf("\nRespuesta 4:Venus y Marte ");
printf("\n\nIntruducir numero de la respuesta: ");
scanf("%d",&r1);
if(r1==4)
{printf("\ncorrecto");   
suma=suma+.5;}
else printf("\nincorrecto");
getche();
clrscr();
system("color 80");
printf("PREGUNTA 17: \nComo se representa el número 2993 en numeros romanos?");
printf("\n\nRespuesta 1:MCMXCIII ");
printf("\nRespuesta 2:MMCMXCIII ");
printf("\nRespuesta 3:MMMXCIII ");
printf("\nRespuesta 4:MMMCMXCIII ");
printf("\n\nIntruducir numero de la respuesta: ");
scanf("%d",&r1);
if(r1==2)
{printf("\ncorrecto");   
suma=suma+.5;}
else printf("\nincorrecto");
getche();
clrscr();
system("color 80");
printf("PREGUNTA 18: \nQue es un zar?");
printf("\n\nRespuesta 1:Un animal ");
printf("\nRespuesta 2:Una planta ");
printf("\nRespuesta 3:Una estructura ");
printf("\nRespuesta 4:Un emperador ");
printf("\n\nIntruducir numero de la respuesta: ");
scanf("%d",&r1);
if(r1==4)
{printf("\ncorrecto");   
suma=suma+.5;}
else printf("\nincorrecto");
getche();
clrscr();
system("color 80");
printf("PREGUNTA 19: \nCual de las siguientes palabras deberia de llevar tilde segun las reglas ortograficas?");
printf("\n\nRespuesta 1:Toner ");
printf("\nRespuesta 2:Capaz ");
printf("\nRespuesta 3:Surgir ");
printf("\nRespuesta 4:Programar ");
printf("\n\nIntruducir numero de la respuesta: ");
scanf("%d",&r1);
if(r1==1)
{printf("\ncorrecto");   
suma=suma+.5;}
else printf("\nincorrecto");
getche();
clrscr();
system("color 80");
printf("PREGUNTA 20: \nQuien escribio Fuenteovejuna?");
printf("\n\nRespuesta 1:Lope de Vega ");
printf("\nRespuesta 2:Miguel Delibes ");
printf("\nRespuesta 3:Antonio Machado ");
printf("\nRespuesta 4:Gustavo Adolfo Bécquer ");
printf("\n\nIntruducir numero de la respuesta: ");
scanf("%d",&r1);
if(r1==1)
{printf("\ncorrecto");   
suma=suma+.5;}
else printf("\nincorrecto");
getche();
clrscr();
system("color 80");
printf("la calificacion es de: %f",suma);
printf("Desea volver a intentar?(s/n): "); 
scanf("%s",continuar);
getche();}
while(continuar!='n' && continuar!='N');}
