#include <stdio.h>
#include <string.h>
#include <conio.h>
int main ()
{
  char szInput[256];
  printf ("Enter a sentence: ");
  gets (szInput);
  printf ("The sentence entered is %u characters long.\n",(unsigned)strlen(szInput));
  getch();
}

