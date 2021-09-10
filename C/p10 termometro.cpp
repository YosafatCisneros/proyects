#include<stdio.h>
#include<conio.h>

int main()

{
float n1;
printf("Introducir temperatura en grados Centigrados: \n");
scanf("%f",&n1);
printf("\n\n La temperatura en grados fahrenheit es de: \n %f*1.8+32=%f",n1,n1*1.8+32);
printf("\n La temperatura en grados kelvin es de: \n %f+273=%f",n1,n1+273);
getche();
}
