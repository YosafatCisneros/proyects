#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <ctype.h>
#include <ctime>
#include <cstdlib>
#include <iostream>
int main()
{
    int la1, la2, y, j, i, x, aux=0, error=0, str=0, final=0, rep=0, opcion;
    char cpy[20], ca1[20], ca2[20], tw[20], letra ,claves[6][4]={{'g','a','t','o'},{'p','e','r','a'},{'v','a','c','a'},{'n','u','b','e'},{'d','a','d','o'},{'m','a','n','o'}}, respuesta[4]={'_','_','_','_'}, usadas[26]={0};
    do{
        printf("Opcion 1: Ahorcado\nOpcion 2: Leer texto\nOpcion 3: Mostrar texto\nOpcion 4: Salir\nIntroduce tu numero de opcion: ");
        do{
            scanf("%d",&opcion);
            fflush( stdin );
            if(opcion<0|| opcion>4)
                printf("opcion no valida, intenta otra vez:");
        }while(opcion<0|| opcion>4);
        system("cls") ;
        switch(opcion){
            case 1:{
                aux=0;
                error=0;
                str=0;
                final=0;
                rep=0;
                respuesta[0]='_';
                respuesta[1]='_';
                respuesta[2]='_';
                respuesta[3]='_';
                for(j=0;j<26;j++)
                    usadas[j]=0;
                int gdriver=DETECT, gmode;
                initwindow(500,750,"C:\\BORLANDC\\BGI");
                rectangle(20, 20, 40, 750);
                rectangle(40, 20, 250, 40);
                line(250, 40, 250, 200);
                srand(time(0));
                y=rand()%6;
                do{
                    printf("Introduce la letra: ");
                        do{
                            scanf("%c",&letra);
                            fflush( stdin );
                            letra=tolower(letra);
                            if(letra<97 || letra>122)
                                printf("Caracter no valido, intente otra vez con una letra: ");
                            else
                            {
                                for(j=0;j<26;j++)
                                {
                                    if(letra==usadas[j])
                                    {
                                        printf("Letra repetida, introducir una letra nueva:");
                                        letra=90;
                                    }
                               }
                           }
                        }while(letra<97 || letra>122);
                        usadas[rep]=letra;
                        rep++;

                        for(j=0;j<4;j++)
                        {
                            if(letra==claves[y][j])
                            {
                                respuesta[j]=letra;
                            }
                            else
                                str++;
                        }
                    if(str==4)
                        error++;
                    str=0;
                    switch (error)
                    {
                        case 1:
                        printf("Error 1, 4 intentos");
                        circle(250,250,50);
                        break;
                        case 2:
                        printf("Error 3, 3 intentos");
                        line(250, 300, 250, 550);
                        break;
                        case 3:
                        printf("Error 3, 2 intentos");
                        line(150, 370, 350, 370);
                        break;
                        case 4:
                        printf("Error 4, 1 intentos");
                        line(250, 550, 150, 700);
                        break;
                        case 5:
                        printf("Error 5, 0 intentos\nPerdiste, vuelve a intentar");
                        line(250, 550, 350, 700);

                        final++;
                        break;
                    }
                    printf("\n");
                    aux=0;
                    for(j=0;j<4;j++)
                    {
                        printf("%c",respuesta[j]);
                        if(respuesta[j]=='_')
                            aux++;

                    }
                    printf("\n");
                    if(aux==0)
                    {
                        final++;
                        printf("Felicidades, ganaste!");
                    }
                }while(final==0);
                closegraph();
            }
                break;
            case 2:
                j=0;
                printf("Introduce tu oracion (maximo 20 caracteres):\n");
                do{
                    scanf("%c",&tw[j]);
                    j++;
                }while(tw[j-1]!=10);
                j-=2;
                if(j>19)
                    printf("Numero de caracteres mayor al indicado");
                else
                    printf("Cadena almacenada");
                break;
            case 3:
                printf("Introduce la cadena 1:\n");
                gets(ca1);
                printf("Introduce la cadena 2:\n");
                gets(ca2);
                la1=strlen(ca1);
                la2=strlen(ca2);
                strcpy(cpy, ca1);
                for(j=0, i=0;j<la1;j++)
                {
                    if(cpy[j]!=' ')
                    {
                        ca1[i]=cpy[j];
                        i++;
                    }
                }
                ca1[i]='\0';
                la1=strlen(ca1);
                printf("Cadena 1 sin espacios:\n");
                for(j=0;j<la1;j++)
                {
                    printf("%c",ca1[j]);
                }
                printf("\n");
                strcpy(cpy, ca2);
                for(j=0, i=0;j<la2;j++)
                {
                    if(cpy[j]!=' ')
                    {
                        ca2[i]=cpy[j];
                        i++;
                    }
                }
                ca2[i]='\0';
                la2=strlen(ca2);
                printf("Cadena 2 sin espacios:\n");
                for(j=0;j<la2;j++)
                {
                    printf("%c",ca2[j]);
                }


                if(la1==la2)
                {
                    for(j=0;j<la2;j++)
                    {
                        ca1[j]=tolower(ca1[j]);
                        ca2[j]=tolower(ca2[j]);
                    }

                    for(j=0;j<la2-1;j++)
                    {
                        for(i=0;i<la2-1;i++)
                        {
                            if(ca1[i]>ca1[i+1])
                            {
                                cpy[0]=ca1[i];
                                ca1[i]=ca1[i+1];
                                ca1[i+1]=cpy[0];
                            }
                            if(ca2[i]>ca2[i+1])
                            {
                                cpy[0]=ca2[i];
                                ca2[i]=ca2[i+1];
                                ca2[i+1]=cpy[0];
                            }
                        }
                    }
                    printf("\nCadena 1 en orden:\n");
                    for(j=0;j<la2;j++)
                    {
                        printf("%c",ca1[j]);
                    }
                    printf("\nCadena 2 en orden:\n");
                    for(j=0;j<la2;j++)
                    {
                        printf("%c",ca2[j]);
                    }
                    for(j=0, i=0;j<la2;j++)
                    {
                        if(ca1[j]!=ca2[j])
                            i++;
                    }
                    if(i==0)
                        printf("\nLas cadenas son anagrama");
                    else
                        printf("\nLas cadenas no son anagrama");
                }
                else
                    printf("\nDiferente cantidad de caracteres, las cadenas no son anagrama");
                break;
            case 4:
                printf("Vuelva pronto");
                break;
        }
        printf("\nDa enter para continuar");
        std::cin.get();
        system("cls") ;
    }while(opcion!=4);
}
