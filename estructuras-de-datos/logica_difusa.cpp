#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>
void ingresar_matrices(char c1[],char c2[],int fi1, int co1, int fi2, int co2, double m1[10][10], double m2[10][10]);
void normalizar(double m1[10][10], double m2[10][10], int fi1, int co1, int fi2, int co2);
void reldifusa(double m1[10][10], double m2[10][10],double m3[10][10],int fi1, int co1, int co2);
void mostrar_relacion(double m3[10][10], int fi1, int co2);
void imprimir(double m1[10][10],double m2[10][10],int fi1, int co1, int fi2, int co2);
void cad_oper(char c1[]);
int comparar(char c1[], char c2[]);

void main()
{
 double m1[10][10], m2[10][10], m3[10][10];
 char c1[20], c2[20];
 char opc;
 int fi1, co1, fi2, co2, i, j;
   do{
   clrscr();
   for(i=0;i<10;i++)
   {
     for(j=0; j<10; j++)
     { 
        m1[i][j]=NULL;
        m2[i][j]=NULL;
     }
   }
   gotoxy(30,1);printf("RELACIONES DIFUSAS");
   gotoxy(1,3);printf("Dimension de 1º Matriz(M x N): ");
   gotoxy(30,3);printf("  Filas: ");cin>>fi1;
   gotoxy(47,3);printf("  Columnas: ");cin>>co1;
   gotoxy(1,5);printf("Dimension de 2º Matriz(M x N): ");
   gotoxy(30,5);printf("  Filas: ");cin>>fi2;
   gotoxy(47,5);printf("  Columnas: ");cin>>co2;
   ingresar_matrices(c1,c2,fi1,co1,fi2,co2,m1,m2);
   normalizar(m1,m2,fi1,co1,fi2,co2);
   imprimir(m1,m2,fi1,co1,fi2,co2);
   reldifusa(m1,m2,m3,fi1,co1,co2);
   mostrar_relacion(m3,fi1,co2);
   gotoxy(2,23);printf("¿DESEA VOLVER A INGRESAR?: ");cin>>opc;
   }while(opc==82||opc==115);

}
void ingresar_matrices(char c1[],char c2[],int fi1, int co1, int fi2, int co2, double m1[10][10], double m2[10][10])
{
double i, j, x=3, y=3;
int comp1, comp2, comp3, comp4;
clrscr();
gotoxy(10,1);printf("MATRIZ # 1: (%d x %d)",fi1,co1);

for(i=0;i<fi1;i++)
{
  for(j=0;j<co1;j++)
  {
    gotoxy(x,y);gets(c1);
    gotoxy((x+6),y);cin>>m1[i][j];
    comp1=comparar(c1,"log10");
    comp2=comparar(c1,"ln");
    if(comp1==0)
    m1[i][j]=log10(m1[i][j]);
    if(comp2==0)
    {m1[i][j]=log(m1[i][j]);}
    x+=11;
  }
  x=3;
  y++;
}
x=35;
y=3;
gotoxy(40,1);printf("MATRIZ # 2: (%d x %d)",fi2,co2);
for(i=0;i<fi2;i++)
{
  for(j=0;j<co2;j++)
  {
    gotoxy(x,y);gets(c2);
    gotoxy((x+6),y);cin>>m2[i][j];
    comp3=comparar(c2,"log10");
    comp4=comparar(c2,"ln");
    if(comp3==0)
     m2[i][j]=log10(m2[i][j]);

    if(comp4==0)
      m2[i][j]=log(m2[i][j]);
    x+=11;
  }
  x=35;
  y++;
}
}
void cad_oper(char c1[])
{
   int car, i;
   i=0;
   do
   {
     car=getche();
     if(car!=13)
     {
      c1[i]=car;
      i++;
     }
   }while(car!=13);
   c1[i]='\0';
}

int comparar (char c1[], char c2[]){
int dif=0, i=0;

while((c1[i]!='\0' || c2[i]!='\0')&&(dif==0))
	{
	if(c1[i]!=c2[i])
	{dif=(c1[i]-c2[i]);}
	i++;
	}
return dif;
}   

void normalizar(double m1[10][10], double m2[10][10], int fi1, int co1, int fi2, int co2)
{
double mayor, mayor1, i, j;
mayor=1;
mayor1=1;
for(i=0;i<fi1;i++)
{
  for(j=0;j<co1;j++)
  {
    if(m1[i][j]<0)
      m1[i][j]*=(-1);
    if(m1[i][j]>mayor)
      mayor=m1[i][j];
  }
}

for(i=0;i<fi2;i++)
{
  for(j=0;j<co2;j++)
  {
    if(m2[i][j]<0)
      m2[i][j]*=(-1);
    if(m2[i][j]>mayor1)
      mayor1=m2[i][j];
  }
}

if(mayor>1)
{
  for(i=0;i<fi1;i++)
  {
    for(j=0;j<co1;j++)
    {
      if(m1[i][j]>1)
      m1[i][j]/=mayor;
    }
  }
}

if(mayor1>1)
{
  for(i=0;i<fi2;i++)
  {
    for(j=0;j<co2;j++)
    {
      if(m2[i][j]>1)
      m2[i][j]/=mayor1;
    }
  }
}

}


void reldifusa(double m1[10][10], double m2[10][10],double m3[10][10],int fi1, int co1, int co2)
{
  int i, j, k;
  double pro1, mayor;
  mayor=0;
  for(i=0;i<fi1;i++)
  {
     for(j=0;j<co2;j++)
     {
	for(k=0;k<co1;k++)                    
        {
	   pro1=m1[i][k]*m2[k][j];
	   if(pro1>mayor)
	      mayor=pro1;
        }
        m3[i][j]=mayor;
	mayor=0;
     }
  }
}         


void mostrar_relacion(double m3[10][10], int fi1, int co2)
{
 int i, j, x, y;
 x=30;y=17;
 gotoxy(30,15);cout<<"LA RELACION XZ ES: ";
 for(i=0;i<fi1;i++)
 {
   for(j=0;j<co2;j++)
   {
     gotoxy(x,y);printf("%.2f",m3[i][j]);
     x+=6;
   }
   x=30;
   y++;
 }
}

void imprimir(double m1[10][10],double m2[10][10], int fi1, int co1, int fi2, int co2)
{
  clrscr();
  int j, i, x, y;
  x=3;
  y=3;
  gotoxy(3,1);printf("MATRIZ #1 NORMALIZADA: ");
  for(i=0;i<fi1;i++)
  {
    for(j=0;j<co1;j++)
    {
      gotoxy(x,y);printf("%.2f",m1[i][j]);
      x+=6;
    }
    x=3;
    y++;
  }

  x=35;y=3;
  gotoxy(34,1);printf("MATRIZ #2 NORMALIZADA: ");
  for(i=0;i<fi2;i++)
  {
    for(j=0;j<co2;j++)
    {
      gotoxy(x,y);printf("%.2f",m2[i][j]);
      x+=6;
    }
    x=35;
    y++;
  }
}







         
                                                                                     




















   