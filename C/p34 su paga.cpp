//3. Determinar la cantidad de dinero que recibirá un trabajador por concepto de las horas extras trabajadas en una empresa, 
//sabiendo que cuando las horas de trabajo exceden de 40, el resto se consideran horas extras y que estas se pagan al doble 
//de una hora normal cuando no exceden de 8; si las horas extras exceden de 8 se pagan las primeras 8 al doble de lo que se pagan 
//las horas normales y el resto al triple.

#include<stdio.h>
#include<conio.h>

int main()
{
float ht,pph,he,pd,pt,pe,tp;
printf("Intruducir horas trbajadas esta semana: ");
scanf("%f",&ht);
printf("Intruducir pago por hora: ");
scanf("%f",&pph);
if(ht<=40) printf("\nSu paga es de: %f",ht,pph,ht*pph);
else{
he=ht-40;
if(he<=8) pe=he*pph*2;
else {
pd=8*pph*2;
pt=(he-8)*pph*3;
pe=pd+pt;}
tp=40*pph+pe;
printf("\nSu paga con horas extra es de: %f",tp,tp);}
getche();
}
