/*Programa que imprima aprovado o no aprovado*/
#include<stdio.h>
#include<conio.h>
#include<windows.h>
int main()
{
    system("cls");
    float nota;
    printf("Introduzca la calificacion\n");
    scanf("%f",&nota);
    while((nota<0)||(nota>10))
    {
                            printf("\nERROR nota incorrecta\n");
                            }
   
                            if (nota>=6) printf("\nAPROVADO\n");
                            else         printf("\nNo APROVADO\n");
    
    getche();
    return 0;
}
