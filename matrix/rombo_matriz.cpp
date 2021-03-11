#include<iostream.h>
#include<conio.h>
#include<stdio.h>

void llenar(int n);
void imprimir(int n);
char m[50][50];
void main()
{
  int n,d;
  char opc;
  do
  {
    clrscr();
    for(n=0;n<20;n++)
    {
      for(d=0;d<20;d++)
      {
	m[n][d]=' ';
      }
    }
    printf("Ingrese dimension del rombo: ");cin>>n;
    llenar(n);
    imprimir(n);
    gotoxy(25,24);printf("¿Desea generar otro rombo?: ");cin>>opc;
  }while(opc==83||opc==115);
}

void llenar(int n)
{
  int i, j=0, k;
  for(i=0;i<((2*n)-1);i++)
  {
      if(i>n||i==n)
        {
	  j=((n-2)-(i-n));
        }	  
      for(k=(n-j-1);k<(j+n);k++)
      {
	m[i][k]='*';
      }
      j++;  
  }
}

void imprimir(int n)
{
  int i, j, x=10, y=1;
  clrscr();
  for(i=0;i<((2*n)-1);i++)
  {
    for(j=0;j<((2*n)-1);j++)
    {
      if(m[i][j]=='*')
      {
	gotoxy(x,y);printf("%c",m[i][j]);
	x+=2;
      }
      else
      {
	gotoxy(x,y);printf(" ");
	x+=2;
      }
    }
    y++;
    x=10;
  }
}



