#include<iostream.h>
#include<conio.h>
#include<stdio.h>

char *invertir(char *c1);
void main(){
char c1[50];
gotoxy(1,1);cout<<"Ingrese una cadena: ";gets(c1);
invertir(c1),
gotoxy(1,5);printf("La cadena invertida es: %s",c1);
getch();
}

char *invertir(char *c1)
{
  int cont=0, cont2=0;
  char *copinv;
  while(*c1!='\0')
  {
    c1++;
    cont++;
  }
  c1--;
  while(cont>0)
  {
    *copinv=*c1;
    copinv++;
    c1--;
    cont--;
    cont2++;
  }
  *copinv='\0';
  c1++;
  while(cont2>0)
  {
    copinv--;
    cont2--;
  }
  while(*copinv!='\0')
  {
    *c1=*copinv;
    c1++;
    copinv++;
  }
  *c1='\0';
  return c1;
}

