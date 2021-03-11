#include<iostream.h>
#include<stdio.h>
#include<conio.h>

void copiar(char *c1, char *c2);
int longitud(char *c3);
int comparar(char *c4, char *c5);
void concatenar(char *c6, char *c7);
void ingresar(char *c1);
void imprimir(char *c2);

void main()
{
  char c1[100], c2[50], c3[100];
  int num, num1, ncomp, x;
  gotoxy(1,1);cout<<"Ingrese una cadena: ";ingresar(c1);
  gotoxy(1,3);cout<<"Ingrese otra cadena: ";ingresar(c2);
  clrscr();
  gotoxy(1,1);printf("CADENA 1: ");imprimir(c1);
  gotoxy(1,2);printf("CADENA 2: ");imprimir(c2);

  num=longitud(c1);
  num1=longitud(c2);

  gotoxy(1,5);printf("La longitud de la cadena 1 es: %d",num);
  gotoxy(1,6);printf("La longitud de la cadena 2 es: %d",num1);

  copiar(c3,c1);
  gotoxy(1,9);printf("COPIAR: ");imprimir(c3);

  ncomp=comparar(c1,c2);
  if(ncomp==0)
    {gotoxy(1,12);printf("Las cadenas son iguales.");}
  if(ncomp>0)
    {gotoxy(1,12);printf("La cadena 1 es mayor.");}
  if(ncomp<0)
    {gotoxy(1,12);printf("La cadena 2 es mayor.");}


  concatenar(c1,c2);
  gotoxy(1,15);printf("CONCATENADAS: ");imprimir(c1);
}

int longitud(char *c3)
{
  int i=0;
  while(*c3!='\0')
  {
    c3++;
    i++;
  }
  return i;
}

void ingresar(char *c1)
{
  int y;
  do
  {
    y=getche();
    if(y!=13 && y!=32)
    {
      *c1=y;
      c1++;
    }
  }while(y!=13);
  *c1='\0';
}

void imprimir(char *c2)
{
  while(*c2!='\0')
  {
    cout<<*c2;
    c2++;
  }
}


void copiar(char *c1, char *c2)
{
  while(*c2!='\0')
  {
    *c1=*c2;
    c1++;
    c2++;
  }
  *c1='\0';
}

int comparar(char *c4, char *c5)
{
  int cont=0;
  while((*c4!='\0'||*c5!='\0')&&(cont==0))
  {
    if(*c4!=*c5)
    {
      cont=*c4-*c5;
    }
    c4++;
    c5++;
  }
  return cont;
}

void concatenar(char *c6, char *c7)
{
  //int num;
  while(*c6!='\0')
  {
    c6++;
  }
  while(*c7!='\0')
  {
    *c6=*c7;
    c6++;
    c7++;
  }
  *c6='\0';
}    



















    
    























