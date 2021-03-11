#include <iostream.h>
#include <stdio.h>
#include <string.h>
void main()
{
  int contador=0, i=0, act1=0, cont2=0;
  char cad[100];
  printf("Ingrese una cadena: ");gets(cad);
  while(i<strlen(cad))
  {
    if(cad[i]==32)
    {
      cont2++;
      while((cad[i+1]!=32)&&(act1==0))
      { 
	cad[i-contador]=cad[i+1];
	i++;
	if(cad[i+1]=='\0')
	  {
	    act1=1;
	    cad[strlen(cad)-cont2]='\0';
          }
      }
      contador++;
    }
    i++;
  }
  printf("\n\nLa cadena sin espacios es : %s", cad);
}       