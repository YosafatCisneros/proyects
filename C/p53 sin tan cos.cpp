//sin, cos, tan
#include<stdio.h>
#include<conio.h>
#include <math.h> 
int main()
{
int f;
for(f=0;f<361;f++)
{printf("seno%d=%0.4f",f,sin(f));
printf("\tcoseno%d=%0.4f",f,cos(f));
printf("\ttangente%d=%0.4f\n",f,tan(f));}
getche();
}
