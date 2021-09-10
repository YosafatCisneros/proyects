#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<windows.h>

int main()
{
int opcion=2, i, j;
float matriz[3][4], matriz2[3][4], aux, x, y, z, di[3][3], b[3][1], lu[3][3], xm[3][1], dib[3][1], dilu[3][3], dilux[3][1], final[3][1],ax, ay, az;
do{
    if (opcion==2){
        printf("  PROGRAMA PARA RESOLVER SISTEMAS DE ECUACIONES DE 3X3 \n\n");
        printf("  Introduce los coeficientes  \n");
        for(int i=0; i<3; ++i){
            printf("  Ecuacion #%d: \n",i+1);
            for(int j=0; j<4; ++j){
                switch(j){
                    case 0:
                        printf("  x= ");
                        break;
                    case 1:
                        printf("  y= ");
                        break;
                    case 2:
                        printf("  z= ");
                        break;
                    case 3:
                        printf("  Resultado= ");
                        break;
                }
                scanf("%f",&aux);
                matriz[i][j]=aux;
                printf("\n");
            }
        printf("\n");
        }

    }
    for(opcion=4;opcion>3||opcion<0;){
        system("cls");
        printf("  Menu  \n");
        printf("  1.- Eliminacion de Gauss-Jordan\n");
        printf("  2.- Regla de Cramer\n");
        printf("  3.- Metodo de Jacobi\n\n");
        printf("  Escribir el numero de su opcion: \n  ");
        scanf("%d", &opcion);
        if(opcion>3||opcion<0){
            printf("  Error: opcion invalida, intenta denuevo");
          getch();}}
    switch(opcion){
        case 1:
            system ("cls");
            printf("  1.- Eliminacion de Gauss-Jordan\n\nMatriz:\n");
            for(int i=0; i<3; ++i){
                for(int j=0; j<4; ++j){
                    printf("%.2f\t",matriz[i][j]);
                    matriz2[i][j]=matriz[i][j];
                }
                printf("\n");
            }
            printf("\nPrimer pivote\n");
            aux=matriz[0][0];
            matriz[0][0]/=aux;
            matriz[0][1]/=aux;
            matriz[0][2]/=aux;
            matriz[0][3]/=aux;
            aux=matriz[1][0]*-1;
            matriz[1][0]+=matriz[0][0]*aux;
            matriz[1][1]+=matriz[0][1]*aux;
            matriz[1][2]+=matriz[0][2]*aux;
            matriz[1][3]+=matriz[0][3]*aux;
            aux=matriz[2][0]*-1;
            matriz[2][0]+=matriz[0][0]*aux;
            matriz[2][1]+=matriz[0][1]*aux;
            matriz[2][2]+=matriz[0][2]*aux;
            matriz[2][3]+=matriz[0][3]*aux;
            for(int i=0; i<3; ++i){
                for(int j=0; j<4; ++j){
                    printf("%.2f\t",matriz[i][j]);
                }
                printf("\n");
            }
            printf("\nSegundo pivote\n");
            aux=matriz[1][1];
            matriz[1][1]/=aux;
            matriz[1][2]/=aux;
            matriz[1][3]/=aux;
            aux=matriz[0][1]*-1;
            matriz[0][1]+=matriz[1][1]*aux;
            matriz[0][2]+=matriz[1][2]*aux;
            matriz[0][3]+=matriz[1][3]*aux;
            aux=matriz[2][1]*-1;
            matriz[2][1]+=matriz[1][1]*aux;
            matriz[2][2]+=matriz[1][2]*aux;
            matriz[2][3]+=matriz[1][3]*aux;
            for(int i=0; i<3; ++i){
                for(int j=0; j<4; ++j){
                    printf("%.2f\t",matriz[i][j]);
                }
                printf("\n");
            }
            printf("\nTercer pivote\n");
            aux=matriz[2][2];
            matriz[2][2]/=aux;
            matriz[2][3]/=aux;
            aux=matriz[0][2]*-1;
            matriz[0][2]+=matriz[2][2]*aux;
            matriz[0][3]+=matriz[2][3]*aux;
            aux=matriz[1][2]*-1;
            matriz[1][2]+=matriz[2][2]*aux;
            matriz[1][3]+=matriz[2][3]*aux;

            ax=matriz[0][3];
            ay=matriz[1][3];
            az=matriz[2][3];
            for(int i=0; i<3; ++i){
                for(int j=0; j<4; ++j){
                    printf("%.2f\t",matriz[i][j]);
                    matriz[i][j]=matriz2[i][j];
                }
                printf("\n");
            }
            printf("\nx= %.2f\t\n",ax);
            printf("y= %.2f\t\n",ay);
            printf("z= %.2f\t",az);
            getch();
            break;
        case 2:
            system ("cls");
            printf("  2.- Regla de Cramer\n\n");
            aux=(matriz[0][0]*matriz[1][1]*matriz[2][2]+matriz[1][0]*matriz[2][1]*matriz[0][2]+matriz[2][0]*matriz[0][1]*matriz[1][2])-(matriz[0][2]*matriz[1][1]*matriz[2][0]+matriz[1][2]*matriz[2][1]*matriz[0][0]+matriz[2][2]*matriz[0][1]*matriz[1][0]);
            x=(matriz[0][3]*matriz[1][1]*matriz[2][2]+matriz[1][3]*matriz[2][1]*matriz[0][2]+matriz[2][3]*matriz[0][1]*matriz[1][2])-(matriz[0][2]*matriz[1][1]*matriz[2][3]+matriz[1][2]*matriz[2][1]*matriz[0][3]+matriz[2][2]*matriz[0][1]*matriz[1][3]);
            y=(matriz[0][0]*matriz[1][3]*matriz[2][2]+matriz[1][0]*matriz[2][3]*matriz[0][2]+matriz[2][0]*matriz[0][3]*matriz[1][2])-(matriz[0][2]*matriz[1][3]*matriz[2][0]+matriz[1][2]*matriz[2][3]*matriz[0][0]+matriz[2][2]*matriz[0][3]*matriz[1][0]);
            z=(matriz[0][0]*matriz[1][1]*matriz[2][3]+matriz[1][0]*matriz[2][1]*matriz[0][3]+matriz[2][0]*matriz[0][1]*matriz[1][3])-(matriz[0][3]*matriz[1][1]*matriz[2][0]+matriz[1][3]*matriz[2][1]*matriz[0][0]+matriz[2][3]*matriz[0][1]*matriz[1][0]);
            printf("  DETERMINANTES\n  Det del sistema=%f\n  Det x=%f\n  Det y=%f\n  Det z=%f",aux, x, y, z);
            x/=aux;
            y/=aux;
            z/=aux;
            printf("\n\n  RESULTADOS\n  x=%f\n  y=%f\n  z=%f", x, y, z);
            getch();
            break;
        case 3:
            system ("cls");
            printf("  3.- Metodo de Jacobi");
            for(i=0;i<3;i++){
	   for(j=0;j<3;j++){
	      di[i][j]=1/matriz[i][j];
	      if(i!=j){
		     lu[i][j]=matriz[i][j]*-1;}
		  else{
		     lu[i][j]=0;}}}

	for(i=0;i<3;i++){
	      b[i][0]=matriz[i][3];}

	for(i=0;i<3;i++){
	      dib[i][0]=di[i][i]*b[i][0];}

	for(i=0;i<3;i++){
	   for(j=0;j<3;j++){
	       if(i!=j)
		      dilu[i][j]=di[i][0]*lu[0][j]+di[i][1]*lu[1][j]+di[i][2]*lu[2][j];
		   else
	          dilu[i][j]=0;}}


	x=0;
	y=0;
	z=0;
	//iteraciones
	printf("\n\nprimera iteracion: x=%f, y=%f, z=%f", x, y, z);
	for(i=0;i<3;i++){
	      dilux[i][0]=dilu[i][0]*x+dilu[i][1]*y+dilu[i][2]*z;}

	for(i=0;i<3;i++){
	      final[i][0]=dilux[i][0]+dib[i][0];
		  switch(i){
	      	case 0:
	      		x=final[i][0];
	      		printf("\nx=%f",x);
	      		break;
	      	case 1:
	      		y=final[i][0];
	      		printf("\ny=%f",y);
	      		break;
	      	case 2:
	      		z=final[i][0];
	      		printf("\nz=%f",z);
	      		break;
		  }}

            getch();
            break;
    }
    system("cls");
    printf("  Escribir el numero de su opcion:\n  1.- Salir\n  2.- Para cambiar el sistema\n  #.- Cualquier otro numero para seleccionar otro metodo\n  ");
    scanf("%d",&opcion);
    system("cls");
} while(opcion!=1);
}
