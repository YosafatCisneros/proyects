#include<stdio.h>
#include<conio.h>
int main()
{
int x, suma=1 ;
for (x=0; x<100; x++)
  {
  suma=suma+x;
  printf("%d+%d=%d \n",suma,x,suma+x);
  }

getche();
}
