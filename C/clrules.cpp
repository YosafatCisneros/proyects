#include<stdio.h>
#include<conio.h>
#define Y 2
#define X 3
main()
{
int z[X][Y],f,c;
printf("Introduce tu arreglo bidimensional:\n");
for(f=0;f<X;++f)
{
	for(c=0;c<Y;++c)
	{
		scanf("%d",&z[f][c]);
	}
}
printf("Tu arreglo bidimencional es:\n");
for(f=0;f<X;++f)
{
	for(c=0;c<Y;++c)
	{
		printf("%-4d",z[f][c]);
	}
	printf("\n");
}
	getch();

}
