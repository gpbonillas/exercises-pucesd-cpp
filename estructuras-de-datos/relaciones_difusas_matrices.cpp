#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>
void ingresar_matrices(int fi1, int co1, int fi2, int co2,int m1[10][10], int m2[10][10]);
void reldifusa(int m1[10][10], int m2[10][10],int m3[10][10],int fi1, int co1, int co2);
void mostrar_relacion(int m3[10][10], int fi1, int co2);


void main()
{
 int m1[10][10], m2[10][10], m3[10][10];
 //char c1[10], c2[10];
 char opc;
 int fi1, co1, fi2, co2, i, j;
   do{
   clrscr();
   gotoxy(30,1);printf("RELACIONES DIFUSAS");
   gotoxy(1,3);printf("Dimension de 1º Matriz(M x N): ");
   gotoxy(30,3);printf("  Filas: ");cin>>fi1;
   gotoxy(47,3);printf("  Columnas: ");cin>>co1;
   gotoxy(1,5);printf("Dimension de 2º Matriz(M x N): ");
   gotoxy(30,5);printf("  Filas: ");cin>>fi2;
   gotoxy(47,5);printf("  Columnas: ");cin>>co2;
   ingresar_matrices(fi1,co1,fi2,co2,m1,m2);
   reldifusa(m1,m2,m3,fi1,co1,co2);
   mostrar_relacion(m3,fi1,co2);
   gotoxy(2,23);printf("¿DESEA VOLVER A INGRESAR?: ");cin>>opc;
   }while(opc==82||opc==115);

}
void ingresar_matrices(int fi1, int co1, int fi2, int co2, int m1[10][10],int m2[10][10])
{
int i, j, x=3, y=3;
clrscr();
gotoxy(14,1);printf("MATRIZ # 1: ");

for(i=0;i<fi1;i++)
{
  for(j=0;j<co1;j++)
  {
    gotoxy(x,y);cin>>m1[i][j];
    x+=5;
  }
  x=3;
  y++;
}
x=35;
y=3;
gotoxy(44,1);printf("MATRIZ # 2: ");
for(i=0;i<fi2;i++)
{
  for(j=0;j<co2;j++)
  {
    gotoxy((x+6),y);cin>>m2[i][j];
    x+=5;
  }
  x=35;
  y++;
}
}

void reldifusa(int m1[10][10], int m2[10][10],int m3[10][10],int fi1, int co1, int co2)
{
  int i, j, k, l, m;
  int mayor, mins[10];
  mayor=0;
  l=0;
  for(i=0;i<fi1;i++)
  {
     for(j=0;j<co2;j++)
     {
	for(k=0;k<co1;k++)                    
        {
	   if(m1[i][k]<m2[k][j])
	      mins[l]=m1[i][k];
           else
	      mins[l]=m2[k][j];
              l++;
        }
	for(m=0;m<l;m++)
	{
	   if(mins[m]>mayor)
	      mayor=mins[m];
	}
	m3[i][j]=mayor;
	mayor=0;
	l=0;
     }
  }
}         


void mostrar_relacion(int m3[10][10], int fi1, int co2)
{
 int i, j, x, y;
 x=30;y=17;
 gotoxy(30,15);cout<<"LA RELACION XZ ES: ";
 for(i=0;i<fi1;i++)
 {
   for(j=0;j<co2;j++)
   {
     gotoxy(x,y);printf("%d",m3[i][j]);
     x+=6;
   }
   x=30;
   y++;
 }
}







         
                                                                                     




















