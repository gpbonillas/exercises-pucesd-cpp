#include<iostream.h>
#include<conio.h>


void main(){
int matriz[10][10], n, m, cont, i, j, x, y, k, divisor, nump;
char opc='n';
do{
clrscr();
cout<<"¿Cuantas Filas desea ?: ";cin>>n;cout<<"\n";
cout<<"¿Cuantas columnas desea ?: ";cin>>m; cout<<endl;
nump=2;
for(i=0; i<n; i++)
{
  for(j=0; j<m; j++)
  {
  cont=0;
	  while(cont==0)
	  {
	  divisor=1;
	  k=0;
		 while(divisor<=nump)
		 {
			 if(nump%divisor==0)
			 {
			 k++;
			 }
		 divisor++;
		 }
				 if(k==2)
				 {
				  matriz[i][j]=nump;
				  cont=1;
				 }
		nump++;
		}
	}
}


clrscr();
gotoxy(15,3);cout<<"MATRIZ DE NUMEROS PRIMOS";
x=15;y=5;
for(i=0;i<n;i++){
  for(j=0;j<m;j++){
  gotoxy(x,y);cout<<matriz[i][j];
  x=x+4;
  }
  x=15;
  y++;
  }
gotoxy(1,20);cout<<"¿Desea ingresar otras dimensiones?: ";cin>>opc;
}while(opc=='s'||opc=='S');
}


