#include<stdio.h>
#include<conio.h>
int main()
{
int a;
int *ptrA;
a=7;
ptrA=&a;
printf("La direccion de a es %p\nEl valor de ptrA es %p ",&a,ptrA);
printf("\n\nEl valor de a es %d\nEl valor de *ptrA es %d",a,*ptrA);
printf("\n\nMuestra de que * y & son complementos uno del otro &*ptrA=%p \n*&ptrA=%p ",&*ptrA,*&ptrA);
getche();
}
