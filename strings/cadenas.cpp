#include<iostream.h>
#include<stdio.h>
#include<string.h>

void copiar(char a[], char b[]);
int longitud(char c[]);
int comparar(char d[], char e[]);
void concatenar(char x[],  char y[]);
void mayusculas(char m[]);
void minusculas(char n[]);

void main()
{
  char cad1[100];
  char cad2[50];
  char cad3[100];
  int longt, comp;
  cout<<"Ingrese una cadena: ";gets(cad1);
  cout<<"\n\nIngrese otra cadena: ";gets(cad2);

  longt=longitud(cad1);
  cout<<"\nLa cadena uno tiene "<<longt<<" caracteres ";
  longt=longitud(cad2);
  cout<<"\nLa cadena 2 tiene "<<longt<<" caracteres";

  mayusculas(cad1);
  minusculas(cad2);
  cout<<"\nMAYUSCULAS= ";puts(cad1);
  cout<<"\nMINUSCULAS= ";puts(cad2);
  strcpy(cad3,cad1);//copiar(cad3,cad1);

  cout<<"\n\nLa copia de la cadena es: ";puts(cad3);

  comp=strcmp(cad1,cad2);//comparar(cad1,cad2);

  if(comp==0)
  cout<<"\n\nCADENA 1 IGUAL A LA SEGUNDA";
  if(comp>0)
  cout<<"\n\nCADENA 1 MAYOR QUE LA 2";
  if(comp<0)
  cout<<"\n\nCADENA 1 MENOR QUE LA 2";
  cout<<"\n\t\t\t"<<comp;
  strcat(cad1,cad2);//concatenar(cad1,cad2);

  cout<<"\n\nCONCATENACION: ";puts(cad1);
}

int longitud(char c[])
{
  int l=0, i=0;

  while(c[l]!='\0')
  {
    if(c[l]!=32)
    {i++;}
    l++;
  }
  return i;
}

void copiar(char a[], char b[])
{
  int i=0;
  while(b[i]!='\0')
  {
    a[i]=b[i];
    i++;
  }
  a[i]='\0';
}

int comparar(char d[], char e[])
{
  int c, i=0, dif=0;

  while((d[i]!='\0'||e[i]!='\0') && dif==0)
  {
    if(d[i]!=e[i])
      dif=d[i]-e[i];
    i++;
  }
  return dif;
}

void concatenar(char x[], char y[])
{
  int i=0, k=0, l;
  while(x[i]!='\0')
    i++;

  while(y[k]!='\0')
  {
    x[i]=y[k];
    i++;
    k++;
  }
  x[i]='\0';
}      
    
void mayusculas(char m[])
{
 int i=0;
 while(m[i]!='\0')
 {
   if(m[i]>=97 && m[i]<=122)
   m[i]-=32;
   i++;
 }
}


void minusculas(char n[])
{
  int i=0;
  while(n[i]!='\0')
  {
    if(n[i]>=65 && n[i]<=90)
    n[i]+=32;
    i++;
  }
}














   
























     

























   