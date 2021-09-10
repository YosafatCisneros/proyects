//una persona enferma tiene permitidas 2 actividades las cuales son: estar sentado y dormido, calcular el consumo de calorias en x tiempo
#include<stdio.h>
#include<conio.h>

int main()
{
char act;
int ed;
printf("Escribe tu edad: ");
scanf("%d",&ed);
printf("Escribe tu sexo m=masculino f=femenino): ");
scanf("%s",&sex);
if((sex=="m")||(sex=="M")) printf("\nPulsaciones hombre=%f",(220-ed)/10);
else printf("\nPulsaciones mujer=%f",(210-ed)/10);
getche();
}
