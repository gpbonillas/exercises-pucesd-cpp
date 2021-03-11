#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>
void ingresar_matrices(int fi1, int co1, int fi2, int co2);
void normalizar(int fi1, int co1, int fi2, int co2);
void relacion(int fi1, int co1, int co2);
void relacionxz(int fi1, int co2);
void imprimir_normalizada(int fi1, int co1, int fi2, int co2);

double m1[10][10], m2[10][10], m3[10][10];
char c1[20];

void main()
{
 char opc;
 int fi1, co1, fi2, co2;
   do{
   clrscr();
   gotoxy(30,1);printf("RELACIONES DIFUSAS-MAXIMO PRODUCTO");
   gotoxy(1,3);printf("Primera Matriz(M x N): ");
   gotoxy(30,4);printf("  Filas(M): ");cin>>fi1;
   gotoxy(47,4);printf("  Columnas(N): ");cin>>co1;
   gotoxy(1,9);printf("Segunda Matriz(M x N): ");
   gotoxy(30,11);printf("  Filas(M): ");cin>>fi2;
   gotoxy(47,11);printf("  Columnas(N): ");cin>>co2;
   ingresar_matrices(fi1,co1,fi2,co2);
   normalizar(fi1,co1,fi2,co2);
   imprimir_normalizada(fi1,co1,fi2,co2);
   relacion(fi1,co1,co2);
   relacionxz(fi1,co2);
   gotoxy(2,20);printf("¿DESEA VOLVER A INGRESAR?: ");cin>>opc;
   }while(opc==82||opc==115);

}
void ingresar_matrices(int fi1, int co1, int fi2, int co2)
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
    comp1=strcmp(c1,"log10");
    comp2=strcmp(c1,"ln");
    if(comp1==0)
    m1[i][j]=log10(m1[i][j]);
    if(comp2==0)
    {m1[i][j]=log(m1[i][j]);}
    x+=11;
  }
  x=3;
  y++;
}
x=3;
y=14;
gotoxy(10,12);printf("MATRIZ # 2: (%d x %d)",fi2,co2);
for(i=0;i<fi2;i++)
{
  for(j=0;j<co2;j++)
  {
    gotoxy(x,y);gets(c1);
    gotoxy((x+6),y);cin>>m2[i][j];
    comp3=strcmp(c1,"log10");
    comp4=strcmp(c1,"ln");
    if(comp3==0)
     m2[i][j]=log10(m2[i][j]);

    if(comp4==0)
      m2[i][j]=log(m2[i][j]);
    x+=11;
  }
  x=3;
  y++;
}
}
void normalizar(int fi1, int co1, int fi2, int co2)
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


void relacion(int fi1, int co1, int co2)
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


void relacionxz(int fi1, int co2)
{
 int i, j, x, y;
 x=30;y=14;
 gotoxy(22,15);cout<<"R(XZ)= ";
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

void imprimir_normalizada(int fi1, int co1, int fi2, int co2)
{
  clrscr();
  int j, i, x, y;
  x=9;
  y=4;
  gotoxy(9,2);printf("MATRIZ #1 NORMALIZADA: ");
  gotoxy(2,5);printf("R(XY)=");
  for(i=0;i<fi1;i++)
  {
    for(j=0;j<co1;j++)
    {
      gotoxy(x,y);printf("%.2f",m1[i][j]);
      x+=6;
    }
    x=9;
    y++;
  }

  x=47;y=4;
  gotoxy(47,2);printf("MATRIZ #2 NORMALIZADA: ");
  gotoxy(40,5);printf("R(YZ)=");
  for(i=0;i<fi2;i++)
  {
    for(j=0;j<co2;j++)
    {
      gotoxy(x,y);printf("%.2f",m2[i][j]);
      x+=6;
    }
    x=47;
    y++;
  }
}







         
                                                                                     




















   