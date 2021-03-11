#include<iostream.h>
#include<conio.h>
#include<math.h>
int m1[3][3], m2[2][2], suma, x, y, i, j, m, n, aux, pn, flag, k, l;
char opc;
void main(){
do{
suma=0;
clrscr();
gotoxy(30,1);cout<<"DETERMINANTE DE UNA MATRIZ";
x=15;y=3;
for(i=0;i<3;i++){
	for(j=0;j<3;j++){
gotoxy(x,y);cin>>m1[i][j];
x=x+4;
}
x=15;
y=y+2;
}



//CALCULO DEL DETERMINANTE
aux=0;
for(i=0;i<3;i++)
{
 if(((aux+i+2)%2)==0)
 {pn=1;}
 else
 {pn=-1;}


flag=0;
m=0;n=0;
for(k=0;k<3;k++)
  {
	 for(l=0;l<3;l++)
	  {
		if(l!=i)
		 {
		  if(k!=aux)
			  {
				m2[m][n]=m1[k][l];
				n++;
				flag=1;
			  }
		 }
	  }
		n=0;
		if(flag==1)
		{m++;}
	}
suma=suma+((pn*m1[aux][i])*((m2[0][0]*m2[1][1])-(m2[0][1]*m2[1][0])));
}


gotoxy(1,15);cout<<"DETERMINANTE: "<<suma;
gotoxy(1,20);cout<<"¿Desea volver a ingresar?(s/n): ";cin>>opc;
}while(opc=='s'||opc=='S');


}












