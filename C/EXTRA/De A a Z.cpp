//5.       Programa de imprima de la letra  a   a  la letra  z
#include<stdio.h>
#include<conio.h>
#include<windows.h>
int main()
{
    char contador;
    printf("\n");
    contador='a';
    while(contador<='z')
    {                  system("cls");
                       printf("%c\n",contador);
                       contador++;
                        
                          
    }
    getche();
    return 0;
}
