


























































































































































#include<stdio.h>
#include<conio.h>
#include "iostream.h"

void ingresar(char *cad)
{
  int ch;
  do
  {
   ch=getche();
   if (ch !=13)
   {
    *cad=ch;
    cad++;
   }
  }while(ch!=13);
 *cad='\0';
}


void imprimir(char * cad){
  while (*cad !='\0'){
    cout << *cad;
    cad++;
  }
}

void main ()
{
char *cad;
clrscr ();
cout << "ingrese una cadena :"; ingresar(cad);
cout << endl << "Usted ingreso :"  ; imprimir(cad);
getch ();
}
