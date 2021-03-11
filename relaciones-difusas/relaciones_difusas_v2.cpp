#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>
void ingresar_matrices(char c1[],char c2[],int fila1, int colu1, int fila2, int colu2, double mat1[10][10], double mat2[10][10]);
void normalizar(double mat1[10][10], double mat2[10][10], int fila1, int colu1, int fila2, int colu2);
void reldifusa(double mat1[10][10], double mat2[10][10],double mat3[10][10],int fila1, int colu1, int colu2);
void mostrar_relacion(double mat3[10][10], int fi1, int co2);
void imprimir(double mat1[10][10],double mat2[10][10],int fila1, int colu1, int fila2, int colu2);
int comparar(char c1[],char c2[]);

void main()
{
 double mat1[10][10], mat2[10][10], mat3[10][10];
 char c1[20], c2[20];
 char r;
 int fila1, colu1, fila2, colu2, i, j;
   do{
   clrscr();
  
   gotoxy(30,1);printf(" TRABAJO DE RELACIONES DIFUSAS");
   gotoxy(10,3);printf("Matriz  (X  Y) ");
   gotoxy(35,3);printf("  Filas: ");cin>>fila1;
   gotoxy(47,3);printf("  Columnas: ");cin>>colu1;
   gotoxy(10,5);printf("Matriz  (Y  Z) ");
   gotoxy(35,5);printf("  Filas: ");cin>>fila2;
   gotoxy(47,5);printf("  Columnas: ");cin>>colu2;
   ingresar_matrices(c1,c2,fila1,colu1,fila2,colu2,mat1,mat2);
   normalizar(mat1,mat2,fila1,colu1,fila2,colu2);
   imprimir(mat1,mat2,fila1,colu1,fila2,colu2);
   reldifusa(mat1,mat2,mat3,fila1,colu1,colu2);
   mostrar_relacion(mat3,fila1,colu2);
  gotoxy(2,23);cout<<"Desea volver a ingresar otra matriz (S/N): ";cin>>r;
  }while(r=='s'||r=='S');
}

void ingresar_matrices(char c1[],char c2[], int fila1, int colu1, int fila2, int colu2, double mat1[10][10], double mat2[10][10])
{
double i, j, x=3, y=3, pi=3.1415926535897932384626433832795;
int compa1, compa2, compa3, compa4,compa5,compa6;
clrscr();
gotoxy(10,1);cout<<"MATRIZ XY ( "<<fila1<<"*"<<colu1<<" )";

for(i=0;i<fila1;i++)
{
  for(j=0;j<colu1;j++)
  {
    gotoxy(x,y);gets(c1);
    gotoxy((x+4),y);cin>>mat1[i][j];
    compa1=comparar(c1,"sin");
    compa2=comparar(c1,"cos");
    compa3=comparar(c1,"tan");
    if(compa1==0)
    mat1[i][j]=sin((mat1[i][j]*pi)/180);
    if(compa2==0)
    mat1[i][j]=cos((mat1[i][j]*pi)/180);
    if(	compa3==0)
    mat1[i][j]=tan((mat1[i][j]*pi)/180);
    x=x+10;
  }
  x=3;
  y++;
}
x=43;
y=3;
gotoxy(40,1);cout<<"MATRIZ YZ: ( "<<fila2<<"*"<<colu2<<" )";
for(i=0;i<fila2;i++)
{
  for(j=0;j<colu2;j++)
  {
    gotoxy(x,y);gets(c2);
    gotoxy((x+4),y);cin>>mat2[i][j];
    compa4=comparar(c2,"sin");
    compa5=comparar(c2,"cos");
    compa6=comparar(c2,"tan");
    if(compa4==0)
     mat2[i][j]=sin((mat2[i][j]*pi)/180);

    if(compa5==0)
      mat2[i][j]=cos((mat2[i][j]*pi)/180);
    if(compa6==0)
      mat2[i][j]=tan((mat2[i][j]*pi)/180);
    x=x+11;
  }
  x=43;
  y++;
}
}

int comparar (char c1[], char c2[] ){
int dif=0, i=0;

while((c1[i]!='\0' || c2[i]!='\0')&&(dif==0))
	{
	if(c1[i]!=c2[i])
	{dif=(c1[i]-c2[i]);}
	i++;
	}
return dif;
}   

void normalizar(double mat1[10][10], double mat2[10][10], int fila1, int colu1, int fila2, int colu2)
{
double mayor, mayor1, i, j;
mayor=1;
mayor1=1;
for(i=0;i<fila1;i++)
{
  for(j=0;j<colu1;j++)
  {
    if(mat1[i][j]<0)
      mat1[i][j]*=(-1);
    if(mat1[i][j]>mayor)
      mayor=mat1[i][j];
  }
}

for(i=0;i<fila2;i++)
{
  for(j=0;j<colu2;j++)
  {
    if(mat2[i][j]<0)
      mat2[i][j]*=(-1);
    if(mat2[i][j]>mayor1)
      mayor1=mat2[i][j];
  }
}

if(mayor>1)
{
  for(i=0;i<fila1;i++)
  {
    for(j=0;j<colu1;j++)
    {
      if(mat1[i][j]>1)
      mat1[i][j]/=mayor;
    }
  }
}

if(mayor1>1)
{
  for(i=0;i<fila2;i++)
  {
    for(j=0;j<colu2;j++)
    {
      if(mat2[i][j]>1)
      mat2[i][j]/=mayor1;
    }
  }
}

}


void reldifusa(double mat1[10][10], double mat2[10][10],double mat3[10][10],int fila1, int colu1, int colu2)
{
  int i, j, k,l,m;
  double mayor,mins[20];
  mayor=0;
  l=0;
  for(i=0;i<fila1;i++)
  {
     for(j=0;j<colu2;j++)
     {
	for(k=0;k<colu1;k++)                    
        {
	   if(mat1[i][k]<mat2[k][j])
	      mins[l]=mat1[i][k];
	   else
	      mins[l]=mat2[k][j];
           l++;
	}
	for(m=0;m<l;m++)
	{
	  if(mins[m]>mayor)
	     mayor=mins[m];
        }
        mat3[i][j]=mayor;
	mayor=0;
        l=0;
     }
  }
}         


void mostrar_relacion(double mat3[10][10], int fila1, int colu2)
{
 int i, j, x, y;
 gotoxy(5,15);cout<<"Autores";
 gotoxy(3,17);cout<<"David Andrade";
 gotoxy(3,18);cout<<"Jhonny Andrade";
 gotoxy(3,19);cout<<"Sergio Santana";

 x=30;y=17;
 gotoxy(30,15);cout<<"RELACION XZ ES: ";
 for(i=0;i<fila1;i++)
 {
   for(j=0;j<colu2;j++)
   {
     gotoxy(x,y);printf("%.2f",mat3[i][j]);
     x=x+6;
   }
   x=30;
   y++;
 }
}

void imprimir(double mat1[10][10],double mat2[10][10], int fila1, int colu1, int fila2, int colu2)
{
  clrscr();
  int j, i, x, y;
  x=3;
  y=3;
  gotoxy(3,1);cout<<"MATRIZ XY NORMALIZADA: ";
  for(i=0;i<fila1;i++)
  {
    for(j=0;j<colu1;j++)
    {
      gotoxy(x,y);printf("%.2f",mat1[i][j]);
      x=x+6;
    }
    x=3;
    y++;
  }

  x=35;y=3;
  gotoxy(34,1);cout<<"MATRIZ YZ NORMALIZADA: ";
  for(i=0;i<fila2;i++)
  {
    for(j=0;j<colu2;j++)
    {
      gotoxy(x,y);printf("%.2f",mat2[i][j]);
      x=x+6;
    }
    x=35;
    y++;
  }
 }








         
                                                                                     




















