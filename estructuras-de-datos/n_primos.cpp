/* EMPRESA:PUCESD
	NOMBRE:Gabriel Bonilla
	FECHA: Martes 6 de Octubre de 2009
	DESCRIPCION: Mostrar los n numeros primos

	FECHA DE MODIFICACION:
	DESCRIPCION:
	RESPONSABLE:
	VERSION 0.1
*/

# include<iostream.h>
#include<string.h>
int n, m, r, p, c;
void main(){
#include"cabecera.cpp"
cout<<"Ingrese un n valor limite:   ";
cin>>n;
cout<<"\n";
int c=1, num=2;
while(c<=n)
{
int r=0; m=1; p=0;
while(m<=num)
{
r=num%m;
if(r==0)
{
p=p+1;
}
m=m+1;
}
if(p==2)
{
cout<<"Los n numeros son :   "<<num<<"\n";
c=c+1;
}
  num=num+1;
}
}




