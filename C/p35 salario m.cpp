//4. Calcular la utilidad que un trabajador recibe en el reparto anual de utilidades si este se le asigna 
//como un porcentaje de su salario mensual que depende de su antigüedad en la empresa de acuerdo con la sig. 
  
#include<stdio.h>
#include<conio.h>
int main()
{
float an,u;
int sm;
printf("Introducir salario mensual: ");
scanf("%d",&sm);
printf("Tiempo en años de trabajo en la empreza: ");
scanf("%f",an);
if(an<1) {
u=sm*0.05;}
else{
if((an>=1)&&(an<2)) {
u=sm*0.07;}
else {
if ((an>=2)&&(an<5)) {
u=sm*0.10;}
else{
if((an>=5)&&(an<10)) {
u=sm*0.15;}
else{
u=sm*0.20;
}}}}
printf("\nSus utilidades son de: %f",u,u);
getche();
}
